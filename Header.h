// Camilla Moraes - camillamoraes@wustl.edu
// File: Header.h
// Lab 2
// Header file with all enums (success and error values, information about the usage of the game, and information about the actual game and board being used)

#pragma once

#ifndef HEADER_H
#define HEADER_H

//success and error values 
enum ErrorValues {
	Success, 
	InvalidNumberOfArguments,
	UserQuitGame,
	BadlyFormattedInput,
	ErrorExtractingCoordinates,
	GameOverWithoutWinner,
	TurnFunctionTerminated
};

//program info
enum Info {
	ProgramName,
	FileName,
	NumArguments
};

//info about game (board dimensions, important board indices, etc)
enum GameInfo {
	ZeroMovesRemaining = 0,
	LowerLimit = 1,
	UpperLimit = 3,
	BoardWidth = 5,
	BoardHeight = 5,
	LeftDiagonalIndex = 6,
	RightDiagonalIndex = 8,
	TotalGameMoves = 9
};

#endif /* HEADER_H */
