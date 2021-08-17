#include <iostream>
#include <vector>
#include "file.h"

namespace problem_011 {
    int solve(int n) {
        std::vector<std::vector<int>> matrix = file::readFileAsArrayOfArrayOfInt("../problems/problem_011/input/input.in");
        int max = 0;

        for (int j = 0; j <= matrix.size() - n; ++j) {
            for (int i = 0; i <= matrix.size() - n - j; ++i) {
                int prod = 1;
                for (int l = 0; l < n; ++l) {
                    prod *= matrix[i + l][i + j + l];
                }
                max = std::max(prod, max);

                prod = 1;
                for (int l = 0; l < n; ++l) {
                    prod *= matrix[i + j + l][i + l];
                }
                max = std::max(prod, max);
            }
        }

        for (int j = 0; j <= matrix.size() - n; ++j) {
            int k = 0;
            for (int i = j; i <= matrix.size() - n; ++i) {
                int prod = 1;
                for (int l = 0; l < n; ++l) {
                    prod *= matrix[i + l][matrix.size() - 1 - k - l];
                }
                max = std::max(prod, max);
                k++;
            }
        }

        for (int j = 0; j <= matrix.size() - n; ++j) {
            int k = j;
            for (int i = 0; i <= matrix.size() - n - j; ++i) {
                int prod = 1;
                for (int l = 0; l < n; ++l) {
                    prod *= matrix[i + l][matrix.size() - 1 - k - l];
                }
                max = std::max(prod, max);
                k++;
            }
        }

        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix.size() - n; ++j) {
                int prod = 1;
                for (int l = 0; l < n; ++l) {
                    prod *= matrix[i][j + l];
                }
                max = std::max(prod, max);
            }
        }

        for (int i = 0; i < matrix.size() - n; ++i) {
            for (int j = 0; j < matrix.size(); ++j) {
                int prod = 1;
                for (int l = 0; l < n; ++l) {
                    prod *= matrix[i + l][j];
                }
                max = std::max(prod, max);
            }
        }

        return max;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_011::solve(4) << std::endl;

    return 0;
}
#endif
