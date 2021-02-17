#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class HomeDecoController : public oatpp::web::server::api::ApiController
{
public:
    HomeDecoController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT("GET", "/home-deco", root) {
        return createResponse(Status::CODE_200, "All HomeDeco Items returned corectly!");
    }

    ENDPOINT("GET", "/home-deco/{}", getHomeDecoById,
        PATH(Int64, homeDecoId, ""))
    {

    }

};
