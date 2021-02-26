// Fill out your copyright notice in the Description page of Project Settings.


#include "laserMesh.h"

// Sets default values
AlaserMesh::AlaserMesh()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Lmesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Lmesh"));
	RootComponent = Lmesh;

	LaserThickness = 0.05;
}


// Called when the game starts or when spawned
void AlaserMesh::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AlaserMesh::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AlaserMesh :: setTrans(FVector start, FVector end) {

	laserMeshProj(start, end);
	/*
	FVector norm = start - end;
	FVector forScale = norm;
	norm.Normalize();
	FRotator newRot = FRotationMatrix::MakeFromZ(norm).Rotator();

	Lmesh->SetWorldLocation(start);
	Lmesh->SetWorldRotation(newRot);
	Lmesh->SetWorldScale3D(FVector(LaserThickness, LaserThickness,forScale.Size()*-1/100));
	*/

}
