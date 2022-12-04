#include <iostream>
#include <fstream>
#include <map>
#include <vector>

std::string file_path = "input.txt";

int get_priority_from_item_type(const char item_type)
{
    int item_ascii = int(item_type);
    if (65 <= item_ascii && item_ascii <= 90)
    {
        return item_ascii - 65 + 27;
    }
    return item_ascii - 97 + 1;
}

const char get_only_shared_item_type(std::vector<std::string> group)
{
    std::map<char, int> chars;

    for (size_t i = 0; i < group.size(); i++)
    {
        for (size_t j = 0; j < group[i].size(); j++)
        {
            if (i == 2 && chars[group[i][j]] == 2) return group[i][j];
            if (chars[group[i][j]] == i) chars[group[i][j]] = i + 1;
        }
    }

    return '#';
}

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(file_path);

    int score = 0;

    int cycle = 1;
    std::vector<std::string> group = {};
    while (getline(file, line))
    {
        group.push_back(line);
        if (cycle % 3 == 0)
        {
            const char tmp = get_only_shared_item_type(group);
            score += get_priority_from_item_type(tmp);
            group.clear();
        }
        cycle++;
    }

    std::cout << score << "\n";
    return 0;
}
