#pragma once
#include "stdafx.h"
#include "IT.h"
#include "LT.h"
#include "In.h"

void Up();
void Down();
void Generation(LT::LexTable &Lextable, In::StToken *tokens, IT::IdTable & idtable);
