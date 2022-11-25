/*************************************************************************************
 * * FILENAME : loadSaleData.c
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
 * * FUNCTION NAME : UpdateSalesFile()
 *   
 * * DESCRIPTION : In this function it performs the file operations in sales.csv file
 *
 * * RETURNS : Returns nothing as it's return type is void
 * * *************************************************************************************/
void UpdateSalesFile()
{
  FILE *A = fopen("Sales.csv","a");
  if(SalesHead==NULL)
  {
    /*Error message*/
  }
  else
  {
    struct Sales *SalesTemp;
    SalesTemp = SalesHead;
    while(SalesTemp!=NULL)
    {
      fprintf(A,"%d, %s, ",SalesTemp->SaleID, SalesTemp->DateTime);
      int i=0;
      while(i<SalesTemp->NoItems)
      {
        fprintf(A,"%s  ",SalesTemp->Cart[i]);
        i++;
      }
        fprintf(A,"\n");
        SalesTemp=SalesTemp->Next;
    }
  }
  fclose(A);
}

/*****************************************************************************************
 * * FUNCTION NAME : JoinStrings()
 *   
 * * DESCRIPTION : In this function it performs to join strings of productId and product Quantity
 *
 * * RETURNS : SUCCESS , in case of error FAILURE
 * * *************************************************************************************/

char *JoinStrings(char String1[15],char String2[15])
{
	int i=0,j=1;
	char *STR =  (char *)malloc(sizeof(30));
	STR[0] = '<';
	
	while (String1[i] != '\0')// Insert First String
	{
    STR[j] = String1[i];
    i++;
    j++;
  }
    
  i = 0;
  STR[j]=',';
  j++;
  while (String2[i] != '\0') 
  {
    STR[j] = String2[i];
    i++;
    j++;
  }
  STR[j] = '>';
  j++;
	STR[j] = '\0';
	return STR;
}
/*****************************************************************************************
 * * FUNCTION NAME : makeSale()
 *   
 * * DESCRIPTION : In this function it performs the timestamp operations to get date and time
 *
 * * RETURNS : SUCCESS , in case of error FAILURE
 * * *************************************************************************************/
char* GetTime()
{
	int point=0,count=0;
	time_t t = time(NULL);
  struct tm tm = *localtime(&t);
  char *DateTime =  (char *)malloc(sizeof(25));
  char Day[3];
  char Month[3];
  char Year[5];
  char Hour[3];
  char Minute[3];
  char Seconds[3];
  char Date[15]; //Date like 22-11-2022
  char Time[15]; //Time like 15:20:60
  sprintf(Day, "%d", tm.tm_mday);
  sprintf(Month, "%02d",tm.tm_mon + 1);
  sprintf(Year, "%02d",tm.tm_year + 1900);
  sprintf(Hour, "%02d",tm.tm_hour);
  sprintf(Minute, "%02d",tm.tm_min);
  sprintf(Seconds, "%02d",tm.tm_sec);
  
  //Join Date with '-'
  while(Day[count]!='\0')
  {
    Date[point]= Day[count];
    point++;
    count++;
  }
  Date[point]='-';
  point++;
  count=0;
  while(Month[count]!='\0')
  {
    Date[point]= Month[count];
    point++;
    count++;
  }
  Date[point]='-';
  point++;
  count=0;
  while(Year[count]!='\0')
  {
    Date[point]= Year[count];
    point++;
    count++;
  }
  Date[point]='\0';
 
  
  /*Joins Time with ':'*/
  point=0;
  count=0;
  while(Hour[count]!='\0')
  {
    Time[point] = Hour[count];
    point++;
    count++;
  }
  Time[point]=':';
  point++;
  count=0;
  while(Minute[count]!='\0')
  {
    Time[point]=Minute[count];
    point++;
    count++;
  }
  count=0;
  Time[point]=':';
  point++;
  while(Seconds[count]!='\0')
  {
    Time[point]=Seconds[count];
    point++;
    count++;
  }
  Time[point]='\0';
  
  point=0;
  count=0;
  while(Date[count]!='\0')
  {
    DateTime[point]=Date[count];
    point++;
    count++;
  }
  DateTime[point]=' ';
  point++;
  
  count=0;
  while(Time[count]!='\0')
  {
    DateTime[point]=Time[count];
    point++;
    count++;
  }
  DateTime[point]='\0';
  return DateTime;
}

/*****************************************************************************************
 * * FUNCTION NAME : SalesReport()
 *   
 * * DESCRIPTION : In this function it display the sales report
 *
 * * RETURNS : SUCCESS , in case of error FAILURE
 * * *************************************************************************************/

void SalesReport()
{
	printf("\n ############Sales Report#############");
	SaleDisplay();
}