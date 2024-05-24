// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "MyGameModeBase.h"
#include "CoreUObject.h"
#include "Misc/FileHelper.h"
#include <Windows.h>
#include "Components/Button.h"
#include "Components/Image.h"
#include "Components/TextBlock.h"


bool UMyUserWidget::Initialize()
{
	Super::Initialize();
	if (Card1 != nullptr)
	{
		Card1->OnClicked.AddDynamic(this, &UMyUserWidget::ClicedCard1);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Card1 is not initialized!"));
	}
	if (Card2 != nullptr)
	{
		Card2->OnClicked.AddDynamic(this, &UMyUserWidget::ClicedCard2);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Card2 is not initialized!"));
	}
	if (Card3 != nullptr)
	{
		Card3->OnClicked.AddDynamic(this, &UMyUserWidget::ClicedCard3);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Card3 is not initialized!"));
	}
	if (Stop != nullptr)
	{
		Stop->OnClicked.AddDynamic(this, &UMyUserWidget::ClicedStop);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Stop is not initialized!"));
	}
	if (Button_0 != nullptr)
	{
		Button_0->OnClicked.AddDynamic(this, &UMyUserWidget::But0);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Button_0 is not initialized!"));
	}
	if (Button_1 != nullptr)
	{
		Button_1->OnClicked.AddDynamic(this, &UMyUserWidget::But1);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Button_1 is not initialized!"));
	}
	if (Button != nullptr)
	{
		Button->OnClicked.AddDynamic(this, &UMyUserWidget::But);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Button is not initialized!"));
	}
	if (Button_2 != nullptr)
	{
		Button_2->OnClicked.AddDynamic(this, &UMyUserWidget::But2);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Button_2 is not initialized!"));
	}
	return true;
}

void UMyUserWidget::But0()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (Obgect->money >= 60) {
		Obgect->El_red();
		Obgect->money -= 60;
		
		FString FilePath = TEXT("game.txt");
		int32 LineIndex = 2;
		FString FullPath = FPaths::Combine(FPaths::ProjectDir(), FilePath);
		TArray<FString> Lines;
		FFileHelper::LoadFileToStringArray(Lines, *FullPath);
		if (LineIndex >= 0 && LineIndex < Lines.Num())
		{
			FString UpdatedLine = FString::Printf(TEXT("%d"), Obgect->money);
			Lines[LineIndex] = UpdatedLine;
			FFileHelper::SaveStringArrayToFile(Lines, *FullPath);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Error"));
		}
	}
	Obgect->GameOverTheEnemyLost();
}

void UMyUserWidget::But()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("M1"));
}

void UMyUserWidget::But2()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("M2"));
}

void UMyUserWidget::But1()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (Obgect->money >= 60) {
		Obgect->El_green();
		Obgect->money -= 60;

		FString FilePath = TEXT("game.txt");
		int32 LineIndex = 2;
		FString FullPath = FPaths::Combine(FPaths::ProjectDir(), FilePath);
		TArray<FString> Lines;
		FFileHelper::LoadFileToStringArray(Lines, *FullPath);
		if (LineIndex >= 0 && LineIndex < Lines.Num())
		{
			FString UpdatedLine = FString::Printf(TEXT("%d"), Obgect->money);
			Lines[LineIndex] = UpdatedLine;
			FFileHelper::SaveStringArrayToFile(Lines, *FullPath);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Error"));
		}
	}
	Obgect->GameOverTheEnemyLost();
}

FString UMyUserWidget::Not()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	return Obgect->str;
}

FString UMyUserWidget::Money()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	return FString::FromInt(Obgect->money);
}

void UMyUserWidget::ClicedCard1()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (Obgect->ind_card1 == 0) {
		if (Obgect->magna >= 1) {
			Obgect->Attack();
			Obgect->magna -= 1;
			Card1->SetIsEnabled(false);
			Card1->SetVisibility(ESlateVisibility::Hidden);
			Image_7->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_245->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card1 == 1) {
		if (Obgect->magna >= 1) {
			Obgect->Heal();
			Obgect->magna -= 1;
			Card1->SetIsEnabled(false);
			Card1->SetVisibility(ESlateVisibility::Hidden);
			Image_7->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_245->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card1 == 2) {
		if (Obgect->magna >= 1) {
			Obgect->Shead(); 
			Obgect->magna -= 1;
			Card1->SetIsEnabled(false);
			Card1->SetVisibility(ESlateVisibility::Hidden);
			Image_7->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_245->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card1 == 3) {
		if (Obgect->magna >= 2) {
			Obgect->StrengthPotion();
			Obgect->magna -= 2;
			Card1->SetIsEnabled(false);
			Card1->SetVisibility(ESlateVisibility::Hidden);
			Image_7->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_245->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card1 == 4) {
		if (Obgect->magna >= 2) {
			Obgect->PotionWeakness();
			Obgect->magna -= 2;
			Card1->SetIsEnabled(false);
			Card1->SetVisibility(ESlateVisibility::Hidden);
			Image_7->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_245->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card1 == 5) {
		if (Obgect->magna >= 2) {
			Obgect->Attack_x2();
			Obgect->magna -= 2;
			Card1->SetIsEnabled(false);
			Card1->SetVisibility(ESlateVisibility::Hidden);
			Image_7->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_245->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card1 == 6) {
		if (Obgect->magna >= 2) {
			Obgect->Heal_and_Shead();
			Obgect->magna -= 2;
			Card1->SetIsEnabled(false);
			Card1->SetVisibility(ESlateVisibility::Hidden);
			Image_7->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_245->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card1 == 7) {
		if (Obgect->magna >= 3) {
			Obgect->PotionWeakness_and_StrengthPotion();
			Obgect->magna -= 3;
			Card1->SetIsEnabled(false);
			Card1->SetVisibility(ESlateVisibility::Hidden);
			Image_7->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_245->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	Obgect->GameOverTheEnemyLost();
}

void UMyUserWidget::ClicedCard2()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (Obgect->ind_card2 == 0) {
		if (Obgect->magna >= 1) {
			Obgect->Attack();
			Obgect->magna -= 1;
			Card2->SetIsEnabled(false);
			Card2->SetVisibility(ESlateVisibility::Hidden);
			Image_12->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_2->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card2 == 1) {
		if (Obgect->magna >= 1) {
			Obgect->Heal();
			Obgect->magna -= 1;
			Card2->SetIsEnabled(false);
			Card2->SetVisibility(ESlateVisibility::Hidden);
			Image_12->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_2->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card2 == 2) {
		if (Obgect->magna >= 1) {
			Obgect->Shead();
			Obgect->magna -= 1;
			Card2->SetIsEnabled(false);
			Card2->SetVisibility(ESlateVisibility::Hidden);
			Image_12->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_2->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card2 == 3) {
		if (Obgect->magna >= 2) {
			Obgect->StrengthPotion();
			Obgect->magna -= 2;
			Card2->SetIsEnabled(false);
			Card2->SetVisibility(ESlateVisibility::Hidden);
			Image_12->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_2->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card2 == 4) {
		if (Obgect->magna >= 2) {
			Obgect->PotionWeakness();
			Obgect->magna -= 2;
			Card2->SetIsEnabled(false);
			Card2->SetVisibility(ESlateVisibility::Hidden);
			Image_12->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_2->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card2 == 5) {
		if (Obgect->magna >= 2) {
			Obgect->Attack_x2();
			Obgect->magna -= 2;
			Card2->SetIsEnabled(false);
			Card2->SetVisibility(ESlateVisibility::Hidden);
			Image_12->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_2->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card2 == 6) {
		if (Obgect->magna >= 2) {
			Obgect->Heal_and_Shead();
			Obgect->magna -= 2;
			Card2->SetIsEnabled(false);
			Card2->SetVisibility(ESlateVisibility::Hidden);
			Image_12->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_2->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card2 == 7) {
		if (Obgect->magna >= 3) {
			Obgect->PotionWeakness_and_StrengthPotion();
			Obgect->magna -= 3;
			Card2->SetIsEnabled(false);
			Card2->SetVisibility(ESlateVisibility::Hidden);
			Image_12->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_2->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	Obgect->GameOverTheEnemyLost();
}

void UMyUserWidget::ClicedCard3()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (Obgect->ind_card3 == 0) {
		if (Obgect->magna >= 1) {
			Obgect->Attack();
			Obgect->magna -= 1;
			Card3->SetIsEnabled(false);
			Card3->SetVisibility(ESlateVisibility::Hidden);
			Image_13->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_1->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card3 == 1) {
		if (Obgect->magna >= 1) {
			Obgect->Heal();
			Obgect->magna -= 1;
			Card3->SetIsEnabled(false);
			Card3->SetVisibility(ESlateVisibility::Hidden);
			Image_13->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_1->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card3 == 2) {
		if (Obgect->magna >= 1) {
			Obgect->Shead();
			Obgect->magna -= 1;
			Card3->SetIsEnabled(false);
			Card3->SetVisibility(ESlateVisibility::Hidden);
			Image_13->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_1->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card3 == 3) {
		if (Obgect->magna >= 2) {
			Obgect->StrengthPotion();
			Obgect->magna -= 2;
			Card3->SetIsEnabled(false);
			Card3->SetVisibility(ESlateVisibility::Hidden);
			Image_13->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_1->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card3 == 4) {
		if (Obgect->magna >= 2) {
			Obgect->PotionWeakness();
			Obgect->magna -= 2;
			Card3->SetIsEnabled(false);
			Card3->SetVisibility(ESlateVisibility::Hidden);
			Image_13->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_1->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card3 == 5) {
		if (Obgect->magna >= 2) {
			Obgect->Attack_x2();
			Obgect->magna -= 2;
			Card3->SetIsEnabled(false);
			Card3->SetVisibility(ESlateVisibility::Hidden);
			Image_13->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_1->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card3 == 6) {
		if (Obgect->magna >= 2) {
			Obgect->Heal_and_Shead();
			Obgect->magna -= 2;
			Card3->SetIsEnabled(false);
			Card3->SetVisibility(ESlateVisibility::Hidden);
			Image_13->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_1->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	else if (Obgect->ind_card3 == 7) {
		if (Obgect->magna >= 3) {
			Obgect->PotionWeakness_and_StrengthPotion();
			Obgect->magna -= 3;
			Card3->SetIsEnabled(false);
			Card3->SetVisibility(ESlateVisibility::Hidden);
			Image_13->SetVisibility(ESlateVisibility::Hidden);
			TextBlock_1->SetVisibility(ESlateVisibility::Hidden);
		}
	}
	Obgect->GameOverTheEnemyLost();
}

void UMyUserWidget::ClicedStop()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	Obgect->EnemyMove();
	Card1->SetIsEnabled(true);
	Card1->SetVisibility(ESlateVisibility::Visible);
	Card2->SetIsEnabled(true);
	Card2->SetVisibility(ESlateVisibility::Visible);
	Card3->SetIsEnabled(true);
	Card3->SetVisibility(ESlateVisibility::Visible);
	Image_13->SetVisibility(ESlateVisibility::Visible);
	Image_12->SetVisibility(ESlateVisibility::Visible);
	Image_7->SetVisibility(ESlateVisibility::Visible);
	TextBlock_245->SetVisibility(ESlateVisibility::Visible);
	TextBlock_2->SetVisibility(ESlateVisibility::Visible);
	TextBlock_1->SetVisibility(ESlateVisibility::Visible);
}

FString UMyUserWidget::Magna() {
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	return FString::FromInt(Obgect->magna);
}

FString UMyUserWidget::StrMagnC1() {
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (Obgect->ind_card1 == 1 || Obgect->ind_card1 == 2 || Obgect->ind_card1 == 0) {
		return FString::FromInt(1);
	}
	else if (Obgect->ind_card1 == 3 || Obgect->ind_card1 == 4 || Obgect->ind_card1 == 5 || Obgect->ind_card1 == 6) {
		return FString::FromInt(2);
	}
	else if (Obgect->ind_card1 == 7) {
		return FString::FromInt(3);
	}
	return FString::FromInt(0);
}

void UMyUserWidget::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	Super::NativeTick(MyGeometry, InDeltaTime);
	if (b) {
		Image_17->SetVisibility(ESlateVisibility::Hidden);
		Image_18->SetVisibility(ESlateVisibility::Hidden);
		Image_19->SetVisibility(ESlateVisibility::Hidden);
		TextBlock_6->SetVisibility(ESlateVisibility::Hidden);
		Button->SetVisibility(ESlateVisibility::Hidden);
		Button_2->SetVisibility(ESlateVisibility::Hidden);
		b = false;
	}
	if (Obgect->finish) {
		Image_17->SetVisibility(ESlateVisibility::Visible);
		Image_18->SetVisibility(ESlateVisibility::Visible);
		Image_19->SetVisibility(ESlateVisibility::Visible);
		TextBlock_6->SetVisibility(ESlateVisibility::Visible);
		Button->SetVisibility(ESlateVisibility::Visible);
		Button_2->SetVisibility(ESlateVisibility::Visible);
		Obgect->finish = false;
		if (Obgect->WinHero) {
			Obgect->money += 60;
			Obgect->level += 200;
			Obgect->numgames++;
			strMoney = "+60";
			strLevel = "+200";
		}
		else {
			Obgect->money += 30;
			Obgect->level += 50;
			Obgect->numgames++;
			strMoney = "+30";
			strLevel = "+50";
		}
		FString FilePath = TEXT("game.txt");
		int32 LineIndex = 2;
		FString FullPath = FPaths::Combine(FPaths::ProjectDir(), FilePath);
		TArray<FString> Lines;
		FFileHelper::LoadFileToStringArray(Lines, *FullPath);
		if (LineIndex >= 0 && LineIndex < Lines.Num())
		{
			FString UpdatedLine = FString::Printf(TEXT("%d"), Obgect->money);
			Lines[LineIndex] = UpdatedLine;
			FFileHelper::SaveStringArrayToFile(Lines, *FullPath);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Error"));
		}
		LineIndex = 1;
		if (LineIndex >= 0 && LineIndex < Lines.Num())
		{
			FString UpdatedLine = FString::Printf(TEXT("%d"), Obgect->level);
			Lines[LineIndex] = UpdatedLine;
			FFileHelper::SaveStringArrayToFile(Lines, *FullPath);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Error"));
		}
		LineIndex = 0;
		if (LineIndex >= 0 && LineIndex < Lines.Num())
		{
			FString UpdatedLine = FString::Printf(TEXT("%d"), Obgect->numgames);
			Lines[LineIndex] = UpdatedLine;
			FFileHelper::SaveStringArrayToFile(Lines, *FullPath);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Error"));
		}
	}
}

FString UMyUserWidget::WinOrLose()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (Obgect->WinHero) {
		str = TEXT("You Win");
	}
	else {
		str = TEXT("You Lose");
	}
	return str;
}

FString UMyUserWidget::StrMagnC2()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (Obgect->ind_card2 == 1 || Obgect->ind_card2 == 2 || Obgect->ind_card2 == 0) {
		return FString::FromInt(1);
	}
	else if (Obgect->ind_card2 == 3 || Obgect->ind_card2 == 4 || Obgect->ind_card2 == 5 || Obgect->ind_card2 == 6) {
		return FString::FromInt(2);
	}
	else if (Obgect->ind_card2 == 7) {
		return FString::FromInt(3);
	}
	return FString::FromInt(0);
}

FString UMyUserWidget::STRM()
{
	return strMoney;
}

FString UMyUserWidget::StrMagnC3()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	if (Obgect->ind_card3 == 1 || Obgect->ind_card3 == 2 || Obgect->ind_card3 == 0) {
		return FString::FromInt(1);
	}
	else if (Obgect->ind_card3 == 3 || Obgect->ind_card3 == 4 || Obgect->ind_card3 == 5 || Obgect->ind_card3 == 6) {
		return FString::FromInt(2);
	}
	else if (Obgect->ind_card3 == 7) {
		return FString::FromInt(3);
	}
	return FString::FromInt(0);
}

FString UMyUserWidget::STRL()
{
	return strLevel;
}

float UMyUserWidget::HealHero()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	return  Obgect->HealHero()  / 100.0;
}

float UMyUserWidget::HealEnemy()
{
	AMyGameModeBase * Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	return  Obgect->HealEnemy() / 100.0;
}

FString UMyUserWidget::EnemySheald()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	return FString::FromInt(Obgect->Enemy->shield);
}

FString UMyUserWidget::HealSheald()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	return FString::FromInt(Obgect->Hero->shield);
}


FString UMyUserWidget::HealHeroText()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	return FString::FromInt(Obgect->HealHero());
}

FString UMyUserWidget::HealEnemyText()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	return FString::FromInt(Obgect->HealEnemy());
}

FString UMyUserWidget::BoostAttackEnemy()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	return FString::FromInt(Obgect->Enemy->boost_attack * 100 - 100) + "%";
}

FString UMyUserWidget::BoostAttackHero()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	return FString::FromInt(Obgect->Hero->boost_attack * 100 - 100) + "%";
}

FSlateBrush UMyUserWidget::Card1_Imadge()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	FSlateBrush Imadge;
	UTexture2D* Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/last-timejew-"));
	int q = Obgect->ind_card1;
	if (q == 0) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/last-timejew-"));
	}
	if (q == 1) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/Heart_corazón_svg"));
	}
	if (q == 2) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/dima-piatyhorets-shchiit2"));
	}
	if (q == 3) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/pngwing_com"));
	}
	if (q == 4) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/transparent-witch-65226768c4fb36_8863024616967535128068"));
	}
	if (q == 5) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/Default_2_swords_in_a_vertical_position_on_a_gray_background_a_3__1_"));
	}
	if (q == 6) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/Default_heart_and_shield_in_a_vertical_position_on_a_gray_back_0__1_"));
	}
	if (q == 7) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/Default_On_the_right_side_there_should_be_2_potions_a_poison_p_3"));
	}
	if (Texture)
	{
		Imadge.SetResourceObject(Texture);
	}
	return Imadge;
}

FSlateBrush UMyUserWidget::Card2_Imadge()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	FSlateBrush Imadge;
	int q = Obgect->ind_card2;
	UTexture2D* Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/NewTexture2DArray_2"));
	if (q == 0) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/last-timejew-"));
	}
	if (q == 1) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/Heart_corazón_svg"));
	}
	if (q == 2) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/dima-piatyhorets-shchiit2"));
	}
	if (q == 3) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/pngwing_com"));
	}
	if (q == 4) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/transparent-witch-65226768c4fb36_8863024616967535128068"));
	}
	if (q == 5) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/Default_2_swords_in_a_vertical_position_on_a_gray_background_a_3__1_"));
	}
	if (q == 6) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/Default_heart_and_shield_in_a_vertical_position_on_a_gray_back_0__1_"));
	}
	if (q == 7) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/Default_On_the_right_side_there_should_be_2_potions_a_poison_p_3"));
	}
	if (Texture)
	{
		Imadge.SetResourceObject(Texture);
	}
	return Imadge;
}

FSlateBrush UMyUserWidget::Card3_Imadge()
{
	AMyGameModeBase* Obgect = Cast<AMyGameModeBase>(UGameplayStatics::GetGameMode(GetWorld()));
	FSlateBrush Imadge;
	int q = Obgect->ind_card3;
	UTexture2D* Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/NewTexture2DArray_3"));
	if (q == 0) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/last-timejew-"));
	}
	if (q == 1) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/Heart_corazón_svg"));
	}
	if (q == 2) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/dima-piatyhorets-shchiit2"));
	}
	if (q == 3) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/pngwing_com"));
	}
	if (q == 4) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/transparent-witch-65226768c4fb36_8863024616967535128068"));
	}
	if (q == 5) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/Default_2_swords_in_a_vertical_position_on_a_gray_background_a_3__1_"));
	}
	if (q == 6) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/Default_heart_and_shield_in_a_vertical_position_on_a_gray_back_0__1_"));
	}
	if (q == 7) {
		Texture = LoadObject<UTexture2D>(nullptr, TEXT("/Game/UI/Default_On_the_right_side_there_should_be_2_potions_a_poison_p_3"));
	}
	if (Texture)
	{
		Imadge.SetResourceObject(Texture);
	}
	return Imadge;
}



