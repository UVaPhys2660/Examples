// stdio.cpp
// g++ stdio -O -Wall -o stdio stdio.cpp
// example use of stdin, stdout
// The following program will function much like the cat command
// eg: stdio < some_file
// or
//     stdio some_file

#include <stdio.h>

int main(int argc, char *argv[]){ 

  FILE *inp;
  if (argc>1) inp=fopen(argv[1],"r");
  else inp=stdin;

  unsigned char c;

  while(1){
    c=fgetc(inp);          // read in 1 byte at a time
    if (feof(inp)) break;
    fputc(c,stdout);
  }
}
