#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class WinesController : public oatpp::web::server::api::ApiController
{
public:
    WinesController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT("GET", "/wine", root) {
        return createResponse(Status::CODE_200, "All Wine Sortiments returned corectly!");
    }

    ENDPOINT("GET", "/wine{}", getWineById,
        PATH(Int64, wineId, ""))
    {

    }

};
