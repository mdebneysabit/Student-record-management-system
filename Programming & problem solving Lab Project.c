#include<stdio.h>
#include <stdlib.h>
#include<string.h>
#include <curses.h>
void menu();
void add();
void view();
void search();
void modify();

struct student
{
    char email[20];
    char name[20];
    char mobile[10];
    int id;
    char password[20];
    char address[20];

};

int main()
{
    char username[20]="mdebneysabit";
    char passcode[20]="mdebneysabit123";
    char use[20];
    char pass[20];
    printf ("\t\t\t--------------------------------------------\n");
    printf("\t\t\t---<<STUDENT RECORD MANAGEMENT SYSTEM>>---\n");
    printf ("\t\t\t--------------------------------------------\n");
    printf("\n\n\n");
    printf("SUBMITTED BY_");
            printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
            printf("\n\t\t\t        =          Name                           ID        =");
            printf("\n\t\t\t        =***************************************************=");
            printf("\n\t\t\t        = Md Ebney Sabit          **      0242310005101128  =");
            printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\nSUBMITTED TO_");
       printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
       printf("\n\t\t\t        =      Abdullah Al Mamun(AAM)     =");
       printf("\n\t\t\t        =*********************************=");
       printf("\n\t\t\t        =    Lecturer                     =");
       printf("\n\t\t\t        =    Dept. of CSE                 =");
       printf("\n\t\t\t        =    DIU                          =");
       printf("\n\t\t\t        =-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=");
    printf("\n        ADMIN LOGIN\n");
    printf("       --------------\n\n\n");
    printf("\n      Enter Username: ");
    gets(use);
    printf("\n      Enter password: ");
    gets(pass);
    if(strcmp(use,username)==0 && strcmp(pass,passcode)==0)
    {
        menu();
    }
    else
    {
        printf("\n       -----------Username or password incorrect----------------\n\n");
    }
    return 0;
}

void menu()
{
    int choice;
    system("cls");

    printf("<--:MENU:-->");

    printf("Enter appropriate number to perform following task.");

    printf("\n1 : Add Record.");

    printf("\n2 : View Record.");

    printf("\n3 : Search Record.");

    printf("\n4 : Modify Record.");

    printf("\n7 : Exit.");

    printf("\nEnter your choice.");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        view();
        break;

    case 3:
        search();
        break;

    case 4:
        modify();
        break;

    case 7:
        exit(1);
        break;

    default:

        printf("Invalid Choice.");
    }
}

void add()
{
    FILE *fp;
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");

    fflush(stdin);
    while(another == 'y')
    {
        printf("<--:ADD RECORD:-->");
        printf("\n\nEnter details of student.");
        printf("\nEnter Email : ");
        gets(std.email);
        printf("\nEnter Name : ");
        gets(std.name);
        printf("\nEnter Mobile Number : ");
        gets(std.mobile);
        printf("\nEnter ID : ");
        scanf("%d",&std.id);
        fflush(stdin);
        printf("\nEnter password : ");
        gets(std.password);
        printf("\nEnter address : ");
        gets(std.address);
        fwrite(&std,sizeof(std),1,fp);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);

    printf("\nPress any key to continue.");
    getch();
    menu();
}

void view()
{
    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls");

    printf("<--:VIEW RECORD:-->");

    printf("\n\n\nS.No   Email of Student       Name       Mobile No     ID      Password      Address");

    printf("\n-----------------------------------------------------------------------------------------");
    fp = fopen("record.txt","rb+");
    if(fp == NULL){

        printf("Error opening file.");
        exit(1);
    }

    while(fread(&std,sizeof(std),1,fp) == 1){

        printf("\n%-6d%-20s%-15s%-12s%-9d%-12s%-12s",i,std.email,std.name,std.mobile,std.id,std.password,std.address);
        i++;

    }
    fclose(fp);

    printf("\n\n\nPress any key to continue.");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct student std;
    char stname[20];
    system("cls");

    printf("<--:SEARCH RECORD:-->");

    printf("Enter name of student : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){

        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stname,std.name) == 0){
            printf("Email: %s",std.email);

            printf("Name : %s",std.name);

            printf("Mobile Number : %s",std.mobile);

            printf("ID : %d",std.id);

            printf("Password : %s",std.password);

            printf("Address : %s",std.address);
        }
    }
    fclose(fp);

    printf("Press any key to continue.");
    getch();
    menu();
}
void modify()
{
    char stname[20];
    FILE *fp;
    struct student std;
    system("cls");

    printf("<--:MODIFY RECORD:-->");

    printf("Enter name of student to modify: ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){

        printf("Error opening file");
        exit(1);
    }

    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name) == 0){
            printf("Enter email: ");
            gets(std.email);
            printf("Enter name: ");
            gets(std.name);

            printf("Enter mobile number : ");
            gets(std.mobile);

            printf("Enter id : ");
            scanf("%d",&std.id);

            printf("Enter Password : ");
            fflush(stdin);
            gets(std.password);

            printf("Enter Address : ");
            fflush(stdin);
            gets(std.address);
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);

    printf("Press any key to continue.");
    getch();
    menu();
}
