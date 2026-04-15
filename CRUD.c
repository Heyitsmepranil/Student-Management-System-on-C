/*  Code Written and Owned By: Pranil Tandukar */

//A program which contains features to add, edit, delete, and view record of the students in a database

//header files used.
#include <stdio.h>
#include <stdlib.h>    
#include <string.h>

//structure to store data
typedef struct          
{
    char name[50];
    int roll;
    int year;
    char sec[5];
    char fac[30];
    int nfac;
    long ph;
    char add[50];
} stud;

//declaration of functions
void add();            
void view(int c);
void edit();
void delete();
void sort();
char *strupr(char string[]);
int choice(int c);

//main function
int main()              
{
    system("clear");    //used as clrscr()
 
    int c,check;        
    
    repeat:

    printf("STUDENT MANAGEMENT SYSTEM \n \n");
    printf("WELCOME to the student management system. Please enter the action you want to do. \n"); 
    printf("\n Create records.  (1) \n View records.\t  (2) \n Edit records.\t  (3) \n Delete records.  (4) \n Exit the program.(5) \n \nPlease enter number: ");
    
    scanf("%d",&c);

    check=choice (c);
    if(check == 0)          //0 is returned from the choice() function so that the menu is not exited unless and until the users commands
    {
       system("clear");     //used as clrscr()
        goto repeat;
    }

    return 0;
    
}

int choice(int c)       //function which executes the option from the users.
{
    char temp;
    switch(c)
    {
        
        case 1:
            sort();
            add();
            return (0);
            break;
        
        case 2:
            sort();
            view(0);
            return(0);
            break;
        
        case 3:
            sort();
            edit();
            return(0);
            break;
        
        case 4:
            sort();
            delete();
            return(0);
            break;
        
        case 5:
            return(1);          //1 is returned in order to exit the program
            break;

        default:
            printf("\nInvalid action. Please enter a valid choice. \n \nPress hit enter to continue to.  ");
            getchar();
            temp=getchar();
            return (0);
            break;
    }
}

//function which helps to write a record.
void add()
{
    FILE *fptr;
    fptr = fopen("student.bin","ab");

    stud s;
    char c,temp;

    if(fptr==NULL)
    {
        printf("Error occured during opening the file.");
    }

    do
    {
        system("clear");    //used as clrscr()
        
        printf("STUDENT MANAGEMENT SYSTEM \n \n");

        printf("Enter the details of the student (format: name/year/faculty/section/roll/phone no./address) \n\n");
        printf("Name: ");
        getchar(); 
        fgets(s.name, sizeof(s.name), stdin);
        s.name[strcspn(s.name, "\n")] = '\0';  
        printf("Year: ");
        scanf("%d",&s.year);
        printf("Faculty: ");
        scanf("%s",s.fac);
        strupr(s.fac);
        printf("Section: ");
        scanf("%s",s.sec);
        strupr(s.sec);
        printf("Roll number: ");
        scanf("%d",&s.roll);
        printf("Phone number: ");
        scanf("%ld",&s.ph);
        printf("Address: ");
        getchar(); 
        fgets(s.add, sizeof(s.add), stdin);
        s.add[strcspn(s.add, "\n")] = '\0';
        
        if(strcmp(s.fac,"BCT")==0) s.nfac=1;    //used during sorting.
        if(strcmp(s.fac,"BEI")==0) s.nfac=2;
        if(strcmp(s.fac,"BEL")==0) s.nfac=3;
        if(strcmp(s.fac,"BCE")==0) s.nfac=4;

        fwrite(&s,sizeof(stud),1,fptr);

        printf("\nAdd another? (Y/N)");
        c=getchar();
        
        if (c!='Y')
        {
            printf("\nProceeding to main menu. Press enter to continue. ");
            getchar();
            temp=getchar();
        }
    
    }while(c=='Y');    

    fclose(fptr);

}

//funtion which helps to view a record.
void view(int c)
{
    stud t;
    int i=5,j=1;
    char temp;

    system("clear");    //used as clrscr()

    FILE *fptr;
    fptr=fopen("student.bin","rb");

     if(fptr==NULL)
    {
        printf("Error occured during opening the file.");
    }

    printf("STUDENT MANAGEMENT SYSTEM \n\n");
    printf("S.no.\tName");
    printf("\033[3;30H");           //helps with making the interface cleaner.
    printf("Year\tFaculty\t\tSection\t\tRoll no.\tPhone no.\tAddress\n\n");
    while(fread(&t,sizeof(stud),1,fptr)==1)
    {
        printf("%d\t%s",j++,t.name);
        printf("\033[%d;30H",i++);
        printf("%d\t\t%s\t\t%s\t\t%d\t\t%ld\t%s\n",t.year,t.fac,t.sec,t.roll,t.ph,t.add);
    }

    if(c==0)
    {
        printf("\nPlease hit enter to proceed to the main menu. ");

        getchar();
        temp=getchar();
        fclose(fptr);

    }
}

//function that allows the user to edit a record.
void edit()
{
    FILE *fptr;
    fptr = fopen("student.bin","rb+");

    if(fptr==NULL)
    {
        printf("Error occured during opening the file.");
    }


    char temp,ch;
    int c;
    stud s;

    repeat:

    printf("STUDENT MANAGEMENT SYSTEM \n\n");

    view(1);

    printf("\nPlease enter the data to be edited: ");
    scanf("%d",&c);

    system("clear");        //used as clrscr()

    printf("STUDENT MANAGEMENT SYSTEM \n\n");
    printf("Please enter the details.\n\n");

    fseek(fptr,(c-1)*sizeof(stud),SEEK_SET);

    printf("Name: ");
    getchar(); 
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';  

    printf("Year: ");
    scanf("%d",&s.year);
    printf("Faculty: ");
    scanf("%s",s.fac);
    strupr(s.fac);
    printf("Section: ");
    scanf("%s",s.sec);
    strupr(s.sec);
    printf("Roll number: ");
    scanf("%d",&s.roll);
    printf("Phone number: ");
    scanf("%ld",&s.ph);
    printf("Address: ");
    getchar(); 
    fgets(s.add, sizeof(s.add), stdin);
    s.add[strcspn(s.add, "\n")] = '\0';  

    if(strcmp(s.fac,"BCT")==0) s.nfac=1;
    if(strcmp(s.fac,"BEI")==0) s.nfac=2;
    if(strcmp(s.fac,"BEL")==0) s.nfac=3;
    if(strcmp(s.fac,"BCE")==0) s.nfac=4;
    
    fwrite(&s,sizeof(stud),1,fptr);
    
    printf("\nEdit another? (Y/N)");
    ch=getchar();
        
    if (ch=='Y')
    {
       goto repeat;
    }
    else
    {
        printf("\nProceeding to main menu. Press enter to continue. ");
        getchar();
        temp=getchar();
    }
    
    fclose(fptr);
}

//funtion to delete a record.
void delete()
{
    FILE *fptr;
    fptr = fopen("student.bin","rb");

    if(fptr==NULL)
    {
        printf("Error occured during opening the file. It doesnt exist.");
        getchar();
        getchar();
    }

    int count=0,i,j=1,c;
    stud temp;

    while(fread(&temp,sizeof(stud),1,fptr)==1)
    {
        count++;
    }

    stud s[count];

    rewind(fptr);
    fread(s,sizeof(stud),count,fptr);
    rewind(fptr);

    printf("STUDENT MANAGEMENT SYSTEM \n\n");

    view(1);

    printf("\nPlease enter the data to be deleted: ");
    scanf("%d",&c);

    if(c>count)
    {
        printf("\nInvalid choice. Please enter again. ");
        scanf("%d",&c);
    }
    
    system("clear");        //used as clrscr()
    
    for(i=c-1;i<count-1;i++)
    {
        s[i] = s[i + 1];
    }
    
    fclose(fptr);
    fptr=fopen("student.bin","wb");
    fwrite(s,sizeof(stud),count-1,fptr);
    fclose(fptr);

    printf("STUDENT MANAGEMENT SYSTEM \n\n");
    printf("The data record has been deleted. Please hit enter to continue. ");
    getchar();
    getchar();


}

//function which sorts the record in the priorty of faculty>year>roll.
void sort()
{
    FILE *fptr;
    fptr = fopen("student.bin","rb");

    if(fptr==NULL)
    {
        printf("Error occured during opening the file. It doesnt exist.");
        getchar();
        getchar();
    }


    int count=0,i,j;
    stud temp;

    while(fread(&temp,sizeof(stud),1,fptr)==1)
    {
        count++;
    }

    stud s[count];

    rewind(fptr);
    fread(s,sizeof(stud),count,fptr);
    rewind(fptr);

    for(i=0;i<count;i++)
    {
        for(j=i+1;j<count;j++)
        {
            if 
            (
                (s[i].nfac > s[j].nfac) ||
                (s[i].nfac == s[j].nfac && s[i].year > s[j].year) ||
                (s[i].nfac == s[j].nfac && s[i].year == s[j].year && s[i].roll > s[j].roll)
            )
                {
                    temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                }
        }
    }

    fclose(fptr);
    fptr=fopen("student.bin","wb");
    fwrite(s,sizeof(stud),count,fptr);
    fclose(fptr);

}

//since strupr() is not a standard function in <string.h>. a UDF was created to do the task of strupt().
char *strupr(char string[])
{   
    int i;
    int n=strlen(string);

    for(i=0;i<n;i++)
    {
        if((string[i]<=122)&&(string[i]>=97))
        {
            string[i]=string[i]-32;
        }
    }

    return(string);
}