Camilla Moraes - camillamoraes@wustl.edu
CSE 332
Lab 3

Program Summary: 
In this lab I build a game of tic tac toe. I built a 5x5 tic tac toe board in which the outter 16 squares remain empty 
throughout the entire game. The game has two players, Player X and Player O, who enter coordinates that they would like
their pieces to appear. When the game begins, Player X is the first player to make a move. After each player makes
a valid move, the current player alternates. If all positions on the board are full but neither player got 3 in 
a row, the game ends in a tie.

Error Messages Program Can Generate:  
Success - occurs when program executes with no errors 
InvalidNumberOfArguments - occurs if user does not enter exactly 1 command line argument (Lab3 TicTacToe) in this case
UserQuitGame - occurs when user chooses to quit the game instead of entering coordinates
BadlyFormattedInput - occurs if users input is not well formated or invalid (i.e. 1,     1, 1.1, 1 1, etc)
ErrorExtractingCoordinates - occurs if there is a problem extracting coordinates from the istringstream
GameOverWithoutWinner - occurs when game ends in a tie

Tests cases: 
- Empty input 
- 0 command line arguments 
- User inputs a command line argument that isn't TicTacToe 
- Incorrect number of command line arguments
- Not properly formatted coordinates (i.e. 1,    1 or 1 1 or 123 or 11,1 etc)
- Case of a tie game
