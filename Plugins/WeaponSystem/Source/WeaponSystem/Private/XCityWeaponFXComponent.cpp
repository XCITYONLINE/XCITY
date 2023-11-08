
#include "XCityWeaponFXComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "PhysicalMaterials/PhysicalMaterial.h"
#include "Kismet/GameplayStatics.h"
#include "Components/DecalComponent.h"



UXCityWeaponFXComponent::UXCityWeaponFXComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UXCityWeaponFXComponent::PlayImpactFX(const FHitResult& Hit)
{
	auto ImpactData = DefaultImpactData;

	if (Hit.PhysMaterial.IsValid())
	{
		const auto PhysMat = Hit.PhysMaterial.Get();
		if (ImpactDataMap.Contains(PhysMat))
		{
			ImpactData = ImpactDataMap[PhysMat];
		}
	}

	// Spawn niagara
	UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(),               //
		ImpactData.NiagaraEffect,                                            //
		Hit.ImpactPoint,                                                     //
		Hit.ImpactNormal.Rotation());

	// Spawn decal
	auto DecalComponent = UGameplayStatics::SpawnDecalAtLocation(GetWorld(), //
		ImpactData.DecalData.Material,                                       //
		ImpactData.DecalData.Size,                                           //
		Hit.ImpactPoint,                                                     //
		Hit.ImpactNormal.Rotation());

	if (DecalComponent)
	{
		DecalComponent->SetFadeOut(ImpactData.DecalData.LifeTime, ImpactData.DecalData.FadeOutTime);
	}
}
