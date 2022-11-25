/****************************************************************************************************************
 * * FILENAME : main.c
 *
 * * DESCRIPTION : This file contains main function
 *
 * * REVISION HISTORY:
 * * DATE              NAME              REFERENCE                           REASON
 * * --------------------------------------------------------------------------------------------------------------
 * * 21 Nov 2022      Group 05             NEW                        NEW CODE TO PERFORM GIVEN OPERATIONS
 * *
 * * ************************************************************************************************************/
#include<ias.h>
 
/************************************************************************************************
 * * FUNCTION NAME : main()
 *
 * * DESCRIPTION : This function calls other defined functions to perform the given operations
 *
 * * RETURNS : SUCCESS in case of failure ERROR
 * * **************************************************************************************************/
int main()
{
    
	printf("\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
	printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        =                    WELCOME                =");
    printf("\n\t\t\t        =                      TO                   =");
    printf("\n\t\t\t        =               Inventory Analysis          =");
    printf("\n\t\t\t        =                    Software               =");
    printf("\n\t\t\t        =                                           =");
    printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n\n\t\t\t  **-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**-**\n");

	LoadProductFile();
	Options();
	UpdateProductFile();
	UpdateSalesFile();
    
	return 0;
}
