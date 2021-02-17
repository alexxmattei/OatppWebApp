#include "../HeaderModels/Book.h"

Book::Book()
{

}

Book::Book(std::int64_t newId, std::string newName, std::string newDescription, double pret, std::string writer, std::string language, std::string category, int nr)
{
	this->SetProductId(newId);
	this->SetProductName(newName);
	this->SetProductDescription(newDescription);
	this->SetProductPrice(pret);
	this->bookWriter = writer;
	this->bookLanguage = language;
	this->bookCategory = category;
	this->bookNrOfPages = nr;

	std::string bookString = "Book";
	bookString.append("|");
	bookString.append(std::to_string(this->GetProductId()));
	bookString.append("|");
	bookString.append(this->GetProductName());
	bookString.append("|");
	bookString.append(this->GetProductDescription());
	bookString.append("|");
	bookString.append(std::to_string(this->GetPrice()));
	bookString.append("|");
	bookString.append(this->GetWriter());
	bookString.append("|");
	bookString.append(this->GetLanguage());
	bookString.append("|");
	bookString.append(this->GetCategory());
	bookString.append("|");
	bookString.append(std::to_string(this->GetNrOfPages()));
	std::ofstream outfile;

	outfile.open("Products.txt", std::ios_base::app);
	outfile << bookString << "\n";
	outfile.close();
}

Book::~Book()
{
}

std::string Book::GetWriter() const
{
	return this->bookWriter;
}

std::string Book::GetLanguage() const
{
	return this->bookLanguage;
}

std::string Book::GetCategory() const
{
	return this->bookCategory;
}

int Book::GetNrOfPages() const
{
	return this->bookNrOfPages;
}



void Book::SetBookWriter(std::string writer)
{
	this->bookWriter = writer;
}

void Book::SetBookLanguage(std::string language)
{
	this->bookLanguage = language;
}

void Book::SetBookCategory(std::string category)
{
	this->bookCategory = category;
}

void Book::SetNrOfPages(int nr)
{
	this->bookNrOfPages = nr;
}
