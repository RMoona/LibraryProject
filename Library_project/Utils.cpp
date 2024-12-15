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
			cin.clear();  // Clear the error flag
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ignores all characters up to newline 
		}
		else
		{
			break;
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
	cout << "Enter ISBN: ";
	getline(cin, newBook.ISBN);

	/*cout << "Enter barcode: ";
	getline(cin, newBook.barcode);*/

	cout << "Enter book title: ";
	getline(cin, newBook.title);

	int authorID;
	bool validAuthorID = false;

	// Validate the authorID input
	while (!validAuthorID)
	{
		cout << "Enter author ID (integer only): ";
		cin >> authorID;

		if (cin.fail())
		{
			// If the input is not an integer, clear the error flag and ignore the rest of the input
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "Invalid input. Please enter an integer for author ID.\n";
		}
		else
		{
			validAuthorID = true; // If valid, break the loop
		}
	}
	cin.ignore(); // Clear the newline character after reading the integer

	// Check if the author exists
	bool authorFound = false;
	for (int i = 0; i < authorCount; i++)
	{
		if (authors[i].authorID == authorID)
		{
			// If the author is found, assign this author to the Book's author field
			newBook.author = authors[i];
			authorFound = true;
			break;
		}
	}

	if (!authorFound)
	{
		cout << "Author not found. Adding a new author.\n";

		// Check if the authorID already exists in the authors array
		for (int i = 0; i < authorCount; i++)
		{
			if (authors[i].authorID == authorID)
			{
				cout << "Error: Author with this ID already exists.\n";
				return;
			}
		}

		// Add the new author to the authors array if not already added
		Author newAuthor;
		newAuthor.authorID = authorID;

		cout << "Enter author's first name: ";
		getline(cin, newAuthor.firstName);

		cout << "Enter author's last name: ";
		getline(cin, newAuthor.lastName);

		if (authorCount < MAX_AUTHORS) {
			authors[authorCount++] = newAuthor; // Add the new author to the authors array
		}
		else
		{
			cerr << "Error: Maximum number of authors reached.\n";
			return;
		}

		// Assign the new author to the book
		newBook.author = newAuthor;
	}

	// Add the new book to the books array
	if (bookCount < MAX_BOOKS)
	{
		books[bookCount++] = newBook;
		cout << "Book added successfully!\n";
	}
	else
	{
		cerr << "Error: Maximum number of books reached.\n";
	}
}

void addReader()
{
	if (readerCount >= MAX_READERS)
	{
		cerr << "Error: Maximum number of loans reached.\n";
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
			cin.ignore(numeric_limits<streamsize>::max(), '\n');  // ignores all characters up to newline 
		}
		else
		{
			break;
		}
	}
	cin.ignore();

	cout << "Enter reader's First Name: ";
	getline(cin, newReader.firstName);

	cout << "Enter reader's Last Name: ";
	getline(cin, newReader.lastName);

	cout << "Enter reader's e-mail: ";
	getline(cin, newReader.contactEmail);

	cout << "Enter reader's Phone Number: ";
	getline(cin, newReader.phoneNumber);

	readers[readerCount++] = newReader;
	//add activeLoans logic (count how many books have this readerID


	cout << "Reader added successfully!\n";
}

void addLoan()
{
	if (loanCount >= MAX_LOANS)
	{
		cerr << "Error: Maximum number of loans reached.\n";
		return;
	}

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
			break;
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
			break;
		}
	}
	cin.ignore();

	cout << "Enter ISBN: ";
	getline(cin, newLoan.ISBN);

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

	char returnStatus;
	while (true)
	{
		cout << "Has the book been returned? (y/n): ";
		cin >> returnStatus;

		if (cin.fail())
		{
			cerr << "Invalid input. Please enter 'y' for yes or 'n' for no.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else if (returnStatus != 'y' && returnStatus != 'n')
		{
			cerr << "Invalid input. Please enter 'y' for yes or 'n' for no.\n";
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
		}
		else
		{
			newLoan.isReturned = (returnStatus == 'y');
			break;
		}
	}

	loans[loanCount++] = newLoan;

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

	// Save authors data
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

	// Save books data, including the authorID
	for (int i = 0; i < bookCount; i++)
	{
		booksFile << books[i].ISBN << ";"
			/*<< books[i].barcode << ";"*/
			<< books[i].title << ";"
			<< books[i].author.authorID << endl; // Include authorID
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
			<< readers[i].phoneNumber << endl;
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

	if (!authorsFile.is_open())
	{
		cerr << "Failed to open authors file.\n";
		return;
	}

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
	if (!booksFile.is_open())
	{
		cerr << "Failed to open books file.\n";
		return;
	}

	// Read books data
	while (getline(booksFile, line))
	{
		stringstream ss(line);
		string temp;

		getline(ss, books[bookCount].ISBN, ';');
		/*getline(ss, books[bookCount].barcode, ';');*/
		getline(ss, books[bookCount].title, ';');

		// Parse and assign the authorID
		getline(ss, temp, ';');
		int authorID = stoi(temp);

		// Find the corresponding Author
		for (int i = 0; i < authorCount; ++i)
		{
			if (authors[i].authorID == authorID)
			{
				books[bookCount].author = authors[i]; // Link Author to Book
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
	if (!loansFile.is_open())
	{
		cerr << "Failed to open loans file for writing.\n";
		return;
	}

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
				cout << "Max loan count reached only " << MAX_LOANS << " loan entries displayed" << endl;
				break;
			}
		}

		loansFile.close();
	}

	ifstream readersFile("readers.txt");
	if (!readersFile.is_open())
	{
		cerr << "Failed to open readers file for writing.\n";
		return;
	}

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
			readerCount++;

			if (readerCount == MAX_READERS)
			{
				cout << "Max reader count reached only " << MAX_READERS << " reader entries displayed" << endl;
				break;
			}
		}

		readersFile.close();
	}
}

void displayAllData()
{
	cout << "\nAUTHORS:\n";
	if (authorCount > 0)
	{
		cout << left << setw(10) << "ID"
			<< setw(20) << "First Name"
			<< setw(20) << "Last Name" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < authorCount; i++)
		{
			cout << left << setw(10) << authors[i].authorID
				<< setw(20) << authors[i].firstName
				<< setw(20) << authors[i].lastName << endl;
		}
	}
	else
	{
		cout << "No authors found.\n";
	}

	cout << "\nBOOKS:\n";
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

	cout << "\nLOANS:\n";
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
			{
				cout << setw(10) << "Yes" << endl;
			}
			else
			{
				cout << setw(10) << "No" << endl;
			}
		}
	}
	else
	{
		cout << "No loans found.\n";
	}

	cout << "\nREADERS:\n";
	if (readerCount > 0)
	{
		cout << left << setw(10) << "Reader ID"
			<< setw(20) << "First Name"
			<< setw(20) << "Last Name"
			<< setw(30) << "Email"
			<< setw(15) << "Phone" << endl;
		cout << "---------------------------------------------------------------------------------------" << endl;

		for (int i = 0; i < readerCount; i++)
		{
			cout << left << setw(10) << readers[i].readerID
				<< setw(20) << readers[i].firstName
				<< setw(20) << readers[i].lastName
				<< setw(30) << readers[i].contactEmail
				<< setw(15) << readers[i].phoneNumber << endl;
		}
	}
	else
	{
		cout << "No readers found.\n";
	}
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

			cout << "Current Title: " << books[i].title << endl;
			cout << "Enter new title (leave empty to keep current): ";

			string newTitle;

			getline(cin, newTitle);
			if (!newTitle.empty())
			{
				books[i].title = newTitle;
			}

			// Edit author details (optional, as author is a nested struct)
			cout << "Current Author: " << books[i].author.firstName << " " << books[i].author.lastName << endl;
			cout << "Would you like to change the author? (yes/no): ";

			string changeAuthor;

			getline(cin, changeAuthor);

			if (changeAuthor == "yes")
			{
				cout << "Enter new author's first name: ";
				getline(cin, books[i].author.firstName);
				cout << "Enter new author's last name: ";
				getline(cin, books[i].author.lastName);
			}

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

			getline(cin, newFirstName);  // Read input as string

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

			cout << "Current Active Loans: " << readers[i].activeLoans << endl;
			cout << "Enter new Active Loans (leave empty to keep current): ";

			int newActiveLoans;
			string inputActiveLoans;

			getline(cin, inputActiveLoans);  // Read as string

			if (!inputActiveLoans.empty())
			{
				newActiveLoans = stoi(inputActiveLoans);  // Convert to integer
				readers[i].activeLoans = newActiveLoans;
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

			getline(cin, inputReaderID);  // Read input as string

			if (!inputReaderID.empty())
			{
				newReaderID = stoi(inputReaderID);  // Convert to integer
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

	bool found = false;

	for (int i = 0; i < loanCount; i++)
	{
		// Search for the book associated with the loan using the ISBN
		for (int j = 0; j < bookCount; j++)
		{
			// Check if the loan's ISBN matches the book's ISBN, and if the author's name matches
			if (loans[i].ISBN == books[j].ISBN && books[j].author.lastName == authorLastName)
			{
				if (!found)
				{
					cout << "Loans found for Author " << books[j].author.firstName
						<< " " << books[j].author.lastName << ":\n";
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
	}

	if (!found)
	{
		cout << "No loans found for Author " << authorLastName << ".\n";
	}
}

void searchLoans(Loan loans[], int loanCount, Book books[], int bookCount)
{
	int choice;
	cout << "\nSEARCH MENU\n";
	cout << "------------------\n";
	cout << "Select search criterion:\n";
	cout << "1. Search by Loan ID\n";
	cout << "2. Search by ISBN\n";
	cout << "3. Search by Borrow Date\n";
	cout << "4. Search by Return Status\n";
	cout << "5. Search by Author\n";
	cout << "------------------\n";
	cout << "Enter your choice (1-5): ";
	cin >> choice;

	switch (choice)
	{
	case 1:
		searchLoanByLoanID(loans, loanCount);
		break;
	case 2:
		searchLoanByISBN(loans, loanCount);
		break;
	case 3:
		searchLoanByBorrowDate(loans, loanCount);
		break;
	case 4:
		searchLoanByReturnStatus(loans, loanCount);
		break;
	case 5:
		searchLoanByAuthor(loans, loanCount, books, bookCount);
		break;
	default:
		cout << "Invalid choice.\n";
	}
}