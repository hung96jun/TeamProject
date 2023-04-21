#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Engine/DataTable.h"
#include "GenericTeamAgentInterface.h"
#include "CharacterBase.generated.h"


USTRUCT(BlueprintType)
struct FMovementInf : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	const float GetJumpPower() const { return JumpPower; }
	const float GetWalkSpeed() const { return WalkSpeed; }
	const float GetJogSpeed() const { return JogSpeed; }
	const float GetRunSpeed() const { return RunSpeed; }
	const float GetAccelTimer() const { return AccelTimer; }

	void SetJumpPower(const float Value) { JumpPower = Value; }
	void SetWalkSpeed(const float Value) { WalkSpeed = Value; }
	void SetJogSpeed(const float Value) { JogSpeed = Value; }
	void SetRunSpeed(const float Value) { RunSpeed = Value; }
	void SetAccelTimer(const float Value) { AccelTimer = Value; }

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float JumpPower = 700.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float WalkSpeed = 150.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float JogSpeed = 270.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float RunSpeed = 350.0f;
	UPROPERTY(BlueprintReadWrite, VisibleAnywhere)
		float AccelTimer = 1.5f;
};

USTRUCT(BlueprintType)
struct FCharacterStatus : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	FCharacterStatus()
	{
		Health = 100.0f;
		Stamina = 100.0f;
		Strength = 10.0f;
		Agility = 10.0f;
		Defence = 10.0f;
	}

	FCharacterStatus(const float Health, const float Stamina, const float Strength, const float Agility, const float Defence)
	{
		this->Health = Health;
		this->Stamina = Stamina;
		this->Strength = Strength;
		this->Agility = Agility;
		this->Defence = Defence;
	}

	const float GetHealth() const { return Health; }
	const float GetStamina() const { return Stamina; }
	const float GetStrength() const { return Strength; }
	const float GetAgility() const { return Agility; }
	const float GetDefence() const { return Defence; }

	float SetHealth(const float Value) { Health = Value; }
	float SetStamina(const float Value) { Stamina = Value; }
	float SetStrength(const float Value) { Strength = Value; }
	float SetAgility(const float Value) { Agility = Value; }
	float SetDefence(const float Value) { Defence = Value; }

protected:
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Health = 100.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Stamina = 100.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Strength = 10.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Agility = 10.0f;
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
		float Defence = 10.0f;
};

UCLASS()
class TEAMPROJECT_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

protected:
	/*
	* TeamID
	* @0 : None
	* @1, 2 : Player
	* @3, 4 : Monster
	*/
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character")
		uint8 TeamID = 0;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Status")
		const FCharacterStatus OriginStatus;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Status")
		FCharacterStatus CurrentStatus;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Movement")
		const FMovementInf OriginMovement;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Movement")
		FMovementInf CurrentMovement;

public:
	ACharacterBase();
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	const bool IsFalling() const;

protected:
	virtual void BeginPlay() override;

	virtual void OnDeathEffect();
	virtual void SetDeathState();
	virtual void Death();

private:
	FTimerDelegate MovementTimerDel;
	FTimerHandle MovementTimerHandle;


};
