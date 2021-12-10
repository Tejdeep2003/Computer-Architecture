#include<bits/stdc++.h>
#include<math.h>

using namespace std;

long long int PC=0;
long long int memory[1000];
long long int MBR;
long long int MAR;
long long int IR;
long long int IBR;
long long int AC;
long long int MQ;
long long int run = 1;
int JUMP = 0;
int JUMP_RIGHT = 0;


void decode_execute_ins(long long int IR, long long int MAR)
{
	switch(IR)
	{
		case 0:
			{
				cout << "HALT" << endl;
				run = 0;
				break;
			}
		case 1:
			{
				AC = memory[MAR];
				cout << "LOAD M(x) function is activated" << endl;
				cout << AC << " is loaded to accumulator. " << endl;
				break;
			}
		case 2:
			{
				AC = -(memory[MAR]);
				cout << "LOAD -M(x) function is activated" << endl;
				cout << AC << " is loaded to accumulator. " << endl;
				break;
			}
		case 3:
			{
				if(memory[MAR]>=0)
					AC = memory[MAR];
				else
					AC = -(memory[MAR]);
				cout << "LOAD |M(x)| function is activated" << endl;
				cout << AC << " is loaded to accumulator. " << endl;;
				break;
			}
		case 4:
			{
				if(memory[MAR]>=0)
					AC = -(memory[MAR]);
				else
					AC = memory[MAR];
				cout << "LOAD -|M(x)| function is activated" << endl;
				cout << AC << " is loaded to accumulator. " << endl;
				break;
			}
		case 5:
			{
				AC = AC + memory[MAR];
				cout << "ADD M(x) function is activated" << endl;
				cout << "The resultant sum is " << AC << "." << endl;
				break;
			}
		case 6:
			{
				AC = AC - memory[MAR];
				cout << "SUB M(x) function is activated" << endl;
				cout << "The resultant difference is " << AC << "." << endl;
				break;
			}
		case 7:
			{
				if(memory[MAR]>=0)
					AC = AC + memory[MAR];
				else
					AC = AC - memory[MAR];
				cout << "ADD |M(x)| function is activated" << endl;
				cout << "The resultant sum is " << AC << "." << endl;
				break;
			}
		case 8:
			{
				if(memory[MAR]>=0)
					AC = AC - memory[MAR];
				else
					AC = AC + memory[MAR];
				cout << "SUB |M(x)| function is activated" << endl;
				cout << "The resultant difference is " << AC << "." << endl;
				break;
			}
		case 9:
			{
				MQ = memory[MAR];
				cout << "LOAD MQ,M(x) function is activated" << endl;
				cout << MQ << " is loaded to MQ " << endl;
				break;
			}
		case 10:
			{
				AC = MQ ;
				cout << "LOAD MQ function is activated" << endl;
				cout << AC << " is loaded to Accumulator" << endl;
				break;
			}
		case 11:
			{
				long long int TEMP = MQ*(memory[MAR]);
				long long int n1,n2;
				cout << MQ << " " << memory[MAR] << " " << TEMP << endl;
				n1 = (MQ & 0xfffff);
    			n2 = (memory[MAR] & 0xfffff);
				memory[MAR] /= 1048576;
				MQ /= 1048576;
				AC = memory[MAR]*MQ + (MQ*n2)/108576 + (memory[MAR]*n1)/1048576 + (n1*n2)/1099511627776;
				MQ = (TEMP % 1099511627776);
				cout << AC << " " << MQ << endl;
				cout << "MUL M(x) function is activated" << endl;
				cout << "Most significant bits of the multiplication result loaded into accumulator." << endl;
				cout << "And least significant bits stored in MQ register." << endl;
				break;
			}
		case 12:
			{
				MQ = AC / memory[MAR];   		
				AC = AC % memory[MAR];   		
				cout << "DIV M(x) function is activated" << endl;
				cout << "The resultant quotient of the division is " << MQ << " and remainder is " << AC << "." << endl;
				break;
			}
		case 13:
			{
				PC = MAR;
				JUMP = 1;
				cout << "JUMP M(x,0:19) function is activated" << endl;
				cout << "Next instruction is fetched from location " << PC << "." << endl;
				break;
			}
		case 14:
			{
				PC = MAR;
				JUMP_RIGHT = 1;
				JUMP = 1;
				cout << "JUMP M(x,20:39) function is activated" << endl;
				cout << "Next instruction is fetched from location " << PC << "." << endl;
				break;
			}
		case 15:
			{
				if(AC >= 0){
					PC = MAR;
					JUMP = 1;
					cout << "JUMP+ M(x,0:19) function is activated" << endl;
					cout << "Next instruction is fetched from location " << PC << "." << endl;
				}
				break;
			}
		case 16:
			{
				if(AC >= 0){
					PC = MAR;
					JUMP_RIGHT = 1;
					JUMP = 1;
					cout << "JUMP+ M(x,20:39) function is activated" << endl;
					cout << "Next instruction is fetched from location " << PC << "." << endl;
				}
				break;
			}
		case 18:
			{
				long long int TEMP = memory[MAR] % 1048576;
				memory[MAR] /= 4294967296;
				memory[MAR] *= 256;
				memory[MAR] += AC % 4096;
				memory[MAR] *= 1048576;
				memory[MAR] += TEMP;
				cout << "STOR M(x,8:19) function is activated" << endl;
				cout << "Left address field at M(x) are replaced by 12 rightmost bits of AC" << endl;
				break;
			}
		case 19:
			{
				memory[MAR] /= 4096;
				memory[MAR] *= 4096;
				memory[MAR] += AC % 4096;
				cout << "STOR M(x,28:39) function is activated" << endl;
				cout << "Right address field at M(x) are replaced by 12 rightmost bits of AC" << endl;
				break;
			}
		case 20:
			{
				AC = AC*2;
				cout << "LSH function is activated" << endl;
				cout << "Accumulator is left shifted by one bit." << endl;
				break;
			}
		case 21:
			{
				AC = AC/2;
				cout << "RSH function is activated" << endl;
				cout << "Accumulator is right shifted by one bit." << endl;
				break;
			}
		case 33:
			{
				memory[MAR] = AC;
				cout << "STOR M(x) function is activated" << endl;
				cout << "Transfered contents of accumulator to memory location " << MAR << "." << endl;
				break;
			}


	}


}


int fetch()
{
	int n;
	
	
	if(JUMP_RIGHT == 0)
	{
		MBR = memory[PC];
		cout << "The instruction in memory location of PC is sent to MBR." << endl;

		if( MBR >= 1048576 && MBR < 1099511627776 )
		{
			cout << "Left instruction is present." << endl;
		
			IR = MBR/4294967296;
			cout << "The opcode of left instruction is loaded into IR." << endl;
		
			MAR = (MBR/1048576)%4096;
			cout << "The address of the desired value is loaded into MAR." << endl;
		
			IBR = MBR % 1048576;
			cout << "Right instruction is loaded into MBR." << endl;

			if(run == 1)
			{
				PC += 1;
				cout << "PC is incremented." << endl;
			}

			cout << "The opcode is sent for decoding and followed by execution of the instruction." << endl;
			decode_execute_ins(IR,MAR);
			cout << "" << endl;

			if(JUMP == 0 && run == 1)
			{
				IR = IBR/4096;
				cout << "The opcode of right instruction is loaded into IR." << endl;

	
				MAR = IBR % 4096;
				cout << "The address of the desired value is loaded into MAR." << endl;
		
				cout << "The opcode is sent for decoding and followed by execution of the instruction." << endl;
				decode_execute_ins(IR,MAR);
				cout << "" << endl;
			}
			JUMP = 0;
		}
		else 
		{

			cout << "There is no left instruction." << endl;
		
			IR = MBR/4096;
			cout << "The opcode of right instruction is loaded into IR." << endl;
		
			MAR = MBR % 4096;
			cout << "The address of the desired value is loaded into MAR." << endl;

			if(run == 1)
			{
				PC += 1;
				cout << "PC is incremented." << endl;
			}

			cout << "The opcode is sent for decoding and followed by execution of the instruction." << endl;
			decode_execute_ins(IR,MAR);
			cout << "" << endl;
		}
	}
	else
	{
		if( MBR >= 1048576 && MBR < 1099511627776 )
		{
			MBR = (memory[PC]) % 1048576;
			cout << "The instruction in memory location of PC is sent to MBR." << endl;

			IR = MBR/4096;
			cout << "The opcode of right instruction is loaded into IR." << endl;

			MAR = MBR % 4096;
			cout << "The address of the desired value is loaded into MAR." << endl;

			if(run == 1)
			{
				PC += 1;
				cout << "PC is incremented." << endl;
			}

			cout << "The opcode is sent for decoding and followed by execution of the instruction." << endl;
			decode_execute_ins(IR,MAR);
			cout << "" << endl;
		}
		else
		{
			MBR = memory[PC];
			cout << "The instruction in memory location of PC is sent to MBR." << endl;

			IR = MBR/4096;
			cout << "The opcode of right instruction is loaded into IR." << endl;

			MAR = MBR % 4096;
			cout << "The address of the desired value is loaded into MAR." << endl;

			if(run == 1)
			{
				PC += 1;
				cout << "PC is incremented." << endl;
			}

			cout << "The opcode is sent for decoding and followed by execution of the instruction." << endl;
			decode_execute_ins(IR,MAR);
			cout << "" << endl;
		}
		JUMP_RIGHT = 0;
	}


	return 0;
}

int main()
{
	memory[0] = 0x090200B010;
	memory[1] = 0x0B03001040;
	memory[2] = 0x0C04000000;
	memory[3] = 0x0040000000;
	memory[32] = 1;
	memory[16] = 2;
	memory[48] = 3;
	memory[64] = 6;

	while(run)
	{
		fetch();
		
	}
}
