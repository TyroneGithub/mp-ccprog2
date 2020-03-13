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


void sort(Users aUser[], int numUsers){
	int i, j;
	
	for(i = 0 ; i < numUsers - 1; i++){
		for(j = i + 1; j < numUsers; j++){
			if(aUser[i].userId > aUser[j].userId)
				swap(&aUser[i], &aUser[j]);	
			
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