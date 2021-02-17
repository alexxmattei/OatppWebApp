#ifndef  BooksController_hpp
#define  BooksController_hpp

#include "oatpp/web/server/api/ApiController.hpp"
#include "oatpp/web/server/api/Endpoint.hpp"

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/macro/component.hpp"

#include "oatpp/parser/json/mapping/ObjectMapper.hpp"

#include "../HeaderModelsList/BookList.h"
#include "../DTOs/ProductDto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiController)

class BooksController : public oatpp::web::server::api::ApiController
{
public:
    BooksController(OATPP_COMPONENT(std::shared_ptr<ObjectMapper>, objectMapper)) : oatpp::web::server::api::ApiController(objectMapper)
    {}

    ENDPOINT_ASYNC("GET", "/books", getBooks,
        BODY_DTO(Object<BookDto>), bookDto) {

        ENDPOINT_ASYNC_INIT(getBooks)

            Action act() override {

            BookList bookList;
            bookList.SetBookList();
            std::list<Book> books = bookList.GetBooks();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto bk = BookDto::createShared();

            bk->statusCode = 200;
            bk->message = "Books returned Successfully";

            bk->productName = "Mandrie si Prejudecata";
            bk->productDescription = "Afla de ce toata lumea il iubeste pe Mr. Darcy";
            bk->productPrice = 29.99;

            oatpp::String json = jsonObjectMapper->writeToString(bk);

            OATPP_LOGD("json", "value='%s'", json->c_str());
            //return createResponse(Status::CODE_200, "OK");
            return _return(controller->createDtoResponse(Status::CODE_200, bk));
        }
    };


    ENDPOINT_INFO(getBookById) {
        // general
        info->summary = "Get one Book by bookId";
        info->addResponse<Object<BookDto>>(Status::CODE_200, "application/json");
        info->addResponse<String>(Status::CODE_404, "text/plain");

        info->pathParams["bookId"].description = "Book Object Identifier";
    }
    ENDPOINT_ASYNC("GET", "/books/{bookId}", getBookById, PATH(Int64, bookId, "bookId"),
        BODY_DTO(Object<BookDto>), bgDto) {

        ENDPOINT_ASYNC_INIT(getBookById)

            Action act() override {

            BookList bookList;
            bookList.SetBookList();
            std::list<Book> books = bookList.GetBooks();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto bk = BookDto::createShared();

            auto aid = request->getPathVariable("bookId");

            for (auto& b : books)
            {
                auto t_aid = b.GetProductId();
                char buffer[65];
                const char* n_aid = itoa(t_aid, buffer, 10);
                String s_aid = n_aid;
                if (s_aid == aid)
                {
                    bk->productName = b.GetProductName().c_str();
                    bk->productDescription = b.GetProductDescription().c_str();
                    bk->productPrice = b.GetPrice();
                    break;
                }
            }

            oatpp::String json = jsonObjectMapper->writeToString(bk);

            //OATPP_LOGD("Test", "accessoryId=%d", accessoryId->getValue());
            return _return(controller->createDtoResponse(Status::CODE_200, bk));
        }
    };
    
    ENDPOINT_INFO(deleteBookById) {
        // general
        info->summary = "Delete one Book Item by bookId";
        info->addResponse<Object<BookDto>>(Status::CODE_200, "application/json");
        info->addResponse<String>(Status::CODE_404, "text/plain");

        info->pathParams["boardGameId"].description = "BoardGame Object Identifier";
    }
    ENDPOINT_ASYNC("DELETE", "/books/{bookId}",
        deleteBookById,
        PATH(Int64, bookId, "bookId"),
        BODY_DTO(Object<BookDto>), bgDto) {

        ENDPOINT_ASYNC_INIT(deleteBookById)


            Action act() override {

            BookList bookList;
            bookList.SetBookList();
            std::list<Book> books = bookList.GetBooks();

            auto jsonObjectMapper = oatpp::parser::json::mapping::ObjectMapper::createShared();

            auto bk = BookDto::createShared();

            auto aid = request->getPathVariable("bookId");

            for (auto& b : books)
            {
                auto t_aid = b.GetProductId();
                char buffer[65];
                const char* n_aid = itoa(t_aid, buffer, 10);
                String s_aid = n_aid;
                if (s_aid == aid)
                {
                    bookList.DeleteById(t_aid);
                    bk->statusCode = 200;
                    bk->message = "The Book with the selected Id was successfully deleted!";
                    break;
                }
            }

            oatpp::String json = jsonObjectMapper->writeToString(bk);

            //OATPP_LOGD("Test", "accessoryId=%d", accessoryId->getValue());
            return _return(controller->createDtoResponse(Status::CODE_200, bk));
        }
    };

};
#include OATPP_CODEGEN_END(ApiController)

#endif 
