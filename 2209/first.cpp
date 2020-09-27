#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <fstream>
#include <numeric>
#include <bits/stdc++.h> 

std::vector<float> grades{};
float input;
float grades_sum;
int min_grade = 0;
int max_grade = 10;
int max_inputs = 5;


std::ofstream outfile ("dance_competition.txt");

void insert_grades()
{
    for(int i = 0; i < max_inputs; i++)
    {
        std::cin >> input;

        if(input > max_grade || input < min_grade)
        {
            std::cout << "Insert again... grade between 0 and 10" << std::endl;
            std::cin >> input;
        }

        grades.push_back(input);

    }

    /* float min = *std::min_element(grades.begin(), grades.end());
    float max = *std::max_element(grades.begin(), grades.end()); */

    std::sort(grades.begin(), grades.end(), std::greater<int>());

    grades.erase(grades.begin());
    grades.erase(grades.end() - 1);

    for(int i = 0; i < grades.size(); i++)
    {
        outfile << grades[i] << std::endl;
        std::cout << grades[i] << std::endl;
    }

    grades_sum = std::accumulate(grades.begin(), grades.end(), 0);
}

int main()
{
    std::cout << "Enter grades: " << std::endl;

    insert_grades();

    std::cout << "Sum of three average grades is: " << grades_sum << std::endl;
    outfile << "Sum of three average grades is: " << grades_sum << std::endl;

    return 0;
}