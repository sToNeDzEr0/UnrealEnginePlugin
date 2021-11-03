#pragma once

#include "Core.h"

#include "Models/ENetwork.h"
#include "Models/FError.h"
#include "Models/FLocalCallData.h"
#include "Models/FNetwork.h"
#include "Models/FReceiptResponse.h"
#include "Models/FUInt64.h"
#include "Models/FUTXO.h"
#include "RequestContextManager.h"
#include "TResult.h"
#include "Transaction.h"
#include "UnrealApi.h"

#include "UStratisUnrealManager.generated.h"

DECLARE_DYNAMIC_DELEGATE_OneParam(FGetBalanceResponseReceivedDelegate,
                                  const FUInt64 &, money);
DECLARE_DYNAMIC_DELEGATE_OneParam(FGetCoinsResponseReceivedDelegate,
                                  const TArray<FUTXO> &, data);

DECLARE_DYNAMIC_DELEGATE_OneParam(FSendTransactionResponseReceivedDelegate,
                                  const FString &, transactionID);
DECLARE_DYNAMIC_DELEGATE_OneParam(
    FWaitTillReceiptAvailableResponseReceivedDelegate, const FReceiptResponse &,
    response);
DECLARE_DYNAMIC_DELEGATE_OneParam(
    FLocalCallResponseReceivedDelegate, const FString &,
    returnValue); // TODO: feature -  extend return type
DECLARE_DYNAMIC_DELEGATE_OneParam(FErrorReceivedDelegate, const FError &,
                                  error);

class TransactionBuilder;

UCLASS(BlueprintType, Blueprintable)
class STRATIS_API UStratisUnrealManager : public UObject {

  GENERATED_BODY()

public:
  UStratisUnrealManager();

  UPROPERTY(EditAnywhere)
  uint64 gasPrice;

  UPROPERTY(EditAnywhere)
  uint64 gasLimit;

  UPROPERTY(EditAnywhere)
  uint64 defaultFee;

  UPROPERTY(EditAnywhere)
  FString mnemonic;

  UPROPERTY(EditAnywhere)
  FString baseUrl;

  UPROPERTY(EditAnywhere)
  FNetwork network;

  UFUNCTION(BlueprintCallable, Category = "StratisUnrealManager")
  void setPredefinedNetwork(ENetwork networkType);

  void PostEditChangeProperty(struct FPropertyChangedEvent &e) override;

  UFUNCTION(BlueprintCallable, Category = "StratisUnrealManager")
  FString getAddress();

  UFUNCTION(BlueprintCallable, Category = "StratisUnrealManager")
  void getBalance(const FGetBalanceResponseReceivedDelegate &delegate,
                  const FErrorReceivedDelegate &errorDelegate);
  void getBalance(TFunction<void(const TResult<int64> &)> callback);

  UFUNCTION(BlueprintCallable, Category = "StratisUnrealManager")
  void
  sendRawTransaction(const FString &transactionHex,
                     const FString &transactionID,
                     const FSendTransactionResponseReceivedDelegate &delegate,
                     const FErrorReceivedDelegate &errorDelegate);
  void sendRawTransaction(const FString &transactionHex,
                          const FString &transactionID,
                          TFunction<void(const TResult<FString> &)> callback);

  UFUNCTION(BlueprintCallable, Category = "StratisUnrealManager")
  void
  sendCoinsTransaction(const FString &destinationAddress, int64 money,
                       const FSendTransactionResponseReceivedDelegate &delegate,
                       const FErrorReceivedDelegate &errorDelegate);
  void sendCoinsTransaction(const FString &destinationAddress, int64 money,
                            TFunction<void(const TResult<FString> &)> callback);

  UFUNCTION(BlueprintCallable, Category = "StratisUnrealManager")
  void sendOpReturnStringTransaction(
      const FString &opReturnData,
      const FSendTransactionResponseReceivedDelegate &delegate,
      const FErrorReceivedDelegate &errorDelegate);
  void sendOpReturnStringTransaction(
      const FString &opReturnData,
      TFunction<void(const TResult<FString> &)> callback);

  UFUNCTION(BlueprintCallable, Category = "StratisUnrealManager")
  void sendOpReturnArrayTransaction(
      const TArray<uint8> &opReturnData,
      const FSendTransactionResponseReceivedDelegate &delegate,
      const FErrorReceivedDelegate &errorDelegate);
  void sendOpReturnArrayTransaction(
      const TArray<uint8> &opReturnData,
      TFunction<void(const TResult<FString> &)> callback);

  UFUNCTION(BlueprintCallable, Category = "StratisUnrealManager")
  void getCoins(const FGetCoinsResponseReceivedDelegate &delegate,
                const FErrorReceivedDelegate &errorDelegate);
  void getCoins(TFunction<void(const TResult<TArray<FUTXO>> &)> callback);

  UFUNCTION(BlueprintCallable, Category = "StratisUnrealManager")
  void sendCreateContractTransaction(
      const FString &contractCode, const TArray<FString> &parameters,
      int64 money, const FSendTransactionResponseReceivedDelegate &delegate,
      const FErrorReceivedDelegate &errorDelegate);
  void sendCreateContractTransaction(
      const FString &contractCode, const TArray<FString> &parameters,
      int64 money, TFunction<void(const TResult<FString> &)> callback);

  UFUNCTION(BlueprintCallable, Category = "StratisUnrealManager")
  void sendCallContractTransaction(
      const FString &contractAddress, const FString &methodName,
      const TArray<FString> &parameters, const FUInt64 &money,
      const FSendTransactionResponseReceivedDelegate &delegate,
      const FErrorReceivedDelegate &errorDelegate);
  void sendCallContractTransaction(
      const FString &contractAddress, const FString &methodName,
      const TArray<FString> &parameters, uint64 money,
      TFunction<void(const TResult<FString> &)> callback);

  UFUNCTION(BlueprintCallable, Category = "StratisUnrealManager")
  void waitTillReceiptAvailable(
      const FString &transactionID,
      const FWaitTillReceiptAvailableResponseReceivedDelegate &delegate,
      const FErrorReceivedDelegate &errorDelegate);
  void waitTillReceiptAvailable(
      const FString &transactionID,
      TFunction<void(const TResult<FReceiptResponse> &)> callback);

  UFUNCTION(BlueprintCallable, Category = "StratisUnrealManager")
  void makeLocalCall(const FLocalCallData &localCallData,
                     const FLocalCallResponseReceivedDelegate &delegate,
                     const FErrorReceivedDelegate &errorDelegate);
  void makeLocalCall(const FLocalCallData &localCallData,
                     TFunction<void(const TResult<FString> &)> callback);

  // Legacy method to provide compatibility with smart contract wrappers
  void sendCreateContractTransaction(const FString &contractCode,
                                     const TArray<FString> &parameters,
                                     int64 money,
                                     TFunction<void(const FString &)> callback);

  void sendCallContractTransaction(const FString &contractAddress,
                                   const FString &methodName,
                                   const TArray<FString> &parameters,
                                   uint64 money,
                                   TFunction<void(const FString &)> callback);
  void makeLocalCall(const FLocalCallData &localCallData,
                     TFunction<void(const FString &)> callback);

private:
  UWorld *GetWorld() const;
  void notifyNetworkChanged();

  TSharedPtr<TransactionBuilder> transactionBuilder_;
  TSharedPtr<stratis::api::UnrealApi> unrealApi_;

  RequestContextManager requestContextManager_;
};