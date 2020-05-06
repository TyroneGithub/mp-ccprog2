#define STRING10 12
#define STRING20 22
#define STRING15 17	
#define STRING30 32
#define MAX_USERS 100
#define MAX_ITEMS 20
#define MAX_CART 10

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
	int contactNum;
	int numItems;
	int numCart;
	Items item[MAX_ITEMS];
	Items cart[MAX_CART];
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
	int numItems;
	float total;

	
}Transactions;

void userMenu(Users *aUser, int numUsers, int index);
void checkOutMenu(Users *aUser, int numUsers, int index);
void editCart(Items cart[], int* numCart, Users *currUser, int numUsers, int index);
void displayItems(Items item[], int numItems);