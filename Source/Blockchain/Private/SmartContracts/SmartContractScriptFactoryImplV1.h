#pragma once

#include "SmartContracts/SmartContractScriptFactory.h"
#include "SmartContracts/MethodParameter.h"

namespace smart_contracts
{

class SmartContractScriptFactoryImplV1 : public SmartContractScriptFactory
{

public:
    std::vector<uint8_t> makeCreateSmartContractScript(const CreateContractData& data) const override;
    std::vector<uint8_t> makeCallSmartContractScript(const CallContractData& data) const override;

private:
    std::vector<uint8_t> makePrefix(uint8_t op, uint64_t gasPrice, uint64_t gasLimit) const;
    std::vector< std::vector<uint8_t> > unwrapMethodParameters(const TArray< TUniquePtr<method_parameter::MethodParameter> >& methodParameters) const;
};

}