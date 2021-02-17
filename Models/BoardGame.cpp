#include "../HeaderModels/BoardGame.h"

BoardGame::BoardGame()
{
}

BoardGame::BoardGame(std::int64_t newId, std::string newName, std::string newDescription, double pret, std::string category, int age)
{
	this->SetProductId(newId);
	this->SetProductName(newName);
	this->SetProductDescription(newDescription);
	this->SetProductPrice(pret);
	this->category = category;
	this->age = age;

	std::string boardGameString = "BoardGame";
	boardGameString.append("|");
	boardGameString.append(std::to_string(this->GetProductId()));
	boardGameString.append("|");
	boardGameString.append(this->GetProductName());
	boardGameString.append("|");
	boardGameString.append(this->GetProductDescription());
	boardGameString.append("|");
	boardGameString.append(std::to_string(this->GetPrice()));
	boardGameString.append("|");
	boardGameString.append(this->GetCategory());
	boardGameString.append("|");
	boardGameString.append(std::to_string(this->GetAge()));
	std::ofstream outfile;

	outfile.open("Products.txt", std::ios_base::app);
	outfile << boardGameString << "\n";
	outfile.close();
}

BoardGame::~BoardGame()
{
}

void BoardGame::SetAge(int age)
{
	this->age = age;
}

void BoardGame::SetCategory(std::string category)
{
	this->category = category;
}

std::string BoardGame::GetCategory() const
{
	return this->category;
}

int BoardGame::GetAge() const
{
	return this->age;
}