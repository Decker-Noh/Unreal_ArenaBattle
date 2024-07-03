// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Charactor/ABCharacterBase.h"
#include "ABCharacterNonePlayer.generated.h"

/**
 * 
 */
UCLASS()
class ARENABATTLE_API AABCharacterNonPlayer : public AABCharacterBase
{
	GENERATED_BODY()

public:
	AABCharacterNonPlayer();

protected:
	virtual void SetDead() override;
};