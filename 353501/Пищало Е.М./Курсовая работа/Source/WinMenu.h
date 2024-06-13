// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "WinMenu.generated.h"

/**
 * 
 */
UCLASS()
class SLAYTHESPIRE_API UWinMenu : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize();

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* ReturnToMainMenuButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* QuitWinButton;

	UFUNCTION()
	void ReturnButtonClicked();

	UFUNCTION()
	void QuitWinButtonClicked();
};