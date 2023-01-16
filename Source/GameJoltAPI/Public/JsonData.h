// Copyright by Nick Lamprecht (2020-2023)

#pragma once

#include "CoreMinimal.h"

#if __has_include ("Launch/Resources/Version.h")
#include "Launch/Resources/Version.h"
#else
#include "Runtime/Launch/Resources/Version.h"
#endif

#include "HttpModule.h"
#include "Interfaces/IHttpResponse.h"
#include "Interfaces/IHttpRequest.h"
#include "Dom/JsonObject.h"
#include "Serialization/JsonSerializer.h"
#include "Serialization/JsonReader.h"
#include "JsonData.generated.h"


DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnGetResult, const bool, bSuccess, class UJsonData*, JSON);

UCLASS()
class UJsonData final : public UObject
{
	GENERATED_BODY()

private:

	void OnReady(FHttpRequestPtr Request, const FHttpResponsePtr Response, const bool bWasSuccessful)
	{
		RemoveFromRoot();
		if (!bWasSuccessful)
		{
			OnGetResult.Broadcast(false, this);
			return;
		}
		if (!FromString(Response->GetContentAsString()))
			OnGetResult.Broadcast(false, this);
		OnGetResult.Broadcast(true, this);
	}

	void Reset()
	{
		if (Data.IsValid())
			Data.Reset();

		Data = MakeShareable(new FJsonObject());
	}

public:

	TSharedPtr<FJsonObject> Data;

	UPROPERTY(BlueprintAssignable, Category = "JSON")
	FOnGetResult OnGetResult;

	UJsonData()
	{
		Reset();
	};

	FString GetString(const FString& key) const
	{
		FString string;
		if (!Data->TryGetStringField(*key, string))
			return "";
		return string;
	}

	bool GetBool(const FString& key) const
	{
		bool boolean;
		if (!Data->TryGetBoolField(*key, boolean))
			return false;
		return boolean;
	}

	int32 GetInt(const FString& key) const
	{
		int32 integer;
		if (!Data->TryGetNumberField(*key, integer))
			return 0;
		return integer;
	}

	TArray<FString> GetStringArray(const FString& key)
	{
		TArray<FString> stringArray;
		const TArray<TSharedPtr<FJsonValue>> *arrayPtr;
		if (Data->TryGetArrayField(*key, arrayPtr))
			for (int32 i=0; i < arrayPtr->Num(); i++)
				stringArray.Add((*arrayPtr)[i]->AsString());
		return stringArray;
	}

	TArray<int32> GetIntArray(const FString& key)
	{
		TArray<int32> array;
		const TArray<TSharedPtr<FJsonValue>> *arrayPtr;
		if (Data->TryGetArrayField(*key, arrayPtr))
			for (int32 i = 0; i < arrayPtr->Num(); i++)
				array.Add(static_cast<int32>((*arrayPtr)[i]->AsNumber()));
		return array;
	}

	UJsonData* GetObject(const FString& key)
	{
		UJsonData* fieldObj = NULL;
		const TSharedPtr<FJsonObject> *outPtr;
		if (!Data->TryGetObjectField(*key, outPtr))
			return NULL;
		fieldObj = NewObject<UJsonData>();
		fieldObj->Data = *outPtr;
		return fieldObj;
	}

	TArray<UJsonData*> GetObjectArray(const FString& key)
	{
		TArray<UJsonData*> objectArray;
		const TArray<TSharedPtr<FJsonValue>> *arrayPtr;
		if (Data->TryGetArrayField(*key, arrayPtr))
		{
			for (int32 i = 0; i < arrayPtr->Num(); i++)
			{
				UJsonData* pageData = NewObject<UJsonData>(); 
				pageData->Data = (*arrayPtr)[i]->AsObject();
				objectArray.Add(pageData);
			}
		}
		return objectArray;
	}

	bool FromString(const FString& dataString)
	{
		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(dataString);
		bool isDeserialized = FJsonSerializer::Deserialize(JsonReader, Data);
		if (!isDeserialized || !Data.IsValid())
			return false;
		return true;
	}

	static UJsonData* GetRequest(const FString& url)
	{
		UJsonData* dataObj = NewObject<UJsonData>();
#if ENGINE_MAJOR_VERSION == 4 && ENGINE_MINOR_VERSION >= 26 || ENGINE_MAJOR_VERSION >= 5
		TSharedRef<IHttpRequest, ESPMode::ThreadSafe> HttpRequest = FHttpModule::Get().CreateRequest();
#else
		TSharedRef<IHttpRequest> HttpRequest = FHttpModule::Get().CreateRequest();
#endif
		HttpRequest->SetVerb("GET");
		HttpRequest->SetURL(url);
		HttpRequest->OnProcessRequestComplete().BindUObject(dataObj, &UJsonData::OnReady);
		dataObj->AddToRoot();
		HttpRequest->ProcessRequest();
		return dataObj;
	}
};