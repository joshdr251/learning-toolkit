cmake_minimum_required(VERSION 4.3)
project(learning_toolkit)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

add_executable(compound_interest_calculator compound_interest_calculator.cpp)
add_executable(currency_converter currency_converter.cpp)
add_executable(guess_the_numbers guess_the_numbers.cpp)
