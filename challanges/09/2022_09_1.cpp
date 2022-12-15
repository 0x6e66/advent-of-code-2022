#include <iostream>
#include <fstream>
#include <set>
#include <sstream>

std::string file_path = "input.txt";

int head_x = 0;
int head_y = 0;

int tail_x = 0;
int tail_y = 0;

std::set<std::string> visits = {
    {"0:0"}};

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(file_path);

    while (getline(file, line))
    {
        int move_amount = std::stoi(line.substr(1, line.length()));
        if (line[0] == 'L')
        {
            for (size_t i = 0; i < move_amount; i++)
            {
                head_x--;
                if (tail_x > head_x + 1 && tail_y == head_y)
                {
                    tail_x = head_x + 1;
                    std::stringstream ss;
                    ss << tail_x << ":" << tail_y;
                    visits.insert(ss.str());
                }
                else if (tail_x > head_x + 1 && tail_y != head_y)
                {
                    tail_x = head_x + 1;
                    tail_y = head_y;
                    std::stringstream ss;
                    ss << tail_x << ":" << tail_y;
                    visits.insert(ss.str());
                }
            }
        }
        else if (line[0] == 'R')
        {
            for (size_t i = 0; i < move_amount; i++)
            {
                head_x++;
                if (tail_x < head_x - 1 && tail_y == head_y)
                {
                    tail_x = head_x - 1;
                    std::stringstream ss;
                    ss << tail_x << ":" << tail_y;
                    visits.insert(ss.str());
                }
                else if (tail_x < head_x - 1 && tail_y != head_y)
                {
                    tail_x = head_x - 1;
                    tail_y = head_y;
                    std::stringstream ss;
                    ss << tail_x << ":" << tail_y;
                    visits.insert(ss.str());
                }
            }
        }
        else if (line[0] == 'U')
        {
            for (size_t i = 0; i < move_amount; i++)
            {
                head_y++;
                if (tail_y < head_y - 1 && head_x == tail_x)
                {
                    tail_y = head_y - 1;
                    std::stringstream ss;
                    ss << tail_x << ":" << tail_y;
                    visits.insert(ss.str());
                }else if(tail_y < head_y - 1 && head_x != tail_x)
                {
                    tail_y = head_y - 1;
                    tail_x = head_x;
                    std::stringstream ss;
                    ss << tail_x << ":" << tail_y;
                    visits.insert(ss.str());
                }
            }
        }
        else if (line[0] == 'D')
        {
            for (size_t i = 0; i < move_amount; i++)
            {
                head_y--;
                if (tail_y > head_y + 1 && tail_x == head_x)
                {
                    tail_y = head_y + 1;
                    std::stringstream ss;
                    ss << tail_x << ":" << tail_y;
                    visits.insert(ss.str());
                }
                else if (tail_y > head_y + 1 && tail_x != head_x)
                {
                    tail_y = head_y + 1;
                    tail_x  = head_x;
                    std::stringstream ss;
                    ss << tail_x << ":" << tail_y;
                    visits.insert(ss.str());
                }
            }
        }
    }

    std::cout << visits.size() << "\n";
    return 0;
}
