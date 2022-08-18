// examples of various loop constructs

#include <stdio.h>

int main(){
  // a fixed loop 
  int n;
  for (n=0; n<10; n++){
    printf("n, n^2: %4d %4d\n",n,n*n);
  }
  printf("\n");

  // Another fixed loop.  This time we declare the iterator "m" 
  // inside the for statement
  // also we count by 2 instead of by 1 each time through the loop
  for (int m=2; m<=20; m=m+2){
    printf("m, m^2: %4d %4d\n",m,m*m);
  }
  printf("\n");

  // nested loops
  const int NMAX=100;
  int nloops=0;
  for (int i=0; i<NMAX; i++){
    for (int j=i; j<NMAX; j++){
      nloops++;
    }
  }
  printf("Total entries in nested loop: %d\n",nloops);

  // do while loop always runs at least once
  int count=10;
  do {
    printf("Do-While count= %d\n",count);
  } while (count < 0);
  printf("\n");

  // while loop is not guaranteed to run at all
  count=0;
  while (count < 5 ){
    printf("While count= %d\n",count);
    count++;
  }
}
