//Program that takes a file as input and replaces blank spaces and tabs by single space and writes the output to a file.


int main(){
	FILE *fa, *fb;
	int ca, cb;
	fa = fopen("q1in.c","r");
	if(fa == NULL){
		printf("Cannot open file!\n");
		exit(0);
	}
	fb = fopen("q1out.c","w");
	ca = getc(fa);
	while(ca != EOF){
		if(ca == ' ' || ca == '\t'){
			putc(' ',fb);
			while(ca == ' ' || ca == '\t')
				ca = getc(fa);
		}
		if(ca == '/'){
			cb = getc(fa);
			if(cb == '/'){
				while(ca != '\n')
					ca = getc(fa);
			}
			else if(cb == '*'){
				do{
					while(ca != '*')
						ca = getc(fa);
					ca = getc(fa);
				} while(ca != '/');
			}
			else{
				putc(ca, fb);
				putc(cb, fb);
			}
		}
		else putc(ca, fb);
		ca = getc(fa);
	}
	fclose(fa);
	fclose(fb);
	return 0;
}
