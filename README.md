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

### Simple interest

[simple_interest.cpp](02-basic-mathematical-programs/simple_interest.cpp) reads principal, annual percentage rate, and time in years (fractional years are allowed). Inputs must be finite and non-negative. Simple interest = principal × rate × years / 100; total amount = principal + interest. Results use two decimal places.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 02-basic-mathematical-programs/simple_interest.cpp -o build/simple_interest
./build/simple_interest
```

Sample input:

```text
1000 5 2
```

Result (after the prompt):

```text
Simple interest: 100.00
Total amount: 1100.00
```

### Compound interest

[compound_interest.cpp](02-basic-mathematical-programs/compound_interest.cpp) Reads principal, annual percentage rate, and time in years. Uses annual compounding: amount = principal × (1 + rate / 100)^years; interest = amount − principal. Fractional years use the same power formula. Inputs must be finite and non-negative; results use two decimal places.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 02-basic-mathematical-programs/compound_interest.cpp -o build/compound_interest
./build/compound_interest
```

Sample input:

```text
1000 5 2
```

Result (after the prompt):

```text
Compound interest: 102.50
Total amount: 1102.50
```

### Seconds to hours, minutes, and seconds

[seconds_converter.cpp](02-basic-mathematical-programs/seconds_converter.cpp) Reads one non-negative whole number on a line (up to 9223372036854775807). Uses division and remainder to split it into total hours, remaining minutes, and remaining seconds. Hours may exceed 23; minutes and seconds stay between 0 and 59.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 02-basic-mathematical-programs/seconds_converter.cpp -o build/seconds_converter
./build/seconds_converter
```

Sample input:

```text
3661
```

Result (after the prompt):

```text
Hours: 1
Minutes: 1
Seconds: 1
```
