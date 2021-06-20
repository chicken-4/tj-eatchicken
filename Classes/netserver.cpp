#pragma once
#include"server.h"

server::server(const char* ip, unsigned short port )
{
	ip = "127.0.0.1";//127.0.0.1表示本机地址
	port = 1000;//接口
	
}

server::~server()
{
    serverclose();
    //释放DLL资源
    WSACleanup();
}

bool server::serverconnect(const char* ip, unsigned short port) {
    
    //初始化套接字库
    WORD w_req = MAKEWORD(2, 2);//版本号
    WSADATA wsadata;
    int err;
    err = WSAStartup(w_req, &wsadata);
    if (err != 0) {
        return 0;
        //初始化套接字库失败
    }
    else {
        //初始化套接字库成功
    }
    //检测版本号
    if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {
        //套接字库版本号不符
        WSACleanup();
        return 0;
    }
    else {
        return 1;//套接字库版本正确
    }
    //填充服务端地址信息

    server_add.sin_family = AF_INET;
    server_add.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    server_add.sin_port = htons(port);

    //创建套接字
    c_server= socket(AF_INET, SOCK_STREAM, 0);
    if (bind(c_server, (SOCKADDR*)&server_add, sizeof(SOCKADDR)) == SOCKET_ERROR) {
        //套接字绑定失败
        WSACleanup();
        return 0;
    }
    else {
        //套接字绑定成功
        return 1;
    }
    //设置套接字为监听状态
    /*于服务器端程序，使用 bind() 绑定套接字后，还需要使用 listen() 函数让套接字进入被动监听状态，再调用 accept() 函数，就可以随时响应客户端的请求了。
通过** listen() 函数**可以让套接字进入被动监听状态，它的原型为：*/
    if (listen(c_server, SOMAXCONN) < 0) {
        /*s_server 为需要进入监听状态的套接字，SOMAXCONN为请求队列的最大长度。*/
        //设置监听状态失败
        WSACleanup();
        return 0;
    }
    else {
        return 1;
        //设置监听状态成功
    }
    //服务端正在监听连接
    //接受连接请求
    int len = sizeof(SOCKADDR);
    //当套接字处于监听状态时，可以通过 accept() 函数来接收客户端请求。它的原型为：
    c_accept = accept(c_server, (SOCKADDR*)&accept_add, &len);
    //s_server 为服务器端套接字，accept_addr 为 sockaddr_in 结构体变量len 为参数ccept_addr的长度，可由 sizeof() 求得
    /*最后需要说明的是：listen() 只是让套接字进入监听状态，并没有真正接收客户端请求，
    listen() 后面的代码会继续执行，直到遇到 accept()。accept() 会阻塞程序执行（后面代码不能被执行），
    直到有新的请求到来。*/

    if (c_accept == SOCKET_ERROR) {
        //连接失败
        WSACleanup();
        return 0;
    }
    return 1;
    //连接建立，准备接受数据
}

char* server::serverreceive(char* rece) {
    
    if (recv(c_accept, rece, 100, 0) < 0) {
        return NULL;
    }
    else {
        return rece;
    }
    
}
char* server::serversend(char* sendm) {
    
    if (send(c_accept, sendm, 100, 0) < 0) {
        return NULL;
    }
    else {
        return sendm;
    }
}

void server::serverclose()
{
    //关闭套接字
    closesocket(c_server);
}