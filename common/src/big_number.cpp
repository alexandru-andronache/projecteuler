#include "big_number.h"
#include <numeric>
#include <iostream>

namespace big_number {
    BigNumber::BigNumber(int k) {
        while (k > 0) {
            number.push_back(k % 10);
            k = k / 10;
        }
    }

    BigNumber::BigNumber(const std::vector<int>& nr) {
        for (const auto& n : nr) {
            number.push_back(n);
        }
    }

    BigNumber BigNumber::operator*=(const long long& other) {
        long long p = 0;
        for (int& nr : number) {
            long long k = nr * other + p;
            nr = k % 10;
            p = k / 10;
        }
        while (p > 0) {
            number.push_back(p % 10);
            p = p / 10;
        }
        return *this;
    }

    BigNumber operator*(const BigNumber& number, const long long& other) {
        BigNumber temp = number;
        temp *= other;
        return temp;
    }

    BigNumber operator*(const long long& other, const BigNumber& number) {
        BigNumber temp = number;
        temp *= other;
        return temp;
    }

    BigNumber operator*(const BigNumber& number1, const BigNumber& number2) {
        BigNumber temp(0);
        for (int i = 0; i < number1.size(); ++i) {
            BigNumber n = number2 * number1.number[i];
            for (int j = 0; j < i; ++j) {
                n *= 10;
            }
            temp = temp + n;
        }
        return temp;
    }

    BigNumber BigNumber::operator+=(const BigNumber &other) {
        int p = 0;
        size_t size = std::min(number.size(), other.number.size());
        for (size_t i = 0; i < size; ++i) {
            int k = number[i] + other.number[i] + p;
            number[i] = k % 10;
            p = k / 10;
        }
        if (number.size() >= other.number.size()) {
            for (size_t i = size; i < number.size(); ++i) {
                int k = number[i] + p;
                number[i] = k % 10;
                p = k / 10;
            }
        }
        else {
            for (size_t i = size; i < other.number.size(); ++i) {
                int k = other.number[i] + p;
                number.push_back(k % 10);
                p = k / 10;
            }
        }
        while (p > 0) {
            number.push_back(p % 10);
            p = p / 10;
        }
        return *this;
    }

    BigNumber operator+(const BigNumber& number1, const BigNumber& number2) {
        std::vector<int> sum(std::min(number1.size(), number2.size()), 0);
        int p = 0;
        for (int i = 0; i < std::min(number1.size(), number2.size()); ++i) {
            int s = number1.number[i] + number2.number[i] + p;
            sum[i] = s % 10;
            p = s / 10;
        }

        if (number1.size() > number2.size()) {
            for (int i = number2.size(); i < number1.size(); ++i) {
                int s = number1.number[i] + p;
                sum.push_back(s % 10);
                p = s / 10;
            }
        }
        else {
            for (int i = number1.size(); i < number2.size(); ++i) {
                int s = number2.number[i] + p;
                sum.push_back(s % 10);
                p = s / 10;
            }
        }

        while (p > 0) {
            sum.push_back(p % 10);
            p = p / 10;
        }

        return {sum};
    }

    BigNumber operator+(const BigNumber& number1, const int& nr) {
        BigNumber t = number1;
        BigNumber t2(nr);
        t += t2;
        return t;
    }

    bool BigNumber::operator==(const BigNumber &other) const {
        if (number.size() != other.number.size()) {
            return false;
        }
        for (int i = 0; i < number.size(); ++i) {
            if (number[i] != other.number[i]) {
                return false;
            }
        }
        return true;
    }

    bool BigNumber::operator<(const BigNumber &other) const {
        if (number.size() > other.size()) {
            return false;
        }
        if (number.size() < other.size()) {
            return true;
        }
        for (int i = number.size() - 1; i >= 0; --i) {
            if (number[i] < other.number[i]) {
                return true;
            }
            if (number[i] > other.number[i]) {
                return false;
            }
        }
        return false;
    }

    std::ostream& operator<< (std::ostream& stream, const BigNumber& bigNumber) {
        std::for_each(bigNumber.number.rbegin(), bigNumber.number.rend(),[](const auto & elem){
            std::cout << elem;
        });
        return stream;
    }

    size_t BigNumber::size() const {
        return number.size();
    }

    size_t BigNumber::size() {
        return number.size();
    }

    size_t BigNumber::sumOfNumbers() {
        return std::accumulate(number.begin(), number.end(), 0);
    }

    bool BigNumber::isPalindrom() {
        int li = 0, ls = number.size() - 1;
        while (li <= ls) {
            if (number[li] != number[ls]) {
                return false;
            }
            li++;
            ls--;
        }
        return true;
    }
}