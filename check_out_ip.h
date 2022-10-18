#ifndef   __check_out__
#define  __check_out__
#include "ipv4_data.h"
bool check_out_version(ipv4* ip1); //检验版本号 4位

bool check_out_headlength(ipv4* ip1); //检验首部长度（最小为5字节） 4位

bool check_out_TTl(ipv4* ip1); //检验TTL

bool check_out_desadress(ipv4* ip1); //检验接收到的目的地址

//检验首部检验和

#endif // !  __check_out__

