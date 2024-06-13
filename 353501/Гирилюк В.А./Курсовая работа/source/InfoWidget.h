// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "Delegates/Delegate.h"
#include "BaseCard.h"
#include "InfoWidget.generated.h"

/**
 * 
 */


UCLASS()
class MYSLAYTHESPIRE_API UInfoWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize();



	bool isBattle = false;
	int turn = 0;
	int energy = 3;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* MaxCurrentHP;

	UPROPERTY(meta = (BindWidget))
	class UButton* SettingsMenu;

	UPROPERTY(meta = (BindWidget))
	class UButton* Map;

	
public:

	UFUNCTION()
	void BeginPlay();

	class AHero* Hero;
	class AEnemy* Enemy;
	class AEnemiesBoxSpawner* Spawner;

	UPROPERTY(meta = (BindWidget))
	class UUserWidget* WBP_Map;

	UPROPERTY(meta = (BindWidget))
	class UUserWidget* WBP_SettingsMenu;

	UPROPERTY(meta = (BindWidget))
	class UBattleWidget* WBP_BattleWidget;

	UPROPERTY(meta = (BindWidget))
	class UUserWidget* WBP_VictoryMenu;

	UPROPERTY(meta = (BindWidget))
	class UUserWidget* WBP_DefeatMenu;

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetCurrentCharacterHealth();

	UFUNCTION(BlueprintCallable, BlueprintPure)
	int GetMaxCharacterHealth();

	UFUNCTION()
	void SetMaxCurrentHP();

	UFUNCTION()
	void SettingsButtonClicked();

	UFUNCTION()
	void MapButtonClicked();


	UFUNCTION()
	void OpenCloseMap();

	UFUNCTION()
	void OpenCloseSettingsMenu();

	UFUNCTION()
	void StartBattle();

	UFUNCTION()
	void EndTurn();

	UFUNCTION()
	void CardChoose(UBaseCard* Card);
};
