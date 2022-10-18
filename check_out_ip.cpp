
#include "sysfunction.h"
#include <winsock.h>
//发IP数据报
//接收IP数据报
//转发IP 数据报

//这里是对接收ip数据报的的检验

//以上为系统函数

bool check_out_version(ipv4* ip1)
{
	int version = (ip1->version_ihl >> 4) & 0xf;
	//将高4位移动下，和 0xf相与
	if (version != 4) //版本号不一致
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
		//表示接收到的目的ip不等于本地ip
		//同时也不属于广播
		return false;
	}
	return true;
}

//以上为接收方对IP数据报的检测


//写一个发送IP函数
//接收IP 函数
