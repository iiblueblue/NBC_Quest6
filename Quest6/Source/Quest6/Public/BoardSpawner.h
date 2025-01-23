// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BoardSpawner.generated.h"

UCLASS()
class QUEST6_API ABoardSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABoardSpawner();

protected:
	// 컴포넌트
	USceneComponent* SceneComponent;
	
	// 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardSpawner|Property")
	int32 NumberOfBoards = 10;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardSpawner|Property")
	float SpawnCubeSize = 1000.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardSpawner|Property")
	float MinDistanceBetweenBoard = 30.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardSpawner|Property")
	float MaxDistanceBetweenBoard = 40.0f;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardSpawner|Property")
	float AdditionalHeight = 60.0f;

	FVector CenterLocation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardSpawner|Board")
	TSubclassOf<AActor> SpinningBoardClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardSpawner|Board")
	TSubclassOf<AActor> MovingBoardClass;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BoardSpawner|Board")
	TSubclassOf<AActor> TimerBoardClass;

	// 라이프 사이클 함수
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

	// 일반 함수
	void SpawnBoard();
	bool IsLocationWithinBounds(const FVector& Location);

};
