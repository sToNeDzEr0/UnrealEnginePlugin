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

#include "UnrealApi.h"

#include "UnrealApiOperations.h"
#include "StratisAPIModule.h"

#include "HttpModule.h"
#include "Serialization/JsonSerializer.h"

namespace stratis
{
namespace api
{

UnrealApi::UnrealApi()
: Url(TEXT("http://localhost"))
{
}

UnrealApi::~UnrealApi() {}

void UnrealApi::SetURL(const FString& InUrl)
{
	Url = InUrl;
}

void UnrealApi::AddHeaderParam(const FString& Key, const FString& Value)
{
	AdditionalHeaderParams.Add(Key, Value);
}

void UnrealApi::ClearHeaderParams()
{
	AdditionalHeaderParams.Reset();
}

bool UnrealApi::IsValid() const
{
	if (Url.IsEmpty())
	{
		UE_LOG(LogStratisAPI, Error, TEXT("UnrealApi: Endpoint Url is not set, request cannot be performed"));
		return false;
	}

	return true;
}

void UnrealApi::SetHttpRetryManager(FHttpRetrySystem::FManager& InRetryManager)
{
	if(RetryManager != &GetHttpRetryManager())
	{
		DefaultRetryManager.Reset();
		RetryManager = &InRetryManager;
	}
}

FHttpRetrySystem::FManager& UnrealApi::GetHttpRetryManager()
{
	return *RetryManager;
}

FHttpRequestRef UnrealApi::CreateHttpRequest(const Request& Request) const
{
	if (!Request.GetRetryParams().IsSet())
	{
		return FHttpModule::Get().CreateRequest();
	}
	else
	{
		if (!RetryManager)
		{
			// Create default retry manager if none was specified
			DefaultRetryManager = MakeUnique<HttpRetryManager>(6, 60);
			RetryManager = DefaultRetryManager.Get();
		}

		const HttpRetryParams& Params = Request.GetRetryParams().GetValue();
		return RetryManager->CreateRequest(Params.RetryLimitCountOverride, Params.RetryTimeoutRelativeSecondsOverride, Params.RetryResponseCodes, Params.RetryVerbs, Params.RetryDomains);
	}
}

void UnrealApi::HandleResponse(FHttpResponsePtr HttpResponse, bool bSucceeded, Response& InOutResponse) const
{
	InOutResponse.SetHttpResponse(HttpResponse);
	InOutResponse.SetSuccessful(bSucceeded);

	if (bSucceeded && HttpResponse.IsValid())
	{
		InOutResponse.SetHttpResponseCode((EHttpResponseCodes::Type)HttpResponse->GetResponseCode());
		FString ContentType = HttpResponse->GetContentType();
		FString Content;

		if (ContentType.IsEmpty())
		{
			return; // Nothing to parse
		}
		else if (ContentType.StartsWith(TEXT("application/json")) || ContentType.StartsWith("text/json"))
		{
			Content = HttpResponse->GetContentAsString();

			TSharedPtr<FJsonValue> JsonValue;
			auto Reader = TJsonReaderFactory<>::Create(Content);

			if (FJsonSerializer::Deserialize(Reader, JsonValue) && JsonValue.IsValid())
			{
				if (InOutResponse.FromJson(JsonValue))
					return; // Successfully parsed
			}
		}
		else if(ContentType.StartsWith(TEXT("text/plain")))
		{
			Content = HttpResponse->GetContentAsString();
			InOutResponse.SetResponseString(Content);
			return; // Successfully parsed
		}

		// Report the parse error but do not mark the request as unsuccessful. Data could be partial or malformed, but the request succeeded.
		UE_LOG(LogStratisAPI, Error, TEXT("Failed to deserialize Http response content (type:%s):\n%s"), *ContentType , *Content);
		return;
	}

	// By default, assume we failed to establish connection
	InOutResponse.SetHttpResponseCode(EHttpResponseCodes::RequestTimeout);
}

FHttpRequestPtr UnrealApi::Unity3dApiUnity3dLocalCallPost(const Unity3dApiUnity3dLocalCallPostRequest& Request, const FUnity3dApiUnity3dLocalCallPostDelegate& Delegate /*= FUnity3dApiUnity3dLocalCallPostDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &UnrealApi::OnUnity3dApiUnity3dLocalCallPostResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void UnrealApi::OnUnity3dApiUnity3dLocalCallPostResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUnity3dApiUnity3dLocalCallPostDelegate Delegate) const
{
	Unity3dApiUnity3dLocalCallPostResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr UnrealApi::Unity3dApiUnity3dReceiptGet(const Unity3dApiUnity3dReceiptGetRequest& Request, const FUnity3dApiUnity3dReceiptGetDelegate& Delegate /*= FUnity3dApiUnity3dReceiptGetDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &UnrealApi::OnUnity3dApiUnity3dReceiptGetResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void UnrealApi::OnUnity3dApiUnity3dReceiptGetResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUnity3dApiUnity3dReceiptGetDelegate Delegate) const
{
	Unity3dApiUnity3dReceiptGetResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr UnrealApi::Unity3dBlockGet(const Unity3dBlockGetRequest& Request, const FUnity3dBlockGetDelegate& Delegate /*= FUnity3dBlockGetDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &UnrealApi::OnUnity3dBlockGetResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void UnrealApi::OnUnity3dBlockGetResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUnity3dBlockGetDelegate Delegate) const
{
	Unity3dBlockGetResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr UnrealApi::Unity3dGetaddressbalanceGet(const Unity3dGetaddressbalanceGetRequest& Request, const FUnity3dGetaddressbalanceGetDelegate& Delegate /*= FUnity3dGetaddressbalanceGetDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &UnrealApi::OnUnity3dGetaddressbalanceGetResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void UnrealApi::OnUnity3dGetaddressbalanceGetResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUnity3dGetaddressbalanceGetDelegate Delegate) const
{
	Unity3dGetaddressbalanceGetResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr UnrealApi::Unity3dGetblockheaderGet(const Unity3dGetblockheaderGetRequest& Request, const FUnity3dGetblockheaderGetDelegate& Delegate /*= FUnity3dGetblockheaderGetDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &UnrealApi::OnUnity3dGetblockheaderGetResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void UnrealApi::OnUnity3dGetblockheaderGetResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUnity3dGetblockheaderGetDelegate Delegate) const
{
	Unity3dGetblockheaderGetResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr UnrealApi::Unity3dGetrawtransactionGet(const Unity3dGetrawtransactionGetRequest& Request, const FUnity3dGetrawtransactionGetDelegate& Delegate /*= FUnity3dGetrawtransactionGetDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &UnrealApi::OnUnity3dGetrawtransactionGetResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void UnrealApi::OnUnity3dGetrawtransactionGetResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUnity3dGetrawtransactionGetDelegate Delegate) const
{
	Unity3dGetrawtransactionGetResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr UnrealApi::Unity3dGetutxosforaddressGet(const Unity3dGetutxosforaddressGetRequest& Request, const FUnity3dGetutxosforaddressGetDelegate& Delegate /*= FUnity3dGetutxosforaddressGetDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &UnrealApi::OnUnity3dGetutxosforaddressGetResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void UnrealApi::OnUnity3dGetutxosforaddressGetResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUnity3dGetutxosforaddressGetDelegate Delegate) const
{
	Unity3dGetutxosforaddressGetResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr UnrealApi::Unity3dSendTransactionPost(const Unity3dSendTransactionPostRequest& Request, const FUnity3dSendTransactionPostDelegate& Delegate /*= FUnity3dSendTransactionPostDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &UnrealApi::OnUnity3dSendTransactionPostResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void UnrealApi::OnUnity3dSendTransactionPostResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUnity3dSendTransactionPostDelegate Delegate) const
{
	Unity3dSendTransactionPostResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr UnrealApi::Unity3dTipGet(const Unity3dTipGetRequest& Request, const FUnity3dTipGetDelegate& Delegate /*= FUnity3dTipGetDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &UnrealApi::OnUnity3dTipGetResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void UnrealApi::OnUnity3dTipGetResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUnity3dTipGetDelegate Delegate) const
{
	Unity3dTipGetResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

FHttpRequestPtr UnrealApi::Unity3dValidateaddressGet(const Unity3dValidateaddressGetRequest& Request, const FUnity3dValidateaddressGetDelegate& Delegate /*= FUnity3dValidateaddressGetDelegate()*/) const
{
	if (!IsValid())
		return nullptr;

	FHttpRequestRef HttpRequest = CreateHttpRequest(Request);
	HttpRequest->SetURL(*(Url + Request.ComputePath()));

	for(const auto& It : AdditionalHeaderParams)
	{
		HttpRequest->SetHeader(It.Key, It.Value);
	}

	Request.SetupHttpRequest(HttpRequest);

	HttpRequest->OnProcessRequestComplete().BindRaw(this, &UnrealApi::OnUnity3dValidateaddressGetResponse, Delegate);
	HttpRequest->ProcessRequest();
	return HttpRequest;
}

void UnrealApi::OnUnity3dValidateaddressGetResponse(FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded, FUnity3dValidateaddressGetDelegate Delegate) const
{
	Unity3dValidateaddressGetResponse Response;
	HandleResponse(HttpResponse, bSucceeded, Response);
	Delegate.ExecuteIfBound(Response);
}

}
}
