#include<stdio.h>

#include"user.h"
#include"methodfunction.h"

   char filename[50],phone[50],password[50],phone2[50];
   FILE *fp,*fptr;
   struct userDetails user,usr;
   
int login(){
	int choice;
	char cont ='y';
		system("cls");
		printf("\nPhone No.:\t");
		scanf("%s",phone);
		printf("Password:\t");
		scanf("%s",password);
		fp = fopen(strcat(phone,".dat"),"r");
		if(fp == NULL) printf("Account number not registered");
		else {
			fread(&user,sizeof(user),1,fp);
			fclose(fp);
			if(!strcmp(password,user.password)){
				while(cont == 'y'){
                   system("cls");
				printf("\n\tWelcome %s",user.name);
				printf("\nPress 1 for balance inquiry");
				printf("\nPress 2 for adding fund");
				printf("\nPress 3 for cash withdraw");
				printf("\nPress 4 for online transfer");
				printf("\nPress 5 for changing password\n\n");
				scanf("%d",&choice);
				switch(choice){
					case 1:
					    fun1();
						break;
					case 2:
						system("cls");
						fun2();
						break;
					case 3:
						system("cls");
						fun3();						
						break;					
					case 4:
						system("cls");
						fun4();
						break;
					case 5:
						fun5();
					    break;
					default:
					
				}//switch ends here
				printf("\n\nDo you want to continue?[y/n]:\t");
				scanf("%s",&cont);
				}
			}
			else {
				printf("Invalid password");
			}	
   }
	
return 0;
}
int reg(){
	printf("\nEnter your Full Name:\t");
		scanf("%s",user.name);
		printf("\nEnter your account number:\t");
		scanf("%s",user.ac);
		printf("Enter your phone number:\t");
		scanf("%s",user.phone);
		printf("Enter your new password:\t");
		scanf("%s",user.password);
		user.balance=0;
		strcpy(filename,user.phone);
		fp=fopen(strcat(filename,".dat"),"w");
		fwrite(&user,sizeof(user),1,fp);
		if(fwrite != 0){
			printf("Succesfully registered");
		}
		
return 0;
}



int fun1(){
	printf("Your current balance is Rs. %.2f",user.balance);
	return 0;
}
void fun2(){
	int amt;
    
	printf("Enter amount to be added:\t");
						scanf("%d",&amt);
						user.balance += amt;
						fp = fopen(phone,"w");
						fwrite(&user,sizeof(user),1,fp);
						if(fwrite !=0) printf("\n\nYou have depostied Rs.%d",amt);
						fclose(fp);
}
void fun3(){
	int amount;
	
	printf("Enter withdrawl amount:\t");
						scanf("%d",&amount);
						if(amount % 500 != 0) printf("\nSorry amount should be multiple of 500");
						else if(amount>user.balance) printf("\nSorry insufficeint balance");
						else {
							user.balance -= amount;
						fp = fopen(phone,"w");
						fwrite(&user,sizeof(user),1,fp);
						if(fwrite !=0) printf("\n\nYou have withdrawn Rs.%d",amount);
						fclose(fp);
						}
}
void fun4(){
	int amount;
	 
	printf("Please enter the phone number to trasnfer balance:\t");
						scanf("%s",phone);
						printf("Enter the amount to transfer:\t");
						scanf("%d",&amount);
						if(amount > user.balance) printf("\nSorry insufficent balance");
						else {
							fptr = fopen(strcat(phone,".dat"),"r");
							if(fptr==NULL) printf("Sorry number is not registered");
							else {
								fread(&usr,sizeof(user),1,fptr);
								fclose(fptr);
							
								usr.balance += amount;
								
								fptr = fopen(phone,"w");
								fwrite(&usr,sizeof(user),1,fptr);
								if(fwrite != 0){
									printf("Your trasfer is completed. You have trasnfered Rs.%d to %s",amount,usr.phone);
									fclose(fptr);
									user.balance -= amount;
									strcpy(filename,user.phone);
									fp = fopen(strcat(filename,".dat"),"w");
									fwrite(&user,sizeof(user),1,fp);
									fclose(fp);
								}
							}
						}
}
void fun5(){
	
	printf("\n\nPlease enter your old password:\t");
						scanf("%s",password);
						if(!strcmp(password,user.password)){
							printf("\n\nPlease enter your new password:\t");
							scanf("%s",password);
							strcpy(user.password,password);
							strcpy(filename,user.phone);
							fp = fopen(strcat(filename,".dat"),"w");
							fwrite(&user,sizeof(user),1,fp);
							fclose(fp);	
							printf("\nPassword succesfullly changed");
						}else printf("\nSorry your password is wrong");

}
