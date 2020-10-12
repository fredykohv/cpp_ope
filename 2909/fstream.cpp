#include <fstream>
#include <iostream>
#include <string>

std::ofstream of_file;
std::string line;
std::string file_name = "info.txt";
std::ifstream if_file (file_name);

void create_a_file()
{
    of_file.open(file_name);
    of_file << "Testing line\n";
    of_file.close();
}

void read_from_file()
{
    if (if_file.is_open())
    {
        while( getline (if_file, line))
        {
            std::cout << line << '\n';
        }
        if_file.close();
    }
}

int main()
{
    create_a_file();
    read_from_file();
    return 0;
}