// Fill out your copyright notice in the Description page of Project Settings.


#include "SettingsMenu.h"

bool USettingsMenu::Initialize()
{
	Super::Initialize();

	Return->OnClicked.AddDynamic(this, &USettingsMenu::ReturnButtonClicked);
	ExitMenu->OnClicked.AddDynamic(this, &USettingsMenu::ExitMenuButtonClicked);

	return true;
}

void USettingsMenu::ReturnButtonClicked()
{
	SetVisibility(ESlateVisibility::Hidden);
}

void USettingsMenu::ExitMenuButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "Main_Menu", true);
}
