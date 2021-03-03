// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "laserGates_base.generated.h"

UCLASS()
class PLAYASOBJECT_API AlaserGates_base : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AlaserGates_base();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "meshes", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Sensor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DoorType", meta = (AllowPrivateAccess = "true"))
		TArray<class AOpendoorBase*> gates;

	bool isOpen;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
