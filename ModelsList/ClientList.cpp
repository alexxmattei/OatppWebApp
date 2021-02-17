#include "../HeaderModelsList/ClientList.h"

void ClientList::SetClientList()
{
	std::ifstream fin("Clients.txt");
	while (!fin.eof())
	{
		std::string linie;
		getline(fin, linie);
		Clients.push_back(read.ReadClient(linie));
	}
}

void ClientList::ShowClientList()
{
	std::cout << "The ClientsList is: " << std::endl;
	for (auto& cl : Clients)
	{
		std::cout << cl.GetUserId() << "|" << cl.GetUserRoleId() << "|" << cl.GetUserName() << "|" << cl.GetUserMiddleName() << "|" << cl.GetUserSurname() << "|" << cl.GetUserAge() 
			      << "|" << cl.GetUserBirthDateString() << "|" << cl.GetUserPhone() << "|" << cl.GetUserEmail() << "|" << cl.GetAdress() << "|" << cl.GetPassword() << std::endl;
	}
}

std::list<User> ClientList::GetClients()
{
	return this->Clients;
}

void ClientList::DeleteById(std::int64_t id)
{
	std::list<User> tmp;

	for (auto& cl : Clients)
	{
		if (cl.GetUserId() != id)
		{
			tmp.push_back(cl);

		}
	}
	std::ofstream fout("Clients.txt");
	std::int64_t lastId;
	if (tmp.size() != 0)
		lastId = tmp.back().GetUserId();
	for (auto& cl : tmp)
	{
		if (cl.GetUserId() != lastId)
			fout << cl.GetUserId() << "|" << cl.GetUserRoleId() << "|" << cl.GetUserName() << "|" << cl.GetUserMiddleName() << "|" << cl.GetUserSurname() << "|" << cl.GetUserAge()
			<< "|" << cl.GetUserBirthDate() << "|" << cl.GetUserPhone() << "|" << cl.GetUserEmail() << "|" << cl.GetAdress() << "|" << cl.GetPassword() << std::endl;
		else
			fout << cl.GetUserId() << "|" << cl.GetUserRoleId() << "|" << cl.GetUserName() << "|" << cl.GetUserMiddleName() << "|" << cl.GetUserSurname() << "|" << cl.GetUserAge()
			<< "|" << cl.GetUserBirthDate() << "|" << cl.GetUserPhone() << "|" << cl.GetUserEmail() << "|" << cl.GetAdress() << "|" << cl.GetPassword();
	}

	Clients = tmp;
}

void ClientList::Add(User c)
{
	std::ofstream fout("Clients.txt");
	Clients.push_back(c);
	std::int64_t lastId;
	if (Clients.size() != 0)
		lastId = Clients.back().GetUserId();
	for (auto& cl : Clients)
	{
		if (cl.GetUserId() != lastId)
			fout << cl.GetUserId() << "|" << cl.GetUserRoleId() << "|" << cl.GetUserName() << "|" << cl.GetUserMiddleName() << "|" << cl.GetUserSurname() << "|" << cl.GetUserAge()
			<< "|" << cl.GetUserBirthDate() << "|" << cl.GetUserPhone() << "|" << cl.GetUserEmail() << "|" << cl.GetAdress() << "|" << cl.GetPassword() << std::endl;
		else
			fout << cl.GetUserId() << "|" << cl.GetUserRoleId() << "|" << cl.GetUserName() << "|" << cl.GetUserMiddleName() << "|" << cl.GetUserSurname() << "|" << cl.GetUserAge()
			<< "|" << cl.GetUserBirthDate() << "|" << cl.GetUserPhone() << "|" << cl.GetUserEmail() << "|" << cl.GetAdress() << "|" << cl.GetPassword();
	}
}
