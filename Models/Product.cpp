#include "../HeaderModels/Product.h"

Product::Product()
{

}

Product::Product(std::int64_t newId, std::string newName, std::string newDescription, double pret)
{
	this->SetProductId(newId);
	this->SetProductName(newName);
	this->SetProductDescription(newDescription);
	this->SetProductPrice(pret);
}

Product::~Product()
{

}

void Product::SetProductId(std::int64_t newId)
{
	this->productId = newId;
}

void Product::SetProductName(std::string newName)
{
	this->productName = newName;
}

void Product::SetProductDescription(std::string newDescription)
{
	this->productDescription = newDescription;
}

void Product::SetProductPrice(double newPrice)
{
	this->productPrice = newPrice;
}

std::int64_t Product::GetProductId()
{
	return this->productId;
}

std::string Product::GetProductName()
{
	return this->productName;
}

std::string Product::GetProductDescription()
{
	return this->productDescription;
}

double Product::GetPrice()
{
	return this->productPrice;
}
