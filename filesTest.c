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




int main(){
	Users aUser[MAX_USERS];
//	 = {
//		{
//			1, "Tyrone", "123456", "49 Macopa", 9153001
//		},
//		{
//			2, "Justin", "666667777", "10 Don manuel", 12345
//		}
//	};
	Transactions aTransaction[MAX_USERS];
	int numUsers = aUser[1].userId;
	int option; 
	int i = 0;
	int userId;
	String20 name;
	String10 password;
	String30 address;
	long contactNum;
	
	
	FILE *fp_userAppend, *fp_userRead;
	
//	fp_userAppend = fopen("Users.txt", "w");
	fp_userRead = fopen("Users.txt", "r");
	
	
	printf("Shopping App\n");



	if(fp_userRead == NULL){
		printf("no data");
	}

	i = 0;
	while(!feof(fp_userRead)){
		
		fscanf(fp_userRead, "%d %s\n", &aUser[i].userId, aUser[i].password);
		
		fgets(aUser[i].name, STRING20, fp_userRead);
		aUser[i].name[strlen(aUser[i].name) - 1] = '\0';
		
		fgets(aUser[i].address, STRING30, fp_userRead);
		aUser[i].address[strlen(aUser[i].address) - 1] = '\0';
		
		fscanf(fp_userRead,"%d\n",&aUser[i].contactNum);
	
		printf("ID: %d\npass: %s\nname: %s\naddress: %s\ncontact: %ld\n\n",aUser[i].userId, aUser[i].password, 
														aUser[i].name, aUser[i].address, aUser[i].contactNum);
														
		i++;
		
	}
	
	
	
	
//	while(fscanf(fp_userRead, "%d %s %s %s %d " ,&userId, password, name, address, &contactNum) == 5){
//			fprintf(stdout, "user id: %d\npassword: %s\nname: %s \naddress: %s\n",userId, password, name, address);
//			
//	}	
	

//	for(i = 0; i < numUsers; i++){
//		fprintf(fp_userAppend, "%d %s\n", aUser[i].userId, aUser[i].password);
//		fprintf(fp_userAppend, "%s\n%s\n",aUser[i].name, aUser[i].address);
//		fprintf(fp_userAppend, "%d\n\n",aUser[i].contactNum);
//	}
	
	 
	fclose(fp_userRead);

	
	return 0;
}

