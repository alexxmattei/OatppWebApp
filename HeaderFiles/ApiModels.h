#pragma once

#ifndef ApiModels_h
#define ApiModels_h

#include "oatpp/core/Types.hpp"
#include "oatpp/core/macro/codegen.hpp"


//codegen pentru DTO si integrarea modelelelor 
#include OATPP_CODEGEN_BEGIN(DTO)

class myRequestDto : public oatpp::DTO
{
	DTO_INIT(myRequestDto, DTO)

		DTO_FIELD(String, message);
	DTO_FIELD(Int32, code);

};

class HttpBinResponseDto : public oatpp::DTO
{
	DTO_INIT(HttpBinResponseDto, DTO)

		DTO_FIELD(String, data);
		DTO_FIELD(String, method);
		DTO_FIELD(String, origin);
		DTO_FIELD(String, url);

		DTO_FIELD(Fields<String>::ObjectWrapper, headers);
};

#include OATPP_CODEGEN_END(DTO)

#endif
//ApiModels_h

