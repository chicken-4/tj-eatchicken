#pragma once
#include<iostream>
#include<winsock.h>
#pragma comment(lib,"ws2_32.lib")


class server
{
	//���캯�������ڴ�������
	server(const char* ip ,unsigned short port = 0);
	//�������������ڳ�������
	~server();
	
	//���������׽���
	SOCKET c_server;
	SOCKET c_accept;
	
	SOCKADDR_IN server_add;//����˵�ַ
	SOCKADDR_IN accept_add;//�ͻ��˵�ַ

	bool serverconnect(const char* ip, unsigned short port);
	char* serverreceive(char* rece);
	char* serversend(char* sendm);
	void serverclose();
};

