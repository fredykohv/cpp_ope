#include <iostream>
#include <vector>

int max_inserts = 7;

void giving_grades()
{
    std::vector<int> grades{};
    int input;
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

    std::cout << "You inserted the following: " << std::endl;
    for(int i = 0; i < grades.size(); i++)
    {
        std::cout << grades[i] << " ";
    }
    std::cout << " " << std::endl;
}

int main()
{
    giving_grades();
    return 0;
}
