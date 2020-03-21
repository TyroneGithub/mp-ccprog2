#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shopping.h"
#include "search-funcs.h"
#include "file-processing.h"



void addItem(Users *aUser,  int index, int numUsers){

	int itemIndex;
	int id;
	
	itemIndex = aUser->numItems;

//	aUser[index].item[itemIndex].sellerId = aUser[index].userId;
	
	
	if( aUser->numItems < MAX_ITEMS){
		aUser->numItems++;
		
		
		do{
			printf("Enter product id: ");
			scanf("%d", &id);
			fflush(stdin);
		}while(searchProdId(aUser - index, numUsers, id));	
		
		aUser -> item[itemIndex].productId = id;
		
		
		printf("Enter item name: ");
		getStringInput(aUser->item[itemIndex].name, STRING20);	
		toUpperCase(aUser->item[itemIndex].name);
//		fgets(aUser->item[itemIndex].name, STRING20, stdin);
//		removeEnter(aUser->item[itemIndex].name);
		
		printf("Enter item category: ");
		getStringInput(aUser->item[itemIndex].category, STRING15);
		toUpperCase(aUser->item[itemIndex].category);
//		fgets(aUser->item[itemIndex].category, STRING15, stdin);
//		removeEnter(aUser->item[itemIndex].category);
		
		printf("Enter item description: ");
		getStringInput(aUser->item[itemIndex].description, STRING30);
//		fgets(aUser->item[itemIndex].description, STRING30, stdin);
//		removeEnter(aUser->item[itemIndex].description);

		printf("Enter quantity: ");
		scanf("%d", &aUser->item[itemIndex].quantity);
		printf("Enter price: ");
		scanf("%f", &aUser->item[itemIndex].price);
		fflush(stdin);
		
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
	int i = 0;
	char choice = ' ';

	
	do{
		
		if(item[i].quantity <= 5){
			system("cls");
			printItems(&item[i]);
			do{
				printf("Press N to see next or press X to exit: ");
				scanf("%c",&choice);
				fflush(stdin);
				
			}while(!(choice == 'N' || choice == 'n' || choice == 'X' || choice =='x'));
		
		}
		i++;
		
			
	}while((choice == 'N' || choice == 'n') && i < numItems);
				
	
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
	
	
	if(itemIndex != -1){
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
					getStringInput(item[itemIndex].name, STRING20);
					toUpperCase(item[itemIndex].name);
					printf("New name: %s\n", item[itemIndex].name);
					
					break;
				case 4:
					printf("Enter new category: ");
					getStringInput(item[itemIndex].category, STRING15);
					toUpperCase(item[itemIndex].category);
					printf("New category: %s\n", item[itemIndex].category);
					break;
				case 5:
					printf("Enter new description: ");
					getStringInput(item[itemIndex].description, STRING30);
					printf("New description: %s\n", item[itemIndex].description);
					break;
				case 6:
					break;
				default:
					break;
			}
			
		}while(option != 6);
	
	}
	
}


void sellMenu(Users *aUser, int numUsers, int index){
	int option;
	
	do{
		printf("\n==Sell Menu==\n");
		printf("[1]add item\n[2]Edit stock\n[3]Show my products\n[4]Show low stock\n[5]Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		switch(option){
		
			case 1: 
				aUser->item[aUser->numItems].sellerId = aUser->userId;
				addItem(aUser, index, numUsers);
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

void displayAllProd(Users aUser[], int numUsers){
	int i = 0;
	char choice;
	
	
	do{
		
		if(aUser[i].numItems > 0){
			system("cls");
			printf("Seller Id: %d\n", aUser[i].userId);
			displayItems(aUser[i].item, aUser[i].numItems);	
			do{
				printf("Press N to see next or press X to exit: ");
				scanf("%c",&choice);
				fflush(stdin);
				
				
			}while(!(choice == 'N' || choice == 'n' || choice == 'X' || choice =='x'));
		
		}
		i++;
		
			
	}while((choice == 'N' || choice == 'n') && i < numUsers);
	

	
	
}
void displayBySeller(Users aUser[], int numUsers){
	int sellerId;
	int sellerIndex;

	printf("Enter seller id: ");
	scanf("%d", &sellerId);
	fflush(stdin);
	sellerIndex = searchUser(aUser, numUsers, sellerId);
	displayItems(aUser[sellerIndex].item, aUser[sellerIndex].numItems);
	
}

void displayByCateg(Users aUser[], int numUsers, String15 categ){
	int i , j ;
	int sentinel = 0;
	char choice;
	Items tempItem[MAX_USERS][MAX_ITEMS];
	
	/* put condition if num items <= MAX_ITEMS */
	initTempItem(tempItem, aUser, numUsers);

	i = 0;
	
		do{
			j = 0;
			while(j < aUser[i].numItems && sentinel == 0){
				if(strcmp(categ, tempItem[i][j].category) == 0){
					system("cls");
					printf("Seller Id: %d\n", aUser[i].userId);
					printItems(&tempItem[i][j]);	
					do{
						printf("Press N to see next or press X to exit: ");
						scanf("%c",&choice);
						fflush(stdin);
						
						if(choice == 'X' || choice == 'x')
							sentinel  = 1;
						
					}while(!(choice == 'N' || choice == 'n' || choice == 'X' || choice =='x'));
				
				}
				j++;
			}
			i++;
			
	}while((choice == 'N' || choice == 'n') && i < numUsers && sentinel == 0);

	
	
}

void searchByName(Users *aUser, int numUsers, String20 keyword){
	
	int i , j ;
	int sentinel = 0;
	char choice;
	Items tempItem[MAX_USERS][MAX_ITEMS];
	
	initTempItem(tempItem, aUser, numUsers);

	i = 0;
		do{
			j = 0;
			while(j < aUser[i].numItems && sentinel == 0){
				if(strstr(tempItem[i][j].name, keyword) != NULL){
					system("cls");
					printf("Seller Id: %d\n", aUser[i].userId);
					printItems(&tempItem[i][j]);	
					do{
						printf("Press N to see next or press X to exit: ");
						scanf("%c",&choice);
						fflush(stdin);
						
						if(choice == 'X' || choice == 'x')
							sentinel  = 1;
						
					}while(!(choice == 'N' || choice == 'n' || choice == 'X' || choice =='x'));
				
				}
				j++;
			}
			i++;
			
	}while((choice == 'N' || choice == 'n') && i < numUsers && sentinel == 0);
	
	
}


void removeItemsBySellerId(Items cart[], int* numCart, int sellerId){
	int i;
	int cartIndex;

	
	// check index of item and if it is existing
	while((cartIndex = searchItemBySeller(cart, *numCart, sellerId)) != -1){
		// removes item 
		for(i = cartIndex; i < *numCart && cartIndex != -1; i++)
			cart[i] = cart[i + 1];
		
		(*numCart)--;
	}
	if(cartIndex == -1)
		printf("Seller ID not found in cart\n");

	//sorts cart contents by seller id 
	sortItemBySeller(cart, *numCart);
	
}

void removeItemsById(Items cart[], int* numCart, int prodId){
	int i; 
	int cartIndex;
	int found = 0;
	// check index of item and if it is existing
	while((cartIndex = searchItem(cart, *numCart, prodId)) != - 1){
		// removes item 
		found = 1;
		for(i = cartIndex; i < *numCart && cartIndex != -1; i++)
			cart[i] = cart[i + 1];
		
		(*numCart)--;
	}
	if(found == 0)
		printf("Product ID not in cart\n");

	//sorts cart contents by seller id 
	sortItemBySeller(cart, *numCart);
	
}
	
void editCartQty(Items cart[], int numCart, int numUsers, Users aUser[] ){
	
	int prodId, quantity;
	int cartIndex, userIndex, itemIndex;
	int i, j;
	int found = 0;
	
	printf("Select product ID: ");			
	scanf("%d", &prodId);
	printf("Enter new quantity: ");
	scanf("%d", &quantity);
	
	cartIndex = searchItem(cart, numCart, prodId);
	
	if(cartIndex != - 1){
		if(quantity > 0){
			
			for(i = 0; i < numUsers && found == 0; i++){
				for(j = 0; j < aUser[i].numItems && found == 0; j++){
					if(prodId == aUser[i].item[j].productId){
						userIndex = i;
						itemIndex = j;
						found = 1;
					}
				}
			}
			
			if(quantity > aUser[userIndex].item[itemIndex].quantity)
				printf("New quantity is greater than the available stock\n");
			else
				cart[cartIndex].quantity = quantity;	
			
		}
		else
			printf("Quantity cannot be less than or equal to 0\n");	
	}
	else
		printf("Item not in cart\n");
	
}


void editCart(Items cart[], int* numCart, Users *currUser, int numUsers, int index){
	
	int option;
	int sellerId;
//	int sellIndex;
	int prodId;
	
	
	printf("== Edit Cart ==\n");
	do{
		prodId = 0;
		displayItems(currUser->cart, currUser->numCart);
		printf("[1]Remove all items from Seller\n[2]Remove Specific item\n[3]Edit Quantity\n[4]Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		switch(option){
			case 1:
				printf("Select seller ID products that you want to remove: ");			
				scanf("%d", &sellerId);
//				sellIndex = searchUser(aUser, numUsers, sellerId);
				removeItemsBySellerId(cart, numCart, sellerId);
				break;
			case 2:
				printf("Select product ID that you want to remove: ");			
				scanf("%d", &prodId);
				removeItemsById(cart, numCart, prodId);
				break;
			case 3:
				editCartQty(cart, *numCart, numUsers, currUser - index);
				break;
			case 4:
				break;
			default:
				break;
				
		}	
		
		
	}while(option != 4);
	
	
}

//CHANGE THIS FUNCTION LATER 
void addToCart(Users aUser[], int numUsers, Users *currUser){
	
	int prodId, quantity;
	int itemIndex, userIndex;
	int i, j;
	int found = 0, inCart = -1;
	int ctr = 0;
	Items tempItem[MAX_ITEMS * numUsers];
	char choice = 'A';
	
	
	while(currUser->numCart < MAX_CART && choice == 'A' || choice == 'a'){

		found = 0;

		printf("Enter product id: ");
		scanf("%d", &prodId);
		fflush(stdin);
		
		printf("Enter item quantity: ");
		scanf("%d", &quantity);
		fflush(stdin);
		
		inCart = searchItem(currUser->cart, currUser->numCart, prodId);
		
		if(searchProdId(aUser, numUsers, prodId) != 0){
			if(inCart == -1){
				
				if(quantity > 0){
					
					//search item indeces 
					for(i = 0; i < numUsers && found == 0; i++){
						for(j = 0; j < aUser[i].numItems && found == 0; j++){
							if(prodId == aUser[i].item[j].productId){
								userIndex = i;
								itemIndex = j;
								found = 1;
							}
						}
					}
					
					if(quantity <= aUser[userIndex].item[itemIndex].quantity){
						
						if(currUser->userId != aUser[userIndex].userId){
							
							currUser->cart[currUser->numCart] = aUser[userIndex].item[itemIndex];
							currUser->cart[currUser->numCart].quantity = quantity;
							currUser->numCart++;
							
							sortItemBySeller(currUser->cart, currUser->numCart);
						
					
							printf("Enter A to continue buying, E to edit cart or C to procced to checkout: ");
							scanf("%c", &choice);
							fflush(stdin);
							
							switch(choice){
								case 'A': case 'a':
									break;
								case 'E': case 'e':
									printf("Edit");
									break;
								case 'C': case 'c':
									printf("checkout");
									break;
								default:
									break;
							}
					
						}
						else{
							printf("You cannot buy your own items\n");
							choice = ' ';
						}
					}
					else{
						printf("Quantity is greater than supply please try again\n");
						choice = ' ';
					} 
					
				}
				else{
					printf("Cannot input negative items please try again\n");
					choice = ' ';
				}
			}
			else
				printf("Item is already in your cart please try again\n");
			
		}
		else{
			printf("Item does not exist\n");
			choice = ' ';
		}
	}
	
}

void displayReceipt(){
	
}


void checkOutAll(Users aUser[], int numUsers ,Dates date, Users *currUser){
	int i, j;
	int numTrans;
	Transactions aTrans[MAX_CART];
	
	initTrans(currUser, aTrans, &numTrans, currUser->numCart);
	
//	for(i = 0; i < numTrans; i++){
//		for(j = 0; j < aTrans[i].numItems; j++)
//			printf("%s\n", aTrans[i].aItem[j].name);
//			
//	}
	
	
}



void checkOutMenu(Users *aUser, int numUsers, int index){
	int option;
	Dates date;
	
	date = getDate();
	
	
	do{
		printf("\n==Check Out Menu==\n");
		printf("[1]Check Out All\n[2]Check Out By Specific Seller\n[3]Check Out By Specific Item\n[4]Exit\n");
		
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		
		switch(option){
			case 1:
				checkOutAll(aUser - index, numUsers, date, aUser);
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			default:
				break;
		}
		
	}while(option != 4);
	
	
}

void buyMenu(Users *aUser, int numUsers, int index){
	int option;
	String15 categ;
	String20 keyword;
	
	do{
		printf("\n==Buy Menu==\n");
		printf("[1]View All Products\n[2]Show All Products by Seller\n[3]Search Products By Category\n[4]Search Products By Name\n");
		printf("[5]Add to Cart\n[6]Edit Cart\n[7]Check out\n[8]Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		
		switch(option){
			case 1:
				displayAllProd(aUser - index, numUsers);
				break;
			case 2:
				displayBySeller(aUser - index, numUsers);
				break;
			case 3:
				printf("Enter category: ");
				getStringInput(categ, STRING15);
				toUpperCase(categ);
//				printf("hello");
				displayByCateg(aUser - index, numUsers, categ);
				break;
			case 4:
				printf("Enter item name: ");
				getStringInput(keyword, STRING20);
				toUpperCase(keyword);
				searchByName(aUser - index, numUsers, keyword);
				break;
			case 5:
				addToCart(aUser - index, numUsers, aUser);
				break;
			case 6:
				editCart(aUser->cart, &aUser->numCart, aUser, numUsers, index);
				break;
			case 7:
				checkOutMenu(aUser, numUsers, index);
				break;
			case 8:
				break;
			default:
				break;
		}
		
	}while(option != 8);
}


void printUsers(Users *aUser){
	
	printf("|%3d|", aUser->userId);
	printf("|%-10s|", aUser->password);
	printf("|%-20s|", aUser->name);
	printf("|%-30s|", aUser->address);
	printf("|%9d|", aUser->contactNum);
	
}

void displayAllUsers(Users aUser[], int numUsers){
	int i;
	
	for(i = 0; i < numUsers; i++){
		printUsers(&aUser[i]);
		printf("\n");
	}	
	
}

void displaySellers(Users aUser[], int numUsers){
	int i;
	
	for(i = 0; i < numUsers; i++){
		if(aUser[i].numItems > 0){
			printUsers(&aUser[i]);
			printf("|%2d|", aUser[i].numItems);
			printf("\n");
		}
	}
	
}

void adminMenu(Users *aUser, int numUsers, int index){
	int option;
	
	do{
		printf("\n==Admin Menu==\n");
		printf("[1]Show All Users\n[2]Show All Sellers\n[3]Show Total Sales\n[4]Show Sellers Sales\n");
		printf("[5]Show Shopaholics\n[6]Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		
		switch(option){
			case 1:
				displayAllUsers(aUser - index, numUsers);
				break;
			case 2:
				displaySellers(aUser - index, numUsers);
				break;
			case 3:
				
				break;
			case 4:
				break;
			case 5:
				break;
			case 6:
				break;
			default:
				break;
		}
		
	}while(option != 6);
	
}

void userMenu(Users *aUser, int numUsers, int index){
	int option = 0;
	String10 password;
	
	do{
		printf("\n==User Menu==\n");
		printf("[1]Sell Menu\n[2]Buy Menu\n[3]Admin Menu\n[4]Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		switch(option){
			case 1:
				sellMenu(aUser, numUsers, index); 
//				printf("Sell Menu\n");
				break;
			case 2:
				buyMenu(aUser, numUsers, index);
				break;
			case 3:
				printf("Verify password: ");
				getStringInput(password, STRING10);
				
				if(strcmp(password, aUser->password) == 0)
					adminMenu(aUser, numUsers, index);
				else{
					printf("Incorrect password...Returning to main menu");
					option = 4;
				}
				break;
			case 4:
				break;
			default:
				break;
		}
	

	}while(option != 4);
	
}

void login(Users aUser[], int numUsers){
	int id;
	int getUserIndex ;
	String10 password;
	
	
		printf("Enter User ID: ");
		scanf("%d", &id);
		fflush(stdin);
		
		printf("Enter Password: ");
		getStringInput(password, STRING10);
	
		
		getUserIndex = searchUser(aUser, numUsers, id);
		
		
		if(getUserIndex == -1)	
			printf("User not found...Going back to main menu\n");
			
		else{
			if(id == aUser[getUserIndex].userId && strcmp(password, aUser[getUserIndex].password) == 0)
				userMenu(&aUser[getUserIndex], numUsers, getUserIndex);

			else
				printf("Invalid password...Going back to main menu\n");
		}
	
}


void registerUser(Users aUser[],  int *numUsers){

	int id;
	int index; 
	
	
	if( (*numUsers) < MAX_USERS){
		
		(*numUsers)++;
		
		index = *numUsers - 1;
		
		do{
			printf("Enter User ID: ");
			scanf("%d", &id);
			fflush(stdin);
			
		}while(!search(aUser, id,*numUsers));
		
		aUser[index].userId = id;
		
		
		printf("Enter name: ");
		getStringInput(aUser[(*numUsers) - 1].name, STRING20);		
		
		printf("Enter password: ");
		getStringInput(aUser[(*numUsers) - 1].password, STRING10);	
		
//		fgets(aUser[(*numUsers) - 1].password, STRING10, stdin);
//		removeEnter(aUser[(*numUsers) - 1].password);
		
		printf("Enter address: ");
		getStringInput(aUser[(*numUsers) - 1].address, STRING30);	
		
//		fgets(aUser[(*numUsers) - 1].address, STRING30, stdin);
//		removeEnter(aUser[(*numUsers) - 1].address);
		
		printf("Enter contact number: ");
		scanf("%d", &aUser[(*numUsers) - 1].contactNum);
		fflush(stdin);
		
	}
	
}


int main(){
	Users aUser[MAX_USERS];
	Transactions aTransaction[MAX_USERS];
	int numUsers = 0;
	int option; 

	numUsers = readFile(aUser);
	readItem(aUser, numUsers);

	
	printf("Shopping App\n");
	
	do{
		printf("\n==Main Menu==\n");
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
