#include "../util/int_types.hpp"

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <stdio.h>

std::fstream file;
std::string el_paso, tallinn, london;
std::vector<std::string> el_paso_data{};
std::vector<std::string> tallinn_data{};
std::vector<std::string> london_data{};
int lines = 0;

void read_edit_file()
{
    file.open("temperatures.txt");

    /*---- Tallinn start ----*/

    getline(file, tallinn, ' ');
    tallinn_data.push_back(tallinn);

    for (int i = 0; i < 6; i++)
    {
        getline(file, tallinn, ' ');
        tallinn_data.push_back(tallinn);
    }

    tallinn_data.erase(tallinn_data.begin(), tallinn_data.begin()+1);

    /*---- Tallinn end ----*/

    /*---- London start ----*/

    getline(file, london, '\n');

    getline(file, london, ' ');
    london_data.push_back(london);

    for (int i = 0; i < 6; i++)
    {
        getline(file,london, ' ');
        london_data.push_back(london);
    }

    london_data.erase(london_data.begin(), london_data.begin()+1);

    /*---- London end ----*/

    /*---- El paso start ----*/

    getline(file, el_paso, '\n');

    getline(file, el_paso, ' ');
    el_paso_data.push_back(el_paso);

    for (int i = 0; i < 6; i++)
    {
        getline(file, el_paso, ';');
        el_paso_data.push_back(el_paso);
    }

    el_paso_data.erase(el_paso_data.begin(), el_paso_data.begin()+1);

    /*---- El paso end ----*/

    file.close();
}

s32 main()
{
    read_edit_file();

    for (int i = 0; i < tallinn_data.size(); i++)
    {
        std::cout << tallinn_data[i] << std::endl;
    }

    for (int i = 0; i < london_data.size(); i++)
    {
        std::cout << london_data[i] << std::endl;
    }

    for (int i = 0; i < el_paso_data.size(); i++)
    {
        std::cout << el_paso_data[i] << std::endl;
    }
}
