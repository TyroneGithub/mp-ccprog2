#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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


void removeEnter(char str[]){
	str[strlen(str) - 1] = '\0';
}

void swap(Users *x, Users *y){
	Users temp;
	temp = *x; 
	*x = *y;
	*y = temp;
	
}


void sort(Users aUser[], int numUsers){
	int i, j;
	
	for(i = 0 ; i < numUsers - 1; i++){
		for(j = i + 1; j < numUsers; j++){
			if(aUser[i].userId > aUser[j].userId)
				swap(&aUser[i], &aUser[j]);	
			
		}
	}
}

int searchUser(Users aUser[], int numUsers, int userInput){
	int mid;
	int high = numUsers - 1;
	int low = 0;
	int found = 0;
	int index = - 1;
	
	sort(aUser, numUsers);
	mid = (numUsers - 1) / 2;
	
	
	while(!found){
		if(userInput == aUser[mid].userId){
			index = mid;
			found = 1;
		}
		else if(userInput > aUser[mid].userId){
			low = mid + 1;
			mid = (low + high) / 2;
		}
		else if(userInput < aUser[mid].userId){
			high = mid - 1;
			mid = (low + high) / 2;
		}
		if(low > high)	
			found = 1;	
		
	}
	return index;
	
}


void addItem(Users aUser[], int userId, int numUsers){
	int index;
	int itemIndex;
	index = searchUser(aUser, numUsers, userId);
	
	aUser[index].numItems++;
	itemIndex = aUser[index].numItems;
	
	aUser[index].item[itemIndex - 1].sellerId = userId;
	
	if(aUser[index].numItems <= 20){
		
		printf("Enter product id: ");
		scanf("%d", &aUser[index].item[itemIndex - 1].productId);
		printf("Enter quantity: ");
		scanf("%d", &aUser[index].item[itemIndex - 1].quantity);
		printf("Enter price: ");
		scanf("%f", &aUser[index].item[itemIndex - 1].price);
		fflush(stdin);
		
		printf("Enter item name: ");
		fgets(aUser[index].item[itemIndex - 1].name, STRING20, stdin);
		removeEnter(aUser[index].item[itemIndex - 1].name);
		
		printf("Enter item category: ");
		fgets(aUser[index].item[itemIndex - 1].category, STRING15, stdin);
		removeEnter(aUser[index].item[itemIndex - 1].category);
		
		printf("Enter item description: ");
		fgets(aUser[index].item[itemIndex - 1].description, STRING30, stdin);
		removeEnter(aUser[index].item[itemIndex - 1].description);
		
	}
	
}

//Items *getItem(Users user, int itemNum){
//	Items userItem[20];
//	int i;
//	
//	userItem[itemNum] = user.item[itemNum];
//	
//	return userItem;
//	
//	
//}


void displayItems(Users aUser[], int userId, int numUsers){
	
	int i, j; 
	int index;
	int totalItems;
	index = searchUser(aUser, numUsers, userId);
	totalItems = aUser[index].numItems;
	
	for(i = 0; i < totalItems; i++){
		printf("|%3d|", aUser[index].item[i].productId);
		printf("|%-20s|", aUser[index].item[i].name);
		printf("|%-15s|", aUser[index].item[i].category);
		printf("|%5.2f|", aUser[index].item[i].price);
		printf("|%3d|", aUser[index].item[i].quantity);
		printf("\n");
		
	}
	
}








int main(){
	Users aUser[MAX_USERS];
	Transactions aTransaction[MAX_USERS];
	int numUsers = 0;
	int option; 
	int i = 0;
	
	aUser[0].userId = 1;
	aUser[0].numItems = 0;
	
//	strcpy(aUser[0].item[0].category, "food");
//	strcpy(aUser[0].item[0].description, "edible");
//	strcpy(aUser[0].item[0].name, "hotdog");
//	
//	
//	aUser[0].item[0].price = 15;
//	aUser[0].item[0].productId = 1;
//	aUser[0].item[0].quantity = 15;
	
	

	do{
		printf("[1]add item\n[2]Edit stock\n[3]Show my products\n[4]Show low stock\n");
		scanf("%d", &option);
		switch(option){
		
			case 1: 
				addItem(aUser, 1, 1);
				break;
			case 2:
				break;
			case 3:
				displayItems(aUser,1, 1);
				break;
			case 4:
				break;
		
		}
	}while(option >= 1 && option <= 4);
	
	
	
	return 0;	
}
