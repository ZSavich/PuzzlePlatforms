

#include "Meshes/PPMovingPlatform.h"
#include "PPPlatformTrigger.h"

APPMovingPlatform::APPMovingPlatform()
{
    PrimaryActorTick.bCanEverTick = true;

    SetMobility(EComponentMobility::Movable);
    
    Speed = 0.f;
    TargetPoint = FVector::ZeroVector;
    UnitMovementDirection = FVector::ZeroVector;
    StartLocation = FVector::ZeroVector;
    ActiveTriggers = 0;
}

void APPMovingPlatform::BeginPlay()
{
    Super::BeginPlay();
    if(HasAuthority())
    {
        SetReplicates(true);
        SetReplicateMovement(true);
    }
    TargetLocation = GetTransform().TransformPosition(TargetPoint);
    StartLocation = GetActorLocation();
}


void APPMovingPlatform::Tick(float DeltaSeconds)
{
    Super::Tick(DeltaSeconds);
    if(HasAuthority() && ActiveTriggers)
    {
        if(FMath::IsNearlyZero((TargetLocation - GetActorLocation()).Size(),10.f))
            UnitMovementDirection = (StartLocation - TargetLocation).GetSafeNormal();
        else if (FMath::IsNearlyZero((StartLocation - GetActorLocation()).Size(), 10.f))
            UnitMovementDirection = (TargetLocation - StartLocation).GetSafeNormal();
        
        SetActorLocation(GetActorLocation() + UnitMovementDirection * Speed * DeltaSeconds);
    }
}