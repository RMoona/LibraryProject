#pragma once

#include <fstream>
#include <string>
#include "LibraryEntities.h"

//global variables
extern Author authors[MAX_AUTHORS];
extern int authorCount;
extern Book books[MAX_BOOKS];
extern int bookCount;
extern Loan loans[MAX_LOANS];
extern int loanCount;
extern Reader readers[MAX_READERS];
extern int readerCount;

void addAuthor();
void addBook();
void addReader();
void addLoan();
void saveDataToFile();
void readDataFromFile();
void displayAllData();
void editAuthor(int authorIDToEdit);
void editBook(string ISBNToEdit);
void editReader(int readerIDToEdit);
void editLoan(int loanIDToEdit);
void searchLoans(Loan loans[], int loanCount, Book books[], int bookCount);
void searchLoanByLoanID(Loan loans[], int loanCount); //search by int
void searchLoanByISBN(Loan loans[], int loanCount); //search by string
void searchLoanByBorrowDate(Loan loans[], int loanCount);
void searchLoanByReturnStatus(Loan loans[], int loanCount);
void searchLoanByAuthor(Loan loans[], int loanCount, Book books[], int bookCount);