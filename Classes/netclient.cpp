//客户端
#pragma once
#include"client.h"

client::client(const char* ip, unsigned short port)
{
    ip = "127.0.0.1";//127.0.0.1表示本机地址
    port = 1000;//接口
	
}

client::~client()
{   
    clientclose();
    //释放DLL资源
    WSACleanup();
}

bool client::clientconnect(const char* ip, unsigned short port = 0)
{
      
    //初始化套接字库
    WORD w_req = MAKEWORD(2, 2);//版本号
    WSADATA wsadata;
    int err;
    err = WSAStartup(w_req, &wsadata);
    if (err != 0) {
        return 0;//初始化套接字库失败
    }
    else {
        //初始化套接字库成功
    }
    //检测版本号
    if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2)
    {
        //套接字库版本号不符
        WSACleanup();
        return 0;
    }
    else {
        //套接字库版本正确
    }

    
    //填充服务端地址信息
    server_add.sin_family = AF_INET;
    server_add.sin_addr.S_un.S_addr = inet_addr(ip);
    server_add.sin_port = htons(port);//接口
    c_server = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(c_server, (SOCKADDR*)&server_add, sizeof(SOCKADDR)) == SOCKET_ERROR) {//连接服务器的函数
        WSACleanup();//服务器连接失败
        return 0;
    }
    else {
        return 1;
        //服务器连接成功
    }

}
bool client::clientreceive(char* rece)
{
    if (recv(c_server, rece, 100, 0) < 0) {
        return NULL;
    }
    else {
        return rece;
    }
}

bool client::clientsend(char* sendm)
{
    if (send(c_server, sendm, 100, 0) < 0) {
        return NULL;
    }
    else {
        return sendm;
    }
}

void client::clientclose()
{
    //关闭套接字
    closesocket(c_server);
}