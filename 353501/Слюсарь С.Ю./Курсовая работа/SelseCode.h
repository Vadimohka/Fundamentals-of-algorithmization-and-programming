// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SelsAV.h"
#include "GameFramework/Actor.h"
#include "SelseCode.generated.h"

UCLASS()
class STASSSSIIIIKKKK_API ASelseCode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASelseCode();
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	TArray<FSelsAV> points;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> Vectors;
	
	UFUNCTION(BlueprintCallable, Category = "AV")
	TArray<FSelsAV> CreateSeilsAV(TArray<FVector> Flor, TArray<FSelsAV> sels, int XSize, int YSize, int StartSeilsCount);

	
	UFUNCTION(BlueprintCallable)
	float RooleOfAutomate(TArray<FSelsAV> Flore, int Index, int XSize, int YSize);
	UFUNCTION(BlueprintCallable)
	TArray<FSelsAV> ApplyRules(TArray<FSelsAV> Flore, int XSize, int YSize);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
