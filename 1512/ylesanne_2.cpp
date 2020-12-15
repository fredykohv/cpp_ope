/*
Kirjtage programm, mis näitab failidega tööd.
Failinimi ’Info.txt’ on programmi tekstis kirjas konstandina. 
Lisaks on ette nähtud võimalus anda failinimi ette käsureal, siis proovitakse avada etteantud nimega fail. 
Faili mitteleidmisel antakse veateade ja programm lõpetab töö veakoodiga 1.
Salvestage faili 25 juhuslikult gerenreeritud arvu.
Loege need arvud ja kuvage konsooli.
*/
#include <bits/stdc++.h>
#include <ctime>
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>

const std::string file_name = "Info.txt";
std::string input_choice;
std::string input_file_name;
int random_number;
int input_amount_of_random_numbers;
int amount_of_numbers_to_generate = 25;
std::vector<int> numbers;

int generate_random_number(int amount_of_numbers)
{
    srand(time(NULL));

    for (int i = 0; i < amount_of_numbers; i ++)
    {
        random_number = rand() % 1000000 + 1;
        numbers.push_back(random_number);
    }

    return random_number;
}

void create_and_add_stuff_to_a_file(std::string name)
{
    std::ofstream file(name);
    
    for (int i = 0; i < numbers.size(); i++)
    {
        file << numbers[i] << "\n";
    }
}

int main()
{
    std::cout << "You created a file called: " << file_name << ", do you want to rename it? (y/n)" << std::endl;
    std::cout << "(y/n): "; std::cin >> input_choice;
    if (input_choice == "n")
    {
        std::cout << "How many numbers do you want to add to your file?" << std::endl;
        std::cout << "Amount of numbers to add to the file: "; std::cin >> input_amount_of_random_numbers;
        generate_random_number(input_amount_of_random_numbers);
        create_and_add_stuff_to_a_file(file_name);
    }
    else
    {
        std::cout << "What would you like to rename your file into?" << std::endl;
        std::cout << "Rename: "; std::cin >> input_file_name;
        std::cout << "Renamed! How many numbers do you want to add to your file?" << std::endl;
        std::cout << "Amount of numbers to add to the file: "; std::cin >> input_amount_of_random_numbers;
        generate_random_number(input_amount_of_random_numbers);
        create_and_add_stuff_to_a_file(input_file_name);
    }

    for (int i = 0; i < numbers.size(); i++)
    {
        std::cout << numbers[i] << std::endl;
    }

    return 0;
    
}
