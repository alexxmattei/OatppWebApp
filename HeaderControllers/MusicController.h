#ifndef  MusicController_hpp
#define  MusicController_hpp

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "../HeaderModelsList/MusicList.h"
#include "../DTOs/ProductDto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MusicController : public oatpp::web::server::api::ApiController
{
public:
    MusicController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

     ENDPOINT_ASYNC("GET", "/music", getMusic,
        BODY_DTO(Object<MusicDto>), mscDto) {

        ENDPOINT_ASYNC_INIT(getMusic)

            Action act() override {

            MusicList mscList;
            mscList.SetMusicList();
            std::list<Music> music = mscList.GetmusicList();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto msc = MusicDto::createShared();

            msc->statusCode = 200;
            msc->message = "Music returned corectly";

            msc->productName = "Michael Jackson - Thriller";
            msc->productDescription = "Cel mai bun album al lui MJ";
            msc->productPrice = 99.99;

            oatpp::String json = jsonObjectMapper->writeToString(msc);

            OATPP_LOGD("json", "value='%s'", json->c_str());
            //return createResponse(Status::CODE_200, "OK");
            return _return(controller->createDtoResponse(Status::CODE_200, msc));
        }
    };

     ENDPOINT_INFO(getMusicById) {
         // general
         info->summary = "Get one Music Item by musicId";
         info->addResponse<Object<MusicDto>>(Status::CODE_200, "application/json");
         info->addResponse<String>(Status::CODE_404, "text/plain");

         info->pathParams["musicId"].description = "Music Object Identifier";
     }
     ENDPOINT_ASYNC("GET", "/music/{musicId}", getMusicById, PATH(Int64, musicId, "musicId"),
         BODY_DTO(Object<MusicDto>), mscDto) {

         ENDPOINT_ASYNC_INIT(getMusicById)
             Action act() override {

             MusicList mscList;
             mscList.SetMusicList();
             std::list<Music> music = mscList.GetmusicList();

             auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

             auto msc = MusicDto::createShared();

             auto aid = request->getPathVariable("musicId");

             for (auto& mc : music)
             {
                 auto t_aid = mc.GetProductId();
                 char buffer[65];
                 const char* n_aid = itoa(t_aid, buffer, 10);
                 String s_aid = n_aid;
                 if (s_aid == aid)
                 {
                     msc->productName = mc.GetProductName().c_str();
                     msc->productDescription = mc.GetProductDescription().c_str();
                     msc->productPrice = mc.GetPrice();
                     break;
                 }
             }

             oatpp::String json = jsonObjectMapper->writeToString(msc);

             return _return(controller->createDtoResponse(Status::CODE_200, msc));
         }
     };


     ENDPOINT_INFO(deleteMusicById) {
         // general
         info->summary = "Delete one Music Item by bookId";
         info->addResponse<Object<MusicDto>>(Status::CODE_200, "application/json");
         info->addResponse<String>(Status::CODE_404, "text/plain");

         info->pathParams["musicId"].description = "Music Object Identifier";
     }
     ENDPOINT_ASYNC("DELETE", "/music/{musicId}",
         deleteMusicById,
         PATH(Int64, musicId, "musicId"),
         BODY_DTO(Object<MusicDto>), mscDto) {

         ENDPOINT_ASYNC_INIT(deleteMusicById)
             Action act() override {

             MusicList mscList;
             mscList.SetMusicList();
             std::list<Music> music = mscList.GetmusicList();

             auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

             auto msc = MusicDto::createShared();

             auto aid = request->getPathVariable("musicId");

             for (auto& mc : music)
             {
                 auto t_aid = mc.GetProductId();
                 char buffer[65];
                 const char* n_aid = itoa(t_aid, buffer, 10);
                 String s_aid = n_aid;
                 if (s_aid == aid)
                 {
                     mscList.DeleteById(t_aid);
                     msc->statusCode = 200;
                     msc->message = "The Music Item with the selected Id was successfully deleted!";
                     break;
                 }
             }

             oatpp::String json = jsonObjectMapper->writeToString(msc);

             return _return(controller->createDtoResponse(Status::CODE_200, msc));
         }
     };


};

#include OATPP_CODEGEN_END(ApiController)

#endif 

