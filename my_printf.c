#include <stdio.h>
#include <stdarg.h>
#include "my_printf.h"

// turn an int into a char
char int_to_char( int n){
  return n + '0';
}
// prints a + 
void print_sign(int num){
  if (num >0){
    putchar('+');
  }

}                                                                                                                                              
void  print_long_value(long num) {
  if (num< 0){
    putchar('-');
    num = -num;
  }
  int newN =0;
                                                                                                                                 
    if (num !=0){
      print_long_value(num/10);
    }
                                                                                                                                             
    newN = num % 10; 
    if (num >0){
                                                                                                                                                
      putchar(int_to_char(newN));
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
      putchar(int_to_char(newN));
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

int  my_printf( char *str,...);
// this function prints a decimal number as a hexadecimal number, modeled after print_number

void print_UppHex(unsigned int num){
  int newN =0;
  //cutt the digit down to the first one. Instead of using 10, we are base 16. 

  if (num != 0){
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
	  putchar(int_to_char(newN));
      }
  }
}

                                                                                                                                                                                   

void print_LowHex( unsigned int num){
  
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
	  putchar(int_to_char(newN));
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
// only used for strings because strings won't do percision if it wants to add 0's
void only_width_left( int width, int len, int align, int zeroPadFlag){
  if (align == 1){
    int posWFlag = width - len;
      if ( width>0 && posWFlag >0 && zeroPadFlag ==0){
	print_spaces(posWFlag);
      }
    if( width >0 && posWFlag>0 && zeroPadFlag ==1){
      print_zeros(posWFlag); 
    }
  }
}
void  only_width_right(int width, int len, int align, int zeroPadFlag){
if (align == 0){
  int posWFlag = width - len;
      if ( width>0 && posWFlag >0 && zeroPadFlag ==0){
        print_spaces(posWFlag);
      }
    if( width >0 && posWFlag>0 && zeroPadFlag ==1){
      print_zeros(posWFlag);
    }
  }
 
}
void width_and_percision_left(int width, int percision, int len, int align, int zeroPadFlag, int flagPlus){
  
  if (align ==1){
    int posWFlag =  (width - len) - flagPlus;
    int posPFlag = (percision - len) - flagPlus;
    
    if (width>0 && posWFlag >0 && zeroPadFlag ==0){
      print_spaces(posWFlag);
    }
    if ( width> 0 && posWFlag >0 && zeroPadFlag ==1){
      print_zeros(posWFlag);
    }
    if(percision >0  && posPFlag >0){
      print_zeros(posPFlag);
    }
  }
}
void  width_and_percision_right(int width, int percision, int len, int align, int zeroPadFlag, int flagPlus){
  if (align == 0){
    int posWFlag = width - len - flagPlus;
    int posPFlag = percision - len - flagPlus;
    if (width >0 && posWFlag >0 && zeroPadFlag ==0){
      print_spaces(posWFlag);
    }
    if ( width >0 && posWFlag >0 && zeroPadFlag ==1){
      print_zeros(posWFlag);
    }
    if (percision >0 && posPFlag >0){
      print_zeros(posPFlag);
    }
     
  }
}
int  get_length_long(long longV){
   int count =0;
    while( longV >0){
      // keep chopping down the number                                                                                                                                
      longV = longV/10;
      count++;
    }
    return count;


}
void print_long( long longV, int width, int percision, int len_num, int align, int zeroPadFlag, int flagPlus){
  width_and_percision_right(width, percision, len_num, align, zeroPadFlag, flagPlus);

  print_long_value(longV);

  width_and_percision_left(width, percision, len_num, align, zeroPadFlag, flagPlus);
}

void print_edge_case_zero( int width, int percision, int len_num, int align, int zeroPadFlag, int flagPlus){

 
  width_and_percision_right(width, percision, len_num, align, zeroPadFlag, flagPlus);
  putchar('0');
  width_and_percision_left(width, percision, len_num, align, zeroPadFlag, flagPlus);
}
int  my_printf( char *str , ...){ 
    // initialize the va_list so that you can take in an unknown amount of arguments. 
    va_list args; 
    va_start(args, str); 
    
    // these flags are used to let
    // functions know in certain cases what characters have been processed already.
    // they are also used to save values( width or percision)
    int foundM =0;
    int flagPlus =0;
    int width =0;
    int count =0;
    int flagPercision = 0;
    int percision =0;
    int percentN =0;
    int align =0;
    int zeroPadFlag =0; 
    int longFlag =0;
    int forLoopFlag =0;
     
    for (char *p = str; *p !='\0'; p++)  {
        // if no percent sign is encountered, put the character to stdout.
      if (*p != '%' && foundM ==0){
            putc(*p, stdout);
	    count++; 
        }
      // if a percent sign is encountered, make sure that the %d, %c, %s... can identify that state.
      
      if (*p == '%'){
	foundM =1;
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
		 // if the digit is a long: 
		 if (longFlag ==1){
		   // get as type long
		   long longV = va_arg(args, long);
		   int len_num = get_length_long(longV);
		   // long will take care of width and percision itself. 
		   int amountW = width - len_num - flagPlus;
		   int amountP = percision - len_num - flagPlus; 
		   if (width >0){
		     count = count + width; 
		   }
		   else if (percision>0){

		     count = count + percision; 
		   }
		   else{
		     count = count + len_num; 
		   }
		   print_long(longV, width, percision,len_num, align, zeroPadFlag, flagPlus);  
		   
		   // reset flags and break
		   foundM =0;
		   longFlag =0;
		   align =0;
                   width =0;
                   percision =0;
                   zeroPadFlag =0;
		   flagPlus =0;
		   break;
		 }
		 // if it is not a long: get the argument as an int
		 int val = va_arg(args, int);
		 int len = get_length(val);
		 // deal with edge case of 0: 
		 if (val == 0){
		   print_edge_case_zero(width, percision, len, align, zeroPadFlag, flagPlus);
		   
		   // reset flags and break
		   foundM =0;
                   longFlag =0;
                   align =0;
                   width =0;
                   percision =0;
                   zeroPadFlag =0;
                   flagPlus =0;
		   break;
		 }
		 
                 int amountW = width - len - flagPlus;
                   int amountP = percision - len - flagPlus;
		  
		 if (amountW >0){
                     count = count + width;
                   }
                   else if (amountP >0){

                     count = count + percision;
                   }
                   else{
                     count = count + len + flagPlus;
                   }
		 
		 // deal with width and percision 
		 width_and_percision_right(width, percision, len, align, zeroPadFlag, flagPlus);
		 // print plus 
		 if (flagPlus ==1 ){
                    print_sign(val);
                    
                  }
		  
		  print_number(val);
		  width_and_percision_left(width, percision, len, align, zeroPadFlag, flagPlus);

		  // reset flags and break

		  foundM =0; 
		  align =0;
		  width =0;
		  percision =0;
		  zeroPadFlag =0;
		  flagPlus=0;
		  break;
		 
	        }
                                    
                // if the character is a character

                case 'c': {
		    int len_num = 1; 
                    int value = va_arg(args, int); 
		    // deal with width and percision
		    width_and_percision_right(width, percision, len_num, align, zeroPadFlag, flagPlus);
		    
		    print_character(value);
		    width_and_percision_left(width, percision, len_num, align, zeroPadFlag, flagPlus);

		    // reset flags and break
		    foundM =0;
		    width =0;
                    percision =0;
                    zeroPadFlag =0;
                    flagPlus =0;
		    
		    break; 
                }
                // if the character is a hex digit 
                case 'X': {
		   int value = va_arg(args,int);
		    int len_num = get_length_hex(value);

		   // acount for edgge case 0, and reset flags. 
		  if (value == 0){
		   int len_num = get_length_hex(value);
                   print_edge_case_zero(width, percision, len_num, align, zeroPadFlag, flagPlus);
		  
		   // reset flags and break                                                                                             
                   foundM =0;
                   longFlag =0;
                   align =0;
                   width =0;
                   percision =0;
                   zeroPadFlag =0;
                   flagPlus =0;
                   break;
                 }
		    
		    
		    // cast to an unsigned int to deal with negative hex values.
		    value = (unsigned int) value;
		    // deal with width and percision 
		    width_and_percision_right(width, percision, len_num, align, zeroPadFlag, flagPlus);
		    
		    print_UppHex(value);
		    width_and_percision_left(width, percision, len_num, align, zeroPadFlag, flagPlus);

		    // reset flags
		    foundM =0;
		    align =0;
		    width =0;
                    percision =0;
                    zeroPadFlag =0;
		    flagPlus =0; 
		    
		    break;
                }

                // if the character is a string. 
                case 's': {
		  // get a pointer to the string. 
                   char *value = va_arg(args, char*);
		   int len = get_length_str(value);
		   // only width is applicable to strings in printf 
		   only_width_right(width, len, align, zeroPadFlag);
		   //only print percision's length 
		   print_string(value, percision);
		   only_width_left(width, len, align, zeroPadFlag);

		   // reset flags 
		   foundM =0;
		   align =0;
		   width =0;
                   percision =0;
		   flagPlus =0; 
                   zeroPadFlag =0;
                   break;
		    
                }
	    case 'b':{
	      int binary = va_arg(args, int);
	      if (binary == 0){
		//print_edge_case_zero(width, percision, 8, align, zeroPadFlag, flagPlus);

                   foundM =0;
                   longFlag =0;
                   align =0;
                   width =0;
                   percision =0;
                   zeroPadFlag =0;
                   flagPlus =0;
                   break;
                 }

	      print_binary(binary);
	      foundM =0;
              longFlag =0;
              align =0;
              width =0;
              percision =0;
              zeroPadFlag =0;
              flagPlus =0;
	      
             
	      break;
	    }
	    case '*':{
	      // for a star, the next argument should be the intended width. get the width and store it. 
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
	       if (value == 0){
		  int len_num = get_length_hex(value);
                   print_edge_case_zero(width, percision, len_num, align, zeroPadFlag, flagPlus);

                   // reset flags and break                                                                                            
                                                                                                                                       
                   foundM =0;
                   longFlag =0;
                   align =0;
                   width =0;
                   percision =0;
                   zeroPadFlag =0;
                   flagPlus =0;
                   break;
                 } 
	       value = (unsigned int) value; 
	       
	       width_and_percision_right(width, percision, len_num, align, zeroPadFlag, flagPlus);
               print_LowHex(value);
	       width_and_percision_left(width, percision, len_num, align, zeroPadFlag, flagPlus);
               foundM =0;
	       align =0;
               width =0;
	       flagPlus =0;
               percision =0;
               zeroPadFlag =0;                                                                                    
               break;
	    }
	    case '-':{
	      align =1;
	      break;
	    }
	    case '0':{
	      if(width ==0 && percision ==0){
		zeroPadFlag =1; 
	      }
	      break;
	      case 'l':{
		longFlag =1;
		break;
	      }
	    }	    
	    
	    
           }
	    // if *p is a number, and there was a percent, and there was no percision encountered,then this must be width. 
	  if (*p >=48 && *p <=57 && foundM ==1 && flagPercision ==0){
	    // for the first number, simply get the int value and make that equal to width
	    if (width ==0){
		width = *p - 48;
	      }
	    // if this is not the first number, then newW is the new number
	    // multiply the old number by 10 and add the new number ( solves the problem of encountering each character one at a time
	    // and converting to an integer value) 
	      else{
		int newW = *p - 48;
		width = (width * 10) + newW;
	      
	      }
	    // do the same for percision as done for width! 
	  }else if( *p >= 48 && *p<=57 && foundM ==1){
	    if (percision==0){
                percision = *p - 48;
              }else{
                int newP = *p - 48;
                percision = (percision * 10) + newP;
              }
	  }
	  // this code is used if two percents are encountered.
	  // make a temp pointer to p 
	  char *temp = p;
	  
	  temp--;
	  // check the previous character to see if it was a percent, if so, pretend as if no percents were encountered
	  // and print a %. 
	  if (*temp == '%' && *p =='%'){
	      putchar('%');
	      foundM =0;
	    }
	  
      }
 }
    return count; 
}
