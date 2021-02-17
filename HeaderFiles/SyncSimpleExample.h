#pragma once

#ifndef SyncSimpleExample_h
#define SyncSimpleExample_h

#include "ApiClient.h"

class SimpleExample
{
private:
	constexpr static const char* TAG = "SimpleExample";
public:

	void static runExample(const std::shared_ptr<ShoppingApiClient>& client)
	{
		{
			auto data = client->doGet()->readBodyToString();
			OATPP_LOGD(TAG, "[doGet] data = '%s'", data->c_str());
		}

		{
			auto data = client->doPost("data being passed to POST")->readBodyToString();
			OATPP_LOGD(TAG, "[doPost] data = '%s'", data->c_str());
		}

		{
			auto data = client->doGetAnything("path-parameter")->readBodyToString();
			OATPP_LOGD(TAG, "[doGetAnything] data = '%s'", data->c_str());
		}

		{
			auto data = client->doPostAnything("path-parameter")->readBodyToString();
			OATPP_LOGD(TAG, "[doPostAnything] data = '%s'", data->c_str());
		}

		{
			auto dto = AccesoryDto::createShared();
			dto->message = "The operation applied has been succesful! \n";
			dto->statusCode = 200; //http status code 200 OK 
			auto data = client->getAccessories(dto)->readBodyToString();
			OATPP_LOGD(TAG, "[getAccessoriesWithDto] data = '%s'", data->c_str());
		}
	}
};

#endif 