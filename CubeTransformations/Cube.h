#pragma once

#include <vector>
#include <iostream>
#include <string>

class Cube {
private:
	// namely: white, green, orange, blue, red, yellow
	enum COLORS { W, G, O, B, R, Y };

	std::vector<COLORS> tiles;
	std::vector<COLORS> tmpFace;
	std::vector<COLORS> tmpMiddle;

	std::vector<COLORS> defaultCube;

	int rotations;


public:
	Cube();

	// transforms
	void frontRegular();
	void topRegular();

	// misc
	void print();
	std::string colorCoder(COLORS color);
	int solvedChecker();
};