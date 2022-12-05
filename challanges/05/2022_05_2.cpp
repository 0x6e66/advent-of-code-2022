#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

std::string file_path = "input.txt";

std::vector<std::string> split_str(std::string str, const char delim)
{
    std::vector<std::string> out;
    std::stringstream s(str);

    std::string s2;
    while (std::getline(s, s2, delim))
    {
        out.push_back(s2);
    }
    return out;
}

std::vector<std::vector<char>> get_crates(std::string file_path)
{
    std::string line;
    std::ifstream file(file_path);

    bool state = false;
    std::vector<std::vector<char>> crates;

    while (getline(file, line))
    {
        if (line == "")
            return crates;

        if (!state)
        {
            for (size_t i = 0; i < line.length() / 4 + 1; i++)
            {
                std::vector<char> vec;
                crates.push_back(vec);
            }
            state = true;
        }

        if (line.find_first_of('1') == std::string::npos)
        {
            for (size_t i = 0; i < line.length() / 4 + 1; i++)
            {
                if (line[i * 4 + 1] != ' ')
                    crates[i].insert(crates[i].begin(), line[i * 4 + 1]);
            }
        }
    }
    return crates;
}

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(file_path);

    bool state = false;
    std::vector<std::vector<char>> crates = get_crates(file_path);

    while (getline(file, line))
    {
        if (state)
        {
            std::vector<std::string> splitted_line = split_str(line, ' ');
            int num_of_crates = std::stoi(splitted_line[1], nullptr, 10);
            int from = std::stoi(splitted_line[3], nullptr, 10) - 1;
            int to = std::stoi(splitted_line[5], nullptr, 10) - 1;

            for (size_t i = crates[from].size() - num_of_crates; i < crates[from].size(); i++)
            {
                crates[to].push_back(crates[from][i]);
            }

            for (size_t i = 0; i < num_of_crates; i++)
            {
                crates[from].pop_back();
            }
        }

        if (line == "")
            state = true;
    }

    for (size_t i = 0; i < crates.size(); i++)
    {
        std::cout << crates[i].back();
    }
    std::cout << "\n";

    return 0;
}
