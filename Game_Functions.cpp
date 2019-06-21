// Camilla Moraes - camillamoraes@wustl.edu
// File: Game_Functions.cpp
// Lab 3
// Source file with functions that relate to the Tic Tac Toe game. Functions print the game board, prompt user
// to enter coordinates to place their game piece, switches which player is the current player, and checks 
// if a player has one (3 pieces in a row horizontally, vertically, or diagonally).

#include "stdafx.h"
#include "Header.h"
#include "Functions.h"
#include "Tic_Tac_Toe_Game.h"
#include "Game_Piece.h"
#include <iostream>
#include <istream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

// check if 3 X's or O's are in a vertical, horizontal or diagonal line - check read me for info about function
// implementation
bool TicTacToeGame::done()
{

	//check for 3 X's or O's in a horizontal line - checks if piece type for indices in a horizontal line are equal
	for (int i = 6; i <= 16; i=i+5)
	{
		if (TicTacToeGame::pieces[i].piece_type != ' ' && TicTacToeGame::pieces[i].piece_type
			== TicTacToeGame::pieces[i + 1].piece_type && TicTacToeGame::pieces[i + 1].piece_type ==
			TicTacToeGame::pieces[i + 2].piece_type)
		{
			if (TicTacToeGame::pieces[i].piece_type == 'X')
			{
				winning_piece = 'X';
			}
			else 
			{
				winning_piece = 'O';
			}
			return true;
		}
	}

	//check for 3 X's or O's in a vertical line -  checks if piece type for indices in a vertical line are equal
	for (int i = 6; i <= 8; ++i)
	{
		if (TicTacToeGame::pieces[i].piece_type != ' ' && TicTacToeGame::pieces[i].piece_type
			== TicTacToeGame::pieces[i + 5].piece_type && TicTacToeGame::pieces[i + 5].piece_type ==
			TicTacToeGame::pieces[i + 10].piece_type)
		{
			if (TicTacToeGame::pieces[i].piece_type == 'X')
			{
				winning_piece = 'X';
			}
			else 
			{
				winning_piece = 'O';
			}
			return true;
		}
	}


	//check for 3 X's or O's in a diagonal line - starting bottom left and moving to the top right 
	if(TicTacToeGame::pieces[LeftDiagonalIndex].piece_type != ' ' && (TicTacToeGame::pieces[LeftDiagonalIndex].piece_type ==
		TicTacToeGame::pieces[LeftDiagonalIndex*2].piece_type  && TicTacToeGame::pieces[LeftDiagonalIndex*2].piece_type  ==
		TicTacToeGame::pieces[LeftDiagonalIndex*3].piece_type))
	{
		if (TicTacToeGame::pieces[LeftDiagonalIndex].piece_type == 'X')
		{
			winning_piece = 'X';
		}
		else 
		{
			winning_piece = 'O';
		}
		return true;
	}

	//check for 3 X's or O's in a diagonal line - starting bottom right and ending at top left 
	if (TicTacToeGame::pieces[RightDiagonalIndex].piece_type != ' ' && (TicTacToeGame::pieces[RightDiagonalIndex].piece_type ==
		TicTacToeGame::pieces[RightDiagonalIndex+4].piece_type && TicTacToeGame::pieces[RightDiagonalIndex+4].piece_type ==
		TicTacToeGame::pieces[RightDiagonalIndex*2].piece_type))
	{
		if (TicTacToeGame::pieces[RightDiagonalIndex].piece_type == 'X')
		{
			winning_piece = 'X';
		}
		else 
		{
			winning_piece = 'O';
		}
		return true;
	}

	return false;
}


bool TicTacToeGame::draw()
{

	//return false if there are moves remaining in the game or if done returns true
	if (done() || moves_remaining != ZeroMovesRemaining)
	{
		return false;
	}

	moves_remaining = ZeroMovesRemaining;
	return true; 
}

//prompt user to enter coordinates for game piece or quit game 
int TicTacToeGame::prompt(unsigned int & x, unsigned int & y)
{
	string coordinate = " ";

	//use cout to prompt user to type "quit" or a string representing a valid coordinate "0,0"
	cout << "Enter a valid coordinate (i.e. 1,1) or enter quit if you wish to stop playing." << endl;

	getline(cin, coordinate);

	if (coordinate == "quit")
	{
		int moves_played = TotalGameMoves - moves_remaining;
		cout << "User has chosen to quit game." << endl;

		//set moves_remaining to 0 now that the game is over
		moves_remaining = ZeroMovesRemaining;
		return UserQuitGame;
	}

	//comma_location represents the location of the comma in a properly formatted string of coordinates
	int comma_location = 1;

	//check if there is an error in the users input 
	if (coordinate.at(comma_location) != ',' || coordinate.at(comma_location - 1) == ' ' || coordinate.at(comma_location + 1) == ' ')
	{
		cout << "Unable to extract coordinates. Please make sure you input follows the following format: 1,1" << endl;
		//repeatedly call function until coordinate is valid or quit is pressed
		unsigned int width = BoardWidth;
		unsigned int height = BoardHeight;
		prompt(width, height);
		return BadlyFormattedInput;
	}
	//replace comma with a space if input is well formatted
	else if (coordinate.at(comma_location) == ',')
	{
		coordinate.at(comma_location) = ' ';
	}

	istringstream iss(coordinate);

	//extract x and y coordinates user entered into unsigned integers passed into progrma 
	if (iss >> x && iss >> y)
	{
		//check if coordinates entered are out of bounds of inner 3x3 board 
		if (x < LowerLimit || x > UpperLimit || y < LowerLimit || y > UpperLimit)
		{
			cout << "The coordinate you entered is not valid." << endl;;
			//repeatedly call function until coordinate is valid or quit is pressed
			unsigned int width = BoardWidth;
			unsigned int height = BoardHeight;
			prompt(width, height);
		}
		//display game piece on board if coordinates are valid 
		else
		{
			//get index for piece
			int valid_board_width = BoardWidth;
			int index = valid_board_width * y + x;

			//set x and y coordinates of piece to the coordinates user entered
			TicTacToeGame::pieces[index].x_coord = x;
			TicTacToeGame::pieces[index].y_coord = y;

			//check if spot at coordinates entered by user already has a piece in it 
			if (TicTacToeGame::pieces[index].piece_type != ' ')
			{
				cout << "The spot you chose is already filled." << endl;
				unsigned int width = BoardWidth;
				unsigned int height = BoardHeight;
				prompt(width, height);
			}
			//if spot is empty 
			else
			{
				moves_remaining = moves_remaining - 1;
				moves_played = moves_played + 1;

				//set piece type to type corresponding to current player and print out updated game board
				if (TicTacToeGame::current_player == 'X')
				{
					TicTacToeGame::pieces[index].piece_type = 'X';
					int x_coord = TicTacToeGame::pieces[index].x_coord;
					int y_coord = TicTacToeGame::pieces[index].y_coord;

					//add coordinates to vector storing players moves
					player_x_moves.push_back(make_pair(x_coord, y_coord));
					cout << *this << endl;
					cout << endl;

					//print out all coordinates stored in vector to display players moves
					cout << "Player X Moves: ";
					for (unsigned int i = 0; i < player_x_moves.size(); ++i)
					{
						cout << player_x_moves[i].first << "," << player_x_moves[i].second << "; ";
					}
					cout << endl;
				}
				else if (TicTacToeGame::current_player == 'O')
				{
					TicTacToeGame::pieces[index].piece_type = 'O';
					int x_coord = TicTacToeGame::pieces[index].x_coord;
					int y_coord = TicTacToeGame::pieces[index].y_coord;

					//add coordinates to vector of players moves
					player_o_moves.push_back(make_pair(x_coord, y_coord));
					cout << *this << endl;
					cout << endl;

					//iteratre through vector of players moves and print out all moves stored
					cout << "Player O Moves: ";
					for (unsigned int i = 0; i < player_o_moves.size(); ++i)
					{
						cout << player_o_moves[i].first << "," << player_o_moves[i].second << "; ";
					}
					cout << endl;
				}
			}
		}
	}
	else
	{
		cout << "Unable to extract coordinates" << endl;
		unsigned int width = BoardWidth;
		unsigned int height = BoardHeight;
		prompt(width, height);
	}

	return Success;

}

int TicTacToeGame::turn() 
{
	cout << endl;

	//variables to pass in to prompt function
	unsigned int width = BoardWidth;
	unsigned int height = BoardHeight;

	
	//alternate whose turn it is each time function is called 
	if (TicTacToeGame::current_player == 'X')
	{
		cout << "Current player is Player X" << endl;
		prompt(width, height);
		TicTacToeGame::current_player = 'O';
	}
	else if (TicTacToeGame::current_player == 'O')
	{
		cout << "Current player is Player O" << endl;
		prompt(width, height);
		TicTacToeGame::current_player = 'X';
	}

	return Success;

}

//print game board and call turn method when possible 
int TicTacToeGame::play() 
{

	//print game board 
	cout << *this << endl;

	//while there is no winner and moves still remain continue calling turn function
	while (done() == false && draw() == false)
	{
		turn();
	}

	//if a player has won 
	if (done() == true)
	{
		cout << "Player " << winning_piece << " wins!" << endl;
		return Success;
	}
	
	//if no moves remain but neither player won -- tie game
	else if (draw() == true)
	{
		cout << "Game Over! There is no winner." << endl;
		cout << "Number of moves played: " << moves_played << endl;
		cout << "Number of moves remaining: " << TotalGameMoves - moves_played << endl;
		return GameOverWithoutWinner;
	}

	return Success;

}