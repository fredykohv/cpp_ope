//Kirjutage programm, mis sisestab viis täisarvu ja väljastab, palju oli nende seas paaris, palju paarituid arve.

#include <iostream>
#include <vector>

int input;
std::vector<int> numbers{};
int even_number_count = 0;
int odd_number_count = 0;
int max_entries = 5;

void insert()
{
    std::cout << "Insert your five numbers: " << std::endl;
    for (int i = 0; i < max_entries; i++)
    {
        std::cin >> input;
        numbers.push_back(input);
    }
    for (int i = 0; i < numbers.size(); i++)
    {
        //std::cout << numbers[i] << " ";
        std::cout << "You inserted: " << numbers[i] << std::endl;
        std::cout << " ";
        if (numbers[i] & 1 == 1)
        {
            odd_number_count++;
            std::cout << numbers[i] << " is odd :)" << std::endl;
        }
        else
        {
            even_number_count++;
            std::cout << numbers[i] << " is even :)" << std::endl;
        }
    }

    std::cout << "Total even numbers are: " << even_number_count << std::endl;
    std::cout << "Total odd numbers are: " << odd_number_count << std::endl;
}

int main()
{
    insert();
    return 0;
}