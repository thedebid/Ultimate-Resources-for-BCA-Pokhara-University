#include<stdio.h>
#include <curses.h>

int main()
{
    int sid, choice,flag=0,size;
    
    struct singer{
	int id, age, noOfSongs;
	char name[20];
    char sex[10];
    };
    
    struct singer st;
    
    FILE *fp;
  

    while(1)
    {
        printf("1. Add Record \n");
        printf("2. List Record\n");
        printf("3. Modify Record\n");
        printf("4. Search Record\n");
        printf("5. Delete Record\n");
        printf("6. Exit\n\n\n");
        printf("Enter your choice :  ");
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:
                fp = fopen("singer.dat","w+");
                printf("Enter id, name, age, sex and no of songs recorded :\n");
                scanf("%d%s%d%s%d", &st.id,&st.name,&st.age,&st.sex,&st.noOfSongs);
				fwrite(&st,sizeof(st),1,fp);
                printf("\n\nSinger Details added\n\n\n");
                fclose(fp);
                break;
        
            case 2:
                fp=fopen("singer.dat","r");
                printf("Displaying All Singer Records\n");
                printf("\nID\tName\tAge\tSex\tNo of songs recorded\n");
                while(fread(&st,sizeof(st),1,fp)==1)
                    {
                    printf("%d\t%s\t%d\t%s\t%d\n",st.id,st.name,st.age,st.sex,st.noOfSongs);
                    }
            fclose(fp);
            break;
            case 3:
                size=sizeof(st);
                printf("\nEnter id to modify record: ");
                scanf("%d",&sid);
                fp=fopen("singer.dat","r+");
                while(fread(&st,sizeof(st),1,fp)==1)
                {
                    if(sid==st.id)
                        {
                            flag=1;
                            printf("ID: %d\n",st.id);
                            printf("Name: %s\n",st.name);
                            printf("Age: %d\n",st.age);
                            printf("Sex: %s\n",st.sex);
                            printf("No of songs recorded: %d\n",st.noOfSongs);
                            
                            printf("\nName: ");
                            scanf("%s",&st.name);
                            printf("\nAge: ");
                            scanf("%d",&st.age);
                            printf("\nSex: ");
                            scanf("%s",&st.sex);
                            printf("\nNo of songs recorded: ");
                            scanf("%d",&st.noOfSongs);
                            break;
                            }
                        }
                        fseek(fp,-size,1);
                        fwrite(&st,sizeof(st),1,fp);
                        if(flag==1)
            {

                printf("\n Singer record modified successfully\n");
            }else
                {
                    printf("\nSinger Record not found\n");
                    }
                    fclose(fp);
                    break;
            case 4:
                fp=fopen("singer.dat","r");
                char sname[10];
                int flag=0;
              
                printf("\nEnter singer name for search: ");
                scanf("%s",sname);
                while(fread(&st,sizeof(st),1,fp)==1)
                {
                    if(strcmp(sname,st.name)==0)
                        {
                            flag=1;
                            printf("ID: %d\n",st.id);
                            printf("Name: %s\n",st.name);
                            printf("Age: %d\n",st.age);
                            printf("Sex: %s\n",st.sex);
                            printf("No of songs recorded: %d\n",st.noOfSongs);
            
                        }
                    }
                if(flag==0)
                {
		
                    printf("Record not found\n");
                }
                fclose(fp);
                break;
                
            case 5:
                fp=fopen("singer.dat","r+");
                int sid,f=0;
                FILE *fptr;
                fptr=fopen("temp.dat","w+");
                printf("\nEnter id to delete the singer record: ");
                scanf("%d",&sid);
                while(fread(&st,sizeof(st),1,fp)==1)
                {
                    if(st.id==sid)
                        {
                            f=1;
                        }
                    if(sid!=st.id)
                    {
                        fwrite(&st,sizeof(st),1,fptr);
                    }
                }
                if(f==0)
                {
                printf("\nRecord not found\n");
                }   
                else
                {
                    printf("\nRecord deleted successfully\n");
                }
                fclose(fp);
                fclose(fptr);
                remove("singer.dat");
                rename("temp.dat","singer.dat");
                break;                          
            case 6:
                printf("\n\n\t\t\tProgram Terminated!\n\n\n");
                exit(0);    // terminates the complete program execution
        }
    }
    return 0;
}
