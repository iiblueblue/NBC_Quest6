// Fill out your copyright notice in the Description page of Project Settings.


#include "BoardSpawner.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
ABoardSpawner::ABoardSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneComponent);
}

// Called when the game starts or when spawned
void ABoardSpawner::BeginPlay()
{
	Super::BeginPlay();
	CenterLocation = GetActorLocation();

	SpawnBoard();
	
}

// Called every frame
void ABoardSpawner::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ABoardSpawner::SpawnBoard()
{
	TArray<FVector> SpawnedLocations;
	FVector CurrentLocation = GetActorLocation(); // BoardSpawner의 시작 위치

	// NumberOfBoards 만큼 스폰
	for (int i = 0; i < NumberOfBoards; i++)
	{
		FVector SpawnLocation;
		bool bIsLocationValid = false;
		// x, y, z 좌표 랜덤 생성 (알맞은 위치가 나올 때까지)
		// 새로운 발판 위치 계산
		while (!bIsLocationValid)
		{
			// 이전 위치에서 MinDistance ~ MaxDistance 사이로 이동
			float Distance = FMath::RandRange(MinDistanceBetweenBoard, MaxDistanceBetweenBoard);

			// 랜덤 방향으로 위치 계산
			FRotator RandomDirection = FRotator(0, FMath::RandRange(0.0f, 360.0f), 0);
			FVector Direction = RandomDirection.Vector();
			SpawnLocation = CurrentLocation + Direction * Distance;

			// 전체 범위 안에 있는지 확인
			bIsLocationValid = IsLocationWithinBounds(SpawnLocation);
		}
		SpawnLocation += FVector(0.0f, 0.0f, AdditionalHeight);
		SpawnedLocations.Add(SpawnLocation);
		CurrentLocation = SpawnLocation; // 현재 위치 갱신

		// 랜덤한 발판 클래스 선택
		TSubclassOf<AActor> SelectedBoardClass;
		int32 RandomIndex = FMath::RandRange(0, 2);

		switch (RandomIndex)
		{
		case 0:
			SelectedBoardClass = SpinningBoardClass;
			break;
		case 1:
			SelectedBoardClass = MovingBoardClass;
			break;
		case 2:
			SelectedBoardClass = TimerBoardClass;
			break;
		}

		if (SelectedBoardClass)
		{
			GetWorld()->SpawnActor<AActor>(SelectedBoardClass, SpawnLocation, FRotator::ZeroRotator);
		}
	}
}

bool ABoardSpawner::IsLocationWithinBounds(const FVector& Location)
{
	// Location이 스폰 범위 내에 있는지 확인
	return FMath::Abs(Location.X - CenterLocation.X) <= SpawnCubeSize / 2.0f &&
		FMath::Abs(Location.Y - CenterLocation.Y) <= SpawnCubeSize / 2.0f &&
		Location.Z - CenterLocation.Z >= 0.0f &&
		Location.Z - CenterLocation.Z <= SpawnCubeSize;
}

