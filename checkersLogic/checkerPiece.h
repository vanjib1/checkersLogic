#pragma once
#include <string>
class checkerPiece
{
public:
	checkerPiece();
	~checkerPiece();
	bool isRoyal;
	std::string color; //can be black, red, white, or null (white means it's a valid move but there is no valid checker in play, and null means it is not a valid move)
	bool wasJumped; //smh gang violence

};

