// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Button.h"
#include "InfoWidget.h"
#include "MyMap.generated.h"

/**
 * 
 */
UCLASS()
class MYSLAYTHESPIRE_API UMyMap : public UUserWidget
{
	GENERATED_BODY()

	virtual bool Initialize();

public:

	UPROPERTY(meta = (BindWidget))
	class UButton* Floor1;

	class UInfoWidget* InfoWidget;

	UFUNCTION()
	void FloorButtonClicked();


};
