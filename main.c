#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRING10 11
#define STRING20 21
#define STRING15 16	
#define STRING30 31
#define MAX_USERS 100
#define MAX_ITEMS 20


typedef char String10[STRING10];
typedef char String20[STRING20];
typedef char String30[STRING30];
typedef char String15[STRING15];

typedef struct User{
	int userId;
	String20 name;
	String10 password;
	String30 address;
	long contactNum;
}Users;

typedef struct Item{
	int productId;
	int quantity;
	int sellerId;
	float price;
	String20 name;
	String15 category;
	String30 description;
	
}Items;

typedef struct Transaction{
	int month;
	int day;
	int year;
	int buyerId;
	int sellerId;
	
}Transactions;

//typedef struct User Users;
//typedef struct Item Items;
//typedef struct Transaction Transactions;

void mainMenu(Users aUser[], Items aItem[][MAX_ITEMS], Transactions aTransaction[], int numUser){
	int option = 0;
	do{
		printf("Main Menu\n");
		printf("[1] User Menu\n[2] Buy Menu\n[3] Admin Menu\n[4] Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		switch(option){
			case 1: 
				printf("User Menu\n");
				break;
			case 2:
				printf("Buy Menu\n");
				break;
			case 3:
				printf("Admin Menu\n");
				break;
			case 4:
				break;
		}
	

	}while(option >= 1 && option <= 3);
	
}

void registerUser(Users aUser[], Items aItem[][MAX_ITEMS], Transactions aTransaction[], int *userId){
	
	String10 num;
	int id;
	
	(*userId)++;
	id = *userId;
	
	aUser[id - 1].userId = *userId;
	printf("Enter name: ");
	fgets(aUser[id - 1].name, STRING20, stdin);
	printf("Enter password: ");
	fgets(aUser[id - 1].password, STRING10, stdin);
	printf("Enter address: ");
	fgets(aUser[id - 1].address, STRING30, stdin);
	printf("Enter contact number: ");

	fgets(num, STRING10, stdin);
	aUser[id - 1].contactNum = strtol(num, NULL, 0);

	mainMenu(aUser, aItem, aTransaction, *userId);
	
	
}





int main(){
	Users aUser[MAX_USERS];
	Items aItem[MAX_USERS][MAX_ITEMS];
	Transactions aTransaction[MAX_USERS];
	int numUsers = 0;
	int option; 
	int i;
	FILE *fp_user;
	
	fp_user = fopen("Users.txt", "w");
	
	
	printf("Shopping App\n");
	
	do{
		printf("[1] Register\n[2] Login\n[3] Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		switch(option){
			case 1:
				registerUser(aUser, aItem, aTransaction, &numUsers);
				break;
			case 2:
				printf("login\n");
				break;
			case 3:
				for(i = 0; i < numUsers; i++){
					fprintf(fp_user, "%d %s\n", aUser[i].userId, aUser[i].password);
					fprintf(fp_user, "%s\n%s",aUser[i].name, aUser[i].address);
					fprintf(fp_user, "%d\n\n",aUser[i].contactNum);
				}
				
				break;
			default:
				break;
		}
		
	}while(option >= 1 && option <= 2);
	 
	fclose(fp_user);
	return 0;
}
