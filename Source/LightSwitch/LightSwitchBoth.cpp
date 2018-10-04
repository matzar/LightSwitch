// Fill out your copyright notice in the Description page of Project Settings.

#include "LightSwitchBoth.h"
#include "Components/PointLightComponent.h"
#include "Components/SphereComponent.h"

// Sets default values
ALightSwitchBoth::ALightSwitchBoth()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DesiredIntensity = 3000.0f;

	/** Create the PointLightComponent, set its variables (including setting its intensity to the value of DesiredIntensity), and make it the root component. **/
	// Create the PointLight component
	PointLight = CreateDefaultSubobject<UPointLightComponent>(TEXT("PointLight"));
	// set its intensity to DesiredIntensity variable
	PointLight->Intensity = DesiredIntensity;
	// set the light's visibility
	PointLight->bVisible = true;
	// set the root component to PointLight
	RootComponent = PointLight;

	/** Create the SphereComponent, set its variables, and attach it to the PointLightComponent. **/
	// create the SphereComponent
	Sphere = CreateAbstractDefaultSubobject<USphereComponent>(TEXT("Sphere"));
	// set sphere's radios
	Sphere->InitSphereRadius(250.0f);
	// Attach Sphere to PointLight
	Sphere->SetupAttachment(PointLight);

	/** Designate the OnOverlap function as a delegate called when an Actor overlaps or leaves the SphereComponent. **/

	Sphere->OnComponentBeginOverlap.AddDynamic(this, &ALightSwitchBoth::OnOverlapBegin); // setup a notification for when this component overlaps something
	Sphere->OnComponentEndOverlap.AddDynamic(this, &ALightSwitchBoth::OnOverlapEnd); // setup a notification for when this component (ends?) overlaping something
}


void ALightSwitchBoth::OnOverlapBegin_Implementation(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

void ALightSwitchBoth::OnOverlapEnd_Implementation(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor && (OtherActor != this) && OtherComp)
	{
		ToggleLight();
	}
}

void ALightSwitchBoth::ToggleLight()
{
	PointLight->ToggleVisibility();
}

