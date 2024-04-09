#include<stdio.h> 

int main(int argc,char* argv[]) 
{ 
	int i; 
	printf("Program Name Is: %s",argv[0]); 
	if(argc==1) 
		printf("\nNo Extra Command Line Argument Passed Other Than Program Name"); 
	if(argc>=2) 
	{ 
		printf("\nNumber Of Arguments Passed: %d",argc); 
		printf("\n----Following Are The Command Line Arguments Passed----"); 
		for(i=0;i<argc;i++) 
			printf("\nargv[%d]: %s",i,argv[i]); 
	} 
	return 0; 
} 