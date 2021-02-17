
#include "../HeaderModels/Accessory.h"



Accessory::Accessory()
{
}

Accessory::Accessory(std::int64_t newId, std::string newName, std::string newDescription, double pret, std::string category, std::string gender)
{
	this->SetProductId(newId);
	this->SetProductName(newName);
	this->SetProductDescription(newDescription);
	this->SetProductPrice(pret);
	this->category = category;
	this->gender = gender;

	std::string accessoryString = "Accessory";
	//std::string accessoryString = std::to_string(newId);
	accessoryString.append("|");
	accessoryString.append(std::to_string(this->GetProductId()));
	accessoryString.append("|");
	accessoryString.append(this->GetProductName());
	accessoryString.append("|");
	accessoryString.append(this->GetProductDescription());
	accessoryString.append("|");
	accessoryString.append(std::to_string(this->GetPrice()));
	accessoryString.append("|");
	accessoryString.append(this->GetCategory());
	accessoryString.append("|");
	accessoryString.append(this->GetGender());
	std::ofstream outfile;

	outfile.open("Products.txt", std::ios_base::app);
	outfile << accessoryString << "\n";
	outfile.close();
}

Accessory::~Accessory()
{
}

void Accessory::SetCategory(std::string newCategory)
{
	this->category = newCategory;
}

void Accessory::SetGender(std::string newGender)
{
	this->gender = newGender;
}

std::string Accessory::GetCategory()
{
	return this->category;
}

std::string Accessory::GetGender()
{
	return this->gender;
}
