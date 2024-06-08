// Fill out your copyright notice in the Description page of Project Settings.


#include "SkeletonAxe.h"
#include "IntentionWidget.h"
#include "Hero.h"
#include "Kismet/GameplayStatics.h"

ASkeletonAxe::ASkeletonAxe() : Super()
{
	MaxHealthPoints = 45;
	CurrentHealthPoints = 45;
	Name = FString("Skeleton");
}

void ASkeletonAxe::BeginPlay()
{
	Super::BeginPlay();
	if (IntentionWidget) {
		IntentionWidget->UpdateIntention(10);
	}
}

void ASkeletonAxe::Action(int Turn)
{
	AHero* Hero = Cast<AHero>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (Turn % 3 == 0) {
		Hero->GetDamage(10);
		IntentionWidget->UpdateIntention(6);
	}
	else if (Turn % 3 == 1) {
		Hero->GetDamage(6);
		IntentionWidget->UpdateIntention(17);
	}
	else if (Turn % 3 == 2) {
		Hero->GetDamage(17);
		IntentionWidget->UpdateIntention(10);
	}
}
