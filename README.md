Logic- Jah-El Brandon Van Philips
You dont actually have to read this, this is for me to keep my train of thought

First off if you have any questions text me.


A|_|_|_|_|_|_|_|_|
B|_|_|_|_|_|_|_|_|
C|_|_|_|_|_|_|_|_|
D|_|_|_|_|_|_|_|_|
E|_|_|_|_|_|_|_|_|
F|_|_|_|_|_|_|_|_|
G|_|_|_|_|_|_|_|_|
H|_|_|_|_|_|_|_|_|
  1 2 3 4 5 6 7 8

The board vector for the board is set up in an (X,Y) type orientation, so basically the Y axis is in reverse (hindsight terrible implimentation )

Input:
	sample input "G1-F2"

Pieces:
	The pieces were pretty simple to do. All it required was a class that contained the color, if its a king or not, and if it was jumped or not 
	(which is a variable I might not use but just in case)
	The color has 3 options:
		Red   - for the red side
		Black - for the black side
		White - for the valid places but contains no red or black piece
		Null  - for the invalid places
		(white and null are important for the board construction)

Board:
	This part was a little complicated so 
	tdrl: 
		the board is just a bunch of checker pieces.
	thought process
		OK so this part was conceptually a but challenging but I came up with a solution. OK so the challenge of constructing the board is finding a way to identify
		what squares were valid and which were not legal moves. Hypothetically I could check values of the indexes but that would be more work. Then I I thought what
		if the board was a bunch of pieces that would just change color depending on what piece was there. 
	how the board works
		by default the invalid pieces are of color "null" and of color "white". "white" is a valid move and "null" is not. Then the colors are filled in with setRed
		setBlack.
Moves:
