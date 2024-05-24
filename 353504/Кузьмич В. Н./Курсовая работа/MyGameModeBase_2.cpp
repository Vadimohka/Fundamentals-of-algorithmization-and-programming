// Fill out your copyright notice in the Description page of Project Settings.


#include "MyGameModeBase_2.h"

AMyGameModeBase_2::AMyGameModeBase_2()
{
	HUDClass = AMyHUD_2::StaticClass();
    FString FilePath = TEXT("game.txt");
    int32 LineIndex = 0;
    FString FullPath = FPaths::Combine(FPaths::ProjectDir(), FilePath);
    TArray<FString> Lines;
    FFileHelper::LoadFileToStringArray(Lines, *FullPath);
    if (LineIndex >= 0 && LineIndex < Lines.Num())
    {
        FString Line = Lines[LineIndex];
        numbgame = FCString::Atoi(*Line);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Error"));
    }

    LineIndex = 1;
    if (LineIndex >= 0 && LineIndex < Lines.Num())
    {
        FString Line = Lines[LineIndex];
        level = FCString::Atoi(*Line);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Error"));
    }

    LineIndex = 2;
    if (LineIndex >= 0 && LineIndex < Lines.Num())
    {
        FString Line = Lines[LineIndex];
        money = FCString::Atoi(*Line);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Error"));
    }

    LineIndex = 3;
    if (LineIndex >= 0 && LineIndex < Lines.Num())
    {
        FString Line = Lines[LineIndex];
        cardshop1 = FCString::Atoi(*Line);
    }
    else
    {
        UE_LOG(LogTemp, Error, TEXT("Error"));
    }
}
