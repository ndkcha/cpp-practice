#include "../main.h"
#include <map>
#include <regex>

void pct::n_gram() {
    std::cout << "P2: n gram" << std::endl;
    int n, max = 0;
    std::string input, output;
    std::vector<std::string> lines;
    std::vector<int> frequencyValues;
    std::map<std::string, int> frequencies;
    std::regex alphaNumeric("^[a-zA-Z0-9]*");

    std::getline(std::cin, input);
    n = std::stoi(input);

    do {
        std::getline(std::cin, input);
        lines.push_back(input);
        n--;
    } while (n > 0);

    std::getline(std::cin, input);
    n = std::stoi(input);

    for (std::string &line : lines) {
        for (int i = 0; (int) i < line.size(); i++) {
            std::string sub = line.substr(i, n);
            if (std::regex_match(sub, alphaNumeric))
                ++frequencies[sub];
        }
    }

    // trying to find the max value with transform logic.
    std::transform(frequencies.begin(), frequencies.end(), std::back_inserter(frequencyValues),
                   [](const std::map<std::string, int>::value_type &val) { return val.second; });

    max = *std::max_element(frequencyValues.begin(), frequencyValues.end());

    for (const auto &item : frequencies) {
        if (item.second == max) {
            output = item.first;
            break;
        }
    }

    std::cout << ((n == 1) ? "Unigram" : ((n == 2) ? "Bigram" : "Trigram")) << " " << output << std::endl;
}