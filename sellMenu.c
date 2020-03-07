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


void printItems(Items item[], int itemIndex){
	
	int i, j; 
//	int index;
	int totalItems;
//	index = searchUser(aUser, numUsers, userId);
//	totalItems = aUser[index].numItems;
	
	printf("|%3d|", item[itemIndex].productId);
	printf("|%-20s|", item[itemIndex].name);
	printf("|%-15s|", item[itemIndex].category);
	printf("|%5.2f|", item[itemIndex].price);
	printf("|%3d|", item[itemIndex].quantity);
	printf("\n");
	
	
	
}

void displayItems(Users aUser[], int index){
	int i;
	
	for(i = 0; i < aUser[index].numItems; i++)
		printItems(&aUser[index].item[i], i);
	
}

void displayLowStock(Users aUser[], int index){
	int i; 
//	for(i = 0; i < aUser[index].numItems; i++){
//		if(aUser[index].item[i].quantity <= 5)
//			printItems(aUser, index, i);
//
//	}
	
}


int main(){
	Users aUser[MAX_USERS];
	Transactions aTransaction[MAX_USERS];
	int numUsers = 1;
	int option; 
	int i = 0;
	int index;
	
	aUser[0].userId = 1;
	aUser[0].numItems = 0;
	
	index = searchUser(aUser, numUsers, aUser[0].userId);
//	strcpy(aUser[0].item[0].category, "food");
//	strcpy(aUser[0].item[0].description, "edible");
//	strcpy(aUser[0].item[0].name, "hotdog");
//	
//	
//	aUser[0].item[0].price = 15;
//	aUser[0].item[0].productId = 1;
//	aUser[0].item[0].quantity = 15;
	
	

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
				break;
			case 3:
				displayItems(aUser, index);
				break;
			case 4:
				break;
			case 5:
				break;
			default:
				break;
		
		}
	}while(option != 5);
	
	
	
	return 0;	
}
