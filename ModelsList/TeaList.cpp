#include "../HeaderModelsList/TeaList.h"

TeaList::TeaList()
{

}

void TeaList::SetTeaList()
{
	std::ifstream fin("Tea.txt");
	while (!fin.eof())
	{
		std::string linie;
		getline(fin, linie);
		Teas.push_back(read.ReadTea(linie));
	}
}

void TeaList::ShowTeaList()
{
	std::cout << "The TeaList is: " << std::endl;
	for (auto& tea : Teas)
	{
		std::cout << tea.GetProductId() << "|" << tea.GetProductName() << "|" << tea.GetProductDescription() << "|" << tea.GetPrice() << "|" << tea.GetCategory() << "|" << tea.GetOrigin() << std::endl;
	}
}

std::list<Tea> TeaList::GetTeas()
{
	return this->Teas;
}

void TeaList::DeleteById(long id)
{
	std::list<Tea> tmp;

	for (auto& tea : Teas)
	{
		if (tea.GetProductId() != id)
		{
			tmp.push_back(tea);

		}
	}
	std::ofstream fout("Tea.txt");
	long lastId;
	if (tmp.size() != 0)
		lastId = tmp.back().GetProductId();
	for (auto& tea : tmp)
	{
		if (tea.GetProductId() != lastId)
			fout << tea.GetProductId() << "|" << tea.GetProductName() << "|" << tea.GetProductDescription() << "|" << tea.GetPrice() << "|" << tea.GetCategory() << "|" << tea.GetOrigin() << std::endl;
		else
			fout << tea.GetProductId() << "|" << tea.GetProductName() << "|" << tea.GetProductDescription() << "|" << tea.GetPrice() << "|" << tea.GetCategory() << "|" << tea.GetOrigin();
	}

	Teas = tmp;
}

void TeaList::Add(Tea t)
{
	std::ofstream fout("Tea.txt");
	Teas.push_back(t);
	std::int64_t lastId;
	if (Teas.size() != 0)
		lastId = Teas.back().GetProductId();
	for (auto& tea : Teas)
	{
		if (tea.GetProductId() != lastId)
			fout << tea.GetProductId() << "|" << tea.GetProductName() << "|" << tea.GetProductDescription() << "|" << tea.GetPrice() << "|" << tea.GetCategory() << "|" << tea.GetOrigin() << std::endl;
		else
			fout << tea.GetProductId() << "|" << tea.GetProductName() << "|" << tea.GetProductDescription() << "|" << tea.GetPrice() << "|" << tea.GetCategory() << "|" << tea.GetOrigin();
	}
}
