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

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Tags
	//UPROPERTY(EditAnywhere, BlueprintReadWrite, AdvancedDisplay, Category=Actor)
	//TArray<FName> Tags;
	
	//Player picking me up
	AActor* myPlayer;
	USceneComponent* myPlayerAttachPoint;

	bool canBePickedUp = true;
};
