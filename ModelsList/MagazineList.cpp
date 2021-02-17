#include "../HeaderModelsList/MagazineList.h"

MagazineList::MagazineList()
{

}

void MagazineList::SetMagazineList()
{
	std::ifstream fin("Magazines.txt");
	while (!fin.eof())
	{
		std::string linie;
		getline(fin, linie);
		Magazines.push_back(read.ReadMagazine(linie));
	}
}

void MagazineList::ShowMagazineList()
{
	std::cout << "The MagazineList is: " << std::endl;
	for (auto& m : Magazines)
	{
		std::cout << m.GetProductId() << "|" << m.GetProductName() << "|" << m.GetProductDescription() << "|" << m.GetPrice() << "|" << m.GetLanguage() << "|" << m.GetCategory() << "|" << m.GetNrPages() << std::endl;
	}
}

std::list<Magazine> MagazineList::GetMagazines()
{
	return this->Magazines;
}

void MagazineList::DeleteById(long id)
{
	std::list<Magazine> tmp;

	for (auto& m : Magazines)
	{
		if (m.GetProductId() != id)
		{
			tmp.push_back(m);

		}
	}
	std::ofstream fout("Magazines.txt");
	long lastId;
	if (tmp.size() != 0)
		lastId = tmp.back().GetProductId();
	for (auto& m : tmp)
	{
		if (m.GetProductId() != lastId)
			fout << m.GetProductId() << "|" << m.GetProductName() << "|" << m.GetProductDescription() << "|" << m.GetPrice() << "|" << m.GetLanguage() << "|" << m.GetCategory() << "|" << m.GetNrPages() << std::endl;
		else
			fout << m.GetProductId() << "|" << m.GetProductName() << "|" << m.GetProductDescription() << "|" << m.GetPrice() << "|" << m.GetLanguage() << "|" << m.GetCategory() << "|" << m.GetNrPages();
	}

	Magazines = tmp;
}

inline void MagazineList::Add(Magazine m)
{
	std::ofstream fout("Magazines.txt");
	Magazines.push_back(m);
	std::int64_t lastId;
	if (Magazines.size() != 0)
		lastId = Magazines.back().GetProductId();
	for (auto& mag : Magazines)
	{
		if (mag.GetProductId() != lastId)
			fout << mag.GetProductId() << "|" << mag.GetProductName() << "|" << mag.GetProductDescription() << "|" << mag.GetPrice() << "|" << mag.GetLanguage() << "|" << mag.GetCategory() << "|" << mag.GetNrPages() << std::endl;
		else
			fout << mag.GetProductId() << "|" << mag.GetProductName() << "|" << mag.GetProductDescription() << "|" << mag.GetPrice() << "|" << mag.GetLanguage() << "|" << mag.GetCategory() << "|" << mag.GetNrPages();
	}
}
