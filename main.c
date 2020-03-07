#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "shopping.h"



void removeEnter(char str[]){
	str[strlen(str) - 1] = '\0';
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

void addItem(Users aUser[], int index){
//	int index;
	int itemIndex;
//	index = searchUser(aUser, numUsers, userId);
	
	aUser[index].numItems++;
	itemIndex = aUser[index].numItems;
	
	aUser[index].item[itemIndex - 1].sellerId = aUser[index].userId;
	
	if(aUser[index].numItems <= 20){
		
		printf("Enter product id: ");
		scanf("%d", &aUser[index].item[itemIndex - 1].productId);
		printf("Enter quantity: ");
		scanf("%d", &aUser[index].item[itemIndex - 1].quantity);
		printf("Enter price: ");
		scanf("%f", &aUser[index].item[itemIndex - 1].price);
		fflush(stdin);
		
		printf("Enter item name: ");
		fgets(aUser[index].item[itemIndex - 1].name, STRING20, stdin);
		removeEnter(aUser[index].item[itemIndex - 1].name);
		
		printf("Enter item category: ");
		fgets(aUser[index].item[itemIndex - 1].category, STRING15, stdin);
		removeEnter(aUser[index].item[itemIndex - 1].category);
		
		printf("Enter item description: ");
		fgets(aUser[index].item[itemIndex - 1].description, STRING30, stdin);
		removeEnter(aUser[index].item[itemIndex - 1].description);
		
	}
	
}

void printItems(Users aUser[], int index, int itemIndex){
	
		printf("|%3d|", aUser[index].item[itemIndex].productId);
		printf("|%-20s|", aUser[index].item[itemIndex].name);
		printf("|%-15s|", aUser[index].item[itemIndex].category);
		printf("|%8.2f|", aUser[index].item[itemIndex].price);
		printf("|%3d|", aUser[index].item[itemIndex].quantity);
		printf("\n");
		
}

void displayItems(Users aUser[], int index){
	int i;
	
	printf("|%-3s||%-20s||%-15s||%-8s||%3s|", "ID", "Name", "Category", "Price", "Quantity");
	printf("\n");
	for(i = 0; i < aUser[index].numItems; i++)
		printItems(aUser, index, i);
	
}

void displayLowStock(Users aUser[], int index){
	int i;
	
	printf("|%-3s||%-20s||%-15s||%-8s||%3s|", "ID", "Name", "Category", "Price", "Quantity");
	printf("\n"); 
	for(i = 0; i < aUser[index].numItems; i++){
		if(aUser[index].item[i].quantity <= 5)
			printItems(aUser, index, i);
	}
	
}


void sellMenu(Users aUser[], int userIndex){
	int option;
	
	do{
		printf("[1]add item\n[2]Edit stock\n[3]Show my products\n[4]Show low stock\n[5]Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		switch(option){
		
			case 1: 
				addItem(aUser, userIndex);
				break;
			case 2:
				break;
			case 3:
				displayItems(aUser,userIndex);
				break;
			case 4:
				displayLowStock(aUser, userIndex);
				break;
			case 5:
//				userMenu(aUser, userIndex);
				break;
		
		}
	}while(option >= 1 && option <= 4);
	
	
}

void userMenu(Users aUser[], int userIndex){
	int option = 0;
	do{
		printf("Main Menu\n");
		printf("[1]Sell Menu\n[2]Buy Menu\n[3]Exit\n");
		printf("Input: ");
		scanf("%d", &option);
		fflush(stdin);
		switch(option){
			case 1:
				sellMenu(aUser, userIndex); 
//				printf("Sell Menu\n");
				break;
			case 2:
				printf("Buy Menu\n");
				break;
			case 3:
				break;
			default:
				break;
		}
	

	}while(option >= 1 && option <= 2);
	
}




void login(Users aUser[], int numUsers){
	int id;
	int getUserIndex ;
	String10 password;
	
	
//	do{
	
		printf("Enter User ID: ");
		scanf("%d", &id);
		fflush(stdin);
		
		printf("Enter Password: ");
		fgets(password, STRING10, stdin);
		removeEnter(password);
		// password[strlen(password) - 1] = '\0';
		
		getUserIndex = searchUser(aUser, numUsers, id);
	
		
		if(getUserIndex == -1)	
			printf("User not found...Going back to main menu\n");
			
		else{
			if(id == aUser[getUserIndex].userId && strcmp(password, aUser[getUserIndex].password) == 0)
				userMenu(aUser, getUserIndex);
//				printf("Success\n");
			else
				printf("Invalid password...Going back to main menu\n");
		}
		
//	} while(getUserIndex == -1 ||
//	(id != aUser[getUserIndex].userId || strcmp(password, aUser[getUserIndex].password) != 0));
	
	
}


void registerUser(Users aUser[], Transactions aTransaction[], int *numUsers){
	
	String10 num;
	int id;
	
	(*numUsers)++;
	
	do{
		
		printf("Enter User ID: ");
		scanf("%d", &id);
		
	}while(!search(aUser, id, *numUsers));


	aUser[(*numUsers) - 1].userId = id;

	fflush(stdin);
		
	
	printf("Enter name: ");
	fgets(aUser[(*numUsers) - 1].name, STRING20, stdin);
	removeEnter(aUser[(*numUsers) - 1].name);
	
	// aUser[(*numUsers) - 1].name[strlen(aUser[(*numUsers)- 1].name) - 1] = '\0'; 
	
	printf("Enter password: ");
	fgets(aUser[(*numUsers) - 1].password, STRING10, stdin);
	removeEnter(aUser[(*numUsers) - 1].password);
	// aUser[(*numUsers) - 1].password[strlen(aUser[(*numUsers) - 1].password) - 1] = '\0';
	
	printf("Enter address: ");
	fgets(aUser[(*numUsers) - 1].address, STRING30, stdin);
	removeEnter(aUser[(*numUsers) - 1].address);
	// aUser[(*numUsers) - 1].address[strlen(aUser[(*numUsers) - 1].address) - 1] = '\0';
	
	printf("Enter contact number: ");
	scanf("%ld", &aUser[(*numUsers) - 1].contactNum);
	fflush(stdin);
	//mainMenu(aUser, aTransaction, *numUsers);
	
	
}

int main(){
	Users aUser[MAX_USERS];
	Transactions aTransaction[MAX_USERS];
	int numUsers = 0;
	int option; 
	int i = 0;
	long len;
	FILE *fp_user;
	
	FILE *fp_userWrite, *fp_userRead;
	
	fp_userRead = fopen("Users.txt", "r");
	
	
	if(fp_userRead == NULL){
		printf("File could not be read\n");
	}	
	else{
		
//		https://stackoverflow.com/questions/30133210/check-if-file-is-empty-or-not-in-c/30133326

		fseek(fp_userRead, 0, SEEK_END);
		len = (long)ftell(fp_userRead);
		if(len > 0){
			rewind(fp_userRead);
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
		}
	}
			
	numUsers = i;
//	printf("%d\n", numUsers);
	
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
				login(aUser, numUsers);
//				printf("login\n");
				break;
			case 3:
				fp_userWrite = fopen("Users.txt", "w");
				for(i = 0; i < numUsers ; i++){
					fprintf(fp_userWrite, "%d %s\n", aUser[i].userId, aUser[i].password);
					fprintf(fp_userWrite, "%s\n%s\n",aUser[i].name, aUser[i].address);
					fprintf(fp_userWrite, "%d\n\n",aUser[i].contactNum);
//					printf("ID: %d\npass: %s\nname: %s\naddress: %s\ncontact: %ld\n\n",aUser[i].userId, aUser[i].password, 
//													aUser[i].name, aUser[i].address, aUser[i].contactNum);
													
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
