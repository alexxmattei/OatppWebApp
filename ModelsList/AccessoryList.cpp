#include "../HeaderModelsList/AccessoryList.h"

AccessoryList::AccessoryList()
{

}

void AccessoryList::SetAccessoryList()
{
	std::ifstream fin("Accessories.txt");
	while (!fin.eof())
	{
		std::string linie;
		getline(fin, linie);
		Accessories.push_back(read.ReadAccessory(linie));
	}
}

void AccessoryList::ShowAccessoryList()
{
	std::cout << "The AccessoryList is:" << std::endl;
	for (auto& ac : Accessories)
	{
		std::cout << ac.GetProductId() << "|" << ac.GetProductName() << "|" << ac.GetProductDescription() << "|" << ac.GetPrice() << "|" << ac.GetCategory() << "|" << ac.GetGender() << std::endl;
	}
}

std::list<Accessory> AccessoryList::GetAccessories()
{
	return this->Accessories;
}

void AccessoryList::Add(Accessory a)
{
	std::ofstream fout("Accessories.txt");
	Accessories.push_back(a);
	std::int64_t lastId;
	if (Accessories.size() != 0)
		lastId = Accessories.back().GetProductId();
	for (auto acc : Accessories)
	{
		if (acc.GetProductId() != lastId)
			fout << acc.GetProductId() << "|" << acc.GetProductName() << "|" << acc.GetProductDescription() << "|" << acc.GetPrice() << "|" << acc.GetCategory() << "|" << acc.GetGender() << std::endl;
		else
			fout << acc.GetProductId() << "|" << acc.GetProductName() << "|" << acc.GetProductDescription() << "|" << acc.GetPrice() << "|" << acc.GetCategory() << "|" << acc.GetGender();
	}

}

void AccessoryList::DeleteById(std::int64_t id)
{
	std::list<Accessory> tmp;

	for (auto& acc : Accessories)
	{
		if (acc.GetProductId() != id)
		{
			tmp.push_back(acc);

		}
	}
	std::ofstream fout("Accessories.txt");
	std::int64_t lastId;
	if (tmp.size() != 0)
		lastId = tmp.back().GetProductId();
	for (auto& acc : tmp)
	{
		if (acc.GetProductId() != lastId)
			fout << acc.GetProductId() << "|" << acc.GetProductName() << "|" << acc.GetProductDescription() << "|" << acc.GetPrice() << "|" << acc.GetCategory() << "|" << acc.GetGender() << std::endl;
		else
			fout << acc.GetProductId() << "|" << acc.GetProductName() << "|" << acc.GetProductDescription() << "|" << acc.GetPrice() << "|" << acc.GetCategory() << "|" << acc.GetGender();
	}

	Accessories = tmp;
}
