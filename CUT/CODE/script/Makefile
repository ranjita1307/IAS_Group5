CC = gcc

ProjDir = /mnt/d/CapgeminiTraining/Sprint/documents/Sprint_Group5_IAS/CUT/CODE/IAS_Project

INC = $(ProjDir)/inc
SRC = $(ProjDir)/src
OBJ = $(ProjDir)/obj
BIN = $(ProjDir)/bin

CFLAGS = -c -g -Wall 

 

LDFLAGS = -o

IFLAGS = -I $(INC)


all: IAS

IAS: $(OBJ)/main.o $(OBJ)/sign.o $(OBJ)/menu.o $(OBJ)/product.o $(OBJ)/loadProductData.o $(OBJ)/sale.o $(OBJ)/loadSaleData.o
	$(CC) $(LDFLAGS) $(BIN)/IAS $(OBJ)/main.o $(OBJ)/sign.o $(OBJ)/menu.o $(OBJ)/product.o $(OBJ)/loadProductData.o $(OBJ)/sale.o $(OBJ)/loadSaleData.o

$(OBJ)/main.o: $(SRC)/main.c
	$(CC) $(CFLAGS) $(SRC)/main.c $(IFLAGS)
	mv main.o $(OBJ)/

$(OBJ)/sign.o: $(SRC)/sign.c
	$(CC) $(CFLAGS) $(SRC)/sign.c $(IFLAGS)
	mv sign.o $(OBJ)/

$(OBJ)/menu.o: $(SRC)/menu.c
	$(CC) $(CFLAGS) $(SRC)/menu.c $(IFLAGS)
	mv menu.o $(OBJ)/

$(OBJ)/product.o: $(SRC)/product.c
	$(CC) $(CFLAGS) $(SRC)/product.c $(IFLAGS)
	mv product.o $(OBJ)/

$(OBJ)/loadProductData.o: $(SRC)/loadProductData.c
	$(CC) $(CFLAGS) $(SRC)/loadProductData.c $(IFLAGS)
	mv loadProductData.o $(OBJ)/

$(OBJ)/sale.o: $(SRC)/sale.c
	$(CC) $(CFLAGS) $(SRC)/sale.c $(IFLAGS)
	mv sale.o $(OBJ)/

$(OBJ)/loadSaleData.o: $(SRC)/loadSaleData.c
	$(CC) $(CFLAGS) $(SRC)/loadSaleData.c $(IFLAGS)
	mv loadSaleData.o $(OBJ)/

clean:
	rm -f *.out *.o
	rm -f $(OBJ)/*.o
	rm -f $(BIN)/*
	@echo "Cleaning Done!"
