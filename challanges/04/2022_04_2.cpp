#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

std::string file_path = "input.txt";

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(file_path);

    int count = 0;

    while (getline(file, line))
    {
        std::string first = line.substr(0, line.find(","));
        int first_1 = std::stoi(first.substr(0, first.find("-")), nullptr, 10);
        int first_2 = std::stoi(first.substr(first.find("-") + 1, first.length()), nullptr, 10);

        std::string second = line.substr(line.find(",") + 1, line.length());
        int second_1 = std::stoi(second.substr(0, second.find("-")), nullptr, 10);
        int second_2 = std::stoi(second.substr(second.find("-") + 1, second.length()), nullptr, 10);

        /*  Case1  Case2    Case3   Case4
            1234    2345    12345    234
             2345  1234      234    12345
        */
        if ((first_1 <= second_1 && second_1 <= first_2) ||
            (second_1 <= first_1 && first_1 <= second_2) ||
            (first_1 <= second_1 && second_2 <= first_2) ||
            (second_1 <= first_1 && first_2 <= second_2))
        {
            count++;
        }
    }
    std::cout << count << "\n";
    return 0;
}
