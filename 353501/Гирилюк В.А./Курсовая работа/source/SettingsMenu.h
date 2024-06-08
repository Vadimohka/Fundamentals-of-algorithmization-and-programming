// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"
#include "SettingsMenu.generated.h"

/**
 * 
 */
UCLASS()
class MYSLAYTHESPIRE_API USettingsMenu : public UUserWidget
{
	GENERATED_BODY()


	virtual bool Initialize();

	UPROPERTY(meta = (BindWidget))
	class UButton* Return;

	UPROPERTY(meta = (BindWidget))
	class UButton* ExitMenu;

	UFUNCTION()
	void ReturnButtonClicked();

	UFUNCTION()
	void ExitMenuButtonClicked();
	
};
