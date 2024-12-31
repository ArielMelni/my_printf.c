#include <stdio.h>
#include <stdarg.h>
#include "my_printf.h"

int main(){
  my_printf("----------my_printf--------------\n"); 
  my_printf("Test Regular String No Percents\n");

  my_printf("----------printf--------------\n");
  printf("Test Regular String No Percents\n"); 

  my_printf("----------my_printf--------------\n");
  my_printf("Test Regular String: %s\n", "alskdjfowalidfhieuhfiwhoeihufiodsuhcinouiawuhfoiwheoi");
  my_printf("----------printf--------------\n");
  printf("Test Regular String: %s\n", "alskdjfowalidfhieuhfiwhoeihufiodsuhcinouiawuhfoiwheoi");

  char one = 'a';
  char two = 'z';
  char three = 'L';
  char four = 'M';
  my_printf("----------my_printf--------------\n");
  my_printf("Test Regular Character: %c\n", one );
  my_printf("Test Regular Character: %c\n", two);
  my_printf("Test Regular Character Capital: %c\n", three);
  my_printf("Test Regular Character Capital: %c\n", four);

  my_printf("----------printf--------------\n");

  printf("Test Regular Character: %c\n", one);
  printf("Test Regular Character: %c\n", two);
  printf("Test Regular Character Capital: %c\n", three);
  printf("Test Regular Character Capital: %c\n", four);
  
 my_printf("----------both comparison printing up numbers up to 100--------------\n");
  for(int i =0;  i<=100; i++){
    my_printf("my_printf:  %d ", i);
    printf("printf: %d\n", i); 
    
  }

  my_printf("-------------Negative numbers test--------------\n");
  int neg = -10;
    my_printf("my_printf: %d\n", neg);
    printf("printf: %d\n", neg); 
 my_printf("----------both comparison, lower case hex up to 100--------------\n");
 for(int x =0;  x <=1000; x++){
    my_printf("my_printf: %x ", x);
    printf("printf: %x\n", x);
  }
 my_printf("----------both comparison, upper case hex up to 100--------------\n");
 for(int x =0;  x <=1000; x++){
    my_printf("my_printf: %X ", x);
    printf("printf: %X\n", x);
  }
my_printf("\n----------width tests integer--------------\n");
// varying lengths but all less than the total width
 int num = 1000;
 int numTwo = 10000;
 my_printf("my_printf: \n");
 my_printf("%10d\n", num);

 my_printf("printf: \n"); 
 printf("%10d\n", num);
 
 my_printf("my_printf: \n");
 my_printf("%20d\n", numTwo);

 my_printf("printf:\n");
 printf("%20d\n", numTwo); 

 my_printf("\n----------width tests upper hex--------------\n");

 
 my_printf("my_printf: \n");
 my_printf("%10X\n", num);

 my_printf("printf: \n");
 printf("%10X\n", num);

 my_printf("my_printf: \n");
 my_printf("%20X\n", numTwo);

 my_printf("printf:\n");
 printf("%20X\n", numTwo);

 my_printf("\n----------width tests lower hex--------------\n");


 my_printf("my_printf: \n");
 my_printf("%10x\n", num);

 my_printf("printf: \n");
 printf("%10x\n", num);

 my_printf("my_printf: \n");
 my_printf("%20x\n", numTwo);

 my_printf("printf:\n");
 printf("%20x\n", numTwo);

  my_printf("----------width tests string and char--------------\n");

   my_printf("my_printf: \n");
   my_printf("%30s\n", "test width");

 my_printf("printf: \n");
 printf("%30s\n", "test width");
 char testC = 'a';
 my_printf("my_printf: \n");
 my_printf("%20c\n", testC);

 my_printf("printf:\n");
 printf("%20c\n", testC);
 my_printf("\n----------width tests left align --------------\n");
 my_printf("my_printf: \n");
 my_printf("%-10d|\n", num);

 my_printf("printf: \n");
 printf("%-10d|\n", num);

 my_printf("my_printf: \n");
   my_printf("%-30s|\n", "test width");

 my_printf("printf: \n");
 printf("%-30s|\n", "test width");

 my_printf("my_printf: \n");
 my_printf("%-20x|\n", numTwo);

 my_printf("printf:\n");
 printf("%-20x|\n", numTwo);

  my_printf("my_printf: \n");
 my_printf("%-20c|\n", testC);

 my_printf("printf:\n");
 printf("%-20c|\n", testC);
my_printf("----------percision tests--------------\n");
 my_printf("my_printf: \n");
 my_printf("%.10d\n", num);

 my_printf("printf: \n");
 printf("%.10d\n", num);

 my_printf("my_printf: \n");
   my_printf("%.30s\n", "test width");

 my_printf("printf: \n");
 printf("%.30s\n", "test width");

 my_printf("my_printf: \n");
 my_printf("%.20x\n", numTwo);

 my_printf("printf:\n");
 printf("%.20x\n", numTwo);
my_printf("---------- star test --------------\n");

 my_printf("my_printf:\n %*d\n", 20, 20);
 printf("printf:\n %*d\n", 20,20); 

 my_printf("my_printf:\n%.*d\n",10,10);
 printf("printf:\n%.*d\n", 10,10);

 my_printf("my_printf:\n %.*s\n",3, "Cut output");
 printf("printf:\n %.*s\n",3, "Cut output");

 my_printf("---------- two percent test--------------\n");

 my_printf("my_printf: %%d this test is meant to check if  %%s and you are able to print a %% sign\n");

 printf("printf: %%d this test is meant to check if  %%s and you are able to print a %% sign\n");

my_printf("----------percision tests less than--------------\n");
 my_printf("my_printf: \n");
 my_printf("%.1d\n", num);

 my_printf("printf: \n");
 printf("%.1d\n", num);

my_printf("my_printf: \n");
 my_printf("%.1x\n", num);

 my_printf("printf: \n");
 printf("%.1x\n", num);
 
 my_printf("my_printf: \n");
 my_printf("%.3s\n", "test width");

 my_printf("printf: \n");
 printf("%.3s\n", "test width");
my_printf("----------lots mixed together test--------------\n");

 my_printf("my_printf: \n");
 my_printf(" %10d %2d %.10d %.3s %d\n", 1,2,3,"hi my name is", 1);
 my_printf("printf: \n");
 printf(" %10d %2d %.10d %.3s %d", 1,2,3,"hi my name is", 1);
 my_printf("\n-----------width and plus sign test------------"); 
 my_printf("\nmy_printf: \n");
 my_printf("%+10d\n", 1);
 my_printf("printf: \n");
 printf("%+10d\n", 1); 
my_printf("\n----------Zero Pad test--------------\n");
 my_printf("my_printf:\n");
 my_printf("%05d\n", num);
 my_printf("printf:\n");
 printf("%05d\n", num);
my_printf("\n----------test negatives--------------\n");
 int negNum = -30;
 my_printf("my_printf:\n");
 my_printf("%d\n", negNum);
 my_printf("printf:\n");
 printf("%d\n", negNum);

 my_printf("my_printf:\n");
 my_printf("%x\n", negNum);
 my_printf("printf:\n");
 printf("%x\n", negNum);

 my_printf("my_printf:\n");
 my_printf("%X\n", negNum);
 my_printf("printf:\n");
 printf("%X\n", negNum);
my_printf("\n----------test long and short types--------------\n");
// the longest number that a long type will take. this would only pass if long is dealt with correctly. 
 long longNum = 2147483646;
 my_printf("my_printf:");
 my_printf("%ld\n", longNum);
 my_printf("printf:");
 printf("%ld\n", longNum);
 short shortNum = 2; 
 my_printf("my_printf: %hd\n", shortNum);
 printf("printf: %hd\n", shortNum);
 my_printf("--------------------return amount tests ----------------"); 
 my_printf("\nprintf:\n"); 
 int c = printf("hi my name is ariel %+10d\n", 1000);
 printf("%d\n", c); 
 my_printf("my_printf:\n");
 int my_return = my_printf("hi my name is ariel %+10d\n", 1000); 
 my_printf("%d\n", my_return);
 my_printf("printf:\n");
 int d = printf("Getting the percision and total chars %.20d\n", 10);
 printf("%d\n", d);
my_printf("my_printf:\n");
 int percisionOutput = my_printf("Getting the percision and total chars %.20d\n", 10);
 my_printf("%d\n", percisionOutput);

 int a = printf("all types to know for sure that the count is correct: %.3s, %.17d, %2x,%3X, %4c\n", "string test", 203,99,99,'a');
 
 int k = my_printf("all types to know for sure that the count is correct: %.3s, %.17d, %2x,%3X, %4c\n", "string test",\
 203,99,99,'a');

 my_printf(" my_printf: %d", k);
 printf(" printf: %d", a);
 
 my_printf("\n-----------------------more width and percision tests---------------\n"); 

 my_printf("\n my_printf:\n %2x %3X\n",99, 99);
 
 printf("\n printf:\n %2x %3X\n",99, 99);
 printf("all types to know for sure that the count is correct: %.3s, %.17d, %2x,%3X, %4c\n", "stri\
ng test", 203,99,99,'a');
 my_printf("all types to know for sure that the count is correct: %.3s, %.17d, %2x,%3X, %4c\n", "s\
tring test",\
 203,99,99,'a');
my_printf("\n-----------------------my creative addition, for loop tests---------------\n");
 int i; 
 for (i=0; i<10; i++){
   int value = 5 * i;
   my_printf("%f\n", i, value); 
  }
my_printf("\n-----------------------my creative addition, binary tests---------------\n");
 int q;
 for ( q =0; q<50; q++){
   my_printf("%b\n", q);
 }
 int g;
 my_printf("negatives\n");
 for (g=0; g>-50; g--){
   my_printf("%b\n", g);
 }

my_printf("\n-----------------------my creative addition, binary two's compliment---------------\n");
 int twoTest;
 for ( twoTest =0; twoTest<50; twoTest++){
   my_printf("%!\n", twoTest);
 }
 my_printf("\n ----------------------space modifier test---------\n");

int returnVal = my_printf("\n% d", 10);
int printsReturn =  printf("\n% d",10); 

 my_printf("\nmy %d, print %d", returnVal, printsReturn); 
}


