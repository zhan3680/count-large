#include <stdio.h>
#include <stdlib.h>
int populate_array(int,int*);
int check_sin(int*);
#include <stdbool.h>
int main(int argc, char **argv) {
    // TODO: Verify that command line arguments are valid.
    if(argc!=2){
      return 1;
    }
    // TODO: Parse arguments and then call the two helpers in sin_helpers.c
    // to verify the SIN given as a command line argument.
    int sin=strtol(argv[1],NULL,10);
    /*printf("%d\n",sin);
    bool b=sin>999999999;
    bool b2=sin<100000000;
    printf("%d\n",b2);
    printf("%d\n",b);*/
    if(sin<100000000 || sin>999999999){
      printf("Invalid SIN\n");
      return 0;
    }
    int sin_array[9];
    populate_array(sin, sin_array);
    if(check_sin(sin_array)==0){
      printf("Valid SIN\n");
    }else{
      printf("Invalid SIN\n");
    }
    return 0;
}
