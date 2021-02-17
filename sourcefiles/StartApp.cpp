//return JSON response - JSON OBJECT in order to serialize and deserialize DTOs (Data Transfer Objects) and Object Mappers (oatpp.io)
#include "oatpp/network/Server.hpp"
#include "oatpp/web/client/HttpRequestExecutor.hpp"
#include "oatpp/network/tcp/client/ConnectionProvider.hpp"
#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/network/ConnectionProvider.hpp"
#include "oatpp/network/tcp/client/ConnectionProvider.hpp"
#include "oatpp/web/server/HttpConnectionHandler.hpp"
#include "oatpp/web/server/HttpRouter.hpp"
#include "oatpp/parser/json/mapping/Deserializer.hpp"

//codegen for local generated code
#include "oatpp/core/macro/codegen.hpp"

//classes used for runTest localhost 
#include "oatpp/network/Server.hpp"
#include "oatpp/network/tcp/server/ConnectionProvider.hpp"

// Add Controllers for routing 
#include "../HeaderFiles/ApiClient.h"
#include "../HeaderFiles/SyncSimpleExample.h"
#include "../HeaderModels/ShoppingPlatformAppComponent.h"
#include "../HeaderControllers/AccessoriesController.h"
#include "../HeaderControllers/BoardGamesController.h"
#include "../HeaderControllers/BooksController.h"
#include "../HeaderControllers/HomeDecoController.h"
#include "../HeaderControllers/MagazinesController.h"
#include "../HeaderControllers/MoviesController.h"
#include "../HeaderControllers/MusicController.h"
#include "../HeaderControllers/TeasController.h"
#include "../HeaderControllers/WinesController.h"
#include "../HeaderControllers//ClientController.h"

#include "../DTOs/DefaultDto.hpp"

#include <iostream>


std::shared_ptr<oatpp::web::client::RequestExecutor> createOatppExecutor()
{
	OATPP_LOGD("App", "Oat++ native HttpRequestExecutor.");
	auto connectionProvider = oatpp::network::tcp::client::ConnectionProvider::createShared({ "httpbin.org", 80 });
	//return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
	return oatpp::web::client::HttpRequestExecutor::createShared(connectionProvider);
}

class Handler : public oatpp::web::server::HttpRequestHandler
{
private:
	std::shared_ptr<oatpp::data::mapping::ObjectMapper> m_objectMapper;
public:
	std::shared_ptr<OutgoingResponse> handle(const std::shared_ptr<IncomingRequest>& request) override
	{
		auto message = DefaultDto::createShared();
		message->statusCode = 1001; //Shopping Server working succesfully
		message->message = "Hello World! We started our shopping platform";
		return ResponseFactory::createResponse(Status::CODE_200, message, m_objectMapper);
	}

	Handler(const std::shared_ptr<oatpp::data::mapping::ObjectMapper>& objectMapper) : m_objectMapper(objectMapper)
	{

	}
};


void run() {

	ShoppingPlatformAppComponent components;

	OATPP_COMPONENT(std::shared_ptr<oatpp::web::server::HttpRouter>, router);

	auto accessoriesController = std::make_shared<AccessoriesController>();
	accessoriesController->addEndpointsToRouter(router);

	auto boardGamesController = std::make_shared<BoardGamesController>();
	boardGamesController->addEndpointsToRouter(router);

	auto booksController = std::make_shared<BooksController>();
	booksController->addEndpointsToRouter(router);

	auto homeDecoController = std::make_shared<HomeDecoController>();
	homeDecoController->addEndpointsToRouter(router);

	auto magazinesController = std::make_shared <MagazinesController>();
	magazinesController->addEndpointsToRouter(router);

	auto moviesController = std::make_shared<MoviesController>();
	moviesController->addEndpointsToRouter(router);

	auto musicController = std::make_shared<MusicController>();
	musicController->addEndpointsToRouter(router);

	auto teasController = std::make_shared<TeasController>();
	teasController->addEndpointsToRouter(router);

	auto winesController = std::make_shared<WinesController>();
	winesController->addEndpointsToRouter(router);

	auto clientController = std::make_shared<ClientController>();
	clientController->addEndpointsToRouter(router);

	
	OATPP_COMPONENT(std::shared_ptr<oatpp::network::ConnectionHandler>, connectionHandler);

	OATPP_COMPONENT(std::shared_ptr<oatpp::network::ServerConnectionProvider>, connectionProvider);

	oatpp::network::Server server(connectionProvider, connectionHandler);

	OATPP_LOGI("ShoppingPlatform", "Server running on port %s", connectionProvider->getProperty("port").getData());

	server.run();

}


#include "../HeaderModelsList/BookList.h"
#include "../HeaderModelsList/AccessoryList.h"
#include "../HeaderModelsList/BoardGameList.h"
#include "../HeaderModelsList/HomeDecoList.h"
#include "../HeaderModelsList/MagazineList.h"
#include "../HeaderModelsList/MovieList.h"
#include "../HeaderModelsList/TeaList.h"
#include "../HeaderModelsList/MusicList.h"
#include "../HeaderModelsList/ProductList.h"

int main(int argc, const char* argv[]) {


	ProductList pl;
	pl.SetProductList();
	pl.ShowProductsList();
	std::cout << std::endl;

	BookList z;
	z.SetBookList();
	z.ShowBookList();
	std::cout << std::endl;

	AccessoryList a;
	a.SetAccessoryList();
	a.ShowAccessoryList();
	std::cout << std::endl;


	BoardGameList bg;
	bg.SetBoardGameList();
	bg.ShowBoardGameList();
	std::cout << std::endl;


	HomeDecoList hd;
	hd.SetHomeDecoList();
	hd.ShowHomeDecoList();
	std::cout << std::endl;

	MagazineList ml;
	ml.SetMagazineList();
	ml.ShowMagazineList();
	std::cout << std::endl;

	MovieList moviel;
	moviel.SetMovieList();
	moviel.ShowMovieList();
	std::cout << std::endl;

	TeaList tl;
	tl.SetTeaList();
	tl.ShowTeaList();
	std::cout << std::endl;

	MusicList music;
	music.SetMusicList();
	music.ShowMusicList();
	std::cout << std::endl;

	ClientList clist;
	clist.SetClientList();
	clist.ShowClientList();
	std::cout << std::endl;

	oatpp::base::Environment::init();
	run();
	oatpp::base::Environment::destroy();

	return 0;
}
