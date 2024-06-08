// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "VictoryMenu.generated.h"

/**
 * 
 */
UCLASS()
class MYSLAYTHESPIRE_API UVictoryMenu : public UUserWidget
{
	GENERATED_BODY()
	

	virtual bool Initialize();

	UPROPERTY(meta = (BindWidget))
	class UButton* ExitMenu;

	UFUNCTION()
	void ExitMenuButtonClicked();
};
