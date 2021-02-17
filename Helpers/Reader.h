#pragma once
#pragma once
#include <regex>
#include <vector>
#include "../HeaderModels/Accessory.h"
#include "../HeaderModels/BoardGame.h"
#include "../HeaderModels/Book.h"
#include "../HeaderModels/Client.h"
#include "../HeaderModels/HomeDeco.h"
#include "../HeaderModels/Magazine.h"
#include "../HeaderModels/Movie.h"
#include "../HeaderModels/Music.h"
#include "../HeaderModels/Wine.h"
#include "../HeaderModels/Product.h"
#include "../HeaderModels/Tea.h"

class Reader
{
public:
	Book ReadBook(std::string  fileLine);
	Accessory ReadAccessory(std::string  fileLine);
	BoardGame ReadBoardGame(std::string  fileLine);
	HomeDeco ReadHomeDeco(std::string  fileLine);
	Magazine ReadMagazine(std::string  fileLine);
	Movie ReadMovie(std::string  fileLine);
	Music ReadMusic(std::string  fileLine);
	Wine ReadWine(std::string  fileLine);
	Tea ReadTea(std::string  fileLine);
	User ReadClient(std::string  fileLine);
public:
	std::list<Product> ReadAllProducts();
};

