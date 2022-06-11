#include "fraction.h"

namespace fraction {
    Fraction::Fraction() : numerator(0), denominator(0) {
    }

    Fraction::Fraction(long long n, long long d) : numerator(n), denominator(d) {
    }

    bool Fraction::operator<(const Fraction &other) const {
        return numerator * other.denominator < denominator * other.numerator;
    }
}