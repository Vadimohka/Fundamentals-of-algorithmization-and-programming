// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "PaperZDCharacter.h"
#include "BaseCharacter.generated.h"

/**
 * 
 */
UCLASS()
class MYSLAYTHESPIRE_API ABaseCharacter : public APaperZDCharacter
{
	GENERATED_BODY()

public:
	
	ABaseCharacter();

	virtual void BeginPlay() override;

	FString Name;

	UPROPERTY(VisibleAnywhere)
	class UWidgetComponent* HealthBarComponent;
	class UHealthBarWidget* HealthBarWidget;

	UPROPERTY(EditAnywhere, Category = "CharacterHealthPoints", meta = (ClampMin = "1"))
	int32 MaxHealthPoints = 100; 
	UPROPERTY(EditAnywhere, Category = "CharacterHealthPoints")
	int32 CurrentHealthPoints = 100;

	UFUNCTION()
	int GetHP();

	UFUNCTION()
	void AddHP();

	UFUNCTION()
	void GetDamage(int32 damage);

	UFUNCTION()
	void MaxCurrentHP();

	UPROPERTY(EditDefaultsOnly, Category = "CharacterDefencePoints")
	int DefencePoints = 0;

	UFUNCTION()
	int GetDP();

	UFUNCTION()
	void AddDP(int addDefence);
};