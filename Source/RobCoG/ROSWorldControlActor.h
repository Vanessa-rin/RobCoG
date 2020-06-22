// Copyright 2019, Institute for Artificial Intelligence - University of Bremen

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UROSCallbackRegisterBase.h"
#include "ROSWorldControlActor.generated.h"

UCLASS()
class ROBCOG_API AROSWorldControlActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AROSWorldControlActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, Category = "ROSWorldControl")
	TSubclassOf<UROSCallbackRegisterBase> RWCRegistrationClass;

	UPROPERTY(EditAnywhere, Category = "ROSWorldControl")
	FString Namespace = TEXT("pie_rwc");


};