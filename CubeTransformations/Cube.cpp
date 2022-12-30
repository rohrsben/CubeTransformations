#include "Cube.h"

/*
tiles are referenced by their index in /tiles/
TODO: check into cleaning up how transforms are done?
	maybe modelling the smaller cubes as connected is easier/more efficient?
*/
Cube::Cube() {
	tiles = { W, W, W, W, W, W, W, W, W, G, G, G, G, G, G, G, G, G, O, O, O, O, O, O, O, O, O, B, B, B, B, B, B, B, B, B, R, R, R, R, R, R, R, R, R, Y, Y, Y, Y, Y, Y, Y, Y, Y };
	tmpFace = { W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W, W };
	tmpMiddle = { W, W, W, W, W, W, W, W, W };

	defaultCube = { W, W, W, W, W, W, W, W, W, G, G, G, G, G, G, G, G, G, O, O, O, O, O, O, O, O, O, B, B, B, B, B, B, B, B, B, R, R, R, R, R, R, R, R, R, Y, Y, Y, Y, Y, Y, Y, Y, Y };

	rotations = 0;
}

/* 
transformations are done as such:
	1. all tiles which are going to change/rotate are stored in to tmpFace
	2. on transform by transform basis, the tiles are replaced in /tiles/ with their corresponding tmp value

	these are all created using helper functions, see cubeHelper.py
*/
void Cube::frontRegular() {
	tmpFace = { 
		// f1 - f9
		tiles[0], tiles[1], tiles[2], tiles[3], tiles[4], tiles[5], tiles[6], tiles[7], tiles[8],
		// t7 - t9
		tiles[15], tiles[16], tiles[17],
		// r7 - r9
		tiles[24], tiles[25], tiles[26],
		// b7 - b9
		tiles[33], tiles[34], tiles[35],
		// l7 - l9
		tiles[42], tiles[43], tiles[44] };

	// f1 - f9
	tiles[0] = tmpFace[6];
	tiles[1] = tmpFace[3];
	tiles[2] = tmpFace[0];
	tiles[3] = tmpFace[7];
	tiles[4] = tmpFace[4];
	tiles[5] = tmpFace[1];
	tiles[6] = tmpFace[8];
	tiles[7] = tmpFace[5];
	tiles[8] = tmpFace[2];

	// t7 - t9
	tiles[15] = tmpFace[18];
	tiles[16] = tmpFace[19];
	tiles[17] = tmpFace[20];

	// r7 - r9
	tiles[24] = tmpFace[9];
	tiles[25] = tmpFace[10];
	tiles[26] = tmpFace[11];

	// b7 - b9
	tiles[33] = tmpFace[12];
	tiles[34] = tmpFace[13];
	tiles[35] = tmpFace[14];

	// l7 - l9
	tiles[42] = tmpFace[15];
	tiles[43] = tmpFace[16];
	tiles[44] = tmpFace[17];

	rotations += 1;
}

void Cube::topRegular() {
	tmpFace = { tiles[9], tiles[10], tiles[11], tiles[12], tiles[13], tiles[14], tiles[15], tiles[16], tiles[17], tiles[47], tiles[46], tiles[45], tiles[18], tiles[21], tiles[24], tiles[2], tiles[1], tiles[0], tiles[44], tiles[41], tiles[38] };

	tiles[9] = tmpFace[6];
	tiles[10] = tmpFace[3];
	tiles[11] = tmpFace[0];
	tiles[12] = tmpFace[7];
	tiles[13] = tmpFace[4];
	tiles[14] = tmpFace[1];
	tiles[15] = tmpFace[8];
	tiles[16] = tmpFace[5];
	tiles[17] = tmpFace[2];
	tiles[47] = tmpFace[18];
	tiles[46] = tmpFace[19];
	tiles[45] = tmpFace[20];
	tiles[18] = tmpFace[9];
	tiles[21] = tmpFace[10];
	tiles[24] = tmpFace[11];
	tiles[2] = tmpFace[12];
	tiles[1] = tmpFace[13];
	tiles[0] = tmpFace[14];
	tiles[44] = tmpFace[15];
	tiles[41] = tmpFace[16];
	tiles[38] = tmpFace[17];

	rotations += 1;
}

// misc
void Cube::print() {
	std::string spacer = "       ";
	std::string fancyLine = "------------------------";

	std::string f1 = ' ' + colorCoder(tiles[0]) + ' ' + colorCoder(tiles[1]) + ' ' + colorCoder(tiles[2]) + ' ';
	std::string f2 = ' ' + colorCoder(tiles[3]) + ' ' + colorCoder(tiles[4]) + ' ' + colorCoder(tiles[5]) + ' ';
	std::string f3 = ' ' + colorCoder(tiles[6]) + ' ' + colorCoder(tiles[7]) + ' ' + colorCoder(tiles[8]) + ' ';

	std::string t1 = ' ' + colorCoder(tiles[9]) + ' ' + colorCoder(tiles[10]) + ' ' + colorCoder(tiles[11]) + ' ';
	std::string t2 = ' ' + colorCoder(tiles[12]) + ' ' + colorCoder(tiles[13]) + ' ' + colorCoder(tiles[14]) + ' ';
	std::string t3 = ' ' + colorCoder(tiles[15]) + ' ' + colorCoder(tiles[16]) + ' ' + colorCoder(tiles[17]) + ' ';

	std::string r1 = ' ' + colorCoder(tiles[24]) + ' ' + colorCoder(tiles[21]) + ' ' + colorCoder(tiles[18]) + ' ';
	std::string r2 = ' ' + colorCoder(tiles[25]) + ' ' + colorCoder(tiles[22]) + ' ' + colorCoder(tiles[19]) + ' ';
	std::string r3 = ' ' + colorCoder(tiles[26]) + ' ' + colorCoder(tiles[23]) + ' ' + colorCoder(tiles[20]) + ' ';

	std::string b1 = ' ' + colorCoder(tiles[35]) + ' ' + colorCoder(tiles[34]) + ' ' + colorCoder(tiles[33]) + ' ';
	std::string b2 = ' ' + colorCoder(tiles[32]) + ' ' + colorCoder(tiles[31]) + ' ' + colorCoder(tiles[30]) + ' ';
	std::string b3 = ' ' + colorCoder(tiles[29]) + ' ' + colorCoder(tiles[28]) + ' ' + colorCoder(tiles[27]) + ' ';

	std::string l1 = ' ' + colorCoder(tiles[38]) + ' ' + colorCoder(tiles[41]) + ' ' + colorCoder(tiles[44]) + ' ';
	std::string l2 = ' ' + colorCoder(tiles[37]) + ' ' + colorCoder(tiles[40]) + ' ' + colorCoder(tiles[43]) + ' ';
	std::string l3 = ' ' + colorCoder(tiles[36]) + ' ' + colorCoder(tiles[39]) + ' ' + colorCoder(tiles[42]) + ' ';

	std::string x1 = ' ' + colorCoder(tiles[45]) + ' ' + colorCoder(tiles[46]) + ' ' + colorCoder(tiles[47]) + ' ';
	std::string x2 = ' ' + colorCoder(tiles[48]) + ' ' + colorCoder(tiles[49]) + ' ' + colorCoder(tiles[50]) + ' ';
	std::string x3 = ' ' + colorCoder(tiles[51]) + ' ' + colorCoder(tiles[52]) + ' ' + colorCoder(tiles[53]) + ' ';


	std::vector<std::string> lines;

	lines.push_back(spacer + ' ' + t1     + ' ' + spacer);
	lines.push_back(spacer + ' ' + t2     + ' ' + spacer);
	lines.push_back(spacer + ' ' + t3     + ' ' + spacer);

	lines.push_back(spacer + ' ' + spacer + ' ' + spacer);

	lines.push_back(l1     + ' ' + f1     + ' ' + r1);
	lines.push_back(l2     + ' ' + f2     + ' ' + r2);
	lines.push_back(l3     + ' ' + f3     + ' ' + r3);

	lines.push_back(spacer + ' ' + spacer + ' ' + spacer);

	lines.push_back(spacer + ' ' + b1     + ' ' + x1);
	lines.push_back(spacer + ' ' + b2     + ' ' + x2);
	lines.push_back(spacer + ' ' + b3     + ' ' + x3);

	for (std::string line : lines) {
		std::cout << line << std::endl;
	}
	std::cout << fancyLine << std::endl;
}

std::string Cube::colorCoder(COLORS color) {
	if (color == W) return "W";
	if (color == G) return "G";
	if (color == O) return "O";
	if (color == B) return "B";
	if (color == R) return "R";
	if (color == Y) return "Y";
}

int Cube::solvedChecker() {
	if (tiles == defaultCube) return rotations;
	else return -1;
}