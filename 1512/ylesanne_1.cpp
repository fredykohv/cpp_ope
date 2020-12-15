#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>

std::string input_gender;
std::string input_name;
int input_age;
int min_men_retirement_age = 65;
int min_women_retirement_age = 60;
int add_age = 5;

std::vector<int> ages_for_men;
std::vector<int> ages_for_women;

void output_till_retirement(std::string gender, std::string name, int age)
{
    if (gender == "M" || gender == "m" || gender == "Male" || gender == "male")
    {
        while (age < min_men_retirement_age)
        {
            age = age + add_age;

            if (age > min_men_retirement_age)
            {
                age = min_men_retirement_age;
                ages_for_men.push_back(age);
                break;
            }

            else
            {
                ages_for_men.push_back(age);
            }
        }
        std::sort(ages_for_men.begin(), ages_for_men.end());
    }

    else if (gender == "F" || gender == "f" || gender == "Female" || gender == "female")
    {
        while (age < min_women_retirement_age)
        {
            age = age + add_age;

            if (age > min_women_retirement_age)
            {
                age = min_women_retirement_age;
                ages_for_women.push_back(age);
                break;
            }
            else
            {
                ages_for_women.push_back(age);
            }
        }
        std::sort(ages_for_women.begin(), ages_for_women.end());
    }
}

int main()
{
    std::cout << "Enter your gender, name and age!" << std::endl;
    std::cout << "Gender: "; std::cin >> input_gender;
    std::cout << "Name: "; std::cin >> input_name;
    std::cout << "Age: "; std::cin >> input_age;

    output_till_retirement(input_gender, input_name, input_age);

    for (int i = 0; i < ages_for_men.size(); i++)
    {
        std::cout << "Age: " << ages_for_men[i] << std::endl;
    }

    for (int i = 0; i < ages_for_women.size(); i++)
    {
        std::cout << "Age: " << ages_for_women[i] << std::endl;
    }

    return 0;
}
