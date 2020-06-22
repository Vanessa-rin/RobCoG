// Copyright 2019, Institute for Artificial Intelligence - University of Bremen


#include "ROSWorldControlActor.h"
#include "ROSBridgeGameInstance.h"



// Sets default values
AROSWorldControlActor::AROSWorldControlActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AROSWorldControlActor::BeginPlay()
{
	Super::BeginPlay();

// Getting the actual UROSBridgeGameInstance
	UROSBridgeGameInstance* ActiveGameInstance = Cast<UROSBridgeGameInstance>(GetGameInstance());
	check(ActiveGameInstance);

	check(ActiveGameInstance->ROSHandler.IsValid());

  if(!RWCRegistrationClass)
  {
		UE_LOG(LogTemp, Error, TEXT("No RWCRegistrationClass set in AROSWorldControlActor. Please reference the RWCManager class from UROSControl in this actors respective UPROPERTY"));
		return;
  }

  auto BaseClass = RWCRegistrationClass->GetDefaultObject<UROSCallbackRegisterBase>();

  // Make sure Outer is something GetWorld() can be called on.
  BaseClass->Rename(*BaseClass->GetName(), this);
  BaseClass->Register(Namespace);

  // Register SrvServers
  for (auto SrvServer : BaseClass->ServicesToPublish)
  {
    ActiveGameInstance->ROSHandler->AddServiceServer(SrvServer);
  }

  // Register Publisher
  for (auto Publisher : BaseClass->PublisherToPublish)
  {
    ActiveGameInstance->ROSHandler->AddPublisher(Publisher);
  }

  // Register Subscriber
  for (auto Subscriber : BaseClass->SubscriberToPublish)
  {
    ActiveGameInstance->ROSHandler->AddSubscriber(Subscriber);
  }

}

// Called every frame
void AROSWorldControlActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}