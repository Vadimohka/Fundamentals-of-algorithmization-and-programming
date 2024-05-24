// Fill out your copyright notice in the Description page of Project Settings.


#include "MyHUD_2.h"
#include "Blueprint/UserWidget.h"

AMyHUD_2::AMyHUD_2() : Super()
{
	ConstructorHelpers::FClassFinder<UUserWidget> WBP(TEXT("/Game/UI/NewWidgetBlueprint1"));

	MainHUB = WBP.Class;
}

void AMyHUD_2::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* CharacterWidget = CreateWidget(GetWorld(), MainHUB);
	CharacterWidget->AddToViewport();
}