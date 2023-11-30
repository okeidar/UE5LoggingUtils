// Fill out your copyright notice in the Description page of Project Settings.


#include "BlueprintLogUtilities.h"

DEFINE_LOG_CATEGORY(OKLogBlueprint);

void UBlueprintLogUtilities::OK_Log(UObject* WorldContextObject, FString Message, LogVerbosity Verbosity, bool bPrintToLog, bool bPrintToScreen, float Duration, FColor ScreenMessageColor)
{
	static FName LoggerName="OKLogBlueprint";
	const FString TextToPrint =FString::Printf(TEXT("%s: %s"),*GetNameSafe(WorldContextObject), *Message) ;
	if (bPrintToLog)
	{
		FMsg::LogV(nullptr, 0,LoggerName  ,static_cast<ELogVerbosity::Type>(Verbosity),*TextToPrint, nullptr );	
	}
	
	if (bPrintToScreen && GAreScreenMessagesEnabled)
	{
		GEngine->AddOnScreenDebugMessage(-1, Duration, ScreenMessageColor, TextToPrint);	
	}
}
