#include "Characters/Players/PlayerBase.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/GameplayStatics.h"

#include "Utilities/CLog.h"


APlayerBase::APlayerBase()
{
	FString path = L"";

	{
		CameraArm = CreateDefaultSubobject<USpringArmComponent>("FollowArm");
		Camera = CreateDefaultSubobject<UCameraComponent>("Camera");

		CameraArm->SetupAttachment(RootComponent);
		Camera->SetupAttachment(CameraArm);

		SetCameraMode(CameraMode::ThirdPerson);
	}

	{
		Collision = GetCapsuleComponent();
	}
}

void APlayerBase::BeginPlay()
{
	Super::BeginPlay();
}

void APlayerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FString debug = L"";
	{
		debug = "Vertical Look Value : " + FString::SanitizeFloat(test);
		CLog::Print(debug, 0.001f, FColor::Yellow);

	}
}

void APlayerBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	/// Axis Bind Function
	PlayerInputComponent->BindAxis("HorizontalLook", this, &APlayerBase::HorizontalLook);
	PlayerInputComponent->BindAxis("VerticalLook", this, &APlayerBase::VerticalLook);
	PlayerInputComponent->BindAxis("MoveForward", this, &APlayerBase::ForwardMove);
	PlayerInputComponent->BindAxis("MoveRight", this, &APlayerBase::RightMove);

	/// Action Bind Function
	PlayerInputComponent->BindAction("LeftClick", IE_Pressed, this, &APlayerBase::OnLeftClick);
	PlayerInputComponent->BindAction("RightClick", IE_Pressed, this, &APlayerBase::OnRightClick);
	PlayerInputComponent->BindAction("Space", IE_Pressed, this, &APlayerBase::OnSpace);
}

void APlayerBase::OnAttack()
{
	Super::OnAttack();

}

void APlayerBase::OnSmash()
{
	Super::OnSmash();

}

void APlayerBase::OnEvation()
{
	Super::OnEvation();

}

void APlayerBase::OnDeathEffect()
{
	Super::OnDeathEffect();

}

//void APlayerBase::SetDeathState()
//{
//	Super::SetDeathState();
//
//}

void APlayerBase::Death()
{
	Super::Death();

}

#pragma region Action Bind
void APlayerBase::OnRightClick()
{
	OnSmash();
}

void APlayerBase::OnLeftClick()
{
	OnAttack();
}

void APlayerBase::OnSpace()
{
	OnEvation();
}
#pragma endregion

#pragma region Axis Bind
void APlayerBase::HorizontalLook(float Value)
{
	float yaw = MouseSensitive.X * Value * UGameplayStatics::GetWorldDeltaSeconds(this);

	AddControllerYawInput(yaw);
}

void APlayerBase::VerticalLook(float Value)
{
	float pitch = MouseSensitive.Y * Value * UGameplayStatics::GetWorldDeltaSeconds(this);

	test = pitch;

	AddControllerPitchInput(pitch);
}

void APlayerBase::ForwardMove(float Value)
{
	FVector forward = GetActorForwardVector();
	forward.Normalize();

	forward *= CurrentMovement.GetWalkSpeed() * UGameplayStatics::GetWorldDeltaSeconds(this);

	AddMovementInput(forward, Value);
}

void APlayerBase::RightMove(float Value)
{
	FVector right = GetActorRightVector();
	right.Normalize();

	right *= CurrentMovement.GetWalkSpeed() * UGameplayStatics::GetWorldDeltaSeconds(this);

	AddMovementInput(right, Value);
}
#pragma endregion

void APlayerBase::SetCameraMode(const CameraMode::Type ModeNum)
{
	switch (ModeNum)
	{
	case CameraMode::FirstPerson:
		break;
	case CameraMode::ThirdPerson:		/// Default CameraMode
	{
		CameraArm->TargetArmLength = 450.0f;
		CameraArm->SocketOffset.Z = 270.0f;
		Camera->AddRelativeRotation(FRotator(-20.0f, 0.0f, 0.0f));
		CameraArm->bUsePawnControlRotation = true;
		CameraArm->bInheritPitch = true;
		CameraArm->bInheritRoll = true;
		CameraArm->bInheritYaw = true;
		CameraArm->bDoCollisionTest = true;
		bUseControllerRotationYaw = true;
	}
		break;
	case CameraMode::PreView:
		break;
	default:
		break;
	}
}
