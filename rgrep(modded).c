/*
Name:Tommy Lee Truong and Professor Chi Yan Leung
Last Edit:Oct 22 2018
Program Name: rgrep Matcher
*/
#include <stdio.h>
#define MAXSIZE 4096

/**
 * You can use this recommended helper function 
 * Returns true if partial_line matches pattern, starting from
 * the first char of partial_line.
 */

  

/**
 * You may assume that all strings are properly null terminated 
 * and will not overrun the buffer set by MAXSIZE 
 *
 * Implementation of the rgrep matcher function
 */
int rgrep_matches(char *line, char *pattern) {
		int counter=0;
	char * save=pattern;
    //
    // Implement me 
	while(pattern != NULL){
		counter++;
		pattern=pattern->next;
		save->next=pattern;
	}
	char *temp[counter];
	char *pats[counter];
	for(int i=0; i<= counter; i++){
		*temp[i]=*line;
		partial_line=partial_line->next;
		*pats[i]=*save;
		save=save->next;
	}
	for(i=0; i<=counter;i++){
		int j =0;
		if(*pats[j+1]!='\'){
			if (*pats[j] == '.'){
				*temp[i]=*pats[j];
				j++;
			}
			if (*pats[j] == '+'){
				*pats[j]=*pats[j-1];
				j++;
			}
			if(*pats[j]=='?'){
				*pats[j]=*pats[j-2];
				for(int k = i-2; k<=counter; k++){
					if(*temp[k]==*pats[j]){
						j++;
			
					}
					if(*temp[k]==*pats[j-1]&&*temp[k]!=*pats[j]){
			 			j=0;
					}
					if(j==counter){
			 			return 1;
					}
				}
			}
		}
		if(*pats[j]=='\'){
			j++;		
		}
		if(*temp[i]==*pats[j]){
			j++;
			
		}
		if(*temp[i-1]==*pats[j-1]&&*temp[i]!=*pats[j]){
			 j=0;
		}
		if(j==counter){
			 return 1;
		}
	}
    //
  return 0;

}

int main(int argc, char **argv) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <PATTERN>\n", argv[0]);
        return 2;
    }

    /* we're not going to worry about long lines */
    char buf[MAXSIZE];

    while (!feof(stdin) && !ferror(stdin)) {
        if (!fgets(buf, sizeof(buf), stdin)) {
            break;
        }
        if (rgrep_matches(buf, argv[1])) {
            fputs(buf, stdout);
            fflush(stdout);
        }
    }

    if (ferror(stdin)) {
        perror(argv[0]);
        return 1;
    }

    return 0;
}
