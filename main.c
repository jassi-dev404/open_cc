#include <sys/types.h>
#include <sys/socket.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>

int main(void)
{
  struct sockaddr_in addr;
  int abc = socket(AF_INET, SOCK_STREAM, 0);
  addr.sin_family = AF_INET;  
  addr.sin_port = htons(6969);
  addr.sin_addr.s_addr = inet_addr("127.0.0.1"); 
  memset(&(addr.sin_zero), '\0', 8); 
  int random_int = bind(abc, (struct sockaddr *)&addr, sizeof(struct sockaddr));
  listen(abc, 10);
  int i = 1;
  socklen_t addr_len = sizeof(struct sockaddr);
  while(i == 1) {
    int abcd = accept(abc, (struct sockaddr *)&addr, &addr_len);
    if (abcd == -1) {
      i = 0;
    }
  }
}
