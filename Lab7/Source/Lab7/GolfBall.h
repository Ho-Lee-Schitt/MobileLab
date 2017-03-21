// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "GolfBall.generated.h"

UCLASS()
class LAB7_API AGolfBall : public AActor
{
	GENERATED_BODY()

		/* StaticMesh used for the ball */
		UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Ball, meta = (AllowPrivateAccess = "true"))
		class UStaticMeshComponent* Ball;
	
public:	
	// Sets default values for this actor's properties
	AGolfBall();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	void Hit(float force, FVector *direction);

};
