#include<bits/stdc++.h>
using namespace std;
unordered_map<int,string>display_content;
unordered_map<string,int>address_data; //can be value or instruction
unordered_map<int,string>address_instruction;
string starting_address="";
int next_address,end_address;
int A=0,B=0,C=0,D=0,E=0,H=0,L=0;
bool SF=0,ZF=0,AC=0,PF=0,CF=0;
#include"Mnemonics.cpp"
#include"utility.cpp"
#include"Arithmetic.cpp"
#include"Branching.cpp"
#include"Load_and_Store.cpp"
#include"Logical.cpp"

int main()
{
	bool check=1;
	int bit_operation;
	while(check==1)
	{
		check=0;
		cout<<"Enter 16 for 16bit operation or 8 for 8bit operation\n";
		cin>>bit_operation;
		if(bit_operation==16)break;
		if(bit_operation==8)break;
		cout<<"Bit operation not found! Enter a valid bit operation\n";	
		check = 1;
	}

	check=1;
	while(check==1)
	{
		check=0;
		cout<<"Enter the starting address between 0000H-FFFFH\n";
		cin>>starting_address;
		if(starting_address.size()!=5)
		{
			cout<<"Enter a 4 digit address Ex:- 1010H\n";
			check=1;
		}
		else
		{
			for(int i=0;i<4;++i)
			{
				if(char_to_int.find(starting_address[i])==char_to_int.end())
				{
					cout<<"Enter a valid address\n";
					check=1;break;
				}
			}
		}
	}
	starting_address.pop_back();
	next_address = dec_to_hex(starting_address);

	while(true)
	{
		check=1;
		string user_instruction,mne;
		int n,i;
		while(check==1)
		{
			check = 0;
			mne="";
			cout<<"Enter a Instruction\n";
			getline(cin>>ws,user_instruction);
			for(auto i:user_instruction)i=toupper(i);
			i=0;
			while(i<user_instruction.size() &&  user_instruction[i]!=' ')
			{
				mne.push_back(user_instruction[i]);
				++i;
			}
			if(mnemonics.find(mne)==mnemonics.end())
			{
				cout<<"Instruction not found\nRe-enter correct Instruction or type HELP for debugger\n";
				check=1;
			}
		}
		if(mnemonics[mne]==27)break;
		address_instruction[next_address] = user_instruction;
		next_address+=mnemonics[mne].second-'0';
	}

	bool EOF =0,ERROR = 0;
	end_address = next_address;
	next_address = hex_to_dec(starting_address);
	fstream display_content;
	display_content.open("display_content.txt",ios::out); 
	while(next_address<=end_address)
	{
		if(address_instruction.find(next_address)!=address_instruction.end())
		{
			string user_instruction = address_instruction[next_address];
			string temp_address = dec_to_hex(next_address);
			if(temp_address.size()!=4)
			{
				string temp;
				for(i=0;i<4-temp_address.size())temp.push_back('0');
				temp+=temp_address;
				temp_address=temp;
			}
			display_content<<temp_address+"H  ";
			display_content<<user_instruction+"  ";


			int instruction_id = mnemonics[mne].first;
			switch(instruction_id)
			{
				case 1:
						ADD(user_instruction); // ADD B
						break;
				case 2:
						ADI(user_instruction); // ADI 15H
						break;
				case 3:
						DAD(user_instruction); // DAD B
						break;
				case 4:
						DCR(user_instruction); // DCR B
						break;
				case 5:
						DCX(user_instruction);
						break;
				case 6:
						INR(user_instruction); // INR B 
						break;
				case 7:
						INX(user_instruction);
						break;
				case 8:
						SUB(user_instruction); // SUB A
						break;
				case 9:
						SUI(user_instruction); // SUI 05H
						break;
				case 10:
						SET(user_instruction); // SET 2500, 05H || SET 2500, 0585H
						break;
				case 11:
						ERROR = JMP(user_instruction);
						break;
				case 12:
						if(CF)ERROR = JC(user_instruction,next_address);
						break;
				case 13:
						if(!CF)ERROR = JNC(user_instruction,next_address);
						break;
				case 14:
						if(ZF)ERROR = JZ(user_instruction,next_address);
						break;
				case 15:
						if(!ZF)ERROR = JNZ(user_instruction,next_address);
						break;
				case 16:
						MOV(user_instruction); // MOV A, B
						break;
				case 17:
						MVI(user_instruction); // MOV A, 54H
						break;
				case 18:
						LXI(user_instruction); // LXI H, 5050H
						break;
				case 19:
						LDA(user_instruction);
						break;
				case 20:
						STA(user_instruction);
						break;
				case 21:
						LHLD(user_instruction);
						break;
				case 22:
						SHLD(user_instruction);
						break;
				case 23:
						STAX(user_instruction);
						break;
				case 24:
						XCHG(user_instruction); // XCHG
						break;
				case 25:
						CMA(); // CMA
						break;
				case 26:
						CMP(user_instruction); // CMP B
						break;
				case 27:
						end_address = next_address;
						EOF = 1;
						break;
				/*case 28:
						HELP(user_instruction);
						break;
				*/default:
						cout<<"You found a bug\n";
			}

			if(EOF)break;
			SF=0,ZF=0,AC=0,PF=0,CF=0;
			display_content<<to_string(SF)+" "+to_string(ZF)+" "+to_string(AC)+" "+to_string(PF)+" "+to_string(CF)+"  ";

			int A=0,B=0,C=0,D=0,E=0,H=0,L=0;
			display_content<<dec_to_hex(A)+"H"+" ";
			display_content<<dec_to_hex(B)+"H"+" ";
			display_content<<dec_to_hex(C)+"H"+" ";
			display_content<<dec_to_hex(D)+"H"+" ";
			display_content<<dec_to_hex(E)+"H"+" ";
			display_content<<dec_to_hex(H)+"H"+" ";
			display_content<<dec_to_hex(L)+"H"+"\n";

			next_address+=mnemonics[mne].second-'0';
		}
		else ERROR = 1;
		if(ERROR)break;
	}
	display_content.close();
	if(ERROR)cout<<"ERROR occured!";
	else 
	{
		display_content.open("display_content.txt",ios::in); //open a file to perform read operation using file object
	   if(display_content.is_open()) //checking whether the file is open
	   {   
	      string tp;
	      while(getline(display_content, tp)){ //read data from file object and put it into string.
	         cout << tp << "\n"; //print the data of the string
	      }
	      display_content.close(); //close the file object.
	   }
	}
	return 0;
}
