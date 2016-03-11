/* Mendoza, Ma. Angelica E.
2013-20378
AB-3L
Programming Assignment
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

//function declaration
int getHammingDistance(char *, char *);
int countSubstrPattern(char *, char *);
bool isValidString(char *, char *);
int getSkew(char *, int n);
int getMaxSkewN(char *, int n);
int getMinSkewN(char *, int n);

//main function
int main(){
}

/*function #1
returns the number of characters that differ between two strings
*/
int getHammingDistance(char *str1, char *str2){
	int ctr=0;		//counter for indexing
	int diff=0;		//variable for the final answer

	//if-else that checks first if the length of two strings is equal
	if(strlen(str1) == strlen(str2)){
		//while-loop that runs until the last index of the string is reached
		while(str1[ctr]){
			//checks if the character in the string1 and string2 with the same current index is equal
			//if yes, the counter for difference will increase by 1
			if(str1[ctr]!=str2[ctr]) diff++;
			ctr++;
		}
		return diff;
	}
	//else it will print an error
	else {
		printf("Error! Strings are not equal!\n");
		return 0;		
	}
} //end of function #1


/* function #2
counts and returns the number of times a specific pattern occured in a given string
*/
int countSubstrPattern(char *original, char *pattern){
	int occurrenceCtr=0;		//counter for the occurrence of a given pattern
	
	/*checks first if the length of the string is greater than or equal to the
	length of the pattern. If pattern's length is greater than strings' length, 
	all characters on it will not be seen in the pattern of the original string*/
	if(strlen(original) >= strlen(pattern)){
		//for-loop that will continue to iterate until last index of the original string is reached
		for(int i=0;i<strlen(original);i++){
			int temp=0;		//temporary variable for future use
			//for-loop that has access in the pattern
			for (int j = 0; j < strlen(pattern); j++){
				/*checks the current character in the string and the succeeding characters beside it if
				it is equal to the pattern*/
				if(original[i+j] == pattern[j]) {
					//if yes, the temporary variable will be incremented
					temp++;
					/*if the temporary variable is equal to the length of the pattern, therefore, 
					the current substring matches the pattern. Counter for occurrence will be incremented*/
					if(temp==strlen(pattern)) occurrenceCtr++;
				}
			}
		}
	}
	return occurrenceCtr;	//returns the counter variable
}	//end of function #2


/* funcion #3
checks if the chacters in a string is based on the given set of alphabet; return true if yes, false if no
*/
bool isValidString(char *str, char *alphabet){
	int ctr=0;

	//for-loop to access all characters in the string
	for(int i=0; i<strlen(str); i++){
		//for-loop to check each character in the alphabet if current character of string matches any of it
		for(int j=0;j<strlen(alphabet);j++){
			//if yes, counter for checking later will increment
			if(str[i]==alphabet[j]) ctr++;
		}
	}
	/*checks if the value of the counter is equal to the length of the string. if yes, then all of the string's 
	character is valid*/
	if(ctr==strlen(str)){
		return true; //will return true and when printed will print a 1
	}else{
		return false; //will return false and when printed will print a 0
	}
}	//end of function #3


/* function #4
counts the number of G's and C's from 1 to N position and computes it's difference
*/
int getSkew(char *str, int n){
	//counter variables for G and C
	int ctrG=0;
	int ctrC=0;

	//checks first if n is greater than 0 and it is less than the string length
	if(strlen(str) >= n && n > 0){
		//for-loop to access all the character in the first N position
		for(int i=0; i<n; i++){
			//checks if it match G and C in any case and assigned variable will be incremented
			if(str[i]=='G' || str[i]=='g') ctrG++;
			if(str[i]=='C' || str[i]=='c') ctrC++;
		}
		return (ctrG-ctrC);	//returns the skew value (the difference of G and C)
	}
	//if not, it will print an invalid message and return 0
	else{
		printf("Invalid value for N.\n");
		return 0;
	}
}	//end of function #4


/* function #5
gets the skew in each position until N is reached and gets the maximum among all of it
*/
int getMaxSkewN(char *str, int n){
	//counter variables
	int ctrG=0;
	int ctrC=0;
	int answer=0;

	//if-else for checking of N value
	if(strlen(str) >= n && n > 0){
		//for-loop for access of each character in the string from 1 to N
		for(int i=0; i<n; i++){
			//for-loop for the access of character from the start until the current value of I
			for(int j=0; j<=i;j++){
				//checking if it is a G or a C, counters will be incremented if yes
				if(str[j]=='G' || str[j]=='g') ctrG++;
				if(str[j]=='C' || str[j]=='c') ctrC++;
			}
			//to make sure that the first value of the skew will be assigned to the answer
			if(i==0) answer = ctrG-ctrC; 
			/*checks if the variable for the answer holds the biggest value of skew
			by comparing the current value of answer to the difference of the new
			values of the G and C counter. if not, the difference of the new
			values of the G and C counter will be assigned as new value of answer*/
			if(answer < (ctrG-ctrC)) answer = ctrG-ctrC;
			//resets the values of counters
			ctrG=0;
			ctrC=0;
		}
		return answer; //returns the answer
	}else{
		printf("Invalid value for N.\n");
		return 0;
	}
}	//end of function #5


/* function #6
same with the prvious function, function#5, however, it returns the minimum value of skew
*/
int getMinSkewN(char *str, int n){
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
			if(i==0) answer = ctrG-ctrC; 
			/*checks if current value of answer is greater than the difference of the new values of G 
			and C. If yes, answer's value will be changed*/
			if(answer > ctrG-ctrC) answer = ctrG-ctrC;
			ctrG=0;
			ctrC=0;
		}
		return answer;
	}else{
		printf("Invalid value for N.\n");
		return 0;
	}
}	//end of function #6