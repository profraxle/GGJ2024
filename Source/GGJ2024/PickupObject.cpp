// Copyright 2024 Crows in a Crisis

#include "PickupObject.h"
#include "Cart.h"
#include "PlayerCharacter.h"


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

	//If im picked up
	if (myPlayer)
	{
		SetActorEnableCollision(false);
		isBeingCarried = true;
		//Attach to Player
		SetActorLocation(myPlayerAttachPoint->GetComponentLocation());
		SetActorRotation(myPlayer->GetActorRotation());
	}
	else {
		//Add collision back if YOU ARE A DUMB BASS RAAAAAAAAAAAAAAAAAAAAAAAGH
		SetActorEnableCollision(true);
		isBeingCarried = false;
	}

	//Deposit
	if (myCart)
	{
		SetActorEnableCollision(false);
		isBeingCarried = false;
		ACart* cart = Cast<ACart>(myCart);

		if (getHeight)
		{
			cartHeight = cart->GetHeight() * 40.f;
			getHeight = false;
		}

		//Attach to Player
		SetActorLocation(FVector(cart->GetActorLocation().X, cart->GetActorLocation().Y, cart->GetActorLocation().Z + cartHeight));
		SetActorRotation(cart->GetActorRotation());

	}
}

