// Fill out your copyright notice in the Description page of Project Settings.


#include "Game/ABGameMode.h"
#include "Player/ABPlayerController.h"

AABGameMode::AABGameMode()
{

	//GameController
	PlayerControllerClass = AABPlayerController::StaticClass();
	//PawnClass
	/*static ConstructorHelpers::FClassFinder<APawn> ThirdPersonClassRef(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C"));
	if (ThirdPersonClassRef.Class != nullptr)
	{
		DefaultPawnClass = ThirdPersonClassRef.Class;
	}*/

	static ConstructorHelpers::FClassFinder<APawn> ThirdPersonClassRef(TEXT("/Script/ArenaBattle.ABCharacterPlayer"));
	if (ThirdPersonClassRef.Class != nullptr)
	{
		DefaultPawnClass = ThirdPersonClassRef.Class;
	}
}
