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
	FMovementInf()
	{
		JumpPower = 700.0f;
		WalkSpeed = 150.0f;
		JogSpeed = 270.0f;
		RunSpeed = 350.0f;
		AccelTimer = 1.5f;
	}

	FMovementInf(const float JumpPower, const float WalkSpeed, const float JogSpeed, const float RunSpeed, const float AccelTimer)
	{
		this->JumpPower = JumpPower;
		this->WalkSpeed = WalkSpeed;
		this->JogSpeed = JogSpeed;
		this->RunSpeed = RunSpeed;
		this->AccelTimer = AccelTimer;
	}

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

	static FMovementInf Zero;

	bool operator!=(FMovementInf& Other)
	{
		if (this->JumpPower == JumpPower)
			return false;
		if (this->WalkSpeed == WalkSpeed)
			return false;
		if (this->JogSpeed == JogSpeed)
			return false;
		if (this->RunSpeed == RunSpeed)
			return false;
		if (this->AccelTimer == AccelTimer)
			return false;

		return true;
	}

	bool operator==(FMovementInf& Other)
	{
		if (this->JumpPower != JumpPower)
			return false;
		if (this->WalkSpeed != WalkSpeed)
			return false;
		if (this->JogSpeed != JogSpeed)
			return false;
		if (this->RunSpeed != RunSpeed)
			return false;
		if (this->AccelTimer != AccelTimer)
			return false;

		return true;
	}

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

	static FCharacterStatus Zero;

	bool operator!=(FCharacterStatus& Other)
	{
		if (this->Health == Other.Health)
			return false;
		if (this->Stamina == Other.Stamina)
			return false;
		if (this->Strength == Other.Strength)
			return false;
		if (this->Agility == Other.Agility)
			return false;
		if (this->Defence == Other.Defence)
			return false;

		return true;
	}

	bool operator==(FCharacterStatus& Other)
	{
		if (this->Health != Other.Health)
			return false;
		if(this->Stamina != Other.Stamina)
			return false;
		if(this->Strength != Other.Strength)
			return false;
		if(this->Agility != Other.Agility)
			return false;
		if(this->Defence != Other.Defence)
			return false;

		return true;
	}

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
		FCharacterStatus Status;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character Status")
		FCharacterStatus CurrentStatus;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Character Movement")
		FMovementInf Movement;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Character Movement")
		FMovementInf CurrentMovement;

public:
	ACharacterBase();
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	const bool IsFalling() const;

	void ResetMovementStatus();
	void ResetCharacterStatus();

	const uint8 GetTeamID() { return TeamID; }

protected:
	virtual void BeginPlay() override;

	virtual void OnAttack() {};
	virtual void OnSmash() {};
	virtual void OnEvation() {};

	virtual void OnDeathEffect();
	//virtual void SetDeathState();
	virtual void Death();

private:
	FTimerDelegate MovementTimerDel;
	FTimerHandle MovementTimerHandle;

private:
	/**
	* Origin값으로 Blueprint에서 수정된 Status 값이 BeginPlay에서 할당된다.
	* 그 외에는 변경되면 안된다.
	*/
	FCharacterStatus OriginStatus;
	/**
	* Origin값으로 Blueprint에서 수정된 Movement 값이 BeginPlay에서 할당된다.
	* 그 외에는 변경되면 안된다.
	*/
	FMovementInf OriginMovement;
};
