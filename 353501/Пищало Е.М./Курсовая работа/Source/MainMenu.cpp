// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

bool UMainMenu::Initialize()
{
	Super::Initialize();

	StartGameButton->OnClicked.AddDynamic(this, &UMainMenu::StartButtonClicked);
	QuitGameButton->OnClicked.AddDynamic(this, &UMainMenu::QuitButtonClicked);
	
	return true;
}

void UMainMenu::StartButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "level1", true, "");
}

void UMainMenu::QuitButtonClicked()
{
	GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
}
