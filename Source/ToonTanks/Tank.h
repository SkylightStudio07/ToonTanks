// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
public:
	ATank();

	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
private:
	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* CameraComp;

	UPROPERTY(VisibleAnywhere, Category = "Components", BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* SpringArm;

	void Move(float Value);
	void Turn(float Value);

	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float Speed = 800.f;

	UPROPERTY(EditAnywhere, Category = "Movement", BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	float TurnRate = 45.f;

	APlayerController* PlayerControllerRef;

protected:
	virtual void BeginPlay() override;

};
