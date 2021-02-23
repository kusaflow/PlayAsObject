// Fill out your copyright notice in the Description page of Project Settings.


#include "OpendoorBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"


// Sets default values
AOpendoorBase::AOpendoorBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	box = CreateDefaultSubobject<UBoxComponent>(TEXT("box"));
	RootComponent = box;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	mesh->SetupAttachment(box);

}

// Called when the game starts or when spawned
void AOpendoorBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AOpendoorBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (DoorType == 1) {
		if (bDoOpen) {
			if (openPos > mesh->GetRelativeLocation().Z) {
				mesh->SetRelativeLocation(FVector(0, 0, mesh->GetRelativeLocation().Z + DeltaTime * OpenSpeed));
			}
		}
		else {
			if (closePos < mesh->GetRelativeLocation().Z) {
				mesh->SetRelativeLocation(FVector(0, 0, mesh->GetRelativeLocation().Z - DeltaTime * CloseSpeed));
			}
		}
	}
	else if (DoorType == 2){
		if (bDoOpen) {
			if (openPos > mesh->GetRelativeLocation().Y) {
				mesh->SetRelativeLocation(FVector(0, 0, mesh->GetRelativeLocation().Y + DeltaTime * OpenSpeed));
			}
		}
		else {
			if (closePos < mesh->GetRelativeLocation().Y) {
				mesh->SetRelativeLocation(FVector(0, 0, mesh->GetRelativeLocation().Y - DeltaTime * CloseSpeed));
			}
		}
	}

}

