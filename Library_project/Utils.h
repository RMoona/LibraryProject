#pragma once

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

void checkAndCreateFiles();
void addAuthor();
void addBook();
void addReader();
void addLoan();
void calculateActiveLoans(Loan loans[], int loanCount, Reader readers[], int readerCount);
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
void searchLoanByLoanID(Loan loans[], int loanCount); //search by int
void searchLoanByISBN(Loan loans[], int loanCount); //search by string
void searchLoanByBorrowDate(Loan loans[], int loanCount);
void searchLoanByReturnStatus(Loan loans[], int loanCount);
void searchLoanByAuthor(Loan loans[], int loanCount, Book books[], int bookCount);
void deleteAuthor(int authorID);
void deleteBook(const string& ISBN);
void deleteReader(int readerID);
void deleteLoan(int loanID);
void sortAuthorsByLastName(Author authors[], int authorCount);
void sortReadersByReaderID(Reader readers[], int readerCount);
void sortBooksByAuthorLastName(Book books[], int bookCount); //sorting by complex structure
int calculateTotalActiveLoans(Reader readers[], int readerCount);