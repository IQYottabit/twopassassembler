#include<stdio.h>
#include<string.h>

void main() {
int lc; int s,num,f=0,f1,l,i,n=0;
FILE *fp1,*fp2,*fp3;
char lab[10],op[10],val[10];
char a[15][15]={{'S','T','A'},{'S','T','L'},{'L','D','A'},{'L','D','B'},
				{'J'},{'J','E','Q'},{'J','S','U','B'},{'C','O','M','P'},
				{'S','T','C','H'},{'R','E','S','W'},{'R','E','S','B'},
				{'W','O','R','D'},{'B','Y','T','E'}};
char b[20][10];

fp1=fopen("input.txt","r");
fp2=fopen("symtab.txt","w");
fp3=fopen("inter.txt","w");
fscanf(fp1,"%s\t%s",lab,op);

if(strcmp(op,"START")==0) {
	fscanf(fp1,"%x",&lc);
	fprintf(fp3,"%x\t%s\t%s\t%x\n",lc,lab,op,lc);
}

s=lc;

while(!feof(fp1)) {
	fscanf(fp1,"%s\t%s\t%s",lab,op,val);
	if(strcmp(op,"END")!=0) {
		for(i=0;i<13;i++) {
			if(strcmp(op,a[i])==0) {
				f1=0;
				break;
			}
			f1=1;
		}
	if(strcmp(lab,"$")!=0) {
		for(i=0;i<n;i++) {
			if(strcmp(lab,b[i])==0) {
				f=1;
				break;
			}
		f=0;
		}
	
	if(f==0) {
		fprintf(fp2,"%s\t%x\n",lab,lc);
		strcpy(b[n++],lab);
		}
	}

	fprintf(fp3,"%x\t%s\t%s\t%s\n",lc,lab,op,val);
	num=atoi(val);

	if(strcmp(op,"RESW")==0)
	lc=lc+(num*3);
	else if(strcmp(op,"RESB")==0)
		lc=lc+num;
	else if(strcmp(op,"BYTE")==0) {
		num=strlen(val)-3;
		lc=lc+num;
	} else if(strcmp(op,"WORD")==0)
		lc=lc+3;
	else
		lc=lc+3;	
		}
}

fprintf(fp3,"%x\t%s\t%s\t%s\n",lc,lab,op,val);
l=lc-s;
fprintf(fp3,"PROGRAMLENGTH %x",l);
fcloseall();

}
