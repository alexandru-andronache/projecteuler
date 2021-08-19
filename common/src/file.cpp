#include "file.h"
#include <fstream>
#include <vector>

namespace file {

    std::string readFileAsString(std::string_view path) {
        constexpr auto read_size = std::size_t{4096};
        auto stream = std::ifstream{path.data()};
        stream.exceptions(std::ios_base::badbit);

        auto out = std::string{};
        auto buf = std::string(read_size, '\0');
        while (stream.read(& buf[0], read_size)) {
            out.append(buf, 0, stream.gcount());
        }
        out.append(buf, 0, stream.gcount());
        return out;
    }

    std::vector<std::string> readFileAsArrayOfString(std::string_view path) {
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