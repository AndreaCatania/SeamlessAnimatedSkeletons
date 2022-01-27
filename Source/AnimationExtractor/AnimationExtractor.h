#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

DECLARE_LOG_CATEGORY_EXTERN(AnimationExtractor, Log, All);

class FToolBarBuilder;
class FMenuBuilder;
struct FAssetData;
class USkeleton;
class USeamlessAnimationData;
class FAssetRegistryModule;

class FAnimationExtractorModule : public IModuleInterface
{
public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	/** This function will be bound to Command. */
	void RetargetMissingBtnClick();

private:
	void StartRetarget();
	void Retarget(const FString& FolderPath, USeamlessAnimationData* SeamlessAnimation, FAssetRegistryModule& AssetRegistryModule);
	void UpdateAnimationData(USeamlessAnimationData* SeamlessAnimation, FAssetRegistryModule& AssetRegistryModule);

	void RegisterMenus();

	void FetchAssets(TArray<FAssetData>& OutAssetData, FAssetRegistryModule& AssetRegistryModule);
	bool IsUsingSkeleton(const FAssetData& Asset, const USkeleton* Skeleton);
	FString GetAnimResourceName(const FAssetData& Asset);

private:
	TSharedPtr<class FUICommandList> PluginCommands;
};
