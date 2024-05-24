// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


class KURSATH_API UMyUnit
{
public:
    int health;
    double boost_attack;
    int shield;

    UMyUnit();

    void EnemyStrike(int);
    void WeakeningProtectionFromTheEnemy(int);
    void WeakeningAttackFromTheEnemy(int procent);
    int Attack(int);
    void HealthRecovery(int);
    void Shield(int);
};
