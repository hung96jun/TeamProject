// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "MonsterBase.generated.h"

/**
 * 
 */
UCLASS()
class TEAMPROJECT_API AMonsterBase : public ACharacterBase
{
	GENERATED_BODY()

public:
	AMonsterBase();

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

	virtual void OnAttack() override;
	virtual void OnSmash() override;
	virtual void OnEvation() override;

	virtual void OnDeathEffect() override;
	//virtual void SetDeathState() override;
	virtual void Death() override;

};
