#include <iostream>
#include <fstream>
#include <set>
#include <sstream>
#include <vector>
#include <cmath>

std::string file_path = "input.txt";

std::vector<std::pair<int, int>> snake = {
    {0, 0}, // Head
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0},
    {0, 0} // Tail
};
std::set<std::string> visits = {
    {"0:0"}};

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(file_path);

    char move_dir;

    while (getline(file, line))
    {
        int move_amount = std::stoi(line.substr(1, line.length()));
        move_dir = line[0];

        for (size_t _ = 0; _ < move_amount; _++)
        {
            switch (move_dir)
            {
            case 'U':
                snake[0].second++;
                break;
            case 'D':
                snake[0].second--;
                break;
            case 'L':
                snake[0].first--;
                break;
            case 'R':
                snake[0].first++;
                break;
            }

            for (size_t j = 1; j < snake.size(); j++)
            {
                std::stringstream ss;
                ss << snake[j - 1].first - snake[j].first << ":" << snake[j - 1].second - snake[j].second;

                // Right
                if (ss.str() == "2:1")
                {
                    snake[j].first++;
                    snake[j].second++;
                }
                else if (ss.str() == "2:0")
                {
                    snake[j].first++;
                }
                else if (ss.str() == "2:-1")
                {
                    snake[j].first++;
                    snake[j].second--;
                }

                // Left
                else if (ss.str() == "-2:1")
                {
                    snake[j].first--;
                    snake[j].second++;
                }
                else if (ss.str() == "-2:0")
                {
                    snake[j].first--;
                }
                else if (ss.str() == "-2:-1")
                {
                    snake[j].first--;
                    snake[j].second--;
                }

                // Up
                else if (ss.str() == "-1:2")
                {
                    snake[j].first--;
                    snake[j].second++;
                }
                else if (ss.str() == "0:2")
                {
                    snake[j].second++;
                }
                else if (ss.str() == "1:2")
                {
                    snake[j].first++;
                    snake[j].second++;
                }

                // Down
                else if (ss.str() == "-1:-2")
                {
                    snake[j].first--;
                    snake[j].second--;
                }
                else if (ss.str() == "0:-2")
                {
                    snake[j].second--;
                }
                else if (ss.str() == "1:-2")
                {
                    snake[j].first++;
                    snake[j].second--;
                }

                // Diagonal

                else if (ss.str() == "2:2")
                {
                    snake[j].first++;
                    snake[j].second++;
                }
                else if (ss.str() == "2:-2")
                {
                    snake[j].first++;
                    snake[j].second--;
                }
                else if (ss.str() == "-2:2")
                {
                    snake[j].first--;
                    snake[j].second++;
                }
                else if (ss.str() == "-2:-2")
                {
                    snake[j].first--;
                    snake[j].second--;
                }
            }
            std::stringstream ss;
            ss << snake[snake.size() - 1].first << ":" << snake[snake.size() - 1].second;
            visits.insert(ss.str());;
        }
    }

    std::cout << visits.size() << "\n";
    return 0;
}
