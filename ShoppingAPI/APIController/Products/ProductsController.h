#ifndef  ProductsController_hpp
#define  ProductsController_hpp

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class ProductsController : public oatpp::web::server::api::ApiController
{
public:
    ProductsController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT("GET", "/products", root) {
        return createResponse(Status::CODE_200, "All Products in store returned corectly!");
    }

    ENDPOINT("GET", "/products{}", getProductsById,
        PATH(Int64, productsId, ""))
    {

    }

};

#include OATPP_CODEGEN_END(ApiController)

#endif 

