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

#include "LocalExecutionResult.h"

#include "StratisAPIModule.h"
#include "Helpers.h"

#include "Templates/SharedPointer.h"

namespace stratis
{
namespace api
{

void LocalExecutionResult::WriteJson(JsonWriter& Writer) const
{
	Writer->WriteObjectStart();
	if (InternalTransfers.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("internalTransfers")); WriteJsonValue(Writer, InternalTransfers.GetValue());
	}
	if (GasConsumed.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("gasConsumed")); WriteJsonValue(Writer, GasConsumed.GetValue());
	}
	if (Revert.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("revert")); WriteJsonValue(Writer, Revert.GetValue());
	}
	if (ErrorMessage.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("errorMessage")); WriteJsonValue(Writer, ErrorMessage.GetValue());
	}
	if (_Return.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("return")); WriteJsonValue(Writer, _Return.GetValue());
	}
	if (Logs.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("logs")); WriteJsonValue(Writer, Logs.GetValue());
	}
	Writer->WriteObjectEnd();
}

bool LocalExecutionResult::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	const TSharedPtr<FJsonObject>* Object;
	if (!JsonValue->TryGetObject(Object))
		return false;

	bool ParseSuccess = true;

	ParseSuccess &= TryGetJsonValue(*Object, TEXT("internalTransfers"), InternalTransfers);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("gasConsumed"), GasConsumed);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("revert"), Revert);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("errorMessage"), ErrorMessage);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("return"), _Return);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("logs"), Logs);

	return ParseSuccess;
}

}
}
