int readFile(Users aUser[]){
	int i = 0;
	FILE *fp_userRead;
	
	fp_userRead = fopen("Users.txt", "r");
	
	
	if(fp_userRead != NULL){
		
		while(!feof(fp_userRead) && i <= MAX_USERS){
			if(!feof(fp_userRead) ){
				
				fscanf(fp_userRead, "%d %s\n", &aUser[i].userId, aUser[i].password);

				fgets(aUser[i].name, STRING20, fp_userRead);
				removeEnter(aUser[i].name);
				
				fgets(aUser[i].address, STRING30, fp_userRead);
				removeEnter(aUser[i].address);
				
				fscanf(fp_userRead,"%d\n",&aUser[i].contactNum);
				aUser[i].numItems = 0;
				aUser[i].numCart = 0;

		
					
				i++;
			}
		}
		fclose(fp_userRead);

	}
	return i;

}

void readItem(Users aUser[], int numUsers){
	int i, j;
	int prodId, sellId;
	FILE *fp_item;
	fp_item = fopen("Items.txt", "r");

	if(fp_item != NULL){

		 i = 0;
		while(!feof(fp_item)){
			if(!feof(fp_item)){
				for(i = 0; i < numUsers; i++){
					fscanf(fp_item, "%d %d\n", &prodId, &sellId);
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
						printf("%d", prodId);
					
				}
			}

		}
			
	}


	
	fclose(fp_item);

}


void writeFile(Users aUser[], int numUsers){
	int i, j;
	
	FILE *fp_userRead, *fp_item;

	fp_userRead = fopen("Users.txt", "w");
	fp_item = fopen("Items.txt", "w");

	sort(aUser, numUsers);
	
	for(i = 0; i < numUsers ; i++){
		fprintf(fp_userRead, "%d %s\n", aUser[i].userId, aUser[i].password);
		fprintf(fp_userRead, "%s\n%s\n",aUser[i].name, aUser[i].address);
		fprintf(fp_userRead, "%d\n\n",aUser[i].contactNum);
		for(j = 0; j < aUser[i].numItems; j++){
			fprintf(fp_item, "%d %d\n", aUser[i].item[j].productId, aUser[i].item[j].sellerId);
			fprintf(fp_item, "%s\n%s\n", aUser[i].item[j].name, aUser[i].item[j].category);
			fprintf(fp_item, "%s\n", aUser[i].item[j].description);
			fprintf(fp_item, "%d %.2f\n\n", aUser[i].item[j].quantity, aUser[i].item[j].price * 1.0);
		}
	}
	fclose(fp_userRead);
	fclose(fp_item);
}
