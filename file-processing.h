/*
Loads users information from a text file and saves it to the array of structure

@param(Users) Users aUser[] is the array of structures that contains user information
@return(int) returns the value of the number of users 
*/

int readFile(Users aUser[]){
	int i = 0;
	char cDump;
	FILE *fp_userRead;
	
	
	if((fp_userRead = fopen("Users.txt", "r")) != NULL){
		
		while((fscanf(fp_userRead, "%d%c", &aUser[i].userId, &cDump)) == 2 && i <= MAX_USERS){
			
			fgets(aUser[i].password, STRING10, fp_userRead);
			removeEnter(aUser[i].password);

			fgets(aUser[i].name, STRING20, fp_userRead);
			removeEnter(aUser[i].name);
			
			fgets(aUser[i].address, STRING30, fp_userRead);
			removeEnter(aUser[i].address);
			
			fscanf(fp_userRead,"%d\n",&aUser[i].contactNum);
			aUser[i].numItems = 0;
			aUser[i].numCart = 0;

			i++;
			
			

		}
		fclose(fp_userRead);

	}
	

	return i ;

}

/*
Loads users item information from a text file and saves it to the array of structure

@param(Users) Users aUser[] is the array of structures that contains user information
@param(int) numUsers updates the total number of registered users
@return(void) no return value
*/
void readItem(Users aUser[], int numUsers){
	int i, j;
	int prodId, sellId;
	char cDump;
	FILE *fp_item;
	
	if (numUsers > 0){
		if((fp_item = fopen("Items.txt", "r")) !=  NULL){

			i = 0;
			while((fscanf(fp_item, "%d%c%d%c", &prodId, &cDump, &sellId, &cDump)) == 4){
				
				for(i = 0; i < numUsers; i++){
					
					if(aUser[i].userId == sellId){
						j = aUser[i].numItems;
						aUser[i].item[j].productId = prodId;
						aUser[i].item[j].sellerId = sellId;

						fgets(aUser[i].item[j].name, STRING20, fp_item);
						removeEnter(aUser[i].item[j].name);
						toUpperCase(aUser[i].item[j].name);

						fgets(aUser[i].item[j].category, STRING15, fp_item);
						removeEnter(aUser[i].item[j].category);
						toUpperCase(aUser[i].item[j].category);

						fgets(aUser[i].item[j].description, STRING30, fp_item);
						removeEnter(aUser[i].item[j].description);
						
						fscanf(fp_item,"%d %f\n", &aUser[i].item[j].quantity, 
									&aUser[i].item[j].price);
						
						aUser[i].numItems++;
						
					}
						// printf("%d", prodId);
				}
			}
				
		}
	}
	
	fclose(fp_item);

}

/*
Saves users information to a text file  

@param(Users) Users aUser[] is the array of structures that contains user information
@param(int) numUsers updates the total number of registered users
@return(void) no return value
*/

void writeUser(Users aUser[], int numUsers){
	int i, j;
	
	FILE *fp_userRead;
	
	sort(aUser, numUsers);

	if((fp_userRead = fopen("Users.txt", "w")) != NULL){
		for(i = 0; i < numUsers ; i++){
			fprintf(fp_userRead, "%d %s\n", aUser[i].userId, aUser[i].password);
			fprintf(fp_userRead, "%s\n%s\n",aUser[i].name, aUser[i].address);
			fprintf(fp_userRead, "%d\n\n",aUser[i].contactNum);

		}
	}

	fclose(fp_userRead);
}


/*
Saves users items to a text file  

@param(Users) Users aUser[] is the array of structures that contains user information
@param(int) numUsers updates the total number of registered users
@return(void) no return value
*/

void writeItem(Users aUser[], int numUsers){
	int i, j;
	FILE *fp_item;
	

	if((fp_item = fopen("Items.txt", "w")) != NULL){
		for(i = 0; i < numUsers; i++){
			if (aUser[i].numItems > 0 ){
				for(j = 0; j < aUser[i].numItems; j++){
					fprintf(fp_item, "%d %d\n", aUser[i].item[j].productId, aUser[i].item[j].sellerId);
					fprintf(fp_item, "%s\n%s\n", aUser[i].item[j].name, aUser[i].item[j].category);
					fprintf(fp_item, "%s\n", aUser[i].item[j].description);
					fprintf(fp_item, "%d %.2f\n\n", aUser[i].item[j].quantity, aUser[i].item[j].price * 1.0);
				}
			}
		}
	}

	
	fclose(fp_item);

	
}
/*

Saves a binary file of the contents of a user's cart

@param(Users*)aUser is a pointer to an address of a structure a specific user.
@return(void) no return value
*/
void writeCart(Users *aUser){
	int i;
	String20 filename;
	FILE *fp;

	sprintf(filename,"%d",aUser->userId);
	strcat(filename, ".bag");
	
	if((fp = fopen(filename, "wb")) != NULL){
		for(i = 0; i < aUser->numCart; i++)
			fwrite(&aUser->cart[i], sizeof(Items), 1, fp);
	}

	fclose(fp);

}

/*

Loads the saved binary file of the contents of a user's cart 

@param(Users*)aUser is a pointer to an address of a structure of a specific user.
@return(void) no return value
*/
void readCart(Users *aUser){
	int i;
	String20 filename;
	FILE *fp;

	sprintf(filename,"%d", aUser->userId);
	strcat(filename, ".bag");
	
	if((fp = fopen(filename, "rb")) != NULL){
		i = 0;
		while((fread(&aUser->cart[i], sizeof(Items), 1, fp)) == 1)
			i++;
		aUser->numCart = i;
	}
	fclose(fp);

}

/*

Saves transaction information information to Transactions.dat

@param(Transactions[])aTrans is an array of structures for the transactions of a user.
@param(int)numTrans is the total number of transactions of a user
@return(void) no return value
*/
void writeTrans(Transactions aTrans[], int numTrans){

	int i;
	FILE *fp;

	if((fp = fopen("Transactions.dat", "rb+")) != NULL){
		fseek(fp, 0, SEEK_END);
		for(i = 0; i < numTrans; i++)
			fwrite(&aTrans[i], sizeof(Transactions), 1, fp);

	}
	else{
		fp = fopen("Transactions.dat", "wb");
		for(i = 0; i < numTrans; i++)
			fwrite(&aTrans[i], sizeof(Transactions), 1, fp);
	}

	fclose(fp);

}