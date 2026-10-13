
#include <iostream>
#include <cmath>

double interest_rate = 5;

double calculate_compound_interest(int initial_capital, int duration, int saved_amount) {  // calculates compound interest
    double interest_factor = 1 + interest_rate / 100;
    double starting_capital = initial_capital * pow(interest_factor, duration);
    double savings_rate = saved_amount * interest_factor * ((pow(interest_factor, duration) - 1) / (interest_factor - 1));
    double compound_interest = starting_capital + savings_rate;
    return compound_interest;
}

int main() {  // handles sequence
    std::cout << calculate_compound_interest(1000, 5, 500) << std::endl;
}
