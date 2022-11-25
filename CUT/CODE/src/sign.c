/***************************************************************************************************
 * * FILENAME : sign.c
 *
 * * DESCRIPTION : This file defines required function to perform given options  on input array
 *
 * * REVISION HISTORY:
 * * DATE              NAME                       REFERENCE                    		   REASON
 * * --------------------------------------------------------------------------------------------------------------
 * * 21 Nov 2022     Group-5		              NEW                        NEW CODE TO PERFORM GIVEN OPERATIONS
 * *
 * * ************************************************************************************************/
/*****************************************************************************************************
								HEADER FILE
*****************************************************************************************************/
#include<ias.h>
 
/************************************************************************************
 * * FUNCTION NAME : Options()
 *   
 * * DESCRIPTION : In this function it shows the menu to Register (or) Login
 *
 * * RETURNS : SUCCESS , in case of error FAILURE
 * * ********************************************************************************/
void Options()
{
	int Option;/* Declaring variable of int type */
	int LogStatus;/* Declaring variable of int type */
	do
	{
		printf("\nPress,");
		printf("\n \t 1. Register");
		printf("\n \t 2. Login");
		printf("\n \t 0. Exit");
		printf("\nEnter your choice : ");
		(void)scanf("%d",&Option);
		switch(Option)
		{
			case 1: Register();
			break;
			case 2:
			LogStatus = Login();
			if(LogStatus==1)
			{
			printf("\n Login Successfull\n");
			Menu();
			}
			break;
			case 0: return;
			break;
			default: printf("Invalid");
			break;
		}
	}while(Option!=0);	
}
/************************************************************************************
 * * FUNCTION NAME : ValidateID()
 *   
 * * DESCRIPTION : In this function itperforms the invalid symbols for userId
 *
 * * RETURNS : SUCCESS , in case of error FAILURE
 * * ********************************************************************************/
int ValidateID(char ID[])
{
    for(int i=0;ID[i]!='\0';i++)
    {
	if(ID[i] == '!' || ID[i] == '@' || ID[i] == '#' || ID[i] == '$'
      || ID[i] == '%' || ID[i] == '^' || ID[i] == '&' || ID[i] == '*'
      || ID[i] == '(' || ID[i] == ')' || ID[i] == '-' || ID[i] == '{'
      || ID[i] == '}' || ID[i] == '[' || ID[i] == ']' || ID[i] == ':'
      || ID[i] == ';' || ID[i] == '"' || ID[i] == '\'' || ID[i] == '<'
      || ID[i] == '>' || ID[i] == '.' || ID[i] == '/' || ID[i] == '?'
      || ID[i] == '~' || ID[i] == '`' )
	  {
		printf("\n Please again enter with Valid User ID \n");
		return 1;
	  }
    }
	return 0; /*0 means success*/   
}

/************************************************************************************
 * * FUNCTION NAME : Register()
 *   
 * * DESCRIPTION : In this function it perform the operations of userId and password
 *
 * * RETURNS : returns nothing as it's return type is void
 * * ********************************************************************************/
//Register
void Register()
{
	
	char USERID[20];/* Declaring variable of char type */
	char PASSWORD[20];/* Declaring variable of char type */
	char REENTRY[20];/* Declaring variable of char type */

	do
	{
		printf("\n\t Enter Your ID : ");
		(void)scanf("%s",USERID);
	}while(ValidateID(USERID)!=0);


	printf("\n\t Enter Your Password : ");
	(void)scanf("%s", PASSWORD);
	
	
	/*Password match checking*/
	do
	{
		printf("\n\t Re-enter Your Password : ");
		(void)scanf("%s", REENTRY);
		if(strcmp(PASSWORD,REENTRY)!=0) printf("\n\tPassword mismatch\n");
	}while(strcmp(PASSWORD,REENTRY)!=0);
	
	if(strcmp(PASSWORD,REENTRY)==0)
	{
		FILE *Users = fopen("Users.csv","a");
	  	fprintf(Users,"%s,%s\n",USERID,PASSWORD);
	  	(void)fclose(Users);
	  	printf("\n Registration Successfull\n");
	  	return; 
	}

	return;
}
/************************************************************************************
 * * FUNCTION NAME : Login()
 *   
 * * DESCRIPTION : In this function it performs the Login operations
 *
 * * RETURNS : SUCCESS , in case of error FAILURE
 * * ********************************************************************************/

int Login()
{
	int U=0;
	int UFILE = 0;
	char USERID[50];
	char PASSWORD[50];
	
	char UID[50];
	char UPASS[50];
	
	printf("\n Enter Your ID : ");
	scanf("%s",UID);
	printf("\n Enter Your Password : ");
	scanf("%s", UPASS);

	FILE *US =fopen("Users.csv","r");
	char buffer[1024];
	int column = 0;
	while(fgets(buffer,1024, US)!=NULL)
	{
		char* value = strtok(buffer, ",");
		while (value!=NULL) 
		{
			UFILE=1;
			if (column == 0) 
			{
				strcpy(USERID,value);
			}
			if (column == 1) 
			{
				strcpy(PASSWORD,value);
			}
			value = strtok(NULL, ", ");
			column++;


			//New Code
			U = CompareStrings(UID,USERID,UPASS,PASSWORD);

			if(column==2 && U==1)
			{
				fclose(US);
				return 1;
			}
			if(column==2)
			{	
				column=0;	
			}
		}
	}
	if(UFILE==0)
	{
		printf("\n\t Users Doesn't Exists..");
	}
	else
	{
		printf("\n\t Invalid Password or ID");
	}
	fclose(US);
	return 0;
}

int CompareStrings(char STR1[20], char STR2[20],char STR3[20],char STR4[20])
{
	int i=0;
	int Count1=0;
	int Count2=0;
	int length1 = strlen(STR1);
	int length2 = strlen(STR2);

	int length3 = strlen(STR3);
	int length4 = strlen(STR4);

	int Log=0;
	if(length1==length2)
	{
		i=0;
		while(STR1[i]!='\0')
		{
			if(STR1[i]==STR2[i])
			{
				 Count1++; 
			}
			i++;
		}
	}
	
	if(length1==Count1)
	{
		Log++;
	}

	if(length3==length4-1)
	{
		i=0;
		while(i<length3)
		{
			if(STR3[i]==STR4[i])
			{
				 Count2++; 
			}
			i++;
		}
	}

	if(length3==Count2)
	{
		Log++;
	}
	if(Log==2)
	{
		return 1;
	}
	
	return 0;
}