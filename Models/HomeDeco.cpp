#include "../HeaderModels/HomeDeco.h"

HomeDeco::HomeDeco()
{
}

HomeDeco::HomeDeco(std::int64_t id,std::string type, std::string collection, std::string color, std::string material, std::string manufacturer, std::string prodName, std::string prodDescription, double prodPrice)
{
	this->objectType = type;
	this->objectCollection = collection;
	this->objectColor = color;
	this->objectMaterial = material;
	this->objectManufacutrer = manufacturer;
	this->SetProductId(id);
	this->SetProductName(prodName);
	this->SetProductDescription(prodDescription);
	this->SetProductPrice(prodPrice);

	std::string homeDecoString = "HomeDeco";
	homeDecoString.append("|");
	homeDecoString.append(std::to_string(this->GetProductId()));
	homeDecoString.append("|");
	homeDecoString.append(this->GetProductName());
	homeDecoString.append("|");
	homeDecoString.append(this->GetProductDescription());
	homeDecoString.append("|");
	homeDecoString.append(std::to_string(this->GetPrice()));
	homeDecoString.append("|");
	homeDecoString.append(this->GetObjectType());
	homeDecoString.append("|");
	homeDecoString.append(this->GetObjectCollection());
	homeDecoString.append("|");
	homeDecoString.append(this->GetObjectColor());
	homeDecoString.append("|");
	homeDecoString.append(this->GetObjectMaterial());
	homeDecoString.append("|");
	homeDecoString.append(this->GetObjectManufacturer());

	std::ofstream outfile;

	outfile.open("Products.txt", std::ios_base::app);
	outfile << homeDecoString << "\n";
	outfile.close();
}

HomeDeco::~HomeDeco()
{
}

void HomeDeco::SetObjectType(std::string newObjectType)
{
	this->objectType = newObjectType;
}

void HomeDeco::SetObjectCollection(std::string newObjectCollection)
{
	this->objectCollection = newObjectCollection;
}

void HomeDeco::SetObjectColor(std::string newObjectColor)
{
	this->objectColor = newObjectColor;
}

void HomeDeco::SetObjectMaterial(std::string newObjectMaterial)
{
	this->objectMaterial = newObjectMaterial;
}

void HomeDeco::SetObjectManufacturer(std::string newObjectManufacturer)
{
	this->objectManufacutrer = newObjectManufacturer;
}

void HomeDeco::SetNumberOfPieces(int newNoPieces)
{
	this->numberOfPieces = newNoPieces;
}

std::string HomeDeco::GetObjectType()
{
	return this->objectType;
}

std::string HomeDeco::GetObjectCollection()
{
	return this->objectCollection;
}

std::string HomeDeco::GetObjectColor()
{
	return this->objectColor;
}

std::string HomeDeco::GetObjectMaterial()
{
	return this->objectMaterial;
}

std::string HomeDeco::GetObjectManufacturer()
{
	return this->objectManufacutrer;
}

int HomeDeco::GetNumberOfPieces()
{
	return this->numberOfPieces;
}
