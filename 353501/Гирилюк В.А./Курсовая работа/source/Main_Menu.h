// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UserHUD.h"
#include "Main_Menu.generated.h"

/**
 * 
 */
UCLASS()
class MYSLAYTHESPIRE_API UMain_Menu : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize();

	UPROPERTY(EditAnywhere, meta = (BindWidget))
	class UImage* MenuImage;



	UPROPERTY(meta = (BindWidget))
	class UButton* StartGame;
	UPROPERTY(meta = (BindWidget))
	class UButton* Exit;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* StartGameText;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* ExitText;



	UPROPERTY(meta = (BindWidget))
	class UTextBlock* Name;


	UFUNCTION()
	void StartButtonClicked();

	UFUNCTION()
	void ExitButtonClicked();
};
