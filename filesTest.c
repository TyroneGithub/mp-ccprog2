#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING10 11
#define STRING20 21
#define STRING15 16	
#define STRING30 31
#define MAX_USERS 100
#define MAX_ITEMS 20


typedef char String10[STRING10];
typedef char String20[STRING20];
typedef char String30[STRING30];
typedef char String15[STRING15];

typedef struct Users{
	int userId;
	String20 name;
	String10 password;
	String30 address;
	long contactNum;
}Users;

typedef struct Items{
	int productId;
	int quantity;
	int sellerId;
	float price;
	String20 name;
	String15 category;
	String30 description;
	
}Items;

typedef struct Transactions{
	int month;
	int day;
	int year;
	int buyerId;
	int sellerId;
	
}Transactions;



int main(){
	struct Users aUser[MAX_USERS];
	struct Items aItem[MAX_USERS][MAX_ITEMS];
	struct Transactions aTransaction[MAX_USERS];
	
	
	return 0;
}

