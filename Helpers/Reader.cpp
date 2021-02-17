#include "../Helpers/Reader.h"
#include <sstream>
#include <iomanip>
#include <ctime>
#include <time.h>
#include <locale.h> 

Book Reader::ReadBook(std::string fileLine)
{
	std::regex ws_re("[|]");
	std::vector<std::string> result{
		std::sregex_token_iterator(fileLine.begin(), fileLine.end(), ws_re, -1),{}
	};
	Book temporaryBook;
	for (int index = 0;index < result.size();index++)
	{
		switch (index) {
		case 0:
			temporaryBook.SetProductId(std::atol(result[index].c_str()));
			break;
		case 1:
			temporaryBook.SetProductName(result[index]);
			break;
		case 2:
			temporaryBook.SetProductDescription(result[index]);
			break;
		case 3:
			temporaryBook.SetProductPrice(atof(result[index].c_str()));
			break;
		case 4:
			temporaryBook.SetBookWriter(result[index]);
			break;
		case 5:
			temporaryBook.SetBookLanguage(result[index]);
			break;
		case 6:
			temporaryBook.SetBookCategory(result[index]);
			break;
		case 7:
			std::stringstream intValue(result[index]);
			int number = 0;
			intValue >> number;
			temporaryBook.SetNrOfPages(number);
			break;
		}
	}
	return temporaryBook;
}

Accessory Reader::ReadAccessory(std::string fileLine)
{
	std::regex ws_re("[|]");
	std::vector<std::string> result{
		std::sregex_token_iterator(fileLine.begin(), fileLine.end(), ws_re, -1),{}
	};
	Accessory temporaryAccessory;
	for (int index = 0;index < result.size();index++)
	{
		switch (index) {
		case 0:
			temporaryAccessory.SetProductId(std::atol(result[index].c_str()));
			break;
		case 1:
			temporaryAccessory.SetProductName(result[index]);
			break;
		case 2:
			temporaryAccessory.SetProductDescription(result[index]);
			break;
		case 3:
			temporaryAccessory.SetProductPrice(atof(result[index].c_str()));
			break;
		case 4:
			temporaryAccessory.SetCategory(result[index]);
			break;
		case 5:
			temporaryAccessory.SetGender(result[index]);
			break;
		}
	}
	return temporaryAccessory;
}

BoardGame Reader::ReadBoardGame(std::string fileLine)
{
	std::regex ws_re("[|]");
	std::vector<std::string> result{
		std::sregex_token_iterator(fileLine.begin(), fileLine.end(), ws_re, -1),{}
	};
	BoardGame temporaryBoardGame;
	for (int index = 0;index < result.size();index++)
	{
		switch (index) {
		case 0:
			temporaryBoardGame.SetProductId(std::atol(result[index].c_str()));
			break;
		case 1:
			temporaryBoardGame.SetProductName(result[index]);
			break;
		case 2:
			temporaryBoardGame.SetProductDescription(result[index]);
			break;
		case 3:
			temporaryBoardGame.SetProductPrice(atof(result[index].c_str()));
			break;
		case 4:
			temporaryBoardGame.SetCategory(result[index]);
			break;
		case 5:
			std::stringstream intValue(result[index]);
			int number = 0;
			intValue >> number;
			temporaryBoardGame.SetAge(number);
			break;
		}
	}
	return temporaryBoardGame;
}

HomeDeco Reader::ReadHomeDeco(std::string fileLine)
{
	std::regex ws_re("[|]");
	std::vector<std::string> result{
		std::sregex_token_iterator(fileLine.begin(), fileLine.end(), ws_re, -1),{}
	};
	HomeDeco temporaryHomeDeco;
	for (int index = 0;index < result.size();index++)
	{
		switch (index) {
		case 0:
			temporaryHomeDeco.SetProductId(std::atol(result[index].c_str()));
		case 1:
			temporaryHomeDeco.SetProductName(result[index]);
			break;
		case 2:
			temporaryHomeDeco.SetProductDescription(result[index]);
			break;
		case 3:
			temporaryHomeDeco.SetProductPrice(atof(result[index].c_str()));
			break;
		case 4:
			temporaryHomeDeco.SetObjectType(result[index]);
			break;
		case 5:
			temporaryHomeDeco.SetObjectCollection(result[index]);
			break;
		case 6:
			temporaryHomeDeco.SetObjectColor(result[index]);
			break;
		case 7:
			temporaryHomeDeco.SetObjectMaterial(result[index]);
			break;
		case 8:
			temporaryHomeDeco.SetObjectManufacturer(result[index]);
			break;
		}
	}
	return temporaryHomeDeco;
}

Magazine Reader::ReadMagazine(std::string fileLine)
{
	std::regex ws_re("[|]");
	std::vector<std::string> result{
		std::sregex_token_iterator(fileLine.begin(), fileLine.end(), ws_re, -1),{}
	};
	Magazine temporaryMagazine;
	for (int index = 0;index < result.size();index++)
	{
		switch (index) {
		case 0:
			temporaryMagazine.SetProductId(std::atol(result[index].c_str()));
			break;
		case 1:
			temporaryMagazine.SetProductName(result[index]);
			break;
		case 2:
			temporaryMagazine.SetProductDescription(result[index]);
			break;
		case 3:
			temporaryMagazine.SetProductPrice(atof(result[index].c_str()));
			break;
		case 4:
			temporaryMagazine.SetLanguage(result[index]);
			break;
		case 5:
			temporaryMagazine.SetCategory(result[index]);
			break;
		case 6:
			std::stringstream intValue(result[index]);
			int number = 0;
			intValue >> number;
			temporaryMagazine.SetNeOfPages(number);
			break;
		}
	}
	return temporaryMagazine;
}

Music Reader::ReadMusic(std::string fileLine)
{
	std::regex ws_re("[|]");
	std::vector<std::string> result{
		std::sregex_token_iterator(fileLine.begin(), fileLine.end(), ws_re, -1),{}
	};
	Music temporaryMusic;
	for (int index = 0;index < result.size();index++)
	{
		switch (index) {
		case 0:
			temporaryMusic.SetProductId(std::atol(result[index].c_str()));
		case 1:
			temporaryMusic.SetProductName(result[index]);
			break;
		case 2:
			temporaryMusic.SetProductDescription(result[index]);
			break;
		case 3:
			temporaryMusic.SetProductPrice(atof(result[index].c_str()));
			break;
		case 4:
			temporaryMusic.SetMusicGenre(result[index]);
			break;
		case 5:
			temporaryMusic.SetMusicAlbumName(result[index]);
			break;
		case 6:
			temporaryMusic.SetMusicArtist(result[index]);
			break;
		}
	}
	return temporaryMusic;
}

Wine Reader::ReadWine(std::string fileLine)
{
	std::regex ws_re("[|]");
	std::vector<std::string> result{
		std::sregex_token_iterator(fileLine.begin(), fileLine.end(), ws_re, -1),{}
	};
	Wine temporaryWine;
	for (int index = 1;index < result.size();index++)
	{
		switch (index) {
		case 0:
			temporaryWine.SetProductId(std::atol(result[index].c_str()));
		case 1:
			temporaryWine.SetProductName(result[index]);
			break;
		case 2:
			temporaryWine.SetProductDescription(result[index]);
			break;
		case 3:
			temporaryWine.SetProductPrice(atof(result[index].c_str()));
			break;
		case 4:
			temporaryWine.SetCategory(result[index]);
			break;
		case 6:
			temporaryWine.SetType(result[index]);
			break;
		case 5:
			std::stringstream intValue(result[index]);
			int number = 0;
			intValue >> number;
			temporaryWine.SetYear(number);
			break;
		}
	}
	return temporaryWine;
}

Tea Reader::ReadTea(std::string fileLine)
{
	std::regex ws_re("[|]");
	std::vector<std::string> result{
		std::sregex_token_iterator(fileLine.begin(), fileLine.end(), ws_re, -1),{}
	};
	Tea temporaryTea;
	for (int index = 0;index < result.size();index++)
	{
		switch (index) {
		case 0:
			temporaryTea.SetProductId(std::atol(result[index].c_str()));
		case 1:
			temporaryTea.SetProductName(result[index]);
			break;
		case 2:
			temporaryTea.SetProductDescription(result[index]);
			break;
		case 3:
			temporaryTea.SetProductPrice(atof(result[index].c_str()));
			break;
		case 4:
			temporaryTea.SetCategory(result[index]);
			break;
		case 6:
			temporaryTea.SetOrigin(result[index]);
			break;
		case 5:
			std::stringstream intValue(result[index]);
			int number = 0;
			intValue >> number;
			temporaryTea.SetQuantity(number);
			break;
		}
	}
	return temporaryTea;
}

Movie Reader::ReadMovie(std::string fileLine)
{
	std::regex ws_re("[|]");
	std::vector<std::string> result{
		std::sregex_token_iterator(fileLine.begin(), fileLine.end(), ws_re, -1),{}
	};
	Movie temporaryMovie;
	for (int index = 0;index < result.size();index++)
	{
		switch (index) {
		case 0:
			temporaryMovie.SetProductId(std::atol(result[index].c_str()));
			break;
		case 1:
			temporaryMovie.SetProductName(result[index]);
			break;
		case 2:
			temporaryMovie.SetProductDescription(result[index]);
			break;
		case 3:
			temporaryMovie.SetProductPrice(atof(result[index].c_str()));
			break;
		case 4:
			temporaryMovie.SetMovieFormat(result[index]);
			break;
		case 5:
			temporaryMovie.SetMovieCategory(result[index]);
			break;
		}
		
	}
	return temporaryMovie;
}

User Reader::ReadClient(std::string fileLine)
{
	std::regex ws_re("[|]");
	std::vector<std::string> result{
		std::sregex_token_iterator(fileLine.begin(), fileLine.end(), ws_re, -1),{}
	};
	User temporaryClient;
	for (int index = 0; index < result.size(); index++)
	{
		switch (index) {
		case 0:
			temporaryClient.SetUserId(std::atol(result[index].c_str()));
			break;
		case 1:
			temporaryClient.SetRoleId(std::atol(result[index].c_str()));
			break;
		case 2:
			temporaryClient.SetUserName(result[index]);
			break;
		case 3:
			temporaryClient.SetUserMiddleName(result[index]);
			break;
		case 4:
			temporaryClient.SetUserSurmane(result[index]);
			break;
		case 5: 
		{
			std::stringstream intAge(result[index]);
			int number = 0;
			intAge >> number;
			temporaryClient.SetUserAge(number);
			break; 
		}
		case 6: 
		{   
			std::string bd = result[index].c_str();
			temporaryClient.SetUserBirthdateString(bd);
			break;
		}
		case 7: 
			temporaryClient.SetUserPhoneNumber(result[index]);
			break;
		case 8:
			temporaryClient.SetUserEmail(result[index]);
			break;
		case 9:
			temporaryClient.SetUserAddress(result[index]);
			break;
		case 10:
			temporaryClient.SetUserPassword(result[index]);
			break;
		}
	}
	return temporaryClient;
}

std::list<Product> Reader::ReadAllProducts()
{
	std::list<Product> products;
	std::ifstream fin("Products.txt");
	while (!fin.eof())
	{
		std::string linie;
		getline(fin, linie);
		std::regex ws_re("[|]");
		std::vector<std::string> result{
			std::sregex_token_iterator(linie.begin(), linie.end(), ws_re, -1),{}
		};
		if (result[0] == "Book")
		{

			linie.erase(0, 5);
			Book x = this->ReadBook(linie);
			x.SetProductId(x.GetProductId() + 1000);
			products.push_back(x);
		}
		if (result[0] == "Accessory")
		{
			linie.erase(0, 10);
			Accessory x = this->ReadAccessory(linie);
			x.SetProductId(x.GetProductId() + 2000);
			products.push_back(x);
		}
		if (result[0] == "BoardGame")
		{
			linie.erase(0, 10);
			BoardGame x = this->ReadBoardGame(linie);
			x.SetProductId(x.GetProductId() + 3000);
			products.push_back(x);
		}
		if (result[0] == "HomeDeco")
		{
			linie.erase(0, 9);
			HomeDeco x = this->ReadHomeDeco(linie);
			x.SetProductId(x.GetProductId() + 4000);
			products.push_back(x);
		}
		if (result[0] == "Magazine")
		{
			linie.erase(0, 9);
			Magazine x = this->ReadMagazine(linie);
			x.SetProductId(x.GetProductId() + 5000);
			products.push_back(x);
		}
		if (result[0] == "Movie")
		{
			linie.erase(0, 6);
			Movie x = this->ReadMovie(linie);
			x.SetProductId(x.GetProductId() + 6000);
			products.push_back(x);
		}
		if (result[0] == "Music")
		{
			linie.erase(0, 6);
			Music x = this->ReadMusic(linie);
			x.SetProductId(x.GetProductId() + 7000);
			products.push_back(x);
		}
		if (result[0] == "Tea")
		{
			linie.erase(0, 4);
			Tea x = this->ReadTea(linie);
			x.SetProductId(x.GetProductId() + 8000);
			products.push_back(x);
		}
		if (result[0] == "Wine")
		{
			linie.erase(0, 5);
			Wine x = this->ReadWine(linie);
			x.SetProductId(x.GetProductId() + 9000);
			products.push_back(x);
		}
	}

	return products;
}