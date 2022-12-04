#include <iostream>
#include <vector>
#include <fstream>

std::string file_path = "input.txt";

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(file_path);

    std::vector<int> calories = {0};
    int tmp_num = 0;

    int cnt = 0;
    while (getline(file, line))
    {
        if (line != "")
        {
            tmp_num += std::stoi(line, nullptr, 10);
        }
        else
        {
            for (size_t i = 0; i < calories.size(); i++)
            {
                if (tmp_num >= calories[i])
                {
                    
                    calories.insert(calories.begin() + i, tmp_num);
                    break;
                }
            }
            tmp_num = 0;
        }
        cnt++;
    }
    std::cout << calories[0] + calories[1] + calories[2] << "\n";

    return 0;
}
