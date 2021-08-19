#include <string>

namespace file {
    std::string readFileAsString(std::string_view path);
    std::vector<std::string> readFileAsArrayOfString(std::string_view path);
    std::vector<std::vector<int>> readFileAsArrayOfArrayOfInt(std::string_view path);
}
