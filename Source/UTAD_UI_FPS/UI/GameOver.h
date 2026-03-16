// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameOver.generated.h"

/**
 * 
 */
class UButton;
class UWidgetAnimation;

UCLASS()
class UTAD_UI_FPS_API UGameOver : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UButton> TryAgainButton;

	UPROPERTY(BlueprintReadWrite, meta = (BindWidget))
	TObjectPtr<UButton> QuitButton;

	UPROPERTY(Transient, meta = (BindWidgetAnim))
	TObjectPtr<UWidgetAnimation> FadeIn;
	
	void Show();

protected:

	virtual void NativeConstruct() override;

private:

	UFUNCTION()
	void TryAgain();
	
	UFUNCTION()
	void Quit();
};
