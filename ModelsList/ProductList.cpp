#include "../HeaderModelsList/ProductList.h"

ProductList::ProductList()
{

}

void ProductList::SetProductList()
{

	Products = read.ReadAllProducts();


}

void ProductList::ShowProductsList()
{
	std::cout << "The ProductsList is:" << std::endl;
	for (auto& p : Products)
	{
		if (p.GetProductId() / 1000 == 1)
			std::cout << "Book" "|" << p.GetProductId() << "|" << p.GetProductName() << "|" << p.GetProductDescription() << "|" << p.GetPrice() << std::endl;
		if (p.GetProductId() / 1000 == 2)
			std::cout << "Accessory" << "|" << p.GetProductId() << "|" << p.GetProductName() << "|" << p.GetProductDescription() << "|" << p.GetPrice() << std::endl;
		if (p.GetProductId() / 1000 == 3)
			std::cout << "BoardGame" << "|" << p.GetProductId() << "|" << p.GetProductName() << "|" << p.GetProductDescription() << "|" << p.GetPrice() << std::endl;
		if (p.GetProductId() / 1000 == 4)
			std::cout << "HomeDeco" << "|" << p.GetProductId() << "|" << p.GetProductName() << "|" << p.GetProductDescription() << "|" << p.GetPrice() << std::endl;
		if (p.GetProductId() / 1000 == 5)
			std::cout << "Magazine" << "|" << p.GetProductId() << "|" << p.GetProductName() << "|" << p.GetProductDescription() << "|" << p.GetPrice() << std::endl;
		if (p.GetProductId() / 1000 == 6)
			std::cout << "Movie" << "|" << p.GetProductId() << "|" << p.GetProductName() << "|" << p.GetProductDescription() << "|" << p.GetPrice() << std::endl;
		if (p.GetProductId() / 1000 == 7)
			std::cout << "Music" << "|" << p.GetProductId() << "|" << p.GetProductName() << "|" << p.GetProductDescription() << "|" << p.GetPrice() << std::endl;
		if (p.GetProductId() / 1000 == 8)
			std::cout << "Tea" << "|" << p.GetProductId() << "|" << p.GetProductName() << "|" << p.GetProductDescription() << "|" << p.GetPrice() << std::endl;
		if (p.GetProductId() / 1000 == 9)
			std::cout << "Wine" << "|" << p.GetProductId() << "|" << p.GetProductName() << "|" << p.GetProductDescription() << "|" << p.GetPrice() << std::endl;

	}
}

std::list<Product> ProductList::GetProducts()
{
	return this->Products;
}

void ProductList::DeleteById(std::int64_t id)
{

	std::list<Product> tmp;
	for (auto& p : Products)
	{
		if (p.GetProductId() != id)
		{
			tmp.push_back(p);

		}
	}
	std::ofstream fout("Products.txt");
	std::int64_t lastId;
	if (tmp.size() != 0)
		lastId = tmp.back().GetProductId();
	for (auto& p : tmp)
	{
		if (p.GetProductId() != lastId)
			fout << p.GetProductId() << "|" << p.GetProductName() << "|" << p.GetProductDescription() << "|" << p.GetPrice() << std::endl;
		else
			fout << p.GetProductId() << "|" << p.GetProductName() << "|" << p.GetProductDescription() << "|" << p.GetPrice();
	}

	Products = tmp;
}

void ProductList::Add(Product p)
{
	std::ofstream fout("Products.txt");
	Products.push_back(p);
	std::int64_t lastId;
	if (Products.size() != 0)
		lastId = Products.back().GetProductId();
	for (auto p : Products)
	{
		if (p.GetProductId() != lastId)
			fout << p.GetProductId() << "|" << p.GetProductName() << "|" << p.GetProductDescription() << "|" << p.GetPrice() << std::endl;
		else
			fout << p.GetProductId() << "|" << p.GetProductName() << "|" << p.GetProductDescription() << "|" << p.GetPrice();
	}
}
