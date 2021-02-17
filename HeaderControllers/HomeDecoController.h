#ifndef  HomeDecoController_hpp
#define  HomeDecoController_hpp

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "../HeaderModelsList/HomeDecoList.h"
#include "../DTOs/ProductDto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class HomeDecoController : public oatpp::web::server::api::ApiController
{
public:
    HomeDecoController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT_ASYNC("GET", "/home-deco", getHomeDeco,
        BODY_DTO(Object<HomeDecoDto>), hdDto) {

        ENDPOINT_ASYNC_INIT(getHomeDeco)

            Action act() override {

            HomeDecoList HDList;
            HDList.SetHomeDecoList();
            std::list<HomeDeco> homedeco = HDList.GetDecoList();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto hDeco = HomeDecoDto::createShared();

            hDeco->statusCode = 200;
            hDeco->message = "Home Deco Items returned Successfully";

            hDeco->productName = "Lampa Hexagonala - Tribeca";
            hDeco->productDescription = "Lumieaza-ti casa si gandurile";
            hDeco->productPrice = 349.99;

            oatpp::String json = jsonObjectMapper->writeToString(hDeco);

            OATPP_LOGD("json", "value='%s'", json->c_str());
            //return createResponse(Status::CODE_200, "OK");
            return _return(controller->createDtoResponse(Status::CODE_200, hDeco));
        }
    };

    ENDPOINT_INFO(getHomeDecoById) {
        // general
        info->summary = "Get one HomeDeco Item by homeDecoId";
        info->addResponse<Object<HomeDecoDto>>(Status::CODE_200, "application/json");
        info->addResponse<String>(Status::CODE_404, "text/plain");

        info->pathParams["homeDecoId"].description = "HomeDeco Object Identifier";
    }
    ENDPOINT_ASYNC("GET", "/home-deco/{homeDecoId}", getHomeDecoById, PATH(Int64, homeDecoId, "homeDecoId"),
        BODY_DTO(Object<HomeDecoDto>), hdDto) {

        ENDPOINT_ASYNC_INIT(getHomeDecoById)

            Action act() override {

            HomeDecoList HDList;
            HDList.SetHomeDecoList();
            std::list<HomeDeco> homedeco = HDList.GetDecoList();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto hDeco = HomeDecoDto::createShared();

            auto aid = request->getPathVariable("homeDecoId");

            for (auto& hm : homedeco)
            {
                auto t_aid = hm.GetProductId();
                char buffer[65];
                const char* n_aid = itoa(t_aid, buffer, 10);
                String s_aid = n_aid;
                if (s_aid == aid)
                {
                    hDeco->productName = hm.GetProductName().c_str();
                    hDeco->productDescription = hm.GetProductDescription().c_str();
                    hDeco->productPrice = hm.GetPrice();
                    break;
                }
            }

            oatpp::String json = jsonObjectMapper->writeToString(hDeco);

            return _return(controller->createDtoResponse(Status::CODE_200, hDeco));
        }
    };

    ENDPOINT_INFO(deleteHomeDecoById) {
        // general
        info->summary = "Delete one HomeDeco Item by bookId";
        info->addResponse<Object<HomeDecoDto>>(Status::CODE_200, "application/json");
        info->addResponse<String>(Status::CODE_404, "text/plain");

        info->pathParams["homeDecoId"].description = "HomeDeco Object Identifier";
    }
    ENDPOINT_ASYNC("DELETE", "/home-deco/{homeDecoId}",
        deleteHomeDecoById,
        PATH(Int64, homeDecoId, "homeDecoId"),
        BODY_DTO(Object<HomeDecoDto>), hdDto) {

        ENDPOINT_ASYNC_INIT(deleteHomeDecoById)
            Action act() override {

            HomeDecoList HDList;
            HDList.SetHomeDecoList();
            std::list<HomeDeco> homedeco = HDList.GetDecoList();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto hDeco = HomeDecoDto::createShared();

            auto aid = request->getPathVariable("homeDecoId");

            for (auto& hm : homedeco)
            {
                auto t_aid = hm.GetProductId();
                char buffer[65];
                const char* n_aid = itoa(t_aid, buffer, 10);
                String s_aid = n_aid;
                if (s_aid == aid)
                {
                    HDList.DeleteById(t_aid);
                    hDeco->statusCode = 200;
                    hDeco->message = "The Home Deco Item with the selected Id was successfully deleted!";
                    break;
                }
            }

            oatpp::String json = jsonObjectMapper->writeToString(hDeco);

            return _return(controller->createDtoResponse(Status::CODE_200, hDeco));
        }
    };

};

#include OATPP_CODEGEN_END(ApiController)

#endif 

