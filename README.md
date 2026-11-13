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

### Shape area calculator

[shape_area_calculator.cpp](04-switch-programs/shape_area_calculator.cpp) Offers rectangle (length × width), circle (π × radius²), and triangle (base × height ÷ 2). Select a shape, then enter its dimensions on separate lines. Dimensions must be finite and non-negative. Results are shown to two decimal places.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 04-switch-programs/shape_area_calculator.cpp -o build/shape_area_calculator
./build/shape_area_calculator
```

Sample input: `2
5
`

### Print numbers 1 to 100

[print_one_to_hundred.cpp](05-basic-loops/print_one_to_hundred.cpp) Uses a for loop to print every integer from 1 through 100, one per line. No input is required.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 05-basic-loops/print_one_to_hundred.cpp -o build/print_one_to_hundred
./build/print_one_to_hundred
```

Sample input: `No input`

### Print even numbers from 1 to 100

[print_even_numbers.cpp](05-basic-loops/print_even_numbers.cpp) Uses a for loop that advances by two to print the even integers from 2 through 100, one per line. No input is required.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 05-basic-loops/print_even_numbers.cpp -o build/print_even_numbers
./build/print_even_numbers
```

Sample input: `No input`

### Print odd numbers from 1 to 100

[print_odd_numbers.cpp](05-basic-loops/print_odd_numbers.cpp) Uses a for loop that advances by two to print odd integers from 1 through 99, one per line. No input is required.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 05-basic-loops/print_odd_numbers.cpp -o build/print_odd_numbers
./build/print_odd_numbers
```

Sample input: `No input`

### Sum from 1 to n

[sum_one_to_n.cpp](05-basic-loops/sum_one_to_n.cpp) Reads a whole number n from 0 through 4294967295 and calculates n × (n + 1) ÷ 2. It divides an even factor before multiplying, keeping the result within the signed 64-bit range. n = 0 gives a sum of zero.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 05-basic-loops/sum_one_to_n.cpp -o build/sum_one_to_n
./build/sum_one_to_n
```

Sample input: `10`

### Multiplication table

[multiplication_table.cpp](05-basic-loops/multiplication_table.cpp) Reads a signed integer and prints its first ten multiples. The input is limited to ±922337203685477580 so every product fits in a signed 64-bit integer. Negative numbers and zero are supported.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 05-basic-loops/multiplication_table.cpp -o build/multiplication_table
./build/multiplication_table
```

Sample input: `7`

### Power of a number

[power_calculator.cpp](05-basic-loops/power_calculator.cpp) Reads a finite floating-point base and an integer exponent from -1024 through 1024. A loop multiplies the base by itself; negative exponents return the reciprocal. The result is printed with up to 10 significant digits. Zero with a negative exponent, non-finite inputs, and overflow are reported.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 05-basic-loops/power_calculator.cpp -o build/power_calculator
./build/power_calculator
```

Sample input: `2 10`

### Count digits in a number

[count_digits.cpp](05-basic-loops/count_digits.cpp) Reads one signed 64-bit integer and counts its base-10 digits with a do/while loop. The minus sign is not counted; zero has one digit. Decimals, extra values, and integers outside the signed 64-bit range are rejected.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 05-basic-loops/count_digits.cpp -o build/count_digits
./build/count_digits
```

Sample input: `-12345`

### Reverse a number

[reverse_number.cpp](06-number-based/reverse_number.cpp) Reads a signed 64-bit integer and reverses its decimal digits with a loop. Leading zeroes in the reversed result disappear; a minus sign stays at the front. If the reversed value cannot fit in a signed 64-bit integer, the program reports it.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 06-number-based/reverse_number.cpp -o build/reverse_number
./build/reverse_number
```

Sample input: `-120`

### Palindrome number

[palindrome_number.cpp](06-number-based/palindrome_number.cpp) Checks whether a non-negative signed 64-bit integer reads the same forward and backward. Uses a half-reversal loop to avoid overflowing while reversing large values. Negative numbers are not considered palindromes; zero is a palindrome.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 06-number-based/palindrome_number.cpp -o build/palindrome_number
./build/palindrome_number
```

Sample input: `12321`

### Armstrong number

[armstrong_number.cpp](06-number-based/armstrong_number.cpp) For a non-negative signed 64-bit integer, counts its decimal digits and checks whether the sum of each digit raised to that count equals the original number. For example, 153 = 1³ + 5³ + 3³. Negative numbers are rejected; zero is an Armstrong number.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 06-number-based/armstrong_number.cpp -o build/armstrong_number
./build/armstrong_number
```

Sample input: `153`

### Prime number

[prime_number.cpp](06-number-based/prime_number.cpp) reads one signed 32-bit whole number and checks whether it is prime by trying divisors up to its square root. Numbers below 2 are not prime. Decimals, extra tokens, and out-of-range values are rejected.

```sh
g++ -std=c++17 -Wall -Wextra -pedantic 06-number-based/prime_number.cpp -o build/prime_number
./build/prime_number
```

Sample input: `29` (result: `Prime number`)

### Prime numbers in a range

[prime_numbers_in_range.cpp](06-number-based/prime_numbers_in_range.cpp) reads an inclusive start and end as signed 32-bit whole numbers, then prints every prime in that range. Ranges may include negative numbers; values below 2 are skipped. The start must not exceed the end, and extra or invalid input is rejected.

```sh
g++ -std=c++17 -Wall -Wextra -pedantic 06-number-based/prime_numbers_in_range.cpp -o build/prime_numbers_in_range
./build/prime_numbers_in_range
```

Sample input: `10 30` (result: `11 13 17 19 23 29`)

### Fibonacci series

[fibonacci_series.cpp](06-number-based/fibonacci_series.cpp) reads a term count from 0 to 93 and prints that many Fibonacci numbers starting with 0, 1. The 93-term limit keeps every printed value within a signed 64-bit integer. Zero terms prints `No terms`; invalid counts and extra input are rejected.

```sh
g++ -std=c++17 -Wall -Wextra -pedantic 06-number-based/fibonacci_series.cpp -o build/fibonacci_series
./build/fibonacci_series
```

Sample input: `10` (result: `0 1 1 2 3 5 8 13 21 34`)

### Perfect number

[perfect_number.cpp](06-number-based/perfect_number.cpp) checks a positive signed 32-bit integer by summing its positive proper divisors. For example, 6 is perfect because 1 + 2 + 3 = 6. Zero, negative values, and 1 are not perfect. Invalid or extra input is rejected.

```sh
g++ -std=c++17 -Wall -Wextra -pedantic 06-number-based/perfect_number.cpp -o build/perfect_number
./build/perfect_number
```

Sample input: `28` (result: `Perfect number`)

### Strong number

[strong_number.cpp](06-number-based/strong_number.cpp) sums the factorials of the decimal digits of a non-negative signed 32-bit integer and compares the sum with the original value. Zero is not Strong because 0! = 1. Negative and invalid input is rejected.

```sh
g++ -std=c++17 -Wall -Wextra -pedantic 06-number-based/strong_number.cpp -o build/strong_number
./build/strong_number
```

Sample input: `145` (result: `Strong number`)

### Sum of digits

[sum_of_digits.cpp](06-number-based/sum_of_digits.cpp) adds the decimal digits of one signed 64-bit integer, ignoring its minus sign. Zero has a digit sum of zero. The calculation safely handles the minimum signed 64-bit value; invalid or extra input is rejected.

```sh
g++ -std=c++17 -Wall -Wextra -pedantic 06-number-based/sum_of_digits.cpp -o build/sum_of_digits
./build/sum_of_digits
```

Sample input: `-12345` (result: `15`)

### Product of digits

[product_of_digits.cpp](06-number-based/product_of_digits.cpp) solves the product of digits exercise. It accepts whole-number input and reports invalid input clearly.

```sh
g++ -std=c++17 -Wall -Wextra -pedantic 06-number-based/product_of_digits.cpp -o build/product_of_digits
./build/product_of_digits
```

Sample input: `1234`

### GCD/HCF

[gcd_hcf.cpp](06-number-based/gcd_hcf.cpp) solves the gcd/hcf exercise. It accepts whole-number input and reports invalid input clearly.

```sh
g++ -std=c++17 -Wall -Wextra -pedantic 06-number-based/gcd_hcf.cpp -o build/gcd_hcf
./build/gcd_hcf
```

Sample input: `48 18`

### LCM

[lcm_calculator.cpp](06-number-based/lcm_calculator.cpp) solves the lcm exercise. It accepts whole-number input and reports invalid input clearly.

```sh
g++ -std=c++17 -Wall -Wextra -pedantic 06-number-based/lcm_calculator.cpp -o build/lcm_calculator
./build/lcm_calculator
```

Sample input: `12 18`

### Square star pattern

[square_star_pattern.cpp](07-pattern-programs/square_star_pattern.cpp) prints a square of stars for a size from 1 to 50. Compile with g++ -std=c++17 and run the program. Sample input: `3`.
### Right triangle star pattern

[right_triangle_pattern.cpp](07-pattern-programs/right_triangle_pattern.cpp) prints a growing right triangle for a size from 1 to 50. Compile with g++ -std=c++17 and run the program. Sample input: `3`.

### Pyramid pattern

[pyramid_pattern.cpp](07-pattern-programs/pyramid_pattern.cpp) prints a centered pyramid of stars. Input size is 1–50.

Sample input: `3`

### Number triangle

[number_triangle.cpp](07-pattern-programs/number_triangle.cpp) prints consecutive numbers in a growing triangle. Input size is 1–50.

Sample input: `3`

### Floyd's triangle

[floyd_triangle.cpp](07-pattern-programs/floyd_triangle.cpp) prints consecutive numbers in Floyd triangle rows. Input size is 1–50.

Sample input: `3`

### Pascal triangle

[pascal_triangle.cpp](07-pattern-programs/pascal_triangle.cpp) prints Pascal triangle rows for a size from 1 to 20.

Sample input: `5`

### Diamond star pattern

[diamond_pattern.cpp](07-pattern-programs/diamond_pattern.cpp) prints a centered diamond for half-height from 1 to 25.

Sample input: `5`

### Add two numbers using a function

[add_two_numbers_function.cpp](08-functions-methods/add_two_numbers_function.cpp) adds two signed 32-bit integers in a reusable function.

Sample input: `5`

### maximum using function

[maximum_using_function.cpp](08-functions-methods/maximum_using_function.cpp) finds the larger of two signed integers with a helper function.

Sample input: `8 3`

### prime checker function

[prime_checker_function.cpp](08-functions-methods/prime_checker_function.cpp) checks primality using a reusable helper function.

Sample input: `8 3`

### factorial using function

[factorial_using_function.cpp](08-functions-methods/factorial_using_function.cpp) calculates factorial for values from 0 through 20 with a helper function.

Sample input: `8 3`

### Fibonacci using function

[fibonacci_using_function.cpp](08-functions-methods/fibonacci_using_function.cpp) prints a Fibonacci sequence using a function, with a term count from 0 to 93.

Sample input: `8 2`

### Function overloading

[function_overloading.cpp](08-functions-methods/function_overloading.cpp) demonstrates overloaded addition for integer and decimal values.

Sample input: `8 2`

### Pass arguments and return values

[pass_arguments_return_value.cpp](08-functions-methods/pass_arguments_return_value.cpp) computes rectangle area by passing dimensions to a function and returning its result.

Sample input: `8 2`

### recursive factorial

[recursive_factorial.cpp](28-recursion-problems/recursive_factorial.cpp) calculates factorial recursively for values from 0 to 20.

Sample input: `5`

### recursive Fibonacci

[recursive_fibonacci.cpp](28-recursion-problems/recursive_fibonacci.cpp) prints Fibonacci terms with a memoized recursive function for up to 93 terms.

Sample input: `5`

### recursive sum of digits

[recursive_sum.cpp](28-recursion-problems/recursive_sum.cpp) adds digits recursively and handles the signed 64-bit minimum.

Sample input: `5`

### recursive GCD

[recursive_gcd.cpp](28-recursion-problems/recursive_gcd.cpp) finds the GCD/HCF of two signed 32-bit numbers using Euclid’s recursive algorithm.

Sample input: `48 18`

### recursive reverse number

[recursive_reverse_number.cpp](28-recursion-problems/recursive_reverse_number.cpp) reverses the digits of a signed 32-bit integer recursively.

Sample input: `48 18`

### Tower of Hanoi

[tower_of_hanoi.cpp](28-recursion-problems/tower_of_hanoi.cpp) prints the recursive moves for 1 to 10 disks and reports the move count.

Sample input: `48 18`

### recursive binary search

[recursive_binary_search.cpp](28-recursion-problems/recursive_binary_search.cpp) searches a sorted array recursively and reports the matching index or not found.

Sample input: `3`

### array input and display

[array_input_display.cpp](09-one-dimensional-arrays/array_input_display.cpp) reads up to 100 whole numbers and displays them in order.

Sample input: `3`

### sum of array elements

[array_sum.cpp](09-one-dimensional-arrays/array_sum.cpp) reads up to 100 whole numbers and calculates their sum.

Sample input: `3`

### average of array

[array_average.cpp](09-one-dimensional-arrays/array_average.cpp) calculates the average of 1 to 100 signed whole numbers.

Sample input: `3 2 4 6`

### largest and smallest array elements

[largest_smallest_array.cpp](09-one-dimensional-arrays/largest_smallest_array.cpp) finds the minimum and maximum values in the input array.

Sample input: `3 2 4 6`

### second largest array element

[second_largest_array.cpp](09-one-dimensional-arrays/second_largest_array.cpp) finds the second distinct largest value, including for arrays with duplicate or negative values.

Sample input: `3 2 4 6`

### Reverse an array

[reverse_array.cpp](09-one-dimensional-arrays/reverse_array.cpp) reads an array size from 1 to 100 followed by that many whole numbers, then prints the values in reverse order. A one-element array is supported.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 09-one-dimensional-arrays/reverse_array.cpp -o build/reverse_array
./build/reverse_array
```

Sample input:

```text
5
1 2 3 4 5
```

Result (after the prompt): `Reversed array: 5 4 3 2 1`

### Count even and odd array elements

[count_even_odd_array.cpp](09-one-dimensional-arrays/count_even_odd_array.cpp) reads 1 to 100 whole numbers and counts how many are even or odd. Zero and negative numbers are handled using their remainder when divided by two.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 09-one-dimensional-arrays/count_even_odd_array.cpp -o build/count_even_odd_array
./build/count_even_odd_array
```

Sample input:

```text
6
0 1 2 3 -4 -5
```

Result: `Even count: 3` and `Odd count: 3`

### Search for an array element

[search_array_element.cpp](09-one-dimensional-arrays/search_array_element.cpp) reads an array of 1 to 100 whole numbers and then a target value. It uses a linear search and reports the zero-based index of the first match, or `Not found`.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 09-one-dimensional-arrays/search_array_element.cpp -o build/search_array_element
./build/search_array_element
```

Sample input:

```text
6
4 8 2 8 -1 0
8
```

Result: `Found at index 1`

### Copy an array

[copy_array.cpp](09-one-dimensional-arrays/copy_array.cpp) reads 1 to 100 whole numbers, copies each value into a second array, and displays the copy in its original order.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 09-one-dimensional-arrays/copy_array.cpp -o build/copy_array
./build/copy_array
```

Sample input:

```text
4
7 -2 7 0
```

Result: `Copied array: 7 -2 7 0`

### Merge two arrays

[merge_arrays.cpp](09-one-dimensional-arrays/merge_arrays.cpp) reads two arrays, each with 1 to 100 whole numbers, and copies their values in order into one merged array.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 09-one-dimensional-arrays/merge_arrays.cpp -o build/merge_arrays
./build/merge_arrays
```

Sample input:

```text
3
1 2 3
2
4 5
```

Result: `Merged array: 1 2 3 4 5`

### Remove duplicate array elements

[remove_duplicates.cpp](09-one-dimensional-arrays/remove_duplicates.cpp) reads 1 to 100 whole numbers and keeps the first occurrence of each value. It preserves the original order of the remaining elements.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 09-one-dimensional-arrays/remove_duplicates.cpp -o build/remove_duplicates
./build/remove_duplicates
```

Sample input:

```text
6
4 2 4 3 2 3
```

Result: `Array without duplicates: 4 2 3`

## Searching algorithms

### Binary search

[binary_search.cpp](10-searching-algorithms/binary_search.cpp) searches a sorted ascending array of 1 to 100 whole numbers. It repeatedly checks the middle value, reducing the search range by half. The result uses a zero-based index.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 10-searching-algorithms/binary_search.cpp -o build/binary_search
./build/binary_search
```

Sample input:

```text
6
-5 -1 0 4 8 12
8
```

Result: `Found at index 4`

## Sorting algorithms

### Bubble sort

[bubble_sort.cpp](11-sorting-algorithms/bubble_sort.cpp) sorts 1 to 100 whole numbers in ascending order. It compares neighboring values and swaps them when they are out of order; an already sorted pass ends the algorithm early.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 11-sorting-algorithms/bubble_sort.cpp -o build/bubble_sort
./build/bubble_sort
```

Sample input:

```text
6
5 -1 3 3 0 2
```

Result: `Sorted array: -1 0 2 3 3 5`

### Selection sort

[selection_sort.cpp](11-sorting-algorithms/selection_sort.cpp) sorts 1 to 100 whole numbers in ascending order. On each pass it selects the smallest remaining value and places it at the beginning of the unsorted portion.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 11-sorting-algorithms/selection_sort.cpp -o build/selection_sort
./build/selection_sort
```

Sample input:

```text
6
5 -1 3 3 0 2
```

Result: `Sorted array: -1 0 2 3 3 5`

### Insertion sort

[insertion_sort.cpp](11-sorting-algorithms/insertion_sort.cpp) sorts 1 to 100 whole numbers in ascending order. It takes each next value and inserts it into its correct position in the already sorted part of the array.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 11-sorting-algorithms/insertion_sort.cpp -o build/insertion_sort
./build/insertion_sort
```

Sample input:

```text
6
5 -1 3 3 0 2
```

Result: `Sorted array: -1 0 2 3 3 5`

### Merge sort

[merge_sort.cpp](11-sorting-algorithms/merge_sort.cpp) sorts 1 to 100 whole numbers in ascending order. It recursively divides the array into halves, sorts them, and merges the sorted halves back together.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 11-sorting-algorithms/merge_sort.cpp -o build/merge_sort
./build/merge_sort
```

Sample input:

```text
6
5 -1 3 3 0 2
```

Result: `Sorted array: -1 0 2 3 3 5`

### Quick sort

[quick_sort.cpp](11-sorting-algorithms/quick_sort.cpp) sorts 1 to 100 whole numbers in ascending order. It partitions values around a pivot, then recursively sorts the portions on either side.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 11-sorting-algorithms/quick_sort.cpp -o build/quick_sort
./build/quick_sort
```

Sample input:

```text
6
5 -1 3 3 0 2
```

Result: `Sorted array: -1 0 2 3 3 5`

## Two-dimensional arrays and matrices

### Input and display a matrix

[matrix_input_display.cpp](12-two-dimensional-arrays/matrix_input_display.cpp) reads row and column counts from 1 to 10, then reads and displays the matrix row by row.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 12-two-dimensional-arrays/matrix_input_display.cpp -o build/matrix_input_display
./build/matrix_input_display
```

Sample input:

```text
2 3
1 2 3
4 5 6
```

The displayed matrix is:

```text
1 2 3
4 5 6
```

### Matrix addition

[matrix_addition.cpp](12-two-dimensional-arrays/matrix_addition.cpp) adds two matrices with the same dimensions. Enter row and column counts from 1 to 10, then enter each matrix row by row.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 12-two-dimensional-arrays/matrix_addition.cpp -o build/matrix_addition
./build/matrix_addition
```

Sample input:

```text
2 2
1 2
3 4
5 6
7 8
```

The sum matrix is:

```text
6 8
10 12
```

### Matrix subtraction

[matrix_subtraction.cpp](12-two-dimensional-arrays/matrix_subtraction.cpp) subtracts the second matrix from the first. Both matrices use the same row and column counts, each from 1 to 10.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 12-two-dimensional-arrays/matrix_subtraction.cpp -o build/matrix_subtraction
./build/matrix_subtraction
```

Sample input:

```text
2 2
9 8
7 6
1 2
3 4
```

The difference matrix is:

```text
8 6
4 2
```

### Matrix multiplication

[matrix_multiplication.cpp](12-two-dimensional-arrays/matrix_multiplication.cpp) multiplies two matrices when the first matrix's column count equals the second matrix's row count. Each dimension must be from 1 to 10.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 12-two-dimensional-arrays/matrix_multiplication.cpp -o build/matrix_multiplication
./build/matrix_multiplication
```

Sample input:

```text
2 3
1 2 3
4 5 6
3 2
7 8
9 10
11 12
```

The product matrix is:

```text
58 64
139 154
```

### Matrix transpose

[matrix_transpose.cpp](12-two-dimensional-arrays/matrix_transpose.cpp) reads a matrix with 1 to 10 rows and columns, then displays its transpose by turning each original column into a row.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 12-two-dimensional-arrays/matrix_transpose.cpp -o build/matrix_transpose
./build/matrix_transpose
```

Sample input:

```text
2 3
1 2 3
4 5 6
```

The transpose is:

```text
1 4
2 5
3 6
```

### Sum of main diagonal elements

[diagonal_sum.cpp](12-two-dimensional-arrays/diagonal_sum.cpp) reads a square matrix of size 1 to 10 and adds the values whose row and column indexes are equal (the main diagonal).

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 12-two-dimensional-arrays/diagonal_sum.cpp -o build/diagonal_sum
./build/diagonal_sum
```

Sample input:

```text
3
1 2 3
4 5 6
7 8 9
```

Result: `Main diagonal sum: 15`

### Check whether a matrix is symmetric

[symmetric_matrix.cpp](12-two-dimensional-arrays/symmetric_matrix.cpp) reads a square matrix of size 1 to 10 and checks whether each value at row `i`, column `j` equals the value at row `j`, column `i`.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 12-two-dimensional-arrays/symmetric_matrix.cpp -o build/symmetric_matrix
./build/symmetric_matrix
```

Sample input:

```text
3
1 2 3
2 4 5
3 5 6
```

Result: `Symmetric matrix`

### Find the largest matrix element

[largest_matrix_element.cpp](12-two-dimensional-arrays/largest_matrix_element.cpp) reads a matrix with 1 to 10 rows and columns and tracks the largest whole number as each value is entered. Negative values are supported.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 12-two-dimensional-arrays/largest_matrix_element.cpp -o build/largest_matrix_element
./build/largest_matrix_element
```

Sample input:

```text
2 3
-5 2 7
0 11 4
```

Result: `Largest matrix element: 11`

## String programs

### Read and display a string

[read_display_string.cpp](13-string-programs/read_display_string.cpp) reads a complete line, including spaces, and displays it. An empty line is accepted.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 13-string-programs/read_display_string.cpp -o build/read_display_string
./build/read_display_string
```

Sample input:

```text
Hello, Java and C++!
```

Result: `You entered: Hello, Java and C++!`

### Find the length of a string

[string_length.cpp](13-string-programs/string_length.cpp) reads a full line of text and prints its length, including spaces. An empty line has length zero. For this basic byte-based example, use ASCII text.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 13-string-programs/string_length.cpp -o build/string_length
./build/string_length
```

Sample input: `Hello world`

Result: `String length: 11`

### Reverse a string

[reverse_string.cpp](13-string-programs/reverse_string.cpp) reads a full line, including spaces, and prints its characters in reverse order. An empty line remains empty.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 13-string-programs/reverse_string.cpp -o build/reverse_string
./build/reverse_string
```

Sample input: `A man`

Result: `Reversed string: nam A`

### Check for a palindrome string

[palindrome_string.cpp](13-string-programs/palindrome_string.cpp) checks whether a line reads the same forward and backward. It ignores spaces, punctuation, and letter case; this beginner example compares ASCII letters and digits.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 13-string-programs/palindrome_string.cpp -o build/palindrome_string
./build/palindrome_string
```

Sample input: `A man, a plan, a canal: Panama!`

Result: `Palindrome`

### Count vowels and consonants

[count_vowels_consonants.cpp](13-string-programs/count_vowels_consonants.cpp) counts ASCII English letters in a line, treating uppercase and lowercase equally. Spaces, punctuation, and digits are ignored; `a`, `e`, `i`, `o`, and `u` are vowels, while other letters are consonants.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 13-string-programs/count_vowels_consonants.cpp -o build/count_vowels_consonants
./build/count_vowels_consonants
```

Sample input: `Hello, World! 123`

Result: `Vowels: 3` and `Consonants: 7`

### Count words in a string

[count_words.cpp](13-string-programs/count_words.cpp) counts whitespace-separated words in a full line. Multiple spaces do not add extra words, and an empty or whitespace-only line has a count of zero.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 13-string-programs/count_words.cpp -o build/count_words
./build/count_words
```

Sample input: `Hello, world! from Java`

Result: `Word count: 4`

### Convert text to uppercase and lowercase

[change_case.cpp](13-string-programs/change_case.cpp) reads a full line and displays uppercase and lowercase versions. This beginner example converts ASCII English letters and leaves spaces, digits, and punctuation unchanged.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 13-string-programs/change_case.cpp -o build/change_case
./build/change_case
```

Sample input: `Java 101!`

Result: `Uppercase: JAVA 101!` and `Lowercase: java 101!`

### Compare two strings

[compare_strings.cpp](13-string-programs/compare_strings.cpp) reads two complete lines and compares them lexicographically, including spaces and letter case. It reports whether they are equal or which comes first.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 13-string-programs/compare_strings.cpp -o build/compare_strings
./build/compare_strings
```

Sample input:

```text
apple
banana
```

Result: `First string comes before the second`

### Concatenate two strings

[concatenate_strings.cpp](13-string-programs/concatenate_strings.cpp) reads two complete lines and joins them in order. It does not add a separator, so include spaces in either input line when needed.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 13-string-programs/concatenate_strings.cpp -o build/concatenate_strings
./build/concatenate_strings
```

Sample input:

```text
Good 
morning
```

Result: `Concatenated string: Good morning`

### Character frequency

[character_frequency.cpp](13-string-programs/character_frequency.cpp) counts each distinct character in a full line, preserving the order of its first appearance. Counting is case-sensitive; spaces are shown as `(space)`. An empty line has no character entries.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 13-string-programs/character_frequency.cpp -o build/character_frequency
./build/character_frequency
```

Sample input: `banana`

Result: `b: 1`, `a: 3`, and `n: 2`

### Remove spaces from a string

[remove_spaces.cpp](13-string-programs/remove_spaces.cpp) removes ordinary space characters from a full line while preserving all other characters and their order.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 13-string-programs/remove_spaces.cpp -o build/remove_spaces
./build/remove_spaces
```

Sample input: `a b  c`

Result: `Without spaces: abc`

### Find duplicate characters

[duplicate_characters.cpp](13-string-programs/duplicate_characters.cpp) lists each character that appears more than once, with its count. Results follow the order of first appearance; matching is case-sensitive, and spaces are labeled `(space)`.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 13-string-programs/duplicate_characters.cpp -o build/duplicate_characters
./build/duplicate_characters
```

Sample input: `banana`

Result: `a: 3` and `n: 2`

## Structures and classes

### Student information

[student_information.cpp](14-structures-classes/student_information.cpp) stores a student's name, positive roll number, and positive age in a `Student` struct, then displays the record. Names can contain spaces.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 14-structures-classes/student_information.cpp -o build/student_information
./build/student_information
```

Sample input:

```text
Prabin Poudel
27
20
```

The program displays the name, roll number, and age.

### Employee information

[employee_information.cpp](14-structures-classes/employee_information.cpp) stores an employee's name, positive ID, and non-negative monthly salary in an `Employee` struct, then displays the record. Names can contain spaces.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 14-structures-classes/employee_information.cpp -o build/employee_information
./build/employee_information
```

Sample input:

```text
Ada Lovelace
102
55000.50
```

The salary is displayed to two decimal places.

### Book information

[book_information.cpp](14-structures-classes/book_information.cpp) stores a book's title, author, ISBN, and positive page count in a `Book` struct, then displays the record. The ISBN is kept as text so leading zeroes are preserved.

```sh
mkdir -p build
g++ -std=c++17 -Wall -Wextra -pedantic 14-structures-classes/book_information.cpp -o build/book_information
./build/book_information
```

Sample input:

```text
The Hobbit
J. R. R. Tolkien
9780547928227
310
```

The program displays all four fields.
