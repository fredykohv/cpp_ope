#include <iostream>
#include <vector>

namespace salaries
{

float eligible_salary_for_wage_increase;
float new_salary;
float wage_increase_percentage;


std::vector<float> salaries{1262.34, 871.21, 724.12, 2851.11, 2895.04, 125.3, 815.12, 1873.19};

float wage_increase()
{
    wage_increase_percentage = wage_increase_percentage / 100;
    for (int i = 0; i < salaries.size(); i++)
    {
        if (salaries[i] <= eligible_salary_for_wage_increase)
        {
            std::cout << "Your salary was: " << salaries[i] << " and you are eligible for a wage increase!" << std::endl;
            new_salary = salaries[i] + (salaries[i] * wage_increase_percentage);
            std::cout << "Your new salary is: " << new_salary << std::endl;
        }
    }

    return 0;
}

int main_salaries()
{
    std::cout << "Set your eligible salary size in order to give your workers a 5% wage increase who earn less than your eligible salary size!" << std::endl;
    std::cin >> eligible_salary_for_wage_increase;
    std::cout << "Set your wage increase percentage!" << std::endl;
    std::cin >> wage_increase_percentage;
    
    wage_increase();

    return 0;
}
}
