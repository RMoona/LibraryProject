#include "LibraryEntities.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;

// Arrays and counters
Author authors[MAX_AUTHORS];
int authorCount = 0;

Book books[MAX_BOOKS];
int bookCount = 0;

Reader readers[MAX_READERS];
int readerCount = 0;

Loan loans[MAX_LOANS];
int loanCount = 0;

void checkAndCreateFiles()
{
	ifstream authorsFile("authors.txt");
	if (!authorsFile)
	{
		ofstream createFile("authors.txt");
		if (!createFile.is_open())
		{
			cerr << "Failed to create authors.txt\n";
		}
	}

	ifstream booksFile("books.txt");
	if (!booksFile)
	{
		ofstream createFile("books.txt");
		if (!createFile.is_open())
		{
			cerr << "Failed to create books.txt\n";
		}
	}

	ifstream readersFile("readers.txt");
	if (!readersFile)
	{
		ofstream createFile("readers.txt");
		if (!createFile.is_open())
		{
			cerr << "Failed to create readers.txt\n";
		}
	}

	ifstream loansFile("loans.txt");
	if (!loansFile)
	{
		ofstream createFile("loans.txt");
		if (!createFile.is_open())
		{
			cerr << "Failed to create loans.txt\n";
		}
	}
}

void addAuthor()
{
	if (authorCount >= MAX_AUTHORS)
	{
		cerr << "Error: Maximum number of authors reached.\n";
		return;
	}
	Author newAuthor;

	while (true)
	{
		cout << "Enter author ID (only integers allowed): ";
		cin >> newAuthor.authorID;

		if (cin.fail())
		{
			cerr << "Invalid input. Please enter a valid integer.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			bool authorIdExists = false;
			for (int i = 0; i < authorCount; ++i)
			{
				if (authors[i].authorID == newAuthor.authorID)
				{
					authorIdExists = true;
					break;
				}
			}
			if (authorIdExists)
			{
				cerr << "Error: Author ID already exists. Please enter a unique ID.\n";
			}
			else
			{
				break;
			}
		}
	}
	cin.ignore();

	cout << "Enter author's First Name: ";
	cin >> newAuthor.firstName;
	cin.ignore();

	cout << "Enter author's Last Name: ";
	getline(cin, newAuthor.lastName);

	authors[authorCount++] = newAuthor;

	cout << "Author added successfully!\n";
}

void addBook()
{
	if (bookCount >= MAX_BOOKS)
	{
		cerr << "Error: Maximum number of books reached.\n";
		return;
	}

	cin.ignore();

	Book newBook;

	while (true)
	{
		cout << "Enter ISBN (13 characters): ";
		getline(cin, newBook.ISBN);

		if (newBook.ISBN.length() != 13)
		{
			cout << "Invalid ISBN. It must be 13 characters long.\n";
		}
		else
		{
			bool isbnExists = false;
			for (int i = 0; i < bookCount; ++i)
			{
				if (books[i].ISBN == newBook.ISBN)
				{
					isbnExists = true;
					break;
				}
			}
			if (isbnExists)
			{
				cerr << "Error: ISBN already exists. Please enter a unique ISBN.\n";
			}
			else
			{
				break;
			}
		}
	}

	cout << "Enter book title: ";
	getline(cin, newBook.title);

	while (true)
	{
		int authorID;
		bool validAuthorID = false;
		cout << "Enter author ID (integer only): ";
		cin >> authorID;

		if (cin.fail())
		{
			cerr << "Invalid input. Please enter a valid integer.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			validAuthorID = true;
		}

		if (validAuthorID)
		{
			bool authorFound = false;
			for (int i = 0; i < authorCount; i++)
			{
				if (authors[i].authorID == authorID)
				{
					newBook.author = authors[i];
					authorFound = true;
					break;
				}
			}

			if (!authorFound)
			{
				cout << "Author not found. Please add a new author.\n";

				if (authorCount >= MAX_AUTHORS)
				{
					cerr << "Error: Maximum number of authors reached.\n";
					return;
				}

				Author newAuthor;
				newAuthor.authorID = authorID;

				cin.ignore();
				cout << "Enter author's first name: ";
				getline(cin, newAuthor.firstName);

				cout << "Enter author's last name: ";
				getline(cin, newAuthor.lastName);

				authors[authorCount++] = newAuthor;

				newBook.author = newAuthor;
			}

			break;
		}
	}

	books[bookCount++] = newBook;
	cout << "Book added successfully!\n";
}

void addReader()
{
	if (readerCount >= MAX_READERS)
	{
		cerr << "Error: Maximum number of readers reached.\n";
		return;
	}

	Reader newReader;

	while (true)
	{
		cout << "Enter reader ID (only integers allowed): ";
		cin >> newReader.readerID;

		if (cin.fail())
		{
			cerr << "Invalid input. Please enter a valid integer.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			bool readerIdExists = false;
			for (int i = 0; i < readerCount; ++i)
			{
				if (readers[i].readerID == newReader.readerID)
				{
					readerIdExists = true;
					break;
				}
			}

			if (readerIdExists)
			{
				cerr << "Error: Reader ID already exists. Please enter a unique ID.\n";
			}
			else
			{
				break;
			}
		}
	}
	cin.ignore();

	cout << "Enter reader's first name: ";
	getline(cin, newReader.firstName);

	cout << "Enter reader's last name: ";
	getline(cin, newReader.lastName);

	cout << "Enter reader's e-mail: ";
	getline(cin, newReader.contactEmail);

	cout << "Enter reader's phone number: ";
	getline(cin, newReader.phoneNumber);

	newReader.activeLoans = 0;

	readers[readerCount++] = newReader;

	cout << "Reader added successfully!\n";
}

void calculateActiveLoans(Loan loans[], int loanCount, Reader readers[], int readerCount)
{
	for (int i = 0; i < readerCount; i++)
	{
		readers[i].activeLoans = 0;
	}
	for (int i = 0; i < loanCount; i++)
	{
		if (!loans[i].isReturned)
		{
			for (int j = 0; j < readerCount; j++)
			{
				if (readers[j].readerID == loans[i].readerID)
				{
					readers[j].activeLoans++;
					break;
				}
			}
		}
	}
}

void addLoan()
{
	if (loanCount >= MAX_LOANS)
	{
		cerr << "Error: Maximum number of loans reached.\n";
		return;
	}

	cin.ignore();

	Loan newLoan;

	while (true)
	{
		cout << "Enter loan ID (only integers allowed): ";
		cin >> newLoan.loanID;

		if (cin.fail())
		{
			cerr << "Invalid input. Please enter a valid integer.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			bool loanIdExists = false;
			for (int i = 0; i < loanCount; ++i)
			{
				if (loans[i].loanID == newLoan.loanID)
				{
					loanIdExists = true;
					break;
				}
			}

			if (loanIdExists)
			{
				cerr << "Error: Loan ID already exists. Please enter a unique ID.\n";
			}
			else
			{
				break;
			}
		}
	}
	cin.ignore();

	while (true)
	{
		cout << "Enter reader ID (only integers allowed): ";
		cin >> newLoan.readerID;

		if (cin.fail())
		{
			cerr << "Invalid input. Please enter a valid integer.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			bool readerFound = false;
			for (int i = 0; i < readerCount; i++)
			{
				if (readers[i].readerID == newLoan.readerID)
				{
					readerFound = true;
					break;
				}
			}

			if (!readerFound)
			{
				cout << "Reader with ID " << newLoan.readerID << " not found. Please add a new reader.\n";

				if (readerCount >= MAX_READERS)
				{
					cerr << "Error: Maximum number of readers reached.\n";
					return;
				}

				Reader newReader;
				newReader.readerID = newLoan.readerID;

				cin.ignore();
				cout << "Enter reader's first name: ";
				getline(cin, newReader.firstName);

				cout << "Enter reader's last name: ";
				getline(cin, newReader.lastName);

				cout << "Enter reader's contact email: ";
				getline(cin, newReader.contactEmail);

				cout << "Enter reader's phone number: ";
				getline(cin, newReader.phoneNumber);

				newReader.activeLoans = 0;

				readers[readerCount++] = newReader;

				cout << "Reader added successfully!\n";
			}
			break;
		}
	}

	cin.ignore();
	cout << "Enter ISBN: ";
	getline(cin, newLoan.ISBN);

	bool isAlreadyOnLoan = false;
	for (int i = 0; i < loanCount; i++)
	{
		if (loans[i].ISBN == newLoan.ISBN && !loans[i].isReturned)
		{
			isAlreadyOnLoan = true;
			break;
		}
	}

	if (isAlreadyOnLoan)
	{
		cerr << "Error: This book is already on loan and has not been returned. Please edit the loan or choose another ISBN.\n";
		return; // Exit if the book is already on loan
	}

	while (true)
	{
		cout << "Enter borrow date (only integers in format YYYYMMDD): ";
		cin >> newLoan.borrowDate;

		if (cin.fail())
		{
			cerr << "Invalid input. Please enter a valid integer.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			break;
		}
	}
	cin.ignore();

	while (true)
	{
		cout << "Enter the date when the book should be returned (only integers in format YYYYMMDD): ";
		cin >> newLoan.dueDate;

		if (cin.fail())
		{
			cerr << "Invalid input. Please enter a valid integer.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			break;
		}
	}
	cin.ignore();

	newLoan.isReturned = false;

	loans[loanCount++] = newLoan;

	calculateActiveLoans(loans, loanCount, readers, readerCount);

	cout << "Loan added successfully!\n";
}

void saveDataToFile()
{
	ofstream authorsFile("authors.txt", ios::trunc);
	if (!authorsFile.is_open())
	{
		cerr << "Failed to open authors file for writing.\n";
		return;
	}

	for (int i = 0; i < authorCount; i++)
	{
		authorsFile << authors[i].authorID << ";"
			<< authors[i].firstName << ";"
			<< authors[i].lastName << endl;
	}
	authorsFile.close();

	ofstream booksFile("books.txt", ios::trunc);
	if (!booksFile.is_open())
	{
		cerr << "Failed to open books file for writing.\n";
		return;
	}

	// Save books data including the authorID
	for (int i = 0; i < bookCount; i++)
	{
		booksFile << books[i].ISBN << ";"
			<< books[i].title << ";"
			<< books[i].author.authorID << endl;
	}
	booksFile.close();

	ofstream loansFile("loans.txt", ios::trunc);
	if (!loansFile.is_open())
	{
		cerr << "Failed to open loans file for writing.\n";
		return;
	}

	for (int i = 0; i < loanCount; i++)
	{
		loansFile << loans[i].loanID << ";"
			<< loans[i].readerID << ";"
			<< loans[i].ISBN << ";"
			<< loans[i].borrowDate << ";"
			<< loans[i].dueDate << ";"
			<< loans[i].isReturned << endl;
	}
	loansFile.close();

	ofstream readersFile("readers.txt", ios::trunc);
	if (!readersFile.is_open())
	{
		cerr << "Failed to open readers file for writing.\n";
		return;
	}

	for (int i = 0; i < readerCount; i++)
	{
		readersFile << readers[i].readerID << ";"
			<< readers[i].firstName << ";"
			<< readers[i].lastName << ";"
			<< readers[i].contactEmail << ";"
			<< readers[i].phoneNumber << ";"
			<< readers[i].activeLoans << endl;
	}
	readersFile.close();
}

void readDataFromFile()
{

	authorCount = 0;
	bookCount = 0;
	loanCount = 0;
	readerCount = 0;

	ifstream authorsFile("authors.txt");

	string line;

	while (getline(authorsFile, line))
	{
		stringstream ss(line);
		string temp;

		getline(ss, temp, ';');
		authors[authorCount].authorID = stoi(temp);
		getline(ss, authors[authorCount].firstName, ';');
		getline(ss, authors[authorCount].lastName, ';');
		authorCount++;

		if (authorCount == MAX_AUTHORS)
		{
			cout << "Max author count reached, only " << MAX_AUTHORS << " author entries allowed.\n";
			break;
		}
	}
	authorsFile.close();

	ifstream booksFile("books.txt");


	while (getline(booksFile, line))
	{
		stringstream ss(line);
		string temp;

		getline(ss, books[bookCount].ISBN, ';');
		getline(ss, books[bookCount].title, ';');

		getline(ss, temp, ';');
		int authorID = stoi(temp);

		for (int i = 0; i < authorCount; ++i)
		{
			if (authors[i].authorID == authorID)
			{
				books[bookCount].author = authors[i];
				break;
			}
		}

		bookCount++;
		if (bookCount == MAX_BOOKS)
		{
			cout << "Max book count reached, only " << MAX_BOOKS << " book entries allowed.\n";
			break;
		}
	}
	booksFile.close();

	ifstream loansFile("loans.txt");

	if (loansFile.is_open())
	{
		string line;
		while (getline(loansFile, line))
		{
			stringstream ss(line);
			string temp;

			getline(ss, temp, ';');
			loans[loanCount].loanID = stoi(temp);
			getline(ss, temp, ';');
			loans[loanCount].readerID = stoi(temp);
			getline(ss, loans[loanCount].ISBN, ';');
			getline(ss, temp, ';');
			loans[loanCount].borrowDate = stoi(temp);
			getline(ss, temp, ';');
			loans[loanCount].dueDate = stoi(temp);
			getline(ss, temp, ';');
			loans[loanCount].isReturned = (temp == "1");
			loanCount++;

			if (loanCount == MAX_LOANS)
			{
				cout << "Max loan count reached only " << MAX_LOANS << " loan entries allowed." << endl;
				break;
			}
		}

		loansFile.close();
	}

	ifstream readersFile("readers.txt");

	if (readersFile.is_open())
	{
		string line;
		while (getline(readersFile, line))
		{
			stringstream ss(line);
			string temp;

			getline(ss, temp, ';');
			readers[readerCount].readerID = stoi(temp);
			getline(ss, readers[readerCount].firstName, ';');
			getline(ss, readers[readerCount].lastName, ';');
			getline(ss, readers[readerCount].contactEmail, ';');
			getline(ss, readers[readerCount].phoneNumber, ';');
			getline(ss, temp, ';');
			readers[readerCount].activeLoans = stoi(temp);
			readerCount++;

			if (readerCount == MAX_READERS)
			{
				cout << "Max reader count reached only " << MAX_READERS << " reader entries allowed" << endl;
				break;
			}
		}

		readersFile.close();
	}
}

void displayAuthors()
{
	cout << "\n===== AUTHORS =====\n";
	if (authorCount > 0)
	{
		cout << left << setw(10) << "ID"
			<< setw(20) << "First Name"
			<< setw(20) << "Last Name" << endl;
		cout << "-------------------------------------------------------" << endl;

		for (int i = 0; i < authorCount; i++)
		{
			cout << left << setw(10) << authors[i].authorID
				<< setw(20) << authors[i].firstName
				<< setw(20) << authors[i].lastName << endl;
		}

		cout << endl;
	}
	else
	{
		cout << "No authors found.\n\n";
	}

}

void displayBooks()
{
	cout << "\n===== BOOKS =====\n";
	if (bookCount > 0)
	{
		cout << left << setw(15) << "ISBN"
			<< setw(45) << "Title"
			<< setw(10) << "Author ID" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < bookCount; i++)
		{
			cout << left << setw(15) << books[i].ISBN
				<< setw(45) << books[i].title
				<< setw(10) << books[i].author.authorID << endl;
		}
	}
	else
	{
		cout << "No books found.\n";
	}

}

void displayLoans()
{
	cout << "\n===== LOANS =====\n";
	if (loanCount > 0)
	{
		cout << left << setw(10) << "Loan ID"
			<< setw(15) << "Reader ID"
			<< setw(15) << "ISBN"
			<< setw(15) << "Borrow Date"
			<< setw(15) << "Due Date"
			<< setw(10) << "Returned" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < loanCount; i++)
		{
			cout << left << setw(10) << loans[i].loanID
				<< setw(15) << loans[i].readerID
				<< setw(15) << loans[i].ISBN
				<< setw(15) << loans[i].borrowDate
				<< setw(15) << loans[i].dueDate;

			if (loans[i].isReturned)
				cout << setw(10) << "Yes" << endl;
			else
				cout << setw(10) << "No" << endl;
		}
	}
	else
	{
		cout << "No loans found.\n";
	}

}

void displayReaders()
{
	cout << "\n===== READERS =====\n";
	if (readerCount > 0)
	{
		cout << left << setw(10) << "Reader ID"
			<< setw(20) << "First Name"
			<< setw(20) << "Last Name"
			<< setw(30) << "Email"
			<< setw(15) << "Phone"
			<< setw(10) << "Active loans" << endl;
		cout << "-----------------------------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < readerCount; i++)
		{
			cout << left << setw(10) << readers[i].readerID
				<< setw(20) << readers[i].firstName
				<< setw(20) << readers[i].lastName
				<< setw(30) << readers[i].contactEmail
				<< setw(15) << readers[i].phoneNumber
				<< setw(10) << readers[i].activeLoans << endl;
		}
	}
	else
	{
		cout << "No readers found.\n";
	}

}

void displayAllData()
{
	displayAuthors();
	displayBooks();
	displayLoans();
	displayReaders();
}

void editAuthor(int authorIDToEdit)
{
	bool authorFound = false;

	for (int i = 0; i < authorCount; i++)
	{
		if (authors[i].authorID == authorIDToEdit)
		{
			authorFound = true;

			cout << "Editing Author with ID: " << authorIDToEdit << endl;
			cout << "Current Name: " << authors[i].firstName << " " << authors[i].lastName << endl;

			cout << "Enter new First Name: ";
			cin.ignore();
			getline(cin, authors[i].firstName);

			cout << "Enter new Last Name: ";
			getline(cin, authors[i].lastName);

			cout << "Author details updated successfully!" << endl;
			return;
		}
	}

	if (!authorFound)
	{
		cout << "Author with ID " << authorIDToEdit << " not found." << endl;
	}
}

void editBook(string ISBNToEdit)
{
	bool bookFound = false;

	for (int i = 0; i < bookCount; i++)
	{
		if (books[i].ISBN == ISBNToEdit)
		{
			bookFound = true;

			cout << "Editing book with ISBN: " << books[i].ISBN << endl;
			cin.ignore();

			cout << "Current title: " << books[i].title << endl;
			cout << "Enter new title: ";

			string newTitle;

			getline(cin, newTitle);

			books[i].title = newTitle;

			cout << "Book updated successfully!\n";

			break;
		}
	}

	if (!bookFound)
	{
		cout << "Book with ISBN " << ISBNToEdit << " not found.\n";
	}
}

void editReader(int readerIDToEdit)
{
	bool readerFound = false;

	for (int i = 0; i < readerCount; i++)
	{
		if (readers[i].readerID == readerIDToEdit)
		{
			readerFound = true;

			cout << "Editing reader with ID: " << readers[i].readerID << endl;
			cout << "Current First Name: " << readers[i].firstName << endl;
			cout << "Enter new First Name (leave empty to keep current): ";

			cin.ignore();

			string newFirstName;

			getline(cin, newFirstName);

			if (!newFirstName.empty())
			{
				readers[i].firstName = newFirstName;
			}

			cout << "Current Last Name: " << readers[i].lastName << endl;
			cout << "Enter new Last Name (leave empty to keep current): ";

			string newLastName;

			getline(cin, newLastName);

			if (!newLastName.empty())
			{
				readers[i].lastName = newLastName;
			}

			cout << "Current Contact Email: " << readers[i].contactEmail << endl;
			cout << "Enter new Contact Email (leave empty to keep current): ";

			string newContactEmail;

			getline(cin, newContactEmail);

			if (!newContactEmail.empty())
			{
				readers[i].contactEmail = newContactEmail;
			}

			cout << "Current Phone Number: " << readers[i].phoneNumber << endl;
			cout << "Enter new Phone Number (leave empty to keep current): ";

			string newPhoneNumber;

			getline(cin, newPhoneNumber);

			if (!newPhoneNumber.empty())
			{
				readers[i].phoneNumber = newPhoneNumber;
			}

			cout << "Reader updated successfully!\n";
			break;
		}
	}

	if (!readerFound)
	{
		cout << "Reader with ID " << readerIDToEdit << " not found.\n";
	}
}

void editLoan(int loanIDToEdit)
{
	bool loanFound = false;

	for (int i = 0; i < loanCount; i++)
	{
		if (loans[i].loanID == loanIDToEdit)
		{
			loanFound = true;

			cout << "Editing loan with ID: " << loans[i].loanID << endl;
			cout << "Current Reader ID: " << loans[i].readerID << endl;
			cout << "Enter new Reader ID (leave empty to keep current): ";

			cin.ignore();

			int newReaderID;
			string inputReaderID;

			getline(cin, inputReaderID);

			if (!inputReaderID.empty())
			{
				newReaderID = stoi(inputReaderID);
				loans[i].readerID = newReaderID;
			}

			cout << "Current ISBN: " << loans[i].ISBN << endl;
			cout << "Enter new ISBN (leave empty to keep current): ";

			string newISBN;

			getline(cin, newISBN);

			if (!newISBN.empty())
			{
				loans[i].ISBN = newISBN;
			}

			cout << "Current Borrow Date: " << loans[i].borrowDate << endl;
			cout << "Enter new Borrow Date (leave empty to keep current): ";

			int newBorrowDate;
			string inputBorrowDate;

			getline(cin, inputBorrowDate);

			if (!inputBorrowDate.empty())
			{
				newBorrowDate = stoi(inputBorrowDate);
				loans[i].borrowDate = newBorrowDate;
			}

			cout << "Current Due Date: " << loans[i].dueDate << endl;
			cout << "Enter new Due Date (leave empty to keep current): ";

			int newDueDate;
			string inputDueDate;

			getline(cin, inputDueDate);

			if (!inputDueDate.empty())
			{
				newDueDate = stoi(inputDueDate);
				loans[i].dueDate = newDueDate;
			}

			cout << "Current Return Status: " << (loans[i].isReturned ? "Returned" : "Not Returned") << endl;
			cout << "Is the loan returned? (y/n): ";

			string returnStatus;

			getline(cin, returnStatus);

			if (returnStatus == "y")
			{
				loans[i].isReturned = true;
			}
			else if (returnStatus == "n")
			{
				loans[i].isReturned = false;
			}

			cout << "Loan updated successfully!\n";

			calculateActiveLoans(loans, loanCount, readers, readerCount);

			break;
		}
	}

	if (!loanFound)
	{
		cout << "Loan with ID " << loanIDToEdit << " not found.\n";
	}
}

void searchLoanByLoanID(Loan loans[], int loanCount)
{
	int loanID;
	cout << "Enter Loan ID to search: ";
	cin >> loanID;
	for (int i = 0; i < loanCount; i++)
	{
		if (loans[i].loanID == loanID)
		{
			cout << "Loan found for ID " << loanID << endl;
			cout << left << setw(10) << "Loan ID"
				<< setw(15) << "Reader ID"
				<< setw(15) << "ISBN"
				<< setw(15) << "Borrow Date"
				<< setw(15) << "Due Date"
				<< setw(10) << "Returned" << endl;
			cout << "---------------------------------------------------------------------------------------" << endl;

			cout << left << setw(10) << loans[i].loanID
				<< setw(15) << loans[i].readerID
				<< setw(15) << loans[i].ISBN
				<< setw(15) << loans[i].borrowDate
				<< setw(15) << loans[i].dueDate;
			if (loans[i].isReturned)
			{
				cout << setw(10) << "Yes" << endl;
			}
			else
			{
				cout << setw(10) << "No" << endl;
			}
			return;
		}
	}
	cout << "Loan not found.\n";
}

void searchLoanByISBN(Loan loans[], int loanCount)
{
	string ISBN;
	cout << "Enter ISBN to search: ";
	cin >> ISBN;
	for (int i = 0; i < loanCount; i++)
	{
		if (loans[i].ISBN == ISBN)
		{
			cout << "Loan found for ISBN" << ISBN << endl;
			cout << left << setw(10) << "Loan ID"
				<< setw(15) << "Reader ID"
				<< setw(15) << "ISBN"
				<< setw(15) << "Borrow Date"
				<< setw(15) << "Due Date"
				<< setw(10) << "Returned" << endl;
			cout << "---------------------------------------------------------------------------------------" << endl;

			cout << left << setw(10) << loans[i].loanID
				<< setw(15) << loans[i].readerID
				<< setw(15) << loans[i].ISBN
				<< setw(15) << loans[i].borrowDate
				<< setw(15) << loans[i].dueDate;
			if (loans[i].isReturned)
			{
				cout << setw(10) << "Yes" << endl;
			}
			else
			{
				cout << setw(10) << "No" << endl;
			}
			return;
		}
	}
	cout << "Loan not found.\n";
}

void searchLoanByBorrowDate(Loan loans[], int loanCount)
{
	int borrowDate;
	cout << "Enter borrow date (YYYYMMDD): ";
	cin >> borrowDate;

	bool found = false;
	for (int i = 0; i < loanCount; i++)
	{
		if (loans[i].borrowDate == borrowDate)
		{
			if (!found)
			{
				cout << "Loans found for Borrow Date " << borrowDate << ":\n";
				cout << left << setw(10) << "Loan ID"
					<< setw(15) << "Reader ID"
					<< setw(15) << "ISBN"
					<< setw(15) << "Borrow Date"
					<< setw(15) << "Due Date"
					<< setw(10) << "Returned" << endl;
				cout << "---------------------------------------------------------------------------------------" << endl;
				found = true;
			}

			cout << left << setw(10) << loans[i].loanID
				<< setw(15) << loans[i].readerID
				<< setw(15) << loans[i].ISBN
				<< setw(15) << loans[i].borrowDate
				<< setw(15) << loans[i].dueDate;
			if (loans[i].isReturned)
			{
				cout << setw(10) << "Yes" << endl;
			}
			else
			{
				cout << setw(10) << "No" << endl;
			}
		}
	}

	if (!found)
	{
		cout << "No loans found with the borrow date " << borrowDate << ".\n";
	}
}

void searchLoanByReturnStatus(Loan loans[], int loanCount)
{
	char returnStatus;
	cout << "Enter return status (y/n): ";
	cin >> returnStatus;

	bool found = false;
	for (int i = 0; i < loanCount; i++)
	{
		if ((returnStatus == 'y' && loans[i].isReturned) || (returnStatus == 'n' && !loans[i].isReturned))
		{
			if (!found)
			{
				cout << "Loans found for Return Status: ";
				if (returnStatus == 'y')
				{
					cout << "Returned";
				}
				else
				{
					cout << "Not Returned";
				}
				cout << ":\n";
				cout << left << setw(10) << "Loan ID"
					<< setw(15) << "Reader ID"
					<< setw(15) << "ISBN"
					<< setw(15) << "Borrow Date"
					<< setw(15) << "Due Date"
					<< setw(10) << "Returned" << endl;
				cout << "---------------------------------------------------------------------------------------" << endl;
				found = true;
			}

			cout << left << setw(10) << loans[i].loanID
				<< setw(15) << loans[i].readerID
				<< setw(15) << loans[i].ISBN
				<< setw(15) << loans[i].borrowDate
				<< setw(15) << loans[i].dueDate;
			if (loans[i].isReturned)
			{
				cout << setw(10) << "Yes" << endl;
			}
			else
			{
				cout << setw(10) << "No" << endl;
			}
		}
	}

	if (!found)
	{
		cout << "No loans found with the specified return status.\n";
	}
}

void searchLoanByAuthor(Loan loans[], int loanCount, Book books[], int bookCount)
{
	string authorLastName;

	cout << "Enter author's last name: ";
	cin.ignore();
	getline(cin, authorLastName);

	bool loansFound = false;

	for (int i = 0; i < loanCount; i++)
	{
		for (int j = 0; j < bookCount; j++)
		{
			// Check if the ISBN in loans matches the ISBN in books, and if the author's name also matches
			if (loans[i].ISBN == books[j].ISBN && books[j].author.lastName == authorLastName)
			{
				// To print out table headers only once
				if (loansFound == false)
				{
					cout << "Loans found for author " << books[j].author.firstName
						<< " " << books[j].author.lastName << ":\n";
					cout << left << setw(10) << "Loan ID"
						<< setw(15) << "Reader ID"
						<< setw(15) << "ISBN"
						<< setw(15) << "Borrow Date"
						<< setw(15) << "Due Date"
						<< setw(10) << "Returned" << endl;
					cout << "---------------------------------------------------------------------------------------" << endl;
					loansFound = true;
				}

				cout << left << setw(10) << loans[i].loanID
					<< setw(15) << loans[i].readerID
					<< setw(15) << loans[i].ISBN
					<< setw(15) << loans[i].borrowDate
					<< setw(15) << loans[i].dueDate;

				if (loans[i].isReturned)
				{
					cout << setw(10) << "Yes" << endl;
				}
				else
				{
					cout << setw(10) << "No" << endl;
				}
			}
		}
	}

	if (!loansFound)
	{
		cout << "No loans found for author " << authorLastName << ".\n";
	}
}

void deleteAuthor(int authorID)
{
	bool deleted = false;
	for (int i = 0; i < authorCount; i++)
	{
		if (authors[i].authorID == authorID)
		{
			for (int j = i; j < authorCount; j++)
			{
				authors[j] = authors[j + 1];  // Move the authors to the left (up in the file) not to have empty lines
			}
			authorCount--;
			cout << "Author with ID " << authorID << " deleted.\n";
			deleted = true;
			break;
		}
	}
	if (!deleted)
	{
		cout << "Author not found.\n";
	}
}

void deleteBook(const string& ISBN)
{
	bool deleted = false;
	for (int i = 0; i < bookCount; i++)
	{
		if (books[i].ISBN == ISBN)
		{
			for (int j = i; j < bookCount; j++)
			{
				books[j] = books[j + 1];
			}

			bookCount--;
			cout << "Book with ISBN " << ISBN << " deleted.\n";
			deleted = true;
			break;
		}
	}
	if (!deleted)
	{
		cout << "Book not found.\n";
	}
}

void deleteReader(int readerID)
{
	bool deleted = false;
	for (int i = 0; i < readerCount; i++)
	{
		if (readers[i].readerID == readerID)
		{
			for (int j = i; j < readerCount; j++)
			{
				readers[j] = readers[j + 1];
			}
			readerCount--;
			cout << "Reader with ID " << readerID << " deleted.\n";
			deleted = true;
			break;
		}
	}
	if (!deleted)
	{
		cout << "Reader not found.\n";
	}
}

void deleteLoan(int loanID)
{
	bool deleted = false;
	for (int i = 0; i < loanCount; i++)
	{
		if (loans[i].loanID == loanID)
		{
			for (int j = i; j < loanCount; j++)
			{
				loans[j] = loans[j + 1];
			}
			loanCount--;
			cout << "Loan with ID " << loanID << " deleted.\n";
			deleted = true;
			break;
		}
	}
	if (!deleted)
	{
		cout << "Loan not found.\n";
	}
}

void sortAuthorsByLastName(Author authors[], int authorCount)
{
	for (int i = 0; i < authorCount; i++)
	{
		for (int j = i + 1; j < authorCount; j++)
		{
			if (authors[i].lastName > authors[j].lastName)
			{
				Author temp = authors[i];
				authors[i] = authors[j];
				authors[j] = temp;
			}
		}
	}
}

void sortReadersByReaderID(Reader readers[], int readerCount)
{
	for (int i = 0; i < readerCount; i++)
	{
		for (int j = i + 1; j < readerCount; j++)
		{
			if (readers[i].readerID > readers[j].readerID)
			{
				Reader temp = readers[i];
				readers[i] = readers[j];
				readers[j] = temp;
			}
		}
	}
}

void sortBooksByAuthorLastName(Book books[], int bookCount)
{
	for (int i = 0; i < bookCount; i++)
	{
		for (int j = i + 1; j < bookCount; j++)
		{
			if (books[i].author.lastName > books[j].author.lastName)
			{
				Book temp = books[i];
				books[i] = books[j];
				books[j] = temp;
			}
		}
	}
}

int calculateTotalActiveLoans(Reader readers[], int readerCount)
{
	int totalActiveLoans = 0;
	for (int i = 0; i < readerCount; i++)
	{
		totalActiveLoans += readers[i].activeLoans;
	}
	return totalActiveLoans;
}