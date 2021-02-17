#pragma once
/*
* Data Transfer Object used to serialize/deserialize -Product- objects that we store in the shopping platform 
*/
#ifndef ProductDto_hpp
#define ProductDto_hpp

#include "oatpp/core/macro/codegen.hpp"
#include "oatpp/core/Types.hpp"
#include "ctime"

#include OATPP_CODEGEN_BEGIN(DTO)

/**
 *  Data Transfer Object. Object containing fields only.
 *  Used in API for serialization/deserialization and vaidation
 * 	std::string productName;
	std::string productDescription;
	double productPrice;
 */

//general product dto 
class ProductDto : public oatpp::DTO {

	DTO_INIT(ProductDto, DTO)

	DTO_FIELD(Int32, statusCode);
	DTO_FIELD(String, message);

	DTO_FIELD(Int64, productId);
	DTO_FIELD(String, productName);
	DTO_FIELD(String, productDescription);
	DTO_FIELD(Float64, productPrice); //double is not accepted, used Float64 instead
};

class AccesoryDto : public oatpp::DTO {

	DTO_INIT(AccesoryDto, DTO)

	DTO_FIELD(Int32, statusCode);
	DTO_FIELD(String, message);

	DTO_FIELD(Int64, productId);
	DTO_FIELD(String, productName);
	DTO_FIELD(String, productDescription);
	DTO_FIELD(Float64, productPrice);

	DTO_FIELD(String, category);
	DTO_FIELD(String, gender);
};

class ICollectionAccessoryDto : public oatpp::DTO {
	DTO_INIT(ICollectionAccessoryDto, DTO)

	DTO_FIELD(Int32, statusCode);
	DTO_FIELD(String, message);

	DTO_FIELD(Int64, productId);
	DTO_FIELD(String, productName);
	DTO_FIELD(String, productDescription);
	DTO_FIELD(Float64, productPrice);

	DTO_FIELD(String, category);
	DTO_FIELD(String, gender);
	DTO_FIELD(Fields<List<Object<ICollectionAccessoryDto>>>, data) = { {"accessories", List<Object<ICollectionAccessoryDto>>({ ICollectionAccessoryDto::createShared() })} };
};

class BoardGameDto : public oatpp::DTO {

	DTO_INIT(BoardGameDto, DTO)

	DTO_FIELD(Int32, statusCode);
	DTO_FIELD(String, message);

	DTO_FIELD(Int64, productId);
	DTO_FIELD(String, productName);
	DTO_FIELD(String, productDescription);
	DTO_FIELD(Float64, productPrice);

	DTO_FIELD(String, category);
	DTO_FIELD(String, age);
};

class BookDto : public oatpp::DTO {

	DTO_INIT(BookDto, DTO)

	DTO_FIELD(Int32, statusCode);
	DTO_FIELD(String, message);

	DTO_FIELD(Int64, productId);
	DTO_FIELD(String, productName);
	DTO_FIELD(String, productDescription);
	DTO_FIELD(Float64, productPrice);

	DTO_FIELD(String, bookWriter);
	DTO_FIELD(String, bookLanguage);
	DTO_FIELD(String, bookCategory);
	DTO_FIELD(Int32, bookNrOfPages);
};


class HomeDecoDto : public oatpp::DTO {

	DTO_INIT(HomeDecoDto, DTO)

	DTO_FIELD(Int32, statusCode);
	DTO_FIELD(String, message);

	DTO_FIELD(Int64, productId);
	DTO_FIELD(String, productName);
	DTO_FIELD(String, productDescription);
	DTO_FIELD(Float64, productPrice);

	DTO_FIELD(String, objectType);
	DTO_FIELD(String, objectCollection);
	DTO_FIELD(String, objectColor);
	DTO_FIELD(String, objectMaterial);
	DTO_FIELD(String, objectManufacturer);
	DTO_FIELD(Int32, numberOfPieces);
};

class MagazineDto : public oatpp::DTO {

	DTO_INIT(MagazineDto, DTO)

	DTO_FIELD(Int32, statusCode);
	DTO_FIELD(String, message);

	DTO_FIELD(Int64, productId);
	DTO_FIELD(String, productName);
	DTO_FIELD(String, productDescription);
	DTO_FIELD(Float64, productPrice);

	DTO_FIELD(String, magazineLanguage);
	DTO_FIELD(String, magazineCategory);
	DTO_FIELD(Int32, magazineNrPages);
};

class MovieDto : public oatpp::DTO {

	DTO_INIT(MovieDto, DTO)

	DTO_FIELD(Int32, statusCode);
	DTO_FIELD(String, message);

	DTO_FIELD(Int64, productId);
	DTO_FIELD(String, productName);
	DTO_FIELD(String, productDescription);
	DTO_FIELD(Float64, productPrice);

	DTO_FIELD(String, movieFormat);
	DTO_FIELD(String, movieCategory);
	DTO_FIELD(String, duration);
	DTO_FIELD(Int32, minimumAgeRestriction);
};

class MusicDto : public oatpp::DTO {

	DTO_INIT(MusicDto, DTO)

	DTO_FIELD(Int32, statusCode);
	DTO_FIELD(String, message);

	DTO_FIELD(Int64, productId);
	DTO_FIELD(String, productName);
	DTO_FIELD(String, productDescription);
	DTO_FIELD(Float64, productPrice);

	DTO_FIELD(String, musicGenre);
	DTO_FIELD(String, musicAlbumName);
	DTO_FIELD(String, musicArtist);
};


class TeaDto : public oatpp::DTO {

	DTO_INIT(TeaDto, DTO)

	DTO_FIELD(Int32, statusCode);
	DTO_FIELD(String, message);

	DTO_FIELD(Int64, productId);
	DTO_FIELD(String, productName);
	DTO_FIELD(String, productDescription);
	DTO_FIELD(Float64, productPrice);

	DTO_FIELD(String, category);
	DTO_FIELD(String, origin);
};

class WineDto : public oatpp::DTO {

	DTO_INIT(WineDto, DTO)

	DTO_FIELD(Int32, statusCode);
	DTO_FIELD(String, message);

	DTO_FIELD(Int64, productId);
	DTO_FIELD(String, productName);
	DTO_FIELD(String, productDescription);
	DTO_FIELD(Float64, productPrice);

	DTO_FIELD(String, category);
	DTO_FIELD(Int32, year);
	DTO_FIELD(String, type);
};

#include OATPP_CODEGEN_END(DTO)

#endif /* ProductDto_hpp */

