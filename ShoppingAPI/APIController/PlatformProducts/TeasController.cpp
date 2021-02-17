#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TeasController : public oatpp::web::server::api::ApiController
{
public:
    TeasController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT("GET", "/products", root) {
        return createResponse(Status::CODE_200, "All Products currently stored returned corectly!");
    }

    ENDPOINT("GET", "/products{}", getProductsById,
        PATH(Int64, productId, ""))
    {

    }

};
