#include "../HeaderModels/Magazine.h"

Magazine::Magazine()
{
}

Magazine::Magazine(std::int64_t id,std::string newName, std::string newDescription, double pret, std::string language, std::string category, int pages)
{
	this->SetProductId(id);
	this->SetProductName(newName);
	this->SetProductDescription(newDescription);
	this->SetProductPrice(pret);
	this->magazineLanguage = language;
	this->magazineCategory = category;
	this->magazineNrPages = pages;


	std::string magazineString = "Magazine";
	magazineString.append("|");
	magazineString.append(std::to_string(this->GetProductId()));
	magazineString.append("|");
	magazineString.append(this->GetProductName());
	magazineString.append("|");
	magazineString.append(this->GetProductDescription());
	magazineString.append("|");
	magazineString.append(std::to_string(this->GetPrice()));
	magazineString.append("|");
	magazineString.append(this->GetLanguage());
	magazineString.append("|");
	magazineString.append(this->GetCategory());
	magazineString.append("|");
	magazineString.append(std::to_string(this->GetNrPages()));

	std::ofstream outfile;

	outfile.open("Products.txt", std::ios_base::app);
	outfile << magazineString << "\n";
	outfile.close();
}

Magazine::~Magazine()
{
}

std::string Magazine::GetLanguage() const
{
	return this->magazineLanguage;
}

std::string Magazine::GetCategory() const
{
	return this->magazineCategory;
}

int Magazine::GetNrPages() const
{
	return this->magazineNrPages;
}


void Magazine::SetLanguage(std::string language)
{
	this->magazineLanguage = language;
}

void Magazine::SetCategory(std::string category)
{
	this->magazineCategory = category;
}

void Magazine::SetNeOfPages(int pages)
{
	this->magazineNrPages = pages;
}
