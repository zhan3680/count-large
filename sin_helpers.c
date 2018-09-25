#include<stdio.h>
int populate_array(int,int*);
int check_sin(int*);
// TODO: Implement populate_array
/*
 * Convert a 9 digit int to a 9 element int array.
 */
int populate_array(int sin, int *sin_array) {
    if(sin<100000000 || sin>999999999){
      return 1;
    }else{
      int i;
      int j;
      int temp;
      /*int q=sin/(10^(8-1));
      printf("quotient:%d\n",q);
      printf("reminder:%d\n",q%10);*/
      for(i=0;i<9;i++){
         temp=sin;
	 for(j=0;j<8-i;j++){
	    temp=temp/10;
	 }
         sin_array[i]=temp%10;
      }
    }
    return 0;
}

// TODO: Implement check_sin
/* 
 * Return 0 (true) iff the given sin_array is a valid SIN.
 */
int check_sin(int *sin_array) {
    int sum=0;
    int i;
    int temp;
    for(i=0;i<9;i++){
       if(i%2==0){
         sum+=sin_array[i];
       }else{
         temp=sin_array[i]*2;
	 if(temp>=10){
	   sum+=(temp/10);
	   sum+=(temp%10);
	 }else{
	   sum+=temp;
	 }  
       }
       /*printf("%d\n",sum);*/
    }
   /*printf("%d\n",sum);*/
   if(sum%10==0){
     return 0;
   }
    
   return 1;
}
