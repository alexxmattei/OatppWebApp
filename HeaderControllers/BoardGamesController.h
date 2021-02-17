#ifndef  BoardGamesController_hpp
#define  BoardGamesController_hpp

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "../HeaderModelsList/BoardGameList.h"
#include "../DTOs/ProductDto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class BoardGamesController : public oatpp::web::server::api::ApiController
{
public:
    BoardGamesController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT_ASYNC("GET", "/board-games", getBoardGames,
        BODY_DTO(Object<BoardGameDto>), bgDto) {

        ENDPOINT_ASYNC_INIT(getBoardGames)

            Action act() override {
            
            BoardGameList BGList;
            BGList.SetBoardGameList();
            std::list<BoardGame> BoardGames = BGList.GetBoardGames();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto bGame = BoardGameDto::createShared();
            
            bGame->statusCode = 200;
            bGame->message = "BoardGames returned Successfully";
            
            bGame->productName = "Catan";
            bGame->productDescription = "Joc de Societate bazat pe strategie";
            bGame->productPrice = 199.89;

            oatpp::String json = jsonObjectMapper->writeToString(bGame);

            OATPP_LOGD("json", "value='%s'", json->c_str());
            //return createResponse(Status::CODE_200, "OK");
            return _return(controller->createDtoResponse(Status::CODE_200, bGame));
        }
    };

    ENDPOINT_INFO(getBoardGamesById) {
        // general
        info->summary = "Get one BoardGame Item by boardGameId";
        info->addResponse<Object<BoardGameDto>>(Status::CODE_200, "application/json");
        info->addResponse<String>(Status::CODE_404, "text/plain");

        info->pathParams["boardGameId"].description = "BoardGame Object Identifier";
    }
    ENDPOINT_ASYNC("GET", "/board-games/{boardGameId}", getBoardGamesById, PATH(Int64, boardGameId, "boardGameId"),
        BODY_DTO(Object<BoardGameDto>), bgDto) {

        ENDPOINT_ASYNC_INIT(getBoardGamesById)

            Action act() override {

            BoardGameList BGList;
            BGList.SetBoardGameList();
            std::list<BoardGame> BoardGames = BGList.GetBoardGames();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto bGame = BoardGameDto::createShared();

            auto aid = request->getPathVariable("boardGameId");

            for (auto& bg : BoardGames)
            {
                auto t_aid = bg.GetProductId();
                char buffer[65];
                const char* n_aid = itoa(t_aid, buffer, 10);
                String s_aid = n_aid;
                if (s_aid == aid)
                {
                    bGame->productName = bg.GetProductName().c_str();
                    bGame->productDescription = bg.GetProductDescription().c_str();
                    bGame->productPrice = bg.GetPrice();
                    break;
                }
            }

            oatpp::String json = jsonObjectMapper->writeToString(bGame);

            return _return(controller->createDtoResponse(Status::CODE_200, bGame));
        }
    };

    ENDPOINT_INFO(deleteBoardGamesById) {
        // general
        info->summary = "Delete one BoardGame Item by boardGameId";
        info->addResponse<Object<BoardGameDto>>(Status::CODE_200, "application/json");
        info->addResponse<String>(Status::CODE_404, "text/plain");

        info->pathParams["boardGameId"].description = "BoardGame Object Identifier";
    }
    ENDPOINT_ASYNC("DELETE", "/board-games/{boardGameId}",
        deleteBoardGamesById,
        PATH(Int64, boardGameId, "boardGameId"),
        BODY_DTO(Object<BoardGameDto>), bgDto) {

        ENDPOINT_ASYNC_INIT(deleteBoardGamesById)

            Action act() override {

            BoardGameList BGList;
            BGList.SetBoardGameList();
            std::list<BoardGame> BoardGames = BGList.GetBoardGames();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto bGame = BoardGameDto::createShared();

            auto aid = request->getPathVariable("boardGameId");

            for (auto& bg : BoardGames)
            {
                auto t_aid = bg.GetProductId();
                char buffer[65];
                const char* n_aid = itoa(t_aid, buffer, 10);
                String s_aid = n_aid;
                if (s_aid == aid)
                {
                    BGList.DeleteById(t_aid);
                    bGame->statusCode = 200;
                    bGame->message = "The BoardGame with the selected Id was succsessully deleted!";
                    break;
                }
            }

            oatpp::String json = jsonObjectMapper->writeToString(bGame);

            return _return(controller->createDtoResponse(Status::CODE_200, bGame));
        }
    };

};

#include OATPP_CODEGEN_END(ApiController)

#endif 
