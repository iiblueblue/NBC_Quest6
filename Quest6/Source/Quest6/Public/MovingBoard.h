// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingBoard.generated.h"

UCLASS()
class QUEST6_API AMovingBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AMovingBoard();

protected:
	// ������Ʈ
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpinningBoard|Components")
	UStaticMeshComponent* StaticMeshComponent;

	// ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpinningBoard|Property")
	float MovingSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpinningBoard|Property")
	float MovingDistance;
	FVector StartLocation;

	// ������ ����Ŭ �Լ�
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// �Ϲ� �Լ�
	void SetBoardPosition(FVector BoardPosition);
	bool IsTurningPointReached() const;
	float GetMovedDistance() const;
	void MoveBoard(float DeltaTime);
};
