// Solution to Brooks Chapter 7, Problem 5
//
#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct{
  char name[21];
  char symbol[3];
  float density;
} MDATA;

// convert a string to lower case 
//   Note: this is a little dangerous - if a string does not contain 
//   a NULL terminator, the for loop may overwrite our other data!
void lower_case(char* str){
  unsigned int i;
  for (i=0; i<strlen(str); i++) str[i] = (char)tolower(str[i]);
  return;
}

// read in a data file, return # of entries read
int readData(const char* file, MDATA *metals);

const int MAX_ENTRIES=50;  // maximum number of elements to process

int main(){
  MDATA metals[MAX_ENTRIES];  // array of MAX_ENTRIES structures
  char lookup[21];

  // read data from file
  int nelements=readData("metals.dat",metals);

  // user interaction loop
  while(1){
    printf("Which metal do you want me to lookup? [enter q to quit]\n");
    scanf("%s",lookup);
    lower_case(lookup);
    if (lookup[0]=='q') break;
    printf("data corresponding to \"%s\":\n",lookup);
    bool found=false;
    for (int i=0; i<nelements ; i++){
      if (!strncmp(metals[i].name,lookup,strlen(lookup))) {
	printf("%20s %3s %5.2f[gm/cm^3]\n\n",
	       metals[i].name,metals[i].symbol,metals[i].density);
        found=true;
      }      
    }
    if (!found) printf("Sorry, data for \"%s\" not found\n\n",lookup);
  }
  return 0;
}

int readData(const char* fileName, MDATA *metals){
  FILE *data_f=fopen(fileName,"r");
  if ( data_f==NULL ){
    printf("Error: file not found!\n");
    return -1;
  }
  int status;
  int count=0;
  while(count<MAX_ENTRIES) {
    status=fscanf(data_f,"%s %s %f",metals[count].name, 
		  metals[count].symbol, &(metals[count].density));
    if (status==EOF || status!= 3) break;
    count++;
  }
  fclose(data_f);
  printf("%d metals read from file\n",count);  
  return count;
}

