#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// TODO: Implement a helper named check_permissions that matches the prototype below.
int check_permissions(char *, char *);


int main(int argc, char** argv) {
    if (!(argc == 2 || argc == 3)) {
        fprintf(stderr, "USAGE: count_large size [permissions]\n");
        return 1;
    }
    // TODO: Process command line arguments.
    int count=0;
    int second;
    char *third;
    char clean_permission[32];
    char garbage[32];
    int garbage_number;
    char permission[32];
    int num_links;
    char owner[32];
    char group[32];
    int size;
    char last_modify_month[32];
    int last_modify_date;
    char last_modify_time[32];
    char filename[32];
    scanf("%s",garbage);
    /*printf("%s\n",garbage);*/
    scanf("%d",&garbage_number);
    /*printf("%d\n",garbage_number);*/
    if(argc==2){
       second=strtol(argv[1],NULL,10);
       /*printf("%d\n",second);*/
       while(scanf("%s",permission)!=EOF){
           /*printf("%s\n",permission);*/
	   scanf("%d",&num_links);
	   /*printf("%d\n",num_links);*/
	   scanf("%s",owner);
	   /*printf("%s\n",owner);*/
	   scanf("%s",group);
	   /*printf("%s\n",group);*/
	   scanf("%d",&size);
	   /*printf("%d\n",size);*/
	   scanf("%s",last_modify_month);
	   /*printf("%s\n",last_modify_month);*/
	   scanf("%d",&last_modify_date);
	   /*printf("%d\n",last_modify_date);*/
	   scanf("%s",last_modify_time);
	   /*printf("%s\n",last_modify_time);*/
	   scanf("%s",filename);
	   /*printf("%s\n",filename);*/
	   if(size>=second){
	     count+=1;
	   }
       }
     }else if(argc==3){
       second=strtol(argv[1],NULL,10);
       /*printf("%d\n",second);*/
       third=argv[2];
       /*printf("%s\n",third);*/
       while(scanf("%s",permission)!=EOF){
           strcpy(clean_permission,&permission[1]);
           /*printf("%s\n",clean_permission);*/
	   scanf("%d",&num_links);
	   /*printf("%d\n",num_links);*/
	   scanf("%s",owner);
	   /*printf("%s\n",owner);*/
	   scanf("%s",group);
	   /*printf("%s\n",group);*/
	   scanf("%d",&size);
	   /*printf("%d\n",size);*/
	   scanf("%s",last_modify_month);
	   /*printf("%s\n",last_modify_month);*/
	   scanf("%d",&last_modify_date);
	   /*printf("%d\n",last_modify_date);*/
	   scanf("%s",last_modify_time);
	   /*printf("%s\n",last_modify_time);*/
	   scanf("%s",filename);
	   /*printf("%s\n",filename);*/
	   if((size>=second)&&(check_permissions(clean_permission,third)==0)){
	     count+=1;
	   }
       }
     
     
     }
     printf("%d\n",count);
    // TODO Call check permissions as part of your solution to counting the files to
    // compute and print the correct value.

    return 0;
}

int check_permissions(char *actual_permission, char *least_permission){
    int i;
    for(i=0;i<9;i++){
        if(*(least_permission+i)!='-'){
	  if(*(actual_permission+i)!=*(least_permission+i)){
	    return 1;
	  }
	}
    }
    return 0;
}
