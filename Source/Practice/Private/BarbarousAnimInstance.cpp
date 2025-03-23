// Fill out your copyright notice in the Description page of Project Settings.


#include "BarbarousAnimInstance.h"
#include "BarbarCharacter.h"
#include "GameFramework\CharacterMovementComponent.h"
#include "Kismet/KismetMathLibrary.h"

void UBarbarousAnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();
	BarbarCharacter = Cast<ABarbarCharacter>(TryGetPawnOwner());

	if (BarbarCharacter) {
		BarbarCharacterMovement = BarbarCharacter->GetCharacterMovement();
	}
}

void UBarbarousAnimInstance::NativeUpdateAnimation(float DeltaTime)
{
	Super::NativeUpdateAnimation(DeltaTime);
	if (BarbarCharacterMovement) {
		GroundSpeed = UKismetMathLibrary::VSizeXY(BarbarCharacterMovement->Velocity);
		CharacterState = BarbarCharacter->GetCharacterState();
	}
}
