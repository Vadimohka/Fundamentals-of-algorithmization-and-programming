// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUnit.h"

    UMyUnit::UMyUnit() {
        health = 100;
        boost_attack = 1;
        shield = 0;
    }

    void UMyUnit::EnemyStrike(int attack) {
        if (shield == 0) {
            health -= attack;
        }
        else if (shield > attack) {
            shield -= attack;
        }
        else {
            attack -= shield;
            shield = 0;
            health -= attack;
        }
    }

    void UMyUnit::WeakeningProtectionFromTheEnemy(int procent) {
        boost_attack += procent / 100.0;
    }

    void UMyUnit::WeakeningAttackFromTheEnemy(int procent) {
        boost_attack -= procent / 100.0;
    }

    int UMyUnit::Attack(int attack) {
        return attack * boost_attack;
    }

    void UMyUnit::HealthRecovery(int healt) {
        if (health + healt >= 100) {
            health = 100;
            return;
        }
        health += healt;
    }

    void UMyUnit::Shield(int shiel) {
        shield += shiel;
    }

