 // Fill out your copyright notice in the Description page of Project Settings.


#include "basePawn.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/StaticMeshComponent.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialParameterCollection.h"
#include "Materials/MaterialParameterCollectionInstance.h"


// Sets default values
AbasePawn::AbasePawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	RootComponent = mesh;

	cameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	cameraBoom->SetupAttachment(GetRootComponent());
	cameraBoom->bDoCollisionTest = false;
	cameraBoom->TargetArmLength = 800;
	cameraBoom->SocketOffset = FVector(0.f, 0.f, 0.f);
	//cameraBoom->SetRelativeRotation(FRotator(-20, -70, 0.f));
	//cameraBoom->RelativeRotation = FRotator(0.f, 0.f, 0.f);
	//cameraBoom->bUsePawnControlRotation = false;

	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(cameraBoom, USpringArmComponent::SocketName);

	mesh->SetSimulatePhysics(true);
	mesh->SetRenderCustomDepth(true);

	cameraBoom->bInheritPitch = cameraBoom->bInheritRoll = cameraBoom->bInheritYaw = false;

	cameraBoom->bDoCollisionTest = true;

	limitMin = -80;
	limitMax = 4;


}

// Called when the game starts or when spawned
void AbasePawn::BeginPlay()
{
	Super::BeginPlay();

	if (MaterialParameterCollectionAsset) {
		Matinst = GetWorld()->GetParameterCollectionInstance(MaterialParameterCollectionAsset);
	}
}

// Called every frame
void AbasePawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	


}

// Called to bind functionality to input
void AbasePawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("xAxis", this, &AbasePawn::CameraYaw_z);
	PlayerInputComponent->BindAxis("yAxis", this, &AbasePawn::CameraPitch_y);

	PlayerInputComponent->BindAxis("Scan", this, &AbasePawn::ScanForObj);


	PlayerInputComponent->BindAction("changePawn", IE_Pressed, this, &AbasePawn::changePawn);


}


void AbasePawn::CameraYaw_z(float val) {
	FRotator newR = FRotator(0, 0, 0);
	newR.Yaw += val;
	cameraBoom->AddRelativeRotation(newR);

}

void AbasePawn::CameraPitch_y(float val) {
	
	FRotator newR = cameraBoom->GetRelativeRotation();
	newR.Pitch = FMath::Clamp(newR.Pitch + val, limitMin, limitMax);

	cameraBoom->SetRelativeRotation(newR);
}

void AbasePawn::changePawn() {
	
	//Line Trace
	FHitResult OutHit;
	FVector Start = FollowCamera->GetComponentLocation();

	FVector End = ((FollowCamera->GetForwardVector() * 20000.f) + Start);
	FCollisionQueryParams CollisionParams;

	//DrawDebugLine(GetWorld(), Start, End, FColor::Green, false, 0.1f, 0, 1);

	//if ()
	if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams)) {
		//UE_LOG(LogTemp, Warning, TEXT("noice-----------------------------------------"));
		AbasePawn* pawnA = Cast<AbasePawn>(OutHit.Actor);
		if (pawnA) {
			UGameplayStatics::GetPlayerController(GetWorld(), 0)->Possess(pawnA);
		}
		
	}
}

void AbasePawn::ScanForObj(float val) {
	//scan Effect
	if (Matinst) {
		Matinst->SetScalarParameterValue("highLight", val);
	}
}







