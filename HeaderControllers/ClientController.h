#ifndef  ClientController_hpp
#define  ClientController_hpp

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "../HeaderModelsList/ClientList.h"
#include "../DTOs/ClientDto.hpp"
#include "../HeaderModels/Client.h"

#include OATPP_CODEGEN_BEGIN(ApiController)

using namespace oatpp::web::server::handler;

class ClientController : public oatpp::web::server::api::ApiController
{
public:
    ClientController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {
        setDefaultAuthorizationHandler(std::make_shared<BasicAuthorizationHandler>("my-realm"));
    }

    ENDPOINT_ASYNC("GET", "/", getClients,
        BODY_DTO(Object<ClientDto>), clientDto) {

        ENDPOINT_ASYNC_INIT(getClients)

            Action act() override {

            ClientList clList;
            clList.SetClientList();
            std::list<User> homedeco = clList.GetClients();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto cl = ClientDto::createShared();

            cl->statusCode = 200;
            cl->message = "All registered Users returned successfully";

            cl->clientId = 1001;
            cl->roleId = 1;
            cl->userName = "Alexandru";
            cl->userSurname = "Matei";
            cl->userAge = 20;
            cl->userBirthdate = "10 05 2020";
            cl->userPhoneNumber = "0723217130";
            cl->userEmail = "alexxmattei@gmail.com";
            cl->userAddress = "Strada Oatului Numarul 30 de commituri";
            cl->userPassword = "******";

            oatpp::String json = jsonObjectMapper->writeToString(cl);

            OATPP_LOGD("json", "value='%s'", json->c_str());
            //return createResponse(Status::CODE_200, "OK");
            return _return(controller->createDtoResponse(Status::CODE_200, cl));
        }
    };

  
    ENDPOINT_ASYNC("GET", "/clients/{clientId}", getClientById,
        AUTHORIZATION(std::shared_ptr<DefaultBasicAuthorizationObject>, authObject),
        PATH(Int64, clientId, "clientId"),
        BODY_DTO(Object<ClientDto>), clientDto) {

        ENDPOINT_ASYNC_INIT(getClientById)

            Action act() override {

            ClientList clList;
            clList.SetClientList();
            std::list<User> reg_users = clList.GetClients();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto cl = ClientDto::createShared();
            auto cid = request->getPathVariable("clientId");

            for (auto& spClient : reg_users)
            {
                auto t_aid = spClient.GetUserId();
                char buffer[65];
                const char* n_aid = itoa(t_aid, buffer, 10);
                oatpp::String oat_id = n_aid;

                if (oat_id == cid)
                {
                    cl->clientId = spClient.GetUserId();
                    cl->userName = spClient.GetUserName().c_str();
                    cl->userMiddleName = spClient.GetUserMiddleName().c_str();
                    cl->userSurname = spClient.GetUserSurname().c_str();
                    cl->userEmail = spClient.GetUserEmail().c_str();
                    cl->userAddress = spClient.GetAdress().c_str();
                    cl->userPhoneNumber = spClient.GetUserPhone().c_str();
                    cl->userAge = spClient.GetUserAge();
                    cl->userBirthdate = spClient.GetUserBirthDateString().c_str();
                    cl->userPassword = spClient.GetPassword().c_str();
                }
            }

            oatpp::String json = jsonObjectMapper->writeToString(cl);

            OATPP_LOGD("json", "value='%s'", json->c_str());
            //return createResponse(Status::CODE_200, "OK");
            return _return(controller->createDtoResponse(Status::CODE_200, cl));
        }
    };

     ENDPOINT_INFO(createUser) {
         info->summary = "Example. Documenting path params for async APIs.";
         info->addResponse<String>(Status::CODE_200, "text/plain");
         info->pathParams.add<String>("clientId").description = "Id-ul noului client"; // 0, 1, 2, ...
         info->pathParams.add<String>("roleId").description = "Id-ul rolului sau"; // Admin, Seller, User
     }
     ENDPOINT_ASYNC("POST", "/api/create-account/{clientId}/{roleId}", createUser) {

         ENDPOINT_ASYNC_INIT(createUser)

             Action act() override {
             auto cid = request->getPathVariable("clientId");
             auto rid = request->getPathVariable("roleId");
             OATPP_ASSERT_HTTP(cid && rid, Status::CODE_400, "Id-urile nu ar trebuie sa fie nule!");
             auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

             const char* newId = cid->c_str();
             const char* newRole = rid->c_str();
             int numId;
             int roleId;

             sscanf(newId, "%d", &numId);
             sscanf(newRole, "%d", &roleId);

             ClientList clList;
             clList.SetClientList();
             
             User newClient;

             newClient.SetUserId(numId);
             newClient.SetRoleId(roleId);

             clList.Add(newClient);


             return _return(controller->createResponse(Status::CODE_200, cid));
         }

     };


};

#include OATPP_CODEGEN_END(ApiController)

#endif 

