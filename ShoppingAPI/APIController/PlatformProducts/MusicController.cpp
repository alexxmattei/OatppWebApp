#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MusicController : public oatpp::web::server::api::ApiController
{
public:
    MusicController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT("GET", "/music", root) {
        return createResponse(Status::CODE_200, "All Music returned corectly!");
    }

    ENDPOINT("GET", "/music/{}", getMusicById,
        PATH(Int64, musicId, ""))
    {

    }

};
