// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "Leg_Control.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class MATERIALTEST_API ULeg_Control : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	ULeg_Control();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	//Get the contact point of the line trace.
	FVector LineTrace();
	FVector GetFootLocation();
	FVector UpdateFoot();

public:
	//Variables
	FVector footLocation;
	FVector footTargetLocation;
	bool isMoving;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float detectLength;
		
};
