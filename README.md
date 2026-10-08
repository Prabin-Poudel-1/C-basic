# C++ programming practice

Standalone beginner programs from the programming practice list.
Each solution is added with a separate commit and push.

## Run an exercise

Requires a C++17 compiler (g++ or clang++).

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 01-basic-input-output/hello_world.cpp -o build/hello_world
./build/hello_world
```

Replace `hello_world` with the filename of the exercise you want to run.

## Exercises

| Program | Practice | Sample input |
| --- | --- | --- |
| [hello_world.cpp](01-basic-input-output/hello_world.cpp) | Print Hello World | `No input` |
| [personal_details.cpp](01-basic-input-output/personal_details.cpp) | Read name, age, and address | `Prabin Poudel / 20 / Kathmandu Nepal` |
| [display_two_numbers.cpp](01-basic-input-output/display_two_numbers.cpp) | Input and display two numbers | `12.5 -3` |
| [simple_calculator.cpp](01-basic-input-output/simple_calculator.cpp) | Calculate with +, -, *, /, and % | `8 + 2` |
| [swap_numbers.cpp](01-basic-input-output/swap_numbers.cpp) | Swap two numbers using a temporary variable | `2.5 -3.5` |
| [temperature_converter.cpp](01-basic-input-output/temperature_converter.cpp) | Convert Celsius and Fahrenheit in both directions | `C 0` |

## Basic mathematical programs

### Rectangle area and perimeter

[rectangle_calculator.cpp](02-basic-mathematical-programs/rectangle_calculator.cpp) accepts non-negative length and width, including zero, and prints results to two decimal places.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 02-basic-mathematical-programs/rectangle_calculator.cpp -o build/rectangle_calculator
./build/rectangle_calculator
```

Sample input:

```text
5 3
```

Result (after the prompt):

```text
Area: 15.00
Perimeter: 16.00
```

### Circle area and circumference

[circle_calculator.cpp](02-basic-mathematical-programs/circle_calculator.cpp) accepts non-negative radius, including zero, and prints results to two decimal places.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 02-basic-mathematical-programs/circle_calculator.cpp -o build/circle_calculator
./build/circle_calculator
```

Sample input:

```text
5
```

Result (after the prompt):

```text
Area: 78.54
Circumference: 31.42
```
