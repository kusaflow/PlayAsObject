// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "laserMesh.generated.h"

UCLASS()
class PLAYASOBJECT_API AlaserMesh : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AlaserMesh();


	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "meshes", meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Lmesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Laser", meta = (AllowPrivateAccess = "true"))
		float LaserThickness = 0.05;

	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void setTrans(FVector start, FVector end);

	UFUNCTION(BlueprintImplementableEvent)
		void laserMeshProj(FVector start, FVector end);


};
