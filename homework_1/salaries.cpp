#include <iostream>
#include <vector>

float eligible_salary_for_wage_increase;

std::vector<float> salaries{1262.34, 871.21, 724.12, 2851.11, 2895.04, 125.3, 815.12, 1873.19};

int wage_increase()
{
    for (int i = 0; i < salaries.size(); i++)
    {
        if (salaries[i] <= eligible_salary_for_wage_increase)
        {
            std::cout << "Your salary was: " << salaries[i] << " and you are eligible for a wage increase!" << std::endl;
            float new_salary = salaries[i] + (salaries[i] * 0.05);
            std::cout << "Your new salary is: " << new_salary << std::endl;
        }
    }

    return 0;
}

int main()
{
    std::cout << "Set your eligible salary size in order to give your workers a 5% wage increase who earn less than your eligible salary size!" << std::endl;
    std::cin >> eligible_salary_for_wage_increase;
    wage_increase();
}