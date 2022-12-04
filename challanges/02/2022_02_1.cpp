#include <iostream>
#include <vector>
#include <fstream>
#include <map>

std::string file_path = "input.txt";

std::map<std::string, std::pair<int, int>> plays = {
    {"AX", {1, 3}},
    {"AY", {2, 6}},
    {"AZ", {3, 0}},
    {"BX", {1, 0}},
    {"BY", {2, 3}},
    {"BZ", {3, 6}},
    {"CX", {1, 6}},
    {"CY", {2, 0}},
    {"CZ", {3, 3}}};

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(file_path);

    int score = 0;

    while (getline(file, line))
    {
        std::string play = std::string() + line[0] + line[2];
        std::pair<int, int> tmp = plays[play];
        score += tmp.first + tmp.second;
    }
    std::cout << score << "\n";
    return 0;
}
