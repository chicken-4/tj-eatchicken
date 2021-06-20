#pragma once
#include<iostream>
#include<winsock.h>
#pragma comment(lib,"ws2_32.lib")


class client
{
	//构造函数，用于创建对象
	client(const char* ip, unsigned short port = 0);
	//析构函数，用于撤销对象
	~client();

	SOCKET c_server;//定义服务端套接字
	SOCKADDR_IN server_add;//服务端地址

	bool clientconnect(const char* ip, unsigned short port);//用于客户端连接到主机
	bool clientreceive(char* rece);//用于接受信息
	bool clientsend(char* sendm);//用于传递信息
	void clientclose();
};

