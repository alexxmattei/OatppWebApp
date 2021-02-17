#pragma once
#include "Product.h"

class HomeDeco :public Product
{
private:
	std::string objectType;
	std::string objectCollection;
	std::string objectColor;
	std::string objectMaterial;
	std::string objectManufacutrer;
	int numberOfPieces;

public:

	HomeDeco();
	HomeDeco(std::int64_t newId, std::string type, std::string collection, std::string color, std::string material,
		std::string manufacturer, std::string prodName, std::string prodDescription, double prodPrice);
	~HomeDeco();
	void SetObjectType(std::string);
	void SetObjectCollection(std::string);
	void SetObjectColor(std::string);
	void SetObjectMaterial(std::string);
	void SetObjectManufacturer(std::string);
	void SetNumberOfPieces(int);

	std::string GetObjectType();
	std::string GetObjectCollection();
	std::string GetObjectColor();
	std::string GetObjectMaterial();
	std::string GetObjectManufacturer();
	int GetNumberOfPieces();
};

