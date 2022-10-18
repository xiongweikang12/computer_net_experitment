#ifndef IPV4_DATA_
#define IPV4_DATA_
#include <winsock.h>
#include <string.h>
#include "type_error.h"

struct ipv4
{
	char version_ihl; //ip版本号
	char type_of_service; //区分服务
	short total_length; //总长度
	short identification; //标识
	short fragment_offset; //偏位移
	char time_to_live; //TTl
	char protocol;    //协议
	short header_checksum; //首部检验和
	unsigned int  source_adress; //源地址
	unsigned int  destination_adress; //目的地址
	ipv4() { memset(this, 0, sizeof(ipv4)); }
	//初始化，初值全为0，构造函数1
	ipv4(unsigned int len, unsigned int srcadress,
		unsigned int desadress, char _protocol, char ttl)
	{
		memset(this, 0, sizeof(ipv4));
		version_ihl = 0x45;
		total_length = htons(len + 20);
		//数据载荷长度加上20位ip首部
		time_to_live = ttl;
		protocol = _protocol;
		source_adress = htonl(srcadress);
		destination_adress = htonl(desadress);
		//htons 16位 short
		//htonl 32位 long

		char* ptrBuffer;
		memcpy(ptrBuffer, this, sizeof(ipv4));
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			if (i= !5) {
				sum += (int)((unsigned char)ptrBuffer[i * 2])<< 8;
				sum += (int)((unsigned char)ptrBuffer[i * 2 + 1]);
				//ptrBuffer value_type 为char 1字节 8bit
				//将一组16 分为 两个8bit ,将前面一个的后八位低8位数移动到高8位
				//合成一个16
				//相加，跳过 10~12字节
			}
		}
		while ((sum & 0xffff0000) != 0) {
			sum = (sum & 0xffff) + ((sum >> 16) & 0xffff);
			//由于多个16bit相加产生了进位，还原成16bit 
			// 322C4 0003 + 22C4 = 22C7
			//sum &0xffff 得到低16位
			//(sum>>16)&0xffff 将高16位转到低16位 取其
			//相加
		}
		unsigned short int ssum = sum; //int ->short ,32->16
		header_checksum = ~ssum; //取反
	}

};

#endif // !IPV4_DTAT_
