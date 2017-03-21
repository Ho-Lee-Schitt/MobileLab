// Fill out your copyright notice in the Description page of Project Settings.

#include "Lab7.h"
#include "GolfBall.h"


// Sets default values
AGolfBall::AGolfBall()
{
	// Load a mesh for the golfball from the starter pack
	static ConstructorHelpers::FObjectFinder<UStaticMesh> BallMesh(TEXT("/Game/MobileStarterContent/Props/MaterialSphere.MaterialSphere"));

	// Create mesh component for the ball
	Ball = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Ball0"));
	Ball->SetStaticMesh(BallMesh.Object);
	Ball->BodyInstance.SetCollisionProfileName(UCollisionProfile::PhysicsActor_ProfileName);
	Ball->SetSimulatePhysics(true);
	Ball->SetAngularDamping(0.1f);
	Ball->SetLinearDamping(0.1f);
	Ball->BodyInstance.MassScale = 3.5f;
	Ball->BodyInstance.MaxAngularVelocity = 800.0f;
	Ball->SetNotifyRigidBodyCollision(true);
	RootComponent = Ball;

	UE_LOG(LogTemp, Warning, TEXT("Golf Ball Constructor called"));

 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AGolfBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGolfBall::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

void AGolfBall::Hit(float force, FVector *direction)
{
	UE_LOG(LogTemp, Warning, TEXT("Hit called with %f force"), force);
	UE_LOG(LogTemp, Warning, TEXT("Direction is %s"), *direction->ToString());
	//Ball->AddImpulse(FVector(0.0f, 0.0f, (1.0f * force)));
	Ball->AddForce((*direction)* force);
	const FVector Impulse = FVector(0.0f, 0.0f, force);
}


