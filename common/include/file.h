#include <string>

namespace file {
    std::vector<std::string> readFileAsArrayOfString(std::string path);
    std::vector<std::vector<int>> readFileAsArrayOfArrayOfInt(std::string_view path);
}
