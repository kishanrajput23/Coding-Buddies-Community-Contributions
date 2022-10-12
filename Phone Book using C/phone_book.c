#include<stdio.h>
void add();
void search();
void delet();
void view();
void about();

void main()
{
    system("cls");
    printf("\t*****PHONE BOOK*****\n");
    printf("\t 1. Add Contact\n");
    printf("\t 2. Search Contact\n");
    printf("\t 3. Delete Contact\n");
    printf("\t 4. View All Contact\n");
    printf("\t 5. About developer\n");
    printf("\t 6. Exit\n");
    printf("\nEnter Your Choice:-");
    int option;
    scanf("%d",&option);
    switch(option)
    {
    case 1:a
        add();
        break;
    case 2:
        search();
        break;
    case 3:
        delet();
        break;
    case 4:
        view();
        break;
    case 5:
        about();
        break;
    case 6:
        exit(0);
    default:
        main();
    }
}
void add()
{
    FILE *fp;
    fp=fopen("contact.txt","a+");
    system("cls");
    printf("\t*****ADD CONTACT*****");
    printf("\n\tName    :-\n");
    char name[20];
    scanf("%s", name);
    printf("\n\tMob No. :-  " );
    char mob[20];
    scanf(mob);
    fprintf(fp,"%s\n",name);
    fprintf(fp, "%s\n", mob);
    fclose(fp);
    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getc;
    main();
}
void search()
{
    FILE *fp;
    fp=fopen("contact.txt","r");
    system("cls");
    printf("\t*****SEARCH CONTACT*****");
    printf("\n\t Enter Name :-");
    char name[20];
    scanf("%s",name);
    char name1[20],mob[20];
    while(fscanf(fp,"%s %s",name1,mob)!=EOF)
    {
        if(strcmp(name,name1)==0)
        {
            printf("\n\tNAME     :- %s\n",name1);
            printf("\n\tMOB NO.  :- %s\n",mob);
        }
    }
    fclose(fp);
    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getc;
    main();
}
void delet()
{
    FILE *fp,*fp1;
    fp=fopen("contact.txt","r+");
    fp1=fopen("temp.txt","w");
    system("cls");
    printf("\t*****DELETE CONTACT*****");
    printf("\n\t Enter Name :-");
    char name[20];
    scanf("%s",name);
    char name1[20],mob[20];
    while(fscanf(fp,"%s %s",name1,mob)!=EOF)
    {
        if(strcmp(name,name1)==0)
        {
            continue;
        }
        fprintf(fp1,"%s %s\n",name1,mob);
    }
    fclose(fp);
    fclose(fp1);
    fp=fopen("contact.txt","w");
    fp1=fopen("temp.txt","r");
    while(fscanf(fp1,"%s %s",name1,mob)!=EOF)
    {

        fprintf(fp,"%s %s\n",name1,mob);
    }
    fclose(fp);
    fclose(fp1);
    remove("temp.txt");
    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getc;
    main();
}
void view()
{
    FILE *fp;
    fp=fopen("contact.txt","r");
    system("cls");
    printf("\t*****ALL CONTACTS*****");
    char name1[20],mob[20];
    while(fscanf(fp,"%s %s",name1,mob)!=EOF)
    {
        printf("\n\t NAME    :-  %s",name1);
        printf("\n\t MOB NO. :-  %s",mob);
    }
    fclose(fp);
    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getc;
    main();
}
void about()
{
    system("cls");
    printf("\n\t this project is made by MUHAMMAD ASIF\n");
    printf("\t Profession Web Developer\n");
    printf("\t alexasifhhossain@gmail.com\n");
    printf("\t Institute of science & technology\n");

    printf("\n\tPRESS ANY KEY TO CONTINUE");
    getc;
    main();
}
