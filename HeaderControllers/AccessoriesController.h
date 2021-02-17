#pragma once

#ifndef  AccessoriesController_hpp
#define  AccessoriesController_hpp

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"
#include "oatpp/core/base/StrBuffer.hpp"
#include "../HeaderModelsList/AccessoryList.h"
#include "../DTOs/ProductDto.hpp"
#include <iomanip>



#include OATPP_CODEGEN_BEGIN(ApiController)

class AccessoriesController : public oatpp::web::server::api::ApiController
{
public:
    AccessoriesController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT_INFO(getAccessories) {
        // general
        info->summary = "Get all Accessories";
        info->addResponse<Object<AccesoryDto>>(Status::CODE_200, "application/json");
        info->addResponse<String>(Status::CODE_404, "text/plain");
    }

    ENDPOINT_ASYNC("GET", "/accessories", getAccessories,
        BODY_DTO(Object<AccesoryDto>), accDto) {

        ENDPOINT_ASYNC_INIT(getAccessories)

            Action act() override {
            AccessoryList AList;
            AList.SetAccessoryList();
            std::list<Accessory> Accessories = AList.GetAccessories();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto Acc = AccesoryDto::createShared();
            Acc->statusCode = 200;
            Acc->message = "Accessories";
         

            Acc->productName = Accessories.front().GetProductName().c_str();
            Acc->productDescription = Accessories.front().GetProductDescription().c_str();
            Acc->productPrice = Accessories.front().GetPrice();
            Acc->category = Accessories.front().GetCategory().c_str();
            Acc->gender = Accessories.front().GetGender().c_str();
         
            oatpp::String json = jsonObjectMapper->writeToString(Acc);

            OATPP_LOGD("json", "value='%s'", json->c_str());
            //return createResponse(Status::CODE_200, "OK");
            return _return(controller->createDtoResponse(Status::CODE_200, Acc));
            }
    };

    ENDPOINT_INFO(getAccessoriesById) {
        // general
        info->summary = "Get one Accessory by accessoryId";
        info->addResponse<Object<AccesoryDto>>(Status::CODE_200, "application/json");
        info->addResponse<String>(Status::CODE_404, "text/plain");
        
        info->pathParams["accessoryId"].description = "Accessory Object Identifier";
    }
    ENDPOINT_ASYNC("GET", "/accessories/{accessoryId}", getAccessoriesById, PATH(Int64, accessoryId, "accessoryId"),
        BODY_DTO(Object<AccesoryDto>), accDto) {

        ENDPOINT_ASYNC_INIT(getAccessoriesById)

            Action act() override {
            AccessoryList AList;
            AList.SetAccessoryList();
            std::list<Accessory> Accessories = AList.GetAccessories();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto Acc = AccesoryDto::createShared();
            auto aid = request->getPathVariable("accessoryId");

            for (auto& a : Accessories)
            {
                auto t_aid = a.GetProductId();
                char buffer[65];
                const char* n_aid = itoa(t_aid, buffer, 10);
                String s_aid = n_aid;
                if (s_aid == aid)
                {
                    Acc->productName = a.GetProductName().c_str();
                    Acc->productDescription = a.GetProductDescription().c_str();
                    Acc->productPrice = a.GetPrice();
                    break;
                }
            }

            oatpp::String json = jsonObjectMapper->writeToString(Acc);

            //OATPP_LOGD("Test", "accessoryId=%d", accessoryId->getValue());
            return _return(controller->createDtoResponse(Status::CODE_200, Acc));
        }
    };


    ENDPOINT_ASYNC("PUT", "/edit-accessories/{accessoryId}/{accessoryName}",
        putAccessoriesById, 
        PATH(Int64, accessoryId, "accessoryId"),
        PATH(String, accesssoryName, "accessoryName"),
        BODY_DTO(Object<AccesoryDto>), accDto) {

        ENDPOINT_ASYNC_INIT(putAccessoriesById)

            Action act() override {
            AccessoryList AList;
            AList.SetAccessoryList();
            std::list<Accessory> Accessories = AList.GetAccessories();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto Acc = AccesoryDto::createShared();
            auto aid = request->getPathVariable("accessoryId");
            auto aname = request->getPathVariable("accessoryName");

            for (auto& a : Accessories)
            {
                auto t_aid = a.GetProductId();
                char buffer[65];
                const char* n_aid = itoa(t_aid, buffer, 10);
                std::string newname = aname->std_str();
                String s_aid = n_aid;
                if (s_aid == aid)
                {
                    a.SetProductName(newname);
                    Acc->productName = a.GetProductName().c_str();
                    Acc->productDescription = a.GetProductDescription().c_str();
                    Acc->productPrice = a.GetPrice();
                    break;
                }
            }

            oatpp::String json = jsonObjectMapper->writeToString(Acc);

            //OATPP_LOGD("Test", "accessoryId=%d", accessoryId->getValue());
            return _return(controller->createDtoResponse(Status::CODE_200, Acc));
        }
    };

    ENDPOINT_INFO(deleteAccessoryById) {
        // general
        info->summary = "Delete one Accessory by accessoryId";
        info->addResponse<Object<AccesoryDto>>(Status::CODE_200, "application/json");
        info->addResponse<String>(Status::CODE_404, "text/plain");

        info->pathParams["accessoryId"].description = "Accessory Object Identifier";
    }
    ENDPOINT_ASYNC("DELETE", "/accessories/{accessoryId}",
        deleteAccessoryById,
        PATH(Int64, accessoryId, "accessoryId"),
        BODY_DTO(Object<AccesoryDto>), accDto) {

        ENDPOINT_ASYNC_INIT(deleteAccessoryById)

            Action act() override {
            AccessoryList AList;
            AList.SetAccessoryList();
            std::list<Accessory> Accessories = AList.GetAccessories();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto Acc = AccesoryDto::createShared();
            auto aid = request->getPathVariable("accessoryId");

            for (auto& a : Accessories)
            {
                auto t_aid = a.GetProductId();
                char buffer[65];
                const char* n_aid = itoa(t_aid, buffer, 10);
                String s_aid = n_aid;
                if (s_aid == aid)
                {
                    AList.DeleteById(t_aid);
                    Acc->statusCode = 200;
                    Acc->message = "Item with the selected Id deleted successfully!";
                    break;
                }
            }

            oatpp::String json = jsonObjectMapper->writeToString(Acc);

            //OATPP_LOGD("Test", "accessoryId=%d", accessoryId->getValue());
            return _return(controller->createDtoResponse(Status::CODE_200, Acc));
        }
    };

    ENDPOINT_INFO(postAccessory) {
        info->summary = "Create new Accessory Object";
        info->addConsumes<Object<AccesoryDto>>("application/json");
        info->addResponse<Object<AccesoryDto>>(Status::CODE_200, "application/json");
    }
    ENDPOINT_ASYNC("POST", "api/create/accessory", postAccessory) {

        ENDPOINT_ASYNC_INIT(postAccessory)

         Action act() override 
        {
            return request->readBodyToDtoAsync<oatpp::Object<AccesoryDto>>(
                controller->getDefaultObjectMapper()
                ).callbackTo(&postAccessory::returnResponse);
        }

        Action returnResponse(const oatpp::Object<AccesoryDto>& body) {
            AccessoryList AList;
            AList.SetAccessoryList();
            
            Accessory newAccessory;

            newAccessory.SetProductId(body->productId);
            newAccessory.SetProductName(body->productName->c_str());
            newAccessory.SetProductDescription(body->productDescription->c_str());
            newAccessory.SetProductPrice(body->productPrice);

            AList.Add(newAccessory);

            return _return(controller->createResponse(Status::CODE_200, "Accessory Created Successfully!"));
        }

    };

};

#include OATPP_CODEGEN_END(ApiController)

#endif 