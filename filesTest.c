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

typedef struct Users{
	int userId;
	String20 name;
	String10 password;
	String30 address;
	long contactNum;
}Users;

typedef struct Items{
	int productId;
	int quantity;
	int sellerId;
	float price;
	String20 name;
	String15 category;
	String30 description;
	
}Items;

typedef struct Transactions{
	int month;
	int day;
	int year;
	int buyerId;
	int sellerId;
	
}Transactions;



int main(){
	struct Users aUser[MAX_USERS] = {
		{
			1, "Tyrone", "123456", "49 Macopa st.", 9153001
		},
		{
			2, "Justin", "666667777", "10 Don manuel", 12345
		}
	};
	struct Items aItem[MAX_USERS][MAX_ITEMS];
	struct Transactions aTransaction[MAX_USERS];
	int numUsers = aUser[1].userId;
	int option; 
	int i;
	FILE *fp_user;
	
	fp_user = fopen("Users.txt", "w");
	
	
	printf("Shopping App\n");
	
	for(i = 0; i < numUsers; i++){
		fprintf(fp_user, "%d %s\n", aUser[i].userId, aUser[i].password);
		fprintf(fp_user, "%s\n%s",aUser[i].name, aUser[i].address);
		fprintf(fp_user, "%d\n\n",aUser[i].contactNum);
	}
	
	
//	do{
//		printf("[1] Register\n[2] Login\n[3] Exit\n");
//		printf("Input: ");
//		scanf("%d", &option);
//		fflush(stdin);
//		switch(option){
//			case 1:
//				registerUser(aUser, aItem, aTransaction, &numUsers);
//				break;
//			case 2:
//				printf("login\n");
//				break;
//			case 3:
//				for(i = 0; i < numUsers; i++){
//					fprintf(fp_user, "%d %s\n", aUser[i].userId, aUser[i].password);
//					fprintf(fp_user, "%s\n%s",aUser[i].name, aUser[i].address);
//					fprintf(fp_user, "%d\n\n",aUser[i].contactNum);
//				}
//				
//				break;
//			default:
//				break;
//		}
//		
//	}while(option >= 1 && option <= 2);
	 
	fclose(fp_user);
	return 0;
	
	return 0;
}

