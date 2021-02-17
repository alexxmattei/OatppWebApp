#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MagazinesController : public oatpp::web::server::api::ApiController
{
public:
    MagazinesController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT("GET", "/magazines", root) {
        return createResponse(Status::CODE_200, "All Magazines returned corectly!");
    }

    ENDPOINT("GET", "/magazines/{}", getMagazinesById,
        PATH(Int64, magazineId, ""))
    {

    }

};
