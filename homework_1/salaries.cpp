#include <iostream>
#include <sstream>
#include <string>
#include <vector>

namespace salaries
{

float eligible_salary_for_wage_increase;
float new_salary;
float wage_increase_percentage;
bool still_running;

std::string input;


void wage_increase()
{
    std::vector<float> salaries{};

    bool still_writing = true;

    wage_increase_percentage = wage_increase_percentage / 100;

    while(still_writing)
    {
        std::cout << "Insert salaries or type 'no' to finish inserting... with every enter press 'enter'!" << std::endl;
        std::cin >> input;

        if (input == "no")
        {
            still_writing = false;

            std::cout << "You entered the following:" << std::endl;

            for (int i = 0; i < salaries.size(); i++)
            {
                std::cout << salaries[i] << std::endl;
            }

            for (int i = 0; i < salaries.size(); i++)
            {
                if (salaries[i] <= eligible_salary_for_wage_increase)
                {
                    std::cout << "Your salary was: " << salaries[i] << " and you are eligible for a wage increase!" << std::endl;
                    new_salary = salaries[i] + (salaries[i] * wage_increase_percentage);
                    std::cout << "Your new salary is: " << new_salary << std::endl;
                }
            }
        }
        else
        {
            salaries.push_back(std::stoi(input));
        }
    }
}

int main_salaries()
{
    std::cout << "Set your eligible salary size in order to give your workers a wage increase who earn less than your eligible salary size!" << std::endl;
    std::cin >> eligible_salary_for_wage_increase;
    std::cout << "Set your wage increase percentage!" << std::endl;
    std::cin >> wage_increase_percentage;
    
    wage_increase();

    return 0;
}
}
