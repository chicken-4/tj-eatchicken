//�ͻ���
#pragma once
#include"client.h"

client::client(const char* ip, unsigned short port)
{
    ip = "127.0.0.1";//127.0.0.1��ʾ������ַ
    port = 1000;//�ӿ�
	
}

client::~client()
{   
    clientclose();
    //�ͷ�DLL��Դ
    WSACleanup();
}

bool client::clientconnect(const char* ip, unsigned short port = 0)
{
      
    //��ʼ���׽��ֿ�
    WORD w_req = MAKEWORD(2, 2);//�汾��
    WSADATA wsadata;
    int err;
    err = WSAStartup(w_req, &wsadata);
    if (err != 0) {
        return 0;//��ʼ���׽��ֿ�ʧ��
    }
    else {
        //��ʼ���׽��ֿ�ɹ�
    }
    //���汾��
    if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2)
    {
        //�׽��ֿ�汾�Ų���
        WSACleanup();
        return 0;
    }
    else {
        //�׽��ֿ�汾��ȷ
    }

    
    //������˵�ַ��Ϣ
    server_add.sin_family = AF_INET;
    server_add.sin_addr.S_un.S_addr = inet_addr(ip);
    server_add.sin_port = htons(port);//�ӿ�
    c_server = socket(AF_INET, SOCK_STREAM, 0);
    if (connect(c_server, (SOCKADDR*)&server_add, sizeof(SOCKADDR)) == SOCKET_ERROR) {//���ӷ������ĺ���
        WSACleanup();//����������ʧ��
        return 0;
    }
    else {
        return 1;
        //���������ӳɹ�
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
    //�ر��׽���
    closesocket(c_server);
}