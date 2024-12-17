#include <iostream>
#include <fstream>
#include "Utils.h"
#include "LibraryEntities.h"

using namespace std;

int main()
{
	int mainMenuChoice;
	int totalActiveLoans = 0;
	Author mostBorrowedAuthor;

	do
	{
		cout << "\nMAIN MENU\n";
		cout << "__________________\n";
		cout << "1. View data\n";
		cout << "2. Add data\n";
		cout << "3. Edit data\n";
		cout << "4. Delete data\n";
		cout << "5. Search\n";
		cout << "6. Exit\n";
		cout << "------------------\n";
		cout << "Your choice: ";
		cin >> mainMenuChoice;

		switch (mainMenuChoice)
		{
		case 1:
		{
			int viewDataChoice;

			do
			{
				cout << "\nVIEW DATA MENU\n";
				cout << "------------------\n";
				cout << "1. View all data\n";
				cout << "2. View part of data\n";
				cout << "3. Return to main menu\n";
				cout << "------------------\n";
				cout << "Your choice: ";
				cin >> viewDataChoice;

				switch (viewDataChoice)
				{
				case 1:
					cout << "Viewing all data...\n";
					readDataFromFile();
					displayAllData();

					break;

				case 2:
					cout << "Viewing part of data...\n";

					int partDataChoice;
					
					do
					{
						cout << "\nPART OF DATA MENU\n";
						cout << "------------------\n";
						cout << "1. View authors\n";
						cout << "2. View books\n";
						cout << "3. View readers\n";
						cout << "4. View loans\n";
						cout << "5. Return to previous menu\n";
						cout << "------------------\n";
						cout << "Your choice: ";
						cin >> partDataChoice;

						switch (partDataChoice)
						{
						case 1:
							cout << "Viewing authors...\n";
							readDataFromFile();
							sortAuthorsByLastName(authors, authorCount);
							displayAuthors();

							mostBorrowedAuthor = calculateMostBorrowedAuthor(loans, loanCount, books, bookCount);

							// Output the result
							cout << "Most borrowed author: " << mostBorrowedAuthor.firstName << " " << mostBorrowedAuthor.lastName << endl;

							break;

						case 2:
							cout << "Viewing books...\n";
							readDataFromFile();
							sortBooksByAuthorLastName(books, bookCount);
							displayBooks();

							break;

						case 3:
							cout << "Viewing readers...\n";
							readDataFromFile();
							sortReadersByReaderID(readers, readerCount);
							displayReaders();

							break;

						case 4:
							cout << "Viewing loans...\n";
							readDataFromFile();
							displayLoans();

							totalActiveLoans = calculateTotalActiveLoans(readers, readerCount);
							cout << "Total active loans: " << totalActiveLoans << endl;

							break;

						case 5:
							cout << "Returning to previous menu...\n";

							break;

						default:
							cout << "Invalid choice, please try again.\n";
						}

					} while (partDataChoice != 5);

					break;

				case 3:
					cout << "Returning to main menu...\n";

					break;

				default:
					cout << "Invalid choice, please try again.\n";
				}

			} while (viewDataChoice != 3);

			break;
		}

		case 2:
		{
			int addDataChoice;

			do
			{
				cout << "\nADD DATA MENU\n";
				cout << "-----------------------------------------------------------\n";
				cout << "1. Add a new author\n";
				cout << "2. Add a new book\n";
				cout << "3. Add a new reader\n";
				cout << "4. Add a new loan\n";
				cout << "5. Return to main menu\n";
				cout << "-----------------------------------------------------------\n";
				cout << "Your choice: ";
				cin >> addDataChoice;

				switch (addDataChoice)
				{
				case 1:
					cout << "Adding a new author...\n";
					readDataFromFile();
					addAuthor();
					saveDataToFile();

					break;

				case 2:
					cout << "Adding a new book...\n";
					readDataFromFile();
					addBook();
					saveDataToFile();

					break;

				case 3:
					cout << "Adding a new reader...\n";
					readDataFromFile();
					addReader();
					saveDataToFile();

					break;

				case 4:
					cout << "Adding a new loan...\n";
					readDataFromFile();
					addLoan();
					calculateActiveLoans(loans, loanCount, readers, readerCount);
					saveDataToFile();

					break;

				case 5:
					cout << "Returning to main menu...\n";

					break;

				default:
					cout << "Invalid choice, please try again.\n";
				}

			} while (addDataChoice != 5);
			break;
		}

		case 3:
		{
			int editDataChoice;
			int authorIDToEdit, loanIDToEdit, readerIDToEdit;
			string ISBNToEdit;

			do
			{
				cout << "\nEDIT DATA MENU\n";
				cout << "-----------------------------------------------------------\n";
				cout << "1. Edit author\n";
				cout << "2. Edit book\n";
				cout << "3. Edit reader\n";
				cout << "4. Edit loan\n";
				cout << "5. Return to main menu\n";
				cout << "-----------------------------------------------------------\n";
				cout << "Your choice: ";
				cin >> editDataChoice;

				switch (editDataChoice)
				{
				case 1:
					cout << "Editing an author...\n";
					readDataFromFile();

					cout << "Enter the author ID to edit: ";
					cin >> authorIDToEdit;

					editAuthor(authorIDToEdit);
					saveDataToFile();

					break;

				case 2:
					cout << "Editing a book...\n";
					readDataFromFile();

					cout << "Enter the book ISBN to edit: ";
					cin >> ISBNToEdit;

					editBook(ISBNToEdit);
					saveDataToFile();

					break;

				case 3:
					cout << "Editing a reader...\n";
					readDataFromFile();

					cout << "Enter the reader ID to edit: ";
					cin >> readerIDToEdit;

					editReader(readerIDToEdit);
					saveDataToFile();

					break;

				case 4:
					cout << "Editing a loan...\n";
					readDataFromFile();

					cout << "Enter the loan ID to edit: ";
					cin >> loanIDToEdit;

					editLoan(loanIDToEdit);
					saveDataToFile();

					break;

				case 5:
					cout << "Returning to main menu...\n";

					break;

				default:
					cout << "Invalid choice, please try again.\n";
				}

			} while (editDataChoice != 5);

			break;
		}

		case 4:
		{
			int deleteDataChoice;

			do
			{
				cout << "\nDELETE DATA MENU\n";
				cout << "------------------\n";
				cout << "1. Delete an author\n";
				cout << "2. Delete a book\n";
				cout << "3. Delete a reader\n";
				cout << "4. Delete a loan\n";
				cout << "5. Return to main menu\n";
				cout << "------------------\n";
				cout << "Your choice: ";
				cin >> deleteDataChoice;

				switch (deleteDataChoice)
				{
				case 1:
				{
					cout << "Deleting an author...\n";
					readDataFromFile();

					int authorID;
					cout << "Enter the author ID to delete: ";
					cin >> authorID;

					deleteAuthor(authorID);
					saveDataToFile();

					break;
				}
				case 2:
				{
					cout << "Deleting a book...\n";
					readDataFromFile();

					string ISBN;
					cout << "Enter the ISBN of the book to delete: ";
					cin >> ISBN;

					deleteBook(ISBN);
					saveDataToFile();

					break;
				}
				case 3:
				{
					cout << "Deleting a reader...\n";
					readDataFromFile();

					int readerID;
					cout << "Enter the Reader ID to delete: ";
					cin >> readerID;

					deleteReader(readerID);
					saveDataToFile();

					break;
				}
				case 4:
				{
					cout << "Deleting a loan...\n";
					readDataFromFile();

					int loanID;
					cout << "Enter the Loan ID to delete: ";
					cin >> loanID;

					deleteLoan(loanID);
					saveDataToFile();

					break;
				}
				case 5:
					cout << "Returning to main menu...\n";

					break;

				default:

					cout << "Invalid choice, please try again.\n";

					break;
				}

			} while (deleteDataChoice != 5);

			break;
		}


		case 5:
		{
			int searchDataChoice;
			do
			{
				cout << "\nSEARCH MENU\n";
				cout << "------------------\n";
				cout << "Select search criterion:\n";
				cout << "1. Search loans by loan ID\n";
				cout << "2. Search loans by ISBN\n";
				cout << "3. Search loans by borrow date\n";
				cout << "4. Search loans by return status\n";
				cout << "5. Search loans by author\n";
				cout << "6. Return to main menu\n";
				cout << "------------------\n";
				cout << "Your choice: ";
				cin >> searchDataChoice;

				switch (searchDataChoice)
				{
				case 1:
					cout << "Searching loans by loan ID...\n";
					readDataFromFile();
					searchLoanByLoanID(loans, loanCount);

					break;

				case 2:
					cout << "Searching loans by ISBN...\n";
					readDataFromFile();
					searchLoanByISBN(loans, loanCount);

					break;

				case 3:
					cout << "Searching loans by borrow date...\n";
					readDataFromFile();
					searchLoanByBorrowDate(loans, loanCount);

					break;

				case 4:
					cout << "Searching loans by return status...\n";
					readDataFromFile();
					searchLoanByReturnStatus(loans, loanCount);

					break;

				case 5:
					cout << "Searching loans by author...\n";
					readDataFromFile();
					searchLoanByAuthor(loans, loanCount, books, bookCount);

					break;

				case 6:
					cout << "Returning to main menu...\n";

					break;

				default:
					cout << "Invalid choice, please try again.\n";
				}

			} while (searchDataChoice != 6);

			break;
		}

		case 6:
			cout << "Exiting program...\n";

			break;

		default:

			cout << "Invalid choice, please try again.\n";
		}

	} while (mainMenuChoice != 6);

	return 0;
}