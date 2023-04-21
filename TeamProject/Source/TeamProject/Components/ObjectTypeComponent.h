#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/DataTable.h"
#include "ObjectTypeComponent.generated.h"


USTRUCT(BlueprintType)
struct FObjectData : public FTableRowBase
{
	GENERATED_BODY()

public:
	FObjectData()
	{
		Name = FName(L"");
		//ObjectType = ObjectType::None;
	}

	//ObjectData(const FName Name, const ObjectType::Type Type)
	//{
	//	this->Name = Name;
	//	ObjectType = Type;
	//}

	//ObjectData& operator=(ObjectData const& Other)
	//{
	//	Name = Other.Name;
	//	ObjectType = Other.ObjectType;

	//	return *this;
	//}

	//bool operator==(ObjectData const& Other)
	//{
	//	bool b_result = true;

	//	if (Name != Other.Name ||
	//		ObjectType != Other.ObjectType)
	//		b_result = false;

	//	return b_result;
	//}

	//bool operator!=(ObjectData const& Other)
	//{
	//	bool b_result = false;

	//	if (Name == Other.Name ||
	//		ObjectType == Other.ObjectType)
	//		b_result = true;

	//	return b_result;
	//}

	const FName GetName() const { return Name; }
	//const ObjectType::Type GetType() const { return ObjectType; }

protected:
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
		FName Name;
	//UPROPERTY(BlueprintReadOnly, EditAnywhere)
	//	TEnumAsByte<ObjectType::Type> e_ObjectType;
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TEAMPROJECT_API UObjectTypeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	UObjectTypeComponent();

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	///**
	//* The value of the variable to be passed as a parameter is based
	//* on the information stored in the Datas/DT_ObjectDataTable DataTable.
	//* @param	Name	Datas/DT_ObjectDataTable Name of object stored in DataTable
	//*/
	//const static ObjectType::Type GetObjectType(const FString Name);

	/**
	* Only call in the GameInstance
	* Define the information of Datas/DT_ObjectDataTable in stl_ObjectDatas.
	*/
	static void SetObjectDataTable(const UObject* WorldContextObject);

protected:
	virtual void BeginPlay() override;

protected:
	static class UDataTable* ObjectDataTable;

	//static TMap<FName, E_ObjectType::Type> stl_ObjectDatas;
};
