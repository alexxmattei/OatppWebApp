#ifndef  MoviesController_hpp
#define  MoviesController_hpp

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "../HeaderModelsList/MovieList.h"
#include "../DTOs/ProductDto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class MoviesController : public oatpp::web::server::api::ApiController
{
public:
    MoviesController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

      ENDPOINT_ASYNC("GET", "/movies", getMovies,
        BODY_DTO(Object<MovieDto>), mvDto) {

        ENDPOINT_ASYNC_INIT(getMovies)

            Action act() override {

            MovieList mvList;
            mvList.SetMovieList();
            std::list<Movie> movies = mvList.GetMovies();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto mvs = MovieDto::createShared();

            mvs->statusCode = 200;
            mvs->message = "Movies returned corectly";

            mvs->productName = "Inception";
            mvs->productDescription = "Thriller movie starring Cillian Murphy";
            mvs->productPrice = 39.99;

            oatpp::String json = jsonObjectMapper->writeToString(mvs);

            OATPP_LOGD("json", "value='%s'", json->c_str());
            //return createResponse(Status::CODE_200, "OK");
            return _return(controller->createDtoResponse(Status::CODE_200, mvs));
        }
     };

      ENDPOINT_INFO(getMovieById) {
          // general
          info->summary = "Get one Movie by movieId";
          info->addResponse<Object<MovieDto>>(Status::CODE_200, "application/json");
          info->addResponse<String>(Status::CODE_404, "text/plain");

          info->pathParams["movieId"].description = "Movie Object Identifier";
      }
      ENDPOINT_ASYNC("GET", "/movies/{movieId}", getMovieById, PATH(Int64, movieId, "movieId"),
          BODY_DTO(Object<MovieDto>), mvDto) {

          ENDPOINT_ASYNC_INIT(getMovieById)

              Action act() override {

              MovieList mvList;
              mvList.SetMovieList();
              std::list<Movie> movies = mvList.GetMovies();

              auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

              auto mvs = MovieDto::createShared();

              auto aid = request->getPathVariable("movieId");

              for (auto& mv : movies)
              {
                  auto t_aid = mv.GetProductId();
                  char buffer[65];
                  const char* n_aid = itoa(t_aid, buffer, 10);
                  String s_aid = n_aid;
                  if (s_aid == aid)
                  {
                      mvs->productName = mv.GetProductName().c_str();
                      mvs->productDescription = mv.GetProductDescription().c_str();
                      mvs->productPrice = mv.GetPrice();
                      break;
                  }
              }

              oatpp::String json = jsonObjectMapper->writeToString(mvs);

              return _return(controller->createDtoResponse(Status::CODE_200, mvs));
          }
      };

      ENDPOINT_INFO(deleteMovieById) {
          // general
          info->summary = "Delete one Movie Item by bookId";
          info->addResponse<Object<MovieDto>>(Status::CODE_200, "application/json");
          info->addResponse<String>(Status::CODE_404, "text/plain");

          info->pathParams["movieId"].description = "Movie Object Identifier";
      }
      ENDPOINT_ASYNC("DELETE", "/movies/{movieId}",
          deleteMovieById,
          PATH(Int64, movieId, "movieId"),
          BODY_DTO(Object<MovieDto>), mvDto) {

          ENDPOINT_ASYNC_INIT(deleteMovieById)
              Action act() override {

              MovieList mvList;
              mvList.SetMovieList();
              std::list<Movie> movies = mvList.GetMovies();

              auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

              auto mvs = MovieDto::createShared();

              auto aid = request->getPathVariable("movieId");

              for (auto& mv : movies)
              {
                  auto t_aid = mv.GetProductId();
                  char buffer[65];
                  const char* n_aid = itoa(t_aid, buffer, 10);
                  String s_aid = n_aid;
                  if (s_aid == aid)
                  {
                      mvList.DeleteById(t_aid);
                      mvs->statusCode = 200;
                      mvs->message = "The Movie Item with the selected Id was successfully deleted!";
                      break;
                  }
              }

              oatpp::String json = jsonObjectMapper->writeToString(mvs);

              return _return(controller->createDtoResponse(Status::CODE_200, mvs));
          }
      };

};

#include OATPP_CODEGEN_END(ApiController)

#endif 
