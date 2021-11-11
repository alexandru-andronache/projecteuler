#include <iostream>
#include <vector>
#include <numeric>

namespace problem_061 {
    int solve() {
        const int N = 10000;
        const int SIZE = 6;

        struct state {
            std::vector<int> numbers;
            std::bitset<SIZE> checked {0};
        };

        std::vector<std::bitset<SIZE>> numbers(N, 0);
        std::vector<std::function<int(int)>> generators;
        generators.emplace_back([](int n) { return n * (n + 1) / 2; });
        generators.emplace_back([](int n) { return n * n; });
        generators.emplace_back([](int n) { return n * (3 * n - 1) / 2; });
        generators.emplace_back([](int n) { return n * (2 * n - 1); });
        generators.emplace_back([](int n) { return n * (5 * n - 3) / 2; });
        generators.emplace_back([](int n) { return n * (3 * n - 2); });

        for (int i = 0; i < generators.size(); ++i) {
            int n = 1;
            while (generators[i](n) < N) {
                numbers[generators[i](n)].set(i);
                n++;
            }
        }

        std::vector<state> states;

        for (int i = 1000; i < N; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                if (numbers[i].test(j)) {
                    states.push_back({{i}, 1 << j});
                }
            }
        }

        for (int k = 0; k < SIZE - 1; ++k) {
            std::vector<state> newStates;
            for (const auto& s : states) {
                int nr = s.numbers.back() % 100;
                for (int i = 0; i < 100; ++i) {
                    int newNr = nr * 100 + i;
                    if (newNr >= 1000) {
                        for (int j = 0; j < SIZE; ++j) {
                            if (!s.checked.test(j) && numbers[newNr].test(j)) {
                                std::vector<int> tmp = s.numbers;
                                tmp.push_back(newNr);
                                newStates.push_back({tmp, s.checked.to_ulong() | (1 << j)});
                            }
                        }
                    }
                }
            }
            states = newStates;
        }

        for (const auto& s : states) {
            if (s.numbers[0] / 100 == s.numbers.back() % 100) {
                return std::accumulate(s.numbers.begin(), s.numbers.end(), 0);
            }
        }

        return 0;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_061::solve() << std::endl;

    return 0;
}
#endif
