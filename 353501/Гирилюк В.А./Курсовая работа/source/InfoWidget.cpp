// Fill out your copyright notice in the Description page of Project Settings.


#include "InfoWidget.h"
#include "Hero.h"
#include "BattleWidget.h"
#include "EnemiesBoxSpawner.h"
#include "BattleWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/TextBlock.h"

bool UInfoWidget::Initialize()
{
	bool bSuccess = Super::Initialize();
	if (!bSuccess) return false;

	APlayerController* PlayerController = GetOwningPlayer();
	if (PlayerController)
	{
		SetMaxCurrentHP();
		PlayerController->InputComponent->BindAction("OpenCloseSettingsMenu", IE_Pressed, this, &UInfoWidget::OpenCloseSettingsMenu);
		PlayerController->InputComponent->BindAction("OpenCloseMap", IE_Pressed, this, &UInfoWidget::OpenCloseMap);
	}
	


	SettingsMenu->OnClicked.AddDynamic(this, &UInfoWidget::SettingsButtonClicked);
	Map->OnClicked.AddDynamic(this, &UInfoWidget::MapButtonClicked);
 
	return true;
}

void UInfoWidget::BeginPlay()
{
	WBP_BattleWidget->InfoWidget = this;
	TArray<AActor*> Actors = TArray<AActor*>();
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AActor::StaticClass(), Actors);
	Spawner = (AEnemiesBoxSpawner*)Actors[3];
}


void UInfoWidget::OpenCloseMap()
{
	if (!WBP_SettingsMenu->IsVisible() && !WBP_DefeatMenu->IsVisible() && !WBP_VictoryMenu->IsVisible()) {
		if (WBP_Map->IsVisible()) {
			WBP_Map->SetVisibility(ESlateVisibility::Hidden);
		}
		else {
			WBP_Map->SetVisibility(ESlateVisibility::Visible);
		}
	}

}

void UInfoWidget::OpenCloseSettingsMenu()
{
	if(!WBP_DefeatMenu->IsVisible() && !WBP_VictoryMenu->IsVisible()){
		if (WBP_SettingsMenu->IsVisible()) {
			WBP_SettingsMenu->SetVisibility(ESlateVisibility::Hidden);
		}
		else {
			WBP_SettingsMenu->SetVisibility(ESlateVisibility::Visible);
		}
	}
}

int UInfoWidget::GetCurrentCharacterHealth()
{
	Hero = Cast<AHero>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	return Hero->CurrentHealthPoints;
}

int UInfoWidget::GetMaxCharacterHealth()
{
	Hero = Cast<AHero>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	return Hero->MaxHealthPoints;
}

void UInfoWidget::SetMaxCurrentHP()
{
	MaxCurrentHP->SetText(FText::FromString(FString::Printf(TEXT("%d/%d"), GetCurrentCharacterHealth(), GetMaxCharacterHealth())));
}

void UInfoWidget::SettingsButtonClicked()
{
	OpenCloseSettingsMenu();
}

void UInfoWidget::MapButtonClicked()
{
	OpenCloseMap();
}

void UInfoWidget::StartBattle() {
	if (!isBattle) {
		Enemy = Spawner->SpawnActor();
		WBP_BattleWidget->StartBattle();
		WBP_BattleWidget->SetVisibility(ESlateVisibility::Visible);
		isBattle = true;
	}
}

void UInfoWidget::EndTurn()
{
	Enemy->Action(turn);
	Hero->GetDamage(Hero->GetDP());
	SetMaxCurrentHP();
	energy = 3;
	turn++;
	if (Hero->GetHP() == 0) {
		WBP_BattleWidget->SetVisibility(ESlateVisibility::Hidden);
		WBP_DefeatMenu->SetVisibility(ESlateVisibility::Visible);
	}
}

void UInfoWidget::CardChoose(UBaseCard* Card)
{
	if(energy >= Card->Cur_CardInfo->CardCost){
		if (Card->Cur_CardInfo->CardName == FString("Strike")) {
			Enemy->GetDamage(6);
			if (Enemy->GetHP() == 0) {
				Enemy->Destroy();
				WBP_VictoryMenu->SetVisibility(ESlateVisibility::Visible);
			}
		}
		else if (Card->Cur_CardInfo->CardName == FString("Defend")) {
			Hero->AddDP(5);
		}
		energy -= Card->Cur_CardInfo->CardCost;
		Card->RemoveFromParent();
		Card->ConditionalBeginDestroy();
		Card = nullptr;
		WBP_BattleWidget->UpdateEnergy(energy, 3);
	}
}