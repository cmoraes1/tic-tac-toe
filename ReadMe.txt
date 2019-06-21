Camilla Moraes - camillamoraes@wustl.edu
CSE 332
Lab 3

Write Up:
In this lab I build a game of tic tac toe. I built a 5x5 tic tac toe board in which the outter 16 squares remain empty 
throughout the entire game. The game has two players, Player X and Player O, who enter coordinates that they would like
their pieces to appear. When the game begins, Player X is the first player to make a move. After each player makes
a valid move, the current player alternates. If all positions on the board are full but neither player got 3 in 
a row, the game ends in a tie.

Feedback:
This was my favorite lab to complete so far because it interacts with the user the most and allowed for more creativity
when coming up with how to design the project and build the functions. It was a little more difficult than the first 
two becasue it was more complex, but a lot of parts from Lab 2 were helpful in developing this program. 

Errors:
1. Getting an error when trying to push back game pieces onto my pieces vector created in TicTacToeGame class.
The error stated that I could not add something to a vector that I was constant. I was confused because I did not
declare my vector for the game pieces to be constant. I fixed this error by declaring the vector as mutable so
game pieces could be added to it. 

2. I wasn't sure how to print out the game board in the play() or prompt() methods. I realized you could do 
this using the "this" pointer that is passed. Since these functions are members of the Tic Tac Toe game class, they
are able to access the "this" pointer. Since it is a pointer, I had to dereference it when printing it out. 

3. I added a default constructor and a parameterized constructorat first  which was giving me an error. I 
realized I didn'tneed both and kept the default constructor (with no parameters) because I thought it made 
the most sense given the way my program functions.

Error Messages Program Can Generate:  

Success - occurs when program executes with no errors 

InvalidNumberOfArguments - occurs if user does not enter exactly 1 command line argument (Lab3 TicTacToe) in this case

UserQuitGame - occurs when user chooses to quit the game instead of entering coordinates

BadlyFormattedInput - occurs if users input is not well formated or invalid (i.e. 1,     1, 1.1, 1 1, etc)

ErrorExtractingCoordinates - occurs if there is a problem extracting coordinates from the istringstream

GameOverWithoutWinner - occurs when game ends in a tie


Design Choices:
1. I made a vector to hold all 25 pieces on the 5x5 board. Because the outer 16 pieces are never filled and remain
empty throughout the entire game, I initially thought I would just create a vector of 9 pieces that held the
pieces in the inner 3x3 board. However, I changed my mind because I think that even though the outer 16 squares
are never filled, they should still be represented as empty pieces with x and y coordinates. 

2. I initially thought about creating either a Player class, a Player_X and Player_O class, or a Player class 
with subclasses Player_X and Player_O. I realized that a player in this game doesn't have that much data
associated with it, so it was easier and simpler to just create a char variable that represents the player as 
'X' or 'O'. 

3. In order to keep track of the players valid moves, I created a vector of pairs to keep track of the coordinates.
I had never used pairs before but read about it on cplusplus.com and thought it would work well for this case
since I was trying to store coordinates, and thats essentially what a pair is. 

4. For the done() function I am checking if 3 pieces in a horizontal, vertical, or diagonal line on the board are
the same by checking if the piece type at at certain indices are equal. Although I have an enum that represents 
the index bottom left corner of the 3x3 board and an enum that represents the index ofbottom right corner of the 3x3
board, I increment these values by certain amounts (different depending on horizontal, vertical or diagonal case)
in order to get the index of the piece that we want to compare the current piece with. I technically could make
an enum or declare an integer to represent the numbers that I am incrementing the indices by, but this would involve
a lot of variable or enum declarations that aren't completely necessary because they don't really help to give us 
information about what the code is doing (spoke to Shidal about this).

5. I was going to create a return value in the turn function for when the user entered quit that would make
sure that the turn function was not called again however I decdided to handle this in a different way. When the
user enters quit an error message "UserQuitGame" is returned and the number of remaining moves is set to 0 so
the game terminates. Therefore, there is no need to have another error value returned in the turn function
because there is no way the turn function can be called again. 

Tests:
- Empty input - working

- No command line arguments - working

- When someone inputs a command line argument that isn't TicTacToe - working

- Incorrect number of command line arguments - working 

- Not properly formatted coordinates (i.e. 1,    1 or 1 1 or 123 or 11,1 etc) - working

- What happens if there is a tie  - working 