#include <iostream>
#include <string>
#include "Cube.h"

int main()
{
    Cube test;
    int finished = -1;
    while (finished < 0) {
        test.topRegular();
        test.topRegular();
        test.topRegular();
        test.topRegular();
        test.topRegular();
        
        finished = test.solvedChecker();
    }

    std::cout << "Finished in " << finished << " rotations." << std::endl;
}