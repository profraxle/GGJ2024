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
	CollisionBox->OnComponentHit.AddUnique(delegate);

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

	const int arrayLength = collectedItems.Num();
	if (arrayLength != arrayTotal)
	{
		
	}
}

//Collision With Another Collision Box (i guess it doesnt have to be a box but whatever)
void ACart::OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	if (OtherActor->ActorHasTag("Item"))
	{	
		arrayTotal = collectedItems.Num();
		currentItem = OtherActor;
		APickupObject* item = Cast<APickupObject>(OtherActor);
		item->myCart = this;
		item->isBeingCarried = false;

		if (item->care)
		{
			collectedItems.Add(item);
			currentHeight += 20.f;
			item->care = false;
		}

	}
}

float ACart::GetHeight()
{
	return collectedItems.Num();
}
