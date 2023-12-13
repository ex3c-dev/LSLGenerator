-- premake5.lua
workspace "LSL Generator"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "LSLGenerator-App"

   -- Workspace-wide build options for MSVC
   filter "system:windows"
      buildoptions { "/EHsc", "/Zc:preprocessor", "/Zc:__cplusplus" }

OutputDir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"

group "LSLCore"
	include "LSLCore/Build-LSLCore.lua"
group ""

include "LSLGenerator-App/Build-LSLGenerator-App.lua"