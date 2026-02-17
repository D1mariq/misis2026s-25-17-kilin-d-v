#ifndef COMPLEX_COMPLEX_H_20191010
#define COMPLEX_COMPLEX_H_20191010

#include <iosfwd>
#include <iostream>

struct Complex {
    double re = 0, im = 0;

    const char LeftBrace = '{';
    const char separator = ',';
    const char RightBrace = '}';

    Complex() = default;
    Complex(const Complex&) = default;
    Complex(Complex&&) = default;
    explicit Complex(const double real) : re(real) {}
    explicit Complex(const double _re, const double _im) : re(_re), im(_im) {}
    ~Complex() = default;

    [[nodiscard]] Complex operator-() const noexcept;

    Complex& operator= (const Complex &) = default;
    Complex& operator= (Complex &&) = default;

    [[nodiscard]] bool operator== (Complex &r) noexcept;
    [[nodiscard]] bool operator!= (Complex &r) noexcept;

    [[nodiscard]] Complex operator+ (const Complex &r) noexcept;
    [[nodiscard]] Complex operator+ (const double &r) noexcept;

    [[nodiscard]] Complex operator- (const Complex &r) noexcept;
    [[nodiscard]] Complex operator- (const double &r) noexcept;

    [[nodiscard]] Complex operator* (const Complex &r) noexcept;
    [[nodiscard]] Complex operator* (const double &r) noexcept;

    [[nodiscard]] Complex operator/ (const Complex &r);
    [[nodiscard]] Complex operator/ (const double &r);

    Complex& operator+= (const Complex &r) noexcept;
    Complex& operator+= (const double &r) noexcept;

    Complex& operator-= (const Complex &r) noexcept;
    Complex& operator-= (const double &r) noexcept;

    Complex& operator*= (const Complex &r) noexcept;
    Complex& operator*= (const double &r) noexcept;

    Complex& operator/= (const Complex &r);
    Complex& operator/= (const double &r);

    [[nodiscard]] std::istream& ReadFrom(std::istream& in);

    [[nodiscard]] std::ostream& WriteTo(std::ostream& out) const;

    std::istream& operator>>(std::istream& in) { return ReadFrom(in); };

    std::ostream& operator<< (std::ostream &out) const {return WriteTo(out);};
};

[[nodiscard]] Complex operator+ (const double &l, const Complex &r) noexcept;
[[nodiscard]] Complex operator- (const double &l, const Complex &r) noexcept;
[[nodiscard]] Complex operator* (const double &l, const Complex &r) noexcept;
[[nodiscard]] Complex operator/ (const double &l, const Complex &r);

#endif