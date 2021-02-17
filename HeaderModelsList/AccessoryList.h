#pragma once


#include "../Helpers/Reader.h"
#include "../HeaderModels/Accessory.h"

#include <list>
#include <fstream>

class AccessoryList
{

private:
	std::list<Accessory> Accessories;
	Reader read;
public:
	AccessoryList();

	void SetAccessoryList();

	void ShowAccessoryList();

	std::list<Accessory> GetAccessories();

	void DeleteById(std::int64_t id);

	void Add(Accessory a);
};

