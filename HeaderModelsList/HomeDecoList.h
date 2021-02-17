#pragma once


#include "../Helpers/Reader.h"
#include "../HeaderModels/HomeDeco.h"

#include <list>
#include <fstream>

class HomeDecoList
{
private:
	std::list<HomeDeco> DecoList;
	Reader read;
public:
	HomeDecoList();

	void SetHomeDecoList();

	void ShowHomeDecoList();

	std::list<HomeDeco> GetDecoList();

	void DeleteById(long id);

	void Add(HomeDeco h);


};

