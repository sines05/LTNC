#include <iostream>
#include <vector>
#include <random>
#include <string>

const char MINE = '*';
const char FREE = '.';
const char TRIED = '0';

void display(const std::vector<std::vector<char>>& field) {
    for (const auto& row : field) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int m, n, K;
    std::cout << "Enter the size of the minefield (m, n) and number of mines (K): ";
    std::cin >> m >> n >> K;


    std::vector<std::vector<char>> field(m, std::vector<char>(n, FREE));


    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, m * n - 1);
    for (int k = 0; k < K; ++k) {
        int pos = dis(gen);
        field[pos / n][pos % n] = MINE;
    }


    while (true) {
        display(field);

        int x, y;
        std::cout << "Enter your next try (x, y): ";
        std::cin >> x >> y;

        if (field[x][y] == MINE) {
            std::cout << "YOU'RE DEAD!\n";
            display(field);
            break;
        } else {
            field[x][y] = TRIED;
        }
    }

    return 0;
}
