#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "request.h"



void assign_user(Protocol* protocol, User* user,int state){
  protocol->state = state;
  strcpy(protocol->user_info.name, user->name);
  strcpy(protocol->user_info.pass, user->pass);
  protocol->user_info.state = state;
  protocol->user_info.next = user->next;
}


int request_play(Protocol* protocol, User* user, int client_sock, int state){
  int bytes_received, bytes_sent;
  do {
    assign_user(protocol, user, state);
    protocol->message = WANT_TO_PLAY;

    bytes_sent = send(client_sock, protocol, sizeof(Protocol), 0);
    check_error(bytes_sent, client_sock);

    bytes_received = recv(client_sock, protocol, sizeof(Protocol), 0);
    check_error(bytes_received, client_sock);

    if (protocol->message == ALLOW_PLAY){
      printf("Duoc phep choi\n");
      return protocol->state;
    } else {
      printf("Khong duoc phep\n");
    }
  } while (protocol->message != ALLOW_PLAY);
}


void ready(Protocol* protocol, User* user, int client_sock, int state){
  int bytes_sent;
  assign_user(protocol, user, state);
  protocol->message = I_AM_READY;
  printf("%d\n", protocol->message);
  printf("%d\n", protocol->state);
  bytes_sent = send(client_sock, protocol, sizeof(Protocol), 0);
  check_error(bytes_sent, client_sock);
}


int request_signup(Protocol* protocol, User* user, int client_sock, int state){
  int bytes_sent, bytes_received;
  assign_user(protocol, user, state);
  protocol->state = state;
  protocol->message = WANT_TO_SIGUP;
  bytes_sent = send(client_sock, protocol, sizeof(Protocol), 0);
  check_error(bytes_sent, client_sock);

  bytes_received = recv(client_sock, protocol, sizeof(Protocol), 0);
  check_error(bytes_received, client_sock);

  return protocol->message;
}


int request_sign_in(Protocol* protocol, User* user, int client_sock, int state){

  puts("abc");
  int bytes_sent, bytes_received;
  assign_user(protocol, user, state);
  protocol->state = state;
  protocol->message = WANT_TO_SIGIN;
  bytes_sent = send(client_sock, protocol, sizeof(Protocol), 0);
  check_error(bytes_sent, client_sock);

  bytes_received = recv(client_sock, protocol, sizeof(Protocol), 0);
  check_error(bytes_received, client_sock);

  puts("tttttt");
  return protocol->message;
}