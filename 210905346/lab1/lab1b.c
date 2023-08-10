#include <stdio.h>
#include<stdlib.h>
int main(){
	FILE *fptr1, *fptr2;
	char filename[100], c;
	int n=0,i;
	printf(
		"enter filename to open reading:");
	scanf("%s",filename);
	fptr1=fopen(filename,"r");
	if (fptr1==NULL){
		printf("cannot open %s\n",filename);
		exit(0);
	}
	printf(
		"enter filename to open for writing:");
	scanf("%s",filename);
	fptr2=fopen(filename,"w+");
	c=fgetc(fptr1);
	while(c!=EOF){
		n++;
		c=fgetc(fptr1);

	}
	for(i=n-1;i>0;i--){
		fseek(fptr1,i,SEEK_SET);
		c=fgetc(fptr1);
		fputc(c,fptr2);
	}
	fclose(fptr1);
	fclose(fptr2);
	printf("\nContents copied to %s",filename);
	return 0;
}