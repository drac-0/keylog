#include <netinet/in.h>
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

int main(int argc, char *argv[]){
  if (argc != 4){
    return EXIT_FAILURE;
  }

  // main var
  const char *ip = argv[1];
  int port = atoi(argv[2]);
  const char *message = argv[3];

  // string ip to 
  struct sockaddr_in desti = {.sin_family = AF_INET, .sin_port = htons(port)};

  if (inet_pton(AF_INET, ip, &(desti.sin_addr)) <= 0){
    perror("something wrong with ip");
    return EXIT_FAILURE;
  }

  int udp = socket(AF_INET, SOCK_DGRAM, 0);
  if (udp < 0 ){
    perror("CANT CReATE");
    return EXIT_FAILURE;
  }
  if (sendto(udp, message, strlen(message) + 1, 0,
             (struct sockaddr *)&desti, sizeof(desti)) < 0){
    perror("FAILED");
    close(udp);
    return EXIT_FAILURE;
  } 

  printf("%s to %s:%d\n", message, ip, port);
  close(udp);

}


