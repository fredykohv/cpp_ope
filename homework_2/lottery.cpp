#include <ctime>
#include <iostream>
#include <stdio.h>
#include <string>

std::string input;
int spent_money = 0;
bool game_enabled = true;
 
int random_number()
{
    srand(time(NULL));
 
    int random_number = rand() % 1000000 + 1;
 
    //std::cout << random_number << std::endl;
    return random_number;
}
 
int game()
{
    int winning_number = random_number();

    //std::cout << winning_number << std::endl;

    std::cout << "Want to win a million dollars?" << std::endl;
    std::cout << "If so, guess the winning number (a number between 1 and 1000000)." << std::endl;
 
    while(game_enabled)
    {
        std::cout << "Insert $1.00 and enter your number or 'q' to quit" << std::endl;
        std::cin >> input;
        if (input == "q")
        {
            printf("You left the game and spent: %d $\n", spent_money);
            game_enabled = false;
        }

        int guess = std::stoi(input);

        if (guess != winning_number)
        {
            spent_money++;
            printf("You entered %d and it's wrong... want a hint? y/n\n", guess);
            std::cin >> input;

            if(input == "y" && guess > winning_number)
            {
                spent_money = spent_money + 2;
                std::cout << "Your guess was higher than anticipated" << std::endl;
            }

            else if (input == "y" && guess < winning_number)
            {
                spent_money = spent_money + 2;
                std::cout << "Your guess was lower than anticipated" << std::endl;
            }
            
            else if(input == "n")
            {
                std::cout << "Insert $1.00 and enter your number or 'q' to quit" << std::endl;
                std::cin >> input;

                if(input == "q")
                {
                    game_enabled = false;
                    printf("You left the game and spent: %d $\n", spent_money);
                }

                else
                {
                    spent_money++;
                }
            }
        }

        else if (guess == winning_number)
        {
            spent_money = 0;
            printf("you won!\n");
            game_enabled = false;
        }

    }
    return 0;
}
 
 
int main()
{
    game();
    return 0;
}
