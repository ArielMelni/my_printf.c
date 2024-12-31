my_printf supports the types :

%d: integers
%s: strings
%c: characters
%x: hex values
%X: prints upper case hex 

my_printf also allows for the modifiers: 

left alignement (-), right alignment,  width, space, percision, plus sign, zero padding, star, long, short, and percent. 

left alignment: prints 0's or spaces after the value. 

right alignment: prints 0's or spaces before the value

width: the numbers that follow the % determines the total width printed ( including the length of the value and if plus or space modifiers are encountered). If the width is larger than the length of the value, nothing will change. The full value will still be printed. 

space: prints a space before the integer if it is greater than or equal to 0

percision: if a . is typed after a % sign and a number is typed, then percision is the total amount of characters displayed to output. for strings, percision will cut the string to be percision amount and for digits it will print 0's to fill the space to become percision amount. 

plus sign: if a + is encountered after a % then the digit will have a + before it if it is positive. 

zero padding: if a 0 is encountered after a % than zeros will be printed instead of spaces to become width amount. 

star: if a * is encountered, the next argument will be the amount of width or percision that my_printf should print.

long: supports integers of long type

short: supports integers of short type

percent: ignores the previous percent written, prints a percent, and continues printing as normal. 

There are also three creative additions to printf in my_printf:

1. %b: takes in an integer and prints it as a binary number. Negative numbers are printed as unsigned ints.
2. %!: converts an integer to its two's complement value and prints the two's complement number as an integer.
3. %f: when an f is encountered two arguments are necessary: integer i and integer value.

This is printed for %f:

"When i = %d, the int value is %d\n"

The advantage to %f is that often when debugging it is important to print out what is occuring at each iteration of the for loop. Using %f is easier than printing out the whole phrase!

This repository includes the files:

my_printf.c: my code for my_printf.c

my_printf.h: header file needed to run my tests

test_my_printf.c: my test file 

output.txt: the output when running my tests on my_printf.c

In order to run my tests these are the commands necessary:

gcc -o test_runner my_printf.c test_my_printf.c

./test_runner