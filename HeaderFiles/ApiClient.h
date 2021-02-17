#pragma once

#include "oatpp/web/client/ApiClient.hpp"
#include "oatpp/core/macro/codegen.hpp"

//sunt incluse modelele pentru apelarea din DTO
#include "ApiModels.h"
#include "../DTOs/ProductDto.hpp"

#include OATPP_CODEGEN_BEGIN(ApiClient)

class ShoppingApiClient : public oatpp::web::client::ApiClient
{
	
	API_CLIENT_INIT(ShoppingApiClient)

	API_CALL_ASYNC("GET", "/", getRootAsync)

	
		API_CALL("GET", "get", doGet)
		API_CALL("POST", "post", doPost, BODY_STRING(String, body))
		API_CALL("PUT", "put", doPut, BODY_STRING(String, body))
		API_CALL("PATCH", "patch", doPatch, BODY_STRING(String, body))
		API_CALL("DELETE", "delete", doDelete)

		API_CALL("GET", "/accessories", getAccessories, BODY_DTO(Object<AccesoryDto>, body))

		API_CALL("GET", "anything/{parameter}", doGetAnything, PATH(String, parameter))
		API_CALL("POST", "anything/{parameter}", doPostAnything, PATH(String, parameter))
		API_CALL("PUT", "anything/{parameter}", doPutAnything, PATH(String, parameter))
		API_CALL("PATCH", "anything/{parameter}", doPatchAnything, PATH(String, parameter))
		API_CALL("DELETE", "anything/{parameter}", doDeleteAnything, PATH(String, parameter))


	
};

#include OATPP_CODEGEN_END(ApiClient)