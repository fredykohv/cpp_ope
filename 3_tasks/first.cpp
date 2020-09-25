#include <cmath>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <bits/stdc++.h> 

void insert_grades()
{
    std::cout << "Enter grades: " << std::endl;
    std::vector<float> grades{};
    float input;
    int min_grade = 0;
    int max_grade = 10;

    for(int i = 0; i < 5; i++)
    {
        std::cin >> input;

        if(input > max_grade)
        {
            input = 10;
        }
        else if(input < min_grade)
        {
            input = 0;
        }
        else if (std::modf(input, &input) == 0.5 || std::modf(input, &input) == 1 )
        {
            //input = (int)input;
        }

        grades.push_back(input);
    }

    float min = *std::min_element(grades.begin(), grades.end());
    float max = *std::max_element(grades.begin(), grades.end());

    //grades.erase(min);

    for(int i = 0; i < grades.size(); i++)
    {
        std::cout << grades[i] << std::endl;
    }
}

int main()
{
    insert_grades();
    return 0;
}