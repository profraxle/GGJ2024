// Copyright 2024 Crows in a Crisis


#include "Cart.h"
#include "PickupObject.h"

// Sets default values
ACart::ACart()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Grapple with Black Magics
	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Box"));

	FScriptDelegate delegate;//Attach collision sphere to onComponentHit func
	delegate.BindUFunction(this, "OnComponentHit");
	CollisionBox->OnComponentBeginOverlap.AddUnique(delegate);

	//Finish collision box setup
	CollisionBox->SetupAttachment(RootComponent);
	CollisionBox->SetRelativeLocation(FVector(0.0f, 0.0f, 0.0f));

}

// Called when the game starts or when spawned
void ACart::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACart::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (currentItem)
	{
		APickupObject* item = Cast<APickupObject>(currentItem);
		if (item->myPlayer == nullptr)
		{
			item->myCart = this;
			//if (!collectedItems.Contains(item))
			//{
				collectedItems.Add(item);
				currentItem = nullptr;
				item->cartHeight = currentHeight;
			//	currentHeight += 30.f;
			//}
		}
	}

}

//Collision With Another Collision Box (i guess it doesnt have to be a box but whatever)
void ACart::OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor)
	{
		if (OtherActor->ActorHasTag("Item"))
		{
			currentItem = OtherActor;
		}
	}
}

float ACart::GetHeight()
{
	return currentHeight;
}