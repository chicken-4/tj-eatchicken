#pragma once
#include<iostream>
#include<winsock.h>
#pragma comment(lib,"ws2_32.lib")


class server
{
	//构造函数，用于创建对象
	server(const char* ip ,unsigned short port = 0);
	//析构函数，用于撤销对象
	~server();
	
	//定义服务端套接字
	SOCKET c_server;
	SOCKET c_accept;
	
	SOCKADDR_IN server_add;//服务端地址
	SOCKADDR_IN accept_add;//客户端地址

	bool serverconnect(const char* ip, unsigned short port);
	char* serverreceive(char* rece);
	char* serversend(char* sendm);
	void serverclose();
};

