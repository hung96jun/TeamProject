#include "Characters/CharacterBase.h"
#include "GameFramework/PawnMovementComponent.h"

FMovementInf FMovementInf::Zero = FMovementInf(700.0f, 150.0f, 270.0f, 350.0f, 1.5f);
FCharacterStatus FCharacterStatus::Zero = FCharacterStatus(100.0f, 100.0f, 10.0f, 10.0f, 10.0f);

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();

	if (Status != FCharacterStatus::Zero)
		OriginStatus = Status;

	if (Movement != FMovementInf::Zero)
		OriginMovement = Movement;

	ResetMovementStatus();
	ResetCharacterStatus();
}

void ACharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

const bool ACharacterBase::IsFalling() const
{
	return GetMovementComponent()->IsFalling();
}

void ACharacterBase::ResetMovementStatus()
{
	CurrentMovement = OriginMovement;
}

void ACharacterBase::ResetCharacterStatus()
{
	CurrentStatus = OriginStatus;
}

void ACharacterBase::OnDeathEffect()
{
}

//void ACharacterBase::SetDeathState()
//{
//}

void ACharacterBase::Death()
{
}
