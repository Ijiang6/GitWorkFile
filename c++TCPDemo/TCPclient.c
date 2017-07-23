#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<arpa/inet.h>


int main(int argc, char *argv[]){
int client_sockfd;
int len;
struct sockaddr_in remote_addr;
char buf[1024];
memset(&remote_addr,0,sizeof(remote_addr));
remote_addr.sin_family=AF_INET;
remote_addr.sin_addr.s_addr=inet_addr("127.0.0.1");
remote_addr.sin_port=htons(9999);
client_sockfd=socket(PF_INET,SOCK_STREAM,0);

connect(client_sockfd,(struct sockaddr*)&remote_addr,sizeof(struct sockaddr));
len=recv(client_sockfd,buf,1024,0);
buf[len]='\0';
printf("%s\n",buf);
printf("enter string to send:");
scanf("%s",buf);
len=send(client_sockfd,buf,strlen(buf),0);
len=recv(client_sockfd,buf,1024,0);
buf[len]='\0';
printf("receive :%s\n",buf);

close(client_sockfd);
return 0;
}
