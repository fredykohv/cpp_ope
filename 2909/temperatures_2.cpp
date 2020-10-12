#include <iostream>
#include <fstream>
#include <string>
#include <../pugixml-1.10/src/pugixml.hpp>

std::string file_name = "temperatures.txt";
std::ofstream of_file;
std::ifstream if_file;

std::string el_paso = "El Paso 70 65 61 71 66";
std::string tallinn = "Tallinn 48 52 50 51 56";
std::string london = "London 65 67 50 51 56";

std::string el_paso_city;
std::string tallinn_city;
std::string london_city;

std::string el_paso_temperatures;
std::string tallinn_temperatures;
std::string london_temperatures;

void get_city_names()
{
    el_paso_city = el_paso.substr(0,7);
    tallinn_city = tallinn.substr(0, tallinn.find(" "));
    london_city = london.substr(0,london.find(" "));

    el_paso_temperatures = el_paso.substr(8, -1);
    tallinn_temperatures = tallinn.substr(tallinn.find(" "), -1);
    london_temperatures = london.substr(london.find(" "), -1);
}

int main()
{
    get_city_names();
    std::cout << el_paso_city << " " << tallinn_city << " " << london_city << std::endl;
    std::cout << el_paso_temperatures << "\n" << tallinn_temperatures << "\n" << london_temperatures << std::endl;
    return 0;
}