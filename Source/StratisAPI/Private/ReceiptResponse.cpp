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

#include "ReceiptResponse.h"

#include "StratisAPIModule.h"
#include "Helpers.h"

#include "Templates/SharedPointer.h"

namespace stratis
{
namespace api
{

void ReceiptResponse::WriteJson(JsonWriter& Writer) const
{
	Writer->WriteObjectStart();
	if (TransactionHash.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("transactionHash")); WriteJsonValue(Writer, TransactionHash.GetValue());
	}
	if (BlockHash.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("blockHash")); WriteJsonValue(Writer, BlockHash.GetValue());
	}
	if (BlockNumber.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("blockNumber")); WriteJsonValue(Writer, BlockNumber.GetValue());
	}
	if (PostState.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("postState")); WriteJsonValue(Writer, PostState.GetValue());
	}
	if (GasUsed.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("gasUsed")); WriteJsonValue(Writer, GasUsed.GetValue());
	}
	if (From.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("from")); WriteJsonValue(Writer, From.GetValue());
	}
	if (To.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("to")); WriteJsonValue(Writer, To.GetValue());
	}
	if (NewContractAddress.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("newContractAddress")); WriteJsonValue(Writer, NewContractAddress.GetValue());
	}
	if (Success.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("success")); WriteJsonValue(Writer, Success.GetValue());
	}
	if (ReturnValue.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("returnValue")); WriteJsonValue(Writer, ReturnValue.GetValue());
	}
	if (Bloom.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("bloom")); WriteJsonValue(Writer, Bloom.GetValue());
	}
	if (Error.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("error")); WriteJsonValue(Writer, Error.GetValue());
	}
	if (Logs.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("logs")); WriteJsonValue(Writer, Logs.GetValue());
	}
	Writer->WriteObjectEnd();
}

bool ReceiptResponse::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	const TSharedPtr<FJsonObject>* Object;
	if (!JsonValue->TryGetObject(Object))
		return false;

	bool ParseSuccess = true;

	ParseSuccess &= TryGetJsonValue(*Object, TEXT("transactionHash"), TransactionHash);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("blockHash"), BlockHash);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("blockNumber"), BlockNumber);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("postState"), PostState);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("gasUsed"), GasUsed);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("from"), From);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("to"), To);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("newContractAddress"), NewContractAddress);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("success"), Success);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("returnValue"), ReturnValue);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("bloom"), Bloom);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("error"), Error);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("logs"), Logs);

	return ParseSuccess;
}

}
}
