#include "Characters/AnimInstanceBase.h"
//#include "KismetAnimationLibrary.h"

#include "Characters/CharacterBase.h"
#include "Utilities/CLog.h"

UAnimInstanceBase::UAnimInstanceBase()
{
}

void UAnimInstanceBase::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	Owner = Cast<ACharacterBase>(TryGetPawnOwner());
	if (Owner == NULL)
	{
		FString error = L"Class UAnimInstanceBase - NativeBeginPlay Owner value is NULL, Line : ";
		error.AppendInt(__LINE__ + 2);
		CLog::Print(error, 1000.0f, FColor::Red);
	}
}

void UAnimInstanceBase::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	//Direction = UKismetAnimationLibrary::CalculateDirection(Owner->GetVelocity(), Owner->GetActorRotation());

}
