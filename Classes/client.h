#pragma once
#include<iostream>
#include<winsock.h>
#pragma comment(lib,"ws2_32.lib")


class client
{
	//���캯�������ڴ�������
	client(const char* ip, unsigned short port = 0);
	//�������������ڳ�������
	~client();

	SOCKET c_server;//���������׽���
	SOCKADDR_IN server_add;//����˵�ַ

	bool clientconnect(const char* ip, unsigned short port);//���ڿͻ������ӵ�����
	bool clientreceive(char* rece);//���ڽ�����Ϣ
	bool clientsend(char* sendm);//���ڴ�����Ϣ
	void clientclose();
};

