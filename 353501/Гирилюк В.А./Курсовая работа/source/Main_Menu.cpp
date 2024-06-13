// Fill out your copyright notice in the Description page of Project Settings.


#include "Main_Menu.h"
#include "Components/Button.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"
#include "Widgets/SWidget.h"
#include "Styling/SlateBrush.h"
#include <Kismet/GameplayStatics.h>
#include "Components/CanvasPanel.h"

bool UMain_Menu::Initialize()
{
	Super::Initialize();

	MenuImage->SetBrushFromSoftTexture(LoadObject<UTexture2D>(this, TEXT("../../Content/Assets/Backgrounds/STS_Sprite.uasset")));
	MenuImage->SynchronizeProperties();

	Name->SetText(FText::FromString(TEXT("Slay The Shpire")));
	StartGameText->SetText(FText::FromString(TEXT("New Game")));
	ExitText->SetText(FText::FromString(TEXT("Exit Game")));
	StartGame->AddChild(StartGameText);
	Exit->AddChild(ExitText);
	StartGame->OnClicked.AddDynamic(this, &UMain_Menu::StartButtonClicked);
	Exit->OnClicked.AddDynamic(this, &UMain_Menu::ExitButtonClicked);

	return true;
}

void UMain_Menu::StartButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "Battle_Scene", true);
	APlayerController* PlayerController = GetOwningPlayer();
	((AUserHUD*)PlayerController->GetHUD())->BeginPlay();
	

}

void UMain_Menu::ExitButtonClicked()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}