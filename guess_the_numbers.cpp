
#include <iostream>
#include <string>
#include <random>

int input_entry() {  // takes user input
    while (true) {
        std::string user_input;
        std::cout << "Enter a number between 1 and 100: \n";
        getline(std::cin, user_input);

        try {
            int user_input_int = stoi(user_input);
            if (user_input_int < 1 || user_input_int > 100) {
                std::cout << "Number has to be between 1 and 100..." << std::endl;
                continue;
            }
            return user_input_int;
        }
        catch (const std::exception& e) {
            std::cout << "Error intercepted: " << e.what() << "\n" << std::endl;
        }
    }
}

int generate_number() {  // generates a random number
    std::mt19937 gen(std::random_device{}());
    std::uniform_int_distribution<int> distrib(1, 100);
    int generated_number = distrib(gen);
    return generated_number;
}

bool game(int user_number, int random_number) {  // compares user input and generated number, provides Feedback
    if (random_number < user_number) {
        std::cout << "Too large! Try something smaller..." << std::endl;
        return true;
    }
    else if (random_number > user_number) {
        std::cout << "Too small! Try something larger..." << std::endl;
        return true;

    }
    else {
        std::cout << "Yes! This is the right number..." << std::endl;
        return false;
    }
}

int main() {  // handles sequence
    int random_number = generate_number();
    bool game_state = true;
    while (game_state) {
        int user_input = input_entry();
        game_state = game(user_input, random_number);
    }
}
