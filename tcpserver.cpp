#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <iostream>

#define deb std::cout << "debug "
#define p(x) << x << " "
#define mend << std::endl

#define ll long long

int main() {
  int sockfd;
  struct sockaddr_in addr;

  sockfd = socket(AF_INET, SOCK_STREAM, 0);

  addr.sin_family = AF_INET;
  addr.sin_port = htons(8080);
  addr.sin_addr.s_addr = INADDR_ANY;
  memset(&(addr.sin_zero), 0, 8);

  bind(sockfd, (struct sockaddr *) &addr, sizeof(struct sockaddr));

  listen(sockfd, 5);

  struct sockaddr_in client;
  socklen_t size = sizeof(struct sockaddr_in);

  int connfd = accept(sockfd, (struct sockaddr *) &client, &size);

  char message[1000];
  memset(message, 0, 1000);

  recv(connfd, message, 999, 0);

  std::cout << message << std::endl;

  close(connfd);
  close(sockfd);

}
