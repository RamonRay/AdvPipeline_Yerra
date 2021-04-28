// Fill out your copyright notice in the Description page of Project Settings.


#include "Leg_Control.h"
#include "RenderDebug.h"

// Sets default values for this component's properties
ULeg_Control::ULeg_Control()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void ULeg_Control::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void ULeg_Control::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

FVector ULeg_Control::LineTrace() 
{
	FHitResult result;
	FVector startLocation = GetComponentLocation();
	FVector direction = GetForwardVector();
	FVector targetLocation = startLocation + direction * detectLength;
	FCollisionQueryParams fqueryParams;
	FCollisionResponseParams fResponseParams;
	bool hit = GetWorld() -> LineTraceSingleByChannel(
		result,
		startLocation,
		targetLocation,
		ECC_Visibility,
		fqueryParams,
		fResponseParams
	);

	if (hit) {
		return result.ImpactPoint;
	}
	else {
		return targetLocation;
	}
}

