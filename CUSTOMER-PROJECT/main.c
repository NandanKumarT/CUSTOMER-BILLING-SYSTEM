#include<stdio.h>
#include "customer.h"

int main()
{
    int choice;
    Customer customer;
    initialize(&customer); // Initialize the Invoices
     do
    {
        printf(YELLOW"\n========>WELCOME TO BILLING SYSTEM<========\n"RESET);
        printf(CYAN"\n1.Generate Invoice\n2.Show Invoice \n3.Searcch Invoice\n4.Back\n"RESET);
        printf(YELLOW"\n=========================================\n"RESET);
        printf(GREEN"Enter Your Choice: "RESET);
        scanf("%d",&choice);
        switch (choice)
        {
            case 1:
                 Generate_Invoice(&customer);
                 break;
            case 2:
                 Show_Invoice(&customer);
                 break;
            case 3:
                 Search_Invoice(&customer);
                 break;
            default:
                 printf(RED"Bye Bye\nDevoloped by Nandan Kumar T\n"RESET);
                 break;
        }
    }while(choice!=4);
}
