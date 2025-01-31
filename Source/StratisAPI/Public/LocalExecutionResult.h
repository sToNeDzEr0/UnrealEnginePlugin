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
#include "ContractErrorMessage.h"
#include "Gas.h"
#include "Log.h"
#include "TransferInfo.h"

namespace stratis
{
namespace api
{

/*
 * LocalExecutionResult
 *
 * 
 */
class STRATISAPI_API LocalExecutionResult : public Model
{
public:
    virtual ~LocalExecutionResult() {}
	bool FromJson(const TSharedPtr<FJsonValue>& JsonValue) final;
	void WriteJson(JsonWriter& Writer) const final;

	TOptional<TArray<TransferInfo>> InternalTransfers;
	TOptional<Gas> GasConsumed;
	TOptional<bool> Revert;
	TOptional<ContractErrorMessage> ErrorMessage;
	TOptional<TSharedPtr<FJsonValue>> _Return;
	TOptional<TArray<Log>> Logs;
};

}
}
