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
  addr.sin_port = htons(3490);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(&(addr.sin_zero), 0, 8);

  connect(sockfd, (struct sockaddr *) &addr, sizeof(struct sockaddr));

  char message[1000] = "Hello Server :)";

  send(sockfd, message, strlen(message), 0);

  std::cout << "SENT MESSAGE" << std::endl;

  close(sockfd);

}
