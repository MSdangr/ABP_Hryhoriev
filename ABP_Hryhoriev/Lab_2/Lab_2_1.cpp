#include <iostream>
#include <cmath>

using namespace std;

int Lab_2_1() {
    constexpr int width = 40;
    constexpr int height = 20;
    constexpr double radius = 10.0;


    char grid[height][width];


    for (auto& row : grid) {
        for (auto& cell : row) {
            cell = ' ';
        }
    }


    for (int i = 0; i < 100; ++i) {
        double angle = M_PI + i * M_PI / 100;
        int x = static_cast<int>(radius * cos(angle)) + width / 2;
        int y = static_cast<int>(radius * sin(angle)) + height / 2;


        if (x >= 0 && x < width && y >= 0 && y < height) {
            grid[y][x] = '#';
        }
    }


    for (int y = height / 2; y < height; ++y) {
        for (int x = width / 2 - static_cast<int>(radius); x < width / 2 + static_cast<int>(radius); ++x) {
            if (x >= 0 && x < width && y >= 0 && y < height) {
                grid[y][x] = '#';
            }
        }
    }


    for (const auto& row : grid) {
        for (const auto& cell : row) {
            cout << cell;
        }
        cout << endl;
    }

    return 0;
}
