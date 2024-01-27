// Copyright 2024 Crows in a Crisis

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PickupObject.generated.h"

UCLASS()
class GGJ2024_API APickupObject : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickupObject();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	FString funny;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Getting Picked Up
	AActor* myPlayer;						//The Player
	USceneComponent* myPlayerAttachPoint;	//The Players Attach Point
};
