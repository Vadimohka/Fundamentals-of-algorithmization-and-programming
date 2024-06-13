// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"
#include "IntentionWidget.h"
#include <Components/WidgetComponent.h>

AEnemy::AEnemy() : Super()
{
	IntentionComponent = CreateDefaultSubobject<UWidgetComponent>(TEXT("IntentionComponent"));
	IntentionComponent->SetupAttachment(RootComponent);
	ConstructorHelpers::FClassFinder<UUserWidget> Class(TEXT("/Game/Blueprints/User_Interface/WBP_Intention"));
	IntentionWidget = (UIntentionWidget*)CreateWidget(GetWorld(), Class.Class);
	IntentionComponent->SetWidget(IntentionWidget);
}

void AEnemy::Action(int Turn)
{
}
