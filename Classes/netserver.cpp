#pragma once
#include"server.h"

server::server(const char* ip, unsigned short port )
{
	ip = "127.0.0.1";//127.0.0.1��ʾ������ַ
	port = 1000;//�ӿ�
	
}

server::~server()
{
    serverclose();
    //�ͷ�DLL��Դ
    WSACleanup();
}

bool server::serverconnect(const char* ip, unsigned short port) {
    
    //��ʼ���׽��ֿ�
    WORD w_req = MAKEWORD(2, 2);//�汾��
    WSADATA wsadata;
    int err;
    err = WSAStartup(w_req, &wsadata);
    if (err != 0) {
        return 0;
        //��ʼ���׽��ֿ�ʧ��
    }
    else {
        //��ʼ���׽��ֿ�ɹ�
    }
    //���汾��
    if (LOBYTE(wsadata.wVersion) != 2 || HIBYTE(wsadata.wHighVersion) != 2) {
        //�׽��ֿ�汾�Ų���
        WSACleanup();
        return 0;
    }
    else {
        return 1;//�׽��ֿ�汾��ȷ
    }
    //������˵�ַ��Ϣ

    server_add.sin_family = AF_INET;
    server_add.sin_addr.S_un.S_addr = htonl(INADDR_ANY);
    server_add.sin_port = htons(port);

    //�����׽���
    c_server= socket(AF_INET, SOCK_STREAM, 0);
    if (bind(c_server, (SOCKADDR*)&server_add, sizeof(SOCKADDR)) == SOCKET_ERROR) {
        //�׽��ְ�ʧ��
        WSACleanup();
        return 0;
    }
    else {
        //�׽��ְ󶨳ɹ�
        return 1;
    }
    //�����׽���Ϊ����״̬
    /*�ڷ������˳���ʹ�� bind() ���׽��ֺ󣬻���Ҫʹ�� listen() �������׽��ֽ��뱻������״̬���ٵ��� accept() �������Ϳ�����ʱ��Ӧ�ͻ��˵������ˡ�
ͨ��** listen() ����**�������׽��ֽ��뱻������״̬������ԭ��Ϊ��*/
    if (listen(c_server, SOMAXCONN) < 0) {
        /*s_server Ϊ��Ҫ�������״̬���׽��֣�SOMAXCONNΪ������е���󳤶ȡ�*/
        //���ü���״̬ʧ��
        WSACleanup();
        return 0;
    }
    else {
        return 1;
        //���ü���״̬�ɹ�
    }
    //��������ڼ�������
    //������������
    int len = sizeof(SOCKADDR);
    //���׽��ִ��ڼ���״̬ʱ������ͨ�� accept() ���������տͻ�����������ԭ��Ϊ��
    c_accept = accept(c_server, (SOCKADDR*)&accept_add, &len);
    //s_server Ϊ���������׽��֣�accept_addr Ϊ sockaddr_in �ṹ�����len Ϊ����ccept_addr�ĳ��ȣ����� sizeof() ���
    /*�����Ҫ˵�����ǣ�listen() ֻ�����׽��ֽ������״̬����û���������տͻ�������
    listen() ����Ĵ�������ִ�У�ֱ������ accept()��accept() ����������ִ�У�������벻�ܱ�ִ�У���
    ֱ�����µ���������*/

    if (c_accept == SOCKET_ERROR) {
        //����ʧ��
        WSACleanup();
        return 0;
    }
    return 1;
    //���ӽ�����׼����������
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
    //�ر��׽���
    closesocket(c_server);
}