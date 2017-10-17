#include <iostream>
#include <stdlib.h>
#include <iomanip>

#define red "\x1b[31m"
#define cyan    "\x1b[36m"
#define reset   "\x1b[0m"

using namespace std;

bool checkUnique(int board[5][5], int row, int col)
{
	for(int i = 0; i < row; i++)
	{
		if(board[row][col] == board[i][col])
			return false;
	}
	return true;
}

void generate(int board[5][5])
{
	int i, j;
	
	for(i = 0; i < 5; i ++)
	{
		for(j = 0; j < 5; j++)
		{
			board[j][i] = (rand() % 15) + 1 + (i*15);
			if(!checkUnique(board, j, i))
				j--;
		}
	}
}

void printBoard(int board[5][5])
{
	system("clear");
	int i, j;
	cout << "  B   " << "  I   " << "  N   " << "  G   " << "  O";
	cout << endl;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(board[i][j] == 0)
				cout << "[    ]";
			else
				cout << "[ " << setfill('0') << setw(2) << board[i][j] << " ]";
		}
		cout << endl;
	}
}

void create(int board[5][5])
{
	int i;
	
	cout << "Enter the B column (1-15), pressing 'enter' after each number" << endl;
	for(i = 0; i < 5; i++)
	{
		cin >> board[i][0];
		if(board[i][0] < 1 || board[i][0] > 15 || !checkUnique(board, i, 0))
		{
			cout << "invalid number" << endl;
			i--;
		} else
			printBoard(board);
	}
	cout << "Good, now enter the I column (16-30), pressing 'enter' after each number" << endl;
	for(i = 0; i < 5; i++)
	{
		cin >> board[i][1];
		if(board[i][1] < 16 || board[i][1] > 30 || !checkUnique(board, i, 1))
		{
			cout << "invalid number" << endl;
			i--;
		} else
			printBoard(board);
	}
	cout << "Now the N column (31-45)" << endl;
	for(i = 0; i < 5; i++)
	{
		cin >> board[i][2];
		if(board[i][2] < 31 || board[i][2] > 45 || !checkUnique(board, i, 2))
		{
			cout << "invalid number" << endl;
			i--;
		} else
			printBoard(board);
	}
	cout << "And the G column (46-60)" << endl;
	for(i = 0; i < 5; i++)
	{
		cin >> board[i][3];
		if(board[i][3] < 46 || board[i][3] > 60 || !checkUnique(board, i, 3))
		{
			cout << "invalid number" << endl;
			i--;
		} else
			printBoard(board);
	}
	cout << "Finally, the O column (61-75)" << endl;
	for(i = 0; i < 5; i++)
	{
		cin >> board[i][4];
		if(board[i][4] < 61 || board[i][4] > 75 || !checkUnique(board, i, 4))
		{
			cout << "invalid number" << endl;
			i--;
		} else
			printBoard(board);
	}
}

void input(int board[5][5])
{
	bool done = false;
	
	while(!done)
	{
		int choice = 0;
		cout << "Press 1 to generate a random board, or 2 to generate your own: ";
		cin >> choice;
		done = true;
		
		if(choice == 1)
			generate(board);
		else if(choice == 2)
			create(board);
		else
		{
			cout << "Invalid input, try again" << endl;
			done = false;
		}
	}
}

void printBoards(int board1[5][5], int board2[5][5], int board3[5][5])
{
	int i, j;
	
	cout << "  B   " << "  I   " << "  N   " << "  G   " << "  O";
	cout << "\t";
	cout << "  B   " << "  I   " << "  N   " << "  G   " << "  O";
	cout << "\t";
	cout << "  B   " << "  I   " << "  N   " << "  G   " << "  O";
	cout << endl;
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			if(board1[i][j] == 0)
				cout << "[ " << cyan << "xx" << reset << " ]";
			else if(board1[i][j] == -1)
				cout << "[ " << setfill('0') << setw(2) << red << "xx" << reset << " ]";
			else cout << "[ " << setfill('0') << setw(2) << board1[i][j] << " ]";
		}
		cout << "\t";
		for(j = 0; j < 5; j++)
		{
			if(board2[i][j] == 0)
				cout << "[ " << cyan << "xx" << reset << " ]";
			else if(board2[i][j] == -1)
				cout << "[ " << setfill('0') << setw(2) << red << "xx" << reset << " ]";
			else cout << "[ " << setfill('0') << setw(2) << board2[i][j] << " ]";
		}
		cout << "\t";
		for(j = 0; j < 5; j++)
		{
			if(board3[i][j] == 0)
				cout << "[ " << cyan << "xx" << reset << " ]";
			else if(board3[i][j] == -1)
				cout << "[ " << setfill('0') << setw(2) << red << "xx" << reset << " ]";
			else cout << "[ " << setfill('0') << setw(2) << board3[i][j] << " ]";
		}
		cout << endl;
	}
}

bool checkWin(int board[5][5])
{
	int i, j, k, horiz, vertical, diag1, diag2;
	horiz = vertical = diag1 = diag2 = 0;
	k = 4;
	
	for(i = 0; i < 5; i++)
	{
		diag1 += board[i][i];
		diag2 += board[k--][i];
		for(j = 0; j < 5; j++)
		{
			horiz += board[i][j];
			vertical += board[j][i];
		}
		if(horiz == 0)
		{
			for(j = 0; j < 5; j++)
				board[i][j] = -1;
			return true;
		}
		if(vertical == 0)
		{
			board[j][i] = -1;
			return true;
		}
		horiz = vertical = 0;
	}
	if(diag1 == 0)
	{
		for(i = 0; i < 5; i++)
			board[i][i] = -1;
		return true;
	}
	if(diag2 == 0)
	{
		k = 4;
		for(i = 0; i < 5; i++)
			board[k--][i] = -1;
		return true;
	}
	return false;
}

int unique(int calls[100], int call, int index)
{
	for(int i = 0; i < index; i++)
	{
		if(calls[i] == call)
			return false;
	}
	return true;
}

bool check(int board[5][5], int num)
{
	for(int i = 0; i < 5; i++)
	{
		for(int j = 0; j < 5; j++)
		{
			if(board[i][j] == num)
			{
				board[i][j] = 0;
				return checkWin(board);
			}
		}
	}
	return false;
}

int score(int board1[5][5], int board2[5][5], int board3[5][5], int choice)
{
	int num, i = 0;
	int score1 = 0, score2 = 0, score3 = 0;
	int calls[100] = {0};
	bool done = false;
	
	while(!done)
	{
		do{
			num = (rand() % 75) + 1;
			calls[i] = num;
		} while(!unique(calls, num, i));
		if(choice == 1)
		{
			getchar();
			system("clear");
			printBoards(board1, board2, board3);
			cout << "Press enter to get another number" << endl;
			cout << "Call: " << num << endl;
			cout << "Call History: { " << calls[0];
			for(int j = 1; calls[j] != 0; j++)
				cout << ", " << calls[j];
			cout << " }";
		}
		if(check(board1, num))
			return 1;
		if(check(board2, num))
			return 2;
		if(check(board3, num))
			return 3;
		if(calls[99] != 0)
			done = true;
		i++;
	}
	return 404;
}

int main()
{	
	int winner, choice;

	int board1[5][5] = {0}, board2[5][5] = {0}, board3[5][5] = {0};
	srand(time(NULL));

	input(board1);
	input(board2);
	input(board3);
	
	system("clear");
	
	cout << "Your three cards are as follows: \n\n";
	
	printBoards(board1, board2, board3);
	
	do
	{
		cout << "\nEnter 1 to manually see which card wins, or 2 to simulate it: ";
		cin >> choice;
	} while (choice != 1 && choice != 2);
	winner = score(board1, board2, board3, choice);
	
	cout << endl;
	system("clear");
	
	printBoards(board1, board2, board3);
	
	cout << "\nThe winning bingo card was card " << winner << "!!!" << endl;
	
	return 0;
}
