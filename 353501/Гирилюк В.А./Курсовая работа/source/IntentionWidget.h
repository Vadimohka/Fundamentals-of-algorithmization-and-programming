// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "IntentionWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYSLAYTHESPIRE_API UIntentionWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize();

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* IntentionTextBlock;

public:
	void UpdateIntention(int damage);
};
