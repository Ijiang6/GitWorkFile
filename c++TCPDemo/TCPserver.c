#include<stdio.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<string.h>
int main(int argc,char *argv[]){
int server_sockfd;
int client_sockfd;
int len;
struct sockaddr_in my_addr;//服务器网络地址
struct sockaddr_in remote_addr;//客户端网络地址结构体
int sin_size;
char strbuf[1024]="weclome to my server";
char buf[1024];//数据传输的缓存区
memset(&my_addr,0,sizeof(my_addr));//数据初始化清零
my_addr.sin_family=AF_INET;//设置为ip通信
my_addr.sin_addr.s_addr=INADDR_ANY;//服务器IP地址允许连接到所有本地IP地址上
my_addr.sin_port=htons(9999);//服务器端口号


//创建服务器端套接字--ipv4协议，tcp通信
if((server_sockfd=socket(PF_INET,SOCK_STREAM,0))<0){
perror("socket error");
return -1;

}

//将套接字绑定到服务器的网络地址上
if(bind(server_sockfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr))<0){
perror("bind error");
return -1;


}

//监听链接请求，监听的长度为5
if(listen(server_sockfd,5)<0){
perror("listen error");
return -1;

}

//等待客户端链接请求的到达
if((client_sockfd=accept(server_sockfd,(struct sockaddr *)&remote_addr,&sin_size))<0){
perror("accept error");
return -1;

}

printf("accept client%d\n",inet_ntoa(remote_addr.sin_addr));
len=send(client_sockfd,strbuf,strlen(strbuf),0);//发送欢迎信息
//接收客户端信息，并将其发送给客户端--recv返回收到的字节数目，send返回发送的字节数目

len=recv(client_sockfd,buf,1024,0);
buf[len]='\0';
printf("%s\n",buf);
if(send(client_sockfd,buf,len,0)<0){

perror("write error");
return -1;


}
//关闭套接字
close(client_sockfd);
close(server_sockfd);
return 0;

}
