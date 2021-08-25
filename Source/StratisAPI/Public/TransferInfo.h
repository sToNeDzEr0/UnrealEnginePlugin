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
 * TransferInfo
 *
 * 
 */
class STRATISAPI_API TransferInfo : public Model
{
public:
    virtual ~TransferInfo() {}
	bool FromJson(const TSharedPtr<FJsonValue>& JsonValue) final;
	void WriteJson(JsonWriter& Writer) const final;

	TOptional<TArray<uint8>> From;
	TOptional<TArray<uint8>> To;
	TOptional<int64> Value;
};

}
}
