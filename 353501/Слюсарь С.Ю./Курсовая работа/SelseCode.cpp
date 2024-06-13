// Fill out your copyright notice in the Description page of Project Settings.


#include "SelseCode.h"

// Sets default values
ASelseCode::ASelseCode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}
TArray<FSelsAV> ASelseCode::CreateSeilsAV(TArray<FVector> Flor, TArray<FSelsAV> sels,int XSize,int YSize,int StartSeilsCount)
{
	for (int i = 0; i < XSize * YSize; i++)
	{
		FSelsAV CountSel;
		CountSel.position = Flor[i];
		CountSel.Alive = false;
		CountSel.Density = FMath::FRandRange(0.0f,0.5f);

		sels.Add(CountSel);
	}
	for (int i = 0; i < StartSeilsCount; i++)
	{
		sels[FMath::RandRange(0, XSize * YSize)].Alive = true;
	}
	return sels;
}

float ASelseCode::RooleOfAutomate(TArray<FSelsAV> Flore, int Index, int XSize, int YSize)
{
	int X = Index % XSize;
	int Y = Index / XSize;
	float TotalDensety = 0.0f;
	int NeighborCount = 0;
	for (int OffsetY = -1; OffsetY <= 1; OffsetY++)
	{
		for (int OffsetX = -1; OffsetX <= 1; OffsetX++)
		{
			if (OffsetX == 0 && OffsetY == 0)continue;
			int NeighborX = (X + OffsetX + XSize) % XSize;
			int NeighborY = (Y + OffsetY + YSize) % YSize;
			int NeighborIdex = NeighborX + NeighborY * XSize;
			TotalDensety += Flore[NeighborIdex].Density;
			NeighborCount++;
		}
	}
	return TotalDensety / NeighborCount;
}
TArray<FSelsAV> ASelseCode::ApplyRules(TArray<FSelsAV> Flore, int XSize, int YSize)
{
	TArray<FSelsAV> NewFlore = Flore;
	for (int i = 0; i < Flore.Num(); i++)
	{
		float NeighborDestany = RooleOfAutomate(Flore, i, XSize, YSize);
		if (Flore[i].Alive)
		{
			if (NeighborDestany < 0.2f)
			{
				NewFlore[i].Alive = false;
				NewFlore[i].Density = 0.0f;
			}
			else
			{
				NewFlore[i].Density = FMath::Clamp(NewFlore[i].Density + NeighborDestany * 0.1f, 0.0f, 1.0f);
			}
		}
		else
		{
			if (NeighborDestany > 0.5f)
			{
				NewFlore[i].Alive = true;
				NewFlore[i].Density = NeighborDestany * 0.5f;
			}
		}
	}
	return NewFlore;
}
// Called when the game starts or when spawned
void ASelseCode::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASelseCode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

