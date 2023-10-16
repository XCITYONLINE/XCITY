// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"

#include "CommonUtilsBPFL.generated.h"

UCLASS()
class COMMONCONTRACTSPLUGIN_API UCommonUtilsBPFL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, CustomThunk, meta = (CustomStructureParam = "Result"))
	static void GetStructPropertyValueByName(UObject* Target, FName VarName, bool& Success, UProperty*& Result);

	static void GenericGetStructPropertyValueByName(UObject* Target, FName VarName, bool& Success, UProperty*& Result);

	DECLARE_FUNCTION(execGetStructPropertyValueByName)
	{
		P_GET_OBJECT(UObject, Target);
		P_GET_PROPERTY(FNameProperty, VarName);
		P_GET_PROPERTY_REF(FBoolProperty, Success);

		Stack.StepCompiledIn<FStructProperty>(nullptr);
		void* Result = Stack.MostRecentPropertyAddress;
		P_FINISH;

		if (const FStructProperty* Property =
			FindFProperty<FStructProperty>(Target->GetClass(), VarName))
		{
			if (const void* StructProperty =
				Property->ContainerPtrToValuePtr<void>(Target))
			{
				P_NATIVE_BEGIN;
				Property->Struct->CopyScriptStruct(Result, StructProperty);
				Success = true;
				P_NATIVE_END;
			}
		}
	}
};
