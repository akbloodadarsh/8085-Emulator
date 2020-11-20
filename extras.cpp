#include <bits/stdc++.h>
using namespace std;

void help()
{
	cout << "Arithmetic Instructions\nADD Ex:- ADD B\nADI Ex:- ADI 45H\nSUI Ex:- SUI 24H\nSUB Ex:- SUB D\nDCR Ex:- DCR A\nINR Ex:- INR B\nINX Ex:- INX B\n		DCX Ex:- DCX B\n		DAD Ex:- DAD B\n\nLogical Instructions\n		CMA Ex:- CMA\n		CMP Ex:- CMP B\n\n		Branching Instructions\n		JMP Ex:- JMP 4000H\n		JC Ex:- JC 4000H\n		JNC Ex:- JNC 5000H\n		JZ Ex:- JZ 8000H\n\n		Load and Store Instructions\n		MOV Ex:- MOV B, A\n		MVI Ex:- MVI A, 54H\n		LDA Ex:- LDA 4000H\n		STA Ex:- STA 4000H\n		SHLD Ex:- 4000H\n		LHLD Ex:- LHLD 5000H\n		XCHG Ex:- XCHG\nLXI Ex:- LXI H, 4000H\nSTAX Ex:- STAX B\n\n";
}

void help_debug()
{
	cout << "SET Ex:- SET 2500H, 05H\n	break or b Ex:- break 2500H or b 2500H\n	step or s Ex:- step or s\n	print or p Ex:- print A or p B or print 2500H or p 5000H\n	quit or q Ex:- quit or q\n	help Ex:- help\n\n";
}
