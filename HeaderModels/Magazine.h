#pragma once
#pragma once
#include "Product.h"

class Magazine :public Product
{
private:
	std::string magazineLanguage;
	std::string magazineCategory;
	int magazineNrPages;
public:
	Magazine();
	Magazine(std::int64_t newId,std::string newName, std::string newDescription, double pret, std::string language, std::string category, int pages);
	~Magazine();

	std::string GetLanguage() const;
	std::string GetCategory() const;

	int GetNrPages() const;

	void SetLanguage(std::string language);
	void SetCategory(std::string category);
	void SetNeOfPages(int pages);

};

