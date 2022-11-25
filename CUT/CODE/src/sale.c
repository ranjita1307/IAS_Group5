/*************************************************************************************
 * * FILENAME : sale.c
 *
 * * DESCRIPTION : This file defines required function to perform given options  on input array
 *
 * * REVISION HISTORY:
 * * DATE              NAME                       REFERENCE                    		   REASON
 * * --------------------------------------------------------------------------------------------------------------
 * * 21 Nov 2022     Group-5		              NEW                        NEW CODE TO PERFORM GIVEN OPERATIONS
 * *
 * * ********************************************************************************/
/**********************************************************************************
								HEADER FILE
***********************************************************************************/

#include<ias.h> 

/***************************************************************************
 * * FUNCTION NAME : sale()
 *   
 * * DESCRIPTION : In this function it shows the sales menu
 *
 * * RETURNS : Returns nothing as its return type is void 
 * * ***********************************************************************/
void Sale()
{
	int Option;/* declaring variables of int type*/
    do
	{
		Option = SaleOptions();
		switch(Option)
		{
			case 1: MakeSale();
			break;
			case 2: SaleDisplay();
			break;
			case 0: return;
			default :
			printf("\nInvalid Option!!");
	    }
    }while(Option!=0);

    return;	
}
/****************************************************************************
 * * FUNCTION NAME : saleOptions()
 *   
 * * DESCRIPTION : In this function it shows the submenu to sale menu
 *
 * * RETURNS : SUCCESS , in case of error FAILURE
 * * ***********************************************************************/
int SaleOptions()
{
	int Options;
	printf("\nPress,");
	printf("\n\t 1. Make sale");
	printf("\n\t 2. Display");
    printf("\n\t 0. Back to main menu ");
	printf("\nEnter your choice : ");
	(void)scanf("%d", &Options);
	return Options;
}
/*****************************************************************************************
 * * FUNCTION NAME : makeSale()
 *   
 * * DESCRIPTION : In this function it performs the sale/purchasing operations
 *
 * * RETURNS : SUCCESS , in case of error FAILURE
 * * *************************************************************************************/
//MakeSale
void MakeSale()
{
 	int ID, Quantity;/*Declaring variable of int type*/
 	int Exit=0;
 	char Cart[10][20];
 	int count = 0;
 	int NoSales=0;
 	do
 	{
		int ValidID=0;
		do                              /*start of dowhile*/
		{
			if(ValidID!=0)
			{
				printf("\n\tEnter Number Values only \n");
			}
			ValidID++;
			printf("\nEnter,\n\t product ID : ");
			(void)scanf("%d",&ID);
		}while(isdigit(ID)!=0);
		
		struct Products *PTemp;
		PTemp = Head;
		int VID=0;
		while(PTemp!= NULL)
		{
			int V = PTemp->ID;
			PTemp->ID= V;
			if(PTemp->ID==ID)
			{
				VID=1;	
			}
			PTemp=PTemp->Next;
		}
		if(VID==0)
		{
			printf("\n\t Invalid ID\n");
			return;
		}
		printf("\t Quantity : ");
		(void)scanf("%d",&Quantity);
		PTemp = Head;
		while(PTemp!= NULL)
		{
			if(PTemp->ID==ID)
			{
				if(!(Quantity>=0 && Quantity<=PTemp->Quantity))
				{
					printf("\n\t Entered Quantity exceeds with actual Quantity\n");
					return;
		 		}
		 	}
			PTemp=PTemp->Next;
		}
		EffectProducts(ID,Quantity);
		NoSales++;
		char StrQuant[10];
		char StrID[10];
		sprintf(StrID, "%d", ID);
		sprintf(StrQuant, "%d", Quantity);
		char *NewString;
		NewString = JoinStrings(StrID,StrQuant);   /*Joing Strings with < , >*/
		char String[50];
		strcpy(String, NewString);     /*Copies pointer value to string*/
		int i=0;
		while(String[i]!='\0')
		{
	 		Cart[count][i]=String[i];
	 		i++;
		}
		Cart[count][i]='\0';   /*'\0' Denotes ending of individual String*/
		count++; 
		printf("\n Enter any except 0 to continue \n");
		(void)scanf("%d",&Exit);
		}while(Exit!=0);            /*end of do while loop*/
		
		/*Save to Sales Linked List*/
		int i=0;
		char *DT = GetTime();
		char DATETIME[25];
		strcpy(DATETIME,DT);
	
		struct Sales *SalesNode = (struct Sales*)malloc(sizeof(struct Sales));
	
		SalesNode->SaleID = GenerateID();
    	(void)GenerateID();
		SalesNode->NoItems = NoSales;
		SalesNode->Next = NULL;
		strcpy(SalesNode->DateTime,DATETIME);
	
		/*Save Items to Cart*/
		while(i<count)
		{
			strcpy(SalesNode->Cart[i],Cart[i]);
	  		i++;
		}
	
		/*Updating Sales linked list*/
		if(SalesHead==NULL)
		{
			SalesHead=SalesNode;
		}
		else
		{
	 		struct Sales *SalesTemp;
	 		SalesTemp = SalesHead;
	 		while(SalesTemp->Next!=NULL)
        	{
          		SalesTemp=SalesTemp->Next;
         	}
	  		SalesTemp->Next=SalesNode;
		}
	return;
}
/*****************************************************************************************
 * * FUNCTION NAME : genterateId()
 *   
 * * DESCRIPTION : In this function it generates the Id and stores the data in sales.csv file
 *
 * * RETURNS : SUCCESS , in case of error FAILURE
 * * *************************************************************************************/
int GenerateID()
{
	int SID;
	char ID[10];
	
	FILE *CS =fopen("Sales.csv","r");
	char buffer[1024];
	int column = 0;
	int fresh=0;
	while(fgets(buffer,1024, CS)!=NULL)
	{
		fresh++;
		char* value = strtok(buffer, ", ");
		column =0;
		while (value!=NULL) 
		{
			if (column == 0) 
			{
				strcpy(ID,value);
			}
		
			value = strtok(NULL, ", ");  
			column++;
		}
	}
	if(fresh == 0)
	{
		SID = 1000;
	}
	else
	{
		SID = (atoi(ID)+1);
	}
	fclose(CS);
	return SID;
}
/*****************************************************************************************
 * * FUNCTION NAME : EffectProducts()
 *   
 * * DESCRIPTION : In this function it performs operations to sort the products 
 *
 * * RETURNS : returns nothing return type is void
 * * *************************************************************************************/
void EffectProducts(int ID, int Quantity)
{
	struct Products *Temp;
	Temp = Head;
	while(Temp!= NULL)
	{
		if(Temp->ID==ID)
		{
			if(Quantity!=0)
		 	{
		 		Temp->Quantity = Temp->Quantity - Quantity;
		 	}			
		}
		Temp=Temp->Next;
	}
	return;
}

/*****************************************************************************************
 * * FUNCTION NAME : makeSale()
 *   
 * * DESCRIPTION : In this function it diplays the sales transaction
 *
 * * RETURNS : returns nothing return type is void
 * * *************************************************************************************/
//Display
void SaleDisplay()
{
	if(SalesHead==NULL)
	{
		printf("\n Empty");
	}
	else
	{
		struct Sales *SalesTemp;
		SalesTemp = SalesHead;
		while(SalesTemp!=NULL)
		{
			printf("\n %d  ",SalesTemp->SaleID);
			int i=0;
			while(i<SalesTemp->NoItems)
			{
	   			printf(" %s  ", SalesTemp->Cart[i]);
	   			i++;
	   		}
			printf("\t %s", SalesTemp->DateTime);
			SalesTemp=SalesTemp->Next;
	  	}
	}	 
	return;
}
