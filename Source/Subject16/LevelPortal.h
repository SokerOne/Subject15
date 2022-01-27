#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Materials/MaterialInstance.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "Particles/ParticleSystemComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Engine/DataTable.h"
#include "Components/BoxComponent.h"
#include "LevelPortal.generated.h"

// TODO: Sonido ambiente
// TODO: Sonido de entrada
// TODO: Luz

UCLASS()
class SUBJECT16_API ALevelPortal : public AActor
{
    GENERATED_BODY()

  public:
    ALevelPortal();

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    USceneComponent *RootCompCpp;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UBoxComponent *BoxCompCpp;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UDataTable *LevelPortalDataTableCpp;

    UPROPERTY(EditDefaultsOnly, BlueprintReadWrite)
    UParticleSystemComponent *PortalParticleSystemCompCpp;

    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Portal")
    bool AllowTravel = false;

    UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Level Portal")
    FName TravelOverride = {"None"};

  protected:
    virtual void BeginPlay() override;

  public:
    virtual void Tick(float DeltaTime) override;

  private:
    UFUNCTION()
    void OnOverlap(UPrimitiveComponent *OverlappedComp, AActor *Other,
                   UPrimitiveComponent *OtherComp, int32 OtherBodyIndex, bool bFromSweep,
                   const FHitResult &SweepResult);
};