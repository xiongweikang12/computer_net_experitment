
#include "sysfunction.h"
#include <winsock.h>
//��IP���ݱ�
//����IP���ݱ�
//ת��IP ���ݱ�

//�����ǶԽ���ip���ݱ��ĵļ���

//����Ϊϵͳ����

bool check_out_version(ipv4* ip1)
{
	int version = (ip1->version_ihl >> 4) & 0xf;
	//����4λ�ƶ��£��� 0xf����
	if (version != 4) //�汾�Ų�һ��
	{
		return  false;
	}
	return true;
}

bool check_out_headlength(ipv4* ip1)
{
	// int version_l = ip1->version_ihl & 0xf;
	return int(ip1->version_ihl & 0xf) > 5 ? false : true;
}

bool check_out_TTl(ipv4* ip1)
{
	return ip1->time_to_live == 0 ? false : true;
}

bool check_out_desadress(ipv4* ip1)
{
	int desadress_1 = ntohl(ip1->destination_adress);
	if (desadress_1 != getadress() && desadress_1 != 0xffffffff)
	{
		//��ʾ���յ���Ŀ��ip�����ڱ���ip
		//ͬʱҲ�����ڹ㲥
		return false;
	}
	return true;
}

//����Ϊ���շ���IP���ݱ��ļ��


//дһ������IP����
//����IP ����
