#include "../HeaderModelsList/BookList.h"

 BookList::BookList()
{

}

void BookList::SetBookList()
{
	std::ifstream fin("Books.txt");
	while (!fin.eof())
	{
		std::string linie;
		std::getline(fin, linie);
		Books.push_back(read.ReadBook(linie));
	}
}

void BookList::ShowBookList()
{
	std::cout << "The BookList is" << std::endl;
	for (auto& book : Books)
	{
		std::cout << book.GetProductId() << "|" << book.GetProductName() << "|" << book.GetProductDescription() << "|" << book.GetPrice() << "|" << book.GetWriter() << "|" << book.GetLanguage() << "|" << book.GetCategory() << "|" << book.GetNrOfPages() << std::endl;
	}
}

std::list<Book> BookList::GetBooks()
{
	return this->Books;
}
void BookList::DeleteById(long id)
{
	std::list<Book> tmp;

	for (auto& book : Books)
	{
		if (book.GetProductId() != id)
		{
			tmp.push_back(book);

		}
	}
	std::ofstream fout("Books.txt");
	long lastId;
	if (tmp.size() != 0)
		lastId = tmp.back().GetProductId();
	for (auto& book : tmp)
	{
		if (book.GetProductId() != lastId)
			fout << book.GetProductId() << "|" << book.GetProductName() << "|" << book.GetProductDescription() << "|" << book.GetPrice() << "|" << book.GetWriter() << "|" << book.GetLanguage() << "|" << book.GetCategory() << "|" << book.GetNrOfPages() << std::endl;
		else
			fout << book.GetProductId() << "|" << book.GetProductName() << "|" << book.GetProductDescription() << "|" << book.GetPrice() << "|" << book.GetWriter() << "|" << book.GetLanguage() << "|" << book.GetCategory() << "|" << book.GetNrOfPages();
	}

	Books = tmp;
}

void BookList::Add(Book b)
{
	std::ofstream fout("Books.txt");
	Books.push_back(b);
	std::int64_t lastId;
	if (Books.size() != 0)
		lastId = Books.back().GetProductId();
	for (auto& book : Books)
	{
		if (book.GetProductId() != lastId)
			fout << book.GetProductId() << "|" << book.GetProductName() << "|" << book.GetProductDescription() << "|" << book.GetPrice() << "|" << book.GetWriter() << "|" << book.GetLanguage() << "|" << book.GetCategory() << "|" << book.GetNrOfPages() << std::endl;
		else
			fout << book.GetProductId() << "|" << book.GetProductName() << "|" << book.GetProductDescription() << "|" << book.GetPrice() << "|" << book.GetWriter() << "|" << book.GetLanguage() << "|" << book.GetCategory() << "|" << book.GetNrOfPages();
	}
}
