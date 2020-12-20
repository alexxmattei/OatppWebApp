#pragma once

#include "oatpp/web/client/ApiClient.hpp"
#include "oatpp/core/macro/codegen.hpp"

//sunt incluse modelele pentru apelarea din DTO
#include "ApiModels.h"

#include OATPP_CODEGEN_BEGIN(ApiClient)

class MyApiClient : public oatpp::web::client::ApiClient
{
	
	API_CLIENT_INIT(MyApiClient)
	
	//async endpoint 
	API_CALL_ASYNC("GET", "/", getRootAsync)

	//synchronous calls -  CRUD operations  + PATCH
		API_CALL("GET", "get", doGet)
		API_CALL("POST", "post", doPost, BODY_STRING(String, body))
		API_CALL("PUT", "put", doPut, BODY_STRING(String, body))
		API_CALL("PATCH", "patch", doPatch, BODY_STRING(String, body))
		API_CALL("DELETE", "delete", doDelete)

		API_CALL("POST", "post", doPostWithDto, BODY_DTO(Object<myRequestDto>, body))

		API_CALL("GET", "anything/{parameter}", doGetAnything, PATH(String, paramerter))
		API_CALL("POST", "anything/{parameter}", doPostAnything, PATH(String, paramerter))
		API_CALL("PUT", "anything/{parameter}", doPutAnything, PATH(String, paramerter))
		API_CALL("PATCH", "anything/{parameter}", doPatchAnything, PATH(String, paramerter))
		API_CALL("DELETE", "anything/{parameter}", doDeleteAnything, PATH(String, paramerter))


    //API_CALL
	//("<http-method>", "<path>", <method-name>, <optional param-mappings>)
	
};

#include OATPP_CODEGEN_END(ApiClient)