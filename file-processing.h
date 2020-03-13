int readFile(Users aUser[]){
	int i = 0;
	long len;
	
	FILE *fp_userRead;
	
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
			
			while(!feof(fp_userRead) && i <= MAX_USERS){
				
				if(!feof(fp_userRead)){
					
					fscanf(fp_userRead, "%d %s\n", &aUser[i].userId, aUser[i].password);
					
					fgets(aUser[i].name, STRING20, fp_userRead);
					aUser[i].name[strlen(aUser[i].name) - 1] = '\0';
					
					fgets(aUser[i].address, STRING30, fp_userRead);
					aUser[i].address[strlen(aUser[i].address) - 1] = '\0';
					
					fscanf(fp_userRead,"%d\n",&aUser[i].contactNum);
																	
					i++;
				}
			}
		
			fclose(fp_userRead);
			
		}
	}
	return i;
}

void writeFile(Users aUser[], int numUsers){
	int i;
	
	FILE *fp_userRead;
	printf("%d\n\n", numUsers);
	fp_userRead = fopen("Users.txt", "w");
	for(i = 0; i < numUsers ; i++){
		fprintf(fp_userRead, "%d %s\n", aUser[i].userId, aUser[i].password);
		fprintf(fp_userRead, "%s\n%s\n",aUser[i].name, aUser[i].address);
		fprintf(fp_userRead, "%d\n\n",aUser[i].contactNum);
	}
	fclose(fp_userRead);
}