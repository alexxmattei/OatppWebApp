#ifndef  MagazinesController_hpp
#define  MagazinesController_hpp

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "../HeaderModelsList/MagazineList.h"
#include "../DTOs/ProductDto.hpp"


#include OATPP_CODEGEN_BEGIN(ApiController)

class MagazinesController : public oatpp::web::server::api::ApiController
{
public:
    MagazinesController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT_ASYNC("GET", "/magazines", getMagazines,
        BODY_DTO(Object<MagazineDto>), mgDto) {

        ENDPOINT_ASYNC_INIT(getMagazines)

            Action act() override {

            MagazineList mList;
            mList.SetMagazineList();
            std::list<Magazine> magazines = mList.GetMagazines();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto mags = MagazineDto::createShared();

            mags->statusCode = 200;
            mags->message = "Magazines returned corectly";

            mags->productName = "Fortune 500";
            mags->productDescription = "Afla care sunt miliardarii lunii!";
            mags->productPrice = 49.99;

            oatpp::String json = jsonObjectMapper->writeToString(mags);

            OATPP_LOGD("json", "value='%s'", json->c_str());
            //return createResponse(Status::CODE_200, "OK");
            return _return(controller->createDtoResponse(Status::CODE_200, mags));
        }
    };

    ENDPOINT_INFO(getMagazineById) {
        // general
        info->summary = "Get one Magazine by magazineId";
        info->addResponse<Object<MagazineDto>>(Status::CODE_200, "application/json");
        info->addResponse<String>(Status::CODE_404, "text/plain");

        info->pathParams["magazineId"].description = "Magazine Object Identifier";
    }
    ENDPOINT_ASYNC("GET", "/magazines/{magazineId}", getMagazineById, PATH(Int64, magazineId, "magazineId"),
        BODY_DTO(Object<MagazineDto>), mgDto) {

        ENDPOINT_ASYNC_INIT(getMagazineById)

            Action act() override {

            MagazineList mList;
            mList.SetMagazineList();
            std::list<Magazine> magazines = mList.GetMagazines();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto mags = MagazineDto::createShared();

            auto aid = request->getPathVariable("magazineId");

            for (auto& m : magazines)
            {
                auto t_aid = m.GetProductId();
                char buffer[65];
                const char* n_aid = itoa(t_aid, buffer, 10);
                String s_aid = n_aid;
                if (s_aid == aid)
                {
                    mags->productName = m.GetProductName().c_str();
                    mags->productDescription = m.GetProductDescription().c_str();
                    mags->productPrice = m.GetPrice();
                    break;
                }
            }

            oatpp::String json = jsonObjectMapper->writeToString(mags);

            return _return(controller->createDtoResponse(Status::CODE_200, mags));
        }
    };

    ENDPOINT_INFO(deleteMagazineById) {
        // general
        info->summary = "Delete one Magazine Item by bookId";
        info->addResponse<Object<MagazineDto>>(Status::CODE_200, "application/json");
        info->addResponse<String>(Status::CODE_404, "text/plain");

        info->pathParams["magazineId"].description = "Magazine Object Identifier";
    }
    ENDPOINT_ASYNC("DELETE", "/magazines/{magazineId}",
        deleteMagazineById,
        PATH(Int64, magazineId, "magazineId"),
        BODY_DTO(Object<MagazineDto>), mgDto) {

        ENDPOINT_ASYNC_INIT(deleteMagazineById)

            Action act() override {

            MagazineList mList;
            mList.SetMagazineList();
            std::list<Magazine> magazines = mList.GetMagazines();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto mags = MagazineDto::createShared();

            auto aid = request->getPathVariable("magazineId");

            for (auto& m : magazines)
            {
                auto t_aid = m.GetProductId();
                char buffer[65];
                const char* n_aid = itoa(t_aid, buffer, 10);
                String s_aid = n_aid;
                if (s_aid == aid)
                {
                    mList.DeleteById(t_aid);
                    mags->statusCode = 200;
                    mags->message = "The Magazine Item with the selected Id was successfully deleted!";
                    break;
                }
            }

            oatpp::String json = jsonObjectMapper->writeToString(mags);

            return _return(controller->createDtoResponse(Status::CODE_200, mags));
        }
    };

};

#include OATPP_CODEGEN_END(ApiController)

#endif 