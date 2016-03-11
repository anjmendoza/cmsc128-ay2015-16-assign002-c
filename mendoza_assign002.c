/* Mendoza, Ma. Angelica E.
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

int getHammingDistance(char *, char *);
int countSubstrPattern(char *, char *);
bool isValidString(char *, char *);
int getSkew(char *, int n);
int getMaxSkew(char *, int n);
int getMinSkew(char *, int n);
void toUpperCase(char *);
int main(){
	int ret=0;
	bool validString;
	char str1[15];
	char str2[15];
	strcpy(str1, "GGCCAC");
	strcpy(str2, "ACGT");
	//toUpperCase(str1);
	//toUpperCase(str2);
	printf("%s\n",str1);
	printf("%s\n",str2);
	//ret=getHammingDistance(str1,str2);
	//ret=countSubstrPattern(str1,str2);
	//validString=isValidString(str1,str2);
	ret=getMaxSkew(str1,7);
	printf("%d\n",ret);
}
int getHammingDistance(char *str1, char *str2){
	int ctr=0;
	int diff=0;
	if(strlen(str1) == strlen(str2)){
		while(str1[ctr]){
			if(str1[ctr]!=str2[ctr]) diff++;
			ctr++;
		}
		printf("%d\n", diff);
		return diff;
	}else {
		printf("Error! Strings are not equal!\n");
		return 0;
	}
}
int countSubstrPattern(char *original, char *pattern){
	int occurrenceCtr=0;
	if(strlen(original) >= strlen(pattern)){
		for(int i=0;i<strlen(original);i++){
			int temp=0;
			for (int j = 0; j < strlen(pattern); j++)
			{
				if(original[i+j] == pattern[j]) {
					temp++;
					if(temp==strlen(pattern)) occurrenceCtr++;
				}
			}
		}
	}
	return occurrenceCtr;
}
bool isValidString(char *str, char *alphabet){
	int ctr=0;
	if(strlen(str) >= strlen(alphabet)){
		for(int i=0; i<strlen(str); i++){
			for(int j=0;j<strlen(alphabet);j++){
				if(str[i]==alphabet[j]) ctr++;
			}
		}
		if(ctr==strlen(str)){
			return true; //1
		}else{
			return false; //0
		}
	}else{
		return false;
	}
}
int getSkew(char *str, int n){
	int ctrG=0;
	int ctrC=0;
	if(strlen(str) >= n && n > 0){
		for(int i=0; i<n; i++){
			if(str[i]=='G' || str[i]=='g') ctrG++;
			if(str[i]=='C' || str[i]=='c') ctrC++;
		}
		return (ctrG-ctrC);
	}else{
		printf("Invalid value for N.\n");
		return 0;
	}
}
int getMaxSkew(char *str, int n){
	int ctrG=0;
	int ctrC=0;
	int answer=0;
	if(strlen(str) >= n && n > 0){
		for(int i=0; i<n; i++){
			for(int j=0; j<=i;j++){
				if(str[j]=='G' || str[j]=='g') ctrG++;
				if(str[j]=='C' || str[j]=='c') ctrC++;
			}
			if(answer < (ctrG-ctrC)) answer = ctrG-ctrC;
			ctrG=0;
			ctrC=0;
		}
		return answer;
	}else{
		printf("Invalid value for N.\n");
		return 0;
	}
}
int getMinSkew(char *str, int n){
	int ctrG=0;
	int ctrC=0;
	int answer=0;
	int temp=0;
	if(strlen(str) >= n && n > 0){
		for(int i=0; i<n; i++){
			for(int j=0; j<=i;j++){
				if(str[j]=='G' || str[j]=='g') ctrG++;
				if(str[j]=='C' || str[j]=='c') ctrC++;
				
			}
			//temp=ctrG-ctrC;
			if(i==0) answer = ctrG-ctrC; 
			if(answer > ctrG-ctrC) answer = ctrG-ctrC;
			//printf("%d\n", temp);
			ctrG=0;
			ctrC=0;
		}
		return answer;
	}else{
		printf("Invalid value for N.\n");
		return 0;
	}
}
void toUpperCase(char *str1){
	int ctr=0;
	char temp;
	while (str1[ctr]){
		temp=str1[ctr];
		str1[ctr]=toupper(temp);
		ctr++;
	}
}