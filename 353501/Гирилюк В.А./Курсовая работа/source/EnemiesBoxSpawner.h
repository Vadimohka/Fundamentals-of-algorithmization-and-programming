// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Enemy.h"
#include <Components/BoxComponent.h>
#include "EnemiesBoxSpawner.generated.h"

UCLASS()
class MYSLAYTHESPIRE_API AEnemiesBoxSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEnemiesBoxSpawner();

public:
	virtual void BeginPlay() override;

	UBoxComponent* BoxSpawner;

	UPROPERTY(EditDefaultsOnly)
	TSubclassOf<AActor> SpawnerClass;

	UPROPERTY(EditDefaultsOnly)
	int SpawnObjectCount;

	UPROPERTY(EditDefaultsOnly)
	bool bShouldSpawnLoop;

	AEnemy* SpawnActor();

};
