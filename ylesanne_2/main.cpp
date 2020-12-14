/*
Ülesanne 2

Salat

* Toiduaine - nimetus, vp (valguprotsent),   rp (rasvaprotsent), sp (süsivesikuprotsent)
* Toidukomponent - koosneb toiduaine eksemplarist ja kogusest.  Juurde käsklused valgu, rasva ja süsivesikute koguse küsimiseks. 
* Toiduportsjon - sisaldab Toidukomponente. Saab küsida kogumassi ning toitainete massi eraldi.
  Võimalik küsida välja toidukomponentide kogus soovitud massiga portsjoni jaoks. 

* Toidukomponent võib sisaldada kas toiduainet või siis juba teist toidukomponenti.
*/
#include <iostream>
#include <string>
#include <vector>

std::string input_name;

float input_valk;
float input_vp;

float input_rasv;
float input_rp;

float input_susivesikud;
float input_sp;

int input_amount;

class toiduaine
{
    private:
        struct toiduained
        {
            std::string name;
            float vp;
            float rp;
            float sp;  
        };
    public:
        toiduained ta;

        toiduaine();

        toiduaine(std::string name, float vp, float rp, float sp)
        {
            ta.name = name;
            ta.vp = vp;
            ta.rp = rp;
            ta.sp = sp;
        }

        //---- getter/setter ----//
        void set_percentages(int valk, int rasv, int susivesikud)
        {
            ta.vp = valk / 100;
            ta.rp = rasv / 100;
            ta.sp = susivesikud / 100;
        }

        void set_name(std::string name)
        {
            ta.name = name;
        }

        std::string get_name()
        {
            return ta.name;
        }

        float get_valk_percentage()
        {
            return ta.vp;
        }

        float get_rasv_percentage()
        {
            return ta.rp;
        }

        float get_susivesikud_percentage()
        {
            return ta.sp;
        }
        //---- ------------- ----//
};


class toidukomponent : public toiduaine
{
    private:
        struct toidukomponendid
        {
            toiduaine ta;
            std::string name;
            int amount;
        };
    public:
        toidukomponendid tk;

        toidukomponent();

        toidukomponent(toiduaine toiduaine)
        {
            tk.ta = toiduaine;
        }

        toidukomponent(toiduaine toiduaine, std::string name, int amount)
        {
            tk.ta = toiduaine;
            tk.name = name;
            tk.amount = amount;
        }

        //---- getter/setter ----//
        std::string get_name()
        {
            return tk.name;
        }

        float get_valk()
        {
            return ((tk.amount * tk.ta.get_valk_percentage()) / 100);
        }

        float get_rasv()
        {
            return ((tk.amount * tk.ta.get_rasv_percentage()) / 100);
        }

        float get_susivesikud()
        {
            return ((tk.amount * tk.ta.get_susivesikud_percentage()) / 100);
        }

        int get_amount()
        {
            return tk.amount;
        }
        //---- ------------- ----//


};

class toiduportsjon
{   
    protected:
        struct toiduportsjonid
        {
            toidukomponent tk;
            std::vector<toidukomponent> list_of_tk;
            int sum_of_mass; 
        };
    public:
        toiduportsjonid tp;

        toiduportsjon();

        toiduportsjon(std::vector<toidukomponent> toidukomponentide_list)
        {
            tp.list_of_tk = toidukomponentide_list;
        }

        //---- getter/setter ----//
        void set_list_of_tk(std::vector<toidukomponent> toidukomponentide_list)
        {
            tp.list_of_tk = toidukomponentide_list;
        }

        float get_multiple_food_mass()
        {
            tp.sum_of_mass = 0;
            for (int i = 0; i < tp.list_of_tk.size(); i++)
            {
                tp.sum_of_mass = tp.sum_of_mass + tp.list_of_tk[i].get_amount();
            }
            return tp.sum_of_mass;
        }

        float get_mass_of_food(toidukomponent tk)
        {
            return tk.get_amount();
        }

        float get_mass_of_custom_food()
        {
            return 0;
        }        

        std::string get_name_of_food(toidukomponent tk)
        {
            return tk.get_name();
        }
        //---- ------------- ----//
};

toiduaine::toiduaine()
{
    std::cout << "Toiduaine class constructor is working!" << std::endl;
}

toidukomponent::toidukomponent()
{
    std::cout << "Toidukomponent class constructor is working!" << std::endl;
}

toiduportsjon::toiduportsjon()
{
    std::cout << "Toiduportsjon class constructor is working!" << std::endl;
}

int main()
{
    //---- INPUT/OUTPUT ----//
    std::cout << "Insert the name of the foodstuff and the percentages of protein, fat, carbohydrates: " << std::endl;
    std::cout << "Name: "; std::cin >> input_name;
    std::cout << "Protein: "; std::cin >> input_vp;
    std::cout << "Fat: "; std::cin >> input_rp;
    std::cout << "Carbohydrates: "; std::cin >> input_sp;

    toiduaine toiduaine_1(input_name, input_vp, input_rp, input_sp);
    toiduaine toiduaine_2("veisehakkliha", 25, 30, 45);

    std::cout << "Name: " << toiduaine_1.get_name() << " | Protein percentage: " 
                        << toiduaine_1.get_valk_percentage() << "% | Fat percentage: " 
                        << toiduaine_1.get_rasv_percentage() << "% | Carbohydrates percentage: " 
                        << toiduaine_1.get_susivesikud_percentage() << "%" << std::endl;

    std::cout << "Enter the name of the food component and the amount: " << std::endl;
    std::cout << "Name: "; std::cin >> input_name;
    std::cout << "Amount: "; std::cin >> input_amount;

    toidukomponent toidukomponent_1(toiduaine_1, input_name, input_amount);
    toidukomponent toidukomponent_2(toiduaine_2, "pasta", 2);

    std::cout << toidukomponent_1.get_amount() << " grams of "
            << toidukomponent_1.get_name() << " contains: " 
            << toidukomponent_1.get_valk() << " grams of protein, " 
            << toidukomponent_1.get_rasv() << " grams of fat, " 
            << toidukomponent_1.get_susivesikud() << " grams of carbohydrates!" << std::endl;

    std::vector<toidukomponent> pastas = {toidukomponent_1, toidukomponent_2};
    toiduportsjon pasta(pastas);

    std::cout << "Food weighs about: " << pasta.get_multiple_food_mass() << " grams" << std::endl;
    //---- ------------ ----//
    
    return 0;
}
