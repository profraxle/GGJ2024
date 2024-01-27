// Copyright 2024 Crows in a Crisis

#pragma once

#include "CoreMinimal.h"
#include "Components/BoxComponent.h"
#include "GameFramework/Actor.h"
#include "Cart.generated.h"

UCLASS()
class GGJ2024_API ACart : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACart();

	//Collision
	UPROPERTY(EditAnywhere)
	UBoxComponent* CollisionBox;					//Collision Box

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//Array of the items collected
	TArray<AActor*> collectedItems;



	float currentHeight = 40.f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	float GetHeight();

	//Collision 
	UFUNCTION() void OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	AActor* currentItem;
};
