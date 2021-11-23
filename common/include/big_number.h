#include <vector>

namespace big_number {
    class BigNumber {
    public:
        explicit BigNumber(int k);
        BigNumber(const std::vector<int>& nr);
        BigNumber operator*=(const long long& other);
        friend BigNumber operator*(const BigNumber& number, const long long& other);
        friend BigNumber operator*(const long long& other, const BigNumber& number);
        friend BigNumber operator*(const BigNumber& number1, const BigNumber& number2);

        BigNumber operator+=(const BigNumber &other);
        friend BigNumber operator+(const BigNumber& number1, const BigNumber& number2);
        friend BigNumber operator+(const BigNumber& number1, const int& nr);

        bool operator==(const BigNumber &other) const;
        bool operator<(const BigNumber &other) const;

        friend std::ostream& operator<< (std::ostream& stream, const BigNumber& bigNumber);

        size_t size() const;
        size_t size();
        size_t sumOfNumbers();
        bool isPalindrom();

        std::vector<int> number;
    };
}
