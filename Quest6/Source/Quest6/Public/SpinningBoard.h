// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpinningBoard.generated.h"

UCLASS()
class QUEST6_API ASpinningBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASpinningBoard();

protected:
	// 컴포넌트
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpinningBoard|Components")
	UStaticMeshComponent* StaticMeshComponent;

	// 변수
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="SpinningBoard|Property")
	float RotationSpeed;

	// 라이프 사이클 함수
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// 일반 함수
	void SetBoardPosition(FVector BoardPosition);

};
