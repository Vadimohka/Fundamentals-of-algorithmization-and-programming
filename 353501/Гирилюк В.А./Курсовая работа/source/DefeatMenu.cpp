// Fill out your copyright notice in the Description page of Project Settings.


#include "DefeatMenu.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

bool UDefeatMenu::Initialize()
{
	Super::Initialize();

	ExitMenu->OnClicked.AddDynamic(this, &UDefeatMenu::ExitMenuButtonClicked);

	return false;
}

void UDefeatMenu::ExitMenuButtonClicked()
{
	UGameplayStatics::OpenLevel(GetWorld(), "Main_Menu", true);
}
