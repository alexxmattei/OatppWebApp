#pragma once

#include "../HeaderModels/Book.h"
#include "../Helpers/Reader.h"

#include <list>
#include <fstream>
class BookList
{
private:
	std::list<Book> Books;
	Reader read;
public:

	BookList();

	void SetBookList();

	void ShowBookList();

	std::list<Book> GetBooks();

	void DeleteById(long id);

	void Add(Book b);
};

