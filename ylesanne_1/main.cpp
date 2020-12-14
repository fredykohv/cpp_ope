/*
Ülesanne 1

* Loo klass Punkt privaatväljadega x ja y +
* Lisa klassile käsklus andmete sisestuseks ja väljatrükiks. Testi. +
* Lisa klassile käsklus teise punkti andmete liitmiseks. Testi. (Sama klassi +
eksemplarid pääsevad ligi teineteise privaatmuutujatele.) +
* Lisa friend-meetod trükkimaks punkti kauguse koordinaatide alguspunktist. +

* Muuda Punkti väljade ligipääsuõiguseks protected. +
* Koosta punktile alamklass RuumiPunkt, kus lisanduks kolmas väli z. +
* Lisa klassile käsklus andmete sisestuseks ning väljatrükiks. Testi. +
* Lisa klassile Punkt parameetriteta konstruktor ning teata ekraanile, kui +
see käivitatakse. Testi nii Punkti kui RuumiPunkti loomist. +
* Koosta nii Punktile kui RuumiPunktile konstruktor, mille abil saab +
objektile loomisel andmed sisestada. Kutsu RuumiPunkti parameetritega +
konstruktorist välja Punkti parameetritega konstruktor. +
* Loo kummastki klassist eksemplar, millega suheldakse viida kaudu.
* Omista RuumiPunkti eksemplari aadress Punkti viidale. Testi toimimist. 
* Hoolitse, et nii Punkti kui RuumiPunkti andmeid väljatrükkiv funktsioon
oleks sama nime ja parameetritega (tõenäoliselt parameetrid puuduvad).
* Muuda vastav funktsioon virtuaalseks. Testi tulemust.

* Koosta massiiv viitadest Punktidele. Paiguta sinna nii Punkte kui
RuumiPunkte. Trüki andmed tsükli abil välja.
*/

#include <math.h>
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>

float input_x;
float input_y;
float input_z;
float distance_from_starting_point;

class coordinate
{
    protected:
        struct coordinates
        {
            float x;
            float y;
            float z;
        };
    public:
        coordinates coords, coords_sum;

        coordinate();

        coordinate(float x, float y)
        {
            coords.x = x;
            coords.y = y;
        }

        //---- getter/setter ----//
        coordinates get_coords()
        {
            return coords;
        }

        void set_coords(float x, float y)
        {
            coords.x = x;
            coords.y = y;
        }
        //---- ------------- ----//

        coordinates sum_of_coords(coordinate c)
        {
            coords_sum.x = coords.x + c.coords.x;
            coords_sum.y = coords.y + c.coords.y;
            return coords_sum;
        }

        virtual void display_data()
        {
            std::cout << "X: " << coords.x << " Y: " << coords.y << std::endl;
        }

        friend void starting_point(coordinate c);


};

class spatial_coordinate : protected coordinate
{
    public:
        spatial_coordinate();

        spatial_coordinate(float x, float y, float z) : coordinate(x, y)
        {
            coords.z = z;
        }

        //---- setter ----//
        void set_spatial_coords(float x, float y, float z)
        {
            coords.x = x;
            coords.y = y;
            coords.z = z;
        }
        //---- ------ ----//

        void display_data()
        {
            std::cout << "X: " << coords.x << " Y: " << coords.y << " Z: " << coords.z << std::endl;
        }
};

coordinate::coordinate()
{
    std::cout << "Coordinate constructor is working!" << std::endl;
}

void starting_point(coordinate c)
{
    distance_from_starting_point = sqrt(pow(c.coords.x, 2) + pow(c.coords.y, 2));
}

spatial_coordinate::spatial_coordinate()
{
    std::cout << "Spatial Coordinate constructor is working!" << std::endl;
}

int main()
{
    coordinate();
    spatial_coordinate();
    coordinate coordinates_1, coordinates_2, coordinates_3;
    spatial_coordinate coordinates_4, coordinates_5;

    //---- INPUT/OUTPUT ----//
    std::cout << "Insert coordinate x: " << std::endl;
    std::cin >> input_x;
    std::cout << "Insert coordinate y: " << std::endl;
    std::cin >> input_y;
    std::cout << "Insert coordinate z: " << std::endl;
    std::cin >> input_z;
    coordinate(input_x, input_y);
    spatial_coordinate(input_x, input_y, input_z);
    std::cout << "X: " << input_x << " Y: " << input_y << " Z: " << input_z <<std::endl;
    //----            ----//

    coordinates_1.set_coords(input_x, input_y);
    starting_point(coordinates_1);
    std::cout << "Distance from starting point (0, 0) is: " << distance_from_starting_point << std::endl;
    
    std::vector<coordinate*> coords{&coordinates_1, &coordinates_2, &coordinates_3};
    std::vector<spatial_coordinate*> spatial_coords{&coordinates_4, &coordinates_5};

    for (coordinate* c : coords)
    {
        c->display_data();
    }
    
    for (spatial_coordinate* s : spatial_coords)
    {
        s->display_data();
    }

    return 0;
}
