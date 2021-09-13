#include <vector>

namespace big_number {
    class BigNumber {
    public:
        explicit BigNumber(int k);
        BigNumber operator+=(BigNumber &other);
        bool operator==(const BigNumber &other) const;

        friend std::ostream& operator<< (std::ostream& stream, const BigNumber& bigNumber);

        size_t size();
    private:
        std::vector<int> number;
    };
}
