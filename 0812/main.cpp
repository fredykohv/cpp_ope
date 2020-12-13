#include <iostream>
template <typename T>

T get_min(T a, T b)
{
    return ((a < b) ? a : b);
}

template <int multiplier>

int do_multiplication(int a)
{
    return (a * multiplier);
}

int main()
{
    std::cout << "Hello world" << std::endl;
    int a = 3;
    int b = 6;
    std::cout << get_min(a, b) << std::endl; //3
    std::cout << do_multiplication<5>(a) << std::endl; //15
}