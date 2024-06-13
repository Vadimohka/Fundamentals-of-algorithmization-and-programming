// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Engine/DataTable.h"
#include "BaseCard.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FCardInfo : public FTableRowBase
{
	GENERATED_BODY()
	UPROPERTY(EditAnywhere)
	FString CardName;
	UPROPERTY(EditAnywhere)
	UTexture2D* CardImage;
	UPROPERTY(EditAnywhere)
	FString CardType;
	UPROPERTY(EditAnywhere)
	FString CardDescription;
	UPROPERTY(EditAnywhere)
	int CardCost;
};

UCLASS()
class MYSLAYTHESPIRE_API UBaseCard : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize();

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* CardNameText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* CardType;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* CardDescriptionText;

	UPROPERTY(meta = (BindWidget))
	class UTextBlock* CardCostText;

	UPROPERTY(meta = (BindWidget))
	class UImage* CardBackgroundImage;

	UPROPERTY(meta = (BindWidget))
	class UImage* CardImage;

	UPROPERTY(meta = (BindWidget))
	class UButton* ActiveButton;

	UFUNCTION()
	void CardClicked();

	int RandomNumber();
public:
	UPROPERTY(EditAnywhere, Category = "CardDataTable")
	class UDataTable* CardDataTable;

	class UInfoWidget* InfoWidget;
	FCardInfo* Cur_CardInfo;
};
