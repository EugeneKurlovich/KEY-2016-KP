#include "Generation.h"

ofstream fout("D://LAST//KP//KEY-2016//Debug//Generation.html");
void Up()
{
	fout << "<html>" << endl;
	fout << "<head>" << endl;
	fout << "<style>" << endl;
	fout << "#b {background-color: black;font-family:" << '"' << "Consolas" << '"' << "; color: #D7D8DE;font-size: 16px;height: 565px;margin: 0;padding: 5px;}" << endl;
	fout << "#a {background-color: white;color: black;font-family:" << ' "' << "Arial" << '"' << ";font-size: 12px;border: 1px solid black;padding: 1px 2px 1px 10px;margin: 0;}" << endl;
	fout << "</style>" << endl;
	fout << "</head>" << endl;
	fout << "<body>" << endl;
	fout << "<div id=" << '"' << "a" << '"' << "><p>Командная строка </p>	</div> " << endl;
	fout << "<div id=" << '"' << "b" << '"' << ">" << endl;
	fout << "<script src=" << '"' << "MyJSlibrary.js" << '"' << "></script>" << endl;
	fout << "<script>" << endl;
}


void Down()
{
	fout << "</script>" << endl;
	fout << "</div>" << endl;
	fout << "</body>" << endl;
	fout << "</html>" << endl;
	fout.close();
}


void Generation(LT::LexTable &Lextable, In::StToken *tokens, IT::IdTable & idtable)
{
	Up();
	for (int i = 0; i < Lextable.size; i++)
	{
		switch (Lextable.table[i].lexema)
		{
		case LEX_LEFTBRACE:
		{
			fout << "{" << endl;
			break;
		}
		case  LEX_CREATE:
		{
			fout << "var";
			break;
		}
		case LEX_ID:
		{
			int y;
			y = Lextable.table[i].idxTI;
			if (Lextable.table[i-2].lexema == LEX_OUT)
			{
				if (idtable.table[y].iddatatype == IT::NUM)
					fout << "Math.floor(" << idtable.table[y].id << ")";
				else
					fout << idtable.table[y].id;
			}
			else if (idtable.table[y].iddatatype == IT::WRD || IT::NUM && Lextable.table[i - 2].lexema != LEX_OUT)
			{
				fout << idtable.table[y].id;
			}

			break;
		}
		case LEX_SEPARATOR:
		{
			fout << ";" << endl;
			break;
		}
		case  LEX_EQUAL:
		{
			fout << "=";
			break;
		}
		case LEX_LITERAL:
		{
			int toInt;
			toInt = atoi(tokens[i].token);
			if (toInt > INT_MAXSIZE )
			{
				toInt = INT_MAXSIZE;
				fout << toInt;
				break;
			}
			if (toInt < INT_MINUS_MAXSIZE)
			{
				toInt = INT_MINUS_MAXSIZE;
				fout << toInt;
				break;
			}
				fout << tokens[i].token;
			break;
		}
		case LEX_ID_TYPE:
		case SPACE: 
		{
			fout << " ";
			break;
		}
		case LEX_LIBRARY:
		{
			fout << "document.write('<br />');" << endl;
			fout << "document.write('Included MATHEMATIC library')";
			break;
		}
		case LEX_OUT:
		{
			fout << "document.write('<br />');" << endl;
			fout << "document.write";
			break;
		}
		case LEX_LEFTHESIS:
		{
			fout << "(";
			break;
		}
		case LEX_RIGHTTHESIS:
		{
			fout << ")";
			break;
		}
		case LEX_END:
		{
			fout << "document.write('<br />');" << endl;
			fout << "document.write('Programm is End')" ;
			break;
		}
		case LEX_BRACELET:
		{
			fout << "}" << endl;
			break;
		}
		case tochka:
		{
			fout << endl;
			break;
		}
		case LEX_PLUS:
		{
			fout << "+";
			break;
		}
		case LEX_STAR:
		{
			fout << "*";
			break;
		}
		case LEX_MINUS:
		{
			fout << "-";
			break;
		}
		case LEX_DIRSLASH:
		{
			fout << "/";
			break;
		}
		case LEX_FUNCTION:
		{
			fout << "function ";
			break;
		}
		case LEX_COMMA:
		{
			fout << ",";
			break;
		}
		case LEX_RETURN:
		{
			fout << "return ";
			break;
		}

		case LEX_KOREN:
		{
			fout << "koren";
			break;
		}
		case LEX_STEP:
		{
			fout << "step";
		
			break;
		}
		}
	}
	Down();
}