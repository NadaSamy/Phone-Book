#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "structures.h"
#include "prototype.h"

int count=0;
Contacts ar[100];

int validst(char *s)
{
    if (( (*s<'a') || (*s>'z') )&&( (*s<'A') || (*s>'Z')))
        return 0;
    while (*s)
    {
        if (isdigit(*s++) == 0)
            return 1;

    }

    return 0;
}
int validI(char *v)
{
    while((*v)!='\0')
    {
        if (isdigit(*v)!=0)
        {
            v++;
            continue;
        }
        else
        {
            return 0;
            break;

        }
    }
    return 1;

}

int validPN(char *s)
{
    int x=0;
    while(*s++!='\0')
        x++;
    if( x>=7 && x<=11)
        return 1;
    else
        return 0;
}
int validemail(char s[])
{
    int length=strlen(s),flag,x=0, index1=0, index2=0;
    while(s[x]!='\0')
    {
        if (s[x]=='@')
        {
            flag=0;
            index1=x+1;
            break;
        }
        flag=1;
        x++;
    }
     if(index1<9)
    {
        printf("Error.\nInvalid Email.\nEnter 8 characters or more.\n\n\n");
        return 0;
    }
    if(flag==1)
    {
        return 0;
    }
    if (( (s[0]<'a') || (s[0]>'z') )&&( (s[0]<'A') || (s[0]>'Z')))
        return 0;
    else
    {
        for (x=1; x<length; x++)
        {
            if ((( (s[x]<'a') ||(s[x]>'z') )&&( (s[x]<'A') || (s[x]>'Z')))&& ((s[x]<'0') || (s[x]>'9'))&&(s[x]!='_')&&(s[x]!='.')&&(s[x]!='@'))
                return 0;
        }
    }
    if ((( (s[index1]<'a') || (s[index1]>'z') )&&( (s[index1]<'A') || (s[index1]>'Z'))))
        return 0;
    else
    {
        for (flag=index1; flag<length; flag++)
        {
            if (s[flag]=='.')
            {
                index2=flag+1;
                break;
            }
            else if ((( (s[flag]<'a') || (s[flag]>'z') )&&( (s[flag]<'A') || (s[flag]>'Z'))))
                return 0;
        }
        if (tolower(s[index2]) == 'c' && tolower(s[index2+1]) == 'o'&& tolower(s[index2+2]) == 'm'&& s[index2+3] == '\0')
            return 1;
        else
            return 0;
    }
}

void load()
{
    FILE *f1;
    f1=fopen("contacts1.txt","r");
    while(!feof(f1))
    {
        fscanf(f1,"%[^,],",ar[count].firstname);
        fscanf(f1,"%[^,],",ar[count].lastname);
        fscanf(f1,"%[^-]-",ar[count].DOB.day);
        fscanf(f1,"%[^-]-",ar[count].DOB.month);
        fscanf(f1,"%[^,],",ar[count].DOB.year);
        fscanf(f1,"%[^,],",ar[count].address);
        fscanf(f1,"%[^,],",ar[count].email);
        fscanf(f1,"%[^\n]\n",ar[count].phonenumber);
        count++;
    }
    fclose(f1);
}

void modify_Normal()
{
    Contacts R;
    Contacts * list[count];
    int m,i;
    int list_count=0;
    if(count==0)
    {
        printf("Error, you must load contacts first.\n\n\n");
        return;
    }
    printf("Please enter last name for the contact you want to modify: \n");
    scanf("%[^\n]",R.lastname);
    getchar();
    if(validst(R.lastname))
    {
        printf("\nSearch Result: \n\n");
        for(i=0; i<count; i++)
        {
            if(strcasecmp(R.lastname,ar[i].lastname)==0)
            {
                list[list_count]=ar+i;
                list_count++;
                printf("First name: %s\nLast name: %s\n",ar[i].firstname,ar[i].lastname);
                printf("Date of birth: %s-%s-%s\n",ar[i].DOB.day,ar[i].DOB.month,ar[i].DOB.year);
                printf("Address: %s\nEmail: %s\nPhone number: %s\n\n",ar[i].address,ar[i].email,ar[i].phonenumber);

            }
        }
        if(list_count==0)
        {
            printf("This last name does not match any existing contact.\n\n\n");
            return;
        }
    }
    else
    {
        printf("Error.\nEnter characters only.\n\n\n");
        return;
    }
    printf("After seeing every matching contact please enter the email of the contact you want to modify: \n");
    scanf("%[^\n]",R.email);
    getchar();
    if(validemail(R.email))
    {
        for(i=0; i<list_count; i++)
        {
            if(strcasecmp(R.email,list[i]->email)==0)
            {
                while(1)
                {
                    printf("\n\nMODIFY MENU: \n");
                    printf("Choose what you want to modify about this contact: \n");
                    printf("1-first name.\n");
                    printf("2-last name.\n");
                    printf("3-Date of birth.\n");
                    printf("4-Address. \n");
                    printf("5-Email.\n");
                    printf("6-Phone number.\n");
                    printf("7-Quit.\n");
                    printf("Choice: \n");
                    scanf("%d",&m);
                    getchar();
                    switch(m)
                    {
                    case 1:
                        printf("Enter new first name: \n");
                        scanf("%[^\n]",list[i]->firstname);
                        getchar();
                        if(validst(list[i]->firstname)==0)
                        {
                            printf("\n\nError.\nEnter characters only.\n");
                        }
                        else
                        {
                            printf("\nFirst name has been modified.\n");
                        }
                        break;
                    case 2:
                        printf("Enter new last name: \n");
                        scanf("%[^\n]",list[i]->lastname);
                        getchar();
                        if(validst(list[i]->lastname)==0)
                        {
                            printf("\n\nError.\nEnter characters only.\n");
                        }
                        else
                        {
                            printf("\nLast name has been modified.\n");
                        }
                        break;
                    case 3:
                        printf("Date of birth: \n");
                        printf("Enter new day of birth in numbers: \n");
                        scanf("%[^\n]",list[i]->DOB.day);
                        getchar();
                        if(validI(list[i]->DOB.day))
                        {
                            if(atoi(list[i]->DOB.day)>31 || atoi(list[i]->DOB.day)<=0)
                            {
                                printf("Error.\nInvalid Input.\n");
                                break;
                            }
                        }
                        else
                        {
                            printf("Error.\nInvalid input.\n");
                            break;
                        }
                        printf("Enter new month of birth in numbers: \n");
                        scanf("%[^\n]",list[i]->DOB.month);
                        getchar();
                        if(validI(list[i]->DOB.month))
                        {
                            if(atoi(list[i]->DOB.month)>12 || atoi(list[i]->DOB.month)<=0)
                            {
                                printf("Error.\nInvalid Input.\n\n");
                                break;
                            }
                            if(atoi(list[i]->DOB.month)==2)
                            {
                                if(atoi(list[i]->DOB.day)>28)
                                {
                                    printf("Error.\nInvalid input.\nThis month has only 28 days.\n\n");
                                    break;
                                }

                            }
                            if(atoi(list[i]->DOB.month)==4 || atoi(list[i]->DOB.month)==6 || atoi(list[i]->DOB.month)==9 || atoi(list[i]->DOB.month)==11)
                            {
                                if(atoi(list[i]->DOB.day)>30)
                                {
                                    printf("Error.\nInvalid input.\nThis month has only 30 days.\n\n");
                                    break;
                                }
                            }
                        }
                        else
                        {
                            printf("Error.\nEnter numbers only.\n");
                            break;
                        }
                        printf("Enter new year of birth in numbers: \n");
                        scanf("%[^\n]",list[i]->DOB.year);
                        getchar();
                        if(validI(list[i]->DOB.year))
                        {
                            if(atoi(list[i]->DOB.year)>=9999 || atoi(list[i]->DOB.year)<=1900)
                            {
                                printf("Error.\nInvalid input.\n");
                                break;
                            }
                        }
                        else
                        {
                            printf("Error.\nInvalid input.\n");
                            printf("Enter numbers only.\n\n\n");
                            break;
                        }
                        printf("Contact's date of birth has been modified.\n");
                        break;
                    case 4:
                        printf("Enter new address: \n");
                        scanf("%[^\n]",list[i]->address);
                        getchar();
                        printf("\nAddress has been modified.\n");
                        break;
                    case 5:
                        printf("Enter new email: \n");
                        scanf("%[^\n]",list[i]->email);
                        getchar();
                        if(validemail(list[i]->email)==0)
                        {
                            printf("Error.\nInvalid email.\n\n");
                            break;
                        }
                        else
                        {
                            printf("Email has been modified.\n");
                        }
                        break;
                    case 6:
                        printf("Enter new phone number: \n");
                        scanf("%[^\n]",list[i]->phonenumber);
                        getchar();
                        if(validI(list[i]->phonenumber))
                        {
                            if(validPN(list[i]->phonenumber)==0)
                            {
                                printf("Error.\nInvalid phone number.\n\n\n");
                                break;
                            }
                            else
                            {
                                printf("\nPhone number has been modified.\n");
                            }
                        }
                        else
                        {
                            printf("Error.\nInvalid input.\n\n");
                            break;
                        }
                        break;
                    case 7:
                        main();
                        break;
                    default:
                        printf("Error, enter numbers from 1-6.\n");
                        break;

                    }
                }
            }
            else
            {
                printf("Error.\nThe email you entered doesn't exist in contacts.\n\n\n");
                return;
            }
        }
    }
    else
    {
        printf("Error.\nInvalid email.\n\n\n");
        return;
    }
}
void save()
{
    FILE *f1;
    if(count==0)
    {
        printf("Error, you must load contacts first before performing this action.\n\n\n");
        return;
    }
    f1=fopen("contacts1.txt","w");
    int i;
    for(i=0; i<count; i++)
    {
        fprintf(f1,"%s,",ar[i].firstname);
        fprintf(f1,"%s,",ar[i].lastname);
        fprintf(f1,"%s-",ar[i].DOB.day);
        fprintf(f1,"%s-",ar[i].DOB.month);
        fprintf(f1,"%s,",ar[i].DOB.year);
        fprintf(f1,"%s,",ar[i].address);
        fprintf(f1,"%s,",ar[i].email);
        fprintf(f1,"%s\n",ar[i].phonenumber);
    }
    fclose(f1);
    if(count!=0)
    {
        printf("Your changes have been saved successfully.\n\n\n");
    }
}
void add()
{
    Contacts x;
    if(count==0)
    {
        printf("Error, you must load contacts first.\n");
        return;
    }
    printf("Enter the new contact info: \n");
    printf("Enter first name: \n");
    scanf("%[^\n]",x.firstname);
    getchar();
    if(validst(x.firstname)==0)
    {
        printf("Error.\nInvalid input.\n\n\n");
        return;
    }
    printf("Enter last name: \n");
    scanf("%[^\n]",x.lastname);
    getchar();
    if(validst(x.lastname)==0)
    {
        printf("Error.\nInvalid input.\n\n\n");
        return;
    }
    printf("Date of birth: \n");
    printf("Enter day of birth: \n");
    scanf("%[^\n]",x.DOB.day);
    getchar();
    if(validI(x.DOB.day))
    {
        if(atoi(x.DOB.day)>31 || atoi(x.DOB.day)<=0)
        {
            printf("Error.\nInvalid Input.\n");
            return;
        }
    }
    else
    {
        printf("Error.\nInvalid input.\n");
        return;
    }
    printf("Enter month of birth in numbers: \n");
    scanf("%[^\n]",x.DOB.month);
    getchar();
    if(validI(x.DOB.month))
    {
        if(atoi(x.DOB.month)>12 || atoi(x.DOB.month)<=0)
        {
            printf("Error.\nInvalid Input.\n\n");
            return;
        }

        if(atoi(x.DOB.month)==2)
        {
            if(atoi(x.DOB.day)>28)
            {
                printf("Error.\nInvalid input.\nThis month has only 28 days.\n\n");
                return;
            }

        }
        if(atoi(x.DOB.month)==4 || atoi(x.DOB.month)==6 || atoi(x.DOB.month)==9 || atoi(x.DOB.month)==11)
        {
            if(atoi(x.DOB.day)>30)
            {
                printf("Error.\nInvalid input.\nThis month has only 30 days.\n\n");
                return;
            }
        }
    }
    else
    {
        printf("Error.\nInvalid input.\n");
        return;
    }
    printf("Enter year of birth in numbers: \n");
    scanf("%[^\n]",x.DOB.year);
    getchar();
    if(validI(x.DOB.year))
    {
        if(atoi(x.DOB.year)>=9999 || atoi(x.DOB.year)<=1900)
        {
            printf("Error.\nInvalid input.\n");
            return;
        }
    }
    else
    {
        printf("Error.\nInvalid input.\n");
        printf("Enter numbers only.\n\n\n");
        return;
    }
    printf("Enter address: \n");
    gets(x.address);
    printf("Enter email: \n");
    scanf("%[^\n]",x.email);
    getchar();
    if(validemail(x.email)==0)
    {
        printf("Error.\nInvalid email.\n\n\n");
        return;
    }
    printf("Enter phone number: \n");
    scanf("%[^\n]",x.phonenumber);
    getchar();
    if(validI(x.phonenumber))
    {
        if(validPN(x.phonenumber)==0)
        {
            printf("Error.\nInvalid phone number.\n\n\n");
            return;
        }
    }
    else
    {
        printf("Error.\nInvalid input.\n");
        return;
    }

    system("cls");
    ar[count]=x;
    printf("Contact has been added successfully.\n\n");
    count++;

}


void delete_contact()
{
    int i;
    int flag=0;
    Contacts z;
    if(count==0)
    {
        printf("Error, you must load contacts first.\n");
        return;
    }
    printf("Enter first name of this contact: \n");
    scanf("%[^\n]",z.firstname);
    getchar();
    if(validst(z.firstname))
    {
        for(i=0; i<count; i++)
        {
            if(strcasecmp(z.firstname,ar[i].firstname)==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("Error.\nThis first name does not exist in contacts.\n");
            return;
        }
    }
    else
    {
        printf("Error.\nEnter characters only.\n");
        return;
    }
    flag=0;
    printf("Enter last name of this contact: \n");
    scanf("%[^\n]",z.lastname);
    getchar();
    if(validst(z.lastname))
    {
        for(i=0; i<count; i++)
        {
            if(strcasecmp(z.lastname,ar[i].lastname)==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("Error.\nThis last name does not exist in contacts.\n");
            return;
        }
    }
    else
    {
        printf("Error.\nEnter characters only.\n");
        return;
    }
    printf("Enter email of this contact: \n");
    scanf("%[^\n]",z.email);
    getchar();
    if(validemail(z.email))
    {
        for(i=0; i<count; i++)
        {
            if(strcasecmp(z.email,ar[i].email)==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("Error.\nThis email does not exist in contacts.\n");
            return;
        }

    }
    else
    {
        printf("Error.\nInvalid email.\n\n\n");
        return;
    }
    for(i=0; i<count; i++)
    {
        if(strcasecmp(z.firstname,ar[i].firstname)==0 && strcasecmp(z.lastname,ar[i].lastname)==0 && strcasecmp(z.email,ar[i].email)==0)
        {
            ar[i]=ar[count-1];
            count--;
        }
    }

    printf("Contact has been deleted successfully.\n\n\n");
}

void quitproject()
{
    exit(0);
}
void SortByLname()
{
    int i,j;
    Contacts temp;
    for(i=0; i<count; i++)
    {
        for(j=0; j<count-i-1; j++)
        {
            if(strcasecmp(ar[j].lastname,ar[j+1].lastname)==1)
            {
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
        }
    }
    for(i=0; i<count; i++)
    {
        printf("CONTACT #%d: \n\n",i+1);
        printf("First name: %s\n",ar[i].firstname);
        printf("Last name: %s\n",ar[i].lastname);
        printf("Date of birth:%s-%s-%s\n",ar[i].DOB.day,ar[i].DOB.month,ar[i].DOB.year);
        printf("Address: %s\n",ar[i].address);
        printf("Email: %s\n",ar[i].email);
        printf("Phone number: %s\n\n\n",ar[i].phonenumber);
    }
}

void SortByDOB()
{
    int i,j;
    Contacts temp;
    for(i=0; i<count; i++)
    {
        for(j=0; j<count-i-1; j++)
        {
            if(atoi(ar[j].DOB.year)>atoi(ar[j+1].DOB.year))
            {
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
            else if(atoi(ar[j].DOB.year)==atoi(ar[j+1].DOB.year) && atoi(ar[j].DOB.month)>atoi(ar[j+1].DOB.month))
            {
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
            else if(atoi(ar[j].DOB.year)==atoi(ar[j+1].DOB.year) && atoi(ar[j].DOB.month)==atoi(ar[j+1].DOB.month) && atoi(ar[j].DOB.day)>atoi(ar[j+1].DOB.day))
            {
                temp=ar[j];
                ar[j]=ar[j+1];
                ar[j+1]=temp;
            }
            else if(atoi(ar[j].DOB.year)==atoi(ar[j+1].DOB.year) && atoi(ar[j].DOB.month)==atoi(ar[j+1].DOB.month) && atoi(ar[j].DOB.day)==atoi(ar[j+1].DOB.day))
                printf("All contacts have the same birthday.\n");

        }
    }
    for(i=0; i<count; i++)
    {
        printf("CONTACT #%d: \n\n",i+1);
        printf("First name: %s\n",ar[i].firstname);
        printf("Last name: %s\n",ar[i].lastname);
        printf("Date of birth:%s-%s-%s\n",ar[i].DOB.day,ar[i].DOB.month,ar[i].DOB.year);
        printf("Address: %s\n",ar[i].address);
        printf("Email: %s\n",ar[i].email);
        printf("Phone number: %s\n\n\n",ar[i].phonenumber);
    }

}

void print_contacts()
{
    int i;
    if(count==0)
    {
        printf("Error. Load contacts first.\n");
    }
    else
        for(i=0; i<count; i++)
        {
            printf("CONTACT #%d: \n\n",i+1);
            printf("First name: %s\nLast name: %s\n",ar[i].firstname,ar[i].lastname);
            printf("Date of birth: %s-%s-%s\n",ar[i].DOB.day,ar[i].DOB.month,ar[i].DOB.year);
            printf("Address: %s\nEmail: %s\nPhone number: %s\n\n",ar[i].address,ar[i].email,ar[i].phonenumber);
        }
}

void print_sorted()
{
    int choice;
    if(count==0)
    {
        printf("Error, you must load contacts first.\n");
        return;
    }
    printf("How would you like to sort contacts? \n");
    printf("1-By last name. \n");
    printf("2-By date of birth. \n");
    printf("Choice: \n");
    scanf("%d",&choice);
    getchar();
    if(choice==1)
        SortByLname();
    else
        SortByDOB();
}

void search_Normal()
{
    int i;
    int flag=0;
    Contacts R;
    if(count==0)
    {
        printf("Error, you must load contacts first.\n");
        return;
    }
    printf("Please enter the last name of this contact: \n");
    scanf("%[^\n]",R.lastname);
    getchar();
    if(validst(R.lastname))
    {
        for(i=0; i<count; i++)
        {
            if(strcasecmp(R.lastname,ar[i].lastname)==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("Error.\nThis last name does not exist in contacts.\n");
            return;
        }
    }
    else
    {
        printf("Error.\nEnter characters only.\n");
        return;
    }
    printf("Search Result: \n\n");
    for(i=0; i<count; i++)
    {
        if(strcasecmp(R.lastname,ar[i].lastname)==0)
        {
            printf("First name: %s\nLast name: %s\n",ar[i].firstname,ar[i].lastname);
            printf("Date of birth: %s-%s-%s\n",ar[i].DOB.day,ar[i].DOB.month,ar[i].DOB.year);
            printf("Address: %s\nEmail: %s\nPhone number: %s\n\n\n",ar[i].address,ar[i].email,ar[i].phonenumber);
        }

    }


}

void search_advanced()
{
    Contacts R;
    char temp_str[2];
    int list_count=0;
    Contacts * list[count];
    int counter,i,flagF,flagL,flagDOB,flagAdd,flagE,flagP;
    int flag;
    flag=0;
    flagF=0;
    flagL=0;
    flagAdd=0;
    flagDOB=0;
    flagE=0;
    flagP=0;
    counter=0;
    if(count==0)
    {
        printf("Error, you must load contacts first.\n\n\n");
        return;
    }
    printf("For each field if you want to use it in the search enter 1 if not press enter.\n\n");
    printf("1-First name: \n");
    flagF=scanf("%[^\n]",temp_str);
    getchar();
    if(flagF==1)
    {
        if(strcasecmp(temp_str,"1")!=0)
        {
            printf("Error.\nInvalid input.\n");
            printf("If you want to use this field in searching enter 1 only.\n\n\n");
            return;
        }
    }
    printf("2-Last name: \n");
    flagL=scanf("%[^\n]",temp_str);
    getchar();
    if(flagL==1)
    {
        if(strcasecmp(temp_str,"1")!=0)
        {
            printf("Error.\nInvalid input.\n");
            printf("If you want to use this field in searching enter 1 only.\n\n\n");
            return;
        }
    }
    printf("3-Date of birth: \n");
    flagDOB=scanf("%[^\n]",temp_str);
    getchar();
    if(flagDOB==1)
    {
        if(strcasecmp(temp_str,"1")!=0)
        {
            printf("Error.\nInvalid input.\n");
            printf("If you want to use this field in searching enter 1 only.\n\n\n");
            return;
        }
    }
    printf("4-Address: \n");
    flagAdd=scanf("%[^\n]",temp_str);
    getchar();
    if(flagAdd==1)
    {
        if(strcasecmp(temp_str,"1")!=0)
        {
            printf("Error.\nInvalid input.\n");
            printf("If you want to use this field in searching enter 1 only.\n\n\n");
            return;
        }
    }
    printf("5-Email: \n");
    flagE=scanf("%[^\n]",temp_str);
    getchar();
    if(flagE==1)
    {
        if(strcasecmp(temp_str,"1")!=0)
        {
            printf("Error.\nInvalid input.\n");
            printf("If you want to use this field in searching enter 1 only.\n\n\n");
            return;
        }
    }
    printf("6-Phone number: \n");
    flagP=scanf("%[^\n]",temp_str);
    getchar();
    if(flagP==1)
    {
        if(strcasecmp(temp_str,"1")!=0)
        {
            printf("Error.\nInvalid input.\n");
            printf("If you want to use this field in searching enter 1 only.\n\n\n");
            return;
        }
    }
    system("cls");
    if(flagF==1)
    {
        printf("Enter first name of the contact: \n");
        scanf("%[^\n]",R.firstname);
        getchar();
        if(validst(R.firstname))
        {
            for(i=0; i<count; i++)
            {
                if(strcasecmp(R.firstname,ar[i].firstname)==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                printf("This first name does not exist it contacts.\n\n\n");
                return;
            }
        }
        else
        {
            printf("Error.\nEnter characters only.\n\n\n");
            return;
        }
    }
    if(flagL==1)
    {
        printf("Enter last name of this contact: \n");
        scanf("%[^\n]",R.lastname);
        getchar();
        if(validst(R.lastname)==0)
        {
            for(i=0; i<count; i++)
            {
                if(strcasecmp(R.lastname,ar[i].lastname)==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                printf("This last name does not exist it contacts.\n\n\n");
                return;
            }
        }
        else
        {
            printf("Error.\nEnter characters only.\n\n\n");
            return;
        }
    }
    flag=0;
    if(flagDOB==1)
    {
        printf("Date of birth of this contact: \n");
        printf("Enter day of birth: \n");
        scanf("%[^\n]",R.DOB.day);
        getchar();
        if(validI(R.DOB.day))
        {
            if(atoi(R.DOB.day)>31 || atoi(R.DOB.day)<=0)
            {
                printf("Error.\nInvalid Input.\n");
                return;
            }
        }
        else
        {
            printf("Error.\nInvalid input.\n");
            return;
        }
        printf("Enter month of birth: \n");
        scanf("%[^\n]",R.DOB.month);
        getchar();
        if(validI(R.DOB.month))
        {
            if(atoi(R.DOB.month)>12 || atoi(R.DOB.month)<=0)
            {
                printf("Error.\nInvalid Input.\n\n");
                return;
            }
            if(atoi(R.DOB.month)==2)
            {
                if(atoi(R.DOB.day)>28)
                {
                    printf("Error.\nInvalid input.\nThis month has only 28 days.\n\n");
                    return;
                }

            }
            if(atoi(R.DOB.month)==4 || atoi(R.DOB.month)==6 || atoi(R.DOB.month)==9 || atoi(R.DOB.month)==11)
            {
                if(atoi(R.DOB.day)>30)
                {
                    printf("Error.\nInvalid input.\nThis month has only 30 days.\n\n");
                    return;
                }
            }
        }
        else
        {
            printf("Error.\nInvalid input.\n");
            return;
        }
        printf("Enter year of birth: \n");
        scanf("%[^\n]",R.DOB.year);
        getchar();
        if(validI(R.DOB.year))
        {
            if(atoi(R.DOB.year)>=9999 || atoi(R.DOB.year)<=1900)
            {
                printf("Error.\nInvalid input.\n");
                return;
            }
        }
        else
        {
            printf("Error.\nInvalid input.\n");
            printf("Enter numbers only.\n\n\n");
            return;
        }
        for(i=0; i<count; i++)
        {
            if(atoi(R.DOB.day)==atoi(ar[i].DOB.day) && atoi(R.DOB.month)==atoi(ar[i].DOB.month) && atoi(R.DOB.year)==atoi(ar[i].DOB.year))
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("This date of birth does not exist in contacts.\n\n\n");
            return;
        }
    }
    flag=0;
    if(flagAdd==1)
    {
        printf("Enter address of this contact: \n");
        gets(R.address);
        for(i=0; i<count; i++)
        {
            if(strcasecmp(R.address,ar[i].address)==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("This address does not exist in contacts.\n\n\n");
            return;
        }
    }
    flag=0;
    if(flagE==1)
    {
        printf("Enter this contact's email: \n");
        scanf("%[^\n]",R.email);
        getchar();
        if(validemail(R.email))
        {
            for(i=0; i<count; i++)
            {
                if(strcasecmp(R.email,ar[i].email)==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                printf("This email does not exist in contacts.\n\n\n");
                return;
            }
        }
        else
        {
            printf("Error.\nInvalid email.\n\n\n");
            return;
        }
    }
    flag=0;
    if(flagP==1)
    {
        printf("Enter this contact's phone number: \n");
        scanf("%[^\n]",R.phonenumber);
        getchar();
        if(validI(R.phonenumber))
        {
            if(validPN(R.phonenumber))
            {
                for(i=0; i<count; i++)
                {
                    if(atoi(R.phonenumber)==atoi(ar[i].phonenumber))
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    printf("This phone number does not exist in contacts.\n\n\n");
                    return;
                }
            }
            else
            {
                printf("Error.\nInvalid phone number.\n\n\n");
                return;
            }
        }
        else
        {
            printf("Error.\nInvalid input.\n");
            return;
        }

    }
    for(i=0; i<count; i++)
    {

        if(flagF==1)
        {
            if(strcasecmp(R.firstname,ar[i].firstname)==0)
            {
                counter++;
            }
        }
        if(flagL==1)
        {
            if(strcasecmp(R.lastname,ar[i].lastname)==0)
            {
                counter++;
            }
        }
        if(flagDOB==1)
        {
            if(atoi(R.DOB.day)==atoi(ar[i].DOB.day) && atoi(R.DOB.month)==atoi(ar[i].DOB.month) && atoi(R.DOB.year)==atoi(ar[i].DOB.year))
            {
                counter++;
            }
        }
        if(flagAdd==1)
        {
            if(strcasecmp(R.address,ar[i].address)==0)
            {
                counter++;
            }
        }
        if(flagE==1)
        {
            if(strcasecmp(R.email,ar[i].email)==0)
            {
                counter++;
            }
        }
        if(flagP==1)
        {
            if(atoi(R.phonenumber)==atoi(ar[i].phonenumber))
            {
                counter++;
            }
        }
        if(counter==(flagAdd+flagDOB+flagE+flagF+flagL+flagP))
        {
            list[list_count]=ar+i;
            list_count++;
        }
        counter=0;
    }
    system("cls");
    printf("\nSearch Result: \n\n");
    if(list_count==0)
    {
        printf("No search match.\n\n");
        return;
    }
    for(i=0; i<list_count; i++)
    {
        printf("First name: %s\nLast name: %s\n",list[i]->firstname,list[i]->lastname);
        printf("Date of birth: %s-%s-%s\n",list[i]->DOB.day,list[i]->DOB.month,list[i]->DOB.year);
        printf("Address: %s\nEmail: %s\nPhone number: %s\n",list[i]->address,list[i]->email,list[i]->phonenumber);
        printf("\n");
    }
}

void modify_advanced()
{
    Contacts Y;
    Contacts R;
    char temp_str[2];
    int list_count=0;
    Contacts * list[count];
    int counter,i,flagL,flagDOB,flagAdd,flagE,flagP,m,flag;
    flag=0;
    flagL=0;
    flagAdd=0;
    flagDOB=0;
    flagE=0;
    flagP=0;
    counter=0;
    int flagF=0;
    if(count==0)
    {
        printf("Error, you must load contacts first.\n\n\n");
        return;
    }
    printf("For each field if you want to use it in the search enter 1 if not press enter.\n\n");
    printf("1-First name: \n");
    flagF=scanf("%[^\n]",temp_str);
    getchar();
    if(flagF==1)
    {
        if(strcasecmp(temp_str,"1")!=0)
        {
            printf("Error.\nInvalid input.\n");
            printf("If you want to use this field in searching enter 1 only.\n\n\n");
            return;
        }
    }
    printf("2-Last name: \n");
    flagL=scanf("%[^\n]",temp_str);
    getchar();
    if(flagL==1)
    {
        if(strcasecmp(temp_str,"1")!=0)
        {
            printf("Error.\nInvalid input.\n");
            printf("If you want to use this field in searching enter 1 only.\n\n\n");
            return;
        }
    }
    printf("3-Date of birth: \n");
    flagDOB=scanf("%[^\n]",temp_str);
    getchar();
    if(flagDOB==1)
    {
        if(strcasecmp(temp_str,"1")!=0)
        {
            printf("Error.\nInvalid input.\n");
            printf("If you want to use this field in searching enter 1 only.\n\n\n");
            return;
        }
    }
    printf("4-Address: \n");
    flagAdd=scanf("%[^\n]",temp_str);
    getchar();
    if(flagAdd==1)
    {
        if(strcasecmp(temp_str,"1")!=0)
        {
            printf("Error.\nInvalid input.\n");
            printf("If you want to use this field in searching enter 1 only.\n\n\n");
            return;
        }
    }
    printf("5-Email: \n");
    flagE=scanf("%[^\n]",temp_str);
    getchar();
    if(flagE==1)
    {
        if(strcasecmp(temp_str,"1")!=0)
        {
            printf("Error.\nInvalid input.\n");
            printf("If you want to use this field in searching enter 1 only.\n\n\n");
            return;
        }
    }
    printf("6-Phone number: \n");
    flagP=scanf("%[^\n]",temp_str);
    getchar();
    if(flagP==1)
    {
        if(strcasecmp(temp_str,"1")!=0)
        {
            printf("Error.\nInvalid input.\n");
            printf("If you want to use this field in searching enter 1 only.\n\n\n");
            return;
        }
    }
    system("cls");
    if(flagF==1)
    {
        printf("Enter first name of the contact: \n");
        scanf("%[^\n]",R.firstname);
        getchar();
        if(validst(R.firstname))
        {
            for(i=0; i<count; i++)
            {
                if(strcasecmp(R.firstname,ar[i].firstname)==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                printf("This first name does not exist it contacts.\n\n\n");
                return;
            }
        }
        else
        {
            printf("Error.\nEnter characters only.\n\n\n");
            return;
        }
    }
    flag=0;
    if(flagL==1)
    {
        printf("Enter last name of this contact: \n");
        scanf("%[^\n]",R.lastname);
        getchar();
        if(validst(R.lastname))
        {
            for(i=0; i<count; i++)
            {
                if(strcasecmp(R.lastname,ar[i].lastname)==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                printf("This last name does not exist it contacts.\n\n\n");
                return;
            }
        }
        else
        {
            printf("Error.\nEnter characters only.\n\n\n");
            return;
        }
    }
    flag=0;
    if(flagDOB==1)
    {
        printf("Date of birth of this contact: \n");
        printf("Enter day of birth: \n");
        scanf("%[^\n]",R.DOB.day);
        getchar();
        if(validI(R.DOB.day))
        {
            if(atoi(R.DOB.day)>31 || atoi(R.DOB.day)<=0)
            {
                printf("Error.\nInvalid Input.\n");
                return;
            }
        }
        else
        {
            printf("Error.\nInvalid input.\n");
            return;
        }
        printf("Enter month of birth: \n");
        scanf("%[^\n]",R.DOB.month);
        getchar();
        if(validI(R.DOB.month))
        {
            if(atoi(R.DOB.month)>12 || atoi(R.DOB.month)<=0)
            {
                printf("Error.\nInvalid Input.\n\n");
                return;
            }
            if(atoi(R.DOB.month)==2)
            {
                if(atoi(R.DOB.day)>28)
                {
                    printf("Error.\nInvalid input.\nThis month has only 28 days.\n\n");
                    return;
                }

            }
            if(atoi(R.DOB.month)==4 || atoi(R.DOB.month)==6 || atoi(R.DOB.month)==9 || atoi(R.DOB.month)==11)
            {
                if(atoi(R.DOB.day)>30)
                {
                    printf("Error.\nInvalid input.\nThis month has only 30 days.\n\n");
                    return;
                }
            }
        }
        else
        {
            printf("Error.\nInvalid input.\n");
            return;
        }
        printf("Enter year of birth: \n");
        scanf("%[^\n]",R.DOB.year);
        getchar();
        if(validI(R.DOB.year))
        {
            if(atoi(R.DOB.year)>=9999 || atoi(R.DOB.year)<=1900)
            {
                printf("Error.\nInvalid input.\n");
                return;
            }
        }
        else
        {
            printf("Error.\nInvalid input.\n");
            printf("Enter numbers only.\n\n\n");
            return;
        }
        for(i=0; i<count; i++)
        {
            if(atoi(R.DOB.day)==atoi(ar[i].DOB.day) && atoi(R.DOB.month)==atoi(ar[i].DOB.month) && atoi(R.DOB.year)==atoi(ar[i].DOB.year))
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("This date of birth does not exist in contacts.\n\n\n");
            return;
        }

    }
    flag=0;
    if(flagAdd==1)
    {
        printf("Enter address of this contact: \n");
        gets(R.address);
        for(i=0; i<count; i++)
        {
            if(strcasecmp(R.address,ar[i].address)==0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0)
        {
            printf("This address does not exist in contacts.\n\n\n");
            return;
        }
    }
    flag=0;
    if(flagE==1)
    {
        printf("Enter this contact's email: \n");
        scanf("%[^\n]",R.email);
        getchar();
        if(validemail(R.email))
        {
            for(i=0; i<count; i++)
            {
                if(strcasecmp(R.email,ar[i].email))
                {
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                printf("This email does not exist in contacts.\n\n\n");
                return;
            }
        }
        else
        {
            printf("Error.\nInvalid email.\n\n\n");
            return;
        }
    }
    flag=0;
    if(flagP==1)
    {
        printf("Enter this contact's phone number: \n");
        scanf("%[^\n]",R.phonenumber);
        getchar();
        if(validI(R.phonenumber))
        {
            if(validPN(R.phonenumber))
            {
                for(i=0; i<count; i++)
                {
                    if(atoi(R.phonenumber)==atoi(ar[i].phonenumber))
                    {
                        flag=1;
                        break;
                    }
                }
                if(flag==0)
                {
                    printf("This phone number does not exist in contacts.\n\n\n");
                    return;
                }
            }
            else
            {
                printf("Error.\nInvalid phone number.\n\n\n");
                return;
            }
        }
        else
        {
            printf("Error.\nInvalid input.\n");
            return;
        }

    }
    system("cls");
    for(i=0; i<count; i++)
    {

        if(flagF==1)
        {
            if(strcasecmp(R.firstname,ar[i].firstname)==0)
            {
                counter++;
            }
        }
        if(flagL==1)
        {
            if(strcasecmp(R.lastname,ar[i].lastname)==0)
            {
                counter++;
            }
        }
        if(flagDOB==1)
        {
            if(atoi(R.DOB.day)==atoi(ar[i].DOB.day) && atoi(R.DOB.month)==atoi(ar[i].DOB.month) && atoi(R.DOB.year)==atoi(ar[i].DOB.year))
            {
                counter++;
            }
        }
        if(flagAdd==1)
        {
            if(strcasecmp(R.address,ar[i].address)==0)
            {
                counter++;
            }
        }
        if(flagE==1)
        {
            if(strcasecmp(R.email,ar[i].email)==0)
            {
                counter++;
            }
        }
        if(flagP==1)
        {
            if(atoi(R.phonenumber)==atoi(ar[i].phonenumber))
            {
                counter++;
            }
        }
        if(counter==(flagAdd+flagDOB+flagE+flagF+flagL+flagP))
        {
            list[list_count]=ar+i;
            list_count++;
        }
        counter=0;
    }
    printf("\nSearch Result: \n\n");
    if(list_count==0)
    {
        printf("No search match.\n\n");
        return;
    }
    for(i=0; i<list_count; i++)
    {
        printf("First name: %s\nLast name: %s\n",list[i]->firstname,list[i]->lastname);
        printf("Date of birth: %s-%s-%s\n",list[i]->DOB.day,list[i]->DOB.month,list[i]->DOB.year);
        printf("Address: %s\nEmail: %s\nPhone number: %s\n",list[i]->address,list[i]->email,list[i]->phonenumber);
        printf("\n");
    }
    printf("After seeing every matching contact please enter the email of the contact you want to modify: \n");
    scanf("%[^\n]",Y.email);
    getchar();
    if(validemail(Y.email))
    {
        for(i=0; i<list_count; i++)
        {
            if(strcasecmp(Y.email,list[i]->email)==0)
            {
                while(1)
                {
                    printf("\n\nMODIFY MENU: \n");
                    printf("Choose what you want to modify about this contact: \n");
                    printf("1-first name.\n");
                    printf("2-last name.\n");
                    printf("3-Date of birth.\n");
                    printf("4-Address. \n");
                    printf("5-Email.\n");
                    printf("6-Phone number.\n");
                    printf("7-Quit.\n");
                    printf("Choice: \n");
                    scanf("%d",&m);
                    getchar();
                    switch(m)
                    {
                    case 1:
                        printf("Enter new first name: \n");
                        scanf("%[^\n]",list[i]->firstname);
                        getchar();
                        if(validst(list[i]->firstname)==0)
                        {
                            printf("\n\nError.\nEnter characters only.\n");
                        }
                        else
                        {
                            printf("\nFirst name has been modified.\n");
                        }
                        break;
                    case 2:
                        printf("Enter new last name: \n");
                        scanf("%[^\n]",list[i]->lastname);
                        getchar();
                        if(validst(list[i]->lastname)==0)
                        {
                            printf("\n\nError.\nEnter characters only.\n");
                        }
                        else
                        {
                            printf("\nLast name has been modified.\n");
                        }
                        break;
                    case 3:
                        printf("Date of birth: \n");
                        printf("Enter new day of birth in numbers: \n");
                        scanf("%[^\n]",list[i]->DOB.day);
                        getchar();
                        if(validI(list[i]->DOB.day))
                        {
                            if(atoi(list[i]->DOB.day)>31 || atoi(list[i]->DOB.day)<=0)
                            {
                                printf("Error.\nInvalid Input.\n");
                                break;
                            }
                        }
                        else
                        {
                            printf("Error.\nInvalid input.\n");
                            break;
                        }
                        printf("Enter new month of birth in numbers: \n");
                        scanf("%[^\n]",list[i]->DOB.month);
                        getchar();
                        if(validI(list[i]->DOB.month))
                        {
                            if(atoi(list[i]->DOB.month)>12 || atoi(list[i]->DOB.month)<=0)
                            {
                                printf("Error.\nInvalid Input.\n\n");
                                break;
                            }
                            if(atoi(list[i]->DOB.month)==2)
                            {
                                if(atoi(list[i]->DOB.day)>28)
                                {
                                    printf("Error.\nInvalid input.\nThis month has only 28 days.\n\n");
                                    break;
                                }

                            }
                            if(atoi(list[i]->DOB.month)==4 || atoi(list[i]->DOB.month)==6 || atoi(list[i]->DOB.month)==9 || atoi(list[i]->DOB.month)==11)
                            {
                                if(atoi(list[i]->DOB.day)>30)
                                {
                                    printf("Error.\nInvalid input.\nThis month has only 30 days.\n\n");
                                    break;
                                }
                            }
                        }
                        else
                        {
                            printf("Error.\nInvalid input.\nEnter numbers only.\n");
                            break;
                        }
                        printf("Enter new year of birth: \n");
                        scanf("%[^\n]",list[i]->DOB.year);
                        getchar();
                        if(validI(list[i]->DOB.year))
                        {
                            if(atoi(list[i]->DOB.year)>=9999 || atoi(list[i]->DOB.year)<=1900)
                            {
                                printf("Error.\nInvalid input.\n");
                                break;
                            }
                        }
                        else
                        {
                            printf("Error.\nInvalid input.\n");
                            printf("Enter numbers only.\n\n\n");
                            break;
                        }
                        printf("Contacts's date of birth has been modified.\n");
                        break;
                    case 4:
                        printf("Enter new address: \n");
                        gets(list[i]->address);
                        printf("\nAddress has been modified.\n");
                        break;
                    case 5:
                        printf("Enter new email: \n");
                        scanf("%[^\n]",list[i]->email);
                        getchar();
                        if(validemail(list[i]->email)==0)
                        {
                            printf("Error.\nInvalid email.\n\n");
                            break;
                        }
                        else
                        {
                            printf("Email has been modified.\n");
                        }
                        break;
                    case 6:
                        printf("Enter new phone number: \n");
                        scanf("%[^\n]",list[i]->phonenumber);
                        getchar();
                        if(validI(list[i]->phonenumber))
                        {
                            if(validPN(list[i]->phonenumber)==0)
                            {
                                printf("Error.\nInvalid phone number.\n\n\n");
                                break;
                            }
                            else
                            {
                                printf("\nPhone number has been modified.\n");
                            }
                        }
                        else
                        {
                            printf("Error.\nInvalid input.\n\n");
                            break;
                        }
                        break;
                    case 7:
                        main();
                        break;
                    default:
                        printf("Error, enter numbers from 1-6.\n");
                        break;

                    }
                }
            }
            else
            {
                printf("Error.\n The email you entered doesn't exist in contacts\n\n\n");
                return;
            }
        }
    }
    else
    {
        printf("Error.\nInvalid email\n\n\n");
        return;
    }

}
