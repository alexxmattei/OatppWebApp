#pragma once

#include "../Helpers/Reader.h"
#include "../HeaderModels/Wine.h"

#include <list>
#include <fstream>

class WineList
{
	std::list<Wine> Wines;
	Reader read;

public:
	WineList();

	void SetWineList();

	void ShowWineList();

	std::list<Wine> GetWines();

	void DeleteById(long id);

	void Add(Wine w);

};

