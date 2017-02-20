/*          ISA-JNU69
                TEAM MEMBERS
                       Aditya Sharma 14UCS007
                       Anshul Goyal  14UCS020
                       Vinod Sharma  14UCC042
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#define M 70
#include "define.c"

int flag=0;

void Error_Msg()
{
	fprintf(stdout,"Error in Previous Line\n");
}
char* ChkInputValuesTwoAdd(FILE *f1,char *str1)
{
	if(str1[0]=='$')
	{
		if(strcmp(ChkVal(str1+1),"-1")==0)
        {                                   // No Range should be from [0 to 128)
            flag=1;
            return NULL;
        }
        else
            return ChkVal(str1+1);
	}
	else if(strcmp(ChkReg(str1),"-1")!=0)
			return ChkReg(str1);
	else
    {
        flag=1;
        return NULL;
    }
}
char* ChkInputValuesOneAdd(FILE *f1,char *str1)
{
	if(strcmp(ChkReg(str1),"-1")!=0)
			return ChkReg(str1);
	else
    {
        flag=1;
        return NULL;
    }
}

char* ChkInputValuesLabel(FILE *f1,char *str1)
{
    if(strcmp(ChkLabel(str1),"-1")!=0)
			return ChkLabel(str1);
	else
    {
        flag=1;
        return NULL;
    }
}
void TakeInput(FILE *f1,FILE *f2)
{
	char str1[M],str2[M],str3[M],str4[M],str5[M],str6[M],*str_t1,*str_t2,val1[M],val2[M];
    int count =0,tmp;
	do{
        flag=0;
		fscanf(stdin,"%s",str1);

		strcpy(str2,ChkTwoAddress(str1));
		strcpy(str3,ChkOneAddress(str1));
		strcpy(str4,ChkZeroAddress(str1));
		strcpy(str5,ChkOneAddandlabel(str1));
		strcpy(str6,ChkLabel(str1));

		if(strcmp(str2,"-1")!=0)
		{
			fscanf(stdin,"%s %s",val1,val2);
			str_t1=ChkInputValuesTwoAdd(f1,val1);
			str_t2=ChkInputValuesTwoAdd(f1,val2);
			if(flag==1)
            {
                Error_Msg();
            }
            else
            {
                fprintf(f1,"0000000000000%s%s%s",ChkTwoAddress(str1),str_t1,str_t2);
                fprintf(f1,"\n");
                count++;
            }
		}
		else if(strcmp(str3,"-1")!=0)
		{
			fscanf(stdin,"%s",val1);
			str_t1=ChkInputValuesOneAdd(f1,val1);

			if(flag==1)
            {
                Error_Msg();
            }
            else
            {
                fprintf(f1,"0000000000000%s%s",ChkOneAddress(str1),str_t1);
                fprintf(f1,"\n");
                count++;
            }
		}
		else if(strcmp(str4,"-1")!=0)
		{
			fprintf(f1,"0000000000000%s",ChkZeroAddress(str1));
			fprintf(f1,"\n");
			count++;
		}
		else if(strcmp(str5,"-1")!=0)
		{
			fscanf(stdin,"%s",val1);
			str_t1=ChkInputValuesLabel(f1,val1);
			if(flag==1)
            {
                Error_Msg();
            }
            else
            {
                fprintf(f1,"0000000000000%s%s",ChkOneAddandlabel(str1),str_t1);
                fprintf(f1,"\n");
                count++;
            }
		}
		else if(strcmp(str6,"-1")!=0)
		{
		    tmp=count+1;
			fprintf(f2,"%d %s %s",tmp,ChkLabel(str1),str1);
			fprintf(f2,"\n");
		}
		else
		{
			gets(val1);
			Error_Msg();
		}

	}while(strcmp(str1,"HLT")!=0);
	}
int main()
{
	FILE *f1,*f2;
	f1=fopen("machinecode.txt","w");
	f2=fopen("symbol.txt","w");
	TakeInput(f1,f2);
	fclose(f1);
	fclose(f2);
	return 0;
}

