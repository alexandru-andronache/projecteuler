#pragma once

namespace fraction
{
    class Fraction {
        public:
            Fraction();
            Fraction(long long n, long long d);

            bool operator<(const Fraction &other) const;
            long long getNumerator() { return numerator; }
            long long getDenominator() { return denominator; }

        private:
            long long numerator;
            long long denominator;
    };
} // namespace fraction