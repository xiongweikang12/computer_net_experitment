#ifndef __SYS_FUNCTION_
#define __SYS_FUNCTION_
#include "ipv4_data.h"
#include "rount_map.h"


// void fwd_discardpkt(char* ptrbuffer,int type ); //���ִ���
// void fwd_localrec(char* ptrbuffer,int lenght);//�����ϲ�
void fwd_sendtolow(char* ptrbuffer, int lenght, int nexthop); //ת��
unsigned int getadress();
void ip_DiscardPkt(char* pBuffer, int type); //��������
void send_to_lower(char* pBuffer, int len); //����
void send_to_up(char* pBuffer, int len); //�����ϲ�
void stud_add_route_map(vector<Rount_map>& mpl, const Rount_map mp1);//·�ɱ����
void stud_init_route_map(vector<Rount_map>& mpl);

#endif // !__Handle_ptrbuffer
