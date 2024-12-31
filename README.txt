my_printf supports the types : 
%d integers, %s strings ,%c characters, %x hex values, %X prints upper case hex, %x prints lower case hex

my_printf also allows for the modifiers: 

left alignement (-) ,right alignment, width, space, percision, plus sign, zero padding, star , long, and short. 

left alignment: prints 0's or spaces after the value. 

right alignment: prints 0's or spaces before the value

width: the numbers that follow the % determines the total width printed ( including the length of the value and if plus or space modifiers are encountered). If the width is larger than the length of the value, nothing will change. The full value will still be printed. 

space: prints a space before the integer if it is greater than or equal to 0

percision: if a . is typed after a % sign and a number is typed, then percision is the total amount of characters displayed to output. for strings, percision will cut the string to be percision amount and for digits it will print 0's to fill the space to become percision amount. 

plus sign: if a + is encountered after a % then the digit will have a + before it if it is positive. 

zero padding: if a 0 is encountered after a % than zeros will be printed instead of spaces to become width amount. 

star: if a * is encountered, the next argument will be the amount of width or percision that my_printf should print. 

long: if an l is encountered after a % ( then a d) supports a long type integer 

short: if an 'h' is encountered after a % (then a d) supports a short type integer 

There are also three creative additions to printf in my_printf: 

1. binary numbers: if a %b is encountered than the integer value will be printed as a binary numbers (negative numbers are printed as unsigned binary numbers) 

2. twos complement: if a %! is encountered than the two's complement integer value of the inputted integer will be printed. 

3. for loop: if a %f is encountered than i would be the first argument and the digit value would be the second and a line like this would be printed: 

"When i = %d (the i value inputted) , the int value is %d (the value inputted) \n"

The advantage to %f is that if you want to debug and print to the screen the values of i as it goes through the for loop, it is very convienient to simply write %f, with i and value immediately after. 

my_printf returns the amount of successful characters that were printed. 

Included in this repository is: 

1. my_printf.c: the code 
2. my_printf.h: header file necessary to run my tests
3. test_my_printf.c: my tests file
4. my_printf_output_tests.txt: my output file after my tests were run

In order to run my tests, these commands should be run on the command line: 

gcc -o test_runner my_printf.c test_my_printf.c
./test_runner




