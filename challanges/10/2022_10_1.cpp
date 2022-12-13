#include <iostream>
#include <fstream>

std::string file_path = "input.txt";

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(file_path);

    int x = 1;
    int cycles = 0;

    int sum_signal_strength = 0;

    while (getline(file, line))
    {
        std::string command = line.substr(0, 4);
        if (command == "addx")
        {
            int num = std::stoi(line.substr(5, line.length()), nullptr, 10);
            sum_signal_strength += (++cycles >= 20 && (cycles - 20) % 40 == 0) * cycles * x;
            sum_signal_strength += (++cycles >= 20 && (cycles - 20) % 40 == 0) * cycles * x;
            x += num;
        }
        else
        {
            sum_signal_strength += (++cycles >= 20 && (cycles - 20) % 40 == 0) * cycles * x;
        }
    }
    std::cout << sum_signal_strength << "\n";
    return 0;
}
