// This example shows methods of making and using various
// types of functions in your code
// All examples here use double types, but input parameters and
// the return value can be of any variable type

#include <stdio.h>

// it's often MUCH better style to use constants than #define commands!
const double PI=3.14159;

// function prototypes
double volumeOfSphere(double radius);
double volumeOfCylinder(double radius, double height);
double volumeOfBox(double length, double width, double height);

int main(){
  printf( "Volume of unit sphere = %lf\n",volumeOfSphere(1.0) );
  printf( "Volume of unit cylinder = %lf\n",volumeOfCylinder(1.0,1.0) );
  printf( "Volume of unit box = %lf\n",volumeOfBox(1.0,1.0,1.0) );
  return 0;
}


double volumeOfSphere(double radius){
  return 4.0/3.0*PI*radius*radius*radius;
}

double volumeOfCylinder(double radius, double height){
  return PI*radius*radius*height;
}

double volumeOfBox(double length, double width, double height){
  return length*width*height;
}
