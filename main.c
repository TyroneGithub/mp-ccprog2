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

typedef struct Date{
	int month;
	int day;
	int year;
	
}Dates;

typedef struct Transaction{
	Dates transDate;
	Items aItem[5];
	int buyerId;
	int sellerId;
	int total;
	
}Transactions;



void mainMenu(Users aUser[], Transactions aTransaction[], int numUser){
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

//void swap(int *x, int *y){
//}
	

//void sortId(Users aUser[]){
//	printf("Hello");
//}

int search(Users aUser[], int id, int numUsers){
	int i;
	int found = 1; 
	
	for(i = 0; i < numUsers; i++){
		if(id == aUser[i].userId)
			found = 0;
	}
	
	return found;
	
}


void registerUser(Users aUser[], Transactions aTransaction[], int *numUsers){
	
	String10 num;
	int id;
	
	
	
	
	
	do{
		printf("Enter User ID: ");
		scanf("%d", &id);
	}while(!search(aUser, id, *numUsers));


	aUser[(*numUsers) - 1].userId = id;

	fflush(stdin);
		
	
	printf("Enter name: ");
	fgets(aUser[(*numUsers) - 1].name, STRING20, stdin);
	aUser[(*numUsers) - 1].name[strlen(aUser[(*numUsers)- 1].name) - 1] = '\0'; 
	
	printf("Enter password: ");
	fgets(aUser[(*numUsers) - 1].password, STRING10, stdin);
	aUser[(*numUsers) - 1].password[strlen(aUser[(*numUsers) - 1].password) - 1] = '\0';
	
	printf("Enter address: ");
	fgets(aUser[(*numUsers) - 1].address, STRING30, stdin);
	aUser[(*numUsers) - 1].address[strlen(aUser[(*numUsers) - 1].address) - 1] = '\0';
	
	printf("Enter contact number: ");
	scanf("%ld", &aUser[(*numUsers) - 1].contactNum);
	(*numUsers)++;
	mainMenu(aUser, aTransaction, *numUsers);
	
	
}





int main(){
	Users aUser[MAX_USERS];
	Transactions aTransaction[MAX_USERS];
	int numUsers = 0;
	int option; 
	int i = 0;
	FILE *fp_user;
	
	FILE *fp_userWrite, *fp_userRead;
	
	fp_userRead = fopen("Users.txt", "r");
	
	
//	if(fp_userRead == NULL)
		fp_userWrite = fopen("Users.txt", "w");
//		
//	else
//		fp_userWrite = fopen("Users.txt", "a");
		
	
	while(!feof(fp_userRead)){
		
		fscanf(fp_userRead, "%d %s\n", &aUser[i].userId, aUser[i].password);
		
		fgets(aUser[i].name, STRING20, fp_userRead);
		aUser[i].name[strlen(aUser[i].name) - 1] = '\0';
		
		fgets(aUser[i].address, STRING30, fp_userRead);
		aUser[i].address[strlen(aUser[i].address) - 1] = '\0';
		
		fscanf(fp_userRead,"%d\n",&aUser[i].contactNum);
	
//		printf("ID: %d\npass: %s\nname: %s\naddress: %s\ncontact: %ld\n\n",aUser[i].userId, aUser[i].password, 
//														aUser[i].name, aUser[i].address, aUser[i].contactNum);
														
		i++;
		
	}
	
	numUsers = i;
	printf("%d\n", numUsers);
	
	printf("Shopping App\n");
	
	do{
		printf("[1] Register\n[2] Login\n[3] Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		switch(option){
			case 1:
				registerUser(aUser, aTransaction, &numUsers);
				break;
			case 2:
				printf("login\n");
				break;
			case 3:
				for(i = 0; i < numUsers ; i++){
//					fprintf(fp_userWrite, "%d %s\n", aUser[i].userId, aUser[i].password);
//					fprintf(fp_userWrite, "%s\n%s\n",aUser[i].name, aUser[i].address);
//					fprintf(fp_userWrite, "%d\n\n",aUser[i].contactNum);
					printf("ID: %d\npass: %s\nname: %s\naddress: %s\ncontact: %ld\n\n",aUser[i].userId, aUser[i].password, 
													aUser[i].name, aUser[i].address, aUser[i].contactNum);
													
													
				}
				
				break;
			default:
				break;
		}
		
	}while(option >= 1 && option <= 2);
	
	fclose(fp_userWrite); 
	fclose(fp_userRead);
	
	
	
	return 0;
}
