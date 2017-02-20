#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

char* dec_binary(int num)
{
    int k,c;
    char *binary=(char *)malloc(sizeof(char)*7);
    for (c = 6; c >= 0; c--)
    {
        k = num >> c;

        if (k & 1)
          binary[6-c]='1';
        else
          binary[6-c]='0';
    }
    return binary;

}

char* ChkTwoAddress(char *st)
{

	if(strcmp(st,"MOV")==0)
		return "00000";

	else if(strcmp(st,"MOVI")==0)       // %%%I Means Immediate value
		return "00001";

	else if(strcmp(st,"ADD")==0)
		return "00010";

	else if(strcmp(st,"ADDI")==0)
		return "00011";

	else if(strcmp(st,"SUB")==0)
		return "00100";

	else if(strcmp(st,"SUBI")==0)
		return "00101";

	else if(strcmp(st,"TEST")==0)
		return "00110";

	else if(strcmp(st,"TESTI")==0)
		return "00111";

	else if(strcmp(st,"CMP")==0)
		return "01000";

	else if(strcmp(st,"CMPI")==0)
		return "01001";

	else if(strcmp(st,"CMPII")==0)
		return "01010";

    else if(strcmp(st,"AND")==0)
		return "01011";

    else if(strcmp(st,"ANDI")==0)
		return "01100";

    else if(strcmp(st,"MUL")==0)
		return "01101";

    else if(strcmp(st,"MULI")==0)
		return "01110";

    else if(strcmp(st,"DIV")==0)
		return "01111";

    else if(strcmp(st,"DIVI")==0)
		return "10000";

    else if(strcmp(st,"SAR")==0)
		return "10001";

    else if(strcmp(st,"SAL")==0)
		return "10010";


	else return "-1";

}


char * ChkOneAddress(char *st)
{
	if(strcmp(st,"PUSH")==0)
		return "100110000000";

	else if(strcmp(st,"POP")==0)
		return "100110000001";

	else if(strcmp(st,"SCAN")==0)
		return "100110000010";

	else if(strcmp(st,"PRINT")==0)
		return "100110000011";

	else return "-1";
}
char * ChkOneAddandlabel(char *st)
{
	 if(strcmp(st,"JNE")==0)
		return "1001100001000000";

	else if(strcmp(st,"JMP")==0)
		return "1001100001000001";

	else if(strcmp(st,"JNS")==0)
		return "1001100001000010";

	else if(strcmp(st,"JG")==0)
		return "1001100001000011";


	else return "-1";
}


char * ChkZeroAddress(char * st)
{
	if(strcmp(st,"HLT")==0)
		return "1001100001000100000";

	else if(strcmp(st,"NOP")==0)
		return "1001100001000100001";

	else return "-1";

}


char * ChkReg(char *st)
{
	if(strcmp(st,"R00")==0)
		return "0000000";

	else if(strcmp(st,"R01")==0)
		return "0000001";

	else if(strcmp(st,"R02")==0)
		return "0000010";

	else if(strcmp(st,"R03")==0)
		return "0000011";

	else if(strcmp(st,"R04")==0)
		return "0000100";

	else if(strcmp(st,"R05")==0)
		return "0000101";

	else if(strcmp(st,"R06")==0)
		return "0000110";

	else if(strcmp(st,"R07")==0)
		return "0000111";

	else if(strcmp(st,"R08")==0)
		return "0001000";

	else if(strcmp(st,"R09")==0)
		return "0001001";

	else if(strcmp(st,"R10")==0)
		return "0001010";

	else if(strcmp(st,"R11")==0)
		return "0001011";

	else if(strcmp(st,"R12")==0)
		return "0001100";

	else if(strcmp(st,"R13")==0)
		return "0001101";

	else if(strcmp(st,"R14")==0)
		return "0001110";

	else if(strcmp(st,"R15")==0)
		return "0001111";

	else
		return "-1";
}


char * ChkLabel(char *st)
{
	if(strcmp(st,"L00")==0)
		return "000";

	else if(strcmp(st,"L01")==0)
		return "001";

	else if(strcmp(st,"L02")==0)
		return "010";

	else if(strcmp(st,"L03")==0)
		return "011";

	else if(strcmp(st,"L04")==0)
		return "100";

	else if(strcmp(st,"L05")==0)
		return "101";

	else if(strcmp(st,"L06")==0)
		return "110";

	else if(strcmp(st,"L07")==0)
		return "111";

    else
        return "-1";

}


char  *ChkVal(char *st)
{
	if(atoi(st)>=0 && atoi(st)<128)
		return dec_binary(atoi(st));
		else
        {
            return "-1";
        }
}


