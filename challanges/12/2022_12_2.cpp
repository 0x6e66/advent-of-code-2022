#include <iostream>
#include <fstream>
#include <vector>
#include <map>

std::string file_path = "input.txt";

std::vector<std::vector<char>> field;
std::pair<int, int> start;
std::pair<int, int> end;
std::vector<std::vector<int>> visited;
std::vector<std::string> chart;

int find(int x, int y, int d)
{
    visited[y][x] = d;
    if (x == end.first && y == end.second)
    {
        return 1;
    }

    int min = 10000;
    char dir = '.';

    // Check Up
    if (y > 0 && (field[y - 1][x] - field[y][x] <= 1) && visited[y - 1][x] > d + 1)
    {
        int steps = find(x, y - 1, d + 1);
        if (steps < min)
        {
            min = steps;
            dir = '^';
        }
    }

    // Check Left
    if (x > 0 && (field[y][x - 1] - field[y][x] <= 1) && visited[y][x - 1] > d + 1)
    {
        int steps = find(x - 1, y, d + 1);
        if (steps < min)
        {
            min = steps;
            dir = '<';
        }
    }

    // Check Right
    if (x < field[y].size() - 1 && (field[y][x + 1] - field[y][x] <= 1) && visited[y][x + 1] > d + 1)
    {
        int steps = find(x + 1, y, d + 1);
        if (steps < min)
        {
            min = steps;
            dir = '>';
        }
    }

    // Check Down
    if (y < field.size() - 1 && (field[y + 1][x] - field[y][x] <= 1) && visited[y + 1][x] > d + 1)
    {
        int steps = find(x, y + 1, d + 1);
        if (steps < min)
        {
            min = steps;
            dir = 'v';
        }
    }

    chart[y][x] = dir;

    return min + 1;
}

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(file_path);

    int y = 0;
    while (getline(file, line))
    {
        if (line.find("S") != std::string::npos)
        {
            start = {line.find("S"), y};
            line = line.replace(line.find("S"), 1, "a");
        }
        if (line.find("E") != std::string::npos)
        {
            end = {line.find("E"), y};
            line = line.replace(line.find("E"), 1, "z");
        }

        std::vector<char> tmp;
        std::string tmp_str = "";
        std::vector<int> tmp_vec;
        for (size_t i = 0; i < line.length(); i++)
        {
            tmp.push_back(line[i]);
            tmp_str += ".";
            tmp_vec.push_back(10000);
        }
        field.push_back(tmp);
        chart.push_back(tmp_str);
        visited.push_back(tmp_vec);
        y++;
    }

    int min = 10000;
    for (size_t i = 0; i < field.size(); i++)
    {
        for (size_t j = 0; j < field[i].size(); j++)
        {
            if (field[i][j] == 'a')
            {
                int tmp = find(j, i, 0)-1;
                if (tmp < min)
                {
                    min = tmp;
                }
            }
        }
    }

    std::cout << min << "\n";

    return 0;
}
