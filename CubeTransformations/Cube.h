#pragma once

#include <vector>
#include <iostream>
#include <string>

class Cube {
private:
	enum COLORS { W, G, O, B, R, Y };

	std::vector<COLORS> tiles;
	std::vector<COLORS> tmpFace;
	std::vector<COLORS> tmpMiddle;


public:
	Cube();
	void front();
	void print();
};