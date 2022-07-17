// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "SAttributeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_FourParams(FOnHealthChanged, AActor*, InstigatorActor, USAttributeComponent*, OwningComp, float, NewHealth, float, Delta);

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ACTIONROUGUELIKE_API USAttributeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	USAttributeComponent();

protected:
	// EditAnywhere - edit in BP editor and per-instance in level
	// VisibelAnywhere - 'read-only' in edit and level. {use for components}
	// EditDefaultsOnly - hide variable per instance, edit in BP edit only.
	// VisibleDefaultsOnly - allow only editing of instance (eg. when placed in level)
	
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category = "Attribute")
	float Health;

	// HealthMasx, Stamina,Strength



public:	

	UPROPERTY(BlueprintAssignable) // let us in blueprint or ui let's bind or subscribe to this event.
	FOnHealthChanged OnHealthChanged;

	UFUNCTION(BlueprintCallable,Category = "Attributes")
	bool ApplyHealthChange(float Delta);


};
