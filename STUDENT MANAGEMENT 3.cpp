#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include <windows.h>

#define Student struct Stud
char findbook;

FILE *fp,*ft,*fs;
char catagories[][15]={"Computer","Electronics","Electrical","Civil","Mechanical","Architecture"};
void add(FILE * fp);
void modify(FILE * fp);
void display(FILE * fp);
void Individual(FILE *fp);
void password();
FILE * del(FILE * fp);
void printChar(char ch,int n);
void title();
FILE *tp;
struct meroDate
{
int mm,dd,yy;
};
struct books
{
int id;
char stname[20];
char name[20];
char Author[20];
int quantity;
float Price;
int count;
int rackno;
char *cat;
struct meroDate issued;
struct meroDate duedate;
};
struct books a;

void gotoxy(int x,int y)
{
	COORD CRD;
    CRD.X = x;
    CRD.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),CRD);
}

struct pass
{
	char pass[25];
}pa;

struct Stud
{
    char name[100];
    char dept[50];
    int roll;
    float sgpa[12];
    float cgpa;
};


int main()
{
    int ch,id,k,i;
    char c,pas[50];
    SetConsoleTitle("\t\t\t\t\t\t\t\t\t\t|QUANTUM STUDENT MANAGEMENT SYSTEM| QU");
    FILE * fp;
    Student s;
    int option;
    char another;

    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        if((fp=fopen("db.txt","wb+"))==NULL)
        {
            printf("Can't create or open Database.");
            return 0;
        }
    }
    system("color 9f");
	gotoxy(42,8);
	printf("LOGIN:(new user hit enter)");
	gotoxy(42,10);
	printf("__________________________________________");
	gotoxy(42,11);
	printf("|Enter Your Password:                     |");
	gotoxy(42,12);
	printf("|_________________________________________|");
	//printf("\n\t\t\t\t\t");
	gotoxy(65,11);
	while( k<10)
	{
	    pas[k]=getch();
	    char s=pas[k];
	    if(s==13)
		 break;
	    else printf("*");
	    k++;
	}
	pas[k]='\0';
	tp=fopen("F:/Password.txt","r+");
    fgets(pa.pass,25,tp);
    if(strcmp(pas,pa.pass)==0)
	{
		system("cls");
		gotoxy(10,3);
		printf("\t\t\t\t\t<<<< Loading Please Wait >>>>");
		for(i=0; i<10; i++)
        {
            printf("...");
            Sleep(500);
        }
        printf("\n\n\n\n\n\t\t\t\t\t\t\t*******************************");
		printf("\n\n\t\t\t\t\t\t\t*                             *");
		printf("\n\n\t\t\t\t\t\t\t*          WELCOME            *");
		printf("\n\n\t\t\t\t\t\t\t*            TO               *");
	    printf("\n\n\t\t\t\t\t\t\t* STUDENT MANAGEMENT SYSTEM   *");
	    printf("\n\n\t\t\t\t\t\t\t*                             *");
		printf("\n\n\t\t\t\t\t\t\t*******************************");
		printf("\n\n\n\n\n\t\t\t\t\tPLEASE PRESS ENTER KEY TO CONTINUE.... ");
		getch();

    title();
    
    printf("\n\n\t\t\t\t\t\t\t\t\t\tPROJECT FOR HACKATHON");
    printf("\n\n\t\t\t\t\t\t\t\t\tBy TEAM BINARY BEAST");
    printf("\n\n\t\t\t\t\t\t\t\t MEMBER");
    printf("\n\n\t\t\t\t\t\t\t\tYASH JAIN\n\n\t\t\t\t    SUMIT SONI\n\n\t\t\t\t    TUSHAR CHAUHAN\n\n\t\t\t\t    SURYANSH YADAV ");
    printChar('=',38);
    printf("\n\n\n\t\t\t\t\t\tPLEASE PRESS ENTER KEY!");
    getch();

    while(1)
    {
	
        title();
        printf("\n\t");
        printChar('*',64);

        printf("\n\n\t\t\t\t1. Add Student");
        printf("\n\n\t\t\t\t2. Modify Student");
        printf("\n\n\t\t\t\t3. Show All Student");
        printf("\n\n\t\t\t\t4. Individual View");
        printf("\n\n\t\t\t\t5. Library Management");
        printf("\n\n\t\t\t\t5. Remove Student");
        printf("\n\n\t\t\t\t6. Change Password");
        printf("\n\n\t\t\t\t7. Logout\n\t");
        printChar('*',64);
        printf("\n\n\t\t\t\tEnter Your Option :--> ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:
                add(fp);
                break;
            case 2:
                modify(fp);
                break;
            case 3:
                display(fp);
                break;
            case 4:
                Individual(fp);
                break;
          
            
            case 5:
                fp=del(fp);
                break;
            case 6:
                    system("cls");
				    system("color 5f");
			        password();
                break;
            case 7:
                return 1;
                break;
            default:
                printf("\n\t\tNo Action Detected");
                printf("\n\t\tPress Any Key\n\n\n");
                getch();
                system("pause");
        }
    }
    }
    else
    {
        printf("Wrong Password . Get Out");
        getch();
    }
    return 1;

}

void password()
{
	char c;
	printf("\nEnter new password :");
	fflush(stdin);
	gets(pa.pass);
	printf("\nSave password (y/n) :");
	fflush(stdin);
	scanf("%c",&c);
	if(c=='y'||c=='Y')
	{
		tp=fopen("F:/Password.txt","w+");
	    fwrite(&pa,sizeof(pa),1,tp);
	    fclose(tp);
		printf("\n\tPassword Saved\n");
	}
	else
	{
		printf("Password not saved :\n");
		printf("Press any key to continue >>>");
		getch();
	}
}


void printChar(char ch,int n)
{
    while(n--)
    {
        putchar(ch);
    }
}

void title()
{
    system("cls");
    system("COLOR 03");
    printf("\n\n\t");
    printChar('=',19);
    printf(" Student Management System ");
    printChar('=',19);
    printf("\n");
}


//Insert at end

void add(FILE * fp)
{
    title();

    char another='y';
    Student s;
    int i;
    float cgpa;

    fseek(fp,0,SEEK_END);
    while(another=='y'||another=='Y')
    {

        printf("\n\n\t\tEnter Full Name of Student: ");
        fflush(stdin);
        fgets(s.name,100,stdin);
        s.name[strlen(s.name)-1]='\0';

        printf("\n\n\t\tEnter Depertment Name: ");
        fflush(stdin);
        fgets(s.dept,50,stdin);
        s.dept[strlen(s.dept)-1]='\0';

        printf("\n\n\t\tEnter Roll number: ");
        scanf("%d",&s.roll);

        printf("\n\n\tEnter SGPA for 8 semesters\n");
        for(i=0,cgpa=0; i<8; i++)
        {
            scanf("%f",&s.sgpa[i]);
            cgpa+=s.sgpa[i];

        }

        cgpa/=8.0;
        s.cgpa=cgpa;

        fwrite(&s,sizeof(s),1,fp);

        printf("\n\n\t\tAdd another student?(Y/N)?");
        fflush(stdin);
        another=getchar();
    }
}


FILE * del(FILE * fp)
{
    title();

    Student s;
    int flag=0,tempRoll,siz=sizeof(s);
    FILE *ft;

    if((ft=fopen("temp.txt","wb+"))==NULL)
    {
        printf("\n\n\t\t\t\\t!!! ERROR !!!\n\t\t");
        system("pause");
        return fp;
    }

    printf("\n\n\tEnter Roll number of Student to Delete the Record");
    printf("\n\n\t\t\tRoll No. : ");
    scanf("%d",&tempRoll);

    rewind(fp);


    while((fread(&s,siz,1,fp))==1)
    {
        if(s.roll==tempRoll)
        {
            flag=1;
            printf("\n\tRecord Deleted for");
            printf("\n\n\t\t%s\n\n\t\t%s\n\n\t\t%d\n\t",s.name,s.dept,s.roll);
            continue;
        }

        fwrite(&s,siz,1,ft);
    }


    fclose(fp);
    fclose(ft);

    remove("db.txt");
    rename("temp.txt","db.txt");

    if((fp=fopen("db.txt","rb+"))==NULL)
    {
        printf("ERROR");
        return  NULL;
    }

    if(flag==0) printf("\n\n\t\tNO STUDENT FOUND WITH THE INFORMATION\n\t");

    printChar('-',65);
    printf("\n\t");
    system("pause");
    return fp;
}



