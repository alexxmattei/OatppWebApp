#ifndef  WinesController_hpp
#define  WinesController_hpp

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "../HeaderModelsList/WineList.h"
#include "../DTOs/ProductDto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class WinesController : public oatpp::web::server::api::ApiController
{
public:
    WinesController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT_ASYNC("GET", "/wines", getWines,
        BODY_DTO(Object<WineDto>), wnDto) {

        ENDPOINT_ASYNC_INIT(getWines)

            Action act() override {

            WineList wnList;
            wnList.SetWineList();
            std::list<Wine> wines = wnList.GetWines();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto wn = WineDto::createShared();

            wn->statusCode = 200;
            wn->message = "Wines returned corectly";

            wn->productName = "Busuioaca de Bohotin";
            wn->productDescription = "O amintire creata in stil Moldovenesc in Vama Veche";
            wn->productPrice = 13.05;

            oatpp::String json = jsonObjectMapper->writeToString(wn);

            OATPP_LOGD("json", "value='%s'", json->c_str());
            //return createResponse(Status::CODE_200, "OK");
            return _return(controller->createDtoResponse(Status::CODE_200, wn));
        }
    };


    ENDPOINT_INFO(getWineById) {
        // general
        info->summary = "Get one Wine Item by wineId";
        info->addResponse<Object<WineDto>>(Status::CODE_200, "application/json");
        info->addResponse<String>(Status::CODE_404, "text/plain");

        info->pathParams["wineId"].description = "Wine Object Identifier";
    }
    ENDPOINT_ASYNC("GET", "/wines/{wineId}", getWineById, PATH(Int64, wineId, "wineId"),
        BODY_DTO(Object<WineDto>), wnDto) {

        ENDPOINT_ASYNC_INIT(getWineById)

            Action act() override {

            WineList wnList;
            wnList.SetWineList();
            std::list<Wine> wines = wnList.GetWines();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto wn = WineDto::createShared();

            auto aid = request->getPathVariable("wineId");

            for (auto& w : wines)
            {
                auto t_aid = w.GetProductId();
                char buffer[65];
                const char* n_aid = itoa(t_aid, buffer, 10);
                String s_aid = n_aid;
                if (s_aid == aid)
                {
                    wn->productName = w.GetProductName().c_str();
                    wn->productDescription = w.GetProductDescription().c_str();
                    wn->productPrice = w.GetPrice();
                    break;
                }
            }

            oatpp::String json = jsonObjectMapper->writeToString(wn);

            return _return(controller->createDtoResponse(Status::CODE_200, wn));
        }
    };

    ENDPOINT_INFO(deleteWineById) {
        // general
        info->summary = "Delete one Tea Item by bookId";
        info->addResponse<Object<WineDto>>(Status::CODE_200, "application/json");
        info->addResponse<String>(Status::CODE_404, "text/plain");

        info->pathParams["wineId"].description = "Wine Object Identifier";
    }
    ENDPOINT_ASYNC("DELETE", "/wines/{wineId}",
        deleteWineById,
        PATH(Int64, wineId, "wineId"),
        BODY_DTO(Object<wineDto>), wnDto) {

        ENDPOINT_ASYNC_INIT(deleteWineById)

            Action act() override {

            WineList wnList;
            wnList.SetWineList();
            std::list<Wine> wines = wnList.GetWines();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto wn = WineDto::createShared();

            auto aid = request->getPathVariable("wineId");

            for (auto& w : wines)
            {
                auto t_aid = w.GetProductId();
                char buffer[65];
                const char* n_aid = itoa(t_aid, buffer, 10);
                String s_aid = n_aid;
                if (s_aid == aid)
                {
                    wnList.DeleteById(t_aid);
                    wn->statusCode = 200;
                    wn->message = "The Wine Item with the selected Id was successfully deleted!";
                    break;
                }
            }

            oatpp::String json = jsonObjectMapper->writeToString(wn);

            return _return(controller->createDtoResponse(Status::CODE_200, wn));
        }
    };

};

#include OATPP_CODEGEN_END(ApiController)

#endif 

