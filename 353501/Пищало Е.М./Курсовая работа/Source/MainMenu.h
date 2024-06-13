// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MainMenu.generated.h"

/**
 * 
 */
UCLASS()
class SLAYTHESPIRE_API UMainMenu : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize();

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* StartGameButton;

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UButton* QuitGameButton;

	UFUNCTION()
	void StartButtonClicked();
	UFUNCTION()
	void QuitButtonClicked();
};
