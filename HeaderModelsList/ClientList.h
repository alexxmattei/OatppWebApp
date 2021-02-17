#pragma once

#include "../Helpers/Reader.h"
#include "../HeaderModels/Client.h"

#include <list>
#include <fstream>


class ClientList
{
private:
	std::list<User> Clients;
	Reader read;
public:
	ClientList()
	{

	}

	void SetClientList();

	void ShowClientList();

	std::list<User> GetClients();

	void DeleteById(std::int64_t id);

	void Add(User c);
};

