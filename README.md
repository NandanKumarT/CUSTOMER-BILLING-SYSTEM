CUSTOMER BILLING SYSTEM
A simple console-based billing system built in C to manage customer invoices and store them in a binary file (BILL.dat).

Features:

Add new customer bills

View, search, and manage invoice records

Automatically save data to BILL.dat

Simple text-based menu interface

Tech Stack:

Language: C

Storage: Binary file (BILL.dat)

Platform: Windows / Linux

File Structure:
CUSTOMER-BILLING-SYSTEM/
│
├── CUSTOMER-PROJECT/
│ ├── BILL.dat → Stores all invoice records
│ ├── main.c → Main source code
│ ├── customer.h → Header file for customer data structures
│ ├── functions.c → Supporting functions
│ └── ... → Additional modules
│
└── README.md

Setup and Usage:

Clone the repository
git clone https://github.com/NandanKumarT/CUSTOMER-BILLING-SYSTEM.git

Navigate to project directory
cd CUSTOMER-BILLING-SYSTEM/CUSTOMER-PROJECT

Compile the program
gcc main.c -o billing_system

Run the program
./billing_system

Data File:
All bills are stored in BILL.dat.
The file is automatically created if not present.

Author:
Nandan Kumar T
GitHub: https://github.com/NandanKumarT
Project: https://github.com/NandanKumarT/CUSTOMER-BILLING-SYSTEM
