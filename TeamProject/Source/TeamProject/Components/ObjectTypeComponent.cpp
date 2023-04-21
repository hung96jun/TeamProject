#include "Components/ObjectTypeComponent.h"
#include "Kismet/GameplayStatics.h"

//#include "Utilities/CLog.h"

UObjectTypeComponent::UObjectTypeComponent()
{
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

void UObjectTypeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UObjectTypeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UObjectTypeComponent::SetObjectDataTable(const UObject* WorldContextObject)
{

}
