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
}

/* 
transformations are done as such:
	1. all tiles which are going to change/rotate are stored in to tmpFace
	2. on transform by transform basis, the tiles are replaced in /tiles/ with their corresponding tmp value
*/
void Cube::front() {
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
}

void Cube::print() {
	// TODO: print actual color codes instead of enum color value
	std::string spacer = "       ";
	std::string fancyLine = "------------------------";

	std::string f1 = ' ' + std::to_string(tiles[0]) + ' ' + std::to_string(tiles[1]) + ' ' + std::to_string(tiles[2]) + ' ';
	std::string f2 = ' ' + std::to_string(tiles[3]) + ' ' + std::to_string(tiles[4]) + ' ' + std::to_string(tiles[5]) + ' ';
	std::string f3 = ' ' + std::to_string(tiles[6]) + ' ' + std::to_string(tiles[7]) + ' ' + std::to_string(tiles[8]) + ' ';

	std::string t1 = ' ' + std::to_string(tiles[9]) + ' ' + std::to_string(tiles[10]) + ' ' + std::to_string(tiles[11]) + ' ';
	std::string t2 = ' ' + std::to_string(tiles[12]) + ' ' + std::to_string(tiles[13]) + ' ' + std::to_string(tiles[14]) + ' ';
	std::string t3 = ' ' + std::to_string(tiles[15]) + ' ' + std::to_string(tiles[16]) + ' ' + std::to_string(tiles[17]) + ' ';

	std::string r1 = ' ' + std::to_string(tiles[24]) + ' ' + std::to_string(tiles[21]) + ' ' + std::to_string(tiles[18]) + ' ';
	std::string r2 = ' ' + std::to_string(tiles[25]) + ' ' + std::to_string(tiles[22]) + ' ' + std::to_string(tiles[19]) + ' ';
	std::string r3 = ' ' + std::to_string(tiles[26]) + ' ' + std::to_string(tiles[23]) + ' ' + std::to_string(tiles[20]) + ' ';

	std::string b1 = ' ' + std::to_string(tiles[35]) + ' ' + std::to_string(tiles[34]) + ' ' + std::to_string(tiles[33]) + ' ';
	std::string b2 = ' ' + std::to_string(tiles[32]) + ' ' + std::to_string(tiles[31]) + ' ' + std::to_string(tiles[30]) + ' ';
	std::string b3 = ' ' + std::to_string(tiles[29]) + ' ' + std::to_string(tiles[28]) + ' ' + std::to_string(tiles[27]) + ' ';

	std::string l1 = ' ' + std::to_string(tiles[38]) + ' ' + std::to_string(tiles[41]) + ' ' + std::to_string(tiles[44]) + ' ';
	std::string l2 = ' ' + std::to_string(tiles[37]) + ' ' + std::to_string(tiles[40]) + ' ' + std::to_string(tiles[43]) + ' ';
	std::string l3 = ' ' + std::to_string(tiles[36]) + ' ' + std::to_string(tiles[39]) + ' ' + std::to_string(tiles[42]) + ' ';

	std::string x1 = ' ' + std::to_string(tiles[45]) + ' ' + std::to_string(tiles[46]) + ' ' + std::to_string(tiles[47]) + ' ';
	std::string x2 = ' ' + std::to_string(tiles[48]) + ' ' + std::to_string(tiles[49]) + ' ' + std::to_string(tiles[50]) + ' ';
	std::string x3 = ' ' + std::to_string(tiles[51]) + ' ' + std::to_string(tiles[52]) + ' ' + std::to_string(tiles[53]) + ' ';


	std::vector<std::string> lines;

	lines.push_back(spacer + ' ' + t1 + ' ' + spacer);
	lines.push_back(spacer + ' ' + t2 + ' ' + spacer);
	lines.push_back(spacer + ' ' + t3 + ' ' + spacer);

	lines.push_back(spacer + ' ' + spacer + ' ' + spacer);

	lines.push_back(l1 + ' ' + f1 + ' ' + r1);
	lines.push_back(l2 + ' ' + f2 + ' ' + r2);
	lines.push_back(l3 + ' ' + f3 + ' ' + r3);

	lines.push_back(spacer + ' ' + spacer + ' ' + spacer);

	lines.push_back(spacer + ' ' + b1 + ' ' + x1);
	lines.push_back(spacer + ' ' + b2 + ' ' + x2);
	lines.push_back(spacer + ' ' + b3 + ' ' + x3);

	for (std::string line : lines) {
		std::cout << line << std::endl;
	}
	std::cout << fancyLine << std::endl;
}