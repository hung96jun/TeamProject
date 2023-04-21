#include "CLog.h"
#include "Engine/Engine.h"
#include "DrawDebugHelpers.h"


CLog::CLog()
{
}

CLog::~CLog()
{
}

void CLog::Log(int Value)
{
	GLog->Logf(L"%d", Value);
}

void CLog::Log(float Value)
{
	GLog->Logf(L"%f", Value);
}

void CLog::Log(const FString& Value)
{
	GLog->Log(Value);
}

void CLog::Log(const TCHAR* Value)
{
	GLog->Log(Value);
}

void CLog::Log(const FName& Value)
{
	GLog->Log(Value.ToString());
}

void CLog::LogNull(UObject* Object)
{
	GLog->Log(Object != NULL ? L"Not Null" : L"Null");
}

void CLog::Print(int Value, float Time, FColor Color, int32 Key)
{
	GEngine->AddOnScreenDebugMessage(Key, Time, Color, FString::Printf(L"%d", Value));
}

void CLog::Print(float Value, float Time, FColor Color, int32 Key)
{
	GEngine->AddOnScreenDebugMessage(Key, Time, Color, FString::Printf(L"%f", Value));
}

void CLog::Print(const FString& Value, float Time, FColor Color, int32 Key)
{
	GEngine->AddOnScreenDebugMessage(Key, Time, Color, Value);
}

void CLog::Print(const TCHAR* Value, float Time, FColor Color, int32 Key)
{
	GEngine->AddOnScreenDebugMessage(Key, Time, Color, Value);
}

void CLog::Print(const FName& Value, float Time, FColor Color, int32 Key)
{
	GEngine->AddOnScreenDebugMessage(Key, Time, Color, Value.ToString());
}

void CLog::PrintNull(UObject* Object, float Time, FColor Color, int32 Key)
{
	GEngine->AddOnScreenDebugMessage(Key, Time, Color, Object != NULL ? "Not Null" : "Null");
}

void CLog::DrawLine(const UWorld* InWorld, FVector const& LineStart, FVector const& LineEnd, FColor const& Color, bool bPersistentLines, float LifeTime, float Thickness)
{
	DrawDebugLine(InWorld, LineStart, LineEnd, Color, bPersistentLines, LifeTime, 0, Thickness);
}

void CLog::DrawCircle(const UWorld* InWorld, const FVector Center, float Radius, int32 Segments, const FColor& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Tickness)
{
	DrawDebugCircle(InWorld, Center, Radius, Segments, Color, bPersistentLines, LifeTime, DepthPriority, Tickness);
}

void CLog::DrawCapsule(const UWorld* InWorld, FVector const& Center, float HalfHeight, float Radius, FColor const& Color, bool bPersistentLines, float LifeTime, uint8 DepthPriority, float Tickness)
{
	DrawDebugCapsule(InWorld, Center, HalfHeight, Radius, FRotator(0.0f, 0.0f, 0.0f).Quaternion(), Color, bPersistentLines, LifeTime, DepthPriority, Tickness);
}

void CLog::DrawSphere(const UWorld* InWorld, FVector const& Center, float Radius, FColor const& Color, float LifeTime, int32 Segments, bool bPersistentLines, uint8 DepthPriority, float Tickness)
{
	DrawDebugSphere(InWorld, Center, Radius, Segments, Color, bPersistentLines, LifeTime, DepthPriority, Tickness);
}