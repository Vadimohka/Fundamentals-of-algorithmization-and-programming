// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget_2.h"
#include "MyGameModeBase_2.h"
#include "CoreUObject.h"
#include "Misc/FileHelper.h"
#include <Windows.h>
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

bool UMyUserWidget_2::Initialize()
{
	Super::Initialize();
	if (Start != nullptr)
	{
		Start->OnClicked.AddDynamic(this, &UMyUserWidget_2::Start_fun);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Card1 is not initialized!"));
	}
	if (Button_0 != nullptr)
	{
		Button_0->OnClicked.AddDynamic(this, &UMyUserWidget_2::Button_0_fun);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Card1 is not initialized!"));
	}
	if (Button1 != nullptr)
	{
		Button1->OnClicked.AddDynamic(this, &UMyUserWidget_2::Button1_fun);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Card1 is not initialized!"));
	}
	if (Button2 != nullptr)
	{
		Button2->OnClicked.AddDynamic(this, &UMyUserWidget_2::Button2_fun);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Card1 is not initialized!"));
	}
	if (Button3 != nullptr)
	{
		Button3->OnClicked.AddDynamic(this, &UMyUserWidget_2::Button3_fun);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Card1 is not initialized!"));
	}
	return true;
}

void UMyUserWidget_2::Start_fun()
{
	UGameplayStatics::OpenLevel(GetWorld(), FName("M1"));
}

void UMyUserWidget_2::Button_0_fun()
{
	AMyGameModeBase_2* Obgect = Cast<AMyGameModeBase_2>(UGameplayStatics::GetGameMode(GetWorld()));
	Obgect->money = 0;
	Obgect->level = 0;
	Obgect->numbgame = 0;
	Obgect->cardshop1 = 0;
	FString FilePath = TEXT("game.txt");
	int32 LineIndex = 0;
	FString FullPath = FPaths::Combine(FPaths::ProjectDir(), FilePath);
	TArray<FString> Lines;
	FFileHelper::LoadFileToStringArray(Lines, *FullPath);
	if (LineIndex >= 0 && LineIndex < Lines.Num())
	{
		FString UpdatedLine = FString::Printf(TEXT("%d"), 0);
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
		FString UpdatedLine = FString::Printf(TEXT("%d"), 0);
		Lines[LineIndex] = UpdatedLine;
		FFileHelper::SaveStringArrayToFile(Lines, *FullPath);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error"));
	}
	LineIndex = 2;
	if (LineIndex >= 0 && LineIndex < Lines.Num())
	{
		FString UpdatedLine = FString::Printf(TEXT("%d"), 0);
		Lines[LineIndex] = UpdatedLine;
		FFileHelper::SaveStringArrayToFile(Lines, *FullPath);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error"));
	}
	LineIndex = 3;
	if (LineIndex >= 0 && LineIndex < Lines.Num())
	{
		FString UpdatedLine = FString::Printf(TEXT("%d"), 0);
		Lines[LineIndex] = UpdatedLine;
		FFileHelper::SaveStringArrayToFile(Lines, *FullPath);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Error"));
	}
}

void UMyUserWidget_2::Button1_fun()
{
	AMyGameModeBase_2* Obgect = Cast<AMyGameModeBase_2>(UGameplayStatics::GetGameMode(GetWorld()));
	if (Obgect->money >= 120) {
		Obgect->money -= 120;
		Obgect->cardshop1 += 1;
		FString FilePath = TEXT("game.txt");
		int32 LineIndex = 3;
		FString FullPath = FPaths::Combine(FPaths::ProjectDir(), FilePath);
		TArray<FString> Lines;
		FFileHelper::LoadFileToStringArray(Lines, *FullPath);
		if (LineIndex >= 0 && LineIndex < Lines.Num())
		{
			FString UpdatedLine = FString::Printf(TEXT("%d"), Obgect->cardshop1);
			Lines[LineIndex] = UpdatedLine;
			FFileHelper::SaveStringArrayToFile(Lines, *FullPath);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Error"));
		}
	}
}

void UMyUserWidget_2::Button2_fun()
{
	AMyGameModeBase_2* Obgect = Cast<AMyGameModeBase_2>(UGameplayStatics::GetGameMode(GetWorld()));
	if (Obgect->money >= 180) {
		Obgect->money -= 180;
		Obgect->cardshop1 += 1;
		FString FilePath = TEXT("game.txt");
		int32 LineIndex = 3;
		FString FullPath = FPaths::Combine(FPaths::ProjectDir(), FilePath);
		TArray<FString> Lines;
		FFileHelper::LoadFileToStringArray(Lines, *FullPath);
		if (LineIndex >= 0 && LineIndex < Lines.Num())
		{
			FString UpdatedLine = FString::Printf(TEXT("%d"), Obgect->cardshop1);
			Lines[LineIndex] = UpdatedLine;
			FFileHelper::SaveStringArrayToFile(Lines, *FullPath);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Error"));
		}
	}
}

void UMyUserWidget_2::Button3_fun()
{
	AMyGameModeBase_2* Obgect = Cast<AMyGameModeBase_2>(UGameplayStatics::GetGameMode(GetWorld()));
	if (Obgect->money >= 250) {
		Obgect->money -= 250;
		Obgect->cardshop1 += 1;
		FString FilePath = TEXT("game.txt");
		int32 LineIndex = 3;
		FString FullPath = FPaths::Combine(FPaths::ProjectDir(), FilePath);
		TArray<FString> Lines;
		FFileHelper::LoadFileToStringArray(Lines, *FullPath);
		if (LineIndex >= 0 && LineIndex < Lines.Num())
		{
			FString UpdatedLine = FString::Printf(TEXT("%d"), Obgect->cardshop1);
			Lines[LineIndex] = UpdatedLine;
			FFileHelper::SaveStringArrayToFile(Lines, *FullPath);
		}
		else
		{
			UE_LOG(LogTemp, Error, TEXT("Error"));
		}
	}
}

FString UMyUserWidget_2::Money()
{
	AMyGameModeBase_2* Obgect = Cast<AMyGameModeBase_2>(UGameplayStatics::GetGameMode(GetWorld()));
	return FString::FromInt(Obgect->money);
}

FString UMyUserWidget_2::Level()
{
	AMyGameModeBase_2* Obgect = Cast<AMyGameModeBase_2>(UGameplayStatics::GetGameMode(GetWorld()));
	return FString::FromInt(Obgect->level);
}

FString UMyUserWidget_2::NumGames()
{
	AMyGameModeBase_2* Obgect = Cast<AMyGameModeBase_2>(UGameplayStatics::GetGameMode(GetWorld()));
	return FString::FromInt(Obgect->numbgame);
}

void UMyUserWidget_2::NativeTick(const FGeometry& MyGeometry, float InDeltaTime) {
	AMyGameModeBase_2* Obgect = Cast<AMyGameModeBase_2>(UGameplayStatics::GetGameMode(GetWorld()));
	if (Obgect->level < 200 || Obgect->cardshop1 < 0) {
		Button1->SetIsEnabled(false);
	}
	else {
		Button1->SetIsEnabled(true);
	}
	if (Obgect->level < 400 || Obgect->cardshop1 < 1) {
		Button2->SetIsEnabled(false);
	}
	else {
		Button2->SetIsEnabled(true);
	}
	if (Obgect->level < 600 || Obgect->cardshop1 < 2) {
		Button3->SetIsEnabled(false);
	}
	else {
		Button3->SetIsEnabled(true);
	}
	if (Obgect->cardshop1 == 1) {
		Button1->SetIsEnabled(false);
	}
	if (Obgect->cardshop1 == 2) {
		Button1->SetIsEnabled(false);
		Button2->SetIsEnabled(false);
	}
	if (Obgect->cardshop1 == 3) {
		Button1->SetIsEnabled(false);
		Button2->SetIsEnabled(false);
		Button3->SetIsEnabled(false);
	}
}
