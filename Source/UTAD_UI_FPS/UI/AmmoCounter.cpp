// Fill out your copyright notice in the Description page of Project Settings.


#include "AmmoCounter.h"
#include "../UTAD_UI_FPSCharacter.h"
#include "../TP_WeaponComponent.h"
#include "Components/TextBlock.h"

void UAmmoCounter::Show()
{
	SetVisibility(ESlateVisibility::HitTestInvisible);

	AUTAD_UI_FPSCharacter* character = Cast<AUTAD_UI_FPSCharacter>(GetOwningPlayer()->GetCharacter());
	if (character)
	{
		character->OnTotalBulletsChanged.BindUObject(this, &UAmmoCounter::UpdateTotalAmmo);

		UTP_WeaponComponent* weaponComponent = character->GetAttachedWeaponComponent();

		if (weaponComponent)
		{
			weaponComponent->OnCurrentBulletsChanged.BindUObject(this, &UAmmoCounter::UpdateCurrentAmmo);
		}
	}
}

void UAmmoCounter::Hide()
{
	SetVisibility(ESlateVisibility::Hidden);

	AUTAD_UI_FPSCharacter* character = Cast<AUTAD_UI_FPSCharacter>(GetOwningPlayer()->GetCharacter());
	if (character)
	{
		character->OnTotalBulletsChanged.Unbind();

		UTP_WeaponComponent* weaponComponent = character->GetAttachedWeaponComponent();

		if (weaponComponent)
		{
			weaponComponent->OnCurrentBulletsChanged.Unbind();
		}
	}
}

void UAmmoCounter::UpdateCurrentAmmo(int NewCurrentAmmo)
{
	CurrentAmmo->SetText(FText::AsNumber(NewCurrentAmmo));
}

void UAmmoCounter::UpdateTotalAmmo(int NewTotalAmmo)
{
	TotalAmmo->SetText(FText::AsNumber(NewTotalAmmo));
}
