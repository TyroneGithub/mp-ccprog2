/***
Programmed by: Tyrone Sta. Maria S11A 
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shopping.h"
#include "search-funcs.h"
#include "file-processing.h"

/*

Adds items to the user's item inventory.

@param(Users*) aUser is the pointer to the address of the current user that is logged in 
@param(int) index is the index of the current logged in user. 
@param(int) numUsers is the total number of current registered users.
@return(void) no return value
*/

void addItem(Users *aUser,  int index, int numUsers){
//	sellMenu();
	int itemIndex;
	int id;
	
	
	itemIndex = aUser->numItems;

//	aUser[index].item[itemIndex].sellerId = aUser[index].userId;
	
	
	if( aUser->numItems < MAX_ITEMS){
		printf("= = = = ADD ITEM = = = =\n");
		aUser->numItems++;
		
		
		do{
			printf("Enter product id: ");
			scanf("%d", &id);
			fflush(stdin);
			
			if(searchProdId(aUser - index, numUsers, id))
				printf("Product Id already entered\n");
			
		}while(searchProdId(aUser - index, numUsers, id));	
		
		aUser -> item[itemIndex].productId = id;
		
		
		printf("Enter item name: ");
		getStringInput(aUser->item[itemIndex].name, STRING20);	
		toUpperCase(aUser->item[itemIndex].name);

		printf("Enter item category: ");
		getStringInput(aUser->item[itemIndex].category, STRING15);
		toUpperCase(aUser->item[itemIndex].category);

		printf("Enter item description: ");
		getStringInput(aUser->item[itemIndex].description, STRING30);

		printf("Enter quantity: ");
		scanf("%d", &aUser->item[itemIndex].quantity);
		printf("Enter price: ");
		scanf("%f", &aUser->item[itemIndex].price);
		fflush(stdin);
		
		printf("Item successfully added! Press enter to go back to sell menu...");
		getchar();
		system("cls");
		
	}
	else{
		printf("Max number of items reached. Press enter to go back to sell menu...");
		getchar();
		system("cls");
	}
	
}

/*

Displays header for item information
@return(void) no return value
*/
void itemHeader(){
	printf("\n");
	printf("|%-10s|","Product Id");
	printf("|%-20s|","Name");
	printf("|%-30s|", "Description");
	printf("|%-15s|","Category");
	printf("|%-10s|","Price");
	printf("|%-8s|","Quantity");
	printf("\n---------------------------------------------------------------------------------------------------------\n");
}


/*

Prints Items structure information corresponding to its variables 

@param(Items*) item is the pointer to the  structure of a specific item
@return(void) no return value
*/
void printItems(Items *item){
	
	printf("|%10d|", item->productId);
	printf("|%-20s|", item->name);
	printf("|%-30s|", item->description);
	printf("|%-15s|", item->category);
	printf("|%10.2f|", item->price);
	printf("|%8d|", item->quantity);
	printf("\n");
	
}


/*

Displays items specific information

@param(Items[]) item is an array of structures that holds the user is selling
@param(int) numItems is the total number of items that the user is selling

@return(void) no return value
*/
void displayItems(Items item[], int numItems){
	int i;
	
	for(i = 0; i < numItems; i++)
		printItems(&item[i]);
	
}


/*

Displays items that has a quantity of less than 5

@param(Items[]) item is an array of structures that holds the user is selling
@param(int) numItems is the total number of items that the user is selling

@return(void) no return value
*/
void displayLowStock(Items item[], int numItems){
	int i = 0;
	char choice = ' ';

	
	do{
		
		if(item[i].quantity < 5){
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

/*

Edit the the quantity of a specific item

@param(Items[]) item is an array of structures that holds the user is selling
@param(int) numItems is the total number of items that the user is selling

@return(void) no return value
*/


void editStock(Items item[], int numItems){
	int itemIndex;
	int itemOption;
	int option;
	int quantity;
	float price;
	
	printf("\n= = = = Edit Stock = = = =\n\n");
	
	itemHeader();
	displayItems(item, numItems);
	
	printf("\n");
	printf("Enter product id of item to edit: ");
	scanf("%d", &itemOption);
	fflush(stdin);
	system("cls");
	itemIndex = searchItem(item, numItems, itemOption);
	
	
	if(itemIndex != -1){
		do{
			printf("= = = = Currently editing  = = = = \n");
			itemHeader();
			printItems(&item[itemIndex]);
			printf("\n");
			
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
					printf("New Quantity: %d\n", item[itemIndex].quantity);
					printf("Press enter to continue...\n");
					getchar();
					system("cls");
					break;
				case 2:
					printf("Enter new price: ");
					scanf("%f", &price);
					fflush(stdin);
					item[itemIndex].price = price; 
					printf("New price: %.2f\n", item[itemIndex].price);
					printf("Press enter to continue...\n");
					getchar();
					system("cls");	
					break;
				case 3:
					printf("Enter new item name: ");
					getStringInput(item[itemIndex].name, STRING20);
					toUpperCase(item[itemIndex].name);
					printf("New name: %s\n", item[itemIndex].name);
					printf("Press enter to continue...\n");
					getchar();
					system("cls");
					
					break;
				case 4:
					printf("Enter new category: ");
					getStringInput(item[itemIndex].category, STRING15);
					toUpperCase(item[itemIndex].category);
					printf("New category: %s\n", item[itemIndex].category);
					printf("Press enter to continue...\n");
					getchar();
					system("cls");
					break;
				case 5:
					printf("Enter new description: ");
					getStringInput(item[itemIndex].description, STRING30);
					printf("New description: %s\n", item[itemIndex].description);
					printf("Press enter to continue...\n");
					getchar();
					system("cls");
					break;
				case 6:
					break;
				default:
					break;
			}
			
		}while(option != 6);
	
	}
	else{
		printf("Item not found. Press enter to go back to sell menu\n");
		getchar();
		system("cls");
	}
	
}


/*

The user is presented with the options for selling (ie. add item, edit stock, show my products, show low stock)

@param(Users*) aUser is the pointer to the address of the current user that is logged in 
@param(int) numUsers is the total number of current registered users.
@param(int) index is the index of the current logged in user. 
@return(void) no return value
*/

void sellMenu(Users *aUser, int numUsers, int index){
	int option;
	
	do{
		printf("\n= = = = Sell Menu = = = =\n");
		printf("[1]add item\n[2]Edit stock\n[3]Show my products\n[4]Show low stock\n[5] Show item statistics\n[6]Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		switch(option){
		
			case 1: 
				system("cls");
				aUser->item[aUser->numItems].sellerId = aUser->userId;
				addItem(aUser, index, numUsers);
				break;
			case 2:
				system("cls");
				editStock(aUser->item, aUser->numItems);
				break;
			case 3:
				system("cls");
				printf("= = = = All Products = = = =\n");
				itemHeader();
				displayItems(aUser->item, aUser->numItems);
				printf("\n");
				break;
			case 4:
				system("cls");
				printf("= = = = = Low stock products = = = =\n");
				displayLowStock(aUser->item, aUser->numItems);
				break;
			case 5:
				system("cls");
				displayTopItemsPerSeller(aUser->userId);
				break;
			case 6:
				break;
			default:
				break;
		
		}
	}while(option != 6);
	
	
}


/*

Display all products 

@param(Users[]) aUser is the array of structures that contains user information
@param(int) numUsers is the total number of current registered users.
@param(Users*) currUser is the pointer to the address of the current user that is logged in 

@return(void) no return value
*/

void displayAllProd(Users aUser[], int numUsers, Users *currUser){
	int i = 0;
	int sentinel = 0;
	char choice = 'N';
	

	do{
		
		if(aUser[i].numItems > 0 && currUser->userId != aUser[i].userId && sentinel == 0){
			system("cls");
			printf("= = = = Seller Id: %d = = = =\n", aUser[i].userId);
			itemHeader();
			displayItems(aUser[i].item, aUser[i].numItems);	
			do{
				printf("Press N to see next or press X to exit: ");
				scanf("%c",&choice);
				fflush(stdin);
				
				if(choice == 'X' || choice == 'x')
					sentinel  = 1;
				
			}while(!(choice == 'N' || choice == 'n' || choice == 'X' || choice =='x'));
		
		}
		i++;
		
			
	}while((choice == 'N' || choice == 'n') && i < numUsers);
	

	
	
}
/*

Search and display items by specific seller

@param(Users[]) aUser is the array of structures that contains user information
@param(int) numUsers is the total number of current registered users.

@return(void) no return value
*/
void displayBySeller(Users aUser[], int numUsers){
	int sellerId;
	int sellerIndex;
	printf("= = = = Display by seller = = = =\n\n");
	printf("Enter seller id: ");
	scanf("%d", &sellerId);
	fflush(stdin);
	// search for seller index 
	sellerIndex = searchUser(aUser, numUsers, sellerId);
	
	if(sellerIndex != -1){
		printf("\n= = = = Products of Seller id: %d  = = = =\n", sellerId);
		itemHeader();
		displayItems(aUser[sellerIndex].item, aUser[sellerIndex].numItems);
	}
	else{
		printf("Seller id not found. Press enter to go back to buy menu...");
		getchar();
		system("cls");	
	}
	
}
/*

Search and display items by specific category

@param(Users[]) aUser is the array of structures that contains user information
@param(int) numUsers is the total number of current registered users.
@param(String15) categ is the searched  category of the user
@param(Users*) currUser is the pointer to the address of the current user that is logged in 

@return(void) no return value
*/

void displayByCateg(Users aUser[], int numUsers, String15 categ, Users *currUser){
	int i , j ;
	int sentinel = 0;
	char choice = 'N';
	Items tempItem[MAX_USERS][MAX_ITEMS];
	
	/* put condition if num items <= MAX_ITEMS */
	initTempItem(tempItem, aUser, numUsers);

	i = 0;
	
		do{
			j = 0;
			while(j < aUser[i].numItems && sentinel == 0){
				if(strcmp(categ, tempItem[i][j].category) == 0 && currUser->userId != aUser[i].userId){
					system("cls");
					printf("= = = = Seller Id: %d = = = =\n", aUser[i].userId);
					itemHeader();
					printItems(&tempItem[i][j]);	
					do{
						printf("\nPress N to see next or press X to exit: ");
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

/*

Search and display items by specific key words 

@param(Users[]) aUser is the array of structures that contains user information
@param(int) numUsers is the total number of current registered users.
@param(String20) keyword is the searched  keyword of the user
@param(Users*) currUser is the pointer to the address of the current user that is logged in 

@return(void) no return value
*/

void searchByName(Users aUser[], int numUsers, String20 keyword, Users *currUser){
	
	int i , j ;
	int sentinel = 0;
	char choice;
	Items tempItem[MAX_USERS][MAX_ITEMS];
	
	initTempItem(tempItem, aUser, numUsers);

	i = 0;
		do{
			j = 0;
			while(j < aUser[i].numItems && sentinel == 0){
				// to edit 
				if(strstr(tempItem[i][j].name, keyword) != NULL){
					system("cls");
					printf("= = = = Seller Id: %d = = = =\n", aUser[i].userId);
					itemHeader();
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

/*

Removes all items that a specific seller sells. 

@param(Items[]) cart is the array of structures that contains user's cart
@param(int*) numCart is the total number of items in the user's cart.
@param(int) sellerId indicates the products that the selected seller sells.

@return(void) no return value
*/


void removeItemsBySellerId(Items cart[], int* numCart, int sellerId){
	int i;
	int cartIndex;
	int found = 0;
	
	// check index of item and if it is existing
	while((cartIndex = searchItemBySeller(cart, *numCart, sellerId)) != -1){
		found = 1;
		// removes item 
		for(i = cartIndex; i < *numCart && cartIndex != -1; i++)
			cart[i] = cart[i + 1];
		
		(*numCart)--;
	}
	if(found == 0)
		printf("Seller ID not found in cart\n");
	else{
		printf("Item removed from cart successfully. Press enter to continue...");
		getchar();
		system("cls");
	}
	//sorts cart contents by seller id 
	sortItemBySeller(cart, *numCart);

	
}

/*

Removes a specific product that the user chose.

@param(Items[]) cart is the array of structures that contains user's cart
@param(int*) numCart is the total number of items in the user's cart.
@param(int) prodId is the product id that the user chose to remove.

@return(void) no return value
*/


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

/*

Edits the quantity of a specific item in the users cart

@param(Items[]) cart is the array of structures that contains user's cart
@param(int) numCart is the total number of items in the user's cart.
@param(Users[]) aUser is the array of structures that contains user information
@param(int) numUsers is the total number of current registered users.

@return(void) no return value
*/

void editCartQty(Items cart[], int numCart, int numUsers, Users aUser[] ){
	
	int prodId, quantity;
	int cartIndex, userIndex, itemIndex;
	int i, j;
	int found = 0;
	char choice;
	
	printf("Select product ID: ");			
	scanf("%d", &prodId);
	printf("Enter new quantity: ");
	scanf("%d", &quantity);
	fflush(stdin);
	
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
			else{
				cart[cartIndex].quantity = quantity;	
				printf("Item quantity edited successfully. Press enter to edit cart again...");
				getchar();
				system("cls");
			}
			
		}
		else{
			printf("Do you want to remove this item? (Y/N)\n");
			scanf("%c", &choice);
			fflush(stdin);

			if(choice == 'Y' || choice == 'y'){
				removeItemsById(cart, &numCart, prodId);
				printf("Item removed. Press enter to edit cart again...");
				getchar();
				system("cls");
			}
			else if(choice == 'N' || choice == 'n'){
				printf("Press enter to edit cart again...");
				getchar();
				system("cls");
			}


		}
	}
	else
		printf("Item not in cart\n");
	
	
	
	
}


/*

Displays options to edit the cart (ie. remove all items from seller, remove specific item, and edit item quantity)

@param(Items[]) cart is the array of structures that contains user's cart
@param(int*) numCart is the total number of items in the user's cart.
@param(Users*) currUser is the pointer to the address of the current user that is logged in 
@param(int) numUsers is the total number of current registered users.
@param(int) index is the index of the current logged in user. 
@return(void) no return value
*/

void editCart(Items cart[], int* numCart, Users *currUser, int numUsers, int index){
	
	int option;
	int sellerId;
	int prodId;
	int changes = 0;
	
	printf("= = = = Edit Cart = = = =\n");
	do{
		changes = checkChanges(cart, currUser - index, *numCart, numUsers);
		prodId = 0;
		itemHeader();
		displayItems(currUser->cart, currUser->numCart);
		printf("\n");
		printf("[1]Remove all items from Seller\n[2]Remove Specific item\n[3]Edit Quantity\n[4]Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		switch(option){
			case 0:
				break;
			case 1:
				printf("= = = = Remove item by seller id = = = =\n");
				printf("Select seller ID products that you want to remove: ");			
				scanf("%d", &sellerId);
				fflush(stdin);
				removeItemsBySellerId(cart, numCart, sellerId);
				break;
			case 2:
				printf("= = = = Remove item by product id = = = =\n");
				printf("Select product ID that you want to remove: ");			
				scanf("%d", &prodId);
				fflush(stdin);
				removeItemsById(cart, numCart, prodId);
				break;
			case 3:
				printf("= = = = Edit quantity = = = =\n");
				editCartQty(cart, *numCart, numUsers, currUser - index);
				break;
			case 4:
				if(changes == 1){
					system("cls");
					printf("Item quantity is greater than stock please edit your cart\n\n");
					option = 0;
				}
				break;
			default:
				printf("Invalid option\n");
				break;
				
		}	
		
		
	}while(option != 4);
	
	
}

/*

Adds user's chosen items to the user's cart. 

@param(Users[]) aUser is the array of structures that contains user information
@param(int) numUsers is the total number of current registered users.
@param(Users*) currUser is the pointer to the address of the current user that is logged in 

@return(void) no return value
*/


void addToCart(Users aUser[], int numUsers, Users *currUser){
	
	int prodId, quantity;
	int itemIndex, userIndex, index;
	int i, j;
	int found = 0, inCart = -1;
	char choice = 'A';
	

	printf("= = = = Add to Cart = = = = \n");
	if(currUser->numCart >= MAX_CART)
		printf("Maximum number of items in cart reached. Press enter to go back\n");

	while(currUser->numCart < MAX_CART && (choice == 'A' || choice == 'a')){
		if(currUser->numCart < MAX_CART){

			found = 0;
			
			itemHeader();
			for(i = 0; i < numUsers; i++){
				if(aUser[i].userId != currUser->userId)
					displayItems(aUser[i].item, aUser[i].numItems);
			}
			printf("\n");
			
			
			displayTopItems(aUser,  numUsers);
			
			printf("Enter product id: ");
			scanf("%d", &prodId);
			fflush(stdin);
			
			system("cls");
			
			inCart = searchItem(currUser->cart, currUser->numCart, prodId);
			
			if(searchProdId(aUser, numUsers, prodId) != 0){
				
				if(inCart == -1){
					printf("= = = = Chosen item = = = = ");
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
					printf("\n");
					itemHeader();
					printItems(&aUser[userIndex].item[itemIndex]);
					printf("\n");
					printf("Enter item quantity: ");
					scanf("%d", &quantity);
					fflush(stdin);
						
					if(quantity > 0){
						
					
						
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
										system("cls");
										index = searchUser(aUser, numUsers, currUser->userId);
										editCart(currUser->cart, &currUser->numCart, currUser, numUsers, index);
										break;
									case 'C': case 'c':
										system("cls");
										index = searchUser(aUser, numUsers, currUser->userId);
										checkOutMenu(currUser, numUsers, index);
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
				else{
					printf("Item is already in your cart please try again\n");
					choice = ' ';
				}
				
			}
			else{
				printf("Item does not exist\n");
				choice = ' ';
			}
		}
		else{
			printf("Maximum number of items in cart reached. Press enter to go back\n");
			fflush(stdin);
			getchar();
			system("cls");
			choice = ' ';

		}

	}
	
}

/*

Displays a receipt per transaction that the user made.

@param(Transactions[])aTrans array of structure for the transaction made by the user
@param(int) numTrans is the total number of transactions made by the user
@param(Users[]) aUser is the array of structures that contains user information
@param(int) numUsers is the total number of current registered users.


@return(void) no return value
*/

void displayReceipt(Transactions aTrans[], int numTrans, Users aUser[], int numUsers){
	int i, j;
	int userIndex;
	
	for(i = 0; i < numTrans; i++){
		printf("------------------------------------- Transaction %02d -----------------------------------\n", i + 1);
		itemHeader();
		for(j = 0; j < aTrans[i].numItems; j++){	
			printItems(&aTrans[i].aItem[j]);
			aTrans[i].total += aTrans[i].aItem[j].price * aTrans[i].aItem[j].quantity ;		
		}
		printf("\n---------------------------------------------------------------------------------------------------------\n");
		userIndex = searchUser(aUser, numUsers, aTrans[i].sellerId);
		printf("\n\t\t Seller Id: %d", aTrans[i].sellerId);
		printf("\n\t\t Seller Name: %s", aUser[userIndex].name);
		printf("\n\t\t Total Price: %.2f ", aTrans[i].total);	
		printf("\n\n");
		printf("\n---------------------------------------------------------------------------------------------------------\n\n\n");
	}
	
	
	
}

/*

A specific product chosen by the user in their cart will be checked out and will be saved to transactions.dat

@param(Users[]) aUser is the array of structures that contains user information
@param(int) numUsers is the total number of current registered users.
@param(Dates) structure for the date that the transaction was made
@param(Users*) currUser is the pointer to the address of the current user that is logged in 

@return(void) no return value
*/

void checkOutByProdId(Users aUser[], int numUsers ,Dates date, Users *currUser){
	int i, j;
	int numTrans = 0;
	int userIndex, itemIndex, prodIndex;
	int prodId; 
//	int countCart = 0;
	Transactions aTrans[MAX_CART];
	
		
	if(currUser->numCart > 0){
		printf("Enter product Id to checkout: ");
		scanf("%d", &prodId);	
		
		prodIndex = searchItem(currUser->cart, currUser->numCart, prodId);
		
		if(prodIndex == - 1)
			printf("Product Id not found\n");
			
		else{
			
			initTrans(&currUser->cart[prodIndex], aTrans, &numTrans, 1);
			displayReceipt(aTrans, numTrans, aUser, numUsers);
			
			for(i = 0; i < numTrans; i++){
				aTrans[i].buyerId = currUser->userId;
		//		printf("%d", aTrans[i].buyerId);
				aTrans[i].transDate = date;
				for(j = 0; j < aTrans[i].numItems; j++){
					userIndex = searchUser(aUser, numUsers, aTrans[i].sellerId);
					itemIndex = searchItem(aUser[userIndex].item, aUser[userIndex].numItems, aTrans[i].aItem[j].productId);
					itemQuantity(&aUser[userIndex].item[itemIndex], aTrans[i].aItem[j].quantity, '-');
					removeItemsById(currUser->cart, &currUser->numCart, aTrans[i].aItem[j].productId);
					
				}
			} 
			writeTrans(aTrans, numTrans);
		}	
	}
	else
		printf("You have nothing to checkout\n\n");
	
}

/*

The products by a specific seller chosen by the user in their cart will be checked out and will be saved to transactions.dat

@param(Users[]) aUser is the array of structures that contains user information
@param(int) numUsers is the total number of current registered users.
@param(Dates) structure for the date that the transaction was made
@param(Users*) currUser is the pointer to the address of the current user that is logged in 

@return(void) no return value
*/
void checkOutBySeller(Users aUser[], int numUsers ,Dates date, Users *currUser){
	int i, j;
	int numTrans = 0;
	int userIndex, itemIndex, sellerIndex;
	int sellerId; 
	int countCart = 0;
	Transactions aTrans[MAX_CART];
	Items tempCart[MAX_CART];
	
		
	if(currUser->numCart > 0){
		printf("Enter seller Id to checkout: ");
		scanf("%d", &sellerId);	
		
		sellerIndex = searchItemBySeller(currUser->cart, currUser->numCart, sellerId);
		
		if(sellerIndex == - 1)
			printf("Seller Id not found\n");
			
		else{
		
			for(i = 0; i < currUser->numCart; i++){
				if(currUser->cart[i].sellerId == sellerId){
					tempCart[countCart] = currUser->cart[i];
					countCart++;
				}
			}
			
			initTrans(tempCart, aTrans, &numTrans, countCart);
			displayReceipt(aTrans, numTrans, aUser, numUsers);
			
			for(i = 0; i < numTrans; i++){
				aTrans[i].buyerId = currUser->userId;
		//		printf("%d", aTrans[i].buyerId);
				aTrans[i].transDate = date;
				for(j = 0; j < aTrans[i].numItems; j++){
					userIndex = searchUser(aUser, numUsers, aTrans[i].sellerId);
					itemIndex = searchItem(aUser[userIndex].item, aUser[userIndex].numItems, aTrans[i].aItem[j].productId);
					itemQuantity(&aUser[userIndex].item[itemIndex], aTrans[i].aItem[j].quantity, '-');
					removeItemsById(currUser->cart, &currUser->numCart, aTrans[i].aItem[j].productId);
					
				}
			}
			writeTrans(aTrans, numTrans); 
		}	
	}
	else
		printf("You have nothing to checkout\n\n");
	
}

/*

All the products in the user's cart will be checked out and will be saved to transactions.dat

@param(Users[]) aUser is the array of structures that contains user information
@param(int) numUsers is the total number of current registered users.
@param(Dates) structure for the date that the transaction was made
@param(Users*) currUser is the pointer to the address of the current user that is logged in 

@return(void) no return value
*/

void checkOutAll(Users aUser[], int numUsers ,Dates date, Users *currUser){
	int i, j;
	int numTrans = 0;
	int userIndex, itemIndex;
	Transactions aTrans[MAX_CART];
	

	
	if(currUser->numCart > 0){
		initTrans(currUser->cart, aTrans, &numTrans, currUser->numCart);
		displayReceipt(aTrans, numTrans, aUser, numUsers);
		
		for(i = 0; i < numTrans; i++){
			aTrans[i].buyerId = currUser->userId;
			aTrans[i].transDate = date;
			for(j = 0; j < aTrans[i].numItems; j++){
				userIndex = searchUser(aUser, numUsers, aTrans[i].sellerId);
				itemIndex = searchItem(aUser[userIndex].item, aUser[userIndex].numItems, aTrans[i].aItem[j].productId);
				itemQuantity(&aUser[userIndex].item[itemIndex], aTrans[i].aItem[j].quantity, '-');
				removeItemsById(currUser->cart, &currUser->numCart, aTrans[i].aItem[j].productId);

			}

		} 
		writeTrans(aTrans, numTrans);
	}
	else
		printf("You have nothing to checkout\n\n");
	
}
/*

The user is presented with the options for checkout (ie. checkout all, checkout by seller, checkout by product)

@param(Users*) aUser is the pointer to the address of the current user that is logged in 
@param(int) numUsers is the total number of current registered users.
@param(int) index is the index of the current logged in user. 
@return(void) no return value
*/


void checkOutMenu(Users *aUser, int numUsers, int index){
	int option, changes = 0;
	Dates date;
	
	printf("= = = = Enter date = = = =\n");
	date = getDate();
	
	changes = checkChanges(aUser->cart, aUser - index, aUser->numCart, numUsers);
	if(changes == 1){
		printf("Press enter to proceed to edit cart...\n");
		getchar();
		system("cls");
		editCart(aUser->cart, &aUser->numCart, aUser, numUsers, index);
	}
	
	do{
		printf("\n= = = = Check Out Menu = = = =\n");
		printf("[1]Check Out All\n[2]Check Out By Specific Seller\n[3]Check Out By Specific Item\n[4]Exit\n");
		
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		
		switch(option){
			case 1:
				checkOutAll(aUser - index, numUsers, date, aUser);
				break;
			case 2:
				checkOutBySeller(aUser - index, numUsers, date, aUser);
				break;
			case 3:
				checkOutByProdId(aUser - index, numUsers, date, aUser);
				break;
			case 4:
				break;
			default:
				break;
		}
		
	}while(option != 4);
	
	
}


/*

The user is presented with the options for buying (ie. view all products, add to cart, checkout, etc.)

@param(Users*) aUser is the pointer to the address of the current user that is logged in 
@param(int) numUsers is the total number of current registered users.
@param(int) index is the index of the current logged in user. 
@return(void) no return value
*/

void buyMenu(Users *aUser, int numUsers, int index){
	int option;
	String15 categ;
	String20 keyword;
	
	
	readCart(aUser);
	
	do{
		printf("\n= = = =Buy Menu = = = =\n");
		printf("[1]View All Products\n[2]Show All Products by Seller\n[3]Search Products By Category\n[4]Search Products By Name\n");
		printf("[5]Add to Cart\n[6]Edit Cart\n[7]Check out\n[8]Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		
		switch(option){
			case 1:
				displayAllProd(aUser - index, numUsers, aUser);
				break;
			case 2:
				system("cls");
				displayBySeller(aUser - index, numUsers);
				break;
			case 3:
				printf("Enter category: ");
				getStringInput(categ, STRING15);
				toUpperCase(categ);
				displayByCateg(aUser - index, numUsers, categ, aUser);
				break;
			case 4:
				printf("Enter item name: ");
				getStringInput(keyword, STRING20);
				toUpperCase(keyword);
				searchByName(aUser - index, numUsers, keyword, aUser);
				break;
			case 5:
				system("cls");
				addToCart(aUser - index, numUsers, aUser);
				break;
			case 6:
				system("cls");
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


/*
Displays a header for the information of the users 
@return(void) no return value
*/

void usersHeader(){
	//adminMenu()
	printf("|%-10s|", "User Id");
	printf("|%-10s|", "Password");
	printf("|%-20s|", "Name");
	printf("|%-30s|", "Address");
	printf("|%-15s|", "Contact Number");
//	printf("\n");
	printf("\n----------------------------------------------------------------------------------------------\n");
	
}


/*
Displays a header for the information of the sellers 
@return(void) no return value
*/

void sellersHeader(){
	printf("|%-10s|", "User Id");
	printf("|%-10s|", "Password");
	printf("|%-20s|", "Name");
	printf("|%-30s|", "Address");
	printf("|%-15s|", "Contact Number");
	printf("|%-12s|", "No. of items");
	printf("\n-------------------------------------------------------------------------------------------------------------\n");
}


/*

Prints the user information with the corresponding variables inside the Users structure.

@param(Users*) aUser is the pointer to the address of a specific user.
@return(void) no return value
*/

void printUsers(Users *aUser){
	
	printf("|%10d|", aUser->userId);
	printf("|%-10s|", aUser->password);
	printf("|%-20s|", aUser->name);
	printf("|%-30s|", aUser->address);
	printf("|%15d|", aUser->contactNum);
	
}



/*

Displays all users  necessary information

@param(Users[]) aUser is the array of structures that contains user information
@param(int) numUsers is the total number of current registered users.
@return(void) no return value
*/

void displayAllUsers(Users aUser[], int numUsers){
	int i;
	
	for(i = 0; i < numUsers; i++){
		printUsers(&aUser[i]);
		printf("\n");
	}	
	
}


/*

Displays sellers necessary information

@param(Users[]) aUser is the array of structures that contains user information
@param(int) numUsers is the total number of current registered users.
@return(void) no return value
*/

void displaySellers(Users aUser[], int numUsers){
	int i, seller = 0;
	
	for(i = 0; i < numUsers; i++){
		if(aUser[i].numItems > 0){
			printUsers(&aUser[i]);
			printf("|%12d|", aUser[i].numItems);
			printf("\n");
			seller++;
		}
	}
	if(seller <= 0 )
		printf("No sellers\n");
	
}


/*

The user is presented with the total amount of bought by each buyer within the date range

@param(Users[]) aUser is the array of structures that contains user information
@param(int) numUsers is the total number of current registered users.
@return(void) no return value
*/


void shopaholics(Users aUser[], int numUsers){
	int numTrans, i;
	int found = 0;
	int index;
	Dates startDate;
	Dates endDate;
	Transactions aTrans;
	Transactions temp[MAX_USERS];
	FILE *fp;
	
	printf("= = = = Enter start date = = = =\n");
	startDate = getDate();
	
	printf("= = = = Enter end date = = = =\n");
	endDate = getDate();
	
	if((fp = fopen("Transactions.dat", "rb")) != NULL){
		numTrans = 0;
		while((fread(&aTrans, sizeof(Transactions), 1, fp)) == 1){
			if(convertDate(aTrans.transDate) >= convertDate(startDate)  && convertDate(aTrans.transDate) <= convertDate(endDate)){
				i = 0;
				found = 0;
				while(i < numTrans){
					if(temp[i].buyerId == aTrans.buyerId){
						temp[i].total += aTrans.total;
						found = 1;
					}
					i++;
				}
		
				if(found == 0){
					temp[numTrans].buyerId = aTrans.buyerId;
					temp[numTrans].total = aTrans.total;
					numTrans++;
				}		
			}
		}
		fclose(fp);
	}

//	sortTransBySeller(temp, count);
	if(numTrans > 0){
		printf("\nTotal sales per buyer  from %d-%d-%d to %d-%d-%d", startDate.month, startDate.day, startDate.year, endDate.month,
																	endDate.day, endDate.year);
		printf("\n---------------------------------------------\n");
		printf("|%-10s|","User Id");
		printf("|%-20s|", "Name");
		printf("|%-11s|", "Total Sales");
		printf("\n---------------------------------------------\n");
		for(i = 0; i < numTrans; i++){
			index = searchUser(aUser, numUsers, temp[i].buyerId);
			printf("|%10d|",temp[i].buyerId);
			printf("|%-20s|", aUser[index].name);
			printf("|%11.2f|", temp[i].total);
			printf("\n");
		}
	}
	else
		printf("No transactions made from %d-%d-%d to %d-%d-%d", startDate.month, startDate.day, startDate.year, endDate.month,
																	endDate.day, endDate.year);
	
}

/*

The user is presented with the total sales that the seller made within the certain date range.

@param(Users[]) aUser is the array of structures that contains user information
@param(int) numUsers is the total number of current registered users.
@return(void) no return value
*/

void totalSalesPerSeller(Users aUser[], int numUsers){
	int numTrans, i;
	int found = 0;
	int index;
	Dates startDate;
	Dates endDate;
	Transactions aTrans;
	Transactions temp[MAX_USERS];
	FILE *fp;
	
	printf("= = = = Enter start date = = = =\n");
	startDate = getDate();
	
	printf("= = = = Enter end date = = = =\n");
	endDate = getDate();
	
	if((fp = fopen("Transactions.dat", "rb")) != NULL){
		numTrans = 0;
		while((fread(&aTrans, sizeof(Transactions), 1, fp)) == 1){
			if(convertDate(aTrans.transDate) >= convertDate(startDate)  && convertDate(aTrans.transDate) <= convertDate(endDate)){	
				i = 0;
				found = 0;
				while(i < numTrans){
					if(temp[i].sellerId == aTrans.sellerId){
						temp[i].total += aTrans.total;
						found = 1;
					}
					i++;
				}
		
				if(found == 0){
					temp[numTrans].sellerId = aTrans.sellerId;
					temp[numTrans].total = aTrans.total;
					numTrans++;
				}
			}
		}
		fclose(fp);
	}
	
//	sortTransBySeller(temp, count);
	if(numTrans > 0){
		printf("\nTotal sales per seller  from %d-%d-%d to %d-%d-%d", startDate.month, startDate.day, startDate.year, endDate.month,
																	endDate.day, endDate.year);
		printf("\n---------------------------------------------\n");
		printf("|%-8s|","User Id");
		printf("|%-20s|", "Name");
		printf("|%-11s|", "Total Sales");
		printf("\n---------------------------------------------\n");
		for(i = 0; i < numTrans; i++){
			index = searchUser(aUser, numUsers, temp[i].sellerId);
			printf("|%8d|",temp[i].sellerId);
			printf("|%-20s|", aUser[index].name);
			printf("|%11.2f|", temp[i].total);
			printf("\n");
		}
	}
	else
		printf("No transactions made from %d-%d-%d to %d-%d-%d", startDate.month, startDate.day, startDate.year, endDate.month,
																	endDate.day, endDate.year);


}

/*

The user will be shown the total sales that is done within the certain date range. 

@return(void) no return value
*/

void showTotalSales(){
	float sales = 0;
	Dates startDate;
	Dates endDate;
	Transactions aTrans;
	FILE *fp;
	
	printf("= = = = Enter start date = = = =\n");
	startDate = getDate();
	
	printf("= = = = Enter end date = = = =\n");
	endDate = getDate();
	
	system("cls");
	
	if((fp = fopen("Transactions.dat", "rb")) != NULL){
		while((fread(&aTrans, sizeof(Transactions), 1, fp)) == 1){
			if( convertDate(aTrans.transDate) >= convertDate(startDate)  && convertDate(aTrans.transDate) <= convertDate(endDate)){
				sales += aTrans.total;
			}
		}
		
	}
	fclose(fp);

	if(sales == 0.00)
		printf("No transactions made from %d-%d-%d to %d-%d-%d", startDate.month, startDate.day, startDate.year, endDate.month,
																	endDate.day, endDate.year);
	else
		printf("Total Sales from %d-%d-%d to %d-%d-%d:\n = = = = %.2f = = = =\n", startDate.month, startDate.day, startDate.year, endDate.month,
														endDate.day, endDate.year, sales);
	
}

/*

The user will select a year and two different months and will be shown the total sales for each.

@return(void) no return value
*/
void compareSalesPerMonth(){
	
	int year;
	int month1, month2;
	float salesMonth1 = 0, salesMonth2 = 0;
	
	Transactions aTrans;
	FILE *fp;
	
	printf("Enter year: ");
	scanf("%d", &year);
	printf("Enter two (2) months you want to compare:\n");
	
	printf("Enter month 1: ");
	scanf("%d", &month1);
	printf("Enter month 2: ");
	scanf("%d", &month2);
	fflush(stdin);
	
	if((fp = fopen("Transactions.dat", "rb")) != NULL){
		while((fread(&aTrans, sizeof(Transactions), 1, fp)) == 1){
			if(aTrans.transDate.year == year){
				
				if(month1 == aTrans.transDate.month)
					salesMonth1 += aTrans.total;
					
				else if(month2 == aTrans.transDate.month)
					salesMonth2 += aTrans.total;
			}
		}
		
	}
	fclose(fp);
	
	if(salesMonth1 == 0.00)
		printf("No sales for the month of %s\n", stringMonth(month1));
		
	else
		printf("%s sales = %.2f\n", stringMonth(month1), salesMonth1);
		
	if(salesMonth2 == 0.00)
		printf("No sales for the month of %s\n", stringMonth(month2));
	
	else
		printf("%s sales = %.2f\n", stringMonth(month2), salesMonth2 );
	
}


/*

The user is presented with the options of show all users, sellers, and show total sales and seller sales

@param(Users[]) aUser is the array of structures that contains user information
@param(int) numUsers is the total number of current registered users.
@return(void) no return value
*/

void adminMenu(Users aUser[], int numUsers){
	int option;
	
	do{
		printf("\n= = = = Admin Menu = = = =\n\n");
		printf("[1]Show All Users\n[2]Show All Sellers\n[3]Show Total Sales\n[4]Compare Monthly Sales\n[5]Show Sellers Sales\n");
		printf("[6]Show Shopaholics\n[7]Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		
		switch(option){
			case 1:
				if(numUsers > 0){
					system("cls");
					usersHeader();
					displayAllUsers(aUser, numUsers);
				}
				else
					printf("No users at the moment\n");
				break;
			case 2:
				system("cls");
				sellersHeader();
				displaySellers(aUser, numUsers);
				break;
			case 3:
				system("cls");
				showTotalSales();
				break;
			case 4:
				system("cls");
				compareSalesPerMonth();
				break;
			case 5:
				totalSalesPerSeller(aUser, numUsers);
				break;
			case 6:
				shopaholics(aUser, numUsers);
				break;
			case 7:
				break;
			default:
				break;
		}
		
	}while(option != 7);
	
}

/*

The user is presented with the options of sell menu and buy menu

@param(Users*) aUser is the pointer to the address of the current user that is logged in 
@param(int) numUsers is the total number of current registered users.
@param(int) index is the index of the current logged in user. 
@return(void) no return value
*/


void userMenu(Users *aUser, int numUsers, int index){
	int option = 0;
	
	
	do{
		printf("\n= = = = User Menu = = = =\n");
		printf("[1]Sell Menu\n[2]Buy Menu\n[3]Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		switch(option){
			case 1:
				system("cls");
				sellMenu(aUser, numUsers, index); 
//				printf("Sell Menu\n");
				break;
			case 2:
				buyMenu(aUser, numUsers, index);
				break;
			case 3:
				writeCart(aUser);
				break;
			default:
				break;
		}
	

	}while(option != 3);
	
}

/*

The user enters their user id and password. If the login is successful the user is directed to the userMenu function.

@param(Users[]) aUser is the array of structures that contains user information
@param(int) numUsers is the total number of current registered users.
@return(void) no return value
*/

void login(Users aUser[], int numUsers){
	int id;
	int getUserIndex ;
	String10 password;
	
		printf("= = = = LOGIN = = = = \n");
		
		printf("Enter User ID: ");
		scanf("%d", &id);
		fflush(stdin);
		
		
		printf("Enter Password: ");
		getStringInput(password, STRING10);
	
		
		getUserIndex = searchUser(aUser, numUsers, id);
		
		
		if(getUserIndex == -1)	{	
			printf("User not found...press enter to go back to main menu\n");
			getchar();
			system("cls");
		}
			
		else{
			if(id == aUser[getUserIndex].userId && strcmp(password, aUser[getUserIndex].password) == 0){
				system("cls");
				userMenu(&aUser[getUserIndex], numUsers, getUserIndex);
			}

			else{
				printf("Invalid password...press enter to go back to main menu\n");
				getchar();
				system("cls");
			}
		}
	
}

/*
Adds and saves a user to the program where the user is tasked to input all the necessary information. 

@param(Users) Users aUser[] is the array of structures that contains user information
@param(int*) numUsers updates the total number of registered users
@return(void) no return value
*/

void registerUser(Users aUser[],  int *numUsers){

	int id;
	int index; 
	
	
	if( (*numUsers) < MAX_USERS){
		printf("= = = = REGISTER = = = =\n");
		(*numUsers)++;

		index = *numUsers - 1;
	
		
		do{
			printf("Enter User ID: ");
			scanf("%d", &id);
			fflush(stdin);
			
			if(searchUser(aUser, index, id) != -1)
				printf("User already exists\n");
			
		}while(searchUser(aUser, index, id) != -1);
		
		aUser[index].userId = id;
		
		
		printf("Enter name: ");
		getStringInput(aUser[index].name, STRING20);		
		
		printf("Enter password: ");
		getStringInput(aUser[index].password, STRING10);	

		
		printf("Enter address: ");
		getStringInput(aUser[index].address, STRING30);	
		
		
		printf("Enter contact number: ");
		scanf("%d", &aUser[index].contactNum);
		fflush(stdin);
		
		aUser[index].numItems = 0;
		aUser[index].numCart = 0;
		
		printf("Register Successful! Press enter to continue...\n");
		getchar();
		system("cls");
	}
	else{
		printf("Max number of users reached! Press enter to go back to main menu...\n");
		getchar();
		system("cls");	
	}
}

/*
Main function handles the main menu of the program. 
@return (int) return 0

*/
int main(){
	Users aUser[MAX_USERS];
	int numUsers = 0;
	int option; 
	String10 password;
	
	numUsers = readFile(aUser);
	readItem(aUser, numUsers);
	writeUser(aUser, numUsers);
	
	
	printf("= = = = SHOPPING APP = = = =\n");
	
	do{
		printf("\n= = = = Main Menu = = = =\n\n");
		printf("[1] Register\n[2] Login\n[3] Admin Menu\n[4] Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		switch(option){
			case 1:
				system("cls");
				registerUser(aUser, &numUsers);
				break;
			case 2:
				system("cls");
				login(aUser, numUsers);
				break;
			case 3:
				printf("Verify password: ");
				getStringInput(password, STRING10);
				
				if(strcmp(password, "H3LLo?") == 0)
					adminMenu(aUser, numUsers);
				else{
					printf("Incorrect password...Returning to main menu");
					option = 0;
				}
				break;
			case 4:
				writeUser(aUser, numUsers);
				writeItem(aUser, numUsers);
				break;
			default:
				break;
		}
		
	}while(option != 4);
	
	
	return 0;
}
