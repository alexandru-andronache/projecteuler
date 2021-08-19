#include <vector>
#include <iostream>

namespace problem_019 {
    bool isLeapYear(int year) {
        if (year % 4 == 0) {
            if (year % 100 == 0) {
                if (year % 400 == 0) {
                    return true;
                }
                return false;
            }
            return true;
        }
        return false;
    }
    int solve() {
        std::vector<int> months {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30 ,31};
        int currentDay = 0; // Monday
        int sol = 0;
        for (int year = 1900; year <= 2000; ++year) {
            for (int month = 0; month < months.size(); ++month) {
                if (year > 1900 && currentDay == 6) {
                    sol++;
                }
                if (isLeapYear(year)) {
                    months[1] = 29;
                }
                else {
                    months[1] = 28;
                }
                for (int day = 1; day <= months[month]; ++day) {
                    currentDay = (currentDay + 1) % 7;
                }
            }
        }

        return sol;
    }
}

#ifndef TESTING
int main() {
    std::cout << "Solution : " << problem_019::solve(0) << std::endl;

    return 0;
}
#endif
