/*************************************************************************************
 * * FILENAME : menu.c
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
 * * FUNCTION NAME : Menu()
 *   
 * * DESCRIPTION : In this function it displays the entire menu to perform operations
 *
 * * RETURNS : Returns nothing as it's return type is void
 * * *************************************************************************************/
void Menu()
{
	int Option;
	
	do
	{
		Option = MenuOptions();
		switch(Option)
		{
			case 1: Product();
			break;
			case 2: Sale();
			break;
			case 3: SalesReport();
			break;
			case 4: ProductReport();
			break;
			case 0: return;
			default: printf("\n Invalid Option \n");
			break;
		}
	}while(Option!=0);
	return;
}
/*****************************************************************************************
 * * FUNCTION NAME : MenuOptions()
 *   
 * * DESCRIPTION : In this function it diplays the Menuoptions
 *
 * * RETURNS : SUCCESS , in case of error FAILURE
 * * *************************************************************************************/

//Menu Display
int MenuOptions()
{
	int Option;
	printf("\n ###########INVENTORY CONTROL###########\n");
	printf("\nPress,");
	printf("\n\t 1. Product");
	printf("\n\t 2. Sale");
	printf("\n\t 3. Get the Sale Report");
	printf("\n\t 4. Get the Product Report");
	printf("\n\t 0. Go to back...");
	printf("\nEnter your choice : ");
	(void)scanf("%d", &Option);
	return Option;	
}
