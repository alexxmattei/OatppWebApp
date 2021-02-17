#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class BoardGamesController : public oatpp::web::server::api::ApiController
{
public:
    BoardGamesController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT("GET", "/board-games", root) {
        return createResponse(Status::CODE_200, "All BoardGames returned corectly!");
    }

    ENDPOINT("GET", "/board-games/{}", getBoardGamesById,
        PATH(Int64, boardGameId, ""))
    {

    }

};
