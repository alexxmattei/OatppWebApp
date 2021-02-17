#include "../HeaderModels/Movie.h"

Movie::Movie()
{

}

Movie::Movie(std::int64_t id,std::string newName, std::string newDescription, double pret, std::string format, std::string category)
{
	this->SetProductId(id);
	this->SetProductName(newName);
	this->SetProductDescription(newDescription);
	this->SetProductPrice(pret);
	this->movieFormat = format;
	this->movieCategory = category;


	std::string movieString = "Movie";
	movieString.append("|");
	movieString.append(std::to_string(this->GetProductId()));
	movieString.append("|");
	movieString.append(this->GetProductName());
	movieString.append("|");
	movieString.append(this->GetProductDescription());
	movieString.append("|");
	movieString.append(std::to_string(this->GetPrice()));
	movieString.append("|");
	movieString.append(this->GetFormat());
	movieString.append("|");
	movieString.append(this->GetCategory());

	std::ofstream outfile;

	outfile.open("Products.txt", std::ios_base::app);
	outfile << movieString << "\n";
	outfile.close();
}

Movie::~Movie()
{

}


std::string Movie::GetFormat() const
{
	return this->movieFormat;
}

std::string Movie::GetCategory() const
{
	return this->movieCategory;
}

void Movie::SetMovieFormat(std::string format)
{
	this->movieFormat = format;
}

void Movie::SetMovieCategory(std::string category)
{
	this->movieCategory = category;
}
