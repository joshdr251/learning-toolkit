# Learning Toolkit – C++ & CMake
A collection of small, standalone C++ console programs, designed as a learning project to practice the fundamentals of C++: functions, user input, input validation, the standard library, and working with CMake.

Each program has its own `main()` and is **completely independent** of the others. They only share a single `CMakeLists.txt` that builds all of them at once.

## ✨ | Programs

### 💰 Compound Interest Calculator
Calculates the final capital after a given number of years, including an initial capital and a fixed amount that is saved every year. The interest is added once per year, and the yearly savings are paid in at the beginning of each year.

**Highlights:**
- Combines the growth of the initial capital with the growth of the yearly savings in a single formula
- Interest rate is stored in a global variable (`5 %`)
- The program takes no input: the example values (`1000` initial capital, `5` years, `500` saved per year) are set in `main()`
### 💱 Currency Converter
Converts an amount between Euro, Dollar, and Pounds. The program runs in a loop, so several conversions can be made in a row, and it ends when `quit` is entered at one of the currency prompts.

**Highlights:**
- Fixed exchange rates for every combination of the three currencies
- Input validation: invalid, negative, or infinite amounts are rejected without crashing
- Unknown currencies and identical source/target currencies are reported as wrong input
- Currency names are case-sensitive (`Euro`, `Dollar`, `Pounds`)
  | From | To | Rate |
  |---|---|---|
  | Euro | Dollar | 1.12 |
  | Euro | Pounds | 0.85 |
  | Dollar | Euro | 0.89 |
  | Dollar | Pounds | 0.75 |
  | Pounds | Euro | 1.18 |
  | Pounds | Dollar | 1.33 |

### 🎯 Guess the Numbers
A number guessing game. The program picks a random number between 1 and 100, and the player guesses until the number is found. After every guess, the program tells whether the guess was too large or too small.

**Highlights:**
- Random number generation with `std::mt19937` and `std::uniform_int_distribution`
- Input validation: non-numeric input and numbers outside of 1–100 are rejected
- Game logic, input handling, and number generation are split into separate functions
## 🛠️ | Technologies & Libraries
* ``C++20`` - Language standard
* ``CMake`` - Build system for all three programs
* ``iostream`` - Console input and output
* ``string`` - Reading and converting user input
* ``vector`` - Storing the valid currencies
* ``algorithm`` - Searching the valid currencies with `std::ranges::find`
* ``cmath`` - Power calculation for the compound interest
* ``random`` - Generating the random number
## 📁 | Project Structure
```
learning-toolkit/
│
├── CMakeLists.txt                    # Builds all three programs
├── compound_interest_calculator.cpp  # Compound interest with yearly savings
├── currency_converter.cpp            # Currency conversion with input validation
├── guess_the_numbers.cpp             # Number guessing game
└── .gitignore
```

## 🚀 | Installation

1. Clone the repository
```bash
   git clone https://github.com/joshdr251/learning-toolkit.git
   cd learning-toolkit
```

2. Build all programs
```bash
   cmake -B build
   cmake --build build
```

3. Run a program of your choice (the exact location of the executables depends on your compiler, e.g. `build/` or `build/Debug/`)
```bash
   ./build/compound_interest_calculator
   ./build/currency_converter
   ./build/guess_the_numbers
```

You need a C++20-capable compiler and CMake 3.20 or newer.

## 🗂️ | Usage

**Compound Interest Calculator** needs no input and prints the final capital for the values set in `main()`:

```
4177.24
```

To try other values, change the arguments of `calculate_compound_interest(...)` in `main()` or the `interest_rate` at the top of `compound_interest_calculator.cpp`.

**Currency Converter** asks for both currencies and the amount, then prints the result:

```
Which currency do you have:
Euro
To which currency do you want to convert:
Dollar
Input the amount you want to change:
100
112
```

Enter `quit` at one of the currency prompts to end the program.

**Guess the Numbers** asks for guesses until the number is found:

```
Enter a number between 1 and 100:
50
Too large! Try something smaller...
Enter a number between 1 and 100:
25
Too small! Try something larger...
Enter a number between 1 and 100:
37
Yes! This is the right number...
```

## 📕 | Notes
* The programs were developed using C++20 and CLion
* The exchange rates of the currency converter are fixed example values and are not updated automatically
* This is an ongoing learning project
## 🪲 | Bugs
* Feel free to report any bugs
 