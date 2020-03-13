#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shopping.h"
#include "search-funcs.h"
#include "file-processing.h"

void addItem(Users aUser[], int index){

	int itemIndex;
	
	
	itemIndex = aUser[index].numItems;
//	printf("%d\n", itemIndex);

	aUser[index].item[itemIndex].sellerId = aUser[index].userId;
	
	
	if(aUser[index].numItems < MAX_ITEMS){
		aUser[index].numItems++;
		
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

void sellMenu(Users aUser[], int index){
	int option;
	
	do{
		printf("[1]add item\n[2]Edit stock\n[3]Show my products\n[4]Show low stock\n[5]Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		switch(option){
		
			case 1: 
				addItem(aUser, index);
				break;
			case 2:
				editStock(aUser[index].item, aUser[index].numItems);
				break;
			case 3:
				displayItems(aUser[index].item, aUser[index].numItems);
				break;
			case 4:
				displayLowStock(aUser[index].item, aUser[index].numItems);
				break;
			case 5:
				break;
			default:
				break;
		
		}
	}while(option != 5);
	
	
}

void userMenu(Users aUser[], int userIndex){
	int option = 0;
	
	printf("%d", aUser[userIndex].numItems);
	
	do{
		printf("Main Menu\n");
		printf("[1]Sell Menu\n[2]Buy Menu\n[3]Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		switch(option){
			case 1:
				sellMenu(aUser, userIndex); 
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
				userMenu(aUser, getUserIndex);

			else
				printf("Invalid password...Going back to main menu\n");
		}
		

	
	
}


void registerUser(Users aUser[],  int *numUsers){

	int id;
	String20 name;
	String10 password;
	String30 address;
	int contactNum;
	int numItems;
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
		
	}while(searchUser(aUser, *numUsers, id) != -1);

	printf("**%d**\n", index);
	
	
	printf("Enter name: ");
	fgets(name, STRING20, stdin);
	removeEnter(name);
	
//	fgets(aUser[(*numUsers) - 1].name, STRING20, stdin);
//	removeEnter(aUser[(*numUsers) - 1].name);
	
	
	printf("Enter password: ");
	fgets(password, STRING10, stdin);
	removeEnter(password);
//	fgets(aUser[(*numUsers) - 1].password, STRING10, stdin);
//	removeEnter(aUser[(*numUsers) - 1].password);
	
	printf("Enter address: ");
	fgets(address, STRING30, stdin);
	removeEnter(address);
//	fgets(aUser[(*numUsers) - 1].address, STRING30, stdin);
//	removeEnter(aUser[(*numUsers) - 1].address);
	
	printf("Enter contact number: ");
	scanf("%d", &contactNum);
//	scanf("%d", &aUser[(*numUsers) - 1].contactNum);
	fflush(stdin);
	
	
	aUser[index].userId = id;
	aUser[index].numItems = 0;
	aUser[index].contactNum = contactNum;
	strcpy(aUser[index].name, name);
	strcpy(aUser[index].password, password);
	strcpy(aUser[index].address, address);
	
	
}

void printA(Users aUser[], int numUsers){
	int i;
	
	printf("--------------\n");
	
	for(i = 0; i < numUsers ; i++){
		printf("%d %s\n", aUser[i].userId, aUser[i].password);
		printf("%s\n%s\n",aUser[i].name, aUser[i].address);
		printf("%d\n\n",aUser[i].contactNum);
	}
}


int main(){
	Users aUser[MAX_USERS];
	Transactions aTransaction[MAX_USERS];
	int numUsers = 0;
	int option; 

	numUsers = readFile(aUser);
	

	
	printf("Shopping App\n");
	
	do{
		
		printf("**%d**\n", numUsers);
		
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
				printA(aUser, numUsers);
				break;
		}
		
	}while(option != 3);
	
//	fclose(fp_userWrite); 

	
	return 0;
}
