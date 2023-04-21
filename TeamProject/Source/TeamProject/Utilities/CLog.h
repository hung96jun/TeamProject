#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
class TEAMPROJECT_API CLog
{
public:
	CLog();
	~CLog();

	static void Log(int Value);
	static void Log(float Value);
	static void Log(const FString& Value);
	static void Log(const TCHAR* Value);
	static void Log(const FName& Value);
	static void LogNull(UObject* Object);

	static void Print(int Value, float Time = 10.0f, FColor Color = FColor::Black, int32 Key = -1);
	static void Print(float Value, float Time = 10.0f, FColor Color = FColor::Black, int32 Key = -1);
	static void Print(const FString& Value, float Time = 10.0f, FColor Color = FColor::Black, int32 Key = -1);
	static void Print(const TCHAR* Value, float Time = 10.0f, FColor Color = FColor::Black, int32 Key = -1);
	static void Print(const FName& Value, float Time = 10.0f, FColor Color = FColor::Black, int32 Key = -1);
	static void PrintNull(UObject* Object, float Time = 10.0f, FColor Color = FColor::Black, int32 Key = -1);

	static void DrawLine(const UWorld* InWorld, FVector const& LineStart, FVector const& LineEnd, FColor const& Color, bool bPersistentLines = false, float LifeTime = -1.0f, float Thickness = 5.0f);
	static void DrawCircle(const UWorld* InWorld, const FVector Center, float Radius, int32 Segments, const FColor& Color, bool bPersistentLines = false, float LifeTime = -1.0f, uint8 DepthPriority = 0, float Tickness = 0.0f);
	static void DrawCapsule(const UWorld* InWorld, FVector const& Center, float HalfHeight, float Radius, FColor const& Color, bool bPersistentLines = false, float LifeTime = -1.0f, uint8 DepthPriority = 0, float Tickness = 0.0f);
	static void DrawSphere(const UWorld* InWorld, FVector const& Center, float Radius, FColor const& Color, float LifeTime = -1.0f, int32 Segments = 40, bool bPersistentLines = false, uint8 DepthPriority = 0, float Tickness = 0.0f);
};
