// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TimerBoard.generated.h"

UCLASS()
class QUEST6_API ATimerBoard : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATimerBoard();

protected:
#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;
#endif
	// ������Ʈ
	USceneComponent* SceneRoot;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpinningBoard|Components")
	UStaticMeshComponent* StaticMeshComponent;

	// ����
	bool bIsVisible;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpinningBoard|Property")
	float Interval = 3.0f;
	FTimerHandle BoardTimerHandle;

	// ������ ����Ŭ �Լ�
	virtual void BeginPlay() override;
	virtual void OnConstruction(const FTransform& Transform) override;

	// �Ϲ� �Լ�
	void InvertBoardActivation();
	void StartTimer();
};
