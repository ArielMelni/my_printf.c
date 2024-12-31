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
// uses the same logic as print_number, takes a long as input                                     
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
  // deal with negatives
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
      // turn the int into a number character using int to char function 
      putchar(int_to_char(newN));
    }
}

// prints binary number ( uses the same logic as print_number, but instead of base 10, base 2)
// the use of the input being an unsigned int here takes care of negatives! 
int print_binary(unsigned int num){
  int newN =0;
  // recursively cut num with base of 2
  if (num !=0){
    print_binary(num/2);
  }
  // get the remainder and effectively save each new binary number.
  
  newN = num % 2;
  // make sure that it is the second return from the recursion. num =0 after the first if statement.
  if(num >0){
    switch(newN){

    case 0:
      putchar('0');
      break;
    case 1:
      putchar('1'); 
    }


  }
  return 0; 
}
                                                                                                                                                                                       
// simply put the character! 
void print_character(char c){ 
    putchar(c); 
}

// pass in a string and it loops through that string, outputing each character, ( only go up to len)
// the use of len as an input is for percision. 

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
// the use of unsigned int as an input takes care of negative numbers. 
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
	  // use int to char to make newN into a character.
	  putchar(int_to_char(newN));
      }
  }
}

                                                                                                                                                                                   
// same as UppHex just with lower case letters
void print_LowHex( unsigned int num){
  
  int newN =0;
                                                                                               
  if (num !=0){
    print_LowHex(num/16);
  }
                                                                                                          
  newN = num % 16;                                                                                                                  
  if (num >0){                                                                                                                         
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
// get the length of a hex number
int get_length_hex(int hexN){
  int count =0;
  while(hexN > 0){
    hexN = hexN/16;
    count++; 
  }
  return count; 
}
// get the length of the string
int get_length_str(const char *s){
  
  int count =0;
  for (const char *p = s; *p !='\0'; p++){
    count ++;
   }

   return count; 
}
// only used for strings and characters ( no percision)
void only_width_left( int width, int len, int align, int zeroPadFlag){
  // if left align is flagged true: print the appropriate amount of spaces
  if (align == 1){
    // make sure that the width does not make the final width too long ( account for the len) 
    // only print posWFlag amount of spaces/ or zeros for zeroPadding. 
    int posWFlag = width - len;
    
      if ( width>0 && posWFlag >0 && zeroPadFlag ==0){
	print_spaces(posWFlag);
      }
    if( width >0 && posWFlag>0 && zeroPadFlag ==1){
      print_zeros(posWFlag); 
    }
  }
}
// only used for strings and characters ( no precision) 
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
// deals with width, percision, zero padding, right and left alignment.
// left align prints spaces or zeros after the value 
void width_and_percision_left(int width, int percision, int len, int align, int zeroPadFlag, int flagPlus, int flagSpace){
  // only print if meant to be left aligned
  
  if (align ==1){
    // get the value of the amount of spaces or zeros that would actually need to be printed
    // make sure to account of the len and the additional + character and space character. 
    int posWFlag =  (width - len) - flagPlus - flagSpace;
    int posPFlag = (percision - len) - flagPlus - flagSpace;
    // depending on the scenerio, if width was flagged, zeroPadFlag was flagged, or percision was flagged. // do the corresponding action. 
    if(percision >0  && posPFlag >0){
      print_zeros(posPFlag);
    }
    else if(width>0 && posWFlag >0 && zeroPadFlag ==0){
      print_spaces(posWFlag);
    }else if ( width> 0 && posWFlag >0 && zeroPadFlag ==1){
      print_zeros(posWFlag);
    }
  }
}
// same as width_and_percision_left, but only works for right alignment.
// right alignment prints spaces or zeros before the value
void  width_and_percision_right(int width, int percision, int len, int align, int zeroPadFlag, int flagPlus, int  flagSpace){
  if (align == 0){
    int posWFlag = width - len - flagPlus - flagSpace;
    int posPFlag = percision - len - flagPlus - flagSpace;
    if (percision >0 && posPFlag >0){
      print_zeros(posPFlag);
    } else if (width >0 && posWFlag >0 && zeroPadFlag ==0){
      print_spaces(posWFlag);
    } else if ( width >0 && posWFlag >0 && zeroPadFlag ==1){
      print_zeros(posWFlag);
    }
     
  }
}

// gets the length of a long type digit.
int  get_length_long(long longV){
   int count =0;
    while( longV >0){
      // keep chopping down the number                                                                                                                                
      longV = longV/10;
      count++;
    }
    return count;


}
// my creative addition: not the number and add one for two's complement! (prints the base 10 value of the binary two's complement number) 
void twos_complement(int x){
  int y = ~x + 1;
  my_printf("%d\n", y); 
}
// deals with printing a long!
// made this function because my_printf's switch case became really long. 
void print_long( long longV, int width, int percision, int len_num, int align, int zeroPadFlag, int flagPlus, int flagSpace){
  width_and_percision_right(width, percision, len_num, align, zeroPadFlag, flagPlus,flagSpace);

  print_long_value(longV);

  width_and_percision_left(width, percision, len_num, align, zeroPadFlag, flagPlus, flagSpace);
}

// The functions that print hex, binary, or regular digits do not account for the 0 edge case.
// this function takes care of that! 
void print_edge_case_zero( int width, int percision, int len_num, int align, int zeroPadFlag, int flagPlus, int flagSpace){

 
  width_and_percision_right(width, percision, len_num, align, zeroPadFlag, flagPlus, flagSpace);
  if (flagSpace ==1){
    putchar(' '); 

  }
  putchar('0');
  width_and_percision_left(width, percision, len_num, align, zeroPadFlag, flagPlus, flagSpace);
}

// The final printf function!
// returns the number of characters successfully printed!

int  my_printf( char *str , ...){ 
    // initialize the va_list so that you can take in an unknown amount of arguments. 
    va_list args; 
    va_start(args, str); 
    
    // these flags are used to let functions know what characters have been processed already.
    // they are also used to save values( width or percision)
    int foundM =0;
    int flagPlus =0;
    int width =0;
    int count =0;
    int flagPercision = 0;
    int percision =0;
    int percentN =0;
    int shortFlag =0; 
    int align =0;
    int zeroPadFlag =0; 
    int longFlag =0;
    int forLoopFlag =0;
    int flagSpace =0;

    // loop through the first argument, input string 
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
	      // if a + modifier is encountered, flag it.  
	       case '+':{
	          flagPlus =1;
	          break; 
	       }
		 // if a digit is encountered...
               case 'd':{
		 
		 // if the digit is a long: 
		 if (longFlag ==1){
		   // get as type long and the length
		   long longV = va_arg(args, long);
		   int len_num = get_length_long(longV);

		   //this code gets the correct amount that count should be incremented
		   // makes sure to account for length of the number and a + character. 
		   int amountW = width - len_num - flagPlus - flagSpace;
		   int amountP = percision - len_num - flagPlus - flagSpace; 
		   if (amountW >0){
		     // if the width is greater than the total length of the long with +
		     // just increment count  width amount 
		     count = count + width; 
		   }
		   else if (amountP>0){
		     // if the percision is greater than the total length of long with +
		     // just increment count percision amount

		     count = count + percision; 
		   }
		   else{
		     // if width and percision are less than the number
		     // increment by the length including a plus sign and space
		     count = count + len_num + flagPlus + flagSpace; 
		   }
		   
		   print_long(longV, width, percision,len_num, align, zeroPadFlag, flagPlus, flagSpace);  
		   
		   // reset flags and break
		   foundM =0;
		   longFlag =0;
		   align =0;
                   width =0;
		   flagPercision =0;
                   percision =0;
                   zeroPadFlag =0;
		   shortFlag =0; 
		   flagPlus =0;
		   flagSpace =0;
		   break;
		 }
		 
		 // if it is not a long: get the argument as an int
		 int val = va_arg(args, int);
		 // if an 'h' was encountered than it is a short.
		 // nothing needs to change besides casting as a short because a short is less than
		 // an int, so there shouldn't be an issue. 
		 if ( shortFlag ==1){
		   val = (short)val; 
		 }
		 int len = get_length(val);
		 
		 // deal with edge case of 0: 
		 if (val == 0){
		   
		   print_edge_case_zero(width, percision, len, align, zeroPadFlag, flagPlus, flagSpace);
		   
		   // reset flags and break
		   foundM =0;
                   longFlag =0;
                   align =0;
		   flagPercision =0;
                   width =0;
		   shortFlag =0; 
                   percision =0;
                   zeroPadFlag =0;
                   flagPlus =0;
		   flagSpace =0; 
		   break;
		 }
		 // increment count the correct amount.
		 // make sure to account for the length of the digit, and the width/ percision.
		 
		 
                 int amountW = width - len - flagPlus - flagSpace;
                 int amountP = percision - len - flagPlus - flagSpace;
		  
		 if (amountW >0){
                     count = count + width;
                   }
                   else if (amountP >0){

                     count = count + percision;
                   }
                   else{
                     count = count + len + flagPlus + flagSpace;
                   }
	       
		 // deal with width and percision right aligned 
		 width_and_percision_right(width, percision, len, align, zeroPadFlag, flagPlus, flagSpace);

		 // print plus if need be 
		 if (flagPlus ==1 ){
                    print_sign(val);
                    
                  }
		 // print space if need be
		 if ( flagSpace ==1){
		   putchar(' '); 
		 }
		  print_number(val);

		  // deal with width and percision left aligned 
		  width_and_percision_left(width, percision, len, align, zeroPadFlag, flagPlus, flagSpace);

		  // reset flags and break

		  foundM =0; 
		  align =0;
		  width =0;
		  flagPercision =0;
		  percision =0;
		  zeroPadFlag =0;
		  flagPlus=0;
		  shortFlag = 0;
		  flagSpace =0; 
		  break;
		 
	        }
                                    
                // if the character is a character
                case 'c': {
		    int len = 1; 
                    int value = va_arg(args, int);
		    int amountW = width - len - flagPlus;

		    // make sure to increment count the correct amount based on if width is bigger than len
                   if (amountW >0){
                     count = count + width;
                   }else if(percision >0){
                     count = count + percision;
                   }

                   else{
                     count = count + len + flagPlus;
                   }
		   
		    // deal with width and percision
		    only_width_right(width, len, align, zeroPadFlag);
		    print_character(value);
		    only_width_left(width, len, align, zeroPadFlag);

		    // reset flags and break
		    foundM =0;
		    flagPercision =0;
		    width =0;
                    percision =0;
                    zeroPadFlag =0;
                    flagPlus =0;
		    shortFlag =0; 
      		    break; 
                }
                // if the character is a hex digit 
                case 'X': {

		  // unsigned int allows dealing with negative values
		   unsigned int value = va_arg(args,unsigned int);
		   int len_num = get_length_hex(value);
		    
		   // acount for edge case 0, and reset flags. 
		  if (value == 0){
		    
		   count = count+1; 
                   print_edge_case_zero(width, percision, len_num, align, zeroPadFlag, flagPlus, flagSpace);
		  
		   // reset flags and break                                                                                             
                   foundM =0;
                   longFlag =0;
                   align =0;
                   width =0;
		   flagPercision =0;
                   percision =0;
                   zeroPadFlag =0;
                   flagPlus =0;
		   shortFlag =0;
		   flagSpace =0; 
                   break;
                 }
		   
		  // increment count the correct amount depending on the respective lengths
		  // of width, percision and the value itself.
		   int amountW = width - len_num - flagPlus - flagSpace;
                   int amountP = percision - len_num - flagPlus - flagSpace;
                   if (amountW >0){
                     count = count + width;
                   }
                   else if (amountP>0){

                     count = count + percision;
                   }
                   else{
                     count = count + len_num + flagPlus + flagSpace;
                   }

		    
		    // deal with width and percision 
		   width_and_percision_right(width, percision, len_num, align, zeroPadFlag, flagPlus, flagSpace);
		    
		    print_UppHex(value);
		    width_and_percision_left(width, percision, len_num, align, zeroPadFlag, flagPlus, flagSpace);

		    // reset flags
		    foundM =0;
		    align =0;
		    flagPercision =0;
		    width =0;
                    percision =0;
                    zeroPadFlag =0;
		    flagPlus =0;
		    flagSpace =0; 
		    shortFlag =0; 
		    break;
                }

                // if the character is a string. 
                case 's': {
		  // get a pointer to the string. 
                   char *value = va_arg(args, char*);
		   int len = get_length_str(value);
		   
		   // only width is applicable to strings in printf 
		   // make sure to increment count the correct amount depending on
		   // how long the string is and if percision was encountered.
		   int amountW = width - len - flagPlus;
                   
                   if (amountW >0){
                     count = count + width;
                   }else if(percision >0){
		     count = count + percision; 
		   }
                   
                   else{
                     count = count + len + flagPlus;
                   }

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
		   flagPercision =0;
                   zeroPadFlag =0;
		   shortFlag =0; 
                   break;
		    
                }
		  // my creative addition, binary!
	    case 'b':{
	      // use unsigned ints for negative!
	      unsigned int binary = va_arg(args, unsigned int);
	      // deal with edge case 0
	      if (binary == 0){
		putchar('0');
		
		// reset flags and break
                   foundM =0;
                   longFlag =0;
                   align =0;
                   width =0;
                   percision =0;
                   zeroPadFlag =0;
                   flagPlus =0;
		   shortFlag =0;
                   break;
                 }

	      print_binary(binary);

	      // reset flags and break
	      foundM =0;
              longFlag =0;
              align =0;
              width =0;
	      flagPercision =0;
              percision =0;
              zeroPadFlag =0;
              flagPlus =0;
	      shortFlag =0; 
	      break;
	    }
	    case '*':{
	      // for a star, the next argument should be the intended width or percision  get the width or percision  and store it. 
	      if(flagPercision ==0){ 
		int widthNum =va_arg(args, int);
	         width = widthNum;
	      }
	      if (flagPercision ==1){
		int perc = va_arg(args, int);
		percision = perc; 
	      }
	      break;
	    }
	      // if a . is encountered, percision should be flagged 
	    case '.':{
	      
	      flagPercision = 1;
	      break;
	    }
	      // lower case hex
	    case 'x':{
	      
	       unsigned int value = va_arg(args, unsigned int);
	       int len_num = get_length_hex(value);
	       // deal with edge case value = 0
	       if (value == 0){
		  
		 print_edge_case_zero(width, percision, len_num, align, zeroPadFlag, flagPlus, flagSpace);

                   // reset flags and break                                                                                                                                                            
                   foundM =0;
                   longFlag =0;
                   align =0;
                   width =0;
                   percision =0;
		   flagPercision =0;
                   zeroPadFlag =0;
                   flagPlus =0;
		   shortFlag =0; 
                   break;
                 } 
	       
	       // increment count the correct amount, accounting for the length of the number and
	       // if a + was encountered. 
	       int amountW = width - len_num - flagPlus;
               int amountP = percision - len_num - flagPlus;
               if (amountW >0){
                     count = count + width;
                   }
               else if (amountP>0){

        	 count = count + percision;
                }
                else{
                     count = count + len_num + flagPlus;
                }
	       
	       width_and_percision_right(width, percision, len_num, align, zeroPadFlag, flagPlus, flagSpace);
               print_LowHex(value);
	       width_and_percision_left(width, percision, len_num, align, zeroPadFlag, flagPlus, flagSpace);
	       // reset flags and break
	       foundM =0;
	       align =0;
               width =0;
	       flagPlus =0;
               percision =0;
               zeroPadFlag =0;
	       flagPercision =0;
	       shortFlag = 0; 
               break;
	    }
	      // flag left align 
	    case '-':{
	      align =1;
	      break;
	    }
	      // flag zero Padding 
	    case '0':{
	      if(width ==0 && percision ==0){
		zeroPadFlag =1; 
	      }
	      break;
	      // flag long 
	    case 'l':{
		longFlag =1;
		break;
	      }
	      // execute my creative addition ( for loops)
	    case 'f':{
	      // get i as an int 
	      int i = va_arg(args, int);

	      // get value as an int 
	      int val = va_arg(args, int);

	      // this allows for easy formatting when inside a for loop!  
	      my_printf("When i = %d, the int value is %d\n", i,val); 
	      break;
	    }
	      // my creative addition ( two's complement)
	      case '!':{

		int x = va_arg(args, int);
		twos_complement(x);
		break;
	      }
		// flag short
	     case 'h':{
	       shortFlag = 1;
	       break; 
	     }
	       // flag space
	       case ' ':{
		 flagSpace = 1; 
	       }
	    }	    
	    
	    
           }
	    
	    // The goal of the next two if statments is to save width and percision to their variables.
	    // if *p is a number, and there was a percent, and there was no percision encountered,then this must be width.
	    // the statement *p >=48 && *p <= 57 checks to see if *p is a number character
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
	    // save the result to percision
	  }else if( *p >= 48 && *p<=57 && foundM ==1 && flagPercision ==1){
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
