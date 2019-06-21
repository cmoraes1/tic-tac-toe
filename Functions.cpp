// Camilla Moraes - camillamoraes@wustl.edu
// File: Functions.cpp
// Lab 3
// Source file with function definitions for functions that are called in the programs main method. 

#include "stdafx.h"
#include "Tic_Tac_Toe_Game.h"
#include "Header.h"
#include "Functions.h"
#include "Game_Piece.h"

using namespace std;

//defines a helpful usage message that tells the user how to correctly run the program
int usage_message(char * programName) 
{
	cout << "usage: " << programName << " <TicTacToe>" << endl;
	return InvalidNumberOfArguments;
}