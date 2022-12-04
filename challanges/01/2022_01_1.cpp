#include <iostream>
#include <vector>
#include <fstream>

std::string file_path = "input.txt";

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(file_path);

    int max_num = 0;
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
            if (tmp_num > max_num)
            {
                max_num = tmp_num;
            }
            tmp_num = 0;
        }
        cnt++;
    }
    std::cout << max_num << "\n";

    return 0;
}
