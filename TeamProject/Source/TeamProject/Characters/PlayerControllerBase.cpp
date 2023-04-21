#include "Characters/PlayerControllerBase.h"

#include "Characters/CharacterBase.h"


APlayerControllerBase::APlayerControllerBase()
{

}

void APlayerControllerBase::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

}

void APlayerControllerBase::BeginPlay()
{
	Super::BeginPlay();

}

void APlayerControllerBase::OnPossess(APawn* aPawn)
{
	Super::OnPossess(aPawn);

	if (aPawn == NULL) return;

	//Owner = Cast<ACharacterBase*>(aPawn);
}
