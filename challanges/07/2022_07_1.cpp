#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <map>

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

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(file_path);

    std::string current_dir = "";
    std::map<std::string, int> files;

    while (getline(file, line))
    {
        std::vector<std::string> splitted_line = split_str(line, ' ');

        if (splitted_line.size() == 3 && splitted_line[0] == "$" && splitted_line[1] == "cd")
        {
            if (splitted_line[2] == "..")
            {
                current_dir = current_dir.substr(0, current_dir.find_last_of('/'));
            }
            else if (splitted_line[2] != "/")
            {
                current_dir += "/" + splitted_line[2];
            }
        }
        else if (splitted_line[0] != "$" && splitted_line[0] != "dir")
        {
            files[current_dir + "/" + splitted_line[1]] = std::stoi(splitted_line[0], nullptr, 10);
        }
    }

    std::map<std::string, int> folders;
    for (auto itr = files.begin(); itr != files.end(); itr++)
    {
        auto file_name = itr->first;

        while (file_name != "")
        {
            file_name = file_name.substr(0, file_name.find_last_of('/'));
            folders[file_name] += itr->second;
        }
        folders["/"] += itr->second;
    }

    int sum = 0;
    for (auto itr = folders.begin(); itr != folders.end(); itr++)
    {
        if (itr->second <= 100000)
        {
            sum += itr->second;
        }
    }

    std::cout << sum << "\n";

    return 0;
}
