#include "complex.hpp"
#include <stdexcept>
#include <iostream>

Complex Complex::operator-() const noexcept { return Complex(-re, -im); }

bool Complex::operator== (Complex &r) noexcept { return (re == r.re && im == r.im); }
bool Complex::operator!= (Complex &r) noexcept { return !Complex::operator==(r); }

Complex Complex::operator+ (const Complex &r) noexcept { return Complex (re + r.re, im + r.im); }
Complex Complex::operator+ (const double &r) noexcept { return Complex (re + r); }

Complex Complex::operator- (const Complex &r) noexcept { return Complex (re - r.re, im - r.im); }
Complex Complex::operator- (const double &r) noexcept { return Complex (re - r); }

Complex Complex::operator* (const Complex &r) noexcept { return Complex (re * r.re - im * r.im, re * r.im + im * r.re); }
Complex Complex::operator* (const double &r) noexcept { return Complex (re * r, im * r); }

Complex Complex::operator/ (const Complex &r) {
    double denom = r.re * r.re + r.im * r.im;
    if (abs(denom) < 1e-8) throw std::runtime_error("Division by zero");
    return Complex((re * r.re + im * r.im) / denom, (im * r.re - re * r.im) / denom);
}
Complex Complex::operator/ (const double &r) {
    if (r == 0) throw std::runtime_error("Division by zero");
    return Complex(re / r, im / r);
}

std::istream& Complex::ReadFrom(std::istream& in) {
    char lb, sep, rb;
    double r, i;
    in >> lb >> r >> sep >> i >> rb;
    if (in.good()) {
        if (lb != LeftBrace || sep != separator || rb != RightBrace)
            in.setstate(std::ios::failbit);
        else
            re = r, im = i;
    }
    return in;
}

std::ostream& Complex::WriteTo(std::ostream& out) const {
    out << LeftBrace << re << separator << im << RightBrace;
    return out;
}

Complex operator+ (const double &l, const Complex &r) noexcept { return Complex(r.re + l, r.im); }
Complex operator- (const double &l, const Complex &r) noexcept { return Complex(r.re - l, r.im); }
Complex operator* (const double &l, const Complex &r) noexcept { return Complex(r.re * l, r.im * l); }
Complex operator/ (const double &l, const Complex &r) {
    if (l == 0) throw std::runtime_error("Division by zero");
    return Complex(r.re / l, r.im * l);
}
