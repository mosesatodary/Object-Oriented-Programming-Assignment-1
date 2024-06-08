#pragma once

#include "Library.h"

// The User class represents a user in a library system.
class User
{
public:
	// Constructor that initializes a User object with a name.
	User(std::string m_Name)
		: m_Name(m_Name) // The name of the user.
	{
	}

	// Method to borrow a book from a library.
	// It takes a reference to a Library object and the title of the book as parameters.
	// It returns true if the book is successfully borrowed, false otherwise.
	bool BorrowBook(Library& library, std::string title)
	{
		// Search for the book in the library by title.
		Book* book = library.SearchBookByTitle(title);

		// If the book is found and it's not already borrowed,
		// borrow the book and add it to the user's list of borrowed books.
		if (book != nullptr && !book->m_IsBorrowed)
		{
			book->BorrowBook();
			m_BorrowedBooks.push_back(book);

			return true;
		}

		// If the book is not found or it's already borrowed, return false.
		return false;
	}

	// Method to return a book to a library.
	// It takes a reference to a Library object and the title of the book as parameters.
	// It returns true if the book is successfully returned, false otherwise.
	bool ReturnBook(Library& library, std::string title)
	{
		// Iterate over the user's list of borrowed books.
		for (auto& book : m_BorrowedBooks)
		{
			// If the book is found in the list, return the book and remove it from the list.
			if (book->m_Title == title)
			{
				book->ReturnBook();
				m_BorrowedBooks.erase(std::remove(m_BorrowedBooks.begin(), m_BorrowedBooks.end(), book), m_BorrowedBooks.end());
				return true;
			}
		}

		// If the book is not found in the user's list of borrowed books, print an error message and return false.
		std::cout << "Book not found in user's borrowed m_Books." << std::endl;
		return false;
	}

private:
	std::string m_Name; // The name of the user.
	std::vector<Book*> m_BorrowedBooks; // The list of books borrowed by the user.
};
