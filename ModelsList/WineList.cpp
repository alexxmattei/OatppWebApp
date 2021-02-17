#include "../HeaderModelsList/WineList.h"

WineList::WineList()
{

}

void WineList::SetWineList()
{
	std::ifstream fin("Tea.txt");
	while (!fin.eof())
	{
		std::string linie;
		getline(fin, linie);
		Wines.push_back(read.ReadWine(linie));
	}
}

void WineList::ShowWineList()
{
	std::cout << "The WineList is: " << std::endl;
	for (auto& wine : Wines)
	{
		std::cout << wine.GetProductId() << "|" << wine.GetProductName() << "|" << wine.GetProductDescription() << "|" << wine.GetPrice() << "|" << wine.GetCategory() << "|" << wine.GetYear() << "|" << wine.GetType() << std::endl;
	}
}

std::list<Wine> WineList::GetWines()
{
	return this->Wines;
}

 void WineList::DeleteById(long id)
{
	std::list<Wine> tmp;

	for (auto& wine : Wines)
	{
		if (wine.GetProductId() != id)
		{
			tmp.push_back(wine);

		}
	}
	std::ofstream fout("Wines.txt");
	long lastId;
	if (tmp.size() != 0)
		lastId = tmp.back().GetProductId();
	for (auto& wine : tmp)
	{
		if (wine.GetProductId() != lastId)
			fout << wine.GetProductId() << "|" << wine.GetProductName() << "|" << wine.GetProductDescription() << "|" << wine.GetPrice() << "|" << wine.GetCategory() << "|" << wine.GetYear() << "|" << wine.GetType() << std::endl;
		else
			fout << wine.GetProductId() << "|" << wine.GetProductName() << "|" << wine.GetProductDescription() << "|" << wine.GetPrice() << "|" << wine.GetCategory() << "|" << wine.GetYear() << "|" << wine.GetType();
	}

	Wines = tmp;
}

void WineList::Add(Wine w)
 {
	 std::ofstream fout("Wines.txt");
	 Wines.push_back(w);
	 std::int64_t lastId;
	 if (Wines.size() != 0)
		 lastId = Wines.back().GetProductId();
	 for (auto& wine : Wines)
	 {
		 if (wine.GetProductId() != lastId)
			 fout << wine.GetProductId() << "|" << wine.GetProductName() << "|" << wine.GetProductDescription() << "|" << wine.GetPrice() << "|" << wine.GetCategory() << "|" << wine.GetYear() << "|" << wine.GetType() << std::endl;
		 else
			 fout << wine.GetProductId() << "|" << wine.GetProductName() << "|" << wine.GetProductDescription() << "|" << wine.GetPrice() << "|" << wine.GetCategory() << "|" << wine.GetYear() << "|" << wine.GetType();
	 }
 }
