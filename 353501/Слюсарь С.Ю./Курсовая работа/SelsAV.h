// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "SelsAV.generated.h"
USTRUCT(BlueprintType)
struct STASSSSIIIIKKKK_API FSelsAV
{
	GENERATED_BODY();

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	bool Alive;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector position;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Density;


	FSelsAV();
	~FSelsAV();
};
