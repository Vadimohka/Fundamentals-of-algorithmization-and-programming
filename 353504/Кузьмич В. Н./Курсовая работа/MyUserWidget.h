// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUnit.h"
#include "Styling/SlateBrush.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "MyUserWidget.generated.h"
/**
 * 
 */
UCLASS()
class KURSATH_API UMyUserWidget : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize();

	UPROPERTY(meta = (BindWidget))
	class UButton* Card1;
	UPROPERTY(meta = (BindWidget))
	class UButton* Button_0;
	UPROPERTY(meta = (BindWidget))
	class UButton* Button;
	UPROPERTY(meta = (BindWidget))
	class UButton* Button_2;
	UPROPERTY(meta = (BindWidget))
	class UButton* Button_1;
	UFUNCTION()
	void But0();
	UFUNCTION()
	void But();
	UFUNCTION()
	void But2();
	UFUNCTION()
	void But1();
	UPROPERTY(meta = (BindWidget))
	class UImage* Image_7;
	UPROPERTY(meta = (BindWidget))
	class UImage* Image_18;
	UPROPERTY(meta = (BindWidget))
	class UImage* Image_19;
	UPROPERTY(meta = (BindWidget))
	class UImage* Image_17;
	UPROPERTY(meta = (BindWidget))
	class UImage* Image_12;
	UPROPERTY(meta = (BindWidget))
	class UImage* Image_13;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TextBlock_245;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TextBlock_2;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TextBlock_6;
	UPROPERTY(meta = (BindWidget))
	class UTextBlock* TextBlock_1;
	UFUNCTION()
	void ClicedCard1();
	UPROPERTY(meta = (BindWidget))
	class UButton* Card2;
	UFUNCTION()
	void ClicedCard2();
	UPROPERTY(meta = (BindWidget))
	class UButton* Card3;
	UFUNCTION()
	void ClicedCard3();
	UPROPERTY(meta = (BindWidget))
	class UButton* Stop;
	UFUNCTION()
	void ClicedStop();

public:
	int a = 10;
	bool b = true;
	FString str = "", strMoney = "", strLevel = "";
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString Not();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString Money();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString Magna();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString STRM();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString STRL();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString StrMagnC1();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString WinOrLose();
	UFUNCTION()
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString StrMagnC2();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString StrMagnC3();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float HealHero();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	float HealEnemy();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString EnemySheald();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString HealSheald();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString HealHeroText();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString HealEnemyText();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString BoostAttackEnemy();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString BoostAttackHero();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FSlateBrush Card1_Imadge();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FSlateBrush Card2_Imadge();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FSlateBrush Card3_Imadge();
};
