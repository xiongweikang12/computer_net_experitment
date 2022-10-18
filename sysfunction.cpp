#include "sysfunction.h"


void fwd_localrec(char* ptrbuffer, int lenght){
	//交付上层 
}
void fwd_sendtolow(char* ptrbuffer, int lenght, int nexthop){ 
	//转发
}

unsigned int getadress()//获取本地的ip
{
	//获取本地的ip
	return 1;
}

void ip_DiscardPkt(char* pBuffer, int type)
{
	// 丢弃分组;
}

void send_to_lower(char* pBuffer, int len)
{
	//发送分组
}

void send_to_up(char* pBuffer, int len)
{
	//接收方检验成功;
	//上层接收
}

void stud_add_route_map(vector<Rount_map>& mpl, const Rount_map mp1)//路由表添加
{
	mpl.push_back(mp1);
}
//路由表增加信息

void stud_init_route_map(vector<Rount_map>& mpl)
{
	mpl.clear();
}
//路由表清空，初始化
