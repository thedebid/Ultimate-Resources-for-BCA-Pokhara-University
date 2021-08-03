#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<process.h>
#include<windows.h>
//prototype functions

void display_rec();
void display_stayed_rec();
void display_leaved_rec();
void display_staffs_rec();
void delete_rec();
void search_rec();
void passwordforadmin();
void passwordformanager();
void passwordforstaff();
void insert_rec();
void insert_staff_rec();
void display_staff_rec();
void delete_staff_rec();
void search_staff_rec();
void modify_rec();
void welcome();
void menu();
//menu functions

void adminmenu();
void staffmenu();
void submain(void);

FILE *fp;

struct customer
{
	int id,age,phone;
	char name[10];
	char add[10];
	char status[10];
};

struct customer st;
main() //main menu
{
	welcome();
	menu();

}
void welcome(void) //welcome page
{
	system("cls");
printf("\n \n \n \n \n \n \n");
printf("\t  \t \t * * * * * * * * * * * * * * * * * * * * * * * * *\t\n");
printf("\t  \t      *  \t \t \t \t \t \t   * \n");
printf("\t  \t      * \t \t    -> WELCOME <- \t \t   *  \n");
printf("\t  \t      * \t \t \t \t \t \t   * \n");
printf("\t  \t      * \t \t         TO \t \t\t   *  \n");
printf("\t  \t      * \t \t \t \t \t \t   * \n");
printf("\t  \t      * \t \tHOTEL MANAGEMENT SYSTEM \t   *  \n");
printf("\t  \t      * \t \t \t \t \t \t   * \n");
printf("\t \t \t * * * * * * * * * * * * * * * * * * * * * * * * * \n");
printf("\t  \t             \t  \t Press Any Key to continue......");
getch();
}
void menu(void) //for menu
{
	again:
	int choice;
system("cls");
printf("\n\n\t\t\t\t===============Main Menu===============\n\n");
printf("\t\t\t\tEnter 1 : to login as admin\n");
printf("\t\t\t\tEnter 2 : to login as manager\n");
printf("\t\t\t\tEnter 3 : to login as staffs\n");
printf("\t\t\t\tEnter 4 : for Exit\n");
printf("\n\n\n\t\t\t\t=============================================\n\n");
printf("\t\t\t\tYour Choice[1-4]\n\n");
printf("\t\t\t\tEnter your choice : ");

switch(getch())
{
case '1':
	passwordforadmin();
	break;
case '2':
	passwordformanager();
	break;
case '3':
	passwordforstaff();
	break;
case '4':
	exit(0);
default:
printf("\n\n\t\t\tWrong Choice");
	
goto again;
}
}
void passwordforadmin(void)//password function
{
system("cls");
char pass[10];
printf("\n\n\t\t\t\t===============Administration Login===============\n\n");
printf("\t\t\t\tEnter password : ");
scanf("%s",pass);
if(strcmp(pass,"admin")==0)
{
	
printf("\t\t\t\tpassword Matched\n");
printf("\t\t\t\tpress any key to continue....\n");
getch();
adminmenu();

printf("\n\n\n\t\t\t\t========================================\n\n");

}
else
{
system("cls");
printf("\n\n\t\t\t\t===============Administration login===============\n\n");
printf("\t\t\t\tWarning!!Incorrect Password");
getch();
passwordforadmin();
}

}
void passwordformanager(void)//password function
{
system("cls");
char pass[10];
printf("\n\n\t\t\t\t===============Manager Login===============\n\n");
printf("\t\t\t\tEnter password : ");

scanf("%s",pass);

if(strcmp(pass,"manager")==0)
{
printf("\t\t\t\tpassword Matched\n");
printf("\t\t\t\tpress any key to continue....\n");
getch();
submain();

printf("\n\n\n\t\t\t\t========================================\n\n");

}
else
{
system("cls");
printf("\n\n\t\t\t\t===============Manager login===============\n\n");
printf("\t\t\t\tWarning!!Incorrect Password");
getch();
passwordformanager();
}

}
void passwordforstaff(void)//password function
{
system("cls");
char pass[10];
printf("\n\n\t\t\t\t===============Staff Login===============\n\n");
printf("\t\t\t\tEnter password : ");

scanf("%s",pass);

if(strcmp(pass,"staff")==0)
{
printf("\t\t\t\tpassword Matched\n");
printf("\t\t\t\tpress any key to continue....\n");
getch();
staffmenu();

printf("\n\n\n\t\t\t\t========================================\n\n");

}
else
{
system("cls");
printf("\n\n\t\t\t\t===============Staff login===============\n\n");
printf("\t\t\t\tWarning!!Incorrect Password");
getch();
passwordforstaff();
}

}
void adminmenu() //admin menu
{

	again:
	system("cls");
	int n;
	printf("\n\n\t\t\t\t===============Admin Menu===============\n\n");
	printf("\n\t\t\t\tEnter 1: to view all customers details\n");
	printf("\t\t\t\tEnter 2: to view current stayed customers details\n");
	printf("\t\t\t\tEnter 3: to view current old customers details\n");
	printf("\t\t\t\tEnter 4: to view total staffs record\n");
	printf("\t\t\t\tEnter 5: back to main menu\n");
	printf("\t\t\t\tEnter Your Choice: ");
	scanf("%d",&n);
	switch(n)
	{
		case 1:
			display_rec();
		break;
		case 2:
			display_stayed_rec();
		break;
		case 3:
			display_leaved_rec();
		break;
		case 4:
			display_staff_rec();
		break;
		case 5:
			menu();
		break;
		default:
			printf("\n\n\t\tWrong Choice");
			getch();
	}
	goto again;
	
}

void insert_rec() //add new customer record
{
fp=fopen("customer.txt","a+");
int n,i;
printf("\n\n\t\t\tNo of record ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\n\n\n\t\t\tEnter id,name,address,age,phone and status of customer\n\t\t\t");
scanf("%d%s%s%d%d%s",&st.id,st.name,st.add,&st.age,&st.phone,st.status);
fwrite(&st,sizeof(st),1,fp);
}
fclose(fp);
printf("\t\t\trecord added successfully\n");
getch();
display_rec();
getch();
}

void display_rec() //dispalying all record
{
	system("cls");
	fp=fopen("customer.txt","r");
	printf("\n\n\n\t\tDisplaying All Customers\n");
	printf("\n\tId\tName\tAddress\t\tage\tphone\t\tstatus\n");
	while(fread(&st,sizeof(st),1,fp)==1)
	{
		printf("\t%d\t%s\t%s\t\t%d\t%d\t%s\n",st.id,st.name,st.add,st.age,st.phone,st.status);
	}
	fclose(fp);
	getch();
//	adminmenu();
	
}
void display_stayed_rec() //display stayed customer
{
	system("cls");
	fp=fopen("customer.txt","r");
	printf("\n\n\n\t\t\tDisplaying Current Stayed Customers\n");
	printf("\n\n\n\tId\tName\tAddress\tage\tphone\t\tstatus\n");
	while(fread(&st,sizeof(st),1,fp)==1)
	{
		if(strcmp(st.status,"Available")==0)
		{
		printf("\t%d\t%s\t%s\t%d\t%d\t%s\n",st.id,st.name,st.add,st.age,st.phone,st.status);
	}
	}
	fclose(fp);
	getch();
	adminmenu();
}
void display_leaved_rec() //display old customer record
{
	system("cls");
	fp=fopen("customer.txt","r");
	printf("\n\n\n\t\t\tDisplaying Current Leaved Customers\n");
	printf("\n\n\tId\tName\tAddress\tage\tphone\t\tstatus\n");
	while(fread(&st,sizeof(st),1,fp)==1)
	{
		if(strcmp(st.status,"Unavailable")==0)
		{
		printf("\t%d\t%s\t%s\t%d\t%d\t%s\n",st.id,st.name,st.add,st.age,st.phone,st.status);
	}
	}
	fclose(fp);
	getch();
	adminmenu();
}
void submain(void) //manager menu
{
	
    again:
	system("cls");
	int choice;
	printf("\n\n\t\t===============Manager Menu===============\n\n");
	printf("\t\t\t1. Insert Staff Record\n");
	printf("\t\t\t2. Display Staff record\n");
	printf("\t\t\t3. delete staff record\n");
	printf("\t\t\t4. search staff record\n");
	printf("\t\t\t5. Insert customers record\n");
	printf("\t\t\t6. Display customers record\n");
	printf("\t\t\t7. Modify customers record\n");
	printf("\t\t\t8. Delete customers record\n");
	printf("\t\t\t9. Search customers record\n");
	printf("\t\t\t10. Go to main menu\n");
	printf("\t\t\t11. Exit\n\n");
	printf("\t\t\tEnter your choice ");
	scanf("%d",&choice);
	system("cls");
	switch(choice)
	{
	case 1:
	insert_staff_rec();
	break;
	case 2:
	display_staff_rec();
	break;
	case 3:
	delete_staff_rec();
	break;
	case 4:
	search_staff_rec();
	break;
	case 5:
	insert_rec();
	break;
	case 6:
	display_rec();
	break;
	case 7:
	modify_rec();
	break;
	case 8:
	delete_rec();
	break;
	case 9:
	search_rec();
	break;
	case 10:
	menu();
	break;
	case 11:
	exit(0);
	default:
	system("cls");
	printf("\n\n\t\tWrong choice");
	getch();
}
goto again;
}

void delete_rec() //delete customer record
{
	fp=fopen("customer.txt","r+");
	int did,flag=0;
	system("cls");
	FILE *fptr;
	fptr=fopen("temp.txt","w+");
	printf("\n\n\n\t\t\tEnter id to delete record: ");
	scanf("%d",&did);
	while(fread(&st,sizeof(st),1,fp)==1)
	{
	if(st.id==did)
	{
	flag=1;
	}
	if(did!=st.id)
	{
	fwrite(&st,sizeof(st),1,fptr);
	}
	}
	if(flag==0)
	{
	//system("cls");
	printf("\n\n\t\t\tRecord not found");
	getch();
	}
	else
	{
	//system("cls");
	printf("\n\n\n\t\t\tRecord deleted successfully");
	getch();
	}
	fclose(fp);
	fclose(fptr);
	remove("customer.txt");
	rename("temp.txt","customer.txt");
}

void modify_rec()// for modify customer reecord
{
	int mid,flag=0,size;

size=sizeof(st);
printf("\n\n\n\t\t\tEnter id to modify record: ");
scanf("%d",&mid);
fp=fopen("customer.txt","r+");
while(fread(&st,sizeof(st),1,fp)==1)
{
if(mid==st.id)
{
flag=1;
printf("\t\t\tID: %d\n",st.id);
printf("\t\t\tName: %s\n",st.name);
printf("\t\t\tAddress: %s\n",st.add);
printf("\t\t\tPhone: %d\n",st.phone);
printf("\t\t\tstatus: %s\n",st.status);
printf("\t\t\tAge: %d\n",st.age);
			
			
printf("\n\t\t\tName: ");
scanf("%s",st.name);
printf("\t\t\tAddress: ");
scanf("%s",st.add);
printf("\t\t\tAge: ");
scanf("%d",&st.age);
printf("\t\t\tPhone: ");
scanf("%d",&st.phone);
printf("\t\t\tStatus: ");
scanf("%s",st.status);
break;
	}}		
fseek(fp,-size,1);
fwrite(&st,sizeof(st),1,fp);
//system("cls");

if(flag==1)
{
	printf("\n\t\t\trecord modified successfully");
	getch();
}
else
{
printf("\t\tRecord not found");
}
fclose(fp);
		
}


void staffmenu(void) //staff menu
{
system("cls");
int c;
again :
system("cls");
printf("\n\n\t\t\t\t===============Staff Menu===============\n\n");
printf("\t\t\t1. Insert customers record\n");
printf("\t\t\t2. Display customers record\n");
printf("\t\t\t3. Modify customers record\n");
printf("\t\t\t4. Delete customers record\n");
printf("\t\t\t5. Search customers record\n");
printf("\t\t\t6. Go to main menu\n");
printf("\t\t\t7. Exit\n\n");
printf("\t\t\tEnter your choice ");
scanf("%d",&c);
switch(c)
{
case 1:
insert_rec();
break;
case 2:
display_rec();
break;
case 3:
modify_rec();
break;

	case 4:
	delete_rec();
	break;
	case 5:
	search_rec();
	break;
	case 6:
	menu();
	break;
	case 7:
	exit(0);
	default:
	system("cls");
	printf("\t\tWrong choice");
	getch();
}
goto again;
}
void search_rec() //customer search
{
	
	fp=fopen("customer.txt","r");
	char sname[10];
	int flag=0;
	system("cls");
	printf("\n\n\t\tEnter name: ");
	scanf("%s",sname);
	while(fread(&st,sizeof(st),1,fp)==1)
	{
	if(strcmp(sname,st.name)==0)
	{
	flag=1;
	printf("\n\t\tID : %d\n",st.id);
	printf("\t\tName : %s\n",st.name);
	printf("\t\tAddress : %s\n",st.add);
	printf("\t\tage : %d\n",st.age);
	printf("\t\tphone : %d\n",st.phone);
	printf("\t\tstatus : %s\n",st.status);
	getch();
	}
}
	if(flag==0)
	{
		system("cls");
		printf("\t\tRecord not found\n");
		
	printf("\t\tSearch Again? y for Yes and n for No");
		if(getch()=='y')
		{
			search_rec();
		}
		getch();
	}
	fclose(fp);

}
void insert_staff_rec() ///  for insert staff record
{
fp=fopen("staff.txt","a+");
int n,i;
printf("\n\n\t\t\tNo of record ");
scanf("%d",&n);
for(i=0;i<n;i++)
{
printf("\n\n\t\t\tEnter id, name,address,age,phone of staff\n\t\t\t");
scanf("%d%s%s%d%d",&st.id,st.name,st.add,&st.age,&st.phone);
fwrite(&st,sizeof(st),1,fp);
}
fclose(fp);
display_staff_rec();
getch();
}

void display_staff_rec()// for displaying staff record
{
	fp=fopen("staff.txt","r");
	system("cls");
	printf("\n\n\t\t\tDisplaying staff Record\n\n");
printf("\t\t\tId\tName\tAddress\tage\tphone\n");
while(fread(&st,sizeof(st),1,fp)==1)
printf("\t\t\t%d\t%s\t%s\t%d\t%d\n",st.id,st.name,st.add,st.age,st.phone);
fclose(fp);
getch();
}

void delete_staff_rec()// for deleting staff record
{
fp=fopen("staff.txt","r+");
int did,flag=0;
system("cls");
FILE *fptr;
fptr=fopen("temp1.txt","w+");
printf("\n\n\t\t\tEnter id to delete the staff record: ");
scanf("%d",&did);
while(fread(&st,sizeof(st),1,fp)==1)
{
if(st.id==did)
{
flag=1;
}
if(did!=st.id)
{
fwrite(&st,sizeof(st),1,fptr);
}
}
if(flag==0)
{
//system("cls");
printf("\n\n\t\t\tRecord not found");
getch();
}
else
{
//system("cls");
printf("\n\n\t\t\tRecord deleted successfully");
getch();
}
fclose(fp);
fclose(fptr);
remove("staff.txt");
rename("temp1.txt","staff.txt");
submain();
}
void search_staff_rec()//for searching staff
{
		fp=fopen("staff.txt","r");
	char sname[10];
	int flag=0;
	system("cls");
	printf("\n\n\t\t\tenter name :");
	scanf("%s",sname);
	while(fread(&st,sizeof(st),1,fp)==1)
	{
	if(strcmp(sname,st.name)==0)
	{
	flag=1;
	printf("\n\n\t\t\tID : %d\n",st.id);
	printf("\t\t\tName : %s\n",st.name);
	printf("\t\t\tAddress : %s\n",st.add);
	printf("\t\t\tage : %d\n",st.age);
	printf("\t\t\tphone : %d\n",st.phone);
	getch();
	}
}
	if(flag==0)
	{
		system("cls");
		printf("\n\n\t\t\tRecord not found\n");
		printf("\t\t\tSearch Again? y for Yes and n for No");
		if(getch()=='y')
		{
			search_rec();
		}
		getch();
	}
	fclose(fp);

}

