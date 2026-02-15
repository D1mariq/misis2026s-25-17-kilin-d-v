#include "complex.hpp"

Complex Complex::operator-() const noexcept { return Complex(-re, -im); }

