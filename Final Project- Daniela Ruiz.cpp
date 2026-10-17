#include <iostream>
#include <fstream>
using namespace std;

int main() {
    std::ifstream file("data_proj.txt");
     if (!file.is_open()) {
        std::cout << "Unable to open file\n.";
        return 1;
         }

    int x, y;
    string symbol;
    int maxX = 0;
    int maxY = 0;
   
    while (file >> x >> symbol >> y) {
        if (x > maxX) maxX = x;
        if (y > maxY) maxY = y;
        }
    
        file.close();

        const int cols = maxX + 1;
        const int rows = maxY + 1;

    string grid[rows][cols];



for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
        grid[r][c] = " ";
    }
}

file.open("data_proj.txt");
while (file >> x >> symbol >> y) {
    grid[y][x] = symbol;
}
file.close();

for (int r = 0; r < rows; ++r) {
    for (int c = 0; c < cols; ++c) {
        std::cout << grid[r][c];
    }
    std::cout << "\n";
}

    return 0;
}