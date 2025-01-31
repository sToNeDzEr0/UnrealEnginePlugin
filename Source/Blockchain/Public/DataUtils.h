#pragma once

#include "Core.h"

inline TArray<uint8> HexToBytesArray(const FString &value)
{
    if (value.IsEmpty())
        return {};

    int32 octetsCount = value.Len();
    int32 bytesCount;

    if (octetsCount % 2 != 0)
        bytesCount = (octetsCount + 1) / 2;
    else
        bytesCount = octetsCount / 2;

    uint8 *bytes = new uint8[bytesCount];

    HexToBytes(value, bytes);

    TArray<uint8> result(bytes, bytesCount);

    delete[] bytes;

    return result;
}