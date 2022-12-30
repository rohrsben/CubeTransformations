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
		tiles[33],
		tiles[34],
		tiles[35],
		tiles[0],
		tiles[1],
		tiles[2],
		tiles[3],
		tiles[4],
		tiles[5],
		tiles[6],
		tiles[7],
		tiles[8],
		tiles[42],
		tiles[43],
		tiles[44],
		tiles[24],
		tiles[25],
		tiles[26],
		tiles[15],
		tiles[16],
		tiles[17]
	};

	tiles[33] = tmpFace[15];
	tiles[34] = tmpFace[16];
	tiles[35] = tmpFace[17];
	tiles[0] = tmpFace[9];
	tiles[1] = tmpFace[6];
	tiles[2] = tmpFace[3];
	tiles[3] = tmpFace[10];
	tiles[4] = tmpFace[7];
	tiles[5] = tmpFace[4];
	tiles[6] = tmpFace[11];
	tiles[7] = tmpFace[8];
	tiles[8] = tmpFace[5];
	tiles[42] = tmpFace[0];
	tiles[43] = tmpFace[1];
	tiles[44] = tmpFace[2];
	tiles[24] = tmpFace[18];
	tiles[25] = tmpFace[19];
	tiles[26] = tmpFace[20];
	tiles[15] = tmpFace[12];
	tiles[16] = tmpFace[13];
	tiles[17] = tmpFace[14];

	rotations += 1;
}

void Cube::topRegular() {
	tmpFace = {
		tiles[0],
		tiles[1],
		tiles[2],
		tiles[38],
		tiles[41],
		tiles[44],
		tiles[18],
		tiles[21],
		tiles[24],
		tiles[9],
		tiles[10],
		tiles[11],
		tiles[12],
		tiles[13],
		tiles[14],
		tiles[15],
		tiles[16],
		tiles[17],
		tiles[45],
		tiles[46],
		tiles[47]
	};

	tiles[0] = tmpFace[8];
	tiles[1] = tmpFace[7];
	tiles[2] = tmpFace[6];
	tiles[38] = tmpFace[0];
	tiles[41] = tmpFace[1];
	tiles[44] = tmpFace[2];
	tiles[18] = tmpFace[20];
	tiles[21] = tmpFace[19];
	tiles[24] = tmpFace[18];
	tiles[9] = tmpFace[15];
	tiles[10] = tmpFace[12];
	tiles[11] = tmpFace[9];
	tiles[12] = tmpFace[16];
	tiles[13] = tmpFace[13];
	tiles[14] = tmpFace[10];
	tiles[15] = tmpFace[17];
	tiles[16] = tmpFace[14];
	tiles[17] = tmpFace[11];
	tiles[45] = tmpFace[3];
	tiles[46] = tmpFace[4];
	tiles[47] = tmpFace[5];

	rotations += 1;
}

void Cube::rightRegular() {
	tmpFace = {
		tiles[27],
		tiles[30],
		tiles[33],
		tiles[2],
		tiles[5],
		tiles[8],
		tiles[18],
		tiles[19],
		tiles[20],
		tiles[21],
		tiles[22],
		tiles[23],
		tiles[24],
		tiles[25],
		tiles[26],
		tiles[11],
		tiles[14],
		tiles[17],
		tiles[45],
		tiles[48],
		tiles[51]
	};

	tiles[27] = tmpFace[18];
	tiles[30] = tmpFace[19];
	tiles[33] = tmpFace[20];
	tiles[2] = tmpFace[2];
	tiles[5] = tmpFace[1];
	tiles[8] = tmpFace[0];
	tiles[18] = tmpFace[12];
	tiles[19] = tmpFace[9];
	tiles[20] = tmpFace[6];
	tiles[21] = tmpFace[13];
	tiles[22] = tmpFace[10];
	tiles[23] = tmpFace[7];
	tiles[24] = tmpFace[14];
	tiles[25] = tmpFace[11];
	tiles[26] = tmpFace[8];
	tiles[11] = tmpFace[3];
	tiles[14] = tmpFace[4];
	tiles[17] = tmpFace[5];
	tiles[45] = tmpFace[17];
	tiles[48] = tmpFace[16];
	tiles[51] = tmpFace[15];

	rotations += 1;
}

void Cube::leftRegular() {
	tmpFace = {
		tiles[29],
		tiles[32],
		tiles[35],
		tiles[0],
		tiles[3],
		tiles[6],
		tiles[36],
		tiles[37],
		tiles[38],
		tiles[39],
		tiles[40],
		tiles[41],
		tiles[42],
		tiles[43],
		tiles[44],
		tiles[9],
		tiles[12],
		tiles[15],
		tiles[47],
		tiles[50],
		tiles[53]
	};

	tiles[29] = tmpFace[5];
	tiles[32] = tmpFace[4];
	tiles[35] = tmpFace[3];
	tiles[0] = tmpFace[15];
	tiles[3] = tmpFace[16];
	tiles[6] = tmpFace[17];
	tiles[36] = tmpFace[12];
	tiles[37] = tmpFace[9];
	tiles[38] = tmpFace[6];
	tiles[39] = tmpFace[13];
	tiles[40] = tmpFace[10];
	tiles[41] = tmpFace[7];
	tiles[42] = tmpFace[14];
	tiles[43] = tmpFace[11];
	tiles[44] = tmpFace[8];
	tiles[9] = tmpFace[20];
	tiles[12] = tmpFace[19];
	tiles[15] = tmpFace[18];
	tiles[47] = tmpFace[0];
	tiles[50] = tmpFace[1];
	tiles[53] = tmpFace[2];

	rotations += 1;
}

void Cube::bottomRegular() {
	tmpFace = {
		tiles[27],
		tiles[28],
		tiles[29],
		tiles[30],
		tiles[31],
		tiles[32],
		tiles[33],
		tiles[34],
		tiles[35],
		tiles[6],
		tiles[7],
		tiles[8],
		tiles[36],
		tiles[39],
		tiles[42],
		tiles[20],
		tiles[23],
		tiles[26],
		tiles[51],
		tiles[52],
		tiles[53]
	};

	tiles[27] = tmpFace[6];
	tiles[28] = tmpFace[3];
	tiles[29] = tmpFace[0];
	tiles[30] = tmpFace[7];
	tiles[31] = tmpFace[4];
	tiles[32] = tmpFace[1];
	tiles[33] = tmpFace[8];
	tiles[34] = tmpFace[5];
	tiles[35] = tmpFace[2];
	tiles[6] = tmpFace[12];
	tiles[7] = tmpFace[13];
	tiles[8] = tmpFace[14];
	tiles[36] = tmpFace[18];
	tiles[39] = tmpFace[19];
	tiles[42] = tmpFace[20];
	tiles[20] = tmpFace[11];
	tiles[23] = tmpFace[10];
	tiles[26] = tmpFace[9];
	tiles[51] = tmpFace[17];
	tiles[52] = tmpFace[16];
	tiles[53] = tmpFace[15];

	rotations += 1;
}

void Cube::backRegular() {
	tmpFace = {
		tiles[27],
		tiles[28],
		tiles[29],
		tiles[36],
		tiles[37],
		tiles[38],
		tiles[18],
		tiles[19],
		tiles[20],
		tiles[9],
		tiles[10],
		tiles[11],
		tiles[45],
		tiles[46],
		tiles[47],
		tiles[48],
		tiles[49],
		tiles[50],
		tiles[51],
		tiles[52],
		tiles[53]
	};

	tiles[27] = tmpFace[3];
	tiles[28] = tmpFace[4];
	tiles[29] = tmpFace[5];
	tiles[36] = tmpFace[9];
	tiles[37] = tmpFace[10];
	tiles[38] = tmpFace[11];
	tiles[18] = tmpFace[0];
	tiles[19] = tmpFace[1];
	tiles[20] = tmpFace[2];
	tiles[9] = tmpFace[6];
	tiles[10] = tmpFace[7];
	tiles[11] = tmpFace[8];
	tiles[45] = tmpFace[18];
	tiles[46] = tmpFace[15];
	tiles[47] = tmpFace[12];
	tiles[48] = tmpFace[19];
	tiles[49] = tmpFace[16];
	tiles[50] = tmpFace[13];
	tiles[51] = tmpFace[20];
	tiles[52] = tmpFace[17];
	tiles[53] = tmpFace[14];

	rotations += 1;
}

void Cube::frontPrime() {
	frontRegular();
	frontRegular();
	frontRegular();
	rotations -= 2;
}

void Cube::topPrime() {
	topRegular();
	topRegular();
	topRegular();
	rotations -= 2;
}

void Cube::rightPrime() {
	rightRegular();
	rightRegular();
	rightRegular();
	rotations -= 2;
}

void Cube::leftPrime() {
	leftRegular();
	leftRegular();
	leftRegular();
	rotations -= 2;
}

void Cube::bottomPrime() {
	bottomRegular();
	bottomRegular();
	bottomRegular();
	rotations -= 2;
}

void Cube::backPrime() {
	backRegular();
	backRegular();
	backRegular();
	rotations -= 2;
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
	switch (color) {
		case W:
			return "W";
		case G:
			return "G";
		case O:
			return "O";
		case B:
			return "B";
		case R:
			return "R";
		case Y:
			return "Y";
	}
}

int Cube::solvedChecker() {
	if (tiles == defaultCube) return rotations;
	else return -1;
}