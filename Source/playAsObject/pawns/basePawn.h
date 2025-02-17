// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "basePawn.generated.h"

UCLASS()
class PLAYASOBJECT_API AbasePawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AbasePawn();

	/*camera behind the player*/
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class USpringArmComponent* cameraBoom;

	/* main camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* FollowCamera;

	//mesh
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* mesh;

	//material collection
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MatCollection", meta = (AllowPrivateAccess = "true"))
	class UMaterialParameterCollection* MaterialParameterCollectionAsset;

	class UMaterialParameterCollectionInstance* Matinst;
	
	//pitch limit
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CAMERA_S", meta = (AllowPrivateAccess = "true"))
		float limitMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CAMERA_S", meta = (AllowPrivateAccess = "true"))
		float limitMax;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
		void CameraYaw_z(float val);

	UFUNCTION()
		void CameraPitch_y(float val);
	
	UFUNCTION()
		void ScanForObj(float val);

	UFUNCTION()
		void changePawn();

};
