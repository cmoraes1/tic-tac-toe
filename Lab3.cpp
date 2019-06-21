// Camilla Moraes - camillamoraes@wustl.edu
// File: Lab3.cpp
// Lab 3
// Source file with overriding ostream operator and main function. Main function contains usage message function
// that ensures the correct number of command line arguments are passed in, declares an object of the TicTacToeGame
// class and calls the play() function on the game object. 

#include "stdafx.h"
#include "Header.h"
#include "Tic_Tac_Toe_Game.h"
#include "Functions.h"
#include "Game_Piece.h"
#include <iostream>
#include <fstream>
#include <ostream>
using namespace std;

//class constructor
TicTacToeGame::TicTacToeGame()
	: width(BoardWidth), height(BoardHeight), piece_type(' '), current_player('X'), winning_piece(' '), 
	player_x_moves({}), player_o_moves({ }), moves_remaining(TotalGameMoves), moves_played(0)
{}


//insertion operator that returns the ostream reference passed in 
ostream & operator <<(ostream & output, const TicTacToeGame & game)
{
	//use this int when creating an placeholder game piece (x and y coordinates don't matter for placeholder pieces so I made them 0)
	int default_coord = 0;

	//fill game board vector with empty pieces
	for (int i = game.width - 1; i >= 0; i--)
	{
		for (int j = 0; j <= game.height - 1; j++)
		{
			//create index for each piece in board 
			int board_width = BoardWidth;
			int index = board_width * i + j;

			//fill empty with empty pieces as placeholders (x and y coordinates set to 0, piece type is an empty char)
			Game_Piece piece;
			piece.x_coord = default_coord;
			piece.y_coord = default_coord;
			piece.piece_type = ' ';
			game.pieces.push_back(piece);
		}
	}

	//print out 5x5 game board 
	for (int i = game.width - 1; i >= 0; i--)
	{
		cout << i << " ";
		for (int j = 0; j <= game.height - 1; j++)
		{
			//get index of each piece on the board 
			int board_width = BoardWidth;
			int index = board_width * i + j;

			//set x and y coordinates of game pieces 
			game.pieces[index].x_coord = j;
			game.pieces[index].y_coord = i;

			//print out each pieces piece tpye (X or O)
			cout << game.pieces[index].piece_type << " ";
		}
		cout << endl;
	}

	cout << "  " << "0 " << "1 " << "2 " << "3 " << "4 ";

	return output;
}

int main(int argc, char * argv[])
{

	//make sure number of command line arguments is 1
	if (argc != NumArguments)
	{
		cout << "Invalid number of arguments" << endl;
		return usage_message(argv[ProgramName]);
	}
	
	//make sure user input is "TicTacToe" 
	else 
	{
		string file_name = argv[FileName];
		if (file_name != "TicTacToe")
		{
			cout << "Incorrect file name" << endl;
			return usage_message(argv[ProgramName]);
		}
	}

	TicTacToeGame game;

	return game.play();

}

