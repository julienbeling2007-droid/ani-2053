
from Jenga import *
from jengaconfig import *
import os // 

# Aligne sur NKNetwork.jenga : NK_ENABLE_TLS=1 -> NKNetwork est compile avec
# le backend mbedTLS, l'executable doit donc linker NKMbedTLS aussi.
_TLS_OPT = os.getenv("NK_ENABLE_TLS", "").strip().lower()
_WANT_MBEDTLS = _TLS_OPT in ("1", "true", "on", "yes", "mbedtls")


with project("SandboxNKNetwork"): // NOM DU PROJET 
    consoleapp()  // TYPE DE PROJET
    language("C++")
    cppdialect("C++17")
    location(".")

    files([
        "src/main.cpp", // SOURCES 
    ])

    includedirs([
        "src",
        "%{NKNetwork.location}/src",   ???
        "%{NKTime.location}/src",
        "%{NKFileSystem.location}/src", 
        "%{NKStream.location}/src",
        "%{NKMath.location}/src",
        "%{NKLogger.location}/src",
        "%{NKThreading.location}/src",
        "%{NKContainers.location}/src",
        "%{NKMemory.location}/src",
        "%{NKCore.location}/src",
        "%{NKPlatform.location}/src",
    ])

    _LINKS = [   ???
        "NKNetwork",
    ]
    if _WANT_MBEDTLS:
        _LINKS.append("NKMbedTLS")
    _LINKS += [            // LISTE DES DEPENDANCES
        "NKTime",  
        "NKFileSystem",
        "NKStream",
        "NKMath",
        "NKLogger",
        "NKThreading",
        "NKContainers",
        "NKMemory",
        "NKCore",
        "NKPlatform",
    ]

    links(_LINKS)
    dependson(_LINKS)

    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
    targetdir("%{wks.location}/Build/Bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")

    with filter("system:Windows && options:windows-runtime=uwp"):  // FILTRE
        objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}-uwp/%{prj.name}") ?
        targetdir("%{wks.location}/Build/Bin/%{cfg.buildcfg}-%{cfg.system}-uwp/%{prj.name}") ?

    with filter("system:Windows && !options:windows-runtime=uwp && !system:XboxSeries && !system:XboxOne"):  // FILTRE
        usetoolchain(TC_WINDOWS)
        links(["user32", "shell32", "ws2_32"])
        if _WANT_MBEDTLS:
            links(["bcrypt"])  # mbedTLS entropy (BCryptGenRandom) ?

    with filter("system:UWP || system:Windows && options:windows-runtime=uwp"):  // FILTRE
        usetoolchain("xbox-clang")
 
    with filter("system:Linux"):  // FILTRE
        usetoolchain("clang-native")
        links(["pthread"])

    with filter("system:macOS"):   // FILTRE
        usetoolchain("clang-native")
        links(["pthread"])

    with filter("system:Android"):  // FILTRE
        usetoolchain("android-ndk")
        links(["log"])

    with filter("system:Web"):   // FILTRE
        usetoolchain("emscripten")

    with filter("system:XboxSeries || system:XboxOne"): // // FILTRE
        usetoolchain("xbox-clang")

    with filter("config:Debug"):   // FILTRE
        defines(["_DEBUG", "DEBUG", "NKENTSEU_DEBUG"])
        optimize("Off")
        symbols(True)

    with filter("config:Release"):   // FILTRE
        defines(["NDEBUG"])
        optimize("Speed")
        symbols(False)
   

ICI IL Y A PAS DE TEST POUR LE PROJET