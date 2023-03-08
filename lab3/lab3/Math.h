#pragma once
class Math {
public:
    static int Add(int a, int b);
    static int Add(int a, int b, int c);
    static double Add(double a, double b);
    static double Add(double a, double b, double c);
    static int Mul(int a, int b);
    static int Mul(int a, int b, int c);
    static double Mul(double a, double b);
    static double Mul(double a, double b, double c);
    static int Add(int count, ...);
    static char* Add(const char* str1, const char* str2);
};