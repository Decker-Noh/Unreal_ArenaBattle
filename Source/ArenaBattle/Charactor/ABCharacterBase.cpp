// Fill out your copyright notice in the Description page of Project Settings.


#include "Charactor/ABCharacterBase.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ABCharacterDataAsset.h"

// Sets default values
AABCharacterBase::AABCharacterBase()
{
	//Pawn
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

	//Capsule
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);
	GetCapsuleComponent()->SetCollisionProfileName(TEXT("Pawn"));

	// Movement
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 500.0f, 0.0f);
	GetCharacterMovement()->JumpZVelocity = 700.f;
	GetCharacterMovement()->AirControl = 0.35f;
	GetCharacterMovement()->MaxWalkSpeed = 500.f;
	GetCharacterMovement()->MinAnalogWalkSpeed = 20.f;
	GetCharacterMovement()->BrakingDecelerationWalking = 2000.f;

	// Mesh
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0f, 0.0f, -100.0f), FRotator(0.0f, -90.0f, 0.0f));
	GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);
	GetMesh()->SetCollisionProfileName(TEXT("CharacterMesh"));

	//메시 가져와서 부착
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> CharacterMeshRef(TEXT("/Script/Engine.SkeletalMesh'/Game/InfinityBladeWarriors/Character/CompleteCharacters/SK_CharM_Cardboard.SK_CharM_Cardboard'"));
	if (CharacterMeshRef.Object)
	{
		GetMesh()->SetSkeletalMesh(CharacterMeshRef.Object);
	}
	//애니메이션 가져와서 부착
	static ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstanceClassRef(TEXT("/Game/ArenaBattle/Animation/ABP_ABCharacter.ABP_ABCharacter_C"));
	if (AnimInstanceClassRef.Class)
	{
		UE_LOG(LogTemp, Log, TEXT("Anim suc"));
		GetMesh()->SetAnimInstanceClass(AnimInstanceClassRef.Class);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("Anim fail"));
	}

	static ConstructorHelpers::FObjectFinder<UABCharacterDataAsset> ShoulderDataRef(TEXT("/Script/ArenaBattle.ABCharacterDataAsset'/Game/ArenaBattle/CharacterControl/ABC_Shoulder.ABC_Shoulder'"));
	static ConstructorHelpers::FObjectFinder<UABCharacterDataAsset> QuaterDataRef(TEXT("/Script/ArenaBattle.ABCharacterDataAsset'/Game/ArenaBattle/CharacterControl/ABC_Quater.ABC_Quater'"));
	
	if (ShoulderDataRef.Object)
	{
		CharacterControlManager.Add(ECharacterControlType::Shoulder, ShoulderDataRef.Object);
		if (ShoulderDataRef.Object->InputMappingContext)
		{
			UE_LOG(LogTemp, Log, TEXT("you"));
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("moo"));
		}
	}
	if (QuaterDataRef.Object)
	{
		CharacterControlManager.Add(ECharacterControlType::Quater, QuaterDataRef.Object);
	}
	else
	{
		UE_LOG(LogTemp, Log, TEXT("none2"));
	}
	UE_LOG(LogTemp, Log, TEXT(":d: %d"), CharacterControlManager.Num());
}

void AABCharacterBase::SetCharacterControlData(UABCharacterDataAsset* CharacterData)
{
	// Pawn
	bUseControllerRotationYaw = CharacterData->bUseControllerRotationYaw;

	// CharacterMovement
	GetCharacterMovement()->bOrientRotationToMovement = CharacterData->bOrientRotationToMovement;
	GetCharacterMovement()->bUseControllerDesiredRotation = CharacterData->bUseControllerDesiredRotation;
	GetCharacterMovement()->RotationRate = CharacterData->RotationRate;
}

