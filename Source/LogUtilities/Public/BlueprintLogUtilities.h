#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include <Engine.h>
#include "BlueprintLogUtilities.generated.h"



DECLARE_LOG_CATEGORY_EXTERN(OKLogBlueprint, All, All)

class UEngine;
UENUM(BlueprintType)
enum class LogVerbosity : uint8
{
	None		= 0				UMETA(Hidden),
	Fatal			 			UMETA(DisplayName = "Fatal (Crash)"),
	Error						UMETA(DisplayName = "Error"),
	Warning						UMETA(DisplayName = "Warning"),
	Display						UMETA(DisplayName = "Display"),
	Log							UMETA(DisplayName = "Log"),
	Verbose						UMETA(DisplayName = "Verbose"),
	VeryVerbose					UMETA(DisplayName = "Very Verbose")
};

struct FLogCategoryOKLogBlueprint;

UCLASS(meta=(BlueprintThreadSafe, ScriptName = "UlueprintLogUtilities"))
class LOGUTILITIES_API UBlueprintLogUtilities : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, meta = (WorldContext = "WorldContextObject", CallableWithoutWorldContext, DisplayName = "OK Log", Keywords = "OK, Log, Print String, Message", AdvancedDisplay = "3"), Category = "OK Log Utilities")
	static void OK_Log(UObject* WorldContextObject, FString Message, LogVerbosity Verbosity = LogVerbosity::Log, bool bPrintToLog = true, bool bPrintToScreen = true, float Duration = 2.0f, FColor ScreenMessageColo=FColor(46, 204, 113));

};