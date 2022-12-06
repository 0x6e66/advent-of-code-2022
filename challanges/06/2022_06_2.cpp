#include <iostream>
#include <fstream>
#include <vector>
#include <set>

std::string file_path = "input.txt";

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(file_path);

    while (getline(file, line))
    {
        for (size_t i = 13; i < line.length(); i++)
        {
            std::set<char> tmp_set;
            for (size_t j = 0; j < 14; j++)
            {
                tmp_set.insert(line[i-j]);
            }

            if (tmp_set.size() == 14)
            {
                std::cout << i + 1 << "\n";
                break;
            }
        }
    }

    return 0;
}
