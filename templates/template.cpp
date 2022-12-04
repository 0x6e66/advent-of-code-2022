#include <iostream>
#include <fstream>

std::string file_path = "test_input.txt";

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(file_path);

    while (getline(file, line))
    {

    }
    return 0;
}
