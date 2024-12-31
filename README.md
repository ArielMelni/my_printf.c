my_printf supports the types : %d,integers,  %s strings , %c characters, and %x hex values. 

%ld: supports a long type integer 

%hd: supports a short type integer 

%X: prints upper case hex 

my_printf also allows for the modifiers: 

left alignement (-) ,right alignment, width, space, percision, plus sign, zero padding, and star

left alignment: prints 0's or spaces after the value. 

right alignment: prints 0's or spaces before the value

width: the numbers that follow the % determines the total width printed ( including the length of the value and if plus or space modifiers are encountered). If the width is larger than the length of the value, nothing will change. The full value will still be printed. 

space: prints a space before the integer if it is greater than or equal to 0

percision: if a . is typed after a % sign and a number is typed, then percision is the total amount of characters displayed to output. for strings, percision will cut the string to be percision amount and for digits it will print 0's to fill the space to become percision amount. 

plus sign: if a + is encountered after a % then the digit will have a + before it if it is positive. 

zero padding: if a 0 is encountered after a % than zeros will be printed instead of spaces to become width amount. 

star: if a * is encountered, the next argument will be the amount of width or percision that my_printf should print.



