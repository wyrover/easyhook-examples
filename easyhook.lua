includeexternal ("premake-vs-include.lua")

workspace "easyhook"
    language "C++"
    location "build/%{_ACTION}/%{wks.name}"    
    if _ACTION == "vs2015" then
        toolset "v140_xp"
    end


    function create_easyhook_dll_project(name)       
        project(name)               
        kind "SharedLib"             
        
        files
        {
            "easyhook-examples/%{prj.name}/*.def",   
            "easyhook-examples/%{prj.name}/**.h",
            "easyhook-examples/%{prj.name}/**.cpp", 
            "easyhook-examples/%{prj.name}/**.c"
            
        }   
        includedirs
        {                   
            "EasyHook/Public",
            "H:/rover/Program Files (x86)/Microsoft DirectX SDK (June 2010)/Include"
        }
        libdirs
        {
            "lib"
        }       
        filter { "platforms:Win32" }            
            links
            { 
                "EasyHook32.lib"                    
            }            
        filter "platforms:x64"           
            links
            { 
                "EasyHook64.lib"                          
            }                    
    end


    project "easyhook"               
        kind "SharedLib"         
        buildoptions { "/Gz" } 
        includedirs
        {      
            
            "EasyHook/Public",
            "EasyHook/EasyHookDll",
            "EasyHook/DriverShared",

           
        }
        libdirs
        {
            "EasyHook/easyhook-examples"
        }      
        filter { "platforms:Win32" }
            defines
            {
                "WIN32",
                "_WINDOWS",
                "_USRDLL",
                "EASYHOOK_EXPORTS"
            }
            files
            {
                "EasyHook/DriverShared/**.h",
                "EasyHook/DriverShared/**.c",
                "EasyHook/DriverShared/ASM/HookSpecific_x86.asm",           
                "EasyHook/EasyHookDll/**.h",
                "EasyHook/EasyHookDll/**.cpp", 
                "EasyHook/EasyHookDll/**.c"
                
            }               
        filter { "platforms:x64" }
            files
            {
                "EasyHook/DriverShared/**.h",
                "EasyHook/DriverShared/**.c",
                "EasyHook/DriverShared/ASM/HookSpecific_x64.asm",           
                "EasyHook/EasyHookDll/**.h",
                "EasyHook/EasyHookDll/**.cpp", 
                "EasyHook/EasyHookDll/**.c"
                
            }   
            
        filter { "files:**.asm", "platforms:Win32" }            
            buildmessage "Compiling %{file.relpath}"
            buildcommands 
            {
                "ml -c \"-Fl%{cfg.objdir}/%{file.basename}.lst\" \"-Fo%{cfg.objdir}/%{file.basename}.obj\" \"%{file.relpath}\""
            }
            buildoutputs
            {
                "%{cfg.objdir}/%{file.basename}.obj"
            }

        filter { "files:**.asm", "platforms:x64" }            
            buildmessage "Compiling %{file.relpath}"
            buildcommands 
            {
                "ml64 -c \"-Fl%{cfg.objdir}/%{file.basename}.lst\" \"-Fo%{cfg.objdir}/%{file.basename}.obj\" \"%{file.relpath}\""
            }
            buildoutputs
            {
                "%{cfg.objdir}/%{file.basename}.obj"
            }               

        --pchsource(dir .. "/%{prj.name}/StdAfx.cpp")
        pchheader("stdafx.h")
      
    
    group "easyhook-examples"                          
        
        create_console_project("Injector2", "easyhook-examples")
            defines { "STATIC_GETOPT" }
            links
            {
                
                "Shlwapi.lib",
                "Dbghelp.lib"
            }
   
        create_console_project("DllInjector", "easyhook-examples")
        create_console_project("Target", "easyhook-examples")
        create_console_project("Injector", "easyhook-examples")
            includedirs
            {                   
                "EasyHook/Public"
            }
            libdirs
            {
                "lib"
            }
            filter { "platforms:Win32" }            
                links
                { 
                    "EasyHook32.lib"                    
                }            
            filter "platforms:x64"           
                links
                { 
                    "EasyHook64.lib"                          
                }  


        project "BeepHook"            
            kind "SharedLib"             
            
            files
            {
                "easyhook-examples/%{prj.name}/*.def",   
                "easyhook-examples/%{prj.name}/**.h",
                "easyhook-examples/%{prj.name}/**.cpp", 
                "easyhook-examples/%{prj.name}/**.c"
                
            }   
            includedirs
            {                   
                "EasyHook/Public"
            }
            libdirs
            {
                "lib"
            }       
            filter { "platforms:Win32" }            
                links
                { 
                    "EasyHook32.lib"                    
                }            
            filter "platforms:x64"           
                links
                { 
                    "EasyHook64.lib"                          
                }            

    group "easyhook_dll_template"    
        create_easyhook_dll_project("easyhook_dll_template")
        create_easyhook_dll_project("messagebox_hook_dll")
        create_wtl_project("wtl_dialog_target", "easyhook-examples")

        