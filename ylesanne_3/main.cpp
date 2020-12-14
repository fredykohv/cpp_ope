/*
Ülesanne 3

Mallid

* Loo klass Punkt ja sellele liitmise operaator nõnda, et
  liitmise malliga funktsioon toimiks ka Punkti puhul.
* Leia  punktimassiivis olevate punktide koordinaatide kokkuliitmisel saadava punkti 
  koordinaatide väärtused.
* Loo mallfunktsioon massiivist suurima elemendi leidmiseks.
  Hoolitse, et see töötaks ka Punkti ja Kellaaja korral.
* Loo mallfunktsioon massiivist otsitava elemendi järjekorranumbri 
  leidmiseks.
* Loo ahel, kus iga element näitab järgnevale. Ahela l�li elementide 
  väärtuseks on viit andmetele ja viit järgmisele l�lile. Andmetüüp
  määratakse malliga. Testi ahelat.

* Loo klassimall, milles oleks kaks elementi. Kummagi tüübi saab
  malli kaudu määrata.
* Lisa konstruktorid andmete sisestamiseks ja kopeerimiseks, 
  meetod väljatrükiks. 
*/

#include <math.h>
#include <iostream>
#include <vector>

class coordinate
{
    public:
        struct coordinates
        {
            float x;
            float y;
        };

        coordinates coords;

        coordinate();

        coordinate(float x, float y)
        {
            coords.x = x;
            coords.y = y;
        }

};

coordinate::coordinate()
{
    std::cout << "Constructor is working!" << std::endl;
}

int main()
{

    return 0;
}
