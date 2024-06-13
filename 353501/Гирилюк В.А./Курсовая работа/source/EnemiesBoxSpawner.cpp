// Fill out your copyright notice in the Description page of Project Settings.


#include "EnemiesBoxSpawner.h"
#include "SkeletonAxe.h"
#include "Kismet/KismetMathLibrary.h"

// Sets default values
AEnemiesBoxSpawner::AEnemiesBoxSpawner() : Super()
{
	SpawnObjectCount = 3;

	BoxSpawner = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxSpawner"));
	BoxSpawner->SetupAttachment(RootComponent);
	BoxSpawner->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

// Called when the game starts or when spawned
void AEnemiesBoxSpawner::BeginPlay()
{
	Super::BeginPlay();
	
}
AEnemy* AEnemiesBoxSpawner::SpawnActor()
{
	FRotator Rotation(0, 0, 0);
	FVector RandomLocation = UKismetMathLibrary::RandomPointInBoundingBox(GetActorLocation(), BoxSpawner->GetScaledBoxExtent());

	return GetWorld()->SpawnActor<AEnemy>(SpawnerClass, RandomLocation, Rotation);
}


