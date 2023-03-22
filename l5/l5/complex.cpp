#include "complex.h"

Complex::Complex() : Complex(0, 0) {
}

Complex::Complex(double real, double imag) {
    real_data = real;
    imag_data = imag;
}

bool Complex::is_real() const {
    return imag() == 0;
}

double Complex::real() const {
    return real_data;
}

double Complex::imag() const {
    return imag_data;
}

double Complex::abs() const {
    return sqrt(real() * real() + imag() * imag());
}

Complex Complex::conjugate() const {
    return { real(), -imag() };
}

Complex& Complex::operator()(double real, double imag) {
    this->real_data = real;
    this->imag_data = imag;
    return *this;
}

Complex& Complex::operator++() {
    this->real_data++;
    return *this;
}

Complex Complex::operator++(int) {
    Complex result = *this;
    ++(*this);
    return result;
}

Complex& Complex::operator--() {
    this->real_data--;
    return *this;
}

Complex Complex::operator--(int) {
    Complex result = *this;
    --(*this);
    return result;
}

Complex operator+(const Complex& l, const Complex& r) {
    double real = l.real() + r.real();
    double img = l.imag() + r.imag();
    Complex copy(real, img);
    return copy;
}

Complex operator+(const Complex& l, double r) {
    double real = r;
    double img = 0;
    Complex copy(real, img);
    return copy + l;
}

Complex operator+(double l, const Complex& r) {
    double real = l;
    double img = 0;
    Complex copy(real, img);
    return copy + r;
}

Complex operator-(const Complex& l, const Complex& r) {
    return l + (-r);
}

Complex operator-(const Complex& l, double r) {
    double real = r;
    double img = 0;
    Complex copy(real, img);
    return l + (-copy);
}

Complex operator-(double l, const Complex& r) {
    double real = l;
    double img = 0;
    Complex copy(real, img);
    return copy + (-r);
}

Complex operator*(const Complex& l, const Complex& r) {
    double real = l.real() * r.real() - l.imag() * r.imag();
    double img = l.real() * r.imag() + l.imag() * r.real();
    Complex copy(real, img);
    return copy;
}

Complex operator*(const Complex& l, double r) {
    double real = r;
    double img = 0;
    Complex copy(real, img);
    return l * copy;
}

Complex operator*(double l, const Complex& r) {
    double real = l;
    double img = 0;
    Complex copy(real, img);
    return copy * r;
}

Complex operator-(const Complex& obj) {
    double real = -obj.real();
    double img = -obj.imag();
    Complex copy(real, img);
    return copy;
}

bool operator==(const Complex& l, const Complex& r) {
    return l.real() == r.real() && l.imag() == r.imag();
}

bool operator!=(const Complex& l, const Complex& r) {
    return !(l == r);
}

std::ostream& operator<<(std::ostream& out, const Complex& complex) {
    if (complex.real() == 0 && complex.imag() == 0)
        out << 0;
    else if (complex.real() == 0)
        out << complex.imag() << "i";
    else if (complex.imag() == 0)
        out << complex.real();
    else if (complex.imag() < 0)
        out << complex.real() << " - " << -complex.imag() << "i";
    else
        out << complex.real() << " + " << complex.imag() << "i";
    return out;
}




