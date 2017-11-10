Logic- Jah-El Brandon Van Philips


First off if you have any questions text me.

	BLACK SIDE
A|_|_|_|_|_|_|_|_|
B|_|_|_|_|_|_|_|_|
C|_|_|_|_|_|_|_|_|
D|_|_|_|_|_|_|_|_|
E|_|_|_|_|_|_|_|_|
F|_|_|_|_|_|_|_|_|
G|_|_|_|_|_|_|_|_|
H|_|_|_|_|_|_|_|_|
  1 2 3 4 5 6 7 8
	RED SIDE



Pieces:
	The pieces were pretty simple to do. All it required was a class that contained the color, if its a king or not, and if it was jumped or not 
	(which is a variable I might not use but just in case)
	The color has 3 options:
		Red   - for the red side
		Black - for the black side
		White - for the valid places but contains no red or black piece
		Null  - for the invalid places
	member variables
		color   - what color the piece is
		isRoyal - if the piece is a king or not


Board:
	This part was a little complicated so 

	tdrl: 
		the board is just a bunch of checker pieces.

	thought process
		OK so this part was conceptually challenging but I came up with a solution. OK so the challenge of constructing the board is finding a way to identify
		what squares were valid and which were not legal moves. Hypothetically I could check values of the indexes but that would be more work. Then I thought what
		if the board was a bunch of pieces that would just change color depending on what piece was there. 

	how board set up works
		by default the invalid pieces are of color "null" and of color "white". They alternate to create the checkerboard pattern. Then the colors are filled in with setRed
		setBlack.
	The board vector for the board is set up in an (X,Y) access style

Moves:
	Input:
		sample input "G1-F2"
		format:
			"currentPlace-newPlace"
		 will also accept:
			"g1-f2"
			"g 1 - f 2"
			and other variations 
	functions:
		bool isStringGood(std::string string)
			checks to see if string is formatted correctly and within bounds
		vector stringToPoint(string point)
			takes the input (shown above) and converts it and returns a {x1,y1,x2,y2} vector
		bool canJump(std::vector<int> move, std::vector<std::vector<checkerPiece>>& board)
			checks to see if a piece is able to jump another piece
		bool anyJumpable( std::vector<std::vector<checkerPiece>>& board)
			checks if there is a piece on your side that can jump
		void move(std::vector<std::vector<checkerPiece>>& board, std::vector<int> move)
			moves the selected piece to the selected new square
		

			