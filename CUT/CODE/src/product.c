/************************************************************************************************************
 * * FILENAME : product.c
 *
 * * DESCRIPTION : This file contains a function to perform CRUD operations on Inventory
 *
 * * REVISION HISTORY:
 * * DATE              NAME                       REFERENCE                    		   REASON
 * * --------------------------------------------------------------------------------------------------------------
 * * 21 Nov 2022     Group-5		              NEW                        NEW CODE TO PERFORM GIVEN OPERATIONS
 * *
 * * *********************************************************************************************************/
#include<ias.h> 
/*****************************************************************************************
 * * FUNCTION NAME : Product()
 *   
 * * DESCRIPTION : In this function it shows the menu  like add product,update product
 *                  display product,delete product
 *
 * * RETURNS : Returns nothing as it's return type is void
 * * *************************************************************************************/
void Product()
{
	int Option;
    do
	{
		Option = ProductOptions();
		switch(Option)
		{
			case 1: AddProduct();
			break;
			case 2: UpdateProduct();
			break;
			case 3: ShowProducts();
			break;
			case 4: DeleteProduct();
			break;
			case 0: return;
			default :
			printf("Invalid Option!!");
			break;
		}
    }while(Option!=0);
    return;
}
/*****************************************************************************************
 * * FUNCTION NAME : ProductOptions()
 *   
 * * DESCRIPTION : In this function it displays the subment to product menu
 *
 * * RETURNS : SUCCESS , in case of error FAILURE
 * * *************************************************************************************/
int ProductOptions()
{
	int Option;
	printf("\n ###########PRODUCT OPTIONS###########");
	printf("\nPress,");
	printf("\n\t 1. Add a product");
	printf("\n\t 2. Update a product");
	printf("\n\t 3. Display the Product");
	printf("\n\t 4. Delete a product ");
	printf("\n\t 0. Back to main menu ");
	printf("\nEnter your choice : ");
	(void)scanf("%d",&Option);
	return Option;
}

/*******************************************************************
 * * FUNCTION NAME :  add_product()
 *   
 * * DESCRIPTION : This function is used to add the product
 * 		   
 * * RETURNS : returns nothing as its return type is void
 * * ****************************************************************/
 void AddProduct()
{
	int ID, Quantity;
	char Name[50], Description[50];
	printf("\n#########ADD PRODUCT#############");
	printf("\nEnter,\n\t product ID : ");
	(void)scanf("%d",&ID);
	printf("\t product name : ");
	(void)scanf("%s",Name);
	printf("\t description : ");
	(void)scanf("%s",Description);
	printf("\t Quantity : ");
	(void)scanf("%d",&Quantity);
	
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
	ShowProducts();
}

/*********************************************************************************************
 * * FUNCTION NAME : DeleteProduct()
 *   
 * * DESCRIPTION : This function is used to delete the product by taking input as product id.
 *
 * * RETURNS : returns nothing as its return type is void
 * * *****************************************************************************************/
 void UpdateProduct()
{
	int ID, Quantity,Update=0;
	printf("\n Enter the ID of product you want to update: ");
	(void)scanf("%d", &ID);
	printf("\n Enter Quantity:");
	(void)scanf("%d", &Quantity);
	struct Products *Temp;
	Temp = Head;
	while(Temp!= NULL)
	{
		if(Temp->ID==ID)
		{
			
			if(Quantity>=0)
			{
				
				Temp->Quantity = Quantity;
				Update=1;
		 	}
			else
			{
				printf("\n\t Update with positive values only\n");
				Update=0;
				break;
			}
		 			
		}
		Temp=Temp->Next;
	}
	if(Update==1)
	{
		printf("\n Successfully Updated...");
	}
	else
	{
		printf("\n\t Failed to Updated..\n.");
	}
	return;
}
/*****************************************************************************************
 * * FUNCTION NAME : Showproducts()
 *   
 * * DESCRIPTION : In this function it display the products 
 *
 * * RETURNS : Returns nothing as it's return type is void
 * * *************************************************************************************/
//Show Product

void ShowProducts()
{
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
			printf("\n \t%d\t ",Temp->ID);
	        printf("%s \t",Temp->Name);
	   		printf("%s \t",Temp->Description);
	   		printf("\t %d",Temp->Quantity);
	   		Temp=Temp->Next;
	    }
	}	
}
/*****************************************************************************************
 * * FUNCTION NAME : DeleteProduct()
 *   
 * * DESCRIPTION : In this function it performs the delete product operation
 *
 * * RETURNS : Returns nothing as it's return type is void
 * * *************************************************************************************/
//Delete Product
void DeleteProduct()
{
	int ID;
	printf("\n ############DELETE PRODUCT##############");
	printf("\n Enter the ID of product you want to delete:");
	(void)scanf("\n%d",&ID);
	if(Head==NULL)
	{
		printf("\nEmpty..\n");
	}
	else
	{
		int firstNode = 0; 
		struct Products *Temp, *Current;
		Temp = Head;
		while((Temp->Next != NULL) && (Temp->ID != ID))
		{
			firstNode++;
			Current = Temp;
			Temp=Temp->Next;
		}
		if(firstNode==0)
		{
		 	Temp = Head;
		 	Head = Head->Next;
		 	free(Temp);
		 	printf("\n Deleted Successfully"); 
		}
		else
		{
			if(Temp->ID == ID)
			{  
				Current->Next = Temp->Next;  
            	free(Temp);  
            	printf("\n Deleted Successfully");  
      		}
      		else
      		{
      			printf("\n Not Found");
      		}
		} 	 
	}	
}

