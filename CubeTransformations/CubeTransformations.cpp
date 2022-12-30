#include <iostream>
#include "Cube.h"

// TODO: user input for transformation pattern
int main()
{
    Cube cube;

    int rotations = -1;
    while (rotations < 0) {
        cube.frontRegular();
        cube.rightRegular();
        cube.frontPrime();
        cube.rightPrime();

        rotations = cube.solvedChecker();
    }

    std::cout << "Finished in " << rotations << " rotations." << std::endl;
}

