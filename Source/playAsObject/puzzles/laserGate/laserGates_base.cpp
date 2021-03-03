// Fill out your copyright notice in the Description page of Project Settings.


#include "laserGates_base.h"
#include "../openDoor/OpendoorBase.h"

// Sets default values
AlaserGates_base::AlaserGates_base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Sensor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Sensor"));
	RootComponent = Sensor;

	isOpen = false;

}

// Called when the game starts or when spawned
void AlaserGates_base::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AlaserGates_base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	for (int i = 0; i < gates.Num(); i++) {
		gates[i]->bDoOpen = isOpen;
	}
	

}

