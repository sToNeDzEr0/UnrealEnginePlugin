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
 * ValidatedAddress
 *
 * 
 */
class STRATISAPI_API ValidatedAddress : public Model
{
public:
    virtual ~ValidatedAddress() {}
	bool FromJson(const TSharedPtr<FJsonValue>& JsonValue) final;
	void WriteJson(JsonWriter& Writer) const final;

	TOptional<bool> Isvalid;
	TOptional<FString> Address;
	TOptional<FString> ScriptPubKey;
	TOptional<bool> Isscript;
	TOptional<bool> Iswitness;
};

}
}
