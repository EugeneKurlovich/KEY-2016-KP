#include "stdafx.h"
#include "Error.h"

namespace Error
{
	ERROR errors[ERROR_MAX_ENTRY] =
	{
		ERROR_ENTRY(0, "[SYSTEM] Недопустимый код ошибки"), 
		ERROR_ENTRY(1, "[SYSTEM] Системный сбой"), 
		ERROR_ENTRY(2, "[SYSTEM] Параметр -in должен быть задан"), 
		ERROR_ENTRY(3, "[SYSTEM] Превышена длина входного параметра"), 
		ERROR_ENTRY(4, "[SYSTEM] Ошибка при открытии файла с исходным кодом(-in)"), 
		ERROR_ENTRY(5, "[SYSTEM]Ошибка при создании файла протокола(-log)"), 
		ERROR_ENTRY(6, "[SEMANTIC] Отсутствие главной функции"), 
		ERROR_ENTRY(7, "[LEX] Попытка переопределения"), 
		ERROR_ENTRY(8, "[LEX] Отсуствует предварительное определение"), 
		ERROR_ENTRY(9, "[LEX] Недопустимый символ в исходном файле (-in)"), 
		ERROR_ENTRY(10, "[SEMANTIC] Обнаружена вторая главная функция"),
		ERROR_ENTRY(11, "[SEMANTIC] Несоответствие типов"), 
		ERROR_ENTRY(12, "[SEMANTIC] Запрещено присваивать значение функции"), 
		ERROR_ENTRY(13, "[SEMANTIC] word идентификатор - параметр функции библиотеки MATHEMATIC"),
		ERROR_ENTRY(14, "[LEX] Превышен размер таблицы лексем"), 
		ERROR_ENTRY(15, "[SYNTAX] Неверная структура программы"), 
		ERROR_ENTRY(16, "[SYNTAX] Ошибка в параметрах функции "), 
		ERROR_ENTRY(17, "[SYNTAX] Ошибочный оператор"), 
		ERROR_ENTRY(18, "[SYNTAX] Ошибка в выражении"), 
		ERROR_ENTRY(19, "[SYNTAX] Ошибка в параметрах вызываемой функции"), 
		ERROR_ENTRY(20, "[SYNTAX] Ошибка в построении выражения"), 
		ERROR_ENTRY(21, "[SEMANTIC] Использование встроенной функции без подключения библиотеки"),  
		ERROR_ENTRY(22, "[SEMANTIC] Попытка использования операции присваивания между двумя идентификаторами"),  
		ERROR_ENTRY(23, "[IN] Отсутствие закрывающей ковычки, ошибка исправлена"),  
		ERROR_ENTRY(24, "[IN] Превышена длина строкового литерала"),  
		ERROR_ENTRY(25, "[SEMANTIC] Несоответствие параметров в функции"), 
		ERROR_ENTRY(26, "[SEMANTIC] Обнаружены word идентификаторы в математическом выражении"), 
		ERROR_ENTRY(27, "[LEX] Неопознанный элемент"), 
		ERROR_ENTRY(28, "[SEMANTIC] Неверное количество параметров при вызове функции"), 
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