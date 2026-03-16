// Fill out your copyright notice in the Description page of Project Settings.

#include "GameOver.h"
#include "Components/Button.h"
#include "Kismet/KismetSystemLibrary.h"

void UGameOver::NativeConstruct()
{
	//I II III IV V VI VII VIII IX X XI XII XIII XIV XV XVI XVII XVIII XIX XX
	
	TryAgainButton->OnClicked.AddDynamic(this, &UGameOver::TryAgain);
	QuitButton->OnClicked.AddDynamic(this, &UGameOver::Quit);
}

void UGameOver::Show()
{
	
}

void UGameOver::TryAgain()
{
	APlayerController* player = GetOwningPlayer<APlayerController>();

	if (player)
	{
		player->RestartLevel();
	}
}

void UGameOver::Quit()
{
	UKismetSystemLibrary::QuitGame(GetWorld(), NULL, EQuitPreference::Quit, true);
}
