// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "MyUnit.h"
#include "Styling/SlateBrush.h"
#include "SlateBasics.h"
#include "SlateExtras.h"
#include "MyUserWidget_2.generated.h"

/**
 * 
 */
UCLASS()
class KURSATH_API UMyUserWidget_2 : public UUserWidget
{
	GENERATED_BODY()
	virtual bool Initialize();

	UPROPERTY(meta = (BindWidget))
	class UButton* Start;
	UFUNCTION()
	void Start_fun();
	UPROPERTY(meta = (BindWidget))
	class UButton* Button1;
	UPROPERTY(meta = (BindWidget))
	class UButton* Button_0;
	UFUNCTION()
	void Button_0_fun();
	UFUNCTION()
	void Button1_fun();
	UPROPERTY(meta = (BindWidget))
	class UButton* Button2;
	UFUNCTION()
	void Button2_fun();
	UPROPERTY(meta = (BindWidget))
	class UButton* Button3;
	UFUNCTION()
	void Button3_fun();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString Money();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString Level();
	UFUNCTION(BlueprintCallable, BlueprintPure)
	FString NumGames();
public:
	UFUNCTION()
	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime);
};
