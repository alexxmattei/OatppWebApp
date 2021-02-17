#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "../DTOs/ProductDto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class AccessoriesController : public oatpp::web::server::api::ApiController
{
public:
    AccessoriesController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT("GET", "/accessories", root) {
        return createResponse(Status::CODE_200, "All accessories returned correctly!");
    }

    ENDPOINT("GET", "/accessories/{}", getAccessoriesById,
        PATH(Int64, accessoryId, ""))
    {

    }

};


