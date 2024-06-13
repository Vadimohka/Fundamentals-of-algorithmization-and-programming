// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InfoWidget.h"
#include "Blueprint/UserWidget.h"
#include "BattleWidget.generated.h"

/**
 * 
 */
UCLASS()
class MYSLAYTHESPIRE_API UBattleWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize();

	UPROPERTY(meta = (BindWidget))
	class UButton* EndTurnButton;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* EnergyText;

	UPROPERTY(meta = (BindWidget))
	class UCardHand* WBP_CardHand;


public:
	UInfoWidget* InfoWidget;
	TSubclassOf<class UUserWidget> BaseCardClass;

	UFUNCTION()
	void EndTurnButtonClicked();

	void StartBattle();

	void UpdateEnergy(int CurEnergy, int MaxEnergy);
};
