#pragma once

#include "../Helpers/Reader.h"
#include "../HeaderModels/Tea.h"

#include <list>
#include <fstream>

class TeaList
{
	std::list<Tea> Teas;
	Reader read;

public:
	TeaList();

	void SetTeaList();

	void ShowTeaList();

	std::list<Tea> GetTeas();

	void DeleteById(long id);

	void Add(Tea t);

};

