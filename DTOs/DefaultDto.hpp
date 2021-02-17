#pragma once
#ifndef DefaultDto_hpp
#define DefaultDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  Data Transfer Object. Object containing fields only.
 *  Used in API for serialization/deserialization and vaidation
 */
class DefaultDto : public oatpp::DTO {

	DTO_INIT(DefaultDto, DTO)

	DTO_FIELD(Int32, statusCode);
	DTO_FIELD(String, message);

};

#include OATPP_CODEGEN_END(DTO)

#endif /* DefaultDto_hpp */