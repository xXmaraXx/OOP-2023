#include <iostream>
#include "Math.h"

int main()
{
	int a = 2, b = 3, c = 4;
	double x = 1.5, y = 2.5, z = 3.5;

	std::cout << "Add(2, 3): " << Math::Add(a, b) << "\n";
	std::cout << "Add(2, 3, 4): " << Math::Add(a, b, c) << "\n";
	std::cout << "Add(1.5, 2.5): " << Math::Add(x, y) << "\n";
	std::cout << "Add(1.5, 2.5, 3.5): " << Math::Add(x, y, z) << "\n";

	std::cout << "Mul(2, 3): " << Math::Mul(a, b) << "\n";
	std::cout << "Mul(2, 3, 4): " << Math::Mul(a, b, c) << "\n";
	std::cout << "Mul(1.5, 2.5): " << Math::Mul(x, y) << "\n";
	std::cout << "Mul(1.5, 2.5, 3.5): " << Math::Mul(x, y, z) << "\n";

	std::cout << "Add(6, 1, 2, 3, 4, 5, 2): " << Math::Add(6, 1, 2, 3, 4, 5, 2) << "\n";

	const char* s1 = "Hello ";
	const char* s2 = "world!";
	char* s3 = Math::Add(s1, s2);
	std::cout << "Add(Hello, world!): " << s3 << "\n";
	free(s3);

	const char* s4 = nullptr;
	const char* s5 = "world!";
	char* s6 = Math::Add(s4, s5);
	free(s6);

	return 0;
}
