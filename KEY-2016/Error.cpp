#include "stdafx.h"
#include "Error.h"

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "[SYSTEM] ������������ ��� ������"), 
		ERROR_ENTRY(1, "[SYSTEM] ��������� ����"), 
		ERROR_ENTRY(2, "[SYSTEM] �������� -in ������ ���� �����"), 
		ERROR_ENTRY(3, "[SYSTEM] ��������� ����� �������� ���������"), 
		ERROR_ENTRY(4, "[SYSTEM] ������ ��� �������� ����� � �������� �����(-in)"), 
		ERROR_ENTRY(5, "[SYSTEM]������ ��� �������� ����� ���������(-log)"), 
		ERROR_ENTRY(6, "[SEMANTIC] ���������� ������� �������"), 
		ERROR_ENTRY(7, "[LEX] ������� ���������������"), 
		ERROR_ENTRY(8, "[LEX] ���������� ��������������� �����������"), 
		ERROR_ENTRY(9, "[LEX] ������������ ������ � �������� ����� (-in)"), 
		ERROR_ENTRY(10, "[SEMANTIC] ���������� ������ ������� �������"),
		ERROR_ENTRY(11, "[SEMANTIC] �������������� �����"), 
		ERROR_ENTRY(12, "[SEMANTIC] ��������� ����������� �������� �������"), 
		ERROR_ENTRY(13, "[SEMANTIC] word ������������� - �������� ������� ���������� MATHEMATIC"),
		ERROR_ENTRY(14, "[LEX] �������� ������ ������� ������"), 
		ERROR_ENTRY(15, "[SYNTAX] �������� ��������� ���������"), 
		ERROR_ENTRY(16, "[SYNTAX] ������ � ���������� ������� "), 
		ERROR_ENTRY(17, "[SYNTAX] ��������� ��������"), 
		ERROR_ENTRY(18, "[SYNTAX] ������ � ���������"), 
		ERROR_ENTRY(19, "[SYNTAX] ������ � ���������� ���������� �������"), 
		ERROR_ENTRY(20, "[SYNTAX] ������ � ���������� ���������"), 
		ERROR_ENTRY(21, "[SEMANTIC] ������������� ���������� ������� ��� ����������� ����������"),  
		ERROR_ENTRY(22, "[SEMANTIC] ������� ������������� �������� ������������ ����� ����� ����������������"),  
		ERROR_ENTRY(23, "[IN] ���������� ����������� �������, ������ ����������"),  
		ERROR_ENTRY(24, "[IN] ��������� ����� ���������� ��������"),  
		ERROR_ENTRY(25, "[SEMANTIC] �������������� ���������� � �������"), 
		ERROR_ENTRY(26, "[SEMANTIC] ���������� word �������������� � �������������� ���������"), 
		ERROR_ENTRY(27, "[LEX] ������������ �������"), 
		ERROR_ENTRY(28, "[SEMANTIC] �������� ���������� ���������� ��� ������ �������"), 
	};



	ERROR GetError(int id)
	{
		if (id < 0 || id > ERROR_MAX_ENTRY)
			return errors[0];
		else
			return errors[id];
	}

	ERROR GetError(int id, int line, int cells)
	{
		ERROR dopError = GetError(id);
		dopError.position.cells = cells;
		dopError.position.line = line;
		return dopError;
	}
}