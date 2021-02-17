#include "../HeaderModelsList/BoardGameList.h"

BoardGameList::BoardGameList()
{

}

void BoardGameList::SetBoardGameList()
{
	std::ifstream fin("BoardGames.txt");
	while (!fin.eof())
	{
		std::string linie;
		getline(fin, linie);
		BoardGames.push_back(read.ReadBoardGame(linie));
	}
}

void BoardGameList::ShowBoardGameList()
{
	std::cout << "The BoardGameList is: " << std::endl;
	for (auto& bg : BoardGames)
	{
		std::cout << bg.GetProductId() << "|" << bg.GetProductName() << "|" << bg.GetProductDescription() << "|" << bg.GetPrice() << "|" << bg.GetCategory() << "|" << bg.GetAge() << std::endl;
	}
}

std::list<BoardGame> BoardGameList::GetBoardGames()
{
	return this->BoardGames;
}

void BoardGameList::DeleteById(long id)
{
	std::list<BoardGame> tmp;

	for (auto& bg : BoardGames)
	{
		if (bg.GetProductId() != id)
		{
			tmp.push_back(bg);

		}
	}
	std::ofstream fout("BoardGames.txt");
	long lastId;
	if (tmp.size() != 0)
		lastId = tmp.back().GetProductId();
	for (auto& bg : tmp)
	{
		if (bg.GetProductId() != lastId)
			fout << bg.GetProductId() << "|" << bg.GetProductName() << "|" << bg.GetProductDescription() << "|" << bg.GetPrice() << "|" << bg.GetCategory() << "|" << bg.GetAge() << std::endl;
		else
			fout << bg.GetProductId() << "|" << bg.GetProductName() << "|" << bg.GetProductDescription() << "|" << bg.GetPrice() << "|" << bg.GetCategory() << "|" << bg.GetAge();
	}

	BoardGames = tmp;
}

void BoardGameList::Add(BoardGame b)
{
	std::ofstream fout("BoardGames.txt");
	BoardGames.push_back(b);
	std::int64_t lastId;
	if (BoardGames.size() != 0)
		lastId = BoardGames.back().GetProductId();
	for (auto& bg : BoardGames)
	{
		if (bg.GetProductId() != lastId)
			fout << bg.GetProductId() << "|" << bg.GetProductName() << "|" << bg.GetProductDescription() << "|" << bg.GetPrice() << "|" << bg.GetCategory() << "|" << bg.GetAge() << std::endl;
		else
			fout << bg.GetProductId() << "|" << bg.GetProductName() << "|" << bg.GetProductDescription() << "|" << bg.GetPrice() << "|" << bg.GetCategory() << "|" << bg.GetAge();
	}

}
