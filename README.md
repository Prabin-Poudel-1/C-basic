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

### Average of numbers

[average_of_numbers.cpp](02-basic-mathematical-programs/average_of_numbers.cpp) reads a positive whole-number count on its own line, then that many finite numbers separated by whitespace. Negative values and decimals are allowed. It computes sum / count and displays the average to two decimal places. An overflowing running sum is reported instead of printing an invalid result.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 02-basic-mathematical-programs/average_of_numbers.cpp -o build/average_of_numbers
./build/average_of_numbers
```

Sample input:

```text
3
10 20 30
```

Result (after the prompts):

```text
Average: 20.00
```

### Percentage and grade

[percentage_and_grade.cpp](02-basic-mathematical-programs/percentage_and_grade.cpp) reads obtained marks and maximum marks, then calculates percentage = obtained / maximum × 100. Maximum marks must be positive; obtained marks must be between zero and maximum. Both values must be finite.

Example practice scale (not an institutional grading policy): A ≥ 90%, B ≥ 80%, C ≥ 70%, D ≥ 60%, E ≥ 50%, otherwise F. Grade comparisons use the unrounded percentage; the displayed percentage is rounded to two decimal places.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 02-basic-mathematical-programs/percentage_and_grade.cpp -o build/percentage_and_grade
./build/percentage_and_grade
```

Sample input:

```text
425 500
```

Result (after the prompt):

```text
Percentage: 85.00%
Grade: B
```

## Decision-making

### Positive, negative, or zero

[number_sign.cpp](03-decision-making/number_sign.cpp) reads one finite floating-point number and uses `if/else` to classify it. Integers, decimals, and scientific notation are accepted. Both positive and negative zero are classified as zero. Values are interpreted using double-precision floating point.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 03-decision-making/number_sign.cpp -o build/number_sign
./build/number_sign
```

Sample input:

```text
-12.5
```

Result (after the prompt):

```text
Negative
```

### Even or odd

[even_odd_checker.cpp](03-decision-making/even_odd_checker.cpp) reads one signed integer on a line and checks its remainder when divided by two. Zero and negative even numbers are even. Accepted range: −9223372036854775808 to 9223372036854775807. Decimals, extra tokens, and out-of-range inputs are rejected.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 03-decision-making/even_odd_checker.cpp -o build/even_odd_checker
./build/even_odd_checker
```

Sample input:

```text
-7
```

Result (after the prompt):

```text
Odd
```

### Largest of two numbers

[largest_of_two.cpp](03-decision-making/largest_of_two.cpp) reads two finite numbers and uses `if/else` to print the larger value. If they compare equal, it reports that both are equal. Integers, decimals, and scientific notation are accepted and interpreted using double-precision floating point; positive and negative zero compare equal.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 03-decision-making/largest_of_two.cpp -o build/largest_of_two
./build/largest_of_two
```

Sample input:

```text
10 20
```

Result (after the prompt): `Largest: 20` (Java displays `20.0`).

### Largest of three numbers

[largest_of_three.cpp](03-decision-making/largest_of_three.cpp) reads three finite numbers and uses `if/else` comparisons to print the largest value. Tied maximum values are handled with `>=`. Integers, decimals, and scientific notation are accepted and interpreted using double-precision floating point; positive and negative zero compare equal.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 03-decision-making/largest_of_three.cpp -o build/largest_of_three
./build/largest_of_three
```

Sample input:

```text
10 20 15
```

Result (after the prompt): `Largest: 20` (Java displays `20.0`).

### Leap year

[leap_year_checker.cpp](03-decision-making/leap_year_checker.cpp) reads one positive whole year and applies the Gregorian rule: divisible by 400, or divisible by 4 but not by 100. For example, 2000 is a leap year and 1900 is not. This exercise applies the rule to all accepted years, without modeling historical calendar changes. Accepted range: 1 to 9223372036854775807. Decimals and extra tokens are rejected.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 03-decision-making/leap_year_checker.cpp -o build/leap_year_checker
./build/leap_year_checker
```

Sample input:

```text
2024
```

Result (after the prompt):

```text
Leap year
```

### Voting eligibility (age-only practice)

[voting_eligibility.cpp](03-decision-making/voting_eligibility.cpp) reads one non-negative age in whole years and uses `if/else` with an example threshold of 18. This exercise checks only age, not citizenship, registration, or other voting requirements. The threshold is an exercise assumption rather than a complete eligibility determination. Accepted input range: 0 to 9223372036854775807; decimals and extra tokens are rejected.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 03-decision-making/voting_eligibility.cpp -o build/voting_eligibility
./build/voting_eligibility
```

Sample input:

```text
18
```

Result (after the prompt):

```text
Eligible by age.
```

### Grade calculation

[grade_calculator.cpp](03-decision-making/grade_calculator.cpp) reads one score out of 100, rather than calculating a percentage from marks. Uses the same example practice scale as PercentageAndGrade: A >= 90, B >= 80, C >= 70, D >= 60, E >= 50, otherwise F. The finite score must be in [0, 100]. Fractional scores use their unrounded value for comparison. This is an exercise scale, not an institutional grading policy.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 03-decision-making/grade_calculator.cpp -o build/grade_calculator
./build/grade_calculator
```

Sample input:

```text
85
```

Result (after the prompt):

```text
Grade: B
```

### Divisible by 5 and 11

[divisible_by_five_and_eleven.cpp](03-decision-making/divisible_by_five_and_eleven.cpp) reads one signed 64-bit integer and uses remainder checks joined by && to test divisibility by both 5 and 11. Zero and negative multiples of 55 satisfy the condition. Accepted range: -9223372036854775808 to 9223372036854775807; decimals and extra tokens are rejected.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 03-decision-making/divisible_by_five_and_eleven.cpp -o build/divisible_by_five_and_eleven
./build/divisible_by_five_and_eleven
```

Sample input:

```text
55
```

Result (after the prompt):

```text
Divisible by both 5 and 11.
```

### Simple electricity bill

[electricity_bill_calculator.cpp](03-decision-making/electricity_bill_calculator.cpp) reads one finite, non-negative number of consumed units. Fractional units are allowed. Uses fictional progressive rates for practice: the first 100 units cost 1.50 each, the next 100 cost 2.50 each, and units above 200 cost 4.00 each. Each rate applies only to its slab. No fixed charge, tax, or surcharge is included; these are not utility tariffs. Output uses generic currency units and two decimal places.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 03-decision-making/electricity_bill_calculator.cpp -o build/electricity_bill_calculator
./build/electricity_bill_calculator
```

Sample input:

```text
250
```

Result (after the prompt):

```text
Example bill: 600.00 currency units
```

## Switch programs

### Menu-driven calculator

[menu_calculator.cpp](04-switch-programs/menu_calculator.cpp) repeatedly displays a menu: 1 add, 2 subtract, 3 multiply, 4 divide, 5 remainder, 0 exit. Enter the choice and each operand on separate lines. Uses a switch for arithmetic and double-precision values; remainder uses Java `%` or C++ `std::fmod`. Invalid numeric choices, division/remainder by zero, and overflowing results return to the menu. Malformed or non-finite input ends the program with an error.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 04-switch-programs/menu_calculator.cpp -o build/menu_calculator
./build/menu_calculator
```

Sample input (divide 9 by 2, then exit):

```text
4
9
2
0
```

Output includes `Result: 4.5` and `Goodbye.` along with the menus and prompts.

### Day number to day name

[day_name.cpp](04-switch-programs/day_name.cpp) reads one whole-number day and uses a switch to select its name. Mapping: 1 Monday, 2 Tuesday, 3 Wednesday, 4 Thursday, 5 Friday, 6 Saturday, 7 Sunday. Values outside 1-7 are rejected; malformed input, decimals, and extra tokens are rejected too.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 04-switch-programs/day_name.cpp -o build/day_name
./build/day_name
```

Sample input:

```text
3
```

Result (after the prompt):

```text
Wednesday
```

### Month number to month name

[month_name.cpp](04-switch-programs/month_name.cpp) reads one whole-number month and uses a switch to select its English Gregorian month name: 1 January through 12 December. Values outside 1-12, malformed input, decimals, and extra tokens are rejected.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 04-switch-programs/month_name.cpp -o build/month_name
./build/month_name
```

Sample input:

```text
10
```

Result (after the prompt):

```text
October
```

### Simple ATM menu

[simple_atm.cpp](04-switch-programs/simple_atm.cpp) simulates an account starting at 1000 whole currency units. Switch menu: 1 balance, 2 deposit, 3 withdraw, 0 exit. Enter every choice and amount on its own line. Amounts must be positive signed 64-bit integers; insufficient funds and balance overflow leave the balance unchanged. Invalid numeric choices and rejected transactions return to the menu; malformed input ends the program. Balance is kept only in memory and resets to 1000 on each launch. No banking connection or real transactions are involved.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 04-switch-programs/simple_atm.cpp -o build/simple_atm
./build/simple_atm
```

Sample input (deposit 250, withdraw 100, then exit):

```text
2
250
3
100
0
```

Output includes `Balance: 1250`, `Balance: 1150`, and `Goodbye.` along with the menus and prompts.
\n### Shape area calculator\n\n[shape_area_calculator.cpp](04-switch-programs/shape_area_calculator.cpp) Offers rectangle (length × width), circle (π × radius²), and triangle (base × height ÷ 2). Select a shape, then enter its dimensions on separate lines. Dimensions must be finite and non-negative. Results are shown to two decimal places.\n\n```sh\nmkdir -p build\ng++ -std=c++17 -Wall -Wextra -pedantic 04-switch-programs/shape_area_calculator.cpp -o build/shape_area_calculator\n./build/shape_area_calculator\n```\n\nSample input: `2\n5\n`\n\n### Print numbers 1 to 100\n\n[print_one_to_hundred.cpp](05-basic-loops/print_one_to_hundred.cpp) Uses a for loop to print every integer from 1 through 100, one per line. No input is required.\n\n```sh\nmkdir -p build\ng++ -std=c++17 -Wall -Wextra -pedantic 05-basic-loops/print_one_to_hundred.cpp -o build/print_one_to_hundred\n./build/print_one_to_hundred\n```\n\nSample input: `No input`\n\n### Print even numbers from 1 to 100\n\n[print_even_numbers.cpp](05-basic-loops/print_even_numbers.cpp) Uses a for loop that advances by two to print the even integers from 2 through 100, one per line. No input is required.\n\n```sh\nmkdir -p build\ng++ -std=c++17 -Wall -Wextra -pedantic 05-basic-loops/print_even_numbers.cpp -o build/print_even_numbers\n./build/print_even_numbers\n```\n\nSample input: `No input`\n