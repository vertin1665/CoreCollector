// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "CoreCollectorCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;

//输入映射上下文的配置文件
class UInputMappingContext;
//刚做的输入操作类
class UInputAction;
//传递输入的数据
struct FInputActionValue;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

/**
 *  A simple player-controllable third person character
 *  Implements a controllable orbiting camera
 */
UCLASS(abstract)
class ACoreCollectorCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;
	
protected:

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* LookAction;

	/** Mouse Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MouseLookAction;

public:

	/** Constructor */
	ACoreCollectorCharacter();	

protected:

	/** Initialize input action bindings */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

public:

	/** Handles move inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoMove(float Right, float Forward);

	/** Handles look inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoLook(float Yaw, float Pitch);

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpStart();

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpEnd();

public:

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

protected:
	//设置游戏开始
	virtual void BeginPlay() override;
	//设置玩家输入组件
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	//新建的输入资产变量
	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Input)
	UInputMappingContext* DefaultMappingContext;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Input)
	UInputAction* MoveAction;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Input)
	UInputAction* LookAction;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Input)
	UInputAction* JumpAction;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Input)
	UIputAction* SprintAction;

	UPROPERTY(EditAnywhere,BlueprintReadOnly,Category=Input)
	UInputAction* InteractAction;

	//移动和视角的函数
	void Move(const FInputActionValue& Value);
	void Look(const FInputActionValue& Value);

	//冲刺和交互的函数
	void StartSprint();
	void StopSprint();
	void Interact();

	//速度控制
	UPROPERTY(EditAnywhere,Category="Movement")
	float SprintSpeed = 1200.0f;
	float DefaultSpeed = 600.0f;

};

