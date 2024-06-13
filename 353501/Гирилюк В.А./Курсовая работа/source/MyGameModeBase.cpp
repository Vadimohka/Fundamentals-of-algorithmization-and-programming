// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase.h"

AMyGameModeBase::AMyGameModeBase() : Super()
{
	ConstructorHelpers::FClassFinder<APawn> Hero(TEXT("/Game/Blueprints/Knight/BP_Knight"));

	DefaultPawnClass = Hero.Class;
	HUDClass = AUserHUD::StaticClass();
}
