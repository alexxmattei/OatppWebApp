#include "../HeaderModels/Tea.h"

Tea::Tea()
{
}

Tea::Tea(std::int64_t id,std::string newName, std::string newDescription, double pret, std::string category, std::string newOrigin, int newQuantity)
{
	this->SetProductId(id);
	this->SetProductName(newName);
	this->SetProductDescription(newDescription);
	this->SetProductPrice(pret);
	this->category = category;
	this->origin = newOrigin;
	this->quantity = newQuantity;


	std::string teaString = "Tea";
	teaString.append("|");
	teaString.append(std::to_string(this->GetProductId()));
	teaString.append("|");
	teaString.append(this->GetProductName());
	teaString.append("|");
	teaString.append(this->GetProductDescription());
	teaString.append("|");
	teaString.append(std::to_string(this->GetPrice()));
	teaString.append("|");
	teaString.append(this->GetCategory());
	teaString.append("|");
	teaString.append(this->GetOrigin());
	teaString.append("|");
	teaString.append(std::to_string(this->GetQuantity()));

	std::ofstream outfile;

	outfile.open("Products.txt", std::ios_base::app);
	outfile << teaString << "\n";
	outfile.close();
}

Tea::~Tea()
{
}

void Tea::SetCategory(std::string newCategory)
{
	this->category = newCategory;
}

void Tea::SetQuantity(int newQuantity)
{
	this->quantity = newQuantity;
}

void Tea::SetOrigin(std::string newOrigin)
{
	this->origin = newOrigin;
}

std::string Tea::GetCategory()
{
	return this->category;
}

std::string Tea::GetOrigin()
{
	return this->origin;
}

int Tea::GetQuantity()
{
	return this->quantity;
}
