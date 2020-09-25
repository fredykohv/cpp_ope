#include <iostream>
#include <vector>
#include <bits/stdc++.h> 

void distance_between_earth_and_moon()
{
    bool running = true;
    float input;
    const int average_distance = 384400;
    float resolution = (average_distance / 100) * 3;
    float plausible_answer_min = average_distance - resolution;
    float plausible_answer_max = average_distance + resolution;
    
    std::cout << "What is the distance between earth and moon?" << std::endl;

    std::vector<float> range{plausible_answer_min, plausible_answer_max};

    float min = *std::min_element(range.begin(), range.end());
    float max = *std::max_element(range.begin(), range.end());

    while(running)
    {
        std::cin >> input;

        if(input == average_distance || input >= min && input <= max)
        {
            running = false;
            std::cout << "You entered: " << input << " and you guessed it right!" << std::endl; 
        }
        else if (input == 0)
        {
            running = false;
            std::cout << "You quit" << std::endl;
        }
        else if (input < min)
        {
            std::cout << "try again! you entered " << input << std::endl;
            std::cout << "your guess was lower than anticipated" << std::endl;
        }
        else if (input > max)
        {
            std::cout << "try again! you entered " << input << std::endl;
            std::cout << "your guess was higher than anticipated" << std::endl;
        }
    }
}

int main()
{
    distance_between_earth_and_moon();
    return 0;
}