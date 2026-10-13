
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

double convert(double amount, double exchange_rate) {  // converts currencies
    return exchange_rate * amount;
}

int main() {  // handles sequence
    const std::vector<std::string> valid_currencies = {"Euro", "Dollar", "Pounds"};
    while (true) {
        std::string source_currency;
        std::cout << "\n" << "Which currency do you have: " << std::endl;
        std::getline(std::cin, source_currency);

        if (source_currency == "quit") {
            break;
        }

        std::string target_currency;
        std::cout << "To which currency do you want to convert: " << std::endl;
        std::getline(std::cin, target_currency);

        if (target_currency == "quit") {
            break;
        }

        std::string user_input_amount;
        std::cout << "Input the amount you want to change: " << std::endl;
        std::getline(std::cin, user_input_amount);

        double user_input_amount_double = 0;

        try {
            user_input_amount_double = std::stod(user_input_amount);

            if (std::isinf(user_input_amount_double) || user_input_amount_double < 0) {
                std::cout << "Not able to understand the input amount. Please try again!" << std::endl;
                continue;
            }
        }
        catch (const std::exception& e) {
            std::cout << "Error intercepted: " << e.what() << "\n" << std::endl;
            continue;
        }

        if (std::ranges::find(valid_currencies.begin(), valid_currencies.end(), source_currency) != valid_currencies.end() &&
    std::ranges::find(valid_currencies.begin(), valid_currencies.end(), target_currency) != valid_currencies.end()) {
            if (source_currency == "Euro" && target_currency == "Dollar") {
                std::cout << convert(user_input_amount_double, 1.12) << std::endl;
            }
            else if (source_currency == "Euro" && target_currency == "Pounds") {
                std::cout << convert(user_input_amount_double, 0.85) << std::endl;
            }
            else if (source_currency == "Dollar" && target_currency == "Euro") {
                std::cout << convert(user_input_amount_double, 0.89) << std::endl;
            }
            else if (source_currency == "Dollar" && target_currency == "Pounds") {
                std::cout << convert(user_input_amount_double, 0.75) << std::endl;
            }
            else if (source_currency == "Pounds" && target_currency == "Euro") {
                std::cout << convert(user_input_amount_double, 1.18) << std::endl;
            }
            else if (source_currency == "Pounds" && target_currency == "Dollar") {
                std::cout << convert(user_input_amount_double, 1.33) << std::endl;
            }
            else {
                std::cout << "Wrong input, try again!" << "\n" << std::endl;
            }
        }
        else {
            std::cout << "Wrong currency, try again!" << "\n" << std::endl;
        }
    }
}
