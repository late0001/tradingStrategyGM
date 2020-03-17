
#ifndef __NETTS_TW_H__
#define __NETTS_TW_H__

#include "Stockdrv.h"

#pragma pack(1)

typedef	STOCK_STRUCTEx TW_STOCK;
typedef CArray<TW_STOCK, TW_STOCK&> CTWStockArray;

//typedef struct _tw_stock_t
//{
//	BYTE	m_type;					// stock's type
//	char	m_code[6];				// stock code
//} TW_STOCK;

#define TW_MAGIC				0xFDFDFDFD
#define	TW_MAGIC_BYTE			0xFD
#define TW_LENGTH_LEN			8

typedef struct _tw_header_t
{
	DWORD m_magic;					// 0xFDFDFDFD
	char m_length[TW_LENGTH_LEN];	// length
	char m_end;						// always 0
} TW_HEADER;

typedef struct _tw_login_t
{
	TW_HEADER	m_header;			// tw header
	BYTE m_tag;						// 0x0A
	WORD m_name_len;				// name length
	char m_data[256];				// (NAME)(WORD m_passwd_len)(PASSWD)
} TW_LOGIN;

typedef struct _tw_ask_t
{
	TW_HEADER	m_header;			// tw header
	BYTE	m_tag1;					// second data type
	BYTE	m_tag2;					// data type
	BYTE	m_serial;				// request serial, max 0x7F
	BYTE	m_reserved;				// always 0x00
	SHORT	m_size;					// request data's size
	TW_STOCK	m_stocks[32];		// max 32 stocks
} TW_ASK;

typedef struct _tw_ans_t {
	TW_HEADER	m_header;			//
	BYTE	m_tag1;					// second data type
	BYTE	m_tag2;					// data type
	BYTE	m_serial;				// request serial, max 0x7f
	BYTE	m_reserved;				// always 0x00
	SHORT	m_size;					// request data's size
} TW_ANS;

typedef struct _tw_ans_init_t {
	BYTE	m_tag;					// = 0xfd
	CHAR	m_name[8];
	BYTE	m_type;
	CHAR	m_code[6];
	DWORD	m_lastclose;			// ���� 0.001
	DWORD	m_reserved2;
	CHAR	m_shortname[4];
} TW_ANS_INIT;

typedef struct _tw_ans_report_t {
	WORD	m_number;				// No.
	DWORD	m_volnow;				// ���֣���λΪ�ɣ�
	DWORD	m_open;					// 0.001
	DWORD	m_high;					// 0.001
	DWORD	m_low;					// 0.001
	DWORD	m_new;					// 0.001
	DWORD	m_volume;
	DWORD	m_amount;
	DWORD	m_buy1;					// 0.001
	DWORD	m_buy1vol;
	DWORD	m_buy2;					// 0.001
	DWORD	m_buy2vol;
	DWORD	m_buy3;					// 0.001
	DWORD	m_buy3vol;
	DWORD	m_sell1;				// 0.001
	DWORD	m_sell1vol;
	DWORD	m_sell2;				// 0.001
	DWORD	m_sell2vol;
	DWORD	m_sell3;				// 0.001
	DWORD	m_sell3vol;
	WORD	m_reserved;				// = 0x64 0x00
} TW_ANS_REPORT;

typedef struct _tw_detail_t {
	WORD	m_offset;
	DWORD	m_price;				// 0.001
	DWORD	m_volume;
	DWORD	m_buy;					// 0.001
	DWORD	m_sell;					// 0.001
} TW_DETAIL;

typedef struct _tw_minute_t {
	DWORD	m_data1;				// * 0.001 if price
	DWORD	m_data2;				// * 0.001 if price
} TW_MINUTE;

typedef struct _tw_ans_minute_t {
	TW_DETAIL	m_details[11];
	WORD	m_offset;
	DWORD	m_bargain;
	DWORD	m_outter;
	DWORD	m_innter;
	DWORD	m_open;					// 0.001
	DWORD	m_high;					// 0.001
	DWORD	m_low;					// 0.001
	DWORD	m_new;					// 0.001
	DWORD	m_volume;
	DWORD	m_amount;
	DWORD	m_buy1;					// 0.001
	DWORD	m_buy1vol;
	DWORD	m_buy2;					// 0.001
	DWORD	m_buy2vol;
	DWORD	m_buy3;					// 0.001
	DWORD	m_buy3vol;
	DWORD	m_sell1;				// 0.001
	DWORD	m_sell1vol;
	DWORD	m_sell2;				// 0.001
	DWORD	m_sell2vol;
	DWORD	m_sell3;				// 0.001
	DWORD	m_sell3vol;
	WORD	m_reserved;				// = 0x64 0x00
	TW_MINUTE	m_minutes[246];
} TW_ANS_MINUTE;

typedef struct _tw_ans_history_t {
	DWORD	m_date;					//����	Format is MMDDHHMM for 5min, Format is YYYYMMDD for day
	DWORD	m_open;					// 0.001
	DWORD	m_high;					// 0.001
	DWORD	m_low;					// 0.001
	DWORD	m_close;				// 0.001
	DWORD	m_volume;				// 100
} TW_ANS_HISTORY;

typedef	RCV_MULTISORT_STRUCTEx	TW_ANS_MULTISORT;

typedef struct _tw_ans_detail_t {
	WORD	m_offset;
	DWORD	m_price;				// 0.001
	DWORD	m_volume;
	DWORD	m_buy1;					// 0.001
	DWORD	m_sell1;				// 0.001
} TW_ANS_DETAIL;

/* INIT
	m_tag1 = 0x01
	m_tag2 = 0x01
	m_serial = 0x00
	m_size = 0x0007
	the next 7 bytes = 0xdc, 0xcc, 0x31, 0x01, 0x00, 0x00, 0x00
	the next is string:
		"E013.45D013.04D022.03D043.20xcs1.00.is2.00"
*/

/* REPORT
	m_tag1 = 0x00
	m_tag2 = 0x03
	m_size = ���������Ʊ����
	�ظ�m_size��TW_STOCK
*/

/* MINUTE
	m_tag1 = 0x01
	m_tag2 = 0x04
	m_size = 0x0001
	m_stocks = 1��stock
*/

/* HISTORY
	������Ʊ��ĵ�һ������:
		m_tag1 = 0x20�� 0x33��� 0x43ʮ��� 0x53��ʮ�� 00x63��ʮ�� 0x83�� 0x93��
		m_tag2 = 0x09
		m_size = �������ݸ���*-1
		m_stocks = 1��stock

	�����������ͺ�ĵ�һ������:
		m_tag1 = 0x11�� 0x31��� 0x41ʮ��� 0x51��ʮ�� 00x61��ʮ�� 0x81�� 0x91��
		m_tag2 = 0x09
		m_size = �������ݸ���*-1
		m_stocks = 1��stock

	��������:
		m_tag1 = 0x12�� 0x32��� 0x42ʮ��� 0x52��ʮ�� 00x62��ʮ�� 0x82�� 0x92�� 
		m_tag2 = 0x09
		m_size = �������ݸ���*-1
		m_stocks = 1��stock
*/

/* MULTISORT
	m_tag1 = 0x0a
	m_tag2 = 0x08
	m_size = �������ݸ���*-1��һ�������Ϊ ((WORD)-9)
	m_stocks[0].m_type = enum StockType
	m_stocks[0].m_code = 0x06 0x00 0xff 0x01 0x00 0x00
*/

/* DETAIL
	m_tag1 = 0x01
	m_tag2 = 0x02
	m_size = 0x0001
	m_stocks = 1��stock
*/

/* BASE
	m_tag1 = 0x05
	m_tag2 = 0x0b
	m_size = 0x0005
	m_stocks = 5��stock
*/

#pragma pack()

// return the real length of the constructed buffer, -1 means no enough memory
int ConstructLength(TW_HEADER& header, int len);
int ConstructLoginBuffer(BYTE* buffer, size_t maxlen, LPCTSTR lpszUser, LPCTSTR lpszPasswd);
int ConstructAskInitBuffer(TW_ASK& ask);
int ConstructAskReportBuffer(TW_ASK& ask, TW_STOCK* pStocks, size_t size);
int ConstructAskMinuteBuffer(TW_ASK& ask, TW_STOCK* pStock);
int ConstructAskHistoryBuffer(TW_ASK& ask, TW_STOCK* pStock, int nKType, int nDataCount, BOOL bChangeStock, BOOL bFirstRequest);
int ConstructAskMultisortBuffer(TW_ASK& ask, TW_STOCK* pStock);
int ConstructAskDetailBuffer(TW_ASK& ask, TW_STOCK* pStock);
int ConstructAskBaseBuffer(TW_ASK& ask, TW_STOCK* pStock);

size_t TryGetLength(TW_HEADER& header);
size_t TryGetLength(BYTE* buffer, size_t len);
BOOL IsLoginOK(BYTE* buffer, size_t len);
int TryGetInit(BYTE* buffer, size_t len, PRCV_DATA pRCV_DATA);
int TryGetReport(BYTE* buffer, size_t len, PRCV_DATA pRCV_DATA);
int TryGetMinute(BYTE* buffer, size_t len, PRCV_DATA pRCV_MINUTE, PRCV_DATA pRCV_REPORT);
int TryGetHistory(BYTE* buffer, size_t len, PRCV_DATA pRCV_DATA);
int TryGetMultisort(BYTE* buffer, size_t len, PRCV_DATA pRCV_DATA);
int TryGetDetail(BYTE* buffer, size_t len, PRCV_DATA pRCV_DATA);
int TryGetBase(BYTE* buffer, size_t len, PRCV_DATA pRCV_DATA);

#endif
