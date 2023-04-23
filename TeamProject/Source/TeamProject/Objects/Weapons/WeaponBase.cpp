#include "Objects/Weapons/WeaponBase.h"
#include "Components/BoxComponent.h"

#include "Characters/CharacterBase.h"


AWeaponBase::AWeaponBase()
{
	PrimaryActorTick.bCanEverTick = true;

	{
		Collision = CreateDefaultSubobject<UBoxComponent>("Collision");
	}
}

void AWeaponBase::BeginPlay()
{
	Super::BeginPlay();

	Owner = Cast<ACharacterBase>(GetOwner());
	
	Collision->OnComponentBeginOverlap.AddDynamic(this, &AWeaponBase::OnBegin);
	Collision->OnComponentEndOverlap.AddDynamic(this, &AWeaponBase::OnEnd);
	Collision->OnComponentHit.AddDynamic(this, &AWeaponBase::OnHit);
}

void AWeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AWeaponBase::OnBegin(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == NULL) return;
	if (SweepResult.GetActor() == NULL) return;
	if (SweepResult.GetActor() == this) return;
	if (SweepResult.GetActor() == GetOwner()) return;
	
	ACharacterBase* target = Cast<ACharacterBase>(SweepResult.GetActor());
	if (target == NULL) return;
	
	if (Owner != NULL)
	{
		if (target->GetTeamID() == Owner->GetTeamID())
			return;
	}
}

void AWeaponBase::OnEnd(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

void AWeaponBase::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor == NULL) return;
	if (Hit.GetActor() == NULL) return;
	if (Hit.GetActor() == this) return;
	if (Hit.GetActor() == GetOwner()) return;

	ACharacterBase* target = Cast<ACharacterBase>(Hit.GetActor());
	if (target == NULL) return;

	if (Owner != NULL)
	{
		if (target->GetTeamID() == Owner->GetTeamID())
			return;
	}
}


