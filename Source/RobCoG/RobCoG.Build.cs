// Copyright 2017-2019, Institute for Artificial Intelligence - University of Bremen
// Author: Andrei Haidu (http://haidu.eu)

using UnrealBuildTool;

public class RobCoG : ModuleRules
{
	public RobCoG(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
// getting the urosbridge editor module for the callback registration of RWC
   	 // getting UROSControl for the ROS service registration
  		  PublicDependencyModuleNames.AddRange(new string[] {"UROSBridge","UROSControl"});

		//PrivateDependencyModuleNames.AddRange(new string[] {"HeadMountedDisplay", "SteamVR" });

		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
