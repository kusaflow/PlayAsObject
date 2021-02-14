// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "OpendoorBase.generated.h"

UCLASS()
class PLAYASOBJECT_API AOpendoorBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AOpendoorBase();

	//mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* mesh;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UBoxComponent* box;

	//doorType
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DoorType", meta = (AllowPrivateAccess = "true"))
	int DoorType;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DoorType", meta = (AllowPrivateAccess = "true"))
	float OpenSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DoorType", meta = (AllowPrivateAccess = "true"))
	float CloseSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DoorType", meta = (AllowPrivateAccess = "true"))
	bool bDoOpen;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DoorType", meta = (AllowPrivateAccess = "true"))
	float openPos;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "DoorType", meta = (AllowPrivateAccess = "true"))
	float closePos;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
