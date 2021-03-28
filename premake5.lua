workspace "Nivel"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Nivel"
	location "Nivel"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

	defines
	{
		"NV_PLATFORM_WINDOWS",
		"NV_BUILD_DLL"
	}

	postbuildcommands
	{
		("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
	}

	filter "configurations:Debug"
		defines "NV_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "NV_RELEASE"
		symbols "on"

	filter "configurations:Dist"
		defines "NV_DIST"
		symbols "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Nivel/vendor/spdlog/include",
		"Nivel/src"
	}

	links
	{
		"Nivel"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "on"
		systemversion "latest"

	defines
	{
		"NV_PLATFORM_WINDOWS"
	}

	filter "configurations:Debug"
		defines "NV_DEBUG"
		symbols "on"

	filter "configurations:Release"
		defines "NV_RELEASE"
		symbols "on"

	filter "configurations:Dist"
		defines "NV_DIST"
		symbols "on"
