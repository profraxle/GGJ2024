// Copyright 2024 Crows in a Crisis

#include "PlayerCharacter.h"
#include "PickupObject.h"

// Sets default values
APickupObject::APickupObject()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APickupObject::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void APickupObject::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (myPlayer)
	{
		SetActorLocation(myPlayerAttachPoint->GetComponentLocation());
		SetActorRotation(myPlayer->GetActorRotation());
		SetActorEnableCollision(false);
	}
}

