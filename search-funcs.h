

void removeEnter(char str[]){
	str[strlen(str) - 1] = '\0';
	
}


void swap(Users *x, Users *y){
	Users temp;
	temp = *x; 
	*x = *y;
	*y = temp;
	
}

int search(Users aUser[], int id, int numUsers){
	int i;
	int found = 1; 
	
	for(i = 0; i < numUsers; i++){
		if(id == aUser[i].userId)
			found = 0;
	}
	
	return found;
	
}


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


void sort(Users aUser[], int numUsers){
	int i, j;
	
	for(i = 0 ; i < numUsers - 1; i++){
		for(j = i + 1; j < numUsers; j++){
			if(aUser[i].userId > aUser[j].userId)
				swap(&aUser[i], &aUser[j]);	
			
		}
	}
}


void swapItem(Items *x, Items *y){
	Items temp;
	temp = *x;
	*x = *y;
	*y = temp;

}

void sortItemBySeller(Items item[], int numItems){
	int i, j;
	
	for(i = 0 ; i < numItems - 1; i++){
		for(j = i + 1; j < numItems; j++){
			if(item[i].sellerId > item[j].sellerId)
				swapItem(&item[i], &item[j]);	
			
		}
	}
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

void getStringInput(char str[], int length){
	fgets(str, length, stdin);
	removeEnter(str);
}

void toUpperCase(char str[]){
	int j;

	for(j = 0; j < strlen(str); j++){
		if(str[j] >= 'a' && str[j] <= 'z')
			str[j] -= 32;
	}


}

void initTempItem(Items tempItem[][MAX_ITEMS], Users aUser[], int numUsers){
	int i, j;
	for(i = 0 ; i < numUsers; i++){
		for(j = 0; j < aUser[i].numItems; j++){
			tempItem[i][j] = aUser[i].item[j];
		}
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

void initTrans(Users *currUser, Transactions aTrans[], int *numTrans, int numItems){

	int i, j, x; 	
	

	j = 0;
	
	for(i = 0; i < numItems; i++){
		x = 0;
		aTrans[j].buyerId = currUser->userId;
		aTrans[j].sellerId = currUser->cart[i].sellerId;
		while(x < 5){
			if(aTrans[j].sellerId == currUser->cart[x].sellerId){
				aTrans[j].aItem[x] = currUser->cart[x];
				aTrans[j].numItems++;
			}
			else
				j++;
			
			printf("%d\n", j);

			x++;
		}
		

	}

	*numTrans = j;
	printf("%d", *numTrans);


}