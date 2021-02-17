#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class BooksController : public oatpp::web::server::api::ApiController
{
public:
    BooksController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT("GET", "/books", root) {
        return createResponse(Status::CODE_200, "All Books returned corectly!");
    }

    ENDPOINT("GET", "/books/{}", getBooksById,
        PATH(Int64, bookId, ""))
    {

    }

};
