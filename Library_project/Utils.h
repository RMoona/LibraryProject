#pragma once

#include "LibraryEntities.h"

extern Author authors[MAX_AUTHORS];
extern int authorCount;
extern Book books[MAX_BOOKS];
extern int bookCount;
extern Loan loans[MAX_LOANS];
extern int loanCount;
extern Reader readers[MAX_READERS];
extern int readerCount;

void checkAndCreateFiles();
void addAuthor();
void addBook();
void addReader();
void addLoan();
void calculateActiveLoans();
void saveDataToFile();
void readDataFromFile();
void displayAuthors();
void displayBooks();
void displayLoans();
void displayReaders();
void displayAllData();
void editAuthor(int authorIDToEdit);
void editBook(string ISBNToEdit);
void editReader(int readerIDToEdit);
void editLoan(int loanIDToEdit);
void searchLoanByLoanID();
void searchLoanByISBN();
void searchLoanByBorrowDate();
void searchLoanByReturnStatus();
void searchLoanByAuthor();
void deleteAuthor(int authorID);
void deleteBook(const string& ISBN);
void deleteReader(int readerID);
void deleteLoan(int loanID);
void sortAuthorsByLastName();
void sortReadersByReaderID();
void sortBooksByAuthorLastName(); //sorting by complex structure
int calculateTotalActiveLoans();