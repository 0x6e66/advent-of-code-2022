#include <iostream>
#include <fstream>
#include <vector>

std::string file_path = "input.txt";

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(file_path);

    int x = 1;
    int cycles = 0;
    std::vector<int> sprite_pos = {0, 1, 2};

    while (getline(file, line))
    {
        std::string command = line.substr(0, 4);
        if (command == "addx")
        {
            int num = std::stoi(line.substr(5, line.length()), nullptr, 10);
            for (size_t i = 0; i < 2; i++)
            {
                if (x - 1 <= cycles % 40 && cycles % 40 <= x + 1)
                {
                    std::cout << "#";
                }
                else
                {
                    std::cout << ".";
                }
                cycles++;

                if (cycles % 40 == 0)
                {
                    std::cout << "\n";
                }
            }
            
            x += num;
        }
        else
        {
            if (x - 1 <= cycles % 40 && cycles % 40 <= x + 1)
            {
                std::cout << "#";
            }
            else
            {
                std::cout << ".";
            }
            cycles++;
            if (cycles % 40 == 0)
            {
                std::cout << "\n";
            }
        }
    }

    return 0;
}
