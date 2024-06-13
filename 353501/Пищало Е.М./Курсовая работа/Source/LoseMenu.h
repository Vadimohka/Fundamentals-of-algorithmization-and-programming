// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "LoseMenu.generated.h"

/**
 * 
 */
UCLASS()
class SLAYTHESPIRE_API ULoseMenu : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize();

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* ReturnToMainMenuLose;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* QuitLoseButton;

	UFUNCTION()
	void ReturnToMainMenuLoseClicked();

	UFUNCTION()
	void QuitLoseButtonClicked();
};