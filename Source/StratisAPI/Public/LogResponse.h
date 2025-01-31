/**
 * Stratis Node API
 * Access to the Stratis Node's api.
 *
 * OpenAPI spec version: 1.0
 * 
 *
 * NOTE: This class is auto generated by OpenAPI Generator
 * https://github.com/OpenAPITools/openapi-generator
 * Do not edit the class manually.
 */

#pragma once

#include "BaseModel.h"

namespace stratis
{
namespace api
{

/*
 * LogResponse
 *
 * 
 */
class STRATISAPI_API LogResponse : public Model
{
public:
    virtual ~LogResponse() {}
	bool FromJson(const TSharedPtr<FJsonValue>& JsonValue) final;
	void WriteJson(JsonWriter& Writer) const final;

	TOptional<FString> Address;
	TOptional<TArray<FString>> Topics;
	TOptional<FString> Data;
	TOptional<TSharedPtr<FJsonValue>> Log;
};

}
}
