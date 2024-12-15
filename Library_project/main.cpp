#include <iostream>
#include <fstream>
#include "Utils.h"
#include "LibraryEntities.h"

using namespace std;

int main()
{
	int mainMenuChoice;

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
					// Call function to view part of data

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
					cout << "Enter the Author ID to edit: ";
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
				cout << "-----------------------------------------------------------\n";
				cout << "1. Delete author\n";
				cout << "2. Delete book\n";
				cout << "3. Delete reader\n";
				cout << "4. Delete loan\n";
				cout << "5. Return to main menu\n";
				cout << "-----------------------------------------------------------\n";
				cout << "Your choice: ";
				cin >> deleteDataChoice;

				switch (deleteDataChoice)
				{
				case 1:
					cout << "Deleting an author...\n";
					// Call function to delete an author
					break;

				case 2:
					cout << "Deleting a book...\n";
					// Call function to delete a book
					break;

				case 3:
					cout << "Deleting a reader...\n";
					// Call function to delete a reader
					break;

				case 4:
					cout << "Deleting a loan...\n";
					// Call function to delete a loan
					break;

				case 5:
					cout << "Returning to main menu...\n";
					break;

				default:
					cout << "Invalid choice, please try again.\n";
				}

			} while (deleteDataChoice != 5);
			break;
		}

		case 5:
			cout << "Searching...\n";
			readDataFromFile();
			searchLoans(loans, loanCount, books, bookCount);
			break;

		case 6:
			cout << "Exiting program...\n";
			break;

		default:
			cout << "Invalid choice, please try again.\n";
		}

	} while (mainMenuChoice != 6);

	return 0;
}