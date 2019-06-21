// Camilla Moraes - camillamoraes@wustl.edu
// File: TicTacToeGame.h
// Lab 3
// Header file with TicTacToe game class. Class has member variables defining the boards dimensions and 
// information about the game (i.e. current player, vectors to store the players moves, number of moves
// remaining in the game). The class also defines functions that are called in the Game_Functions source 
// file that control the state of the game. 

#pragma once

#ifndef TICTACTOEGAME_H
#define TICTACTOEGAME_H

#include "Game_Piece.h"
#include "Header.h"
#include <iostream>
#include <vector>

class TicTacToeGame {
private:
	int width; //5 squares wide
	int height; //5 squares tall 
	char piece_type;
	char current_player;
	char winning_piece;
	std::vector<std::pair<int, int>> player_x_moves;
	std::vector<std::pair<int, int>> player_o_moves;
	int moves_remaining;
	int moves_played;
public:
	mutable std::vector<Game_Piece> pieces;
	TicTacToeGame();
	bool done(); 
	bool draw(); 
	int prompt(unsigned int & x, unsigned int & y);
	int turn();
	int play();

	//declare the insertion operator to be a friend
	friend std::ostream & operator <<(std::ostream & output, const TicTacToeGame & game);
};

#endif /* TICTACTOEGAME_H */