// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD.h"
#include "Blueprint/UserWidget.h"

AMyHUD::AMyHUD() : Super()
{
	ConstructorHelpers::FClassFinder<UUserWidget> WBP(TEXT("/Game/UI/Heal_2"));

	MainHUB = WBP.Class;
}

void AMyHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* CharacterWidget = CreateWidget(GetWorld(), MainHUB);
	CharacterWidget->AddToViewport();
}
