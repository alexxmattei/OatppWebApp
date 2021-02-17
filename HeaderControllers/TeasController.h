#ifndef  TeasController_hpp
#define  TeasController_hpp

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "../HeaderModelsList/TeaList.h"
#include "../DTOs/ProductDto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class TeasController : public oatpp::web::server::api::ApiController
{
public:
    TeasController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT_ASYNC("GET", "/teas", getTeas,
        BODY_DTO(Object<TeaDto>), tDto) {

        ENDPOINT_ASYNC_INIT(getTeas)

            Action act() override {

            TeaList tList;
            tList.SetTeaList();
            std::list<Tea> teas = tList.GetTeas();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto t = TeaDto::createShared();

            t->statusCode = 200;
            t->message = "Teas returned corectly";

            t->productName = "Jasmine";
            t->productDescription = "Relaxing Jasmine tea, to be infused for 5-7 minutes";
            t->productPrice = 12.99;

            oatpp::String json = jsonObjectMapper->writeToString(t);

            OATPP_LOGD("json", "value='%s'", json->c_str());
            //return createResponse(Status::CODE_200, "OK");
            return _return(controller->createDtoResponse(Status::CODE_200, t));
        }
    };

    ENDPOINT_INFO(getTeaById) {
        // general
        info->summary = "Get one Tea Item by teaId";
        info->addResponse<Object<TeaDto>>(Status::CODE_200, "application/json");
        info->addResponse<String>(Status::CODE_404, "text/plain");

        info->pathParams["teaId"].description = "Tea Object Identifier";
    }
    ENDPOINT_ASYNC("GET", "/teas/{teaId}", getTeaById, PATH(Int64, teaId, "teaId"),
        BODY_DTO(Object<TeaDto>), tDto) {

        ENDPOINT_ASYNC_INIT(getTeaById)
            Action act() override {

            TeaList tList;
            tList.SetTeaList();
            std::list<Tea> teas = tList.GetTeas();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto t = TeaDto::createShared();

            auto aid = request->getPathVariable("teaId");

            for (auto& tt : teas)
            {
                auto t_aid = tt.GetProductId();
                char buffer[65];
                const char* n_aid = itoa(t_aid, buffer, 10);
                String s_aid = n_aid;
                if (s_aid == aid)
                {
                    t->productName = tt.GetProductName().c_str();
                    t->productDescription = tt.GetProductDescription().c_str();
                    t->productPrice = tt.GetPrice();
                    break;
                }
            }

            oatpp::String json = jsonObjectMapper->writeToString(t);

            return _return(controller->createDtoResponse(Status::CODE_200, t));
        }
    };


    ENDPOINT_INFO(deleteTeaById) {
        // general
        info->summary = "Delete one Tea Item by bookId";
        info->addResponse<Object<TeaDto>>(Status::CODE_200, "application/json");
        info->addResponse<String>(Status::CODE_404, "text/plain");

        info->pathParams["teaId"].description = "Tea Object Identifier";
    }
    ENDPOINT_ASYNC("DELETE", "/teas/{teaId}",
        deleteTeaById,
        PATH(Int64, musicId, "musicId"),
        BODY_DTO(Object<TeaDto>), tDto) {

        ENDPOINT_ASYNC_INIT(deleteTeaById)
            Action act() override {

            TeaList tList;
            tList.SetTeaList();
            std::list<Tea> teas = tList.GetTeas();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto t = TeaDto::createShared();

            auto aid = request->getPathVariable("teaId");

            for (auto& tt : teas)
            {
                auto t_aid = tt.GetProductId();
                char buffer[65];
                const char* n_aid = itoa(t_aid, buffer, 10);
                String s_aid = n_aid;
                if (s_aid == aid)
                {
                    tList.DeleteById(t_aid);
                    t->statusCode = 200;
                    t->message = "The Tea Item with the selected Id was successfully deleted!";
                    break;
                }
            }

            oatpp::String json = jsonObjectMapper->writeToString(t);

            return _return(controller->createDtoResponse(Status::CODE_200, t));
        }
    };


};

#include OATPP_CODEGEN_END(ApiController)

#endif 
