#pragma once

#include "stdafx.h"

#define ID_MAXSIZE	10				//���� ����� �������� ��������������
#define ID_FOR_IT   11              //���� ����� �������� ������������� + �������������� �-��
#define TI_MAXSIZE	4096			//���� ����� ���������� ����� � ������� ���������������
#define TI_INT_DEFAULT	0x00000000	//�������� �� ��������� ��� int
#define TI_STR_DEFAULT	0x00		//�������� �� ��������� ��� sting
#define TI_NULLIDX		0xffffffff	//��� �������� ������� ���������������
#define TI_STR_MAXSIZE		255
#define INT_MAXSIZE     65536
#define INT_MINUS_MAXSIZE   -65536

namespace IT
{
	enum IDDATATYPE { NUM = 1, WRD = 2 };			//���� ������ ���������������
	enum IDTYPE { V = 1, F = 2, P = 3, L = 4, S = 5 };	//���� ���������������: ����������, �������, ��������, �������, ����������� �������

	struct Entry
	{
		int	idxfirstLE;						//������ � ������� ������		
		char		id[ID_FOR_IT];					//�������������, ��������� ��������� �� ID_MAXSIZE
		IDDATATYPE	iddatatype;						//��� ������
		IDTYPE		idtype;							//��� ��������������
		union
		{
			int	vNUM;            	//�������� integer
			struct
			{
				int len;							//���������� �������� � string
				char str[TI_STR_MAXSIZE - 1];		//������� string
			}vWRD;									//�������� string
		}value;	//�������� ��������������
		Entry()
		{
			this->value.vNUM = TI_INT_DEFAULT;
			this->value.vWRD.len = NULL;
		};
		Entry(char* id, int idxLT, IDDATATYPE datatype, IDTYPE idtype)
		{
			strncpy_s(this->id, id, ' ');
			this->idxfirstLE = idxLT;
			this->iddatatype = datatype;
			this->idtype = idtype;
		};
	};
	struct IdTable		//��������� ������� ���������������
	{
		int maxsize;	//������� ������� ��������������� < TI_MAXSIZE
		int size;		//������� ������ ������� ��������������� < maxsize
		Entry* table;	//������ ����� ������� ���������������
	};

	IdTable Create(int size = NULL);	//������� ������� ��������������� < TI_MAXSIZE

	void Add(					//�������� ������ � ������� ���������������
		IdTable &idtable,		//��������� ������� ���������������
		Entry entry);			//������ ������� ��������������� 

	int IsId(					//�������: ����� ������(���� ����), TI_NULLIDX(���� ����)
		IdTable &idtable,		//��������� ������� ���������������
		char id[ID_MAXSIZE]);	//�������������

	void SetValue(IdTable &idtable, int, char*);//������ �������� ��������������
}