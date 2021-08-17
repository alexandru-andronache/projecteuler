#include "file.h"
#include <fstream>
#include <vector>

namespace file {

    std::vector<std::string> readFileAsArrayOfString(std::string path) {
        std::ifstream f(path);
        std::string line;
        std::vector<std::string> output;
        while (std::getline(f, line)) {
            output.push_back(line);
        }
        f.close();
        return output;
    }

    std::vector<std::vector<int>> readFileAsArrayOfArrayOfInt(std::string_view path) {
        std::ifstream f(path);
        std::string line;
        std::vector<std::vector<int>> output;
        while (std::getline(f, line)) {
            std::vector<int> l;
            l.push_back(0);
            for (const auto& c : line) {
                if (c >= '0' && c <= '9') {
                    l.back() = l.back() * 10 + c - '0';
                }
                else {
                    l.push_back(0);
                }
            }
            output.emplace_back(l);
        }
        f.close();
        return output;
    }
}