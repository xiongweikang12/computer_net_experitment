#ifndef IPV4_DATA_
#define IPV4_DATA_
#include <winsock.h>
#include <string.h>
#include "type_error.h"

struct ipv4
{
	char version_ihl; //ip�汾��
	char type_of_service; //���ַ���
	short total_length; //�ܳ���
	short identification; //��ʶ
	short fragment_offset; //ƫλ��
	char time_to_live; //TTl
	char protocol;    //Э��
	short header_checksum; //�ײ������
	unsigned int  source_adress; //Դ��ַ
	unsigned int  destination_adress; //Ŀ�ĵ�ַ
	ipv4() { memset(this, 0, sizeof(ipv4)); }
	//��ʼ������ֵȫΪ0�����캯��1
	ipv4(unsigned int len, unsigned int srcadress,
		unsigned int desadress, char _protocol, char ttl)
	{
		memset(this, 0, sizeof(ipv4));
		version_ihl = 0x45;
		total_length = htons(len + 20);
		//�����غɳ��ȼ���20λip�ײ�
		time_to_live = ttl;
		protocol = _protocol;
		source_adress = htonl(srcadress);
		destination_adress = htonl(desadress);
		//htons 16λ short
		//htonl 32λ long

		char* ptrBuffer;
		memcpy(ptrBuffer, this, sizeof(ipv4));
		int sum = 0;
		for (int i = 0; i < 10; i++) {
			if (i= !5) {
				sum += (int)((unsigned char)ptrBuffer[i * 2])<< 8;
				sum += (int)((unsigned char)ptrBuffer[i * 2 + 1]);
				//ptrBuffer value_type Ϊchar 1�ֽ� 8bit
				//��һ��16 ��Ϊ ����8bit ,��ǰ��һ���ĺ��λ��8λ���ƶ�����8λ
				//�ϳ�һ��16
				//��ӣ����� 10~12�ֽ�
			}
		}
		while ((sum & 0xffff0000) != 0) {
			sum = (sum & 0xffff) + ((sum >> 16) & 0xffff);
			//���ڶ��16bit��Ӳ����˽�λ����ԭ��16bit 
			// 322C4 0003 + 22C4 = 22C7
			//sum &0xffff �õ���16λ
			//(sum>>16)&0xffff ����16λת����16λ ȡ��
			//���
		}
		unsigned short int ssum = sum; //int ->short ,32->16
		header_checksum = ~ssum; //ȡ��
	}

};

#endif // !IPV4_DTAT_
