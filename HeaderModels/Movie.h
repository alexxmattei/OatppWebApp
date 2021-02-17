#pragma once
#include "Product.h"

class Movie : public Product
{
private:
	std::string movieFormat;
	std::string movieCategory;

public:

	Movie();
	Movie(std::int64_t newId, std::string newName, std::string newDescription, double pret, std::string format, std::string category);
	~Movie();

	std::string GetFormat() const; 
	std::string GetCategory()const;

	void SetMovieFormat(std::string format);
	void SetMovieCategory(std::string category);



};

