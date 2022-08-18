// This program generates a small data file with the output 
// of several functions

#include<stdio.h>
#include<math.h>

float fcn1(float x);
float fcn2(float x);
float fcn3(float x, float y);

int main(){
  FILE *outfile;
  outfile = fopen("out.dat","w");
  fprintf(outfile,"# Demo data file\n");
  fprintf(outfile,"# All lines beginning w/ # are ignored by gnuplot\n");
  float start=1.0;
  for (int i=0; i<100; i++){
    float x=start + i/10.0;
    fprintf(outfile,"%10f %10f %10f %10f\n",x,fcn1(2*x),fcn2(x),
            fcn3(x,1.3)/20.0);
  }
  fclose(outfile);
  return 0;
}

// sin(x)/x
float fcn1(float x){
  return sin(x)/x;
}

// cos(x)/x
float fcn2(float x){
  return cos(x)/x;
}

// x^y
float fcn3(float x, float y){
  return pow(x,y)*cos(x);
}

