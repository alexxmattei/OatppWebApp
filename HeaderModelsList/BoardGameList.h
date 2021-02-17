#pragma once
#include "../Helpers/Reader.h"
#include "../HeaderModels/BoardGame.h"

#include <list>
#include <fstream>

class BoardGameList
{
private:
	std::list<BoardGame> BoardGames;
	Reader read;
public:
	BoardGameList();

	void SetBoardGameList();

	void ShowBoardGameList();

	std::list<BoardGame> GetBoardGames();

	void DeleteById(long id);

	void Add(BoardGame b);
};

