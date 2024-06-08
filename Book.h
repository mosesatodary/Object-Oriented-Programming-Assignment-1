#pragma once

// The Book class represents a book with a title, author, ID, and a borrowed status.
class Book
{
public:
	// The constructor takes a title, author, and ID as arguments and initializes the book with these values.
	// The borrowed status is initially set to false.
	Book(std::string title, std::string author, int ID)
		: m_Title(title), m_Author(author), m_ID(ID), m_IsBorrowed(false)
	{
	}

	// The BorrowBook function checks if the book is already borrowed. If it is not, it sets the borrowed status to true
	// and prints a message indicating that the book has been successfully borrowed. If the book is already borrowed,
	// it prints a message indicating that the book is already borrowed.
	void BorrowBook()
	{
		if (!m_IsBorrowed)
		{
			m_IsBorrowed = true;
			std::cout << "\nYou have successfully borrowed the book: " << m_Title << " by " << m_Author << "\tBook ID: " << m_ID << std::endl;
		}
		else
		{
			std::cout << "Book is already borrowed." << std::endl;
		}
	}

	// The ReturnBook function checks if the book is borrowed. If it is, it sets the borrowed status to false.
	// If the book is not borrowed, it prints a message indicating that the book was not borrowed.
	void ReturnBook() {
		if (m_IsBorrowed)
		{
			m_IsBorrowed = false;
		}
		else
		{
			std::cout << "Book was not borrowed." << std::endl;
		}
	}

public:
	// m_Title is a public member variable that stores the title of the book.
	std::string m_Title;
	// m_Author is a public member variable that stores the author of the book.
	std::string m_Author;
	// m_ID is a public member variable that stores the ID of the book.
	int m_ID;
	// m_IsBorrowed is a public member variable that stores the borrowed status of the book.
	bool m_IsBorrowed;
};
