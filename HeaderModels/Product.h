#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include "oatpp/core/Types.hpp"

class Product
{
private:
	std::int64_t productId;
	std::string productName;
	std::string productDescription;
	double productPrice;

public:

	Product();
	Product(std::int64_t newId, std::string newName, std::string newDescription, double pret);
	~Product();

	void SetProductId(std::int64_t newId);
	void SetProductName(std::string newName);
	void SetProductDescription(std::string newDescription);
	void SetProductPrice(double newPrice);

	std::int64_t GetProductId();
	std::string GetProductName();
	std::string GetProductDescription();
	double GetPrice();



};