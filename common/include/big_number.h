#include <vector>

namespace big_number {
    class BigNumber {
    public:
        explicit BigNumber(int k);
        BigNumber(const std::vector<int>& nr);
        BigNumber operator*=(const int& other);

        BigNumber operator+=(const BigNumber &other);
        bool operator==(const BigNumber &other) const;

        friend std::ostream& operator<< (std::ostream& stream, const BigNumber& bigNumber);

        size_t size();
        size_t sumOfNumbers();
        bool isPalindrom();

        std::vector<int> number;
    };
}
