// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingBoard.h"

// Sets default values
AMovingBoard::AMovingBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ������Ʈ ����
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot")); // Scene Component
	SetRootComponent(SceneRoot);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh")); // Static Mesh Component
	StaticMeshComponent->SetupAttachment(SceneRoot);

	// ���� �ʱ�ȭ
	MovingSpeed = 50.0f;
	MovingDistance = 10.0f;
}

// Called when the game starts or when spawned
void AMovingBoard::BeginPlay()
{
	Super::BeginPlay();
	
	StartLocation = GetActorLocation(); // ���� ��ġ�� ���� ��ġ�� ����
}

// Called every frame
void AMovingBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// ���� ��ġ ����
// : ������ ��ġ�� BoardPosition���� �����Ѵ�(���� ���� �������� ��� ����)
void AMovingBoard::SetBoardPosition(FVector BoardPosition)
{
}

bool AMovingBoard::IsTurningPointReached() const
{
	return GetMovedDistance() > MovingDistance;
}

float AMovingBoard::GetMovedDistance() const
{
	return FVector::Dist(StartLocation, GetActorLocation());
}

void AMovingBoard::MoveBoard(float DeltaTime)
{
	if (IsTurningPointReached())
	{
		MovingSpeed *= -1;
		StartLocation = GetActorLocation();
	}
	AddActorLocalOffset(FVector(0.0f, MovingSpeed * DeltaTime, 0.0f));
}

