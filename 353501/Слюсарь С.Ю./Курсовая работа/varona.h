// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "varona.generated.h"

UCLASS()
class STASSSSIIIIKKKK_API Avarona : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Avarona();
	UPROPERTY(EditAnywhere,BlueprintReadWrite) int XInCode;
	UPROPERTY(EditAnywhere,BlueprintReadWrite) int YInCode;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
