#include "MetahumanSDKMappingsAsset.h"
#include "Animation/Skeleton.h"
#include "ReferenceSkeleton.h"

#if WITH_EDITOR
void UMetahumanSDKMappingsAsset::FillCurveNames()
{
    USkeleton* Skeleton = LoadObject<USkeleton>(nullptr, TEXT("/MetahumanSDK/Models/FaceExample_Skeleton"), nullptr);
    if (IsValid(Skeleton))
    {
        TArray<FName> CurveNames;
        Skeleton->GetCurveMetaDataNames(CurveNames);

        for (const FName& CurveName : CurveNames)
        {
            BlendShapeMappings.Add(CurveName.ToString(), TEXT(""));
        }
    }
}
#endif
