// Fill out your copyright notice in the Description page of Project Settings.


#include "SpinningBoard.h"

// Sets default values
ASpinningBoard::ASpinningBoard()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// ������Ʈ ����
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot")); // Scene Component
	SetRootComponent(SceneRoot);

	StaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh")); // Static Mesh Component
	StaticMeshComponent->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Deko_MatrixDemo/Apartment/Meshes/SM_DeskChair_A01_N1.SM_DeskChair_A01_N1"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComponent->SetStaticMesh(MeshAsset.Object);
	}

	// ���� �ʱ�ȭ
	RotationSpeed = 90.0f;
}

// Called when the game starts or when spawned
void ASpinningBoard::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ASpinningBoard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FMath::IsNearlyZero(RotationSpeed))
	{
		AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));
	}

}

// ���� ��ġ ����
// : ������ ��ġ�� BoardPosition���� �����Ѵ�(���� ���� �������� ��� ����)
void ASpinningBoard::SetBoardPosition(FVector BoardPosition)
{
	SetActorLocation(BoardPosition);
}

