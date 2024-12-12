#include <stdio.h>
#include <stdarg.h>



void print_number (int num) { 
  int newN =0;
    // Make sure to deal with negative numbers. 
    if (num < 0){ 
        putchar('-'); 
        num = -num;
    }
    // This will recusively cut down the number.
    // The advantage of using recursion here is that it will cut the number
    // to be the first digit.
    if (num !=0){
      print_number(num/10);
    }
    // This line will actually collect the first digit and print it.
    // Because it is recursive when returning from the first digit it will
    // print every digit in order and then return fully from the recursion with the full
    // digit printed in order. 
    newN = num % 10;
    putchar(newN + '0');
}


// simply put the character! 
void print_character(char c){ 
    putchar(c); 
}

void print_string(const char *str ){
   for (const char *p = str; *p !='\0'; p++){
     putchar(*p);
   }
}

void my_printf( char *str,...);

void print_hex(int num){
  int newN =0;

  

  
  while(num >0){
    newN = num % 16;
    num = num/ 16;
     switch(newN){
        case 10:
           my_printf("%c", 'A');
           break;
        case 11:
	   my_printf("%c", 'B');
	   break;
        case 12:
           my_printf("%c", 'C');
	   break;
        case 13:
           my_printf("%c", 'D');
           break;
        case 14:
           my_printf("%c", 'E');
           break;
        case 15:
       	   my_printf("%c", 'F');
	   break; 
        default:
	   my_printf("%d", newN);
      }
  }
}
void my_printf( char *str , ...){ 
    // initialize the va_list so that you can take in an unknown amount of arguments. 
    va_list args; 
    va_start(args, str); 
    // loop through the input string first argument
    // the '\0' makes sure to keep looping until a null is encountered
    
    for (const char *p = str; *p !='\0'; p++){
        // if no percent sign is encountered, put the character to stdout. 
        if (*p != '%'){
            putc(*p, stdout);
        }
        else 
            {
                // if a % is encountered, then increment p to the next character 
            p++; 
            switch (*p) {
                // if the character is a digit 

                case 'd':{
                    int value = va_arg(args, int); 
                    print_number(value); 
                    break;
                }
                // if the character is a character

                case 'c': {
                    int value = va_arg(args, int); 
                    print_character(value); 
                    break; 
                }
                // if the character is a hex digit 
                case 'x': {
                    int value = va_arg(args, int);
		    print_hex(value);
		    //   my_printf("found hex ");
		    break;
                }

                // if the character is a string. 
                case 's': {
                    char *value = va_arg(args, char*);
                    print_string(value);

                    break;
                }

            }
        }
    }
 }

int main(){
    my_printf("NO PERCENTS TEST\n");
    my_printf("-------------------------\n");
    my_printf("Long Digit Test: %d  (answer should be 123455)\n", 123455);
    my_printf("Short Digit Test: %d (answer should be 3)\n", 3);
    my_printf("Negative Digit Test: %d (answer should be -123)\n", -123);
    my_printf("--------------------------\n"); 
    my_printf("Character Test: %c \n",'h');
    my_printf("--------------------------\n");
    my_printf("String Test: %s \n", "You successfully printed this string yay!");
    my_printf("----------------------------\n");
    my_printf("Hex Test 1 (Answer should be A): %x\n", 10);
    my_printf("Hex Test 2 ( Answer should be 64):%x\n", 100);
    my_printf("Hex Test 3  (Answer should be 7E4): %x\n", 2020); 
}
