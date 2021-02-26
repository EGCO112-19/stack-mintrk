#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "stack.h"

int main(int argc, char **argv){
  printf("Checking the parentheses in argv arguments\n");
  int i,N,j;
  
  Stack s;
  s.size = 0;
  s.top = NULL;
  char popvalue;
  int check=0;
  
  
  for(i=1;i<argc;i++){// each argument
    //printf("%s\n",argv[i]);
    //printf("%ld\n",strlen(argv[i]));
     for(j=0;j<strlen(argv[i]);j++){
       /* Use stack to help with the parentheses*/
       if(argv[i][j] == '[' || argv[i][j] == '{'){
          push(&s, argv[i][j]); 
       }
       else if (argv[i][j] == ']'){
          if (s.size==0){
            check = 1;
            break;
          }
          popvalue = pop(&s);
          if (popvalue != '['){
            check = 1;
            break;
          }
       }
       else if (argv[i][j] == '}'){
         if (s.size==0){
           check = 1;
            break;
          }
          popvalue = pop(&s);
          if (popvalue != '{'){
            check = 1;
            break;
          }
       }

      

     }
     if(s.size>0 || check != 0){
         //printf("%d ..\n",s.size);
         printf("The parenthses do not match for %s \n", argv[i]);
         pop_all(&s);
       }else{
         //printf("%d ..\n",s.size);
         printf("The parenthses match successfully for %s \n", argv[i]);
       }

  }
   return 0;
}

 /*switch(argv[i][j]){
         case '[':
            break;
         case '{':
            push(&s, argv[i][j]);
            break;
         case ']':
            
            break;
         case '}':
            pop(&s);
            break;
       }*/