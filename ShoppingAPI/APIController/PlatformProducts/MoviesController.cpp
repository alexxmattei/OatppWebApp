#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MoviesController : public oatpp::web::server::api::ApiController
{
public:
    MoviesController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT("GET", "/movies", root) {
        return createResponse(Status::CODE_200, "All Movies returned corectly!");
    }

    ENDPOINT("GET", "/movies/{}", getMoviesById,
        PATH(Int64, moviesId, ""))
    {

    }

};
