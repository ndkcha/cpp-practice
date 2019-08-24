#include "../main.h"

void pct::credit_card() {
    std::string input;
    std::cin >> input;
    bool isAlternative = false;
    int sum = 0;

    for (int i = (int) input.size() - 1; i >=0; i--) {
        int digit = (int) input[i] - (int) '0';

        if (isAlternative) {
            int mulTwo = digit * 2;
            if (mulTwo > 9)
                mulTwo = 1 + (mulTwo - 10);
            sum += mulTwo;
        } else
            sum += digit;

        isAlternative = !isAlternative;
    }

    int lastDigit = input[input.size() - 1] - '0';
    int mod = sum % 10;
    int correctDigit = lastDigit - mod;
    correctDigit = correctDigit < 0 ? correctDigit + 10 : correctDigit;

    std::cout << ((mod == 0) ? "VALID" : "INVALID ");
    if (mod != 0)
        std::cout << correctDigit;
}