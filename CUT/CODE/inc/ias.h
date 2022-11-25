/*************************************************************************************
 * * FILENAME : ias.h
 *
 * * DESCRIPTION : This file defines required function to perform given options  on input array
 *
 * * REVISION HISTORY:
 * * DATE              NAME                    REFERENCE                    		   REASON
 * * --------------------------------------------------------------------------------------------------------------
 * * 21 Nov 2022     Group-5		              NEW                        NEW CODE TO PERFORM GIVEN OPERATIONS
 * *
 * * ********************************************************************************/
#include<common.h>

struct Products
{ 
	int ID;
	char Name[50];
	char Description[50];
	int Quantity;
	struct Products *Next;
};

struct Sales
{
	int  SaleID;
	int  NoItems;
	char DateTime[25];
	char Cart[20][10];
	struct Sales *Next;
};
struct Products *Head;
struct Sales *SalesHead;

void initialize();
void Options();
void Register();
int Login();
void Menu();
int  MenuOptions();
void Product();
int  ProductOptions();
void AddProduct();
void UpdateProduct();
void ShowProducts();
void DeleteProduct();
void Sale();
int  SaleOptions();
void MakeSale();
void SaleDisplay();
void ProductReport();
void SalesReport();
void UpdateProductFile();
void LoadProductFile();
void UpdateSalesFile();
void EffectProducts(int, int);
char *JoinStrings(char [],char []);
int CompareStrings(char [], char [],char [], char []);
char *GetTime();
int ValidateID(char []);
int GenerateID();

