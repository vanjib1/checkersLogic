// checkersLogic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class checkerPiece
{
public:
	checkerPiece();
	~checkerPiece();
	bool isRoyal;
	std::string color; //can be black, red, white, or null (white means it's a valid move but there is no valid checker in play, and null means it is not a valid move)
	bool wasJumped; //smh gang violence

};
checkerPiece::checkerPiece()
{
	isRoyal = false;
	color = "null";
	wasJumped = false;
}

int redCount = 0;
int blackCount = 0;

std::vector<std::vector<checkerPiece>> createBoard();
void setRed(std::vector<std::vector<checkerPiece>>& board);
void setBlack(std::vector<std::vector<checkerPiece>>& board);
std::vector<int> stringToPoint(std::string point);
bool isStringGood(std::string string);
void jump(std::vector<std::vector<checkerPiece>>& board);
void move(std::vector<std::vector<checkerPiece>>& board, std::vector<int> move);
bool isValidMove(std::vector<int> move);






int main()
{
	auto board = createBoard();
	setRed(board);
	setBlack(board);

	//testing
	stringToPoint("A1-B2");

    return 0;
}

std::vector<std::vector<checkerPiece>> createBoard() //creates the board (no duh) and sets all the valid pieces
{
	std::vector<std::vector<checkerPiece>> board(8);
	for (auto i = 0; i < 8; i++)
	{
		board[i].resize(8);
	} //creates a board of size 8*8 and sets everything to the default color= "null"

	for(auto i =0; i < 8; i++)
	{
		if(i % 2 == 0)
		{
			for(auto j = 0; j < 8; j++)
			{
				if( j % 2 == 0)
				{
					board[i][j].color = "white";
				}
			}
		}
		else
		{
			for (auto j = 0; j < 8; j++)
			{
				if (j % 2 == 1)
				{
					board[i][j].color = "white";
				}
			}
		}
		//sets all valid places to "white"
	}

	return board;
}
void setRed(std::vector<std::vector<checkerPiece>>&  board)
{
	for(auto i = 0; i < 8; i++ )
	{
		for(auto j = 0; j < 3; j++)
		{
			if (board[i][j].color == "white")
			{
				board[i][j].color = "red";
			}
		}

	}
}

void setBlack(std::vector<std::vector<checkerPiece>>& board)
{
	for (auto i = 0; i < 8; i++)
	{
		for (auto j = 7; j > 4; j--)
		{
			if (board[i][j].color == "white")
			{
				board[i][j].color = "black";
			}
		}

	}
}

void jump(std::vector<std::vector<checkerPiece>>& board)
{
	//TODO: this function
}

void move(std::vector<std::vector<checkerPiece>>& board, std::vector<int> move)
{
	//TODO: ...this
}

bool isValidMove(std::vector<int> move)
{
}

std::vector<int> stringToPoint(std::string points)
{
	/*
	assumes that input is valid and in correct format 
	doesnt check if it's a valid move
	sample input:
		"G6-F5"
	Sample output
		{1,6,2,5}
	*/
	points.erase(std::remove_if(points.begin(), points.end(), isspace), points.end());
	std::transform(points.begin(), points.end(), points.begin(), ::toupper); 
	//now the string should be spacesless and all letters should be caps

	std::vector<int> vecInput(5);
	for( auto i = 0; i < points.length(); i++)
	{
		if(static_cast<int> (points[i]) > 64 & static_cast<int> (points[i]) < 73 )
		{
			switch(points[i])
			{
			case('A'): vecInput[i] = 7;
					   break;
			case('B'): vecInput[i] = 6;
				       break;
			case('C'): vecInput[i] = 5;
				       break;
			case('D'): vecInput[i] = 4;
					   break;
			case('E'): vecInput[i] = 3;
					   break;
			case('F'): vecInput[i] = 2;
				       break;
			case('G'): vecInput[i] = 1;
					   break;
			case('H'): vecInput[i] = 0;
			}
		}
		else if(static_cast<int> (points[i]) > 47 & static_cast<int> (points[i]) < 57)
		{
			vecInput[i] = static_cast<int> (points[i]) - 48;
		}
	}
	vecInput.erase(vecInput.begin()+3);
	
	return vecInput;

	
}

bool isStringGood(std::string string)
{
	/* this function simply checks to see if the string is correct, not if the move is valid
	 * string format should be -> letter number - letter number (5 characters in total)
	 * we remove spaces just in case
	 * 
	 */
	
	string.erase(std::remove_if(string.begin(), string.end(), isspace), string.end());
	std::transform(string.begin(), string.end(), string.begin(), ::toupper);

	if(string.length() != 5)
	{
		return false;
	}
	for (auto i = 0; i < 5; i++)
	{
		if(i == 0 | i == 3)
		{
			if (!(static_cast<int> (string[i]) > 64 & static_cast<int> (string[i]) < 73))
			{
				return false;
			}
		}
		else if (i == 1 | i == 4)
		{
			if (!(static_cast<int> (string[i]) > 47 & static_cast<int> (string[i]) < 57))
			{
				return false;
			}
		}
		else
		{
			if (string[i] != '-')
			{
				return false;
			}
		}
	}
	return true;
}


