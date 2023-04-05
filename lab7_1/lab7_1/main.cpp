#include <iostream>
#include <cmath>


long double operator"" _Kelvin(long double value) {
	return (value - 273.15);
}

long double operator"" _Fahrenheit(long double value) {
    return (value - 32.0) / 1.8;
}

int main() {

    long double a = 300.0_Kelvin;

    long double b = 120.0_Fahrenheit;

    std::cout << a << " Celsius\n" << b << " Celsius";
    return 0;
}