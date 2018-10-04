// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "LightSwitchBoth.generated.h"

/*
There is a Blueprintable specifier for the UCLASS() macro. 
It is not necessary in this case because LightSwitchBoth inherits directly from Actor, 
which is Blueprintable, and the Blueprintable specifier is inherited.
*/
UCLASS()
class LIGHTSWITCH_API ALightSwitchBoth : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ALightSwitchBoth();

	// VARIABLES
public:
	/** point light component **/
	//UPROPERTY(VisibleAnywhere, CPF_BlueprintReadOnly, Category = "Switch Components")
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Switch Components")
	class UPointLightComponent* PointLight;

	/** sphere component **/
	UPROPERTY(VisibleAnywhere, BluePrintReadOnly, Category = "Switch Components")
	class USphereComponent* Sphere;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Switch Variables")
	float DesiredIntensity;

	// FUNCTIONS
public:
	/** called when something enters the sphere component **/
	UFUNCTION(BlueprintNativeEvent, Category = "Switch Functions")
	void OnOverlapBegin(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	/** called when something leaves the sphere component **/
	UFUNCTION(BlueprintNativeEvent, Category = "Switch Functions")
	void OnOverlapEnd(class UPrimitiveComponent* OverlappedComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex);

	/** Toggles the light component's visibility **/
	UFUNCTION()
	void ToggleLight();

	
};
