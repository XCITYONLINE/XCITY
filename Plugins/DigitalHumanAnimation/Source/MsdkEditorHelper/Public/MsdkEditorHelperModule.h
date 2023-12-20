#pragma once

#include "Modules/ModuleManager.h"

class FMsdkEditorHelperModule : public IModuleInterface
{

public:
	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
