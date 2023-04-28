#  C++ Master Cheatsheet
  
  
##  Table of Contents
  
1. [Program Structure](#program-structure )
2. [Namespace](#namespace )
3. [Basic Input/Output](#basic-input-and-output )
4. [Variables and Constants](#variables-and-constants )
   a. [Variable Initialization](#variable-initialization )
   b. [Integer Types](#integer-types )
   c. [Floating Point Types](#floating-point-types )
   d. [Constants](#constants )
5. [Arrays and Vectors](#arrays-and-vectors )
   a. [Arrays](#arrays )
   b. [Multi-dimensional arrays](#multi-dimensional-arrays )
   c. [Vectors](#vectors )
6. [Statements and Operators](#statements-and-operators )
   a. [Expressions](#expressions )
   b. [Statements](#statements )
   c. [Operators](#operators )
   d. [Mixed Type Expressions](#mixed-type-expressions )
7. [Control Structures](#control-structures )
   a. [Selection Decision Making](#selection-decision-making )
   b. [Iteration Looping](#iteration-looping )
8. [Strings and Characters](#strings-and-characters )
   a. [Character Functions](#character-functions )
   b. [C-Style Strings](#c-style-strings )
   c. [C-Style String Functions](#c-style-string-functions )
   d. [C++ Strings](#c-strings )
9. [Functions](#functions )
   a. [Math Functions](#math-functions )
   b. [Function Prototypes](#function-prototypes )
   c. [Default Argument Values](#default-argument-values )
   d. [Passing Arrays into Functions](#passing-arrays-into-functions )
   e. [Pass by Reference](#pass-by-reference )
10. [Pointers and References](#pointers-and-references )
   a. [Pointers](#pointers )
   b. [Dynamic Memory Allocation](#dynamic-memory-allocation )
   c. [Relationship Between Arrays and Pointers](#relationship-between-arrays-and-pointers )
   d. [Pointer Arithmetic](#pointer-arithmetic )
   e. [References](#references )
11. [OOP - Classes and Objects](#oop---classes-and-objects )
   a. [Classes vs Objects](#classes-vs-objects )
   b. [Access Modifiers](#access-modifiers )
   b. [Constructors and Destructors](#constructors-and-destructors )
  
##  Appendices
  
1. [C++ Setup and Configuration](#c++-setup-and-configuration )
2. [Makefiles](#makefiles )
    a. [Object files](#object-o-files )
    b. [Makefile variables](#makefile-variables )
  
##  Program structure
  
  
**Preprocessor**: program that scans a `.cpp` file for preprocess directives, pulls the source code from the corresponding namespace(s), and loads it into the C++ file for the compiler to use.
  
**NOTE**: it does **not** understand C++ code. Instead it will scan the beggining of `.cpp` file looking for `#include` or `using` statements.
  
###  Comments
  
  
There are two kinds of comments.
  
```cpp
//single line comment
  
/*
    This is a multiple
     line
       comment
*/
```
  
Keep style of the comments _consistent_ and do **not** comment the _obvious_.
  
Multiline comments are often seen at the beginning of the code file to add relevant authorship information.
  
```cpp
/************************************************
 * author information
 * copyright information
 *
 ************************************************/
```
  
Also, do **not** use comments for Version Control
  
```cpp
/************************************************
 * 11/11/2017 Frank - fixed bu in ..
 * 11/13/2017 Jo - added function to...
 *
 ************************************************/
```
  
###  Main function
  
  
Every C++ program must have exactly one main() function
  
- Starting point of program execution
- return 0 indicates succesful program execution
- 2 versions that are both valid
  
Version 1:
  
```cpp
int main() {
    // code
  
    return 0;
}
  
program.exe
```
  
Version 2:
  
```cpp
int main(int argc, char *argv[]){
    // code
  
    return 0;
}
  
program.exe argument1 argument2
```
  
- `argc` stands for _argument count_
- `argv` stands for _argument vector_
  
If 0 is not returned, the operasting system can check the value of the return value to determine what is wrong.
  
##  Namespace
  
  
Namespaces are used to reduce the possibility of naming conflicts.
  
For example, `std` is the name for the C++ 'standard' namespace. Third party namespaces will have their own names.
  
To use the methods of an entire namespace:
  
```cpp
using namespace std;
```
  
To use only _some_ of the methods in the namespace:
  
```cpp
using namespace std::cout;
using namespace std::cin;
using namespace std::endl;
```
  
##  Basic Input and Output
  
  
`cout`
  
- standard output stream
- console
  
`cin`
  
- standard input stream
- keyboard
  
`<<`
  
- insertion
  
`>>`
  
- extraction operator
- input streams
  
```cpp
int main() {
  
    int num1, num2;
    double num3;
  
    cout << "Enter a first integer: ";
    cin >> num1;
  
    cout << "Enter a second integer: ";
    cin >> num2;
  
    cout << "You enteredd " << num1 << ", " << num2 << endl;
  
    return 0;
}
```
  
Characters written from the keyboard and are stored in an intermediate buffer. Once the compiler reads that piece of input, it will store it in a variable, ignoring any _whitespace characters_ inserted before or after it.
  
```
Enter a first integer: 100
Enter a second integer:    200
You entered 100, 200
```
  
> **NOTE**: `cin` _cannot_ read more than one piece of input at at time.
> Therefore, the following input will result in the first two inputs being stored in the separate `int` variables, thus skipping the second prompt entirely and executing the last code statement prior to `return 0`.
>
> ```
> Enter a first integer: 100 200> Enter a second integer: You > entered 100, 200
> ```
  
If you enter a double for an integer number, then the compiler will read the number in front of the decimal point and store that as the integer, thus losing accuracy on the value stored in the variable.
  
Next, it will store the remainder, 0.5, as a double
  
```cpp
cout << "Enter a integer: ";
cin >> num2;
cout << "Enter a double: ";
cin >> num3;
cout << "You entered: " << num2 << ", " << num3 <<endl;
```
  
```
Enter a integer: 10.5
Enter a double: You entered: 10, 0.5
Press any key to continue . . .
```
  
If you enter a string instead of an integer, the input will immediately fail and enter into a fail state, returning 0.
  
##  Variables and Constants
  
  
###  Variable Initialization
  
  
There are several ways to initialize variables in C++:
  
* **C-like** initialization (i.e. assignment initialization)
* **Constructor** initialization
* **List** initialization (introduced in C++11)
  
```cpp
int age; // unintialized
int age = 21; // C-like init.
int age (21); // Constr. init.
int age {21}; // init
```
  
**NOTE**: It is recommended to use the C++11 list initializati syntax. Uninitialized variables in C++ can store _any kind_ of undesired value.
  
**Global Variables** are variables declared outside the scope of functions
  
- Automatically initialized to zero
- **Danger**: they can be accessed from anywhere in your program, making them very error prone.
  
Compilers will first look locally for variables before looking globally. If there is a local variable with the same name as the global variable then the compiler will use the local one.
  
Unicode is the common standard for representing a number of characters common through many (alphabet-based) languages.
  
- Using the `char` data type is enough for our purposes.
  
###  Integer Types
  
  
Use modifiers like `short` and `long` to store shorter or smaller values of numbers, respectively.
  
To use integers that _only_ use positive values, use the **unsigned** keyword in your declaration.
  
By default, all integer types are defined as **signed** integers.
  
**NOTE**: You must take into account what kind of data and operations you will be performing to decide which integer type and modifiers you will use.
  
Example:
  
```cpp
unsigned short int exam_score {55};
cout << "My exam score was " << exam_score << endl;
  
int countries_represented {65};d << " represented in my meeting." << endl;
  
long people_in_florida { 20'610'000};
cout << "There are about " << people_in_florida << " people living in Florida." << endl;
  
long long people_on_earth {7'600'000'000};
cout << "There are about " << people_on_earth << " people living on earth." << endl;
  
long long distance_to_alpha_centauri {946'100'000'000};
cout << "The distance to alpha centauri is " << distance_to_alpha_centauri << " kilometers." << endl;
```
  
```
My middle initial is J
My exam score was 55
There were 65 represented in my meeting.
There are about 20610000 people living in Florida.
There are about 7600000000 people living on earth.
The distance to alpha centauri is 946100000000 kilometers.
```
  
**NOTE**: Starting with C++ 14 and onward, you can use single quotes `'` inside integers to improve readability of code without modifying the actual value of the variable.
  
###  Floating Point Types
  
  
```cpp
float car_payment {401.23};
cout << "My car payment is " << car_payment << "." << endl;
  
double pi {3.14159};
cout << "PI is " << pi << "." << endl;
  
long double large_amount {2.7e120};
cout << large_amount << " is a very big number." << endl;
```
  
```
My car payment is 401.23.
PI is 3.14159.
2.7e+120 is a very big number.
```
  
####  `sizeof` operator
  
  
The `sizeof` operator return the size in bytes of a variable or a type.
  
```cpp
// for data types
sizeof(int);
sizeof(double);
  
// for variables
sizeof(some_variable); // option 1
sizeof some_variable; // option 2
```
  
sizeof operator gets its information from two C++ files:
  
- `<climits>` provides information of integral types
- `<cfloat>` provides information of floating point types
  
We can use the values defined in `<climits>` to obtain the minimum value that can be stored for each data type.
  
```cpp
cout << "Minimum values: " << endl;
cout << "=================" << endl;
cout << "char:" << CHAR_MIN << endl;
cout << "int:" << INT_MIN << endl;
cout << "short:" << SHRT_MIN << endl;
cout << "long:" << LONG_MIN << endl;
cout << "long long:" << LLONG_MIN << endl;
cout << endl;
cout << "Maximum values: " << endl;
cout << "=================" << endl;
cout << "char:" << CHAR_MAX << endl;
cout << "int:" << INT_MAX << endl;
cout << "short:" << SHRT_MAX << endl;
cout << "long:" << LONG_MAX << endl;
cout << "long long:" << LLONG_MAX << endl;
```
  
```
Minimum values:
=================
char:-128
int:-2147483648
short:-32768
long:-2147483648
long long:-9223372036854775808
  
Maximum values:
=================
char:127
int:2147483647
short:32767
long:2147483647
long long:9223372036854775807
```
  
###  Constants
  
  
**Constants** are C++ variables with values that **cannot** be changed once they are declared.
  
Types of constants:
  
- Literal constants
- Declared constants
  - `const` keyword
- Constant expressions
  - `constexpr` keyword
- Enumerated constants
  - `enum`
- Defined constants
  - `#define`
  
**Literal constansts**
  
- The most obvious kind of constant
  
  ```cpp
  x = 12;
  y = 1.56;
  name = "Frank";
  middle_initial = 'J'
  ```
- Integer Literal Constants
  12 - an integer
  12U - an unsigned integer
  12L - a long integer
  12LL - a long long integer
- Character Literal Constants
  \n - newline
  \r - return
  \t - tab
  \b - backspace
  \\' - single quote
  \\" - double quote
  \\\\ - backslash
  
  ```cpp
  cout << "Hello\tthere\nmy friend\n";
  ```
  
  ```
  Hello   there
  my friend
  ```
  
Declared constants are the most popular way of declaring constants. If you try to change the error of a constant, you get a compiler error.
  
##  Arrays and Vectors
  
  
###  Arrays
  
  
**Arrays** are compound data types or data structures, that is, they are a collection of elements.
  
- All elements are of the _same_ type
- Each element can be accessed directly by their position or index
- Stored contiguously in memory
- Always initialize arrays
  
The name of the array represents the location of the first element in the array (index o).
  
The [`index`] represents the offset from the beginning of the array.
  
Declaration: `Element_Type array_name [constant number of elements in array];`
  
```cpp
int test_scores [5];
  
int high_score_per_level [10];
  
const int days_in_year {365};
double hi_temperatures [days_in_year];
```
  
**NOTE**: Best practice is to _always_ initialize arrays after declaring them.
  
Initialization: `Element_Type array_name [constant number of elements in array] {init list};`
  
```cpp
int test_scores [5] {100,9,5 99, 87,88};
  
int high_score_per_level [10] {3,5} // init first 2 elements to 3 and 5, the rest are set to 0.
  
const int days_in_year {365};
double hi_temperatures [days_in_year] {0}; // init all to zero.
  
int another_array [] {1,2,3,4,5}; // size automatically calculated.
```
  
###  Multi-dimensional arrays
  
  
Declaration: ` Element_Type array_name [dim1_size] [dim2_size];`
  
```cpp
const int rows {3};
const int columns {4};
int movie_rating [rows][columns];
```
  
Accessing array elements in multi-dimensional arrays
  
```cpp
cin >> movie_rating [1][2]; // set element at row 1, column 2
cout << movie_rating [1][2]; // display movie rating
```
  
Initializing multi-dimensional arrays
  
```cpp
int movie_ratings [3][4]
{
    { 0,4,3,5,},
    { 2,3,3,5 },
    { 1,4,4,5 }
};
```
  
###  Vectors
  
  
Vectors are compound structures (i.e. containers) for storing element collection of **unknown** size.
  
- Part of the C++ Standard Template Library
- An array that can grow and shrink in size at execution time.
- Provides similar semantics and syntax as arrasy
- Very efficient
- Can provide bounds checking
- Can use lots of cool functions like sort, reverse, find, and more.
  
Declaring vectors: `vector <data_type> vector_name (vector_size)`
  
```cpp
#include <vector>
using namespace std;
  
vector <char> vowels (5);
vector <int> test_scores (10);
```
  
Vectors are _12 bytes_ in size.
  
Initializing vectors:
  
```cpp
vector <data_type> vector_name {init_list}; // option 1
vector <data_type> vector_name (vector_size, init_value); // option 2
```
  
```cpp
vector <char> vowels {'a', 'e', 'i', 'o', 'u'};
vector <int> test_scores {100, 98, 89, 85, 93};
  
vector <double> hi_temperatures (365, 80.0); // vector of size 365 with elements initializaed to 80
```
  
####  Accessing vector elements
  
  
Method I - array syntax: `vector_name [element_index]`
  
```cpp
vector <int> test_scores {100, 95, 99, 87, 88};
  
cout << "First score at index 0: " << test_scores[0] << endl;
cout << "Second score at index 1: " << test_scores[1] << endl;
cout << "Third score at index 2: " << test_scores[2] << endl;
cout << "Fourth score at index 3: " << test_scores[3] << endl;
cout << "Fifth score at index 4: " << test_scores[4] << endl;
```
  
```txt
First score at index 0: 100
Second score at index 1: 95
Third score at index 2: 99
Fourth score at index 3: 87
Fifth score at index 4: 88
```
  
Method II - vector syntax: `vector_name.at(element_index)`
  
```cpp
vector <int> test_scores {100, 95, 99, 87, 88};
  
cout << "First score at index 0: " << test_scores.at(0) << endl;
cout << "Second score at index 1: " << test_scores.at(1) << endl;
cout << "Third score at index 2: " << test_scores.at(2) << endl;
cout << "Fourth score at index 3: " << test_scores.at(3) << endl;
cout << "Fifth score at index 4: " << test_scores.at(4) << endl;
```
  
####  Growing vectors
  
  
Vectors can increase in size by using the method `push_back()`.
  
```cpp
vector <int> test_scores { 100, 95, 99};    // size is 3
  
test_scores.push_back(80);  // 100, 95, 99, 80
test_scores.push_back(90);  // 100, 95, 99, 80, 90
```
  
Vectors _automatically_ allocate the require space!
  
What if you go out of bounds?
  
- Arrays never do bounds checking
- Many vector methods provide bounds checking
- If so, an exception and error message is generated.
  
```cpp
vector <int> test_scores {100, 95};
  
cin >> test_scores.at(5); // No index 5!
```
  
```text
Exception thrown at 0x76A5E4B2 in main.exe: Microsoft C++ exception: std::out_of_range at memory location 0x00EFFB44.
```
  
Example of a 2D-vector
  
```cpp
vector <vector<int>> movie_ratings
{
    {1,2,3,4},
    {1,2,4,4},
    {1,3,4,5}
};
  
// To retrieve the values from a 2D-vector, you need to use the at() method twice.
cout << "\nHere are the movie ratings for review # 1 using vector syntax: " << endl;
cout << movie_ratings.at(0).at(0) << endl;
cout << movie_ratings.at(0).at(1) << endl;
cout << movie_ratings.at(0).at(2) << endl;
cout << movie_ratings.at(0).at(3) << endl;
  
// To retrieve the values from a 2D-vector, you need to use the at() method twice.
cout << "\nHere are the first movie ratings from each reviewer: " << endl;
cout << movie_ratings.at(0).at(0) << endl;
cout << movie_ratings.at(1).at(0) << endl;
cout << movie_ratings.at(2).at(0) << endl;
return 0;
```
  
```txt
Here are the movie ratings for review # 1 using vector syntax:
1
2
3
4
  
Here are the first movie ratings from each reviewer:
1
1
1
```
  
##  Statements and Operators
  
  
###  Expressions
  
  
An expression is:
  
- the most basic building block of program
- "a sequence of operators and operands that specifies a computation"
- computes a value from a number of operands
  
Expression - example
  
```cpp
34                  // literal
favorite_number     // variable
1.5 + 2.8           // addition
2 * 5               // multiplication
a > b               //  relational
a = b               // assignment
```
  
###  Statements
  
  
A statement is:
  
- a complete line of code that performs some action
- Usually terminated with a semicolon
- Usually contains expressions
  
C++ has many different types of statements: expression, null, compound, selection, iteration, declaration, jump, try blocks, and others.
  
Statements - examples
  
```cpp
int x;                                    // declaration
favorite_number = 12;                     // assignment
1.5 + 2.8;                                // expression
x = 2 * 5;                                // assignment
if (a > b) cout << "a is greater than b"; // if
;                                         // null statement
```
  
###  Operators
  
  
####  Using operators
  
  
C++ has a rich set of operators
  
- _unary_: operates on only one operand (e.g. negator `!`)
- _binary_: operates on two operands (e.g. multiplier `*`)
- _ternary_: (e.g. increment `++`)
  
Common operators can be groupex as follows:
  
- _assignment_: modifies value of object
- _arithmetic_: perform mathematical operations on operands
- _increment/decrement_: work as assignment _and_ arithmetic operator
- _relational_: compares the values of two objects
- _logical_: test for boolean conditions
- _member access_: allows access to object properties (e.g. array subscript notation)
- _other_: do not fit any of the previous operators
  
> \* Assignment does **not** equal initialization, as it is done _after_ a variable is initialized.
  
####  Order of operations
  
  
**PEMDASS**
  
1. **P**arentheses
2. **E**xponents
3. **M**ultiplication
4. **D**vision
5. **A**ddtion
6. **S**ubtraction
  
#####  Arithmetic operators
  
  
| operator | description |
| :------- | :---------- |
  
- | addition
  
* |substraction
  
- | multiplication
  / | division
  % | moduluo or remainder (works only with integers)
  
+, -, \* and / are overloaded to work with multipole types such as int, double, etc.
  
Operators can also be combined with the assignment operator to create ternary operators
  
| ternary operator | operator components | meaning                           |
| :--------------- | :------------------ | :-------------------------------- |
| `+=`           | `+` and `=`     | `operand = operand1 + operand2` |
| `-=`           | `-` and `=`     | `operand = operand1 - operand2` |
| `*=`           | `*` and `=`     | `operand = operand1 * operand2` |
| `/=`           | `/` and `=`     | `operand = operand1 / operand2` |
| `-%`           | `%` and `=`     | `operand = operand1 % operand2` |
  
#####  Increment and Decrement
  
  
Increment or decrement its operand by 1; they can be used with integers, floating points types and points.
  
| operator | meaning                   |
| :------- | :------------------------ |
| `++`   | `operand = operand + 1` |
| `--`   | `operand = operand - 1` |
  
There are two notations
  
1. Prefix : `++num`
2. Postfix: `num++`
  
######  Example 1
  
  
```cpp
int counter {10};
int result {0};
  
// Prefix Example
cout << "Counter: " << counter << endl;
result = ++counter;  // counter is incremented before being assigned to result.
cout << "After incrementation" << endl;
cout << "Result: " << result << endl;
  
cout << endl;
  
// Postfix Example:
counter = 10;
result = 0;
  
cout << "Counter: " << counter << endl;
result = counter++; // counter is incremented after being assigned to result. Therefore result will be equal to 10.
cout << "Result: " << result << endl;
return 0;
```
  
```txt
Counter: 10
After incrementation
Result: 11
  
Counter: 10
After incrementation
Result: 10
```
  
######  Example 2
  
  
```cpp
    int counter {10};
    int result {0};
  
    // Prefix Example
    cout << "Counter: " << counter << endl;
    result = ++counter + 10;  // counter is incremented before been added with 10 and then assigned to result.
    cout << "After incrementation" << endl;
    cout << "Result: " << result << endl;
  
    cout << endl;
  
    // Postfix Example:
    counter = 10;
    result = 0;
  
    cout << "Counter: " << counter << endl;
    result = counter++ + 10; // counter is incremented after being added with 10 and then assigned to result.
    cout << "After incrementation" << endl;
    cout << "Result: " << result << endl;
    return 0;
```
  
```txt
Counter: 10
After incrementation
Result: 21
  
Counter: 10
After incrementation
Result: 20
```
  
> **NOTE**: Never use this operator twice for the same variable in the same statement.
> This behavior is undefined and its result cannot be predicted.
>
> Example: `cout << i++ << ++i;`
  
###  Mixed Type Expressions
  
  
C++ operations occur on the same type operands. If operands are of different types, then C++ will automatically convert types (**coercion**) into the same.
  
> **NOTE** as it could affect outcome of calculation; if C++ is unable to convert all the types then it could result in a compilation error.
  
Conversions occur between _higher_ and _lower_ types; these values are based on the size o fthe values the type can hold
  
- `long double` > `double` > `float` > `unsigned long` > `long`> `unsigned int`> `int`
- `short` and `char` types are always converted to int.
  
We can generally convert from a lower type to a higher type because the lower type's value can always fit into the higher type's value. However, this is not necessarily the case when converting from a higher type to a lower type.
  
Type Coercion: conversion of one operand to another data type. This can be done automatically by the compiler or manually by the programmer.
  
_Promotion_: conversion to a highe type; used in mathematical expressions.
_Demotion_: conversion to a lower type; used with assignment to lower type.
  
Examples
  
- `2 * 5.2` &rarr; the `lower` is promoted to a `higher`
- `int num {0}; num = 100.2` &rarr; the `higher` is promoted to a `lower`
  
**NOTE**: conversion can result in a loss of accuracy.
  
**Explicit Type Casting**: `static_cast<type>`
  
```cpp
int total_amount {100};
int total_number {8};
double average {0.0};
  
average = total_amount / total_number;
cout << average << endl;    // displays 12
  
average = static_cast<double>(total_amount) / total_number;
cout << average << endl;    // displays 12.5
```
  
> **NOTE**: the cast parentheses around the `total_amount` and _not_ the entire expression.
>
> Also, do **not** use the old C-language type cast `(type)`:
> `average = (double)total_amount / total_number;`
  
####  Equality Operators
  
  
Equality is determined via use of the `==` and `!=` operators, which compares the values of 2 expressions and evaluates to a Boolean (True or False, 1 or 0).
  
Commonly used in control flow statements.
  
```cpp
bool result {false}; // define a boolean variable
  
result = (100 == 50 + 50);  // returns true
  
result = (num1 != num2);    // could return true or false
  
cout << (num1 == num2) << endl; // prints 1 or 0
cout << std::boolalpha;         // modifies format of boolean
cout << (num1 == num2) << endl; // prints "true" or "false"
cout << std::noboolalpha;       // reverts formating back to default.
return 0;
```
  
**NOTE**: if you comparing variables with large values that are approximated (rounded) by the compiler on run time, you may get a false positive result.
  
 ```cpp
 bool equal_result {false};
 bool not_equal_result {false};
 double double1{}, double2{};
 cout << "Enter two double separted by a space: ";
 cin >> double1 >> double2;
 equal_result = double1 == double2;
 not_equal_result = double1 != double2;
 cout << "Comparison result (equals): " << equal_result << endl;
 cout << "Comparison result (not equals): " << not_equal_result << endl;
 return 0;
 ```
  
  
```txt
Enter two double separted by a space: 12.0 11.9999999999999999999999999999999
Comparison result (equals): 1
Comparison result (not equals): 0
```
  
####  Relational Operators
  
  
| Operator | Meaning                  |
| :------- | :----------------------- |
| `>`    | greater than             |
| `>=`   | greater than or equal to |
| `<`    | less than                |
| `>=`   | less than or equal to    |
  
####  Logical Operators
  
  
| Operator                                         | Meaning        
| :----------------------------------------------- | :------------- 
| <ul><li>`!`</li><li>`not`</li></ul> | negation       
| <ul><li>`&&`</li><li>`and`</li></ul> | logical *and* 
| <ul><li>`||`</li><li>`or`</li></ul> | logical *or* 
  
> **NOTE**: Extremely rare for people to use the logical word operands (`and`, `or`, or `not`).
  
#####  Logical Order of Operations
  
  
_Precedence_: `not` > `and` > `or`
  
- `not` is a unary operator
- `and` and `not` are binary operators
  
_Short-circuit-evaluation_: when evaluating a logical expression, C++ will stop as soon as the result is known.
  
```cpp
expr1 && expr2 && expr3 // no short-circuiting
expr1 || expr2 || expr3 // short-circuiting
```
  
#####  Compound assignment
  
  
| Operator | Example         | Meaning                 |
| :------- | :-------------- | :---------------------- |
| `+=`   | `lhs += rhs`  | `lhs = lhs + (rhs);`  |
| `-=`   | `lhs -= rhs`  | `lhs = lhs - (rhs);`  |
| `*=`   | `lhs *= rhs`  | `lhs = lhs * (rhs);`  |
| `/=`   | `lhs /= rhs`  | `lhs = lhs + (rhs);`  |
| `%=`   | `lhs %= rhs`  | `lhs = lhs % (rhs);`  |
| `>>=`  | `lhs >>= rhs` | `lhs = lhs >> (rhs);` |
| `<<=`  | `lhs <<= rhs` | `lhs = lhs << (rhs);` |
| `&=`   | `lhs &= rhs`  | `lhs = lhs && (rhs);` |
| `^=`   | `lhs ^= rhs`  | `lhs = lhs ^            |
| `        | =`              | `lhs                    |
  
#####  Operator Precedence
  
  
Higher to lower &darr;
  
| Operator                                                                                                                                       | Associativity     |
| :--------------------------------------------------------------------------------------------------------------------------------------------- | :---------------- |
| `[]`&nbsp;&nbsp;&nbsp;`->`&nbsp;&nbsp;&nbsp;`.`&nbsp;&nbsp;&nbsp;`()`                                                                  | `left to right` |
| `++`&nbsp;&nbsp;&nbsp;`--`&nbsp;&nbsp;&nbsp;`-(unary)`&nbsp;&nbsp;&nbsp;`*(de-ref)`&nbsp;&nbsp;&nbsp;`&`&nbsp;&nbsp;&nbsp;`sizeof` | `right to left` |
| `*`&nbsp;&nbsp;&nbsp;`/`&nbsp;&nbsp;&nbsp;`%`                                                                                            | `left to right` |
| `+`&nbsp;&nbsp;&nbsp;`-`                                                                                                                   | `left to right` |
| `<<`&nbsp;&nbsp;&nbsp;`>>`                                                                                                                 | `left to right` |
| `<`&nbsp;&nbsp;&nbsp;`<=`&nbsp;&nbsp;&nbsp;`>`&nbsp;&nbsp;&nbsp;`>=`                                                                   | `left to right` |
| `==`&nbsp;&nbsp;&nbsp;`!=`                                                                                                                 | `left to right` |
| `&`                                                                                                                                          | `left to right` |
| `^`                                                                                                                                          | `left to right` |
| `                                                                                                                                              | `                 |
| `&&`                                                                                                                                         | `left to right` |
| `                                                                                                                                              |                   |
| `=`&nbsp;&nbsp;&nbsp;`op=`&nbsp;&nbsp;&nbsp;`?:`                                                                                         | `right to left` |
  
- If a statement uses more than two _different_ operators, then use the **Operator** column in the precendence chart to determine which expression to execute first.
  
```cpp
expr1 op1 expr2 op2 expr3  // precendence
```
  
- If a statement uses more than one of the _same_ operator, then refer to their **associativity** in the precendence chart to determine which expression to execute first.
  - If the associativity of `op1` is **left to right** than apply it to `expr1` and `expr2` _first_.
  - If the associativity of `op1` is **right to left** than apply it to `expr2` and `expr3` _first_.
  
```cpp
expr1 op1 expr2 op2 expr3 // associativity
```
  
- Use parentheses to absolutely remove any doubt.
  
For example:
  
```cpp
    // Order of evaluation
    // By order of precedence
    result = num1 + num2 * num3 = num1 + (num2 * num3);
  
    // By associativity
    result = num1 + num2 - num3 = (num1 + num2) - num3;
```
  
##  Control Structures
  
  
Identical to C# except where noted.
  
###  Selection Decision Making
  
  
- `if` statement
- `if-else` statement
- Nested `if` statements
- `switch` statement
- Conditional operator `?:`
  
####  `if` statement
  
  
In C++, one can add a semicolon (`;`) after an if statement to tell the compiler to do nothing even if the statement is true;
  
In the following example, the console will print `"It's cold!"` because the `if` statement that preceeded it has a semicolon at the end of the statement;
  
```cpp
int temperature;
cout << "Enter a temperature: ";
cin >> temperature;
if (temperature < 50);
   cout << "It's cold!" << endl;
if (temperature > 50)
   cout << "It's hot!" << endl;
else
   cout << "Maybe it's raining?";
```
  
```txt
It's cold!
It's hot!
```
  
###  Iteration Looping
  
  
- `for` loop
- Ranged-based `for` loop
- `while` loop
- `do-while` loop
- `continue` and `break`
- Infinite `loops`
- Nested `loops`
  
####  C++ Looping Structures
  
  
- `for` loop
  - iterate a specific number of times
- `Range-based for` loop
  - one iteration for each element in range or collection
- `while` loop
  - iterate while a condition remains true
  - stop when the condition becomes false
  - check the conditiona t the beginning of every iteration
- `do-while` loop
  - iterate while a condition remains true
  - stop when the condition becomes false
  - check the condition at the end of every iteration
  
#####  `for` loop
  
  
Endless loop has no initialization, no test, and no increment.
  
```cpp
for (;;)
    cout << "Endless loop" << endl;
```
  
#####  Range-based `for` loop
  
  
- Introduced in C++11
  
```cpp
for (var_type var_name: sequence)
    statement;  // can use var_name
  
for(var_type var_name: sequence) {
    statements; // can use var_name
}
```
  
Example
  
```cpp
int scores [] {100, 90, 97};
for(int score: scores)
    cout << score << endl;
  
100
90
97
```
  
You can also use the keyword `auto` instead of explicitly specifying the variable type. C++ will _infer_ the type based on the declarations.
  
```cpp
for(auto score: scores)
    cout << score << endl;
```
  
Using a vector:
  
```cpp
vector <double> temps { 87.2, 77.1, 80.0, 72.5 };
  
double average_temp {};
double running_sum {};
  
for (auto temp: temps)
    running_sum += temp;
  
average_temp = running_sum / temps.size();
```
  
Using an initializer list:
  
```cpp
double average_temp {};
double running_sum {};
int size {0};
  
for (auto temp: { 60.2, 80.1, 90.0, 78.2 }) {
    running_sum += temp;
    ++size;
}
average_temp = running_sum / size;
```
  
#####  `while` loop
  
  
- Exampe of a **pretest loop** as the evaluation is done prior to entering the loop sequence.
  
#####  `continue` and `break` statements
  
  
- `continue`
  - no further statements in the body of the loop are executed
  - control immediately goes directly to the beginning of the loop for the next iteration.
- `break`
  - no further statements in the body of the loop are executed
  - loop is immediately terminated
  - Control immediately goes to the statement following the loop construct
  
```cpp
    vector<int> values { 1, 2, 01, 3, -1, 3, -1, -99, 7, 8, 10 };
    for (auto val: values) {
        if (val == -99)
            break;
        else if(val == -1)
            continue;
        else
            cout << val << endl;
    }
  
    1
    2
    3
```
  
The less ways you can come into and out of a loop, the _easier_ it is to debug it.
  
#####  Infinite Loops
  
  
Loops whose condition expression **always** evaluates to true; usually this is unintended and a programmer error
  
Sometimes programmers use infinite loops and include `break` statements in the body to control them
  
Sometimes infinite loops are _exactly_ what we need.
  
- Event loop in an event-driven program: the program might be continously listening to events such as mouse clicks.
- Operating system: continuously handling input and output.
  
Example:
  
```cpp
while (true) {
    char again {};
    cout << "Do you want to loop again? (Y/N): ";
    cin >> again;
  
    if(again == 'N' || again == 'n')
        break;
}
  
```
  
##  Strings and Characters
  
  
###  Character Functions
  
  
Character functions are located in the `<cctype>` namespace.
  
```cpp
#include <cctype>
  
function_name(char)
```
  
They include:
  
- Functions for testing characters
- Functions for converting character case
  
####  Testing characters
  
  
| Function       | Description                                          |
| :------------- | :--------------------------------------------------- |
| `isalpha(c)` | Returns `true` if `c` is a letter                |
| `isalnum(c)` | Returns `true` if `c` is a letter or digit       |
| `isdigit(c)` | Returns `true` if `c` is a digit                 |
| `islower(c)` | Returns `true` if `c` is a lowercase letter      |
| `isprint(c)` | Returns `true` if `c` is a printable character   |
| `ispunct(c)` | Returns `true` if `c` is a punctuation character |
| `issuper(c)` | Returns `true` if `c` is a uppercase letter      |
| `isspace(c)` | Returns `true` if `c` is whitespace              |
  
####  Converting characters
  
  
| Function       | Description                |
| :------------- | :------------------------- |
| `tolower(c)` | Returns lowercase of `c` |
| `toupper(c)` | Returns uppercase of `c` |
  
###  C-Style Strings
  
  
A **C-style string** is a sequence of characters, contigous in memory, that is implemented as an array of characters.
  
- Termined by a null chracter (`null`)
  - null - character with a value of zero (represented by `\0` in memory)
- Referred to as zero or null terminated string
  - This implies that the compiler will allocate _an extra space_ in memory for the null character
  
| F | r | a | n | k | \0 |
| :- | :- | :- | :- | :- | :- |
  
A **String literal** is a sequence of characters in double quotes, e.g. "Frank".
  
- They are a kind of constant variable that is terminated with the null character.
  
```cpp
   string line = "C++ is fun";
```
  
| C | + | + |  | i | s |  | f | u | n | \0 |
| :- | :- | :- | :- | :- | :- | :- | :- | :- | :- | :- |
  
- **NOTE**: You need to import both the `std` and `<string>` namespaces to use string literals.
  
#####  Declaring C-style strings
  
  
```cpp
char my_name[] {"Frank"};
```
  
- Due to the ending null character, you could call the element at index 5 in the above example without generating a compiler error.
  
```cpp
my_name[5] = 'y';   // Problem
```
  
- If, instead, we allocate 8 characters to the string, then there would not be a problem since only one of the null characters will be replaced
  
```cpp
char my_name[8] {"Frank"};
```
  
| F | r | a | n | k | ==\0== | ==\0== | ==\0== |
| :- | :- | :- | :- | :- | :----- | :----- | :----- |
  
```cpp
my_name[5] = 'y'; // OK
```
  
| F | r | a | n | k | y | ==\0== | ==\0== |
| :- | :- | :- | :- | :- | :- | :----- | :----- |
  
If you declare an _uninitialized_ string, then you will (probably) get an error if you try to access any of its elements as there is no knowing if the compiler will append a null character at the end of the string.
  
```cpp
char my_name[8];
```
  
| ? | ? | ? | ? | ? | ? | ? | ? |
| :- | :- | :- | :- | :- | :- | :- | :- |
  
We could, however, resolve this issue using the `strcpy` function to copy a string literal into our character array.
  
```cpp
my_name = "Frank";  // Error
strcpy(my_name, "Frank"); // OK
```
  
###  C-Style String Functions
  
  
Functions that work with C-style are found in the `<cstring>` namespace. They include functions for:
  
- Copying
- Concatenation
- Comparison
- Searching
- and others
  
**NOTE**: All of these functions rely on the sequence of characters terminating on a null character.
  
A few examples:
  
```cpp
char str[80];
  
strcpy(str, "Hello ");  // copy
strcat(str, "there" );  // concatenate --> "Hello there"
cout << strlen(str);    // 11
strcmp(strleng(str), "Another"); // > 0
```
  
**NOTE**: The function `strlng(str)` will **not** count the ending null character when calculating the length of the string. In fact, the functions returns a type called `size_t`, an unsigned integer or long (depending on your system).
  
Inr order to enter an entire string with spaces into `cout`, we need to use the `cin.getlin()` function and provide two arguments: a C-style string and an integer to limit the length the string.
  
```cpp
char full_name[50]{};
cout << "Enter your full name: ";
cin.getline(full_name, 50);
cout << "Your full name is " << full_name << endl;
```
  
```txt
Enter your full name: Connor Blaat
Your full name is Connor Blaat
```
  
When using the `strcmp()` function, a return value of `0` signifies that the two strings are equal; that is, they are made up of the exact same sequence of characters. Otherwise, the function will return either a `1` to indicate that the first string comes **lexically** before the second string, or `-1` if the inverse is true.
  
```cpp
char full_name[50]{};
char temp[50]{};
  
cout << "Enter your full name: ";
cin.getline(full_name, 50);
  
// copy full_name to temp
strcpy(temp, full_name);
  
// convert full_name to all caps
for(size_t i {0}; i < strlen(full_name); ++i){
      if(isalpha(full_name[i]))
          full_name[i] = toupper(full_name[i]);
}
  
// compare the results by mixing argument positions.
cout << "--------------------------" << endl;
cout << "Result of comparing " << temp << " and " << full_name << ": " << strcmp(temp, full_name) << endl;
cout << "Result of comparing " << full_name << " and " << temp << ": " << strcmp(full_name, temp) << endl;
```
  
```txt
--------------------------
Result of comparing Dani Rojas and DANI ROJAS: 1
Result of comparing DANI ROJAS and Dani Rojas: -1
```
  
General purpose functions include functions to convert C-style Strings to
  
- integer
- float
- long
- etc.
  
###  C++ Strings
  
  
`std::string` is a Class in the Standard Template Library.Therefore it must imported first by using:
  
```cpp
#include <string>
  
using namespace std;
```
  
C++ Strings:
  
- contigouos in memory
- dynamic size
- work with input and output streams
- lots of useful member functons
- _can be used with familiar operators (+, =, <, <=, >, >=, +=, ==, !=, [], ...)_
- can be easily converted to C-style Strings if needed
- generally safer
  
####  Declaring and Initializing C++ strings
  
  
```cpp
#include <string>
using namespace std;
  
string s1;                 // Empty --> C++ strings are always initialized, contrary to C-style strings
string s2 { "Frank"};      // Frank --> converted to C++ string
string s3 {s2};            // Frank --> copies value, stored in different memory location
string s4 {"Frank", 3};    // Fra --> Only use first 3 characters of Frank
string s5 {s3, 0, 2};      // Fr --> Only use characters from 0 indices up to 2.
string s6 (3, 'X');        // XXX ---> Initiales string to a specific number of a specific character.
```
  
There are other ways of declaring and initializing C++ strings using constructors and assignment operators.
  
####  Assignment of C++ strings
  
  
```cpp
string s1;
s1 = "C++ Rocks!";
  
string s2 {"Hello"};
s2 = s1;
```
  
####  Concatenation
  
  
```cpp
string part 1 { "C++"};
string part2 { "is a powerful"};
  
string sentence;
  
sentence = part1 + " " + part2 + " language";
// C++ is a powerful language
  
sentence = "C++" + " is powerful";
// ILLEGAL -- cannot concatenate C-style literals.
```
  
####  Accessing characters
  
  
C++ strings acts as vectors of characters and can therefore use the array notation `[]` or the `at()` method to access characters at different positions in the string.
  
```cpp
string s1 { "Mike" };
  
for(char c: s1)
  cout << c << endl;
```
  
```txt
M
i
k
e
```
  
**NOTE**: if you use `int` in the for-range loop, the compiler will instead print out the integer values that represent those characters.
  
```cpp
  string s1 { "Mike"};
  
  for(int c: s1)
      cout << c << endl;
  return 0;
  
77  // M
105 // i
107 // k
101 // e
```
  
####  Comparing C++ Strings
  
  
Using relational operators (`==`&emsp;`!=`&emsp;`>`&emsp;`=>`&emsp;`<`&emsp;`<=`) on C++ strings will compare both objects character by character **lexically**. This means that whichever character comes first in the **ASCII** table will have the lower value.
  
Relational operators can compare:
  
- two `std::string` bojects
- `std::string` object and a C-style string literal
- `std::string` object and C-style string variable
  
For example:
  
```cpp
string s1 {"Apple"};
string s2 {"Banana"};
string s3 {"Kiwi"};
string s4 {"apple"};
string s5 {s1};       // Apple
  
s1 == s5;    // True
s1 == s2;    // False
s1 != s2;    // True
s1 < s2;    // True
s2 > s1;    // True
s4 < s5;    // False
s1 == "Apple";    // True
```
  
####  Substrings - `substr()`
  
  
The method `substr()` extracts a substring from a `std::string`
  
&emsp;&emsp;&emsp;&emsp;`object.substr(start_index, length)`
For example:
  
```cpp
string s1 {"This is a test"};
  
cout << s1.substr(0,4);       // This
cout << s1.substr(5,2);       // is
cout << s1.substr(10,4);      // test
```
  
####  Searching C++ strings
  
  
The method `find()` returns the index of a substring in a `std::string`. Alternatively, it can also find the index of the first character if a character is entered as an argument.
  
&emsp;&emsp;&emsp;&emsp;`object.find(search_string)`
  
For example:
  
```cpp
string s1 {"This is a test"};
  
cout << s1.find("This");  // 0
cout << s1.find("is");    // 2
cout << s1.find("test");  // 10
cout << s1.find('e');     // 11
```
  
Another overloaded version of `find()` takes an integer as a second argument to specify at what index should the method start searching for a match.
  
```cpp
cout << s1.find("is", 4); // 5
```
  
If the method cannot find the substring, then the method will return a `string::npos`, which means no positional information available. You can check for this value in an if statement.
  
####  Removing characters
  
  
The `erase()` method removes a substring of characters from a `std::string`.
  
&emsp;&emsp;&emsp;&emsp;`object.erase(start_index, length)`
  
For example:
  
```cpp
string s1 {"This is a test"};
  
cout << s1.erase("0, 5");  // is a test
cout << s1.erase("5, 4");  // is a
```
  
The `clear()` method completely empties the string.
  
```cpp
s1.clear(); // empties string s1
```
  
**Finally**, C++ strings come with their own `length()` method as well.
  
####  Input with C++ strings
  
  
C++ uses the `getline()` method to store input data from an input stream object (e.g. `cin`) that includes white space characters.
There are two overloaded methods:
  
1. `getline(istream, string)`: extracts characters from an input stream (`istream`), and stores it in a string (`string`) until a newline character (`\n`) is found.
2. `getline(istream, string, char)`: extracts characters from an input stream (`istream`) and stores it in a string until the delimitation character (`char`) is found.
  
```cpp
string s1;
cin >> s1;              // Input = "Hello there"
                        // Only accepts up to the first space.
cout << s1 << endl;     // Output: "Hello"
  
getline(cin,s1);        // Read entire line unit \n
cout << s1 << endl;     // Output: "Hello there";
  
getline(cin, s1, 'x')   // Input = "this isx"
cout << s1 << endl;     // Output = "this is"
```
  
##  Functions
  
  
Identical to C# except where noted.
  
C++ programs involve pre-defined functions from 3 sources:
  
* C++ Standard Libraries
* Third-party libraries
* Your own functions and classes
  
###  Math Functions
  
The `<cmath>` library contains most (if not all) of the classic math functions for C++.
  
|Function |Description
|:---- |:----
| `sqrt(x)` | Calculates the square root of `x`
| `cbrt(x)` | Calculates the cube root of `x`
| `sin(x)` | Calculates the sine of `x`
| `cos(x)` | Calculates the cosine of `x`
| `ceil(x)` | Round *up* the value of `x` (to the ceiling)
| `floor(x)` | Rounds *down* the value of `x`(to the floor)
| `round(x)` | Rounds the value of `x`
| `pow(x, y)` | Calculates `x` to the power of `y`.
  
####  Random number generator
  
C++ uses the `rand()` function from the `<cstdlib>` namespace to generate random numbers.
```cpp
#include <cstdlib>
```
In order to use the random number generator, you must first seed it in order to obtain a distinct sequence of random numbers for each run.
```cpp
int random_number{};
size_t count {10};    // number of random numbers to generate
int min {1}           // lower bound (inclusive) of number sequence
srand(time(nullptr)) // Seed the random number generator
random_number = rand() % max + min;   // generate a random number in the range: [min, max]
```
  
###  Function prototypes
  
  
**Function Prototypes** tell the compiler what it needs to know without requiring a full function definition. They are also known as **forward declarations** or simply function declarations.
  
Function prototypes are placed at the *begining* of the program or they can be used in our own **header** (`.h`) **files**.
  
Example:
  
```cpp
// Prototypes
int function_name(int);
int fuction_name (int a); 
  
// Full definitions
int function_name(int a){
  statements(s);
  return 0;
}
```
  
Actual function definitions are placed **below** the main function.
  
###  Default Argument Values
  
  
When a function is called, all arguments must be supplied, but sometimes some of the arguments have the same values most of the time.
  
In such a case, we can tell the compiler to use **default values** if the arguments are not supplied. Default values can be in the prototype or definition, but not both. The best practice to store it in the prototype.
  
Default arguments must appear at the **tail end** of the parameter list. You can have multiple default values *but* these must *also* appear consecutively at the tail end of the parameter list.
  
Example:
  
```cpp
double calc_cost(double base_cost, double tax_rate = 0.06, double shipping = 3.50);
  
int main() {
  double cost {0};
  cost = calc_cost(200.0);            // will use default tax rate and default shipping
  cost = calc_cost(100.0, 0.08);      // will use provided tax rate of 0.08 and default shipping
  cost = calc_cost(100.0, 0.08, 4.25); // will use provided tax and provided shipping
  return 0;
}
  
  
double calc_cost(double base_cost, double tax_rate){
  return base_cost += (base_cost * tax_rate) + shipping;
}
```
  
###  Passing Arrays into Functions
  
To pass an array to a function, provide square brackets in the formal parameter description
```cpp
void print_array(int numbers []);
```
* Array elements are NOT copied.
* Instead, it is the **memory address** of the array that is passed as an argument.
* The function only knows the location of the *first element* in the array and *not* its actual size.
* Therefore, we need to pass the *size* of the array to the function in order that it knows how many iterations to perform.
  
Example:
```cpp
void print_array(int numbers[], size_t size);
  
int main() {
  int my_numbers[] {1, 2, 3, 4, ,5};
}
  
void print_array(int numbers[], size_t size){
  for (size_t i{0}; i < size; i++)e
    cout << numbers[i] << endl;
}
```
**NOTE**: Since we are passing in the location of the array in memory, we are actually modifying the values of that array, rather than creating a copy of that array.
  
If you do **not** want your function to modify the values of the array, use the `const` keyword in the function parameters to indicate that they are *read-only* values and thus **cannot** be modified.
```cpp
void clear_array(const int numbers [], size_t size){
  for (size_t i{0}; i < size; i++){
    numbers[i] = 0; // attempt to modify the array will result in compiler error.
  }  
}
```
  
###  Pass by Reference
  
To change the actual parameter from within the function body, we need to access its *location in memory* (i.e. the **adress** of the parameter).
  
Functions that take arrays as arguments can use the `const` keyword in front of the parameter of the function declaration and prototype.
  
However, for other variable types, we can pass a **reference** to the actual parameter so that the formal parameter will now be an *alias* for the actual parameter. To do so, add an ampersand (**`&`**) in front of the parameter you want to reference.
  
Example:
```cpp
void scale_number(int &num);
void swap (int &a, int &b);
  
int main() {  
  int number {1000};
  scale_number(number);
  cout << number << endl;
  
  int x{10}, y{20};
  cout << x << " " << y << endl;
  swap(x, y);
  cout << x << " " << y << endl;
  return 0;
}
  
void scale_number(int &num){
  if (num > 100)
    num = 100;
}
void swap(int &a, int &b){
  int temp = a;
  a = b;
  b = temp;
}
```
Passing a parameter by reference is an excellent way to speed up a program by eliminating steps that lead to storage and copy overhead.
  
The following example uses pass by reference to print out the values from the vector **without** creating a copy of the vector in memory. However, it is still required to use the `const` keyword in the method declaration to ensure that the values of the vector are not modified in any way. 
  
Example:
```cpp
void print(const std::vector<int> &v);
  
int main() {  
  std::vector<int> data {1, 2, 3, 4, 5};
  print(data);          // 1, 2, 3, 4, 5
  return 0;
}
  
void print(const std::vector<int> &v) {
  for (auto num: v)
    cout << num << endl;
}
```
  
###  Scope Rules
  
C++ uses **scope** to determine where an indentifier can be used. This includes the use of:
1. **static** or **lexical** scoping
2. **local** or **Block** scope
3. **Global** scope
  
####  1. Local or Block Scope
  
Identifiers that have been declared *inside* a code block are only visible *within* the block `{}` where they are declared.
  
These include *function parameters*, which are only visible inside the method body. Function local variables are only active while the function is executing. Therefore, they are NOT preserved between function calls.
  
With *nested* blocks, inner blocks can 'see' the identifiers in the outer block, but outer blocks cannot 'see' the identifiers in the inner block.
  
####  2. Static local variables**
  
**Static local variables** are declared with the `static` qualifier and have their value preserved between function calls.
```cpp
static int value {10};
```
They are *only* initialized the first time the function is called. If no initializer value is provided, they are set to zero by default.
  
####  3. Global Scope
  
Identifiers that are declared outside any function or class are said to have **global scope**; they are visible to *all parts* of the progrma after the gloval identifier has been declared.
  
**NOTE**: Global variables are OK when using a as global constants but the best practice is to *not* use global variables.
  
Example: 
```cpp
int num {100};    // Local to main
int num1 {500};   // Local to main
  
cout << "Local num is " << num << " in main" << endl;
{ // creates a new level of scope
  int num {200};  // local to this inner block
  cout << "Local num is " << num << " in inner block within main" << endl;
  cout << "Inner block in main can see out - num1 is: " << num1 << endl;
}
  
cout << "Local num remains: " << num << " in main." << endl;
```
```txt
Local num is 100 in main
Local num is 200 in inner block within main
Inner block in main can see out - num1 is: 500
Local num remains: 100 in main.
```
  
####  Function Calls
  
Functions use the **function call stack**; it uses the **LIFO** (**Last In, First Out**) method of push and pop to add and remove functions from a function stack:
* Functions must return control to function that called it.
* Each time a function is called we create a new **activation record** and push it on stack.
* When a function terminates we pop the activation record and return
* Local variables and function parameters are allocated on the stack.
  
**Memory Diagram**
![1680541170865](image/Notes/1680541170865.png )
  
Stack size is *finite*; therefore, if the program produces too large of a stack in memory, the compiler will return a **Stack Overflow** exception.
  
Example: 1 main function, 2 custom functions
```cpp
int func1(int a, int b) {
  int result {};
  result = a + b;
  func2(result, a, b);
  return result;
}
  
void func2(int &x, int y, int z){
  x += y + z;
}
  
int main() {  
  int x {10};
  int y {20};
  int z {};
  z = func1(x, y);
  cout << z << endl;  
  return 0;
}
```
  
Process in memory:
```txt
main:
  push space for the return value
  push space for the parameters
  push the return address
  transfer control to func1 (jmp)
func1:
  push the address of the previous activation record
  push any register values that will need to be restored before returning to the caller
  perform the code in func1
  restore the register values
  restore the previous activation record (move the stack pointer)
  store any funciton result
  transfere control to the return address (jmp)
main:
  pop the parameters
  pop the return value
```
  
####  Inline Functions
  
Since functions can have a certain amount of overhead that may lead to stack overflows, we can suggest the compiler to compile the *simpler* functions **inline**.
  
**Inline functions** are faster functions that avoid function call overhead, and generate inline assembly code. However, overuse of inline functions can cause the cause bloats in your source code.
  
Regardless, some compiler optimizations are so sophisticated that they will likely inline functions even without your suggestion.
  
Example:
```cpp
inline int add_numbers(int a , int b) { // definition
  return a + b;
}
  
int main() {
  in result {0};
  result = add_numbers(100, 200); // call
  return 0;
}
```
  
####  Recursive Functions
  
A **recursive function** is a funciton that calls itself either directly or indirectly through another function.
  
Recursive problem solving inolves establishing a base case to which your recursive function will fall back to, and dividing the rest of the problem into sub-problems and do recursive call.
  
Very popular in mathematical functions ( factorial, Fibonacci, fractals, ...) and searching and sorting (binary search, search trees, ...)
  
Example:
```cpp
unsigned long long factorial (unsigned long long n) {
  if (n == 0)
    return 1;                   // base case
  return n * factorial (n-1);   // recursive case
}
  
int main() {
  cout << factorial(8) << endl; //  40320
  return 0;
}
```
  
**Warning**:
* No base cases leads to infinite recursion (and thus stack overflow)
* Recursive can be resource intensive
* Only use recursive solutions when it makes sense
* ANthing that can be done recursively can be done iteratively
  
##  Pointers and References
  
  
###  Pointers
  
A **pointer** is a variable whose value is an *address* to either another variable or to a function.
  
Pointers have a name, an address in memory, and value, which in this case is an address. To use a pointer, you **need to know** what type of variable it is pointing to.
  
Why use pointers?
* Inside functions, pointers can be used to access data that are defined *outside* the functions. Those variables may not be in scope so you can't access them by their name.
* Pointers can operate on arrays *very efficiently*.
* We can allocate memory dynamically on the heap or free store; the memory does not even have a variable name.
* **Required** for Object-Oriented Programming in C++
*  Can acess *specific* addresses in memory, which can be useful in embedded and systems applications
  
####  Declaring Pointers
  
```cpp
variable_type *pointer_name;
```
* Pointers are read from *right to left* (&larr;):
* The asterisk (`*`) can be placed next to the pointer name or to the variable type (the former is preferred)
```cpp
int *int_pt;        // int_ptr points to an integer
double* double_ptr; // double_ptr points to a double 
char *char_ptr;     // char_ptr points to a character 
string *string_ptr; // string_ptr points to a string
```
* Initialize all pointer variables to **`nullprt`**
  
```cpp
variable_type *pointer_name {nullptr};
```
The `nullptr` keyword was first introduced in C++11. Alternatively, pointers can also be initialized to zero, meaning they are pointing *nowhere*.
```cpp
int *int_ptr {}:         // Compiler will generate garbage data that could point anywhere
double* double_ptr {0};       // Point nowhere
char *char_ptr {nullptr};     // Point nowhere
string *string_ptr {nullptr}; // Point nowhere
```
  
####  Accessing the Pointer Addresss
  
* To access the memory address of a variable, use the address operator: **`&`**
* All variables are stored in unique addresses via a unary operator
* The operand **cannot** be a constant or expression that evaluates to temporary values.
```cpp
int num {10};
  
cout << "Value of num is: " << num << endl;                 // 10
cout << "Size of num is: " << sizeof(num) << endl;          // 4
cout << "Address of num is: " << &num << " bytes" << endl;  // 0113FF0C
```
  
```txt
Value of num is: 10
Size of num is: 4
Address of num is: 0113FF0C
```
  
#####  Using `sizeof` pointer variable
  
* Do **not** confuse the *size of a pointer* with the *size of the value* it points to.
  
* **All pointers** in a program have the **same size** irregardless of the data type they point to.
  
####  Storing an Address in a Pointer Variable
  
The compiler will ensure that the address stored in pointer variable is of the correct type.
  
#####  Typed pointers:
  
```cpp
int score {10};
double high_temp{100.7};
  
int *score_ptr {nullptr};
score_ptr = &score; // OK
score_ptr = &high_temp; // Compiler Error: "a value of type "double *" cannot be assigned to an entity of type "int *"C/C++(513)"
```
  
#####  The `&` address operator
  
Pointers are variables: they can be changed, set to null, or be uninitialized.
```cpp
int *p;
cout << "\nValue of p is: " << p << endl;     // 000A11CC -> garbage value
cout << "Address of p is: " << &p << endl;    // 00AFFF04 -> address in memory
cout << "sizeof p is: " << sizeof p << endl;  // 4 -> size in bytes of p
  
p = nullptr;
cout << "\nValue of p is: " << p << endl; // 0
```
  
```txt
Value of p is: 000A11CC
Address of p is 00AFFF04
sizeof p is 4
Value of p is 0
```
**NOTE**: When requesting the value of of a pointer, the compiler will in fact return the address of the variable to which it is pointing.
```cpp
int score = 20;
p = &score;
cout << "Address of \"score\" is: " << &score << endl; // 00CFFAF4
cout << "Value of p: " << p << endl; // 00CFFAF```
```
  
####  Dereferencing a Pointer
  
**Dereferencing** is to access the data that the pointer is pointing to, as opposed to the address of that data in memory.
  
If your pointer has a valid address, then you can access the data at the address contained in the pointer by using the **derefencing operator**: **`*`**.
  
**Example**: primitive type
```cpp
int score {100};
int *score_ptr {&score};
  
cout << &score << endl;      // 00AFFC88 
cout << score_ptr << endl;   // 00AFFC88
  
cout << *score_ptr << endl;  // 100;
cout << score << endl;       // 100
  
*score_ptr = 200;   // pointer now points to a new variable of value 200
cout << *score_ptr << endl; // 200;
```
  
 **Example**: vector
 ```cpp
  vector<string> band { "Stevie", "Lindsey", "John"}; // init vector
  vector<string> *vector_string{nullptr}; // init vector pointer
  
  vector_string = &band;  // point vector to address of vector.
  
  cout << "First member: " << (*vector_string).at(0) << endl;
  cout << "Fleetwood Mac: ";
  for(auto member : *vector_string){
    cout << member << " ";
  }
  cout << endl << endl;
  return 0;
 ```
  
  
 ```txt
 First member: Stevie
 Fleetwood Mac: Stevie Lindsey John
 ```
  
###  Dynamic Memory Allocation
  
**Memory allocation** refers to the allocating storage from the heap at runtime.
  
![1680631172174](image/Notes/1680631172174.png )
  
Pointers are placed on the *stack* while the variables that they reference are allocated and placed on the *heap*.
* We often don't know how much storage we need until we need it
* Storage can be allocated for a variable at run time.
  
  
#####  Using `new` to allocate storage
  
```cpp
int *int_ptr {nullptr};
int_ptr = new int;        //  allocate an integer on the heap
  
cout << int_ptr << endl;  //  00D126C0 
cout << *int_ptr << endl; //  13708056 --> garbage data
  
*int_ptr = 100;
cout << *int_ptr << endl; //  100
return 0; 
```
  
* When dynamically allocating a variable to a pointer at runtime, the actual variable does **not** have a memory address in and of itself.
* Instead the **only** way to access it is via its pointer.
* If a pointer is reassigned a new variable without *first* deleting the preceeding variable it pointed to will result in a **memory leak**.
  
#####  Using `delete` to deallocate storage
  
```cpp
int *int_ptr {nullptr};
int_ptr = new int;        // allocate an integer on the heap
  
delete int_ptr;           // frees the allocated storage
```
  
#####  Using `new[]` to allocate storage for an array
  
```cpp
int *array_ptr {nullptr};
int size {};
  
cout << "How big do you want the array to be?";
cin >> size;
  
array_ptr = new int[size];  // allocate array on the heap
```
  
#####  using `delete[]` to deallocate storage for an array
  
```cpp
delete [] array_ptr;
```
  
**Warning**: too many memory leaks will cause the program to run out of memory and throw an instance of **`std:: bad_alloc'`**.
  
###  Relationship between Arrays and Pointers
  
* **Recall**: the value of an array name is the address of the *first element* in the array.
* The value of a pointer variable is an address
  
* If the pointer points to the same data type as the array element, then the pointer and array name can be used (almost) interchangeably.
  
```cpp
int scores [] { 100, 95, 89};
  
cout << scores << endl;     // 010FFB8C
cout << *scores << endl;    // 100 --> first element of the array
  
int *score_ptr {scores};
  
// The value of score_ptr is the same as scores
cout << score_ptr << endl;  // 010FFB8C
cout << *score_ptr << endl; // 100
```
If we can use an array name and a pointer name interchangeably, then we can use **array subscripting** on a pointer.
```cpp
int scores [] { 100, 95, 89};
  
int *score_ptr {scores};
  
cout << score_ptr[0] << endl;   // 100
cout << score_ptr[1] << endl;   // 95
cout << score_ptr[2] << endl;   // 89
```
In other words, C++ does **not** use true arrays as other languages, since the array name is just a **refence** to its starting element.
  
Consequently, this allows us to use pointers in expressions:
```cpp
int scores [] { 100, 95, 89};
  
int *score_ptr {scores};
  
cout << score_ptr << endl;         // 006FF724
cout << (score_ptr + 1) << endl;   // 006FF728
cout << (score_ptr + 2) << endl;   // 006FF72C
```
**Notice** that the address increments by 4; that is because the size of each integer in the array is equal to 4 bytes, so we are adding 4 to the previous address. 
  
The size of a data type is dependent on your machine and might be equal to some other value.
  
When we add 1 to the pointer name, we are in fact telling the compiler to move one element down to get the address of the next element in the array.
  
To get the actual values of the elements, simply use the *deference* (`*`) symbol.
```cpp
cout << *score_ptr << endl;         // 100
cout << *(score_ptr + 1) << endl;   // 95
cout << *(score_ptr + 2) << endl;   // 89
```
  
####  Subscript and Offset notation equivalence
  
```cpp
int array_name[] {1,2,3,4,5};
int *pointer_name {array_name};
```
  
| Subscript Notation | Offset Notation
| :---- | :----
| `array_name[index]` | `*(array_name + index)`
| `pointer_name[index]` | `*(pointer_name + index)`
  
###  Pointer Arithmetic
  
C++ allows for **pointer arithmetic** but it only makes sense with raw arrays. 
  
In order to use arithmetic expressions, you must ensure that the pointer and the variable are of the **same data type** or else you will get a compiler error.
  
* (`++`) increments a pointer to point to the next array element, irrespective of the element type.
  * `int_ptr++;`
  
* (`--`) decrements a pointer to point to the previous array element
  * `int_ptr--;`
  
* (`+`) increment pointer by `n * sizeof(type)`
  * `int_ptr += n;` or `int_ptr = int_ptr + n;`
  
* (`-`) decrement pointer by `n * sizeof(type)`
  * `int_ptr -= n;` or `int_ptr = int_ptr - n;`
  
Comparing two pointers using (`==`) and (`!=`) will indicate whether the two pointers are pointing to the same object in memory, i.e. their memory addresses. 
* It does **not** compare the *actual values* stored in those objects.
```cpp
  string s1 {"Samano"};
  string s2 {"Samano"};
  
  string *ptr1 { &s1};
  string *ptr2 { &s2};
  string *ptr3 { &s1};
  
  cout << (ptr1 == ptr2) << endl;   // false
  cout << (ptr3 == ptr1) << endl;   // true
```
  
To compare two data pointers, use the derefence (`*`) operand.
```cpp
  string s1 {"Samano"};
  string s2 {"Samano"};
  
  string *ptr1 { &s1};
  string *ptr2 { &s2};
  string *ptr3 { &s1};
  
  cout << (*ptr1 == *ptr2) << endl;   // true
  cout << (*ptr3 == *ptr1) << endl;   // true
```
  
##  OOP - Classes and Objects
  
Identical to C# except where noted.
  
**Encapsulation**: objects contain data AND operations that work on that data.
* implementation-specific logic can be hidden
* users of the class code to the interface since they don't need to know the implementation
* more abstraction
* easier to test, debug, maintain and extend
  
###  Classes vs Object
  
  
**Classes**: model of a real-world domain entities
**Object**: An instance of a class.
  
In C++, you can create objects *dynamically* on the heap using **pointers** to references class instances.
  
```cpp
  Account my_account
  Account connor_account;
  
  Account *maricela_account = new Account();
  delete maricela_account;
```
  
When declaring a class within another C++ file, you need to add a semicolon (`;`) at the end of the class.
```cpp
  class Player{ . . . };
```
  
In addition, there is the option of initializing the class attributes without using a constructor.
```cpp
class Player{
  // attributes
  string name {"Player"};
  int health {0};
  int xp {3};
  [ . . . ];
}
```
  
####  Accessing Class Members
  
If we have an object, use the **dot operator**:
  
```cpp
  Acount my_account;
  
  my_account.balance;
  my_account.deposit(1000.0);
```
If we have a pointer to an object (member of pointer operator): we need to **dereference** the pointer first, then use the dot operator.
```cpp
  (*my_account).balance;
  (*my_account).deposit(1000.0);
```
Or, use the member of pointer operator (**arrow operator**):
```cpp
  Account *my_account = new Account();
  
  my_account->balance;
  my_account->deposit(1000.0);
```
  
###  Access Modifiers
  
* `public`: accessible everywhere
* `private`: accessible only by members or friends of the class
* `protected`: accessible to members of derived classes
  
####  `public`
  
* Everything below the `public` keyword will be set to public.
  
####  `private`
  
* Everything below the `private` keyword will be set to private.
  
**Example**:
```cpp
  class Player {
  private:
      std::string name;
      int health;
      int xp;
  public:
      void talk(std::string text_to_say){ ... }
      bool is_dead();
  };
```
  
Trying to access a private member will result in the following compiler error:
```txt
member "[object_name]::[object_attribute]" (declared at line [X]) is inaccessible
```
  
####  Implementing Member Methods
  
**Member methods** are the C++ equivalent of *properties* in C#; they are methods with access to member attributes.
* Can be implemented *inside* the class declaration
  * Implicitly inline
* Can be implemented *outside* the class declaration
  * `Class_name::method_name`
* Can separate specification from implementation
  * `.h` file for the class declaration
  * `.cpp` file for the class implementation
  
**Example**: Inside implementation
```cpp
  class Account{
    ...
  public:
      //member methods
      void set_balance(double bal) {
          balance = bal;
      }
      double get_balance() { 
          return balance;
      }
    ...
  };
```
  
**Example**: Outside implementation
```cpp
  class Account{
  ...
  public:
      void set_balance(double bal);
      double get_balance();
    ...
  };
  
  void Account::set_balance(double bal) {
          balance = bal;
  }
  double Account::get_balance() { 
          return balance;
  }
```
  
#####  Example: Separate implementation
  
`Account.h` (header file): contains member method declarations
```cpp
  class Acount {
  private:
      double balance;
  public:
      void set_balance(double bal);
      double gsset_balance();
  };
```
> **Warning**: if we include this header file in more than one `.cpp` file, then the compiler will see the declaration for that class more than once and return an error stating that there are *duplicate declarations*.
>
> To get around this, we can use an **include guard** to ensure that the compiler will process this file only once regardless of the number of times it is included.
> 
> An **include guard** is a set of three preprocessor directives that ensures that the file in question is only included *once*.
>  * `#ifndef` (if not defined): looks to see if the preprocessor has a symbol with particular symbol name (e.g. `_ACCOUNT_H_`)
>  * If so, then the preprocessor skips to the `#endif` directive.
> * Else, the preprocessor goes to the `#define` directive to set the symbol. The compiler will then process the entire file.
> ```cpp
> #ifndef _ACCOUNT_H_
> #define _ACCOUNT_H_
>
>  class Account {
>    private:
>      double balancae;>
>    public:
>      void set_balance(double bal);
>      double get_balance();
> }
>
>  #endif
>```
>
> Finally, notice the naming convention for the preprocessor symbol name:  \_[SYMBOL NAME]\_H\_
> 
>Alternatively, some compilers can use the `#pragma once` preprocessor rather the above mentioned. However, you must check the documentation of the compiler to verify if this is possible.
> ```cpp
> #pragma once
>
>  class Account {
>    private:
>      double balancae;>
>    public:
>      void set_balance(double bal);
>      double get_balance();
> }
>```
>&nbsp;
  
  
  
`Account.cpp` (class file): contain member method declaration/implementation.
* For implementation to work, the class file must prepend an `#include` preprocessor directive followed by the name of the corresponding header file in double quotes (`""`)
* **Double quotes** are used to indicate header files that are **local** and are  **not** part of the C++ standard library.
```cpp
#include "Account.h"
  
void Account::set_balance(double bal) { balance = bal;}
  
double Account::get_balance(){ return balance; }
```
  
Back in our main file, we **only** have to include the header file to import the functions.
  
```cpp
int main() {
    Account luke_account;
    luke_account.set_balance(1000.0);
    double bal = luke_account.get_balance();
  
    std::cout << bal << std::endl;  // 1000
    return 0;
}
```
###  Constructors and Destructors
  
Identical to C# except where noted.
  
####  Destructors
  
**Destructors** are special member methods that are invoked automatically when an object is destroyed.
* Same name as the class proceeded with a tilde (~)
* No return type and no parameters
* Only **1** destructor is allowed per class, i.e. cannot be overloaded!
* Useful to release memory and other resources
```cpp
class Player {
  private:
    // attributes
  public:
    // methods
  
  //Destroyer
  ~Player();
}
```
When local objects go *out of scope*, their destructors are called automatically.
  
In the case of a global object, the object is constructed, used, and then deleted using :
```cpp
Player *enemy = new Player("Enemy", 1000, 0);
delete enemy; // deconstructor called.
```
  
If **no** constructors or destructors are provided by the programmer, then C++ will **automatically** create empty constructors and destructor.
  
####  Default constructor
  
Undefined constructors will result in the C++ compiler creating instances of objects with garbage member values.
  
We can override the default constructor by defining our own default constructor.
```cpp
class Account {
  . . .
public:
  Account(){
    name = "None";
    balance = 0.0;
  }
}
```
* However,  if we define a constructor with arguments, then C++ will **not generate** a default constructor and we will need to explicity define one.
* Else, the objects created with the default dconstructor will result in compilation errors.
```cpp
Account chris_account;                // Error
Account doris_account;                // Error
  
Account *mike_account = new Account;  // Error
Account bill_account {"Connor", 15000.0}; // OK
```
  
###  Default Initialization Lists
  
Rather than setting all data member values in the constructor body, we can instead use **construction initialization lists**:
* More efficient &rarr; variables are initialized before the compiler enters the constructor body.
* Immediately follows the parameter list
initializes the data members as the object is created
* Order of initialization is the **order of declaration** in the class, **not** that of the initialization list itself.
  
```cpp
// Initialization of a Player object
// Using overloaded constructor
Player::Player() {
  name = "None";
  health = 0;
  xp = 0;
}
Player::Player(std::string name_val) {
	name = name_val;
	health = 0;
	xp = 0;
}
Player::Player(std::string name_val, int health_val, int xp_val) {
	name = name_val;
	health = health_val;
	xp = xp_val;
}
  
// Using initialization list
Player::Player() : name {"None"}, health{0}, xp{0}{
}
Player::Player(std::string name_val): name {name_val}, health{0}, xp{0} {
}
Player::Player(std::string name_val, int health_val, int xp_val)
  : name{name_val}, health{health_val}, xp{xp_val} {
}
```
  
####  Delegating constructors
  
**Problem**:
* Code for constructors is very similar
* Duplicate code can lead to errors
  
C++ allows for *delegating constructors:*
* code for one constructor can call another in the initialization list
* avoids duplicating code.
  
**Process**:
* Create a constructor with the *most parameters* using an initialization list.
* Define subsequent constructors by calling the above constructor *with* the initializing data needed.
* The constructor that is called by other overloaded constructors is called the **delegating constructor**
  
Each constructor that is dependent on the delegating constructor will call the delegating constructor first before calling its own constructor.
```cpp
class Player{
private:
	std::string name;
	int health;
	int xp;
public:
  // ...
  // Delegating constructor
  Player(std::string name_val, int health_val, int xp_val)
    : name {name_val}, health {health_val}, xp {xp_val} {
  }
  Player()
    : Player { "None", 0, 0} {
  }
  Player(std::string name_val)
    : Player { name_val, 0, 0 }{
  }
};
```
  
####  Default Constructor Parameters
  
By assigning **default parameters** to one constructor, we can replicate the functionality of the delegating constructor with just *one constructor*.
```cpp
class Player{
private:
	std::string name;
	int health;
	int xp;
public:
  // Constructor with default parameter values
  Player(std::string name_val = "None", 
         int health_val = 0,
         int xp_val = 0){
  }
};
```
```cpp
// Implementing a single constructor
Player::Player(std::string name_val, int health_val, int xp_val)
    : name {name_val}, health {health_val}, xp {xp_val}{ 
}
  
Player empty;                         // None, 0, 0 
Player lucas {"Lucas"};               // Lucas, 0, 0
Player villain {"Villain", 100, 55};  // Villain, 100, 55
Player hero {"Hero", 100};            // Hero, 100, 0
```
####  Copy Constructor
  
When copying objects, C++ must create a new object from an existing object.
Copies of objects are made when:
* passing objects by value as a parameter
* returning an object from a function by value
* constructing one object based on another of the same class
  
If not provided, the C++ compiler will provide its own copy constructor. This applies to copying any object by value.
* Compiler copies the values of each data memberr ot the new object (*default memberwise copy)
* Perfectly fine in many cases.
  
**Warning**: If you have a pointer data member, then the pointer itself will be copied, *not the value it is pointing to*
  
Best Practices for copy constructors:
* Always provide a copy constructor when you class has raw pointer members
* Provide the copy constructor with a **const reference** parameter
* Use STL classes as they already provide copy constructors
* Avoid using raw point data members when possible.
  
**Declaring the Copy Constructor**
```cpp
Type::Type(const Type &source);
  
Player::Player(const Player &source);
  
Account::Account(const Account &source);
```
* The Parameter list contains a single object of the same type as the class it belongs to.
* The object is passed as a *reference* (`&`), to prevent the constructor from making copies of the pointer, and as a *constant* (`const`), to prevent modification of the source object.
  
**Implementing the Copy Constructor**
```cpp
Type::Type(const Type &source){
  // code or initialization list to copy the object
}
  
Player::Player(const Player &source)
    : name {source.name},
      health {source.health},
      xp {source.xp}{
}
  
Account::Account(const Account &source)
    : name {source.name},
    : balance {source.balance}{
}
```
  
###  Shallow vs Deep Copying
  
####  Shallow
  
  
When executing a memberwise copy, each data member is copied from the source object. However, this means that *any pointer member* will be copied as well, rather than the data it points to.
  
**Problem**: if either of the objects is destroyed, the other object will still point to the released storage area because because it continues to believe it is  still valid.
```cpp
class Shallow {
private:
    int *data;                      // POINTER
public:
    Shallow(int d);                 // constructor 
    Shallow(const Shallow &source); // copy constructor
    ~Shallow();                     // destructor
};
  
Shallow::Shallow(const Shallow &source)
	: data(source.data) {
		cout << "Copy constructor - shallow"
			 << endl;
}
  
Shallow::Shallow(int d) {
	data = new int;
	*data = d;
}
```
Shallow copy - only the pointer is copied - not what it is pointing to!
**Problem`source` and the newly created object BOTH point to the SAME `data` location!
  
**For example**:
shallow.h
```cpp
class Shallow {
private:
    int *data;
public:
    void set_data_value(int d);
    int get_data_value();
    Shallow(int d);
    Shallow(const Shallow &source);
    ~Shallow();
};
```
shallow.cpp
```cpp
void Shallow::set_data_value(int d) {
    *data = d;
}
int Shallow::get_data_value(){ 
    return *data;
}
Shallow::Shallow(int d){
    data = new int; // allocate storage
    *data = d;
}
Shallow::Shallow(const Shallow &source)
    : data {source.data} {
        std::cout << "Copy constructor - shallow" 
        << std::endl;
    }
  
Shallow::~Shallow(){
    delete data;
    std::cout << "Destructor freeing data" << std::endl;
}
```
main.cpp
```cpp
void display_shallow(Shallow s){
    std::cout << s.get_data_value() << std::endl;
}
  
int main() {
    Shallow obj1 {100};     // data points to location X with value 100
    display_shallow(obj1);  // 100
  
    Shallow obj2 { obj1};   // data points to location X with value 100
    obj2.set_data_value(1000)
    display_shallow(obj1);  // data points for both object point to location X BUT with value 1000 each.
    return 0;
}
```
  
###  Deep Copying
  
**Deep Copying** creates a **copy** of the *pointed-to data*; each copy will have a pointer to a *unique* storage location in the heap.
  
Use deep copying for when you have a *raw pointer* as a class data member.
  
**deep.h**
```cpp
class Deep {
private:
    int *data;
public:
    int get_data_value();
    void set_data_value(int);
    Deep(int d);
    Deep(const Deep &source);
    ~Deep();
};
```
  
**deep.cpp**
```cpp
#include <iostream>
#include "deep.h"
  
Deep::Deep(int d){
    data = new int;
    *data = d;
}
int Deep::get_data_value(){
    return *data;
}
void Deep::set_data_value(int d){
    *data = d;
}
// Choose one of the following two constructors.
// Deep constructor - longhand
Deep::Deep(const Deep &source){
    data = new int;
    *data = *source.data;  
    std::cout << "Copy constructor - deep"
        << std::endl;
}
  
// Deep constructor - shorthand
Deep::Deep(const Deep &source)
  : Deep{*source.data}{
    std::cout <<  "Copy constructor - deep" 
        << std::endl;
}
Deep::~Deep(){ 
    delete data;
    std::cout << "Destructor freeing data" << std::endl;
}
```
Deep copy - creates new storage *and* copies the values from original object.
  
**main.cpp**
```cpp
#include <iostream>
#include "deep.h"
  
void display_deep(Deep s)
{
    std::cout << s.get_data_value() << std::endl;
}
  
int main()
{
    Deep obj1{100}; // data points to location X with value 100
    display_deep(obj1); 
  
    Deep obj2{obj1}; // data points to location Y with value 100
    obj2.set_data_value(1000);
    display_deep(obj1); // obj1 pointer points to X with value 100
    // obj2  pointer points to Y with new value of 1000
    return 0;
}
```
  
###  Move Constructor
  
Sometimes when we execute code, the compiler creates unnamed temporary values
```cpp
int total {0};
total = 100 + 200;
```
* `100 + 200` is evaluated and `300` is stored in an unnamed temporary value
* `300` is then stored in the variable `total`
* then the temporary value is discarded
  
The same aplies to objects as well. When calling copy constructors over and over again, we can create a *lot* of overhead leading to a significant *performance bottleneck*
  
The **Move constructor** moves an object rather than copy it. It is optional but *recommended* when using raw pointers as data members. Some compilers may optimize copying away completely via *copy elision*
  
**Copy elision** is a compiler optimization technique that eliminates unnecessary copying via **RVO-Return Value Optimization**.
  
**r-value references** are references to r-values; that is, they reference temporary objects.
* Used by move constructor and move assignment operator to efficiently move an object rather than copy it.
* R-value reference operator: **&&**
  
> **NOTE**: An l-value reference is a reference that has an address to a variable with a name.
  
**Example**: r-value references
```cpp
int x {100}
int &l_ref = x;     // l-value reference -> single '&'
l_ref = 10;         // change x to 10
  
int &&r_ref = 200;  // r-value reference -> double '&&'
r_ref = 300;        // change r_ref to 300
  
int &&x_ref = x;    // compiler error: cannot assign r-value ref to l-value ref
```
  
**Example**: l-value reference parameters
```cpp
int x {100};         // x is an l-value
  
void func(int &num); // A
  
func(x);      // calls A - x is an l-value  
func(200);    // Error - 200 is an r-value
```
The above error is caused because the compiler cannot bind non-const l-value refrence of type 'int&' to an rvalue of type 'int'.
  
**Example**: r-value reference parameters
```cpp
int x {100};         // x is an l-value
  
void func(int &&num); // A
  
func(200);      // calls A - x is an r-value  
func(x);    // Error - 200 is an l-value
```
The above error is caused because the compiler cannot bind r-value reference of type 'int&&' to an l-value reference of type 'int'.
  
**Example**: l-value and r-value reference parameters
```cpp
int x {100};         // x is an l-value
  
void func(int &num); // A
void func(int &&Num); // B
  
func(x);      // calls A - x is an l-value  
func(200);    // calls B - 200 is an r-value
```
  
#####  Inefficient copying
  
**Example**: copy constructor
```cpp
Move::Move(const Move &source)
    : data{source.data} {}
```
  
```cpp
Vector<Move> vec;
  
vec.push_back(Move{10});
vec.push_back(Move{20});
```
  
The compiler uses the move constructor to make copies of Move{10} and Move{20}, thus creating temporary values for each and repeatedly using deep copying more than once.
```bash
Constructor for: 10
Constructor for: 10
Copy constructor - deep copy for: 10
Destructor freeing data for: 10
Constructor for: 20
Constructor for: 20
Copy constructor - deep copy for: 20
Constructor for: 10
Copy constructor - deep copy for: 10
Destructor freeing data for: 10
Destructor freeing data for: 20
```
  
Instead of making a deep copy of the move constructor, move copying actually 'moves' theresource by copying the address of the resource from source to the current object *and* nulls out the pointer in the source pointer.
  
Original object owns data in the heap while the copied object holds a pointer to the data of the original object.
  
**Syntax - r-value refrence**
```cpp
Type::Type(Type &&source);
Player::Player(Player &&source);
Move::Move(Move &&source);
```
**NOTE**:
* No `const` qualifier as the parameter source has to be modified to null out its source.
* Use of r-value reference via use of the `&&` sign.
  
**Example**: move constructor prototype
```cpp
  Move(Move &&source);        // Move Constructor
```
  
#####  Efficient copying
  
**Example**: move constructor declaration
```cpp
  Move::Move(Move &&source)
    :data{source.data} {
      source.data = nullptr;
    }
```
Here we are 'stealing' the data and then nulling out the source pointer.
  
---
#  Appendices
  
##  C++ Setup and Configuration
  
  
##  Makefiles
  
Makefiles are configuration files used to automate the build process of software programs. They are used to specify the dependencies between source code files, object files, and executable files, and to define the commands that should be executed to build the program.
  
They are written in a specific format that defines targets, dependencies, and commands to be executed when a target is Sbuilt.
* When a makefile is executed, the make utility reads the file and determines which targets need to be rebuilt based on their dependencies and modification times.
* It then executes the necessary commands to build the target, which may involve compiling source code files, linking **object files**, or running various scripts.
  
The simplest example would be:
```makefile
main: main.o
  g++ -o main main.o
```
* `g++`: C++ compiler used in example (GNU)
* `-o`
  
  
###  Object (`.o`) Files
  
In a Makefile, `.o` files are **object files** that are produced by compiling source code files.
  
When compilling a C++ file, the compiler generates an object file containing the compiled code; that is, machine code that can be linked with other object files and libraries to create an executable program.
  
Output files in a Makefile can speed up the build process by only recompiling the source code files that have changed since the last build. This is because the compiler only needs to recompile the changed source files into new `.o` files, rather than recompiling all of the source files in the project.
  
Here's an example Makefile rule that uses .o files:
```makefile
my_program: main.o my_functions.o
    g++ -o my_program main.o my_functions.o
  
main.o: main.cpp
    g++ -c -o main.o main.cpp
  
my_functions.o: my_functions.cpp
    g++ -c -o my_functions.o my_functions.cpp
```
  
 * `my_program` target depends on the `main.o` and `my_functions.o` files, which are produced by compiling the `main.cpp` and `my_functions.cpp` source code files, respectively. 
 * The `-c `flag with g++ tells the compiler to compile the source code into an object file without linking.
 * Only when the command to create `my_program` is envoked, will the compiler link the different output files together.
###  Header files
  
To use header files in a Makefile, you need to specify the dependencies between source files and header files. 
  
**For example**:
```makefile
my_program: main.cpp my_functions.cpp my_header.h
    g++ -o my_program main.cpp my_functions.cpp
```
* The `my_program` rule specifies the dependencies between the source files `main.cpp`, `my_functions.cpp`, and the header file `my_header.h`. 
* When any of these files change, make will rebuild the `my_program` target.
  
When compiling ***C++ source files*** that use header files in directories other than that of the main program, you need to include the header files using the `-I` flag with the directory path where the header files are located. 
  
**For example**:
```makefile
my_functions.o: my_functions.cpp my_header.h
    g++ -c -o my_functions.o my_functions.cpp -I/path/to/header/files
```
  
###  Makefile Variables
  
####  CXX and CXXFLAGS
  
Makefiles use variables as shorthands for shell commands and arguments that can be reused across serveral make commands. Among the most common variables are `CXX` and `CXXFLAGS`.
  
In a Makefile, **`CXX`** is a variable that specifies the C++ compiler to use when building C++ source files.
**`CXXFLAGS`** contains compile options to the C++ compiler, including debug options, optimization level, warning levels, or any other extra flags
  
For example, consider the following Makefile:
```makefile
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic
  
main: main.o
    $(CXX) $(CXXFLAGS) -o main main.o
  
main.o: main.cpp
    $(CXX) $(CXXFLAGS) -c main.cpp
  
clean:
    rm -f main main.o
```
In this example, the `CXX` variable is set to `g++,` which is the GNU C++ compiler. The `CXXFLAGS` variable is also set to a set of compiler options —`-Wall`, `-Wextra`, and `-pedantic`— that enable extra warnings and pedantic checks.
* `-Wall` enables a set of common warnings that can help detect potential issues in your code, such as warning about unused variables or uninitialized variables, which can lead to bugs or performance issues.
  
* `-Wextra` enables additional warnings that are not included in -Wall. These warnings are often related to coding conventions and can help with writing more readable and maintainable code.
  
* `-pedantic` makes the compiler strictly follow the C++ standard and issue warnings for non-standard code. It can help write code that is more portable and less likely to break on different compilers or platforms.
  
**NOTE**: It's generally a good practice to enable these options when compiling C++ code, as they can help catch potential issues and improve the quality of your code. 
  
>**Warning** it's important to note that these options can also produce a large number of warnings, especially for existing codebases.
  
####  CPPFLAGS
  
**`CPPFLAGS`** passes extra flags to the C++ *preprocessor* or any other programs that use the C++ preprocessor.
* The C++ preprocessor does not need to be explicity called as it will be called once the C++ compiler invokes it.
* THe most common case of **`CPPFLAGS`** to include the compiler search path using the **`-I`** option
  
```makefile
CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic
CPPFLAGS = -I /path/to/header_files
  
main: main.o
    $(CXX) $(CXXFLAGS) $(CPPFLAGS) -o main main.o
```
  
####  LDFLAGS
  
**`LDFLAGS`** pass extra flags to the GNU linker **`ld`**. Similar to **`CPPFLAGS`** except these flags are automatically passed to the linker when the compiler invokes it.
* The most common use is to specify directories where the libraries can be found by using the **`-L`** option.
* *However*, do not include the names of the libraries.
  
```makefile
LDFLAGS = -L. # Search for libraries in the current directory
          -L/usr/foo # Search for libraries in /usr/foo
  
main.o: main.c
  gcc $(LDFLAGS) -c main.c
```
  
####  LDLIBS
  
**`LDLIBS`** contains space-separated list of libraries that are by your programs.
* For this flag, the **`l`** option followed by the name of the library is used.
  
```makefile
LDFLAGS = -L. # Search for libraries in the current directory
          -L/usr/foo # Search for libraries in /usr/foo
  
LDLIBS = -lm lfoo # Use limb and libfoo
  
main.o: main.c
  gcc $(LDFLAGS) -c main.c $(LDLIBS)
```
**NOTE**: **`LDLIBS`** should be included *after* you have listed all your source files. Otherwise, the linker will not be able to link the symbols properly.
  
####  MAKEFLAGS
  
**`MAKEFLAGS`** are used in recursive invocations of **`make`** for projects that have modules or subsystems with their own `makefile`. 
* The top-level `makefile` will then recursively call `make` for each od the modules.
* The `MAKEFLAGS` variable is automatically set up by `make` and contains all the flags and command line variables that you passed to the top-level `make`.
  