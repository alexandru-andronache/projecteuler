#include <iostream>

namespace problem_036 {
    bool isPalindrom(int k) {
        int nr = 0;
        int tmp = k;
        while (tmp > 0) {
            nr = nr * 10 + tmp % 10;
            tmp = tmp / 10;
        }
        return (k == nr);
    }

    int findBitMax(const std::bitset<32>& bits) {
        int k = 0;
        int max = 0;
        while (k < bits.size()) {
            if (bits.test(k)) {
                max = k;
            }
            k++;
        }
        return max;
    }
    int solve() {
        int sum = 0;
        for (int i = 1; i < 1000000; ++i) {
            if (isPalindrom(i)) {
                std::bitset<32> bits(32);
                bits = i;
                std::string o = bits.to_string();
                std::reverse(o.begin(), o.end());
                o = o.substr(0, findBitMax(bits) + 1);
                std::string p = o;
                std::reverse(p.begin(), p.end());
                if (p == o) {
                    sum += i;
                }
            }
        }
        return sum;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_036::solve(0) << std::endl;

    return 0;
}
#endif
