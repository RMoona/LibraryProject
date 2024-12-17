#pragma once

#include <string>

using namespace std;

const int MAX_AUTHORS = 100;
const int MAX_BOOKS = 100;
const int MAX_LOANS = 100;
const int MAX_READERS = 100;

struct Author
{
	int authorID;
	string firstName;
	string lastName;
};

struct Book
{
	string ISBN;
	string title;
	Author author;
};

struct Reader
{
	int readerID;
	string firstName;
	string lastName;
	string contactEmail;
	string phoneNumber;
	int activeLoans;
};

struct Loan
{
	int loanID;
	int readerID;
	string ISBN;
	int borrowDate;
	int dueDate;
	bool isReturned;
};