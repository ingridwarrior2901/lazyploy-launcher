// Copyright 1998-2015 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "AllarBuilderClientApp.h"

/** Type definition for shared pointers to instances of FAllarBuilderClient. */
typedef TSharedPtr<class FAllarBuilderClient> FAllarBuilderClientPtr;

/** Type definition for shared references to instances of FAllarBuilderClient. */
typedef TSharedRef<class FAllarBuilderClient> FAllarBuilderClientRef;

/**
* Main implementation of the Allar Builder client application
*/
class FAllarBuilderClient : public TSharedFromThis<FAllarBuilderClient>
{

public:
	/**
	* Constructor:
	*
	*/
	FAllarBuilderClient();

	/** Destructor. */
	virtual ~FAllarBuilderClient();

	/**
	* Handle user closing the main window
	* @param Window Main window
	*/
	void RequestCloseWindow(const TSharedRef<SWindow>& Window);

	FString GetEditorBinaryPath() const;
	FString GetEngineBatchFilesPath() const;

	// Project options
	FString GetProjectPath() const;
	void SetProjectPath(const FString NewProjectPath);
	FString GetProjectDir() const;
	FString GetProjectName() const;

	void SetBuildUploadEndpoint(FString NewEndpoint);

	bool IsProjectSelected() const;
	FReply LaunchEditor();

public:

	// Project settings
	FString ProjectPath;

	// Current build info for Build Manager
	int32 BuildId;
	FString& BuildUploadEndpoint;
};