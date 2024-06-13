// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "VaroniaStruct.h"
#include "FloraStruct.h"
#include "GameFramework/Actor.h"
#include "varonacode.generated.h"

UCLASS()
class STASSSSIIIIKKKK_API Avaronacode : public AActor
{
	GENERATED_BODY()
public:	
	// Sets default values for this actor's properties
	Avaronacode();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MyClass")
	TArray<FVector>Points;
;
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SITEPoints")
TArray<FVector>Site;
UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SITEPoints")
TArray<FVaroniaStruct>CellsFV;
UFUNCTION(BlueprintCallable, Category = "SITEPoints")
TArray<FVector> GetSitePoints(TArray<FVector> PointsArray,int Min,int Max,int Size);

UFUNCTION(BlueprintCallable, Category = "SITEGenerator")
TArray<FVaroniaStruct> GenerateSiteNode(TArray<FVector> Sites, TArray<FVaroniaStruct> OutCells);

UFUNCTION(BlueprintCallable, Category = "SITEGenerator")
TArray<FVaroniaStruct> GenerateVoronoiDiagram(TArray<FVaroniaStruct> PointsTF, TArray<FVector> Region, int Widh, int height);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
