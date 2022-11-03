// Morgan Williams
//Programming Assignment 1: Tic Tac Toe

#include <cstdlib>				
#include <iostream>	
#include <iomanip>
using namespace std;	

char **createBoard(int rows, int cols) // Creates board
{
	char** board = new char*[rows];
		for (int i = 0; i < rows; ++i)
			board[i] = new char[cols];
	return board;
}
	
const int X = 1, O = -1, EMPTY = 0;		// possible marks
int currentPlayer;				// current player (X or O)

void clearBoard(char **board, int rows, int cols) {	// clear the board

	for (int i = 0; i < rows; ++i)
		for (int j = 0; j < cols; ++j)
			board[i][j]= EMPTY; // every cell is empty

	currentPlayer = X;	// player X starts
}

void putMark(char **board, int i, int j) { // mark row i column j
	
	board[i][j] = currentPlayer;
	currentPlayer = -currentPlayer; // switch players
}

bool isWin(int mark, char **board, int rows, int cols) { // Determines winner

	int count;
	for (int i = 0; i < rows; i++) // Checks for winner in rows (horizontally)
	{
		count = 0;
		for (int j = 0; j < cols; j++)
			if (board[i][j] == mark)
				count++;
		if (count == rows)
			return true;
	}

	for (int i = 0; i < rows; i++) { // Checks for winner in columns (vertically)
		count = 0;
		for (int j = 0; j < cols; j++)
			if (board[j][i] == mark)
				count++;
		if (count == rows)
			return true;
	}

	count = 0;
	for (int i = 0; i < rows; i++) { // Checks for winner in first diagonal (rows = cols)
		if (board[i][i] == mark)
			count++;
	}
	if (count == rows)
		return true;

	count = 0;
	for (int i = 0, j = rows - 1; i < rows; i++, j--) { // Checks for winner in other diagonal
		if (board[i][j] == mark)
			count++;
	}

	if (count == rows)
		return true;

	return false;

}

int getWinner(char **board, int rows, int cols) { // who wins? (EMPTY means tie)
	if (isWin(X, board, rows, cols)) return X;
	else if (isWin(O, board, rows, cols)) return O;
	else return EMPTY;
}


void printBoard(char **board, int y, int x) { // Function to print the grid

	int i = 0;
	int j = 0;

	cout << endl; 

	for (int i = 0; i < (x - 1); i++)
	{
		cout << "+---";	
	}

	cout << "+---+" << endl;


	for (int i = 0; i < x; i++)
	{
		cout << "|";

		for (int j = 0; j < y; j++)
		{
			switch (board[i][j])
			{
			case X: cout << "X"; break;
			case O: cout << "O"; break;
			case EMPTY: cout << " "; break;
			}

			if (j < (y - 1)) cout << "  |";
		}

		cout << "  |" << "  " << "R" << j + 1; 
		j++;

		cout << endl;

		for (int i = 0; i < (x - 1); i++)
		{
			
			cout << "+---";
			
		}
		cout << "+---+";

		cout << endl;
	}

	for (i = 0; i < x; i++)
	{
		cout << setw(2) << "C" << i + 1 << " ";
	}
}

int main() { // main program

	int rows = 0;
	int cols = 0;
	int rowMark = 0;
	int colMark = 0;
	char player;
	int winner = 0;
	int moves = 0;

	// Prints the title of the game

	cout << setw(63) << "*TIC TAC TOE*\n\n"; 
	
	// Prints the menu of rules and inforamation for the user

	cout << "\n\n\t\t\t\t\t RULES & BASIC GAME INFORMATON:"
		<< "\n\t\t  > Your board will be marked with numbers and letters denoting the Columns and Rows:"
		<< "\n\t\t   - 'C1' stands for 'Column 1' and 'R1' stands for 'Row 1'. And so on."
		<< "\n\t\t  > Your row and column coordinates are 1-based (no 0s):"
		<< "\n\t\t   - (Ex. to choose the upper left square, enter '1' for C and '1' for R)"
		<< "\n\t\t   - (i.e. C[1] + R[1] = upper left corner)."
		<< "\n\t\t  > Once a Player, X or O, has placed their marks CONSECUTIVELY and completed a row, that Player WINS!"
		<< "\n\t\t   - A winning row can be: diagonal, horizontal, or vertical."
		<< "\n\t\t  > If the board is filled without a Player obtaining consecutive marks, it's a TIE!"
		<< "\n\n\t\t  This set of rules and information will remain onscreen throughout the game! Good luck!"
		<< "\n\n\t\t*******************************************************************************************";

	// Prompts the user to enter the dimensions of the board

	cout << "\n\n\t\t\t   Welcome, Players! Please enter the dimensions of the board!\n";
	cout << "\t\t\t\t  Dimensions must be between 2x2 and 9x9!\n";
	cout << "\t\t\t\t How manys rows and columns would you like? ";
	cin >> rows;

	while (rows < 2 || rows > 9) // If invalid entry, asks user to re-enter
	{
		cout << "\nInvalid entry! Dimensions must be between 2x2 and 9x9.\nPlease re-enter!\n";
		cin >> rows;
	}

	cols = rows; // Sets columns equal to rows for equal dimensions

	char **board = createBoard(rows, cols); // Creates board
	clearBoard(board, rows, cols); // Clears the board

	do
	{
		system("cls"); // Clears output screen each iteration

		// Prints the menu of rules and information for the user throughout the entirety of the game
		
		cout << "\n\n\t\t\t\t\tRULES & BASIC GAME INFORMATON:"
			<< "\n\t\t  > Your board has been marked with numbers and letters denoting the Columns and Rows:"
			<< "\n\t\t   - 'C1' stands for 'Column 1' and 'R1' stands for 'Row 1'. And so on."
			<< "\n\t\t  > Your row and column coordinates are 1-based (no 0s):"
			<< "\n\t\t   - (Ex. to choose the upper left square, enter '1' for C and '1' for R)"
			<< "\n\t\t   - (i.e. C[1] + R[1] = upper left corner)."
			<< "\n\t\t  > Once a Player, X or O, has placed their marks CONSECUTIVELY and filled a row, that Player WINS!"
			<< "\n\t\t   - A winning row can be: diagonal, horizontal, or vertical."
			<< "\n\t\t  > If the board is filled without a player obtaining consecutive marks, it's a TIE!\n";
		
		printBoard(board, rows, cols); // Prints matrix

		cout << endl << endl;
		if (currentPlayer == 1) // Assigns the character value of 'X' if currentPlayer = 1
		{
			player = 'X';
		}
		else if (currentPlayer == -1) // Assigns the character value of 'O' if currentPlayer = -1
		{
			player = 'O';
		}

		cout << "Player " << player << "'s Turn\n";
		cout << "Where would you like to place your mark for " << player << "?\n";
		cout << "Please enter the numbers corresponding with 'C' and 'R' where you would like to place your mark!\n\n"; // Asks user for location of the mark
		cout << "C:";
		cin >> colMark;

		while (colMark == 0 || colMark > cols) // Checks for non-existent column
		{
			cout << "\nInvalid Entry! The column that you selcted does not exist.\nPlease re-enter for the column!\n";
			cout << "C:";
			cin >> colMark;
		}

		cout << " + " << endl;
		cout << "R:";
		cin >> rowMark;

		while (rowMark == 0 || rowMark > rows) // Checks for non-existent row
		{
			cout << "\nInvalid entry! The row that you selected does not exist.\nPlease re-enter for the row!\n";
			cout << "R:";
			cin >> rowMark;
		}

		cout << endl;
		rowMark--; 
		colMark--;
		moves++; // Keep track of number of moves

			while (board[rowMark][colMark] == 1 || board[rowMark][colMark] == -1) // If a space is already taken
			{
				cout << "I'm sorry! This position is taken\nPlease re-enter!\n";
				cout << "C:";
				cin >> colMark;

				while (colMark == 0 || colMark > cols) // Checks again for a non-existent column
				{
					cout << "\nInvalid Entry! The column that you selcted does not exist.\nPlease re-enter for the column!\n";
					cout << "C:";
					cin >> colMark;
				}
				
				cout << "R:";
				cin >> rowMark;

				while (rowMark == 0 || rowMark > rows) // Checks again for a non-existent row
				{
					cout << "\nInvalid entry! The row that you selected does not exist.\nPlease re-enter for the row!\n"; 
					cout << "R:";
					cin >> rowMark;
				}

				rowMark--;
				colMark--; 
			}


			putMark(board, rowMark, colMark); // If space is empty, places the mark.
			winner = getWinner(board, rows, cols); // Checks for winner each time a mark is placed on the board.

			if (winner) // If winner = true
			{
				cout << "FINAL BOARD:" << endl;
				printBoard(board, rows, cols); // Prints winner
				cout << "  " << endl << endl << (winner == X ? 'X' : 'O') << " wins! Thanks for playing!" << endl;
				return 0;
			}
				
	} while (!winner && moves != rows * cols);
		
		cout << "FINAL BOARD:" << endl;
		printBoard(board, rows, cols); // Displays final board
		cout << endl << endl << "It's a tie. Wah-Wah-Waaaaah..." << endl; // Declares a tie
		cout << "But thanks for playing!\n";
	
	return EXIT_SUCCESS;
}
