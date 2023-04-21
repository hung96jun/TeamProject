#include "Characters/CharacterBase.h"
#include "GameFramework/PawnMovementComponent.h"

ACharacterBase::ACharacterBase()
{
	PrimaryActorTick.bCanEverTick = true;
	
}

void ACharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
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

void ACharacterBase::OnDeathEffect()
{
}

void ACharacterBase::SetDeathState()
{
}

void ACharacterBase::Death()
{
}
