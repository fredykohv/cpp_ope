#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

std::string first_name;
std::string surname;
float input;
float difference_between_last_result;
int max_entries = 6;
std::vector<float> results{};
std::string custom_text = "_tulemused.txt";

void stats()
{
    std::cout << "What's your name: " << std::endl;

    std::cin >> first_name >> surname;

    std::ofstream outfile(first_name + "_" + surname + custom_text);

    outfile << "Name: " << std::endl;
    outfile << first_name << " " << surname << std::endl;

    std::cout << "Insert your 6 results: " << std::endl;
    outfile << " " << std::endl;
    outfile << "First 6 results: " << std::endl;

    for (int i = 0; i < max_entries; i++)
    {
        std::cin >> input;
        results.push_back(input);
        outfile << input << "m\n" << std::endl;
    }

    for (int i = 1; i < results.size(); i++)
    {
        if(results[i-1] < results[i])
        {
            difference_between_last_result = (results[i] - results[i-1]);
            std::cout << "Your result was better than last one by: " << difference_between_last_result << " meters!" << std::endl;
            outfile << "Your result was better than last one by: " << difference_between_last_result << " meters!" << std::endl;
        }
        else if(results[i-1] > results[i])
        {
            
            difference_between_last_result = (results[i-1] - results[i]);
            std::cout << "Your result was worse than last one by: " << difference_between_last_result << " meters!" << std::endl;
            outfile << "Your result was worse than last one by: " << difference_between_last_result << " meters!" << std::endl;
        }
    }

    std::sort(results.begin(), results.end(), std::greater<int>());

    outfile << "Best result: " << results[0] << std::endl;
    outfile << "Runner up: " << results[1] << std::endl;

    outfile.close();
}

int main()
{
    stats();
    return 0;
}



