#include <iostream>
#include <cctype>
#include <string_view>
#include <map>
#include <functional>

bool input_matches(std::string_view input, std::string_view pattern) {
    if (input.length() != pattern.length()) {
        return false;
    }

    static const std::map<char, std::function<int(int)>> validators{
        {'#', &isdigit},
        {'_', &isspace},
        {'@', &isalpha},
        {'?', [](int) { return 1; }}
    };

    return std::equal(input.cbegin(), pattern.cbegin(), pattern.cend(), [&](char ch, char mask) -> bool {
        if (auto iter{validators.find(mask)}; iter != validators.cend()) {
            return iter->second(ch) > 0;
        } else {
            return (ch == mask);
        }
    });
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}