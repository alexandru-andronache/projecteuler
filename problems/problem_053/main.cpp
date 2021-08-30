#include <vector>
#include <iostream>

namespace problem_053 {
    int solve(int n) {

        std::vector<int> line{1, 1};
        int total = 0;
        for (int i = 2; i <= n; ++i) {
            std::vector<int> newLine{1};
            for (int j = 1; j < line.size(); ++j) {
                newLine.push_back(std::min(line[j] + line[j - 1], 1000000));
            }
            newLine.push_back(1);
            line = newLine;
            total += std::count_if(line.begin(), line.end(), [](const auto& nr) {
                return nr >= 1000000;
            });
        }

        return total;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_053::solve(0) << std::endl;

    return 0;
}
#endif
