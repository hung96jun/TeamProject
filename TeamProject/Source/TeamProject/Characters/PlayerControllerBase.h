#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "PlayerControllerBase.generated.h"

/**
 * 
 */
class ACharacterBase;

UCLASS()
class TEAMPROJECT_API APlayerControllerBase : public APlayerController
{
	GENERATED_BODY()
	
public:
	APlayerControllerBase();

	virtual void PlayerTick(float DeltaTime) final;

protected:
	virtual void BeginPlay() final;

	virtual void OnPossess(APawn* aPawn) override;

private:
	//ACharacterBase* Owner = NULL;
};
