// Fill out your copyright notice in the Description page of Project Settings.


#include "TimerBoard.h"

// Sets default values
ATimerBoard::ATimerBoard()
{
	// 컴포넌트 생성
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot")); // Scene Component
	SetRootComponent(SceneRoot);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh")); // Static Mesh Component
	StaticMeshComponent->SetupAttachment(SceneRoot);

	bIsVisible = true;
}

// Called when the game starts or when spawned
void ATimerBoard::BeginPlay()
{
	Super::BeginPlay();
	StartTimer();
}

void ATimerBoard::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	StartTimer();
}

void ATimerBoard::InvertBoardActivation()
{
	SetActorHiddenInGame(!bIsVisible);
	SetActorEnableCollision(bIsVisible);
	bIsVisible = !bIsVisible;
}

void ATimerBoard::StartTimer()
{
	if (GetWorldTimerManager().IsTimerActive(BoardTimerHandle))
	{
		GetWorldTimerManager().ClearTimer(BoardTimerHandle);
	}

	GetWorldTimerManager().SetTimer(BoardTimerHandle, this, &ATimerBoard::InvertBoardActivation, Interval, true);
}

#if WITH_EDITOR
void ATimerBoard::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FName PropertyName = (PropertyChangedEvent.Property != nullptr)
		? FName(*PropertyChangedEvent.Property->GetName())
		: NAME_None;

	if (PropertyName == GET_MEMBER_NAME_CHECKED(ATimerBoard, Interval))
	{
		StartTimer();
	}
}
#endif



