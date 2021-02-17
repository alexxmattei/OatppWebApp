#pragma once
#include "Product.h"

class Book : public  Product
{
private:
	std::string bookWriter;
	std::string bookLanguage;
	std::string bookCategory;
	int bookNrOfPages;

public:
	Book();
	Book(std::int64_t newId, std::string newName, std::string newDescription, double pret, std::string writer, std::string language, std::string category, int nr);
	~Book();

	std::string GetWriter() const;
	std::string GetLanguage() const;
	std::string GetCategory()const;
	int GetNrOfPages() const;

	void SetBookWriter(std::string writer);
	void SetBookLanguage(std::string language);
	void SetBookCategory(std::string category);
	void SetNrOfPages(int nr);
};

