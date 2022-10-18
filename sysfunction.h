#ifndef __SYS_FUNCTION_
#define __SYS_FUNCTION_
#include "ipv4_data.h"
#include "rount_map.h"


// void fwd_discardpkt(char* ptrbuffer,int type ); //出现错误
// void fwd_localrec(char* ptrbuffer,int lenght);//交付上层
void fwd_sendtolow(char* ptrbuffer, int lenght, int nexthop); //转发
unsigned int getadress();
void ip_DiscardPkt(char* pBuffer, int type); //丢弃分组
void send_to_lower(char* pBuffer, int len); //发送
void send_to_up(char* pBuffer, int len); //交付上层
void stud_add_route_map(vector<Rount_map>& mpl, const Rount_map mp1);//路由表添加
void stud_init_route_map(vector<Rount_map>& mpl);

#endif // !__Handle_ptrbuffer
