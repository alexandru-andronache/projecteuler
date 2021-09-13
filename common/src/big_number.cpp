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

    BigNumber BigNumber::operator*=(const int& other) {
        int p = 0;
        for (size_t i = 0; i < number.size(); ++i) {
            int k = number[i] * other + p;
            number[i] = k % 10;
            p = k / 10;
        }
        while (p > 0) {
            number.push_back(p % 10);
            p = p / 10;
        }
        return *this;
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

    std::ostream& operator<< (std::ostream& stream, const BigNumber& bigNumber) {
        std::for_each(bigNumber.number.rbegin(), bigNumber.number.rend(),[](const auto & elem){
            std::cout << elem;
        });
        return stream;
    }

    size_t BigNumber::size() {
        return number.size();
    }

    size_t BigNumber::sumOfNumbers() {
        return std::accumulate(number.begin(), number.end(), 0);
    }
}