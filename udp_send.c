#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <arpa/inet.h>

int main() {
  int sock;
  struct sockaddr_in addr;
  char hello[50];
  printf("メッセージを入力してください");
  scanf("%s", hello);

  sock = socket(AF_INET, SOCK_DGRAM, 0);
  addr.sin_family = AF_INET;
  addr.sin_port = htons(22222);
  inet_pton(AF_INET, "127.0.0.1", &addr.sin_addr.s_addr);

  sendto(sock, hello, sizeof(hello), 0, (struct sockaddr *)&addr, sizeof(addr));
  close(sock);
  return 0;
}
