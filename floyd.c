#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BUFFER_SIZE 1024
static int d[50][50];					//distance matrix
static int d1[50][50];					//duplicate distance matrix
static int p[50][50];					//predecessor matrix



int main(int argc, char *argv[]){
	char *file_name = argv[1];			//storing file name from the arguments
	FILE *f = NULL;
	char buffer[BUFFER_SIZE];
	char *token;
	
	//open the file to read and if file is not present then exit
	f = fopen(file_name,"r");
	if(f == NULL) {
		printf("No such file present \n");
		exit(1);
	}
	
	//to count the number of lines in file. So, that we get to know number of elements in the matrix
	int count =0;
	for(int i= getc(f); i!= EOF ;i=getc(f)){
		if(i=='\n'){
		count = count +1;
		}
	}
	fclose(f);
	
	f = fopen(file_name,"r");
	
	// parsing the lines in the file to store the values into matrix
	for(int j=0;(fgets(buffer,sizeof(buffer),f)>0);j++){
		
		for(int i=0; i<count; i++){
		
			if(i==0){
				token = strtok(buffer, ",");
				d[j][i] = atoi(token);
			}
			else if(i==count-1){
				token = strtok(NULL, "\n");
				d[j][i] = atoi(token);
			}
			else{
				token = strtok(NULL, ",");
				d[j][i] = atoi(token);
			}
		}
	}
	fclose(f);
	
	
	int n=count;
	    for(int k=0;k<n;k++){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(d[i][j] > (d[i][k]+d[k][j])){
                    d1[i][j] = d[i][k]+d[k][j];
                    p[i][j] = k+1;
                }
                else{
                    d1[i][j]=d[i][j];
                }
            }
        }
        
        for(int i=0; i<n ;i++){
            for(int j=0; j<n; j++){
                d[i][j] = d1[i][j];
            }
        }
    }
    
    // printing the distance matrix
    for(int i=0; i<n ;i++){
        for(int j=0; j<n; j++){
            printf("%d \t",d[i][j]);
        }
        printf("\n");
    }

    return 0;
}