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

#include "LocalCallContractRequest.h"

#include "StratisAPIModule.h"
#include "Helpers.h"

#include "Templates/SharedPointer.h"

namespace stratis
{
namespace api
{

void LocalCallContractRequest::WriteJson(JsonWriter& Writer) const
{
	Writer->WriteObjectStart();
	if (BlockHeight.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("blockHeight")); WriteJsonValue(Writer, BlockHeight.GetValue());
	}
	Writer->WriteIdentifierPrefix(TEXT("contractAddress")); WriteJsonValue(Writer, ContractAddress);
	Writer->WriteIdentifierPrefix(TEXT("methodName")); WriteJsonValue(Writer, MethodName);
	if (Amount.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("amount")); WriteJsonValue(Writer, Amount.GetValue());
	}
	if (GasPrice.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("gasPrice")); WriteJsonValue(Writer, GasPrice.GetValue());
	}
	if (GasLimit.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("gasLimit")); WriteJsonValue(Writer, GasLimit.GetValue());
	}
	if (Sender.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("sender")); WriteJsonValue(Writer, Sender.GetValue());
	}
	if (Parameters.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("parameters")); WriteJsonValue(Writer, Parameters.GetValue());
	}
	Writer->WriteObjectEnd();
}

bool LocalCallContractRequest::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	const TSharedPtr<FJsonObject>* Object;
	if (!JsonValue->TryGetObject(Object))
		return false;

	bool ParseSuccess = true;

	ParseSuccess &= TryGetJsonValue(*Object, TEXT("blockHeight"), BlockHeight);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("contractAddress"), ContractAddress);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("methodName"), MethodName);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("amount"), Amount);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("gasPrice"), GasPrice);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("gasLimit"), GasLimit);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("sender"), Sender);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("parameters"), Parameters);

	return ParseSuccess;
}

}
}
