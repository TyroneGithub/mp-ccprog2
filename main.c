#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shopping.h"
#include "search-funcs.h"
#include "file-processing.h"


/* FIX THIS SHIT (FUNCTION) PARA MACHECK NIYA PA RIN YUNG MGA USERS AT ID NUNG MGA ITEMS PER USER */ 

void addItem(Items item[], int* numItems){

	int itemIndex;
	
	
	itemIndex = *numItems;

//	aUser[index].item[itemIndex].sellerId = aUser[index].userId;
	
	
	if( (*numItems) < MAX_ITEMS){
		(*numItems)++;
		
	
		printf("Enter product id: ");
		scanf("%d", &item[itemIndex].productId);
		
		
		
		printf("Enter quantity: ");
		scanf("%d", &item[itemIndex].quantity);
		printf("Enter price: ");
		scanf("%f", &item[itemIndex].price);
		fflush(stdin);
		
		printf("Enter item name: ");
		fgets(item[itemIndex].name, STRING20, stdin);
		removeEnter(item[itemIndex].name);
		
		printf("Enter item category: ");
		fgets(item[itemIndex].category, STRING15, stdin);
		removeEnter(item[itemIndex].category);
		
		printf("Enter item description: ");
		fgets(item[itemIndex].description, STRING30, stdin);
		removeEnter(item[itemIndex].description);
		
	}
	
}

void printItems(Items *item){
	
	printf("|%3d|", item->productId);
	printf("|%-20s|", item->name);
	printf("|%-15s|", item->category);
	printf("|%5.2f|", item->price);
	printf("|%3d|", item->quantity);
	printf("\n");
	
}

void displayItems(Items item[], int numItems){
	int i;
	
	
	for(i = 0; i < numItems; i++)
		printItems(&item[i]);
	
}

void displayLowStock(Items item[], int numItems){
	int i; 
	for(i = 0; i < numItems; i++){
		if(item[i].quantity <= 5)
			printItems(&item[i]);

	}
	
}

void itemQuantity(Items *item, int quantity, char operation){
	switch(operation){
		case '+':
			item->quantity += quantity;
			break;
		case '-':
			item->quantity -= quantity;
			break;
	}
}


void editStock(Items item[], int numItems){
	int itemIndex;
	int itemOption;
	int option;
	int quantity;
	float price;
	String20 name;
	String15 category;
	String30 description;
	
	
	displayItems(item, numItems);
	
	printf("Enter item to edit: ");
	scanf("%d", &itemOption);
	itemIndex = searchItem(item, numItems, itemOption);

	
	do{
		printf("[1]Replenish\n[2]Change Price\n[3]Change item name\n");
		printf("[4]Change Category\n[5]Change Description\n[6]Finish Editing\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		
		switch(option){
			case 1:
				printf("Enter number of items you want to add: ");
				scanf("%d", &quantity);
				fflush(stdin);
				itemQuantity(&item[itemIndex], quantity, '+');
				break;
			case 2:
				printf("Enter new price: ");
				scanf("%f", &price);
				fflush(stdin);
				item[itemIndex].price = price; 
				break;
			case 3:
				printf("Enter new item name: ");
				fgets(name, STRING20, stdin);
				removeEnter(name);
				strcpy(item[itemIndex].name, name);
				break;
			case 4:
				printf("Enter new category: ");
				fgets(category, STRING15, stdin);
				removeEnter(category);
				strcpy(item[itemIndex].category, category);
				break;
			case 5:
				printf("Enter new description: ");
				fgets(description, STRING30, stdin);
				removeEnter(description);
				strcpy(item[itemIndex].description, description);
				break;
			case 6:
				break;
			default:
				break;
		}
		
	}while(option != 6);
	
	
}

void sellMenu(Users *aUser){
	int option;
	
	do{
		printf("[1]add item\n[2]Edit stock\n[3]Show my products\n[4]Show low stock\n[5]Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		switch(option){
		
			case 1: 
				aUser->item[aUser->numItems].sellerId = aUser->userId;
				addItem(aUser->item, &aUser->numItems);
				break;
			case 2:
				editStock(aUser->item, aUser->numItems);
				break;
			case 3:
				displayItems(aUser->item, aUser->numItems);
				break;
			case 4:
				displayLowStock(aUser->item, aUser->numItems);
				break;
			case 5:
				break;
			default:
				break;
		
		}
	}while(option != 5);
	
	
}

void userMenu(Users *aUser){
	int option = 0;
	
	printf("%d", aUser->numItems);
	
	do{
		printf("Main Menu\n");
		printf("[1]Sell Menu\n[2]Buy Menu\n[3]Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		switch(option){
			case 1:
				sellMenu(aUser); 
//				printf("Sell Menu\n");
				break;
			case 2:
				printf("Buy Menu\n");
				break;
			case 3:
				break;
			default:
				break;
		}
	

	}while(option != 3);
	
}

void login(Users aUser[], int numUsers){
	int id;
	int getUserIndex ;
	String10 password;
	
	
		printf("Enter User ID: ");
		scanf("%d", &id);
		fflush(stdin);
		
		printf("Enter Password: ");
		fgets(password, STRING10, stdin);
		removeEnter(password);
		
		getUserIndex = searchUser(aUser, numUsers, id);
	
		
		if(getUserIndex == -1)	
			printf("User not found...Going back to main menu\n");
			
		else{
			if(id == aUser[getUserIndex].userId && strcmp(password, aUser[getUserIndex].password) == 0)
				userMenu(&aUser[getUserIndex]);

			else
				printf("Invalid password...Going back to main menu\n");
		}
		

	
	
}


void registerUser(Users aUser[],  int *numUsers){

	int id;
	int index; 
	
	(*numUsers)++;
	
	index = *numUsers - 1;
	do{
//		
//		if(searchUser(aUser, *numUsers, id) != -1)
//			printf("User already exists please try again\n");
		printf("Enter User ID: ");
		scanf("%d", &id);
		fflush(stdin);
		
	}while(!search(aUser, id,*numUsers));
	
	aUser[index].userId = id;
	
	
	printf("Enter name: ");
	
	fgets(aUser[(*numUsers) - 1].name, STRING20, stdin);
	removeEnter(aUser[(*numUsers) - 1].name);
	
	
	printf("Enter password: ");
	fgets(aUser[(*numUsers) - 1].password, STRING10, stdin);
	removeEnter(aUser[(*numUsers) - 1].password);
	
	printf("Enter address: ");
	fgets(aUser[(*numUsers) - 1].address, STRING30, stdin);
	removeEnter(aUser[(*numUsers) - 1].address);
	
	printf("Enter contact number: ");
	scanf("%d", &aUser[(*numUsers) - 1].contactNum);
	fflush(stdin);
	
	
}


int main(){
	Users aUser[MAX_USERS];
	Transactions aTransaction[MAX_USERS];
	int numUsers = 0;
	int option; 

	numUsers = readFile(aUser);
	

	
	printf("Shopping App\n");
	
	do{
		
		printf("[1] Register\n[2] Login\n[3] Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		switch(option){
			case 1:
				registerUser(aUser, &numUsers);
				break;
			case 2:
				login(aUser, numUsers);
				break;
			case 3:
				writeFile(aUser, numUsers);
				break;
			default:
				break;
		}
		
	}while(option != 3);
	
//	fclose(fp_userWrite); 

	
	return 0;
}
