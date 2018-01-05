#ifndef __SAL_SELECT_H__
#define __SAL_SELECT_H__


#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif

#include "sal_standard.h"

typedef int (*completeness_cb)(void* pData, int DataLen, int* _ps32CompleteLen);

/*
 �� �� ��: select_init
 ��������: ��ʼ��selectģ��
 �������: complete ���һ�����ݰ��Ƿ�����
            cache_size ���ջ���Ĵ�С
            fd �ļ�������
 �������: ��
 �� �� ֵ: �ɹ����ؾ��,ʧ�ܷ���NULL
*/
handle select_init(completeness_cb complete, int cache_size, int fd);

/*
 �� �� ��: select_destroy
 ��������: ȥ��ʼ��selectģ��
 �������: hndselect selectģ����
 �������: ��
 �� �� ֵ: �ɹ�����0,ʧ�ܷ���С��0
*/
int select_destroy(handle hndselect);

/*
 �� �� ��: select_rw
 ����������select �����д����Ҫѭ������
 �������: hndselect selectģ����
 �������: ��
 �� �� ֵ: �ɹ�����0,ʧ�ܷ���С��0
*/
int select_rw(handle hndselect);

/*
 �� �� ��: select_wtimeout
 ��������: д��ʱʱ��
 �������: hndselect selectģ����
 �������: ��
 �� �� ֵ: �ɹ�����д��ʱʱ�䣨���룩,ʧ�ܷ���С��0
*/
int select_wtimeout(handle hndselect);

/*
 �� �� ��: select_rtimeout
 ��������: ����ʱʱ��
 �������: hndselect selectģ����
 �������: ��
 �� �� ֵ: �ɹ����ض���ʱʱ�䣨���룩,ʧ�ܷ���С��0
*/
int select_rtimeout(handle hndselect);

/*
 �� �� ��: select_send
 ��������: �������ݣ��˺�����ʱ���أ���������
 �������: hndselect selectģ����
            pData ����
            DataLen ���ݴ�С
 �������: ��
 �� �� ֵ: �ɹ�����0,ʧ�ܷ���С��0
*/
int select_send(handle hndselect, void* pData, int DataLen);

/*
 �� �� ��: select_recv_get
 ��������: ��ȡ�Ѿ����������ݣ�������֮����select_recv_release
 �������: hndselect selectģ����
 �������:    data ����
            len ���ݴ�С
 �� �� ֵ: �ɹ�����0,ʧ�ܷ���С��0
*/
int select_recv_get(handle hndselect, void** data, int* len);

/*
 �� �� ��: select_recv_release
 ��������: ����ͨ��select_recv_get��ȡ��������
 �������: hndselect selectģ����
            data ����
            len ���ݴ�С
 �������: ��
 �� �� ֵ: �ɹ�����0,ʧ�ܷ���С��0
*/
int select_recv_release(handle hndselect, void** data, int* len);

/*
 �� �� ��: select_sentsize
 ��������: ��ȡ�Ѿ��������ݵ�����
 �������: hndselect selectģ����
 �������: ��
 �� �� ֵ: �ɹ�����0,ʧ�ܷ���С��0
*/
int select_sentsize(handle hndselect);

/*
 �� �� ��: select_readsize
 ��������: ��ȡ�Ѿ���ȡ���ݵ�����
 �������: hndselect selectģ����
 �������: ��
 �� �� ֵ: �ɹ�����0,ʧ�ܷ���С��0
*/
int select_readsize(handle hndselect);

/*
 �� �� ��: select_debug
 ��������: ʹ��selectģ��ĵ�����Ϣ
 �������: hndselect selectģ����
            enable ʹ�ܿ���
 �������: ��
 �� �� ֵ: �ɹ�����0,ʧ�ܷ���С��0
*/
int select_debug(handle hndselect, int enable);


int select_wlist_empty(handle hndselect);
int select_rlist_empty(handle hndselect);

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif

#endif
