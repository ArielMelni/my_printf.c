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
3. for loop: if a %f is encountered than 

