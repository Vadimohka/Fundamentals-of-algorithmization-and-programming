// Fill out your copyright notice in the Description page of Project Settings.


#include "UserHUD.h"
#include "Blueprint/UserWidget.h"
#include "BattleWidget.h"

AUserHUD::AUserHUD() : Super()
{
	ConstructorHelpers::FClassFinder<UUserWidget> WBPInfoWidget(TEXT("/Game/Blueprints/User_Interface/WBP_InfoWidget"));

	MainHUD = WBPInfoWidget.Class;

	ConstructorHelpers::FClassFinder<UUserWidget> WBPCardWidget(TEXT("/Game/Blueprints/User_Interface/WBP_Cards/WBP_BaseCard"));
	BaseCardClass = WBPCardWidget.Class;
}

void AUserHUD::BeginPlay()
{
	Super::BeginPlay();

	UInfoWidget* InfoWidget = (UInfoWidget*)CreateWidget(GetWorld(), MainHUD);
	InfoWidget->BeginPlay();
	InfoWidget->AddToViewport();
	((UBattleWidget*)InfoWidget->WBP_BattleWidget)->BaseCardClass = BaseCardClass;
	((UMyMap*)InfoWidget->WBP_Map)->InfoWidget = InfoWidget;
}
