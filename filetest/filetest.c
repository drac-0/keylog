#include <stdio.h>
#include <stdlib.h>


int main(){
  FILE *fptr ;
  fptr = fopen("new.txt", "w");
  fprintf(fptr, "test\n");
  fprintf(fptr, "p");
  fprintf(fptr, "\b"); // '\b' argument for delete
  fclose(fptr);



}
