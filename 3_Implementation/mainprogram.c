
#include "user.h"
#include "methodfunction.h"
 

void fun1();
void fun2();
void fun3();
void fun4();
void fun5();
void reg();
int login();



int main()
{
		 
	int opt;
	int amount,choice;
	char cont = 'y';
    printf("\nWelcome to Net Banking");
	printf("\n\nPress 1 to Register your account");
	printf("\nPress 2 Login in to your account");

	printf("\n\nPlease enter your choice:\t");
	scanf("%d",&opt);
	switch(opt){
		case 1 :
		system("cls");
		   reg();
		     break;

	    case 2 :

		  login();
		  printf("\n\n***Thank you for using net banking***\n\n");
		    break;




	}		

}
