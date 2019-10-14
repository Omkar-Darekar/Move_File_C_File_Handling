#include<stdio.h>
#include<string.h>

int main(){
	FILE *dst,*src;
	char buff[1000], str[]="BYEE";
	
	char c,sFileName[20],dFileName[50],dFile[50],x[50];
	char *temp;

	puts("\n Enter which file  want to move---------->> \n");
	scanf("%[^\n]",sFileName);
	printf("\nsFileName------>>> %s\n",sFileName);

	
	src=fopen(sFileName,"r");
	printf("--->.%s",sFileName);
	temp= &sFileName;
	if(src== NULL){
		puts("Source File not present");
		return 0;
	}

	puts("\n Enter Where you want to MOVE------>>>! Note-->>>> Enter '/' at the end ! \n");
	scanf("%s",&dFile);

	printf("\ndFile  Destinatiom File path --->>> %s",dFile);	

	fflush(stdin);
	printf("\nDestination FIle name--->>>> %s \n",temp);
	strcat(dFile,temp);
	printf("\n dFile Destination File path  after Concat ---> %s \n",dFile);

	dst=fopen(dFile,"w");
	if(dst==NULL){
		puts("Destination File not opend");
		return 0;
	}
	printf("\nsFileName ------->>> %s\n",sFileName);

	c= fgetc(src);
	while(c != EOF){
		
		fputc(c,dst);
		c=fgetc(src);
		puts("\n------- All fine------\n");	
	}

	puts("\n--------->>\n");
	while(fgets(buff,1000,dst)){
		printf("%s",buff);
		printf("\n");
	}
	
	puts("\n File Succcessfully Moves---\n");

	remove(temp);
	





	fclose(src);
	fclose(dst);
return 0;
}
