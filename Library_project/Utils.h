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