#include "sysfunction.h"


void fwd_localrec(char* ptrbuffer, int lenght){
	//�����ϲ� 
}
void fwd_sendtolow(char* ptrbuffer, int lenght, int nexthop){ 
	//ת��
}

unsigned int getadress()//��ȡ���ص�ip
{
	//��ȡ���ص�ip
	return 1;
}

void ip_DiscardPkt(char* pBuffer, int type)
{
	// ��������;
}

void send_to_lower(char* pBuffer, int len)
{
	//���ͷ���
}

void send_to_up(char* pBuffer, int len)
{
	//���շ�����ɹ�;
	//�ϲ����
}

void stud_add_route_map(vector<Rount_map>& mpl, const Rount_map mp1)//·�ɱ����
{
	mpl.push_back(mp1);
}
//·�ɱ�������Ϣ

void stud_init_route_map(vector<Rount_map>& mpl)
{
	mpl.clear();
}
//·�ɱ���գ���ʼ��
