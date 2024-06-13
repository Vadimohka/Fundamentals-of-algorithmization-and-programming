// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "Blueprint/UserWidget.h"
#include "HealthBarWidget.h"
#include <Components/WidgetComponent.h>

ABaseCharacter::ABaseCharacter() : Super()
{
	HealthBarComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("HealthBarComponent"));
	HealthBarComponent->SetupAttachment(RootComponent);
	ConstructorHelpers::FClassFinder<UUserWidget> Class(TEXT("/Game/Blueprints/User_Interface/WBP_HealthBar"));
	TSubclassOf<class UHealthBarWidget> HB;
	HB = Class.Class;
	HealthBarWidget = (UHealthBarWidget*)CreateWidget(GetWorld(), HB);
	HealthBarComponent->SetWidget(HealthBarWidget);
}

void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
	if (HealthBarWidget) {
		HealthBarWidget->UpdateCurrentMaxHP(MaxHealthPoints, CurrentHealthPoints);
	}
}

int ABaseCharacter::GetHP()
{
	return CurrentHealthPoints;
}

void ABaseCharacter::AddHP()
{
	
}

void ABaseCharacter::GetDamage(int32 damage)
{
	damage = damage - DefencePoints;
	DefencePoints = FMath::Max(0, -damage);
	damage = FMath::Max(0, damage);
	HealthBarWidget->SetDefence(DefencePoints);
	CurrentHealthPoints = FMath::Max(0, CurrentHealthPoints - damage);
	MaxCurrentHP();
}

void ABaseCharacter::MaxCurrentHP()
{
	if (HealthBarWidget) {
		HealthBarWidget->UpdateCurrentMaxHP(MaxHealthPoints, CurrentHealthPoints);
	}
}

int ABaseCharacter::GetDP()
{
	return DefencePoints;
}

void ABaseCharacter::AddDP(int addDefence)
{
	DefencePoints += addDefence;
	HealthBarWidget->SetDefence(DefencePoints);
}
