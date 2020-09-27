#include <iostream>
#include <vector>
#include <bits/stdc++.h>

const int max_inserts = 7;
int grades_array_sum;
float grades_array_average;
int input;

void giving_grades()
{
    std::vector<int> grades{};
    std::cout << "Insert grades from 1-10: " << std::endl;

    for(int i = 0; i < max_inserts; i++)
    {
        std::cin >> input;
        if(input > 0 && input < 11)
        {
            grades.push_back(input);
        }
        else if(input > 10)
        {
            std::cout << "Grade was too high... 1-10... try again: " << std::endl;
            std::cin >> input;
            grades.push_back(input);
        }
        else if(input < 10)
        {
            std::cout << "Grade was too high... 1-10... try again: " << std::endl;
            std::cin >> input;
            grades.push_back(input);
        }
    }

    float min = *std::min_element(grades.begin(), grades.end());
    float max = *std::max_element(grades.begin(), grades.end());

    std::cout << "Average grade is: " << std::endl;

    grades_array_sum = std::accumulate(grades.begin(), grades.end(), 0);

    grades_array_average = (grades_array_sum / grades.size());

    std::cout << grades_array_average << std::endl;

    std::cout << "You inserted the following: " << std::endl;
    for(int i = 0; i < grades.size(); i++)
    {
        std::cout << i+1 << ". grade was: " << grades[i] << std::endl;
        if (grades[i] > grades_array_average)
        {
            std::cout << i+1 << ". grade: " << grades[i] << " difference between average is: " << grades[i] - grades_array_average << std::endl;
        }
        else if (grades[i] < grades_array_average)
        {
            std::cout << i+1 << ". grade: " << grades[i] << " difference between average is: " << grades_array_average - grades[i] << std::endl;
        }
        std::cout << "\n";
    }

    if ((grades_array_average - min) > (max - grades_array_average))
    {
        std::cout << "Grade " << min << " has the most difference between the average grade... which is: " << grades_array_average << std::endl;
    }

    else if ((grades_array_average - min) < (max - grades_array_average))
    {
        std::cout << "Grade " << max << " has the most difference between the average grade... which is: " << grades_array_average << std::endl;
    }
    
    else
    {
        std::cout << "Grade " << min << " has the most difference between the average grade... which is: " << grades_array_average << std::endl;
    }

    std::cout << " " << std::endl;
}

int main()
{
    giving_grades();
    return 0;
}
