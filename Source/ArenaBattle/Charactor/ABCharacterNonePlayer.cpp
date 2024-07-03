// Fill out your copyright notice in the Description page of Project Settings.


#include "Charactor/ABCharacterNonePlayer.h"

AABCharacterNonPlayer::AABCharacterNonPlayer()
{
}

void AABCharacterNonPlayer::SetDead()
{
	Super::SetDead();
	UE_LOG(LogTemp, Log, TEXT("dead reco3"));
	FTimerHandle DeadTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(DeadTimerHandle, FTimerDelegate::CreateLambda(
		[&]()
		{
			Destroy();
		}
	), DeadEventDelayTime, false);
}