/*
 Removes the excess \n from a string and converts it to \0

@param(char[])str is a string with no limit to the number of values 

@return(void) no return value
*/

void removeEnter(char str[]){
	str[strlen(str) - 1] = '\0';
	
}

/*

Swaps the users structure of the first and second transaction

@param(Users*) x is a pointer to the address of the first user
@param(Users*) y is a pointer to the address of the second user
@return(void) no return value
*/

void swap(Users *x, Users *y){
	Users temp;
	temp = *x; 
	*x = *y;
	*y = temp;
	
}

/*

Searches if the user exists or not 

@param(Users[]) aUser is an array of structure of the users information
@param(int) id is the product id of the item to be searched
@param(int) numUsers is total number of users

@return(int) returns 0 if the product does not exist and returns the 1 if the product exists  
*/
// int search(Users aUser[], int id, int numUsers){
// 	int i;
// 	int found = 1; 
	
// 	for(i = 0; i < numUsers; i++){
// 		if(id == aUser[i].userId)
// 			found = 0;
// 	}
	
// 	return found;
	
// }

/*

Searches if the product exists or not 

@param(Users[]) aUser is an array of structure of the users information
@param(int) numUsers is total number of users
@param(int) id is the product id of the item to be searched

@return(int) returns 0 if the product does not exist and returns the 1 if the product exists  
*/
int searchProdId(Users aUser[], int numUsers, int id){
	int i, j;
	int found = 0;
	
	// aUser -= index;
	for(i = 0; i < numUsers && found == 0; i++){
		for(j = 0; j < aUser[i].numItems && found == 0; j++){
			if(id == aUser[i].item[j].productId)
				found = 1;
		}
	}

	return found;

}

/*

Sorts users by its user id 

@param(Users[]) aUser is an array of structure of the users information
@param(int) numUsers is total number of users

@return(void) no return value
*/
void sort(Users aUser[], int numUsers){
	int i, j;
	
	for(i = 0 ; i < numUsers - 1; i++){
		for(j = i + 1; j < numUsers; j++){
			if(aUser[i].userId > aUser[j].userId)
				swap(&aUser[i], &aUser[j]);	
			
		}
	}
}


/*

Swaps the items structure of the first and second transaction

@param(Items*) x is a pointer to the address of the first item
@param(Items*) y is a pointer to the address of the second item
@return(void) no return value
*/

void swapItem(Items *x, Items *y){
	Items temp;
	temp = *x;
	*x = *y;
	*y = temp;

}

/*

Swaps the transactions structure of the first and second transaction

@param(Transactions*) x is a pointer to the address of the first transaction
@param(Transactions*) y is a pointer to the address of the second transaction
@return(void) no return value
*/
void swapTrans(Transactions *x, Transactions *y){
	Transactions temp;
	temp = *x;
	*x = *y;
	*y = temp;

}

/*

Sorts items by its total sales
@param(Items[]) item is an array of structure of the items information
@param(int) numItems is total number of items
@return(void) no return value
*/

void sortItemByPrice(Items item[], int numItems){
	int i, j;
	for(i = 0 ; i < numItems - 1; i++){
		for(j = i + 1; j < numItems; j++){
			if(item[i].price < item[j].price)
				swapItem(&item[i], &item[j]);	
		}
	}
}

/*

Sorts items by the number of quantity sold
@param(Items[]) item is an array of structure of the items information
@param(int) numItems is total number of items
@return(void) no return value
*/

void sortItemByQuantity(Items item[], int numItems){
	int i, j;
	for(i = 0 ; i < numItems - 1; i++){
		for(j = i + 1; j < numItems; j++){
			if(item[i].quantity < item[j].quantity)
				swapItem(&item[i], &item[j]);	
		}
	}
}


/*

Sorts items by its seller id 
@param(Items[]) item is an array of structure of the items information
@param(int) numItems is total number of items
@return(void) no return value
*/

void sortItemBySeller(Items item[], int numItems){
	int i, j;
	
	for(i = 0 ; i < numItems - 1; i++){
		for(j = i + 1; j < numItems; j++){
			if(item[i].sellerId > item[j].sellerId)
				swapItem(&item[i], &item[j]);	
			
		}
	}
}


/*
Sorts the transactions by seller id  

@param(Transactions[])aTrans is an array of structures for the transactions of a user.
@param(int)numTrans is the total number of transactions of a user
@return(void) no return value
*/

void sortTransBySeller(Transactions aTrans[], int numTrans){
	int i, j;
	for(i = 0 ; i < numTrans - 1; i++){
		for(j = i + 1; j < numTrans; j++){
			if(aTrans[i].sellerId > aTrans[j].sellerId)
				swapTrans(&aTrans[i], &aTrans[j]);	
			
		}
	}
}

/*

Searches for the index of the product id searched 

@param(Items[]) item is an array of structure of the items information
@param(int) numUsers is total number of users
@param(int) itemInput is the product id of the item to be searched
@return(int) returns -1 if the product does not exist and returns the index if the product exists  
*/
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

/*

Searches for the index of the seller id searched 

@param(Items[]) item is an array of structure of the items information
@param(int) numUsers is total number of users
@param(int) sellerId is the id of the seller to be searched
@return(int) returns -1 if the seller id does not exist and returns the index if the seller id exists  
*/
int searchItemBySeller(Items item[], int numItems, int sellerId){
	int i;
	int found = 0;
	int itemIndex = -1	;
	
	for(i = 0; i < numItems && found == 0 ; i++){
		if(sellerId == item[i].sellerId){
			itemIndex = i;
			found = 1;
		}	
	}
			
	return itemIndex;
}


/*

Searches for the index of the user id searched 

@param(Users[]) aUser is an array of structure of the users information
@param(int) numUsers is total number of users
@param(int) userInput is the user id to be searched
@return(int) returns -1 if the user id does not exist and returns the index if the user id exists  
*/

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

/*
Function to get a string input and removes the excess \n and converts it to \0

@param(char[])str is a string with no limit to the number of values 
@param(int) length is the length of the string 

@return(void) no return value
*/

void getStringInput(char str[], int length){
	fgets(str, length, stdin);
	removeEnter(str);
}


/*
Converts strings to upper case

@param(char[])str is a string with no limit to the number of values 
@return(void) no return value
*/
void toUpperCase(char str[]){
	int j;

	for(j = 0; j < strlen(str); j++){
		if(str[j] >= 'a' && str[j] <= 'z')
			str[j] -= 32;
	}


}

/*

Initializes users items to a 2d array structure of items 

@param(Items[][]) tempItem is a 2d array of structures 
@param(Users[]) aUser is an array of structure of the users information
@param(int) numUsers is total number of users
@return(void) no return value
*/

void initTempItem(Items tempItem[][MAX_ITEMS], Users aUser[], int numUsers){
	int i, j;
	for(i = 0 ; i < numUsers; i++){
		for(j = 0; j < aUser[i].numItems; j++){
			tempItem[i][j] = aUser[i].item[j];
		}
	}

}

/*

This modifies an item's quantity.

@param(Items*) item is a pointer to an address of a structure of a specific item
@param(int) quantity is the value to be added or subtracted to the item's quantity
@param(char) operation identifies whether the quantity will be added or subtracted
@return(void) no return value
*/

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



/*

The user enters information of a date 

@return(Dates) returns date structure
*/
Dates getDate(){
	Dates tempDate;

	do{
		printf("Enter numeric month: ");
		scanf("%d", &tempDate.month);

		if(tempDate.month < 1 && tempDate.month > 12)
			printf("Invalid month try again\n");

	}while(tempDate.month < 1 && tempDate.month > 12);


	do{

		printf("Enter day: ");
		scanf("%d", &tempDate.day);

		if(tempDate.day < 1 && tempDate.day > 31)
			printf("Invalid day try again\n");

	}while(tempDate.day < 1 && tempDate.day > 31);


	do{

		printf("Enter year: ");
		scanf("%d", &tempDate.year);
		fflush(stdin);

		if(tempDate.year < 0 && tempDate.year > 9999)
			printf("Invalid year try again\n");

	}while(tempDate.year < 0 && tempDate.year > 9999);

	return tempDate;


}



/*

Initializes the user's items in the cart to a transaction array  

@param(Items[]) cart is an array of structure of the users cart information
@param(Transactions[])aTrans is an array of structures for the transactions of a user.
@param(int*)numTrans is the total number of transactions of a user
@param(int) numItems is the total number of items inside the users cart

@return(void) no return value
*/

void initTrans(Items cart[], Transactions aTrans[], int *numTrans, int numItems){

	int i, j, x; 	
	

	j = 0;
	i = 0;
	x = 0;
		aTrans[0].sellerId = cart[0].sellerId;
		aTrans[0].numItems = 0;
		while(i < numItems){
			// aTrans[j].buyerId = currUser->userId;

			if(aTrans[j].sellerId != cart[i].sellerId || x >= 5){
				j++;
				x = 0;
				aTrans[j].numItems = 0;
				aTrans[j].sellerId = cart[i].sellerId;
			}

			aTrans[j].aItem[x] = cart[i];
			aTrans[j].total = 0;
			aTrans[j].numItems++;

			x++;
			i++;
		}

	*numTrans = j + 1;

	// printf("$$$$$$%d$$$$$$$$\n", *numTrans);


}


/*

Checks if there are differences with the current user's cart and the items in stock 

@param(Items[]) cart is an array of structure of the users cart information
@param(Users[]) aUser is an array of structure of the users information
@param(int) numItems is the total number of items inside the users cart
@param(int) numUsers is the total number of users


@return(int) returns 1 if there are changes and 0 if there are not
*/
int checkChanges(Items cart[], Users aUser[], int numItems, int numUsers){
	int i, j;
	int userIndex, itemIndex, currUser;
	int changes = 0;
	for(i = 0; i < numItems; i++){
		userIndex = searchUser(aUser, numUsers, cart[i].sellerId);
		itemIndex = searchItem(aUser[userIndex].item, aUser[userIndex].numItems, cart[i].productId);
		if(aUser[userIndex].item[itemIndex].price != cart[i].price || aUser[userIndex].item[itemIndex].quantity < cart[i].quantity){
			changes = 1;
			if(aUser[userIndex].item[itemIndex].price != cart[i].price){
				printf("\nOld price\tNew Price\n");
				printf("%-9.2f\t%-9.2f\n", cart[i].price, aUser[userIndex].item[itemIndex].price);
				cart[i].price = aUser[userIndex].item[itemIndex].price;
			}
			if(aUser[userIndex].item[itemIndex].quantity < cart[i].quantity){
				printf("Cart Quantity\tCurrent Stock\n");
				printf("%-13d\t%-10d\n", cart[i].quantity, aUser[userIndex].item[itemIndex].quantity);
			}
			
			
		}
		
	}

	return changes;


}


/*
Converts date structure to an integer

@param(Dates) date is the structure of the given date by the user.

@return(int) returns converted integer date
*/
int convertDate(Dates date){

	return date.day + date.month * 100 + date.year * 10000 ;

}

/*

Displays the top 3 best selling items. This is determined by the total number of quantity sold per item.


@return(void) no return value
*/

void displayTopItems(){
	int  i, j, ctr;
	int found = 0;
	Transactions aTrans;
	Items itemStorage[MAX_ITEMS * MAX_USERS];
	FILE *fp;
	
	for(i = 0; i < MAX_ITEMS * MAX_USERS; i++)
		itemStorage[i].productId = -999;
	
	
	if((fp = fopen("Transactions.dat", "rb")) != NULL){
		ctr = 0;
		while((fread(&aTrans, sizeof(Transactions), 1, fp)) == 1){
			found = 0;
			for(i = 0; i < aTrans.numItems; i++){
				found = 0;
				j = 0;
				while(j < MAX_ITEMS * MAX_USERS && found == 0){
					if(itemStorage[j].productId == -999){
						itemStorage[j] = aTrans.aItem[i];
						found = 1;
						ctr++;
					}
					else if(itemStorage[j].productId == aTrans.aItem[i].productId)
						found = 2;


					j++;

				}
			}
			if(found == 2){
				for(i = 0; i < ctr; i++){
					for(j = 0; j < aTrans.numItems; j++){
						if(aTrans.aItem[j].productId == itemStorage[i].productId){
							itemStorage[i].quantity += aTrans.aItem[j].quantity; 
						}
					}
				}
			}
				
		}
		fclose(fp);
	}
	if(ctr > 0){

		sortItemByQuantity(itemStorage, ctr);

		printf("\n\t= = = Top 3 Best Selling Items = = =\n\n");

		printf("|%-10s|","Product Id");
		printf("|%-20s|","Name");
		printf("|%-10s|","Price");
		printf("|%-13s|","Quantity Sold");
		printf("\n-------------------------------------------------------------\n");
		for(i = 0; i < 3; i++){
			if(itemStorage[i].productId != -999){
				printf("|%10d|", itemStorage[i].productId);
				printf("|%-20s|", itemStorage[i].name);
				printf("|%10.2f|", itemStorage[i].price);
				printf("|%13d|", itemStorage[i].quantity);
				printf("\n");
			}
		}
		printf("\n");
	}


}


/*

Displays the top 3 best selling items based on sales made by the seller.

@param(int) userId is the id of the current user which is also the seller. 

@return(void) no return value
*/


void displayTopItemsPerSeller(int userId){

	int  i, j, ctr = 0;
	int found = 0;
	Transactions aTrans;
	Items itemStorage[MAX_ITEMS * MAX_USERS];
	FILE *fp;
	
	for(i = 0; i < MAX_ITEMS * MAX_USERS; i++)
		itemStorage[i].productId = -999;
	
	
	if((fp = fopen("Transactions.dat", "rb")) != NULL){
		ctr = 0;
		while((fread(&aTrans, sizeof(Transactions), 1, fp)) == 1){
			found = 0;
			for(i = 0; i < aTrans.numItems; i++){
				found = 0;
				j = 0;
				while(j < MAX_ITEMS * MAX_USERS && found == 0){
					if(itemStorage[j].productId == -999){
						if(aTrans.sellerId == userId){
							itemStorage[j] = aTrans.aItem[i];
							itemStorage[i].price *= itemStorage[i].quantity;
							found = 1;
							ctr++;
						}
						
					}
					else if(itemStorage[j].productId == aTrans.aItem[i].productId)
						found = 2;


					j++;

				}
			}
			if(found == 2){
				for(i = 0; i < ctr; i++){
					for(j = 0; j < aTrans.numItems; j++){
						if(aTrans.aItem[j].productId == itemStorage[i].productId){
							itemStorage[i].quantity += aTrans.aItem[j].quantity; 
							itemStorage[i].price += (aTrans.aItem[j].price * aTrans.aItem[j].quantity); 

						}
					}
				}
			}
				
		}
		fclose(fp);
	}

		sortItemByPrice(itemStorage, ctr);

		printf("\n= = = My top 3 best selling items based on total sales = = =\n\n");

		printf("|%-10s|","Product Id");
		printf("|%-20s|","Name");
		printf("|%-11s|","Total Sales");
		printf("|%-13s|","Quantity Sold");
		printf("\n--------------------------------------------------------------\n");
		for(i = 0; i < 3; i++){
			if(itemStorage[i].productId != -999){
				printf("|%10d|", itemStorage[i].productId);
				printf("|%-20s|", itemStorage[i].name);
				printf("|%11.2f|", itemStorage[i].price);
				printf("|%13d|", itemStorage[i].quantity);
				printf("\n");
			}
		
		}
		printf("\n");
	

}


/*

Converts an integer month to its corresponding word

@param(int) month is the integer value of the months in the calendar

@return(char *) returns string value of each month. 

*/


static char* stringMonth(int month){

	switch(month){
		case 1:
			return "January";
			break;
		case 2:
			return "February";
			break;
		case 3:
			return "March";
			break;
		case 4:
			return "April";
			break;
		case 5:
			return "May";
			break;
		case 6:
			return "June";
			break;
		case 7:
			return "July";
			break;
		case 8:
			return "August";
			break;
		case 9:
			return "September";
			break;
		case 10:
			return "October";
			break;
		case 11:
			return "November";
			break;
		case 12:
			return "December";
			break;
		default:
			return "Invalid month";
			break;
	}

}