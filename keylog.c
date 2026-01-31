#include <fcntl.h>
#include <linux/input-event-codes.h>
#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  char *event = argv[1];

  int fd = open(argv[1], O_RDONLY, 0);
  struct input_event ie;

  while (1){
    read(fd, &ie,sizeof(ie));

    if (ie.type != EV_KEY){
      continue;
    }

    if (ie.value != 1 ){
      continue;
    }

    if (ie.code > 1 && ie.code < 11){
      printf("the key num that is being pressed is %d\n", ie.code - 1 );
    }

    else if(ie.code == 11 ){
      printf("0\n");
    }

    else if(ie.code ==  KEY_A){
      printf("A\n");
    }
    else if(ie.code ==  KEY_B){
      printf("B\n");
    }
    else if(ie.code ==  KEY_C){
      printf("C\n");
    }
    else if(ie.code ==  KEY_D){
      printf("D\n");
    }
    else if(ie.code ==  KEY_E){
      printf("E\n");
    }
    else if(ie.code ==  KEY_F){
      printf("F\n");
    }
    else if(ie.code ==  KEY_G){
      printf("G\n");
    }
    else if(ie.code ==  KEY_H){
      printf("H\n");
    }
    else if(ie.code ==  KEY_I){
      printf("I\n");
    }
    else if(ie.code ==  KEY_J){
      printf("J\n");
    }
    else if(ie.code ==  KEY_K){
      printf("K\n");
    }
    else if(ie.code ==  KEY_L){
      printf("L\n");
    }
    else if(ie.code ==  KEY_M){
      printf("M\n");
    }
    else if(ie.code ==  KEY_N){
      printf("N\n");
    }
    else if(ie.code ==  KEY_O){
      printf("O\n");
    }
    else if(ie.code ==  KEY_P){
      printf("P\n");
    }
    else if(ie.code ==  KEY_Q){
      printf("Q\n");
    }
    else if(ie.code ==  KEY_R){
      printf("R\n");
    }
    else if(ie.code ==  KEY_S){
      printf("S\n");
    }
    else if(ie.code ==  KEY_T){
      printf("T\n");
    }
    else if(ie.code ==  KEY_U){
      printf("U\n");
    }
    else if(ie.code ==  KEY_V){
      printf("V\n");
    }
    else if(ie.code ==  KEY_W){
      printf("W\n");
    }
    else if(ie.code ==  KEY_X){
      printf("X\n");
    }
    else if(ie.code ==  KEY_Y){
      printf("Y\n");
    }
    else if(ie.code ==  KEY_Z){
      printf("Z\n");
    }
    
    else {
      printf("UNKNOWN KEY\n");
    }

    
  }
}



