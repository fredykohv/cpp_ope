#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <fstream>


std::vector<int> numbers{};
std::ofstream outfile ("third_task_numbers.txt");

int max_numbers = 20;
int random_number;

void random_numbers()
{
    srand(time(NULL));

    for (int i = 0; i < max_numbers; i++)
    {
        random_number = rand() % 80 + 1;
        //numbers.push_back(random_number);
        if (std::find(numbers.begin(), numbers.end(), random_number) != numbers.end())
        {
            i--;
        }
        else
        {
            numbers.push_back(random_number);
            std::cout << random_number << std::endl;

        }
    }

    std::sort(numbers.begin(), numbers.end(), std::greater<int>());

    for (int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << std::endl;
        outfile << numbers[i] << std::endl;     
    }

    outfile.close();

}

int main()
{
    random_numbers();
    return 0;
}