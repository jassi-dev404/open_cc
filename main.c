#include <arpa/inet.h>
#include <netinet/in.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <unistd.h>

int main(void) {
  struct sockaddr_in addr;
  int abc = socket(AF_INET, SOCK_STREAM, 0);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(6969);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1");
  memset(&(addr.sin_zero), '\0', 8);
  int random_int = bind(abc, (struct sockaddr *)&addr, sizeof(addr));
  listen(abc, 10);
  int i = 1;
  const char *text_to_be_sent = "hey bitch \n";
  socklen_t addr_len = sizeof(struct sockaddr);
  while (i == 1) {
    int abcd = accept(abc, (struct sockaddr *)&addr, &addr_len);
    if (abcd == -1) {
      perror("some oopsie happend");
      return 1;
    } else {
      while (i == 1) {
        send(abcd, text_to_be_sent, strlen(text_to_be_sent) + 1, 0);
        sleep(1);
      }
    }
  }
}