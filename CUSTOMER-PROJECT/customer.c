#include <stdio.h>
#include <stdlib.h>
#include "customer.h"
// INITIALIZE CONTACT BOOK
void initialize(Customer *customer) {
    customer->NumberofInvoice=0;
    loadInvoiceFromFile(customer);  
}

void Generate_Invoice(Customer *customer)
{
    system("clear");
    int i=0,j;
    char choice;
    printf("Enter the customer name: ");
    scanf("%s",customer->customer_details[customer->NumberofInvoice].name);
    customer->customer_details[customer->NumberofInvoice].CustomerID = 101 + customer->NumberofInvoice;
    printf("Enter the customer Phone Number: ");
    scanf("%s",customer->customer_details[customer->NumberofInvoice].phone);
    printf("Enter the customer address: ");
    scanf("\n%[^\n]",customer->customer_details[customer->NumberofInvoice].address);
    printf("Enter the Number of Products: ");
    scanf("%d",&customer->customer_details[customer->NumberofInvoice].noproduct);
    if(customer->customer_details[customer->NumberofInvoice].noproduct==0){
        printf(RED"\nEnter the Number of Product that is > 0\n"RESET);
        return;
    }
    do{
        while(i < customer->customer_details[customer->NumberofInvoice].noproduct){
            printf("Enter the Product Name%d: ",i+1);
            scanf("\n%[^\n]",customer->customer_details[customer->NumberofInvoice].product_deatail[i].productname);
            printf("Enter the Quantity of the %s :",customer->customer_details[customer->NumberofInvoice].product_deatail[i].productname);
            scanf("%d",&customer->customer_details[customer->NumberofInvoice].product_deatail[i].Quantity);
            printf("Enter the Price of the %s (per quantity) :",customer->customer_details[customer->NumberofInvoice].product_deatail[i].productname);
            scanf("%f",&customer->customer_details[customer->NumberofInvoice].product_deatail[i].price);
            i++;
        }

        j=0;
        printf(YELLOW1"\n=============================CUSTOMER DETAILS==============================\n"RESET);
        printf(GREEN"Date;-19/10/2025\t\t\t\t\tDay:-Sunday\n\n"RESET);
        printf(CYAN"Customer Name:%-20s \tCustomer ID:-%-20d\n\nCustomer Phone Number:-%-10s \tCustomer Address:-%s\n",customer->customer_details[customer->NumberofInvoice].name, customer->customer_details[customer->NumberofInvoice].CustomerID,customer->customer_details[customer->NumberofInvoice].phone,customer->customer_details[customer->NumberofInvoice].address);
        printf(YELLOW1"\n=============================INVOICE DETAILS================================\n"RESET);
        printf(CYAN"%-10s %-30s %-10s %-10s %-10s\n","S.No","Product","Quantity","Price","Total Price"RESET);
        printf(YELLOW1"----------------------------------------------------------------------------\n\n"RESET);

        float sum=0;
        while(j<customer->customer_details[customer->NumberofInvoice].noproduct){
            float t_price= (customer->customer_details[customer->NumberofInvoice].product_deatail[j].Quantity * customer->customer_details[customer->NumberofInvoice].product_deatail[j].price);
            printf(GREEN"%-10d %-30s %-10d %-10.2f %-10.2f\n"RESET,j+1,customer->customer_details[customer->NumberofInvoice].product_deatail[j].productname,customer->customer_details[customer->NumberofInvoice].product_deatail[j].Quantity,customer->customer_details[customer->NumberofInvoice].product_deatail[j].price,t_price);
            sum+=t_price;
            j++;
        }        
        printf(YELLOW1"----------------------------------------------------------------------------\n\n"RESET);
        printf(MAGENTA"%-15s:-\t\t\t\t\t\t%-10.2f\n"RESET,"Sub Total",sum);
        float discount=(sum*10/100);
        printf(MAGENTA"%-15s:-\t\t\t\t\t\t%-10.2f\n"RESET,"Discount(10%)",discount);
        float net=sum-(sum*10/100);
        printf(MAGENTA"%-15s:-\t\t\t\t\t\t%-10.2f\n"RESET,"Net Total",net);
        float cgst=(sum*9/100);
        float sgst=(sum*9/100);
        printf(MAGENTA"%-15s:-\t\t\t\t\t\t%-10.2f\n"RESET,"CGST @9%",cgst);
        printf(MAGENTA"%-15s:-\t\t\t\t\t\t%-10.2f\n"RESET,"SGST @9%",sgst);
        printf(YELLOW1"----------------------------------------------------------------------------\n\n"RESET);
        printf(MAGENTA"%-15s:-\t\t\t\t\t\t%-20.2f\n"RESET,"Grand Total",(sum-discount+cgst+sgst));
        printf(YELLOW1"----------------------------------------------------------------------------\n\n"RESET);
        printf(RED"%50s \n%45s","Thank You For Shopping With Us","Visit Again\n"RESET);
        printf(YELLOW"----------------------------------------------------------------------------\n\n"RESET);
        printf("Do you want add more products(Y/N): ");
        scanf(" %c",&choice);
        if(choice=='Y'||choice=='y'){
            int add;
            printf("Enter the Number Product to Add ");
            scanf("%d",&add);
            customer->customer_details[customer->NumberofInvoice].noproduct += add;
        }else if(choice=='N'||choice=='n'){
            printf("Do you want save this invoice (y/n):");
            scanf(" %c",&choice);
            if (choice == 'Y' || choice == 'y') {
               FILE *fptr = fopen("BILL.dat", "wb");  // write in binary mode (overwrite old)
               if (fptr == NULL) {
                printf(RED "Error: Cannot open BILL.dat for writing!\n" RESET);
                return;
            }
            customer->NumberofInvoice++;
            fwrite(&customer->NumberofInvoice, sizeof(int), 1, fptr);
            fwrite(customer->customer_details, sizeof(customer->customer_details[0]),customer->NumberofInvoice, fptr);
            fclose(fptr);
            system("clear");
            printf(GREEN "Invoice saved successfully!\n" RESET);
            break;
                }
            } 
        }while(choice=='Y'||choice=='y');

    }

void Show_Invoice(Customer *customer)
{
    system("clear");
    if(customer->NumberofInvoice==100){
        printf(RED"\nCan't generate Storage Full\n"RESET);
        return;
    }
    if(customer->NumberofInvoice==0){
        printf(RED"\nNo previous invoice records found.\n"RESET);
        return;
    }
    printf(CYAN"\nPrevios Invoices are: \n\n"RESET);
    printf(GREEN "Total Number of Invoices are %d \n" RESET, customer->NumberofInvoice);

    // Display all invoices
    for (int i = 0; i < customer->NumberofInvoice; i++) {
        printf(YELLOW1 "\n=============================CUSTOMER DETAILS==============================\n" RESET);
        printf(GREEN "Date: 19/10/2025\t\t\t\t\t\tDay: Sunday\n\n" RESET);
        printf(CYAN "Customer Name: %-20s \tCustomer ID: %-20d\n\n"
                    "Customer Phone Number: %-10s \tCustomer Address: %s\n",
               customer->customer_details[i].name,
               customer->customer_details[i].CustomerID,
               customer->customer_details[i].phone,
               customer->customer_details[i].address);

        printf(YELLOW1 "\n=============================INVOICE DETAILS================================\n" RESET);
        printf(CYAN "%-10s %-30s %-10s %-10s %-10s\n", "S.No", "Product", "Quantity", "Price", "Total Price" RESET);
        printf(YELLOW1 "----------------------------------------------------------------------------\n\n" RESET);

        float sum = 0;
        for (int j = 0; j < customer->customer_details[i].noproduct; j++) {
            float t_price = customer->customer_details[i].product_deatail[j].Quantity *
                            customer->customer_details[i].product_deatail[j].price;
            printf(GREEN "%-10d %-30s %-10d %-10.2f %-10.2f\n" RESET,
                   j + 1,
                   customer->customer_details[i].product_deatail[j].productname,
                   customer->customer_details[i].product_deatail[j].Quantity,
                   customer->customer_details[i].product_deatail[j].price,
                   t_price);
            sum += t_price;
        }

        printf(YELLOW1 "----------------------------------------------------------------------------\n\n" RESET);
        float discount = sum * 0.10f;
        float cgst = sum * 0.09f;
        float sgst = sum * 0.09f;
        float grandTotal = sum - discount + cgst + sgst;

        printf(MAGENTA "%-15s:-\t\t\t\t\t\t%-10.2f\n" RESET, "Sub Total", sum);
        printf(MAGENTA "%-15s:-\t\t\t\t\t\t%-10.2f\n" RESET, "Discount(10%)", discount);
        printf(MAGENTA "%-15s:-\t\t\t\t\t\t%-10.2f\n" RESET, "CGST @9%", cgst);
        printf(MAGENTA "%-15s:-\t\t\t\t\t\t%-10.2f\n" RESET, "SGST @9%", sgst);
        printf(YELLOW1 "----------------------------------------------------------------------------\n\n" RESET);
        printf(MAGENTA "%-15s:-\t\t\t\t\t\t%-20.2f\n" RESET, "Grand Total", grandTotal);
        printf(YELLOW1 "----------------------------------------------------------------------------\n\n" RESET);
        printf(RED"%50s \n%45s","Thank You For Shopping With Us","Visit Again\n"RESET);
        printf(YELLOW "----------------------------------------------------------------------------\n\n" RESET);
    }

    //fclose(fptr);
}

void Search_Invoice(Customer *customer)
{
    system("clear");
    int ID,found=0;
    printf(GREEN"Enter customer ID:"RESET);
    scanf("%d",&ID);
    for (int i = 0; i < customer->NumberofInvoice; i++) {
        if(customer->customer_details[i].CustomerID==ID){
            printf(CYAN"\ncustomer details found!\n"RESET);
            found=1;
            printf(YELLOW1"\n=============================CUSTOMER DETAILS==============================\n" RESET);
            printf(GREEN "Date: 19/10/2025\t\t\t\t\t\tDay: Sunday\n\n" RESET);
            printf(CYAN "Customer Name: %-20s \tCustomer ID: %-20d\n\n""Customer Phone Number: %-10s \tCustomer Address: %s\n",
               customer->customer_details[i].name,
               customer->customer_details[i].CustomerID,
               customer->customer_details[i].phone,
               customer->customer_details[i].address);

            printf(YELLOW1 "\n=============================INVOICE DETAILS================================\n" RESET);
            printf(CYAN "%-10s %-30s %-10s %-10s %-10s\n", "S.No", "Product", "Quantity", "Price", "Total Price" RESET);
            printf(YELLOW1 "----------------------------------------------------------------------------\n\n" RESET);

            float sum = 0;
            for (int j = 0; j < customer->customer_details[i].noproduct; j++) {
                float t_price = customer->customer_details[i].product_deatail[j].Quantity *
                customer->customer_details[i].product_deatail[j].price;
                printf(GREEN "%-10d %-30s %-10d %-10.2f %-10.2f\n" RESET,
                   j + 1,
                   customer->customer_details[i].product_deatail[j].productname,
                   customer->customer_details[i].product_deatail[j].Quantity,
                   customer->customer_details[i].product_deatail[j].price,
                   t_price);
                sum += t_price;
            }

            printf(YELLOW1 "----------------------------------------------------------------------------\n\n" RESET);
            float discount = sum * 0.10f;
            float cgst = sum * 0.09f;
            float sgst = sum * 0.09f;
            float grandTotal = sum - discount + cgst + sgst;

            printf(MAGENTA "%-15s:-\t\t\t\t\t\t%-10.2f\n" RESET, "Sub Total", sum);
            printf(MAGENTA "%-15s:-\t\t\t\t\t\t%-10.2f\n" RESET, "Discount(10%)", discount);
            printf(MAGENTA "%-15s:-\t\t\t\t\t\t%-10.2f\n" RESET, "CGST @9%", cgst);
            printf(MAGENTA "%-15s:-\t\t\t\t\t\t%-10.2f\n" RESET, "SGST @9%", sgst);
            printf(YELLOW1 "----------------------------------------------------------------------------\n\n" RESET);
            printf(MAGENTA "%-15s:-\t\t\t\t\t\t%-20.2f\n" RESET, "Grand Total", grandTotal);
            printf(YELLOW1 "----------------------------------------------------------------------------\n\n" RESET);
            printf(RED"%50s \n%45s","Thank You For Shopping With Us","Visit Again\n"RESET);
            printf(YELLOW "----------------------------------------------------------------------------\n\n" RESET);
            break;
        }
    }
    if(found==0){
        printf(RED"customer details is not found!"RESET);
    }
}

void loadInvoiceFromFile(Customer *customer)
{
    FILE *fptr = fopen("BILL.dat", "rb");  // open in binary read mode
    if (fptr == NULL) {
        printf(YELLOW "No previous invoice records found.\n" RESET);
        return;
    }
    // First, read the total number of invoices stored
    fread(&customer->NumberofInvoice, sizeof(int), 1, fptr);

    // Then, read exactly that many invoices
    fread(customer->customer_details, sizeof(customer->customer_details[0]),
          customer->NumberofInvoice, fptr);

    fclose(fptr);
    //printf(GREEN "%d invoice(s) loaded successfully!\n" RESET, customer->NumberofInvoice);
}
