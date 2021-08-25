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

#include "RawTxModel.h"

#include "StratisAPIModule.h"
#include "Helpers.h"

#include "Templates/SharedPointer.h"

namespace stratis
{
namespace api
{

void RawTxModel::WriteJson(JsonWriter& Writer) const
{
	Writer->WriteObjectStart();
	if (Hex.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("hex")); WriteJsonValue(Writer, Hex.GetValue());
	}
	Writer->WriteObjectEnd();
}

bool RawTxModel::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	const TSharedPtr<FJsonObject>* Object;
	if (!JsonValue->TryGetObject(Object))
		return false;

	bool ParseSuccess = true;

	ParseSuccess &= TryGetJsonValue(*Object, TEXT("hex"), Hex);

	return ParseSuccess;
}

}
}
