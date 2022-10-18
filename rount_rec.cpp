#include "rount_map.h"
#include "sysfunction.h"
#include <vector>
using namespace std;

//ת��ip���ݱ�

int stud_fwd_deal(char* ptrbuffer, int len
	,vector<Rount_map>& r_map)
{
	int THl = ptrbuffer[0] & 0xf; //�ײ�����
	int ttl = (int)ptrbuffer[8];
	int headcheckout = ntohl(*(unsigned short*)(ptrbuffer + 10));
	int destip = ntohl(*(unsigned int*)(ptrbuffer + 16));
	if (destip == getadress())
	{
		send_to_up(ptrbuffer, len);
		return 1;
	}
	if (ttl <= 0)
	{
		ip_DiscardPkt(ptrbuffer, STUD_IP_TEST_TTL_ERROR);
		return 1;
	}
	bool ismacth = false;
	unsigned int longestmarklen = 0;
	int bestmacth = 0;
	for (int  i = 0; i < r_map.size(); i++)
	{
		if (r_map[i].masklen > longestmarklen
			&& (r_map[i].desIP == (destip & r_map[i].mask)))
		{
			ismacth = true;
			bestmacth = i;
		}
	}

	if(ismacth)
	{

		//ת��TTL-1 ,�ײ���������¼���
		//ͨ��һ��buffer ��� ptrbuffer
		char* buffer = new char[len];
		memcpy(buffer, ptrbuffer, len);
		int ttl_rount = ttl - 1;
		memcpy(buffer+8, &ttl_rount, sizeof(int));

		unsigned short int localcheck_head = 0;
		int sum = 0;//�ײ�����
		for (int j = 0; j < THl * 2; j++)
		{
			if (j == 5) { continue; }
			sum += (ptrbuffer[j * 2] << 8) + (ptrbuffer[j * 2 + 1]);
		}
		unsigned short int temp= (sum & 0xffff) + ((sum >> 16) & 0xffff);
		localcheck_head = ~temp;
		memcpy(buffer + 10, &localcheck_head, sizeof(unsigned short int)); //����

		//....
		

		fwd_sendtolow(buffer, len, r_map[bestmacth].nexthop);
		//ת��

	}
	else
	{
		//��ʾδ�ҵ�
		ip_DiscardPkt(ptrbuffer, STUD_IP_TEST_NOMACTHNET);
		return 1;
	}

	return 1;
}