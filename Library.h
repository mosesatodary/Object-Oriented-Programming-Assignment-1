#pragma once

#include "Book.h"

// The Library class represents a collection of books.
class Library
{
public:
	// The AddBook function takes a Book object as an argument and adds it to the library's collection.
	void AddBook(Book book)
	{
		m_Books.emplace_back(book);
	}

	// The RemoveBook function takes an integer ID as an argument. It iterates over the library's collection of books,
	// and if it finds a book with the same ID, it removes that book from the collection. If no book with the given ID is found,
	// it prints "Book not found." to the standard output.
	void RemoveBook(int ID) {
		for (int i = 0; i < m_Books.size(); i++)
		{
			if (m_Books[i].m_ID == ID)
			{
				m_Books.erase(m_Books.begin() + i);
				return;
			}
		}

		std::cout << "Book not found." << std::endl;
	}

	// The SearchBookByTitle function takes a string title as an argument. It iterates over the library's collection of books,
	// and if it finds a book with the same title, it returns a pointer to that book. If no book with the given title is found,
	// it prints "Book not found." to the standard output and returns a null pointer.
	Book* SearchBookByTitle(std::string title)
	{
		for (auto& book : m_Books)
		{
			if (book.m_Title == title)
			{
				return &book;
			}
		}

		std::cout << "Book not found." << std::endl;

		return nullptr;
	}
private:
	// m_Books is a private member variable of the Library class. It is a vector that stores the collection of books in the library.
	std::vector<Book> m_Books;
};
