#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shopping.h"






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

void login(Users aUser[], int numUsers){
	int id;
	int getUserIndex;
	String10 password;
	
	
	printf("Enter User ID: ");
	scanf("%d", &id);
	fflush(stdin);
	
	printf("Enter Password: ");
	fgets(password, STRING10, stdin);
	password[strlen(password) - 1] = '\0';
	
	getUserIndex = searchUser(aUser, numUsers, id);
	printf("%d\n", getUserIndex);
	if(getUserIndex == -1)
		printf("User not found\n");
	else{
		if(id == aUser[getUserIndex].userId && strcmp(password, aUser[getUserIndex].password) == 0)
			printf("Success\n");
		else
			printf("wrong credentials\n");
	}
		
	
	
}

int main(){
	Users aUser[MAX_USERS] 
	 = {
		{
			15, "Tyrone", "hi", "49 Macopa", 9153001
		},
		{
			1, "Justin", "hello", "10 Don manuel", 12345
		}
	};
	
	Transactions aTransaction[MAX_USERS];
	int numUsers = 2;
	int i;
	login(aUser, numUsers);
//	sort(aUser, numUsers);
//	
//	for(i = 0; i < numUsers; i++ )
//		printf("%d\n", aUser[i].userId);
//	if(searchUser(aUser, numUsers, 16) == - 1)
//		printf("not found");	
	
	
	return 0;
}


