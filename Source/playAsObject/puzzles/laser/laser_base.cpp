// Fill out your copyright notice in the Description page of Project Settings.


#include "laser_base.h"
#include "DrawDebugHelpers.h"
#include "Materials/Material.h"
#include "Kismet/KismetMathLibrary.h"
#include "laserMesh.h"
#include "../laserGate/laserGates_base.h"

// Sets default values
Alaser_base::Alaser_base()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	laserBody = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("laserParent"));
	RootComponent = laserBody;

	laserPoint = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("LaserPoint"));
	laserPoint->SetupAttachment(laserBody);

	traceLen = 1000;

}

// Called when the game starts or when spawned
void Alaser_base::BeginPlay()
{
	Super::BeginPlay();
	traceLaser = 0;
}

// Called every frame
void Alaser_base::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


	if (traceLaser >= 20) {
		traceLaser = 0;
		//Line Trace
		
		FHitResult OutHit;
		FVector Start;

		FVector direction;

		FVector End;
		FCollisionQueryParams CollisionParams;
		CollisionParams.bTraceComplex = true;

		direction = laserPoint->GetForwardVector();
		Start = laserPoint->GetComponentLocation();
		laserBounce = 0;

		//clear mesh data
		int cnt = lm_array.Num();

		for (int i = 0; i < cnt; i++) {
			lm_array.Pop()->Destroy();
		}

		do {
			laserBounce++;
			if (laserBounce >= 10)
				break;
			End = Start + traceLen * direction;

			
			FVector TraceMeshEnd = End;
			FVector TraceMeshStart = Start;

			
			//DrawDebugLine(GetWorld(), Start, End, FColor::Orange, false, 0.1f, 0, 7);
			bShouldRef = false;
			if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_laserTrace, CollisionParams)) {
				
				AlaserGates_base* laserGate = Cast<AlaserGates_base>(OutHit.GetActor());

				if (laserGate) {

				}
				else {

					TraceMeshEnd = OutHit.ImpactPoint;

					if (OutHit.GetActor()->ActorHasTag("mirror"))
					{

						bShouldRef = true;
						Start = OutHit.ImpactPoint;
						direction = direction.MirrorByVector(OutHit.ImpactNormal);

					}

				}

			}
			else {
				//render=====================

				FActorSpawnParameters spawnPara;
				spawnPara.Owner = this;

				UWorld* world = GetWorld();
				if (world && lm) {
					AlaserMesh* Lmesh = world->SpawnActor<AlaserMesh>(lm, FVector(0),
						FRotator(0), spawnPara);

					Lmesh->setTrans(TraceMeshStart, TraceMeshEnd);

					lm_array.Add(Lmesh);
				}


				//===============================

				break;
			}

			//render=====================
			
			FActorSpawnParameters spawnPara;
			spawnPara.Owner = this;

			UWorld* world = GetWorld();
			if (world && lm) {
				AlaserMesh* Lmesh = world->SpawnActor<AlaserMesh>(lm, FVector(0),
					FRotator(0), spawnPara);

				Lmesh->setTrans(TraceMeshStart, TraceMeshEnd);

				lm_array.Add(Lmesh);
			}

			
			//===============================

		} while (bShouldRef);
	}
	else {
		traceLaser += 400 * DeltaTime;
	}


}

