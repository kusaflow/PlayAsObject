// Fill out your copyright notice in the Description page of Project Settings.


#include "doorTriggerBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "../../pawns/basePawn.h"
#include "OpendoorBase.h"

// Sets default values
AdoorTriggerBase::AdoorTriggerBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	box = CreateDefaultSubobject<UBoxComponent>(TEXT("box"));
	RootComponent = box;

	box->InitBoxExtent(FVector(150,150,32));

	base = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	base->SetupAttachment(box);

	base->SetRelativeScale3D(FVector((1.167153, 1.167763, 0.163143)));

	trigger = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("trigger"));
	trigger->SetupAttachment(box);

	trigger->SetRelativeScale3D(FVector(1.506446, 1.506446, 0.090000));

	box->OnComponentBeginOverlap.AddDynamic(this, &AdoorTriggerBase::OnOverlapBegin);
	box->OnComponentEndOverlap.AddDynamic(this, &AdoorTriggerBase::OnOverlapEnd);

}

// Called when the game starts or when spawned
void AdoorTriggerBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AdoorTriggerBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AdoorTriggerBase::OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	AbasePawn* myPawn = Cast<AbasePawn>(OtherActor);
	if (myPawn) {
		trigger->SetRelativeLocation(FVector(0,0,-9));
		for (int i = 0; i < gates.Num(); i++) {
			gates[i]->bDoOpen = !gates[i]->bDoOpen;
		}
	}
}

void AdoorTriggerBase::OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	AbasePawn* myPawn = Cast<AbasePawn>(OtherActor);
	if (myPawn) {
		trigger->SetRelativeLocation(FVector(0, 0, 0));
		for (int i = 0; i < gates.Num(); i++) {
			gates[i]->bDoOpen = !gates[i]->bDoOpen;
		}
	}
}

