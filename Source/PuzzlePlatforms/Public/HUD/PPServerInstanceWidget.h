
#pragma once

#include "CoreMinimal.h"
#include "PPMenuInterface.h"
#include "Blueprint/UserWidget.h"
#include "Components/TextBlock.h"
#include "PPServerInstanceWidget.generated.h"

class UButton;
class IPPMenuInterface;
struct FServerData;

UCLASS()
class PUZZLEPLATFORMS_API UPPServerInstanceWidget : public UUserWidget
{
	GENERATED_BODY()

public:

    virtual void NativeConstruct() override;
    virtual void NativeOnInitialized() override;
    
    FORCEINLINE void SetServerData(FServerData* Data)
    {
        UE_LOG(LogTemp, Warning, TEXT("SetServerData"));
        ServerData = Data;
    }
    
protected:    
    UPROPERTY(meta = (BindWidget))
    UTextBlock* ServerName;

    UPROPERTY(meta = (BindWidget))
    UButton* ServerButton;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* CurrentPlayers;

    UPROPERTY(meta = (BindWidget))
    UTextBlock* MaxPlayers;

    FServerData* ServerData;

    UFUNCTION()
    void OnServerButtonClicked();

};
