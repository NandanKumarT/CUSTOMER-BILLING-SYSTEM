#ifndef CUSTOMER_H
#define CUSTOMER_H
#define RED     "\033[1;31m"
#define YELLOW  "\033[4;33m"
#define YELLOW1 "\033[1;33m"
#define GREEN   "\033[1;32m"
#define CYAN    "\033[1;36m"
#define MAGENTA "\033[1;35m"
#define RESET   "\033[0m"

typedef struct{
    int Quantity;
    float price;
    char productname[50];
}Product_Details;

typedef struct{
    char name[50];
    char phone[20];
    char address[100];
    int noproduct;
    Product_Details product_deatail[100];
    int CustomerID;
}Cutomer_Details;

typedef struct{
    int NumberofInvoice;
    Cutomer_Details customer_details[100];
}Customer;

void Generate_Invoice(Customer *customer);
void Show_Invoice(Customer *customer);
void Search_Invoice(Customer *customer);
void initialize(Customer *customer);
void loadInvoiceFromFile(Customer *customer);

#endif
