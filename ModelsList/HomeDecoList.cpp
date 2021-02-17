#include "../HeaderModelsList/HomeDecoList.h"

HomeDecoList::HomeDecoList()
{

}

void HomeDecoList::SetHomeDecoList()
{
	std::ifstream fin("HomeDeco.txt");
	while (!fin.eof())
	{
		std::string linie;
		getline(fin, linie);
		DecoList.push_back(read.ReadHomeDeco(linie));
	}
}

void HomeDecoList::ShowHomeDecoList()
{
	std::cout << "The HomeDecoList is: " << std::endl;
	for (auto& hd : DecoList)
	{
		std::cout << hd.GetProductId() << "|" << hd.GetProductName() << "|" << hd.GetProductDescription() << "|" << hd.GetPrice() << "|" << hd.GetObjectType() << "|" << hd.GetObjectCollection() << "|" << hd.GetObjectColor() << "|" << hd.GetObjectMaterial() << "|" << hd.GetObjectManufacturer() << std::endl;
	}
}

std::list<HomeDeco> HomeDecoList::GetDecoList()
{
	return this->DecoList;
}

void HomeDecoList::DeleteById(long id)
{
	std::list<HomeDeco> tmp;

	for (auto& hd : DecoList)
	{
		if (hd.GetProductId() != id)
		{
			tmp.push_back(hd);

		}
	}
	std::ofstream fout("HomeDeco.txt");
	long lastId;
	if (tmp.size() != 0)
		lastId = tmp.back().GetProductId();
	for (auto& hd : tmp)
	{
		if (hd.GetProductId() != lastId)
			fout << hd.GetProductId() << "|" << hd.GetProductName() << "|" << hd.GetProductDescription() << "|" << hd.GetPrice() << "|" << hd.GetObjectType() << "|" << hd.GetObjectCollection() << "|" << hd.GetObjectColor() << "|" << hd.GetObjectMaterial() << "|" << hd.GetObjectManufacturer() << std::endl;
		else
			fout << hd.GetProductId() << "|" << hd.GetProductName() << "|" << hd.GetProductDescription() << "|" << hd.GetPrice() << "|" << hd.GetObjectType() << "|" << hd.GetObjectCollection() << "|" << hd.GetObjectColor() << "|" << hd.GetObjectMaterial() << "|" << hd.GetObjectManufacturer();
	}

	DecoList = tmp;
}

void HomeDecoList::Add(HomeDeco h)
{
	std::ofstream fout("HomeDeco.txt");
	DecoList.push_back(h);
	std::int64_t lastId;
	if (DecoList.size() != 0)
		lastId = DecoList.back().GetProductId();
	for (auto& hd : DecoList)
	{
		if (hd.GetProductId() != lastId)
			fout << hd.GetProductId() << "|" << hd.GetProductName() << "|" << hd.GetProductDescription() << "|" << hd.GetPrice() << "|" << hd.GetObjectType() << "|" << hd.GetObjectCollection() << "|" << hd.GetObjectColor() << "|" << hd.GetObjectMaterial() << "|" << hd.GetObjectManufacturer() << std::endl;
		else
			fout << hd.GetProductId() << "|" << hd.GetProductName() << "|" << hd.GetProductDescription() << "|" << hd.GetPrice() << "|" << hd.GetObjectType() << "|" << hd.GetObjectCollection() << "|" << hd.GetObjectColor() << "|" << hd.GetObjectMaterial() << "|" << hd.GetObjectManufacturer();
	}
}
