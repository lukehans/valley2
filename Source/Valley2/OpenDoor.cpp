// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Math/Rotator.h"
#include "GameFramework/Actor.h"
#include "Engine/World.h"

// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	ActorThatOpens = GetWorld()->GetFirstPlayerController()->GetPawn();
}

void UOpenDoor::OpenDoor()
{
	AActor* Owner = GetOwner();
	UE_LOG(LogTemp, Warning, TEXT("In Open Door!"));
	if (Owner != nullptr)
	{
		FString ObjectName = Owner->GetName();
		//UE_LOG(LogTemp, Warning, TEXT("OpenDoor initialized. Owner name is %s."), *ObjectName);

		FRotator NewRotation = FRotator(0.f, OpenAngle, 0.f);
		Owner->SetActorRotation(NewRotation);
	}
	else
	{
		//UE_LOG(LogTemp, Warning, TEXT("OpenDoor initialized, but Owner is nullptr."));
	}
}

// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	if (PressurePlate->IsOverlappingActor(ActorThatOpens))
	{
		OpenDoor();
	}
}

