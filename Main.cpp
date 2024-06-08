#include <iostream>
#include <vector>
#include <string>


#include "Library.h"
#include "User.h"



int main() {
	// Create a library
	Library library;

	// Add books to the library
	library.AddBook(Book("The Great Gatsby", "F. Scott Fitzgerald", 1));
	library.AddBook(Book("To Kill a Mockingbird", "Harper Lee", 2));
	library.AddBook(Book("1984", "George Orwell", 3));

	// Create a user
	User user("John Doe");

	// User borrows a book
	if(user.BorrowBook(library, "1984"));
	{
		std::cout << "User borrowed 1984." << std::endl;
	}

	// User returns a book
	if(user.ReturnBook(library, "1984"));
	{
		std::cout << "User returned 1984." << std::endl;
	}

	return 0;
}