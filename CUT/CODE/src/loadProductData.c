/*************************************************************************************
 * * FILENAME : loadProductData.c
 *
 * * DESCRIPTION : This file defines required function to perform given options  on input array
 *
 * * REVISION HISTORY:
 * * DATE              NAME                    REFERENCE                    		   REASON
 * * --------------------------------------------------------------------------------------------------------------
 * * 21 Nov 2022     Group-5		              NEW                        NEW CODE TO PERFORM GIVEN OPERATIONS
 * *
 * * ********************************************************************************/
/**********************************************************************************
								HEADER FILE
***********************************************************************************/

#include<ias.h>
/*****************************************************************************************
 * * FUNCTION NAME : UpdateProductFile()
 *   
 * * DESCRIPTION : In this function it performs the file operations to display products
 *
 * * RETURNS : Returns nothing as it's return type is void
 * * *************************************************************************************/
void UpdateProductFile() 
{
	FILE *W = fopen("Products.csv","w");
	if(Head==NULL)
	{
		printf("\n Empty\n");
	}
	else
	{
		struct Products *Temp;
		Temp = Head;
		while(Temp!=NULL)
	   	{
			fprintf(W,"%d, %s, %s, %d\n",Temp->ID, Temp->Name, Temp->Description, Temp->Quantity); 
	   		Temp=Temp->Next;
	   	}
	}
	fclose(W);
}
/*****************************************************************************************
 * * FUNCTION NAME : LoadProductFile()
 *   
 * * DESCRIPTION : In this function it performs the file operations to Load products
 *
 * * RETURNS : Returns nothing as it's return type is void
 * * *************************************************************************************/

void LoadProductFile()
{

	int ID, Quantity;
	char Name[50], Description[50];
	FILE *CS =fopen("Products.csv","r");
	char buffer[1024];
	int column = 0;
	while(fgets(buffer,1024, CS)!=NULL)
	{
		char* value = strtok(buffer, ", ");
		while (value!=NULL) 
		{
			if (column == 0) 
			{
				ID=atoi(value);
			}
			if (column == 1) 
			{
				strcpy(Name,value);
			}
			if (column == 2) 
			{
				strcpy(Description,value);
			}
			if (column == 3) 
			{
				Quantity = atoi(value);
			}
			
			value = strtok(NULL, ", ");
			column++;
			if(column==4)
			{
				column=0; 
				struct Products *D = (struct Products*)malloc(sizeof(struct Products));
				D->ID= ID;
				strcpy(D->Name, Name);
				strcpy(D->Description,Description);
				D->Quantity= Quantity;
				D->Next=NULL;
				if(Head==NULL)
				{
					Head=D;
				}
				else
				{
					struct Products *Temp;
					Temp = Head;
					while(Temp->Next!=NULL)
					{
						Temp=Temp->Next;
					}
					Temp->Next=D;
				}	
			}		
		}
	}
	fclose(CS);
}
/*****************************************************************************************
 * * FUNCTION NAME : ProductReport()
 *   
 * * DESCRIPTION : In this function it display the product report
 *
 * * RETURNS : SUCCESS , in case of error FAILURE
 * * *************************************************************************************/

void ProductReport()
{
	printf("\n #########Product Report#############\n");
	ShowProducts();
}
