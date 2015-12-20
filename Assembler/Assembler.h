//
//		Assembler class.  This is a container for all the components
//		that make up the assembler.
//
#pragma once 

#include "SymTab.h"
#include "Instruction.h"
#include "FileAccess.h"
#include "Errors.h"
#include "Emulator.h"

class Assembler {

public:
	Assembler(int argc, char *argv[]);
	~Assembler();

	// Pass I - establish the locations of the symbols
	void PassI();
	
	// Pass II - generate a translation
	void PassII();

	// Display the symbols in the symbol table.
	void DisplaySymbolTable() { m_symtab.DisplaySymbolTable(); }

	// Display the errors.
	void DisplayErrorMessages() { m_err.DisplayErrors();  }

	// Run emulator on the translation.
	void RunEmulator() { 
		if (m_err.IsEmpty()) { 
			m_emul.runProgram();
		}
		else {
			cout << endl <<"-----EMULATOR CANNOT BE STARTED UNTIL ERROR LIST IS EMPTY-----" << endl << endl; 
		}
	};

private:

	FileAccess m_faccess;	    // File Access object
	SymbolTable m_symtab;	// Symbol table object
	Instruction m_inst;	    // Instruction object
	Errors m_err;		//Error object
	Emulator m_emul;	// Emulator
};

