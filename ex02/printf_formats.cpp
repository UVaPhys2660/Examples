// examples of format options

#include <stdio.h>

int main(){
  int ia=100;
  int ib=2000;
  int ic=300000;
  printf("Print integers at fixed column positions:\n");
  printf("012345678901234567890123456789\n\n");
  printf("%10d%10d%10d\n",ia,ib,ic);
  printf("now with added spaces:\n");
  printf("%10d %10d %10d\n",ia,ib,ic);
  printf("now left justified:\n");
  printf("%-10d%-10d%-10d\n",ia,ib,ic);
  printf("now with leading 0's:\n");
  printf("%09d %09d %09d\n",ia,ib,ic);
 
  double da=1e-15;
  double db=3.1415927;
  double dc=12345600000.9;
  printf("\n\nPrint doubles at fixed column positions:\n");
  printf("012345678901234567890123456789\n\n");
  printf("%9lf %9lf %9lf\n",da,db,dc);  // not so good looking
  printf("now limit decimal precision:\n");
  printf("%9.2lf %9.2lf %9.2lf\n",da,db,dc);
  printf("now try scientific notation:\n");
  printf("%9.2le %9.2le %9.2le\n",da,db,dc);
  printf("now try most compact notation:\n");
  printf("%9.2lg %9.2lg %9.2lg\n",da,db,dc);

  char sa[12]="Hello";  // here the text should be <= 11 characters
  char sb[12]="World";
  char sc[12]="!";
  printf("\n\nstrings with one space between each:\n");
  printf("%s %s %s\n",sa,sb,sc);
  printf("\n\nstrings at fixed column positions:\n");
  printf("%12s %12s %12s\n",sa,sb,sc);
  return 0;
}
