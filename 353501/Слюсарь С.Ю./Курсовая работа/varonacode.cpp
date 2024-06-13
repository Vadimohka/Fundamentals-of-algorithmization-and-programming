// Fill out your copyright notice in the Description page of Project Settings.


#include "varonacode.h"



// Sets default values
Avaronacode::Avaronacode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void Avaronacode::BeginPlay()
{
	Super::BeginPlay();
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Black, TEXT("11"));
	}
	
}

TArray<FVector> Avaronacode::GetSitePoints(TArray<FVector> GetSitePoints,int Min,int Max,int Size)
{
	TArray<FVector> SiteArray;
	for (int i = 0; i < Size; i++)
	{
		int Caunt = FMath::RandRange(Min, Max);
		SiteArray.Add(GetSitePoints[Caunt]);
		UE_LOG(LogTemp, Warning, TEXT("%s"), *SiteArray[i].ToString());
	}
	return SiteArray;
}
TArray<FVaroniaStruct> Avaronacode::GenerateSiteNode(TArray<FVector> Sites, TArray<FVaroniaStruct> OutCells)
{
	for (const FVector& Point : Sites)
	{
		FVaroniaStruct Cell;
		Cell.Site = Point;

		// Создаем ячейку и заполняем ее вершинами
		for (const FVector& Vertex : Sites)
		{
			if (Point != Vertex) // Исключаем текущую точку
			{
				Cell.Vertices.Add(Vertex);
			}
		}

		// Добавляем ячейку в результат
		OutCells.Add(Cell);
	}
	return OutCells;
}
float Distanse(FVector A,FVector B)
{
	return FVector::Dist(A, B);
}
TArray<FVaroniaStruct> Avaronacode::GenerateVoronoiDiagram(TArray<FVaroniaStruct> PointsTF, TArray<FVector> Region, int Widh, int height)
{
	for (int i = 0; i < Widh*height; i++)
	{
		    FVector CurrwntPoint = Region[i];
			int ClosestPointDistance = 0;
			float ClosestDistanse = Distanse(CurrwntPoint, PointsTF[0].Site);
			for (int j = 0; j < PointsTF.Num(); j++)
			{
				float DistanseTF = Distanse(CurrwntPoint, PointsTF[j].Site);
				if (DistanseTF < ClosestDistanse)
				{
					ClosestPointDistance = j;
					ClosestDistanse = DistanseTF;
				}
			}
			PointsTF[ClosestPointDistance].Region.Add(CurrwntPoint);
	}
	return PointsTF;
}



// Called every frame
void Avaronacode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

