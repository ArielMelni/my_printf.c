#include <stdio.h>
#include <stdarg.h>

void print_sign(int num){
  if (num >0){

    putchar('+');
  }

}
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
    
    // this is necessary because the first time newN would equal 0 because num = 0
    if (num >0){
      // turn the number into a character and print it
      putchar(newN + '0');
    }
}


// simply put the character! 
void print_character(char c){ 
    putchar(c); 
}

void print_string(const char *s ){
   for (const char *p = s; *p !='\0'; p++){
     putchar(*p);
   }
}

void my_printf( char *str,...);

void print_hex(int num){
  int newN =0;
  // following the same logic as print_digit.

  //cutt the digit down to the first one. Instead of using 10, we are base 16. 
  if (num !=0){
    print_hex(num/16); 

  }
  //get the last number by getting the remainder when moding by 16.
  newN = num %16;
    
  if (num >0){
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
void print_spaces(int width){
  for (int i =0; i<= width; i++){
    putchar(' ');
  }
}

void my_printf( char *str , ...){ 
    // initialize the va_list so that you can take in an unknown amount of arguments. 
    va_list args; 
    va_start(args, str); 
    // loop through the input string first argument
    // the '\0' makes sure to keep looping until a null is encountered
    int foundM =0;
    int flagPlus =0;
    int width =0;
    for (const char *p = str; *p !='\0'; p++){
        // if no percent sign is encountered, put the character to stdout. 
     
      if (*p != '%' && foundM ==0){
            putc(*p, stdout);
        }
      if (*p == '%'){
	foundM =1;
      }
      
      if (foundM ==1){ 
            switch (*p) {
                // if the character is a digit
	    case '+':{
	      flagPlus =1;
	      break; 
	    }
                case 'd':{
		  if (width >0){
		    print_spaces(width);
		  }
                    int value = va_arg(args, int); 
		    if (flagPlus ==1 ){
		      print_sign(value);
		      print_number(value);
		      flagPlus =0;
		      foundM =0;
		      
		    
		    }else{
		      print_number(value);
		      foundM =0;
		    }
                    break;
                }
                // if the character is a character

                case 'c': {
                    int value = va_arg(args, int); 
                    print_character(value);
		    foundM =0;
                    break; 
                }
                // if the character is a hex digit 
                case 'x': {
                    int value = va_arg(args, int);
		    print_hex(value);
		    foundM =0;
		    //   my_printf("found hex ");
		    break;
                }

                // if the character is a string. 
                case 's': {
                    char *value = va_arg(args, char*);
                    print_string(value);
		    foundM =0;
                    break;
		    
                }
           }
	  if (*p >=48 && *p <=57 && foundM ==1){
	      if (width ==0){
		width = *p - '0';
	      }else{
		int newW = *p - '0';
		width = (width * 10) + newW;
	      
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
    my_printf("----------------------------\n");
    my_printf("%+d\n", 10);
    my_printf("%+d\n", -10);
    my_printf("%+10d", 66);
}
