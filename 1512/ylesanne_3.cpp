/*
Massiivis ‘nimed’ on tudengite nimed, täpsemalt koosneb massiiv viitadest nimedele. 
Topeltviida ‘nimed’ väärtuseks saab viit esimese nimeaadressile. 
Programm küsib nime esitähte ning liikudes topeltviidaga mööda stringimassiivi väljastab leitud nimed. 
*/

#include <iostream>
#include <string>
#include <vector>

std::string input_key;
char inserted_key;

char ask_for_the_first_letter(std::string key)
{
    //esimene täht at(0)
    char input_key = key.at(0);

    return input_key;
}

int main()
{
    std::cout << "Insert the first letter of a name you are trying to look for!" << std::endl;
    std::cout << "First letter: "; std::cin >> input_key;

    std::string nimi_1 = "Fredy";
    std::string nimi_2 = "Mark";
    std::string nimi_3 = "Margus";

    std::vector<std::string*> nimed{&nimi_1, &nimi_2, &nimi_3};

    std::string** nimed_pp = &nimed[0];

    inserted_key = ask_for_the_first_letter(input_key);

    for (int i = 0; i < nimed.size(); i++)
    {
        if ((**nimed_pp).at(0) == inserted_key)
        {
            std::cout << **nimed_pp << std::endl;
        }
    }

    return 0;
}
