#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <stdarg.h>
#include <cstring>
#include <cstdlib>



int Math::Add(int a, int b) 
{
	return a + b;
}

int Math::Add(int a, int b, int c) 
{
	return a + b + c;
}

double Math::Add(double a, double b)
{
	return a + b;
}

double Math::Add(double a, double b, double c) 
{
	return a + b + c;
}

int Math::Mul(int a, int b) 
{
	return a * b;
}

int Math::Mul(int a, int b, int c) 
{
	return a * b * c;
}

double Math::Mul(double a, double b)
{
	return a * b;
}

double Math::Mul(double a, double b, double c)
{
	return a * b * c;
}

int Math::Add(int count, ...)
{
	va_list args;
	va_start(args, count);
	int sum = 0;
	for (int i = 0; i < count; i++) {
		int num = va_arg(args, int);
		sum += num;
	}
	va_end(args);
	return sum;
}

char* Math::Add(const char* s1, const char* s2)
{
	if (s1 == nullptr || s2 == nullptr) {
		return nullptr;
	}
	int l1 = strlen(s1);
	int l2 = strlen(s2);
	
	char* result = (char*)malloc(l1 +l2 + 1);
	if (result == nullptr) {
		return nullptr;
	}
	strcpy(result, s1);
	strcat(result, s2);
	return result;
}


