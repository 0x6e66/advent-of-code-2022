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
        for (size_t i = 3; i < line.length(); i++)
        {
            std::set<char> tmp_set;
            tmp_set.insert(line[i - 3]);
            tmp_set.insert(line[i - 2]);
            tmp_set.insert(line[i - 1]);
            tmp_set.insert(line[i]);

            if (tmp_set.size() == 4)
            {
                std::cout << i + 1 << "\n";
                break;
            }
        }
    }

    return 0;
}
