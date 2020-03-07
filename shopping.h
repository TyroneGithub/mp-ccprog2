#define STRING10 12
#define STRING20 22
#define STRING15 17	
#define STRING30 32
#define MAX_USERS 100
#define MAX_ITEMS 20


typedef char String10[STRING10];
typedef char String20[STRING20];
typedef char String30[STRING30];
typedef char String15[STRING15];

typedef struct Item{
	int productId;
	int quantity;
	int sellerId;
	float price;
	String20 name;
	String15 category;
	String30 description;
	
}Items;


typedef struct User{
	int userId;
	String20 name;
	String10 password;
	String30 address;
	long contactNum;
	int numItems;
	Items item[MAX_ITEMS];
	Items cart[10];
}Users;


typedef struct Date{
	int month;
	int day;
	int year;
	
}Dates;

typedef struct Transaction{
	Dates transDate;
	Items aItem[5];
	int buyerId;
	int sellerId;
	float total;
	
}Transactions;

void userMenu(Users aUser[], int userIndex);
