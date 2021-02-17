#include "../HeaderModels/Wine.h"

Wine::Wine()
{
}

Wine::Wine(std::int64_t newId, std::string newName, std::string newDescription, double pret, std::string category, int year, std::string type)
{
	this->SetProductId(newId);
	this->SetProductName(newName);
	this->SetProductDescription(newDescription);
	this->SetProductPrice(pret);
	this->category = category;
	this->year = year;
	this->type = type;


	std::string wineString = "Wine";
	wineString.append("|");
	wineString.append(std::to_string(this->GetProductId()));
	wineString.append("|");
	wineString.append(this->GetProductName());
	wineString.append("|");
	wineString.append(this->GetProductDescription());
	wineString.append("|");
	wineString.append(std::to_string(this->GetPrice()));
	wineString.append("|");
	wineString.append(this->GetCategory());
	wineString.append("|");
	wineString.append(std::to_string(this->GetYear()));
	wineString.append("|");
	wineString.append(this->GetType());

	std::ofstream outfile;

	outfile.open("Products.txt", std::ios_base::app);
	outfile << wineString << "\n";
	outfile.close();

}

Wine::~Wine()
{
}

void Wine::SetCategory(std::string newCategory)
{
	this->category = newCategory;
}

void Wine::SetYear(int newYear)
{
	this->year = newYear;
}

void Wine::SetType(std::string newType)
{
	this->type = newType;
}

std::string Wine::GetCategory()
{
	return this->category;
}

int Wine::GetYear()
{
	return this->year;
}

std::string Wine::GetType()
{
	return this->type;
}
