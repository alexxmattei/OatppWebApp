#pragma once
#include "Product.h"

class BoardGame : public Product
{
private:
	std::string category;
	int age;
public:
	BoardGame();
	BoardGame(std::int64_t newId, std::string newName, std::string newDescription, double pret, std::string category, int age);
	~BoardGame();

	void SetAge(int age);
	void SetCategory(std::string category);

	std::string GetCategory() const;
	int GetAge() const;
};

