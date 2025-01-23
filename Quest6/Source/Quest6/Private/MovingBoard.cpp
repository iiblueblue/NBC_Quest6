// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingBoard.h"

// Sets default values
AMovingBoard::AMovingBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// 컴포넌트 생성
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot")); // Scene Component
	SetRootComponent(SceneRoot);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh")); // Static Mesh Component
	StaticMeshComponent->SetupAttachment(SceneRoot);

	// 변수 초기화
	MovingSpeed = 50.0f;
	MovingDistance = 10.0f;
}

// Called when the game starts or when spawned
void AMovingBoard::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMovingBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

