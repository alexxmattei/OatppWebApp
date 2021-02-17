#pragma once

#include "../Helpers/Reader.h"
#include "../HeaderModels/Magazine.h"

#include <list>
#include <fstream>

class MagazineList
{
private:
	std::list<Magazine> Magazines;
	Reader read;
public:
	MagazineList();

	void SetMagazineList();

	void ShowMagazineList();

	std::list<Magazine> GetMagazines();

	void DeleteById(long id);

	void Add(Magazine m);


};

