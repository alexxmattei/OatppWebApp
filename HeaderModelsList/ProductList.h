#pragma once


#include "../Helpers/Reader.h"
#include "../HeaderModels/Product.h"

#include <list>
#include <fstream>


class ProductList
{
private:
	std::list<Product> Products;
	Reader read;

public:
	ProductList();

	void SetProductList();

	void ShowProductsList();

	std::list<Product> GetProducts();

	void DeleteById(std::int64_t id);

	void Add(Product p);
};

