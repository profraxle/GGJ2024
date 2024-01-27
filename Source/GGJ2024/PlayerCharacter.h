// Copyright 2024 Crows in a Crisis

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputActionValue.h"
#include "InputAction.h"
#include "Components/BoxComponent.h"
#include "Engine/StaticMesh.h"
#include "Camera/CameraActor.h"
#include "PlayerCharacter.generated.h"

class UInputMappingContext;
class UInputAction;
class UCameraComponent;

UCLASS()
class GGJ2024_API APlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APlayerCharacter();

	//--- Input Actions ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputMappingContext* playerMappingContext;		//Mapping Context

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputAction* moveAction;						//Move Input Action

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputAction* grabAction;						//Grab Input Action

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UInputAction* dropAction;						//Drop Input Action

	//Camera
	UPROPERTY(EditAnywhere)
	UCameraComponent* cam;							//Static Camera

	//Collision
	UPROPERTY(EditAnywhere)
	UBoxComponent* CollisionBox;					//Collision Box

	//Picked Up Item
	UPROPERTY(EditAnywhere)
	UStaticMesh* ItemMesh;							//Item Following Player

	UPROPERTY(EditAnywhere)
	USceneComponent* AttachPoint;			//Where the item will follow		

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	bool holdingObject = false;
	float grabTime = 0.5f;
	float dropTime = 2.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	AActor* itemTouched;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Movement function for player
	void Move(const FInputActionValue& Value);

	//Pickup/Drop item
	void Grab(const FInputActionValue& Value);
	void Drop(const FInputActionValue& Value);

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//Collision 
	UFUNCTION() void OnComponentHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
};
