#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#include "structures.h"
#include "prototype.h"
#pragma pack(1)
int main()
{
    while(!0)
    {
        int choice=0,m;
        printf("\t\t\t\t\t\tWELCOME TO PHONEBOOK!\t\t\t\t\t\t\t\n");
        //printf("Press any key to continue: \n");
        //getch();
        printf("\nMENU: \n");
        printf("What action do you want to do?\n");
        printf("1-Load contacts.\n");
        printf("2-Print contacts (Unsorted).\n");
        printf("3-Search for a contact.(MULTI SEARCH)\n");
        printf("4-Add a contact.\n");
        printf("5-Delete a contact.\n");
        printf("6-Modify a contact. (Using MULTI SEARCH)\n");
        printf("7-Print Contacts (Sorted).\n");
        printf("8-Search using last name only.\n");
        printf("9-Modify contact (Using search by last name only).\n");
        printf("10-Save.\n");
        printf("11-Quit.\n\n\n");
        printf("Choice: \n");
        scanf("%d",&choice);
        getchar();

        switch(choice)
        {
        case 1:
            system("cls");
            load();
            printf("Contacts have been loaded successfully.\n\n\n");
            break;
        case 2:
            system("cls");
            print_contacts();
            break;
        case 3:
            system("cls");
            search_advanced();
            break;
        case 4:
            system("cls");
            add();
            break;
        case 5:
            system("cls");
            delete_contact();
            break;
        case 6:
            system("cls");
            modify_advanced();
            break;
        case 7:
            system("cls");
            print_sorted();
            break;
        case 8:
            system("cls");
            search_Normal();
            break;
        case 9:
            system("cls");
            modify_Normal();
            break;
        case 10:
            system("cls");
            save();
            break;
        case 11:
            system("cls");
            printf("Make sure to save your work before quitting or all your changes will be discarded!\n\n");
            printf("Enter 1 if you want to save your changes and zero if not.\n");
            scanf("%d",&m);
            if(m==1)
            {
                save();

            }
            else
            {
                printf("Thank you for using phone book!\n");
                quitproject();
            }
            break;

        default:
            main();
            break;
        }
    }
}
