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

#include "BlockModel.h"

#include "StratisAPIModule.h"
#include "Helpers.h"

#include "Templates/SharedPointer.h"

namespace stratis
{
namespace api
{

void BlockModel::WriteJson(JsonWriter& Writer) const
{
	Writer->WriteObjectStart();
	if (Hash.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("hash")); WriteJsonValue(Writer, Hash.GetValue());
	}
	if (Confirmations.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("confirmations")); WriteJsonValue(Writer, Confirmations.GetValue());
	}
	if (Size.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("size")); WriteJsonValue(Writer, Size.GetValue());
	}
	if (Weight.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("weight")); WriteJsonValue(Writer, Weight.GetValue());
	}
	if (Height.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("height")); WriteJsonValue(Writer, Height.GetValue());
	}
	if (Version.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("version")); WriteJsonValue(Writer, Version.GetValue());
	}
	if (VersionHex.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("versionHex")); WriteJsonValue(Writer, VersionHex.GetValue());
	}
	if (Merkleroot.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("merkleroot")); WriteJsonValue(Writer, Merkleroot.GetValue());
	}
	if (Tx.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("tx")); WriteJsonValue(Writer, Tx.GetValue());
	}
	if (Time.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("time")); WriteJsonValue(Writer, Time.GetValue());
	}
	if (Mediantime.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("mediantime")); WriteJsonValue(Writer, Mediantime.GetValue());
	}
	if (Nonce.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("nonce")); WriteJsonValue(Writer, Nonce.GetValue());
	}
	if (Bits.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("bits")); WriteJsonValue(Writer, Bits.GetValue());
	}
	if (Difficulty.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("difficulty")); WriteJsonValue(Writer, Difficulty.GetValue());
	}
	if (Chainwork.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("chainwork")); WriteJsonValue(Writer, Chainwork.GetValue());
	}
	if (NTx.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("nTx")); WriteJsonValue(Writer, NTx.GetValue());
	}
	if (Previousblockhash.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("previousblockhash")); WriteJsonValue(Writer, Previousblockhash.GetValue());
	}
	if (Nextblockhash.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("nextblockhash")); WriteJsonValue(Writer, Nextblockhash.GetValue());
	}
	if (Signature.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("signature")); WriteJsonValue(Writer, Signature.GetValue());
	}
	if (Modifierv2.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("modifierv2")); WriteJsonValue(Writer, Modifierv2.GetValue());
	}
	if (Flags.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("flags")); WriteJsonValue(Writer, Flags.GetValue());
	}
	if (Hashproof.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("hashproof")); WriteJsonValue(Writer, Hashproof.GetValue());
	}
	if (Blocktrust.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("blocktrust")); WriteJsonValue(Writer, Blocktrust.GetValue());
	}
	if (Chaintrust.IsSet())
	{
		Writer->WriteIdentifierPrefix(TEXT("chaintrust")); WriteJsonValue(Writer, Chaintrust.GetValue());
	}
	Writer->WriteObjectEnd();
}

bool BlockModel::FromJson(const TSharedPtr<FJsonValue>& JsonValue)
{
	const TSharedPtr<FJsonObject>* Object;
	if (!JsonValue->TryGetObject(Object))
		return false;

	bool ParseSuccess = true;

	ParseSuccess &= TryGetJsonValue(*Object, TEXT("hash"), Hash);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("confirmations"), Confirmations);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("size"), Size);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("weight"), Weight);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("height"), Height);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("version"), Version);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("versionHex"), VersionHex);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("merkleroot"), Merkleroot);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("tx"), Tx);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("time"), Time);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("mediantime"), Mediantime);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("nonce"), Nonce);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("bits"), Bits);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("difficulty"), Difficulty);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("chainwork"), Chainwork);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("nTx"), NTx);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("previousblockhash"), Previousblockhash);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("nextblockhash"), Nextblockhash);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("signature"), Signature);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("modifierv2"), Modifierv2);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("flags"), Flags);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("hashproof"), Hashproof);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("blocktrust"), Blocktrust);
	ParseSuccess &= TryGetJsonValue(*Object, TEXT("chaintrust"), Chaintrust);

	return ParseSuccess;
}

}
}
