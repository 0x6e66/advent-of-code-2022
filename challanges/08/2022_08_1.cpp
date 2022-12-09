#include <iostream>
#include <fstream>
#include <vector>

std::string file_path = "input.txt";
std::vector<std::vector<int>> trees;

bool check_up(int x, int y)
{
    int tree_height = trees[y][x];

    for (int i = y - 1; i >= 0; i--)
    {
        if (trees[i][x] >= tree_height)
        {
            return false;
        }
    }
    return true;
}

bool check_down(int x, int y)
{
    int tree_height = trees[y][x];

    for (int i = y + 1; i < trees.size(); i++)
    {
        if (trees[i][x] >= tree_height)
        {
            return false;
        }
    }
    return true;
}
bool check_left(int x, int y)
{
    int tree_height = trees[y][x];

    for (int i = x - 1; i >= 0; i--)
    {
        if (trees[y][i] >= tree_height)
        {
            return false;
        }
    }
    return true;
}
bool check_right(int x, int y)
{
    int tree_height = trees[y][x];

    for (int i = x + 1; i < trees[y].size(); i++)
    {
        if (trees[y][i] >= tree_height)
        {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(file_path);

    while (getline(file, line))
    {
        std::vector<int> tmp;
        for (size_t i = 0; i < line.length(); i++)
        {
            const std::string s(1, line[i]);
            tmp.push_back(std::stoi(s, nullptr, 10));
        }
        trees.push_back(tmp);
    }

    int count = 2 * (trees.size() - 1) + 2 * (trees[0].size() - 1);
    for (size_t i = 1; i < trees.size() - 1; i++)
    {
        for (size_t j = 1; j < trees[j].size() - 1; j++)
        {
            count += check_down(j, i) || check_left(j,i) || check_right(j,i) || check_up(j,i);
        }
    }
    std::cout << count << "\n";
    return 0;
}
