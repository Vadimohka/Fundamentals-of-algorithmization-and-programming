
#pragma once

#include "CoreMinimal.h"
#include "VaroniaStruct.generated.h"

USTRUCT(BlueprintType)
struct STASSSSIIIIKKKK_API FVaroniaStruct
{
public:
	GENERATED_BODY()
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FVector Site;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> Vertices;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FVector> Region;




	FVaroniaStruct();
	~FVaroniaStruct();
};
