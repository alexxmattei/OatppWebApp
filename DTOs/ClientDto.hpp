#pragma once
/*
* Data Transfer Object used to serialize/deserialize -Product- objects that we store in the shopping platform
*/
#ifndef ClientDto_hpp
#define ClientDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include "ctime"

#include OATPP_CODEGEN_BEGIN(DTO)

//DTO for existing Clients 
class ClientDto : public oatpp::DTO {

	DTO_INIT(ClientDto, DTO)

	DTO_FIELD(Int32, statusCode);
	DTO_FIELD(String, message);

	DTO_FIELD(Int64, clientId);
	DTO_FIELD(Int64, roleId);
	DTO_FIELD(String, userName); 
	DTO_FIELD(String, userMiddleName); 
	DTO_FIELD(String, userSurname); 
	DTO_FIELD(Int64, userAge);
	DTO_FIELD(String, userBirthdate);
	DTO_FIELD(String, userPhoneNumber);
	DTO_FIELD(String, userEmail);
	DTO_FIELD(String, userAddress);
	DTO_FIELD(String, userPassword);
};


#include OATPP_CODEGEN_END(DTO)

#endif /* ProductDto_hpp */

