#include <iostream>
#include <math.h>
#define _USE_MATH_DEFINES

int circle_radius;
int square_side;

int square_area_function()
{
    int square_area = pow(square_side, 2.0);
    std::cout << "Square area is: " << square_area << "cm²" << std::endl;
    return square_area;
}

int square_perimeter_function()
{

    int square_perimeter = square_side * 4;
    std::cout << "Square perimeter is: " << square_perimeter << "cm" << std::endl;
    return square_perimeter;
}

int circle_area_function()
{
    float circle_area = pow(circle_radius, 2.0) * M_PI;
    std::cout << "Circle area is: " << circle_area << "cm²" << std::endl;
    return circle_area;
}

int circle_perimeter_function()
{
    float circle_perimeter = 2 * M_PI * circle_radius;
    std::cout << "Circle perimeter is: " << circle_perimeter << "cm" << std::endl;
    return circle_perimeter;
}

int main()
{
    std::cout << "Whats the radius of circle in order to calculate square side?" << std::endl;

    std::cin >> circle_radius;
    square_side = circle_radius * 2;
    
    std::cout << "Circle radius is: " << circle_radius << "cm" << " and square side is: " << square_side << std::endl;

    square_area_function();
    square_perimeter_function();
    circle_area_function();
    circle_perimeter_function();
}
