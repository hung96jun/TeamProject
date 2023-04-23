// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Characters/CharacterBase.h"
#include "PlayerBase.generated.h"

/**
 * 
 */
namespace CameraMode
{
	enum Type
	{
		FirstPerson,
		ThirdPerson,
		PreView,
	};
}

UCLASS()
class TEAMPROJECT_API APlayerBase : public ACharacterBase
{
	GENERATED_BODY()
	
protected:
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Component")
		class USpringArmComponent* CameraArm = NULL;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Component")
		class UCameraComponent* Camera = NULL;

	UPROPERTY(BlueprintReadWrite, VisibleAnywhere, Category = "Component")
		class UCapsuleComponent* Collision = NULL;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Controller")
		FVector2D MouseSensitive = FVector2D(10.0f, 10.0f);

public:
	APlayerBase();

	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	virtual void OnAttack() override;
	virtual void OnSmash() override;
	virtual void OnEvation() override;

	virtual void OnDeathEffect() override;
	//virtual void SetDeathState() override;
	virtual void Death() override;

	//////////////////////////////////////////////////////////////////////////////
	// Action Bind Functions
	//////////////////////////////////////////////////////////////////////////////
	void OnRightClick();
	void OnLeftClick();
	void OnSpace();
	//////////////////////////////////////////////////////////////////////////////

	//////////////////////////////////////////////////////////////////////////////
	// Axis Bind Functions
	//////////////////////////////////////////////////////////////////////////////
	void HorizontalLook(float Value);
	void VerticalLook(float Value);

	void ForwardMove(float Value);
	void RightMove(float Value);
	//////////////////////////////////////////////////////////////////////////////

	void SetCameraMode(const CameraMode::Type ModeNum);

private:
	bool OnAttacking = false;
	bool OnSmashing = false;

	UINT AttackCombo = 0;

	float test;
};
