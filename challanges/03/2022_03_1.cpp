#include <iostream>
#include <fstream>
#include <map>

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

const char get_only_shared_item_type(std::string items)
{
    std::map<char, bool> chars;
    std::string first = items.substr(0, items.length() / 2);
    std::string second = items.substr(items.length() / 2, items.length());

    for (auto x : first)
    {
        chars[x] = true;
    }

    for (auto x : second)
    {
        if (chars[x])
        {
            return x;
        }
    }

    return '#';
}

int main(int argc, char const *argv[])
{
    std::string line;
    std::ifstream file(file_path);

    int score = 0;

    while (getline(file, line))
    {
        const char tmp = get_only_shared_item_type(line);
        score += get_priority_from_item_type(tmp);
    }

    std::cout << score << "\n";
    return 0;
}
