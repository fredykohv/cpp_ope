#include "../util/int_types.hpp"

#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <stdio.h>

float tallinn_avg_temperature;
float london_avg_temperature;
float el_paso_avg_temperature;

float tallinn_avg_without_extremes_temperature;
float london_avg_without_extremes_temperature;
float el_paso_avg_without_extremes_temperature;

int tallinn_temperature_sum = 0;
int london_temperature_sum = 0;
int el_paso_temperature_sum = 0;

int tallinn_temperature_sum_exluding_extremes = 0;
int london_temperature_sum_exluding_extremes = 0;
int el_paso_temperature_sum_exluding_extremes = 0;

int tallinn_coldest_temperature = 0;
int tallinn_warmest_temperature = 0;
int london_coldest_temperature = 0;
int london_warmest_temperature = 0;
int el_paso_coldest_temperature = 0;
int el_paso_warmest_temperature = 0;

std::fstream file;
std::string el_paso, tallinn, london;

std::vector<std::string> el_paso_data{};
std::vector<std::string> tallinn_data{};
std::vector<std::string> london_data{};

std::vector<int> el_paso_data_temperatures{};
std::vector<int> tallinn_data_temperatures{};
std::vector<int> london_data_temperatures{};

void read_edit_file()
{
    file.open("temperatures.txt");

    getline(file, tallinn, ' ');
    tallinn_data.push_back(tallinn);

    for (int i = 0; i < 6; i++)
    {
        getline(file, tallinn, ' ');
        tallinn_data.push_back(tallinn);
    }

    tallinn_data.erase(tallinn_data.begin(), tallinn_data.begin()+1);

    getline(file, london, '\n');

    getline(file, london, ' ');
    london_data.push_back(london);

    for (int i = 0; i < 6; i++)
    {
        getline(file,london, ' ');
        london_data.push_back(london);
    }

    london_data.erase(london_data.begin(), london_data.begin()+1);

    getline(file, el_paso, '\n');

    getline(file, el_paso, ' ');
    el_paso_data.push_back(el_paso);

    for (int i = 0; i < 6; i++)
    {
        getline(file, el_paso, ';');
        el_paso_data.push_back(el_paso);
    }

    el_paso_data.erase(el_paso_data.begin(), el_paso_data.begin()+1);

    file.close();
}

void sort_vectors_to_greatest_to_lowest()
{
    std::sort(tallinn_data_temperatures.begin(), tallinn_data_temperatures.end(), std::greater<int>());
    std::sort(london_data_temperatures.begin(), london_data_temperatures.end(), std::greater<int>());
    std::sort(el_paso_data_temperatures.begin(), el_paso_data_temperatures.end(), std::greater<int>());
}

void change_vector_type()
{
    for (int i = 1; i < tallinn_data.size(); i++)
    {
        int temperature = atoi(tallinn_data.at(i).c_str());
        tallinn_data_temperatures.push_back(temperature);
    }

    for (int i = 1; i < london_data.size(); i++)
    {
        int temperature = atoi(london_data.at(i).c_str());
        london_data_temperatures.push_back(temperature);
    }

    for (int i = 1; i < el_paso_data.size(); i++)
    {
        int temperature = atoi(el_paso_data.at(i).c_str());
        el_paso_data_temperatures.push_back(temperature);
    }
}

void average_temperature()
{
    for (int i = 0; i < tallinn_data_temperatures.size(); i++)
    {
        tallinn_temperature_sum = tallinn_temperature_sum + tallinn_data_temperatures[i];
    }

    tallinn_avg_temperature = (float)tallinn_temperature_sum / tallinn_data_temperatures.size();

    for (int i = 0; i < london_data_temperatures.size(); i++)
    {
        london_temperature_sum = london_temperature_sum + london_data_temperatures[i];
    }

    london_avg_temperature = (float)london_temperature_sum / london_data_temperatures.size();

    for (int i = 0; i < el_paso_data_temperatures.size(); i++)
    {
        el_paso_temperature_sum = el_paso_temperature_sum + el_paso_data_temperatures[i];
    }

    el_paso_avg_temperature = (float)el_paso_temperature_sum / el_paso_data_temperatures.size();
}

void warmest_coldest_temperature()
{
    tallinn_coldest_temperature = tallinn_data_temperatures[tallinn_data_temperatures.size()];
    tallinn_warmest_temperature = tallinn_data_temperatures[0];

    london_coldest_temperature = london_data_temperatures[london_data_temperatures.size()];
    london_warmest_temperature = london_data_temperatures[0];

    el_paso_coldest_temperature = el_paso_data_temperatures[el_paso_data_temperatures.size()];
    el_paso_warmest_temperature = el_paso_data_temperatures[0];
}

void average_excluding_extremes()
{
    tallinn_data_temperatures.erase(tallinn_data_temperatures.end());
    tallinn_data_temperatures.erase(tallinn_data_temperatures.begin());

    london_data_temperatures.erase(london_data_temperatures.end());
    london_data_temperatures.erase(london_data_temperatures.begin());

    el_paso_data_temperatures.erase(el_paso_data_temperatures.end());
    el_paso_data_temperatures.erase(el_paso_data_temperatures.begin());

    for (int i = 0; i < tallinn_data_temperatures.size(); i++)
    {
        tallinn_temperature_sum_exluding_extremes = tallinn_temperature_sum_exluding_extremes + tallinn_data_temperatures[i];
    }

    tallinn_avg_without_extremes_temperature = (float)tallinn_temperature_sum_exluding_extremes / tallinn_data_temperatures.size();

    for (int i = 0; i < london_data_temperatures.size(); i++)
    {
        london_temperature_sum_exluding_extremes = london_temperature_sum_exluding_extremes + london_data_temperatures[i];
    }

    london_avg_without_extremes_temperature = (float)london_temperature_sum_exluding_extremes / london_data_temperatures.size();

    for (int i = 0; i < el_paso_data_temperatures.size(); i++)
    {
        el_paso_temperature_sum_exluding_extremes = el_paso_temperature_sum_exluding_extremes + el_paso_data_temperatures[i];
    }

    el_paso_avg_without_extremes_temperature = (float)el_paso_temperature_sum_exluding_extremes / el_paso_data_temperatures.size();
}

s32 main()
{
    read_edit_file();

    change_vector_type();

    sort_vectors_to_greatest_to_lowest();
    

    /*average_temperature();
    std::cout << tallinn_data[0] << " average temperature is: " << tallinn_avg_temperature << std::endl;
    std::cout << london_data[0] << " average temperature is: " << london_avg_temperature << std::endl;
    std::cout << el_paso_data[0] << " average temperature is: " << el_paso_avg_temperature << std::endl;

    warmest_coldest_temperature();
    std::cout << tallinn_data[0] << " coldest temperature is: " << tallinn_coldest_temperature << " and warmest temperature is: " << tallinn_warmest_temperature << std::endl;
    std::cout << london_data[0] << " coldest temperature is: " << london_coldest_temperature << " and warmest temperature is: " << london_warmest_temperature << std::endl;
    std::cout << el_paso_data[0] << " coldest temperature is: " << el_paso_coldest_temperature << " and warmest temperature is: " << el_paso_warmest_temperature << std::endl;*/

    average_excluding_extremes();
    std::cout << tallinn_data[0] << " average temperature excluding extremes is: " << tallinn_avg_without_extremes_temperature << std::endl;
    std::cout << london_data[0] << " average temperature excluding extremes is: " << london_avg_without_extremes_temperature << std::endl;
    std::cout << el_paso_data[0] << " average temperature excluding extremes is: " << el_paso_avg_without_extremes_temperature << std::endl;
}
