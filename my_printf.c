#include <stdio.h>
#include <stdarg.h>

// prints a + 
void print_sign(int num){
  if (num >0){
    putchar('+');
  }

}
// gets an int and prints the int as a string                                                                                                                                              
int print_long(long num) {
  if (num< 0){
    putchar('-');
    num = -num;
  }
  int newN =0;
  // because you need to print the first digit,                                                                                                                                            
  //chop the entire num down.                                                                                                                                                              
  //for this reason use recursion to print each character as returning from recursion occurs.                                                                                              
    if (num !=0){
      print_long(num/10);
    }
    // This line will actually collect the digit.                                                                                                                                          
    newN = num % 10;

    // this is necessary because the first time newN would equal 0 because num = 0                                                                                                         
    // This is also a result of the recursion that num will be fully chopped until it is 0,                                                                                                
    // the function still works because as it returns from the next iteration of recursion the first number                                                                                
    // will successfully be printed.                                                                                                                                                       

    if (num >0){
      // turn the number into a character by adding 48 which is the offset from a number to a character on the ascii                                                                       
      // chart. putchar will turn the decimal number into a character.                                                                                                                     
      putchar(newN + 48);
    }
}

// gets an int and prints the int as a string
int  print_number (int num) { 
  if (num< 0){
    putchar('-');
    num = -num;
  }
  int newN =0;
  // because you need to print the first digit,
  //chop the entire num down.
  //for this reason use recursion to print each character as returning from recursion occurs. 
    if (num !=0){
      print_number(num/10);
    }
    // This line will actually collect the digit. 
    newN = num % 10;
    
    // this is necessary because the first time newN would equal 0 because num = 0
    // This is also a result of the recursion that num will be fully chopped until it is 0,
    // the function still works because as it returns from the next iteration of recursion the first number
    // will successfully be printed.
    
    if (num >0){
      // turn the number into a character by adding 48 which is the offset from a number to a character on the ascii
      // chart. putchar will turn the decimal number into a character. 
      putchar(newN + 48);
    }
}

// prints binary number ( uses the same logic as print_number, but instead of base 10, base 2)
void print_binary(int num){
  
  int newN =0;
  // recursively cut num with base of 2
  if (num !=0){
    print_binary(num/2);
  }
  // get the remainder and effectively save each new binary number.
  
  newN = num % 2;
  // make sure that it is the second return from the recursion. num =0 after the first if statement.
  if (num >0){
    // if the remainder is a 0, print 0, if the remainder is 1, print 1
    switch(newN){
        case 0:
          putchar('0');
	  break;
       case 1:
          putchar('1');
	  break;
  }
  }
}
// prints binary number ( uses the same logic as print_number, but instead of base 10, base 2)                                                                                            
    // if the remainder is a 0, print 0, if the remainder is 1, print 1                                                                                               
// simply put the character! 
void print_character(char c){ 
    putchar(c); 
}

// this for loop is modeled after my_printf. pass in a string and it loops through that string
// printing each character.

void print_string(const char *s, int len ){
  int count =0; 
   for (const char *p = s; *p!='\0'; p++){
     putchar(*p);
     count++;
     if (count == len){
       break;
     }
   }
}

void my_printf( char *str,...);
// this function prints a decimal number as a hexadecimal number, modeled after print_number

void print_UppHex(int num){
  int newN =0;
  //cutt the digit down to the first one. Instead of using 10, we are base 16. 
  if (num !=0){
    print_UppHex(num/16); 
  }
  //get the last number by getting the remainder when moding by 16.
  newN = num % 16;
  // make sure it is the second return from recursion, in the first return num =0; 
  if (num >0){
    // if the remainder is greater than 9, then the corresponding alphabetical character should be printed
    // if the remainder is less than or equal to 9, just print the number. 
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
	   putchar(newN + 48);
      }
  }
}

void print_LowHex(int num){
  int newN =0;
  //cutt the digit down to the first one. Instead of using 10, we are base 16.                                                                                                                                                                                                                              
  if (num !=0){
    print_LowHex(num/16);
  }
  //get the last number by getting the remainder when moding by 16.                                                                                                                                                                                                                                         
  newN = num % 16;
  // make sure it is the second return from recursion, in the first return num =0;                                                                                                                                                                                                                          
  if (num >0){
    // if the remainder is greater than 9, then the corresponding alphabetical character should be printed                                                                                                                                                                                                  
    // if the remainder is less than or equal to 9, just print the number.                                                                                                                                                                                                                                  
    switch(newN){
        case 10:
           my_printf("%c", 'a');
           break;
        case 11:
           my_printf("%c", 'b');
           break;
        case 12:
           my_printf("%c", 'c');
           break;
        case 13:
           my_printf("%c", 'd');
           break;
        case 14:
           my_printf("%c", 'e');
           break;
        case 15:
           my_printf("%c", 'f');
           break;
        default:
           putchar(newN + 48);
      }
  }
}

// prints width amount of spaces.
void print_spaces(int width){
  for (int i =0; i<width; i++){
    putchar(' ');
  }
}
// prints percision amount of zeros. 
void print_zeros(int percision){
  for (int i =0; i< percision; i++){
    putchar('0');
  }
}
// gets and returns the length of the int
// This is not done recursively because the order of the int does not matter in this case
// much simpler to use a while loop!

int get_length (int num) {
  int count =0;

    while(num >0){
      // keep chopping down the number
      num = num/10;
      count++;
    }
    return count;
}
int get_length_hex(int hexN){
  int count =0;
  while(hexN > 0){
    hexN = hexN/16;
    count++; 
  }
  return count; 
}
int get_length_str(const char *s){
  
  int count =0;
  for (const char *p = s; *p !='\0'; p++){
    count ++;
   }

   return count; 
}
void  width_and_percision_left(int width, int percision, int len, int align){
  if (align ==1){
    int posWFlag = width - len;
    int posPFlag = percision - len;
    if (width >0 && posWFlag >0){
      print_spaces(posWFlag);
    }
    if (percision >0 && posPFlag >0){
      print_zeros(posPFlag);
    }
  }
}
void  width_and_percision_right(int width, int percision, int len, int align){
  if (align == 0){
    int posWFlag = width - len;
    int posPFlag = percision - len;
    if (width >0 && posWFlag >0){
      print_spaces(posWFlag);
    }
    if (percision >0 && posPFlag >0){
      print_zeros(posPFlag);
    }
  }
}
void my_printf( char *str , ...){ 
    // initialize the va_list so that you can take in an unknown amount of arguments. 
    va_list args; 
    va_start(args, str); 
    
    // these flags are used to let
    // functions know in certain cases what characters have been processed already.
    // they are also used to save values( width or percision)
    int foundM =0;
    int flagPlus =0;
    int width =0;
    int flagPercision = 0;
    int percision =0;
    int percentN =0;
    int align =0; 
    
    for (const char *p = str; *p !='\0'; p++)  {
        // if no percent sign is encountered, put the character to stdout.
      if (*p != '%' && foundM ==0){
            putc(*p, stdout);
        }
      // if a percent sign is encountered, make sure that the %d, %c, %s... can identify that state.
      
      if (*p == '%'){
	foundM =1;
	percentN++; 
      }
      // if a % is encountered. 
      if (foundM ==1){
	// this switch case lists all the posible cases that can happen after a % is encountered and acts effectively in each case. 
            switch (*p) {
                // if the character is a digit
	 
	       case '+':{
	          flagPlus =1;
	          break; 
	       }
	       
               case 'd':{
		 int val = va_arg(args, int);
		 int len_num = get_length(val);
		 width_and_percision_right(width, percision, len_num, align);
		 if (flagPlus ==1 ){
                    print_sign(val);
                    flagPlus =0;
                  }
		 
		   print_number(val);
		   width_and_percision_left(width, percision, len_num, align);
		   foundM =0; 
		   align =0;
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
                case 'X': {
                    int value = va_arg(args, int);
		    int len_num = get_length_hex(value);
		    width_and_percision_right(width, percision, len_num, align);
		    print_UppHex(value);
		    width_and_percision_left(width, percision, len_num, align);
		    foundM =0;
		    align =0; 
		    //my_printf("found hex ");
		    break;
                }

                // if the character is a string. 
                case 's': {
		 
                   char *value = va_arg(args, char*);
		   int len = get_length_str(value);
                   width_and_percision_right(width, percision, len, align);
		   print_string(value, percision);
		   width_and_percision_left(width, percision, len, align);
		   foundM =0;
		   align =0; 
                    break;
		    
                }
	    case 'b':{
	      int binary = va_arg(args, int);
	      print_binary(binary);
	      foundM =0;
	      align =0; 
	      break;
	    }
	    case '*':{
	      int widthNum =va_arg(args, int);
	      width = widthNum;
	      break;
	    }
	    case '.':{
	      flagPercision = 1;
	      break;
	    }
	    case 'x':{
	       int value = va_arg(args, int);
               int len_num = get_length_hex(value);
               width_and_percision_right(width, percision, len_num, align);
               print_LowHex(value);
	        width_and_percision_left(width, percision, len_num, align);
               foundM =0;
	       align =0;
                    //my_printf("found hex ");                                                                                                                                                                       
               break;
	    }
	    case '-':{

	      align =1; 
	    }
	    
           }
	  if (*p >=48 && *p <=57 && foundM ==1 && flagPercision ==0){
	      if (width ==0){
		width = *p - 48;
	      }else{
		int newW = *p - 48;
		width = (width * 10) + newW;
	      
	      }
    }else if( *p >= 48 && *p<=57 && foundM ==1 && flagPercision ==1){
	    if (percision==0){
                percision = *p - 48;
              }else{
                int newP = *p - 48;
                percision = (percision * 10) + newP;
              }
	  }
	  if(percentN > 1){
	    putchar('%');
	    percentN = 0;
	    foundM =0; 
	  }
      }
 }
}
int main(){
    my_printf("NO PERCENTS TEST\n");
    my_printf("-------------------------\n");
    my_printf("Long Digit Test: %d  (answer should be 123455)\n", 123455);
    my_printf("Short Digit Test: %d (answer should be 3)\n", 3);
    my_printf("Negative Digit Test: %d (answer should be -123)\n",-123);
    my_printf("--------------------------\n"); 
    my_printf("Character Test: %c \n",'h');
    my_printf("--------------------------\n");
    my_printf("String Test: %s \n", "You successfully printed this string yay!");
    my_printf("----------------------------\n");
    my_printf("Hex Test 1 (Answer should be A): %x\n", 10);
    my_printf("Hex Test 2 ( Answer should be 64):%x\n", 100);
    my_printf("Hex Test 3  (Answer should be 7E4): %x\n", 2020);
    my_printf("----------------------------\n");
    my_printf("Plus Modifier test Positive Number: %+d\n", 10);
    my_printf("Negative Modifier Test Negative Number: %+d\n", -10);
    my_printf("----------------------------\n");
    my_printf("Binary test (decimal number is 2): %b\n", 2);
    my_printf("Binary Test (decimal number is 302): %b\n", 302);
    my_printf("----------------------------\n");
    my_printf("%10d\n",1);
    my_printf("%*d\n", 10,1);
    my_printf("%.10d\n",1);
    my_printf("%10d\n",12345);
    my_printf("%*d\n", 10,12345);
    my_printf("%.10d\n",12345);
    my_printf("%2d\n",12345);
    my_printf("----------------------------\n");
    my_printf("%10s\n", "a");
    my_printf("%*s\n", 10,"a");
    my_printf("%.10s\n", "a");
    my_printf("Spaces, width: %10s\n","abcde");
    my_printf("%*s\n", 10,"abcde");
    my_printf("%.10s\n","abcde");
    my_printf("%.2s\n", "abcde");
    my_printf("%.10x\n", 16);
   
    my_printf("\\");
    my_printf("%%d\n");
     my_printf("----------------------------\n");
     my_printf("%-.10s", "hi");
}
