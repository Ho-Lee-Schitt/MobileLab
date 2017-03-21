// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Club.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class LAB7_API UClub : public UActorComponent
{
	GENERATED_BODY()
		
public:
	// Sets default values for this component's properties
	UClub();

	// Called when the game starts
	virtual void BeginPlay() override;

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void HitBall();
	void GetGolfBall();
	FVector DrawDebug();
	
private:
	UInputComponent* InputComponent = nullptr;

	// Reference to the golfball in the scene
	UPROPERTY(EditAnywhere)
	class AGolfBall* myGolfBall;

};
