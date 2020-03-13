#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "shopping.h"





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


int searchItem(Items item[], int numItems, int itemInput){
	int i;
	int found = 0;
	int itemIndex = -1;
	
	for(i = 0; i < numItems && found == 0 ; i++){
		if(itemInput == item[i].productId){
			itemIndex = i;
			found = 1;
		}	
	}
			
	return itemIndex;
}


void addItem(Users aUser[], int index){
//	int index;
	int itemIndex;
//	index = searchUser(aUser, numUsers, userId);
	
	aUser[index].numItems++;
	itemIndex = aUser[index].numItems;
	
	aUser[index].item[itemIndex - 1].sellerId = aUser[index].userId;
	
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
//	return item->quantity;
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




int main(){
	Users aUser[MAX_USERS];
	Transactions aTransaction[MAX_USERS];
	int numUsers = 1;
	int option; 
	int i = 0;
	int index;
	
	
	
	
	aUser[0].userId = 1;
	aUser[0].numItems = 1;
	
	index = searchUser(aUser, numUsers, aUser[0].userId);
	
	
	strcpy(aUser[0].item[0].category, "food");
	strcpy(aUser[0].item[0].description, "edible");
	strcpy(aUser[0].item[0].name, "hotdog");
	
	
	aUser[0].item[0].price = 15;
	aUser[0].item[0].productId = 1;
	aUser[0].item[0].quantity = 15;
	
	

	do{
		printf("[1]add item\n[2]Edit stock\n[3]Show my products\n[4]Show low stock\n[5]Exit\n");
		printf("Option: ");
		scanf("%d", &option);
		fflush(stdin);
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
	
	
	
	return 0;	
}
