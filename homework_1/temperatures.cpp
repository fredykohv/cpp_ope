#include <iostream>
#include <string>
#include <vector>

int temperature;
int hot_temperature = 26;
int cold_temperature = 9;

std::vector<std::string> hot_warm_cold{"hot!", "cold!", "warm!"};


int hot_cold_warm_temperature()
{
    if (temperature >= hot_temperature)
    {
        std::cout << hot_warm_cold[0] << std::endl;
    }
    else if (temperature <= cold_temperature)
    {
        std::cout << hot_warm_cold[1] << std::endl;
    }
    else if (temperature > cold_temperature && temperature < hot_temperature)
    {
        std::cout << hot_warm_cold[2] << std::endl;
    }

    return 0;
}

int main()
{
    std::cout << "Enter the temperature!" << std::endl;
    std::cin >> temperature;
    
    hot_cold_warm_temperature();
}
