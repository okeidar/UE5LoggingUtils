// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "CoreMinimal.h"

#define GET_CLASSNAME_WITH_FUNCTION						FString(__FUNCTION__)
#define GET_LINE_NUMBER									FString::FromInt(__LINE__)


#define OK_LOG(CategoryName,Verbosity,Message, ...)	UE_LOG(CategoryName,Verbosity,TEXT("%s [%s]: %s"),*GET_CLASSNAME_WITH_FUNCTION,*GET_LINE_NUMBER,*FString::Printf(TEXT(Message),##__VA_ARGS__))
#define OK_LOG_TEXT(CategoryName,Verbosity,Message, ...)	UE_LOG(CategoryName,Verbosity,TEXT("%s [%s]: %s"),*GET_CLASSNAME_WITH_FUNCTION,*GET_LINE_NUMBER,*FString::Printf(Message,##__VA_ARGS__))

#define OK_LOG_SCREEN_COLOR( Time, Color, Message, ...) (GEngine->AddOnScreenDebugMessage(-1,Time, Color, *(TEXT("%s [%s]: %s"),*GET_CLASSNAME_WITH_FUNCTION,*GET_LINE_NUMBER, (FString::Printf(TEXT(Message), ##__VA_ARGS__ )))) )
#define OK_LOG_SCREEN_TEXT_COLOR( Time, Color, Message, ...) (GEngine->AddOnScreenDebugMessage(-1,Time, Color, *(TEXT("%s [%s]: %s"),*GET_CLASSNAME_WITH_FUNCTION,*GET_LINE_NUMBER,(FString::Printf(Message, ##__VA_ARGS__ )))) )
#define OK_LOG_SCREEN( Time,  Message, ...) (GEngine->AddOnScreenDebugMessage(-1,Time,  FColor::Green, *(TEXT("%s [%s]: %s"),*GET_CLASSNAME_WITH_FUNCTION,*GET_LINE_NUMBER, (FString::Printf(TEXT(Message), ##__VA_ARGS__ )))) )
#define OK_LOG_SCREEN_TEXT( Time,  Message, ...) (GEngine->AddOnScreenDebugMessage(-1,Time,  FColor::Green, *(TEXT("%s [%s]: %s"),*GET_CLASSNAME_WITH_FUNCTION,*GET_LINE_NUMBER, (FString::Printf(Message, ##__VA_ARGS__ )))) )

#define OK_LOG_MULTI(CategoryName,Verbosity,PrintToScreen,Message, ...)\
	{\
		OK_LOG(CategoryName,Verbosity,Message, ##__VA_ARGS__);\
		if(PrintToScreen)\
			OK_LOG_SCREEN(10.f,Message, ##__VA_ARGS__);\
	}

#define OK_LOG_TEXT_MULTI(CategoryName,Verbosity,PrintToScreen,Message, ...)\
{\
	OK_LOG_TEXT(CategoryName,Verbosity,Message, ##__VA_ARGS__);\
	if(PrintToScreen)\
		OK_LOG_SCREEN_TEXT(10.f,Message, ##__VA_ARGS__);\
}

#define OK_LOG_MULTI_OPTIONS(CategoryName,Verbosity,PrintToScreen,Time, Color, Message, ...)\
{\
	OK_LOG(CategoryName,Verbosity,Message, ##__VA_ARGS__);\
	if(PrintToScreen)\
		OK_LOG_SCREEN_COLOR(Time,Color,Message, ##__VA_ARGS__);\
}

#define OK_LOG_TEXT_MULTI_OPTIONS(CategoryName,Verbosity,PrintToScreen,Time, Color, Message, ...)\
{\
	OK_LOG_TEXT(CategoryName,Verbosity,Message, ##__VA_ARGS__);\
	if(PrintToScreen)\
		OK_LOG_SCREEN_TEXT_COLOR(Time,Color,Message, ##__VA_ARGS__);\
}


/*
 *-------------------------USAGE----------------
	OK_LOG(LogTemp,Display,"Test %i",1);
	OK_LOG_TEXT(LogTemp,Display,TEXT("Test %i"),2);
	OK_LOG_MULTI(LogTemp,Display,true,"Test %i",3);
	OK_LOG_MULTI(LogTemp,Display,false,"Test %i",4);
	OK_LOG_SCREEN(10.f,"Test %i",5);
	OK_LOG_TEXT_MULTI(LogTemp,Display,false,TEXT("Test %i"),6);
	OK_LOG_TEXT_MULTI(LogTemp,Display,true,TEXT("Test %i"),7);
	OK_LOG_SCREEN_TEXT(10.f,TEXT("Test %i"),8);
	OK_LOG_SCREEN_COLOR(10.f,FColor::Red,"Test %i",9);
	OK_LOG_MULTI_OPTIONS(LogTemp,Display,true,10.f,FColor::Purple,"Test %i",10);
	OK_LOG_MULTI_OPTIONS(LogTemp,Display,false,10.f,FColor::Purple,"Test %i",11);
	OK_LOG_SCREEN_TEXT_COLOR(10.f,FColor::Emerald,TEXT("Test %i"),12);
	OK_LOG_TEXT_MULTI_OPTIONS(LogTemp,Display,true,10.f,FColor::Emerald,TEXT("Test %i"),13);
	OK_LOG_TEXT_MULTI_OPTIONS(LogTemp,Display,false,10.f,FColor::Emerald,TEXT("Test %i"),14);	
*/