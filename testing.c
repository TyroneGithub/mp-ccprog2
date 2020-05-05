#include <stdio.h>
#include <string.h>
#include "shopping.h"
#include "search-funcs.h"
#include "file-processing.h"



int main(){
	Users aUser[MAX_USERS];
	Transactions aTransaction[MAX_USERS];
	Items item[MAX_USERS * MAX_ITEMS];
	int numUsers = 0;
	int option; 
	int i, j, k = 0;
	String10 password = "hello world";
	
	numUsers = readFile(aUser);
	readItem(aUser, numUsers);
	
//	for(i = 0; i < numUsers; i++){
//		for(j = 0; j < aUser[i].numItems; j++){
//			item[k] = aUser[i].item[j];
//			printf("%.2f\n", item[k].price);
//			k++;
//		}
//	}

	printf("%d", searchProdId(aUser, numUsers, 4402));

//	for(i = 0; i < k; i++){
////		printf("%d\n", item[i].quantity);
//	}
	
	
	
	
	
	
//	printf("%d", searchUser(aUser, numUsers,999));
	
	return 0;
}
