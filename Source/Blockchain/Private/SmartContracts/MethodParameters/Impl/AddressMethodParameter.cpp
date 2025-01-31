#pragma once

#include "SmartContracts/MethodParameters/AddressMethodParameter.h"

#include "Utils.h"

namespace smart_contracts
{

namespace method_parameter
{

AddressMethodParameter::AddressMethodParameter(const Address& value)
: value_(value)
{
}

AddressMethodParameter::AddressMethodParameter(Address&& value)
: value_(MoveTemp(value))
{
}

std::vector<uint8_t> AddressMethodParameter::serialize() const
{
    std::vector<uint8_t> bytes(utils::asBytes(value_));

    std::vector<uint8_t> result { (uint8_t) MethodParameter::Type::ADDRESS };
    result.insert(result.end(), bytes.begin(), bytes.end());

    return result;
}

MethodParameter::Type AddressMethodParameter::type() const
{
    return MethodParameter::Type::ADDRESS;
}

}

}