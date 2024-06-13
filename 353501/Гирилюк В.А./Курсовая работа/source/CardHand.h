// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "CardHand.generated.h"

/**
 * 
 */
UCLASS()
class MYSLAYTHESPIRE_API UCardHand : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize();
public:
	UPROPERTY(meta = (BindWidget))
	class UHorizontalBox* CardBox;

};
