## fichiers .jenga et .cpp de Applications/MonEssai/main.cpp & Applications/MonEssai/MonEssai.jenga 

###  Applications/MonEssai/main.cpp
```
int main(){

    return 0;
}
```
### Applications/MonEssai/MonEssai.jenga 

```
from Jenga import*
from jengaconfig import *

with project("MonEssai") :
    consoleapp()
    language("C++")
    cppdialect("C++17")
    location(".")

    files(["**.cpp"])
    nkentseudependson(["NKCanvas","NKFont", "NKGlad"])

    objdir("%{wks.location}/Build/Obj/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")
    targetdir("%{wks.location}/Build/Bin/%{cfg.buildcfg}-%{cfg.system}/%{prj.name}")

    with filter("system:Windows"):
        usetoolchain(TC_WINDOWS)
        links(["user32", "gdi32", "opengl32","dwmapi", "shell32"])
    with filter("config:Debug"):
        defines(["_DEBUG"]);optimize("Off"); symbols(True)
    with filter("config:Release"):
        defines(["NDEBUG"]);optimize("Speed");symbols(False)
```

 rendu du jenga info 

 ```
 ╔══════════════════════════════════════════════════════════════════╗
║                                                                  ║
║                ██╗███████╗███╗   ██╗ ██████╗  █████╗             ║
║                ██║██╔════╝████╗  ██║██╔════╝ ██╔══██╗            ║
║                ██║█████╗  ██╔██╗ ██║██║  ███╗███████║            ║
║           ██   ██║██╔══╝  ██║╚██╗██║██║   ██║██╔══██║            ║
║           ╚█████╔╝███████╗██║ ╚████║╚██████╔╝██║  ██║            ║
║            ╚════╝ ╚══════╝╚═╝  ╚═══╝ ╚═════╝ ╚═╝  ╚═╝            ║
║                                                                  ║
║             Multi-platform C/C++ Build System v2.8.0             ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝

[NKCode] ATTENTION : aucun wheel Jenga trouve (dist/*.whl) -> le paquet n'aura PAS de Jenga embarque, et les boutons Construire/Executer seront inoperants. Produisez-le avec ./cri.sh dans le depot Jenga.
========================== Jenga Workspace: Nkentseu ===========================

Location: E:\Nkentseu
Entry file: E:\Nkentseu\Nkentseu.jenga
Configurations: Debug, Release
Platforms: Windows
Target OSes: Windows, Linux, macOS, Android, iOS, Web, HarmonyOS, XboxSeries, XboxOne
Target Architectures: x86_64, arm64, wasm32
Start project: Sandbox


Projects
------------------------------------------------------------
Name                         Kind          Language   Test   External
=====================================================================
__Unitest__                  StaticLib     C++        No     No
NKPlatform_Tests             TestSuite     C++        Yes    Yes
NKPlatform                   StaticLib     C++        No     Yes
NKCore                       StaticLib     C++        No     Yes
NKCore_Tests                 TestSuite     C++        Yes    Yes
NKLogger                     StaticLib     C++        No     Yes
NKLogger_Tests               TestSuite     C++        Yes    Yes
NKMath_Tests                 TestSuite     C++        Yes    Yes
NKMath                       StaticLib     C++        No     Yes
NKMemory                     StaticLib     C++        No     Yes
NKMemory_Tests               TestSuite     C++        Yes    Yes
NKContainers_Tests           TestSuite     C++        Yes    Yes
NKContainers                 StaticLib     C++        No     Yes
NKImage_Tests                TestSuite     C++        Yes    Yes
NKImage                      StaticLib     C++        No     Yes
NKFont                       StaticLib     C++        No     Yes
NKFont_Tests                 TestSuite     C++        Yes    Yes
NKAudio                      StaticLib     C++        No     Yes
NKAudio_Tests                TestSuite     C++        Yes    Yes
NKMedia                      StaticLib     C++        No     Yes
NKTime_Tests                 TestSuite     C++        Yes    Yes
NKTime                       StaticLib     C++        No     Yes
NKStream_Tests               TestSuite     C++        Yes    Yes
NKStream                     StaticLib     C++        No     Yes
NKThreading_Tests            TestSuite     C++        Yes    Yes
NKThreading                  StaticLib     C++        No     Yes
NKFileSystem_Tests           TestSuite     C++        Yes    Yes
NKFileSystem                 StaticLib     C++        No     Yes
NKReflection_Tests           TestSuite     C++        Yes    Yes
NKReflection                 StaticLib     C++        No     Yes
NKNetwork                    StaticLib     C++        No     Yes
NKNetwork_Tests              TestSuite     C++        Yes    Yes
NKSerialization              StaticLib     C++        No     Yes
NKSerialization_Tests        TestSuite     C++        Yes    Yes
NKGlad                       StaticLib     C          No     Yes
NKGLSlang                    StaticLib     C++        No     Yes
NKSPIRVCross                 StaticLib     C++        No     Yes
NKMbedTLS                    StaticLib     C          No     Yes
pybind11                     StaticLib     C++        No     Yes
NKEvent                      StaticLib     C++        No     Yes
NKEvent_Tests                TestSuite     C++        Yes    Yes
NKWindow                     StaticLib     C++        No     Yes
NKWindow_Tests               TestSuite     C++        Yes    Yes
NKSL                         StaticLib     C++        No     Yes
NKCanvas                     StaticLib     C++        No     Yes
NKCanvas_Tests               TestSuite     C++        Yes    Yes
NKRHI                        StaticLib     C++        No     Yes
NKRHI_Tests                  TestSuite     C++        Yes    Yes
NKUI_Tests                   TestSuite     C++        Yes    Yes
NKUI                         StaticLib     C++        No     Yes
NKGui                        StaticLib     C++        No     Yes
NKEditorKit                  StaticLib     C++        No     Yes
Unkeny                       StaticLib     C++        No     Yes
NkPdfProbe                   ConsoleApp    C++        No     Yes
NkPdfRenderProbe             ConsoleApp    C++        No     Yes
NkPdfRasterTest              ConsoleApp    C++        No     Yes
NKCode                       WindowedApp   C++        No     Yes
NkFileWorkerTest             ConsoleApp    C++        No     Yes
NK3DModeler                  WindowedApp   C++        No     Yes
NKImGuiIntegration           StaticLib     C++        No     Yes
NKUIIntegration              StaticLib     C++        No     Yes
NKGuiIntegration             StaticLib     C++        No     Yes
NKCamera                     StaticLib     C++        No     Yes
NKCamera_Tests               TestSuite     C++        Yes    Yes
NKCollision_Tests            TestSuite     C++        Yes    Yes
NKCollision                  StaticLib     C++        No     Yes
NKPhysics_Tests              TestSuite     C++        Yes    Yes
NKPhysics                    StaticLib     C++        No     Yes
NKAnimPhysics                StaticLib     C++        No     Yes
NKAnimation                  StaticLib     C++        No     Yes
NKNavigation                 StaticLib     C++        No     Yes
NKNavigation_Tests           TestSuite     C++        Yes    Yes
NKXR_Tests                   TestSuite     C++        Yes    Yes
NKXR                         StaticLib     C++        No     Yes
NkCanvasDemo                 WindowedApp   C++        No     Yes
RendererRHI                  WindowedApp   C++        No     Yes
NkRHIInterpTest              WindowedApp   C++        No     Yes
NkRHIDemoFull                WindowedApp   C++        No     Yes
cr2d                         WindowedApp   C++        No     Yes
gltftest                     WindowedApp   C++        No     Yes
r2d01                        WindowedApp   C++        No     Yes
Gamepad_Tests                TestSuite     C++        Yes    Yes
NkCanvasDemo_Tests           TestSuite     C++        Yes    Yes
gltftest_Tests               TestSuite     C++        Yes    Yes
renderdemo_Tests             TestSuite     C++        Yes    Yes
NKRHIDemo                    WindowedApp   C++        No     Yes
RendererRHI_Tests            TestSuite     C++        Yes    Yes
NkRHIDemoFullImage_Tests     TestSuite     C++        Yes    Yes
NkRHIDemoFullImage           WindowedApp   C++        No     Yes
NewGeneration                WindowedApp   C++        No     Yes
NKRHIDemo_Tests              TestSuite     C++        Yes    Yes
r2d01_Tests                  TestSuite     C++        Yes    Yes
NkSWRasterPrimitives_Tests   TestSuite     C++        Yes    Yes
NkFDV2                       WindowedApp   C++        No     Yes
renderdemo                   WindowedApp   C++        No     Yes
NewGeneration_Tests          TestSuite     C++        Yes    Yes
firsttriangle                WindowedApp   C++        No     Yes
NkSpriteDemo                 WindowedApp   C++        No     Yes
NkFontDemo                   WindowedApp   C++        No     Yes
firsttriangle_Tests          TestSuite     C++        Yes    Yes
Gamepad                      WindowedApp   C++        No     Yes
NkRHIInterpTest_Tests        TestSuite     C++        Yes    Yes
NkRHIDemoFull_Tests          TestSuite     C++        Yes    Yes
FontLoad                     WindowedApp   C++        No     Yes
NkSpriteDemo_Tests           TestSuite     C++        Yes    Yes
NkDrawableDemo               WindowedApp   C++        No     Yes
NkSWRasterPrimitives         WindowedApp   C++        No     Yes
NkFDV2_Tests                 TestSuite     C++        Yes    Yes
NkDrawableDemo_Tests         TestSuite     C++        Yes    Yes
NkFontDemo_Tests             TestSuite     C++        Yes    Yes
cr2d_Tests                   TestSuite     C++        Yes    Yes
ConquerorProto               WindowedApp   C++        No     Yes
NkAudioDemo                  ConsoleApp    C++        No     Yes
NkCameraDemos                WindowedApp   C++        No     Yes
SandboxNKFileSystem          ConsoleApp    C++        No     Yes
SandboxNKLogger              ConsoleApp    C++        No     Yes
SandboxNKReflection          ConsoleApp    C++        No     Yes
SandboxNKNetwork             ConsoleApp    C++        No     Yes
NKRenderer                   StaticLib     C++        No     Yes
NKRenderer_Tests             TestSuite     C++        Yes    Yes
NKTensor_Tests               TestSuite     C++        Yes    Yes
NKTensor                     StaticLib     C++        No     Yes
NKAutograd_Tests             TestSuite     C++        Yes    Yes
NKAutograd                   StaticLib     C++        No     Yes
NKNN_Tests                   TestSuite     C++        Yes    Yes
NKNN                         StaticLib     C++        No     Yes
NKOptim_Tests                TestSuite     C++        Yes    Yes
NKOptim                      StaticLib     C++        No     Yes
NKData                       StaticLib     C++        No     Yes
NKData_Tests                 TestSuite     C++        Yes    Yes
NKTrain                      StaticLib     C++        No     Yes
NKTrain_Tests                TestSuite     C++        Yes    Yes
NKInfer                      StaticLib     C++        No     Yes
NKInfer_Tests                TestSuite     C++        Yes    Yes
NKRL_Tests                   TestSuite     C++        Yes    Yes
NKRL                         StaticLib     C++        No     Yes
NKAgent_Tests                TestSuite     C++        Yes    Yes
NKAgent                      StaticLib     C++        No     Yes
NKEvolve_Tests               TestSuite     C++        Yes    Yes
NKEvolve                     StaticLib     C++        No     Yes
NKCivilization_Tests         TestSuite     C++        Yes    Yes
NKCivilization               StaticLib     C++        No     Yes
NKEmbodied                   StaticLib     C++        No     Yes
NKEmbodied_Tests             TestSuite     C++        Yes    Yes
NKGen                        StaticLib     C++        No     Yes
NKGen_Tests                  TestSuite     C++        Yes    Yes
NKGpt                        StaticLib     C++        No     Yes
NKSpeech                     StaticLib     C++        No     Yes
NKTensorDemo                 ConsoleApp    C++        No     Yes
NkSLComputeCheck             ConsoleApp    C++        No     Yes
NkGpuProbe                   ConsoleApp    C++        No     Yes
NkComputeNkSL                ConsoleApp    C++        No     Yes
NkTensorGpuTest              ConsoleApp    C++        No     Yes
NKGpuBenchTest               ConsoleApp    C++        No     Yes
NKConvBenchTest              ConsoleApp    C++        No     Yes
NKConvResidentBench          ConsoleApp    C++        No     Yes
NKMlpResidentBench           ConsoleApp    C++        No     Yes
NKMnistGpuTrain              ConsoleApp    C++        No     Yes
NKRebasinTest                ConsoleApp    C++        No     Yes
NKMnistCnnGpuTrain           ConsoleApp    C++        No     Yes
NKTransformerTest            ConsoleApp    C++        No     Yes
NKGptTrain                   ConsoleApp    C++        No     Yes
NKIlyana                     ConsoleApp    C++        No     Yes
NKAutogradTest               ConsoleApp    C++        No     Yes
NKNNTest                     ConsoleApp    C++        No     Yes
NKConvTest                   ConsoleApp    C++        No     Yes
NKDataTest                   ConsoleApp    C++        No     Yes
NKBpeTest                    ConsoleApp    C++        No     Yes
NKLlamaBlockTest             ConsoleApp    C++        No     Yes
NKRebasinTransformer         ConsoleApp    C++        No     Yes
NKTrainTest                  ConsoleApp    C++        No     Yes
NKFp16Test                   ConsoleApp    C++        No     Yes
NKRnnCtcTest                 ConsoleApp    C++        No     Yes
NKASRTest                    ConsoleApp    C++        No     Yes
NKImageCodecTest             ConsoleApp    C++        No     Yes
NkEditableMeshDemo           ConsoleApp    C++        No     Yes
NkLocomotionDemo             ConsoleApp    C++        No     Yes
NkAssetIODemo                ConsoleApp    C++        No     Yes
NkFBXParityDemo              ConsoleApp    C++        No     Yes
NkSVGImportDemo              ConsoleApp    C++        No     Yes
NKMeshAITest                 ConsoleApp    C++        No     Yes
NKEditMeshHarness            ConsoleApp    C++        No     Yes
NkAnimPhysTest               ConsoleApp    C++        No     Yes
NkMicRecord                  ConsoleApp    C++        No     Yes
NKSpeechTest                 ConsoleApp    C++        No     Yes
NKTTSTrain                   ConsoleApp    C++        No     Yes
NkVoiceLoopDemo              ConsoleApp    C++        No     Yes
NKSpeechFeatureDemo          ConsoleApp    C++        No     Yes
NKMediaTest                  ConsoleApp    C++        No     Yes
NkVideoReadTest              ConsoleApp    C++        No     Yes
NkAudioPlayer                WindowedApp   C++        No     Yes
NkVideoPlayer                WindowedApp   C++        No     Yes
NKOpusRef                    ConsoleApp    C++        No     Yes
NKVideoTest                  ConsoleApp    C++        No     Yes
NKInferTest                  ConsoleApp    C++        No     Yes
NKGGUFInspectTest            ConsoleApp    C++        No     Yes
NKLLMInferTest               ConsoleApp    C++        No     Yes
NKQwenTokenizerTest          ConsoleApp    C++        No     Yes
NKQwen2BackwardTest          ConsoleApp    C++        No     Yes
NKQwen2SftTest               ConsoleApp    C++        No     Yes
NKQ4MatmulTest               ConsoleApp    C++        No     Yes
NKQwen2GpuTest               ConsoleApp    C++        No     Yes
NKQwen2Chat                  ConsoleApp    C++        No     Yes
NKQwen2SftGpuTest            ConsoleApp    C++        No     Yes
NKQwen2Train                 ConsoleApp    C++        No     Yes
NKQwen2Ask                   ConsoleApp    C++        No     Yes
NKRLTest                     ConsoleApp    C++        No     Yes
NKAgentTest                  ConsoleApp    C++        No     Yes
NKAgentLLMTest               ConsoleApp    C++        No     Yes
NkAgentEcsDemo               ConsoleApp    C++        No     Yes
NKEmbodiedTest               ConsoleApp    C++        No     Yes
NKEvolveTest                 ConsoleApp    C++        No     Yes
NKEvolveNNTest               ConsoleApp    C++        No     Yes
NKCivilizationTest           ConsoleApp    C++        No     Yes
NKCivilizationSocialTest     ConsoleApp    C++        No     Yes
NKCivilizationScaleTest      ConsoleApp    C++        No     Yes
NKGenTest                    ConsoleApp    C++        No     Yes
NKVAETest                    ConsoleApp    C++        No     Yes
NKMnistVAETest               ConsoleApp    C++        No     Yes
NKMnistConvVAETest           ConsoleApp    C++        No     Yes
NKConvVAETest                ConsoleApp    C++        No     Yes
NKDiffusionTest              ConsoleApp    C++        No     Yes
NKVoxelGenTest               ConsoleApp    C++        No     Yes
NKObjectGenTest              ConsoleApp    C++        No     Yes
NKGen3DTest                  ConsoleApp    C++        No     Yes
NKGenMeshTest                ConsoleApp    C++        No     Yes
NKSmoothMeshTest             ConsoleApp    C++        No     Yes
NKMatTypeResetTest           ConsoleApp    C++        No     Yes
NKEditTargetTest             ConsoleApp    C++        No     Yes
NKMeshRenderTest             ConsoleApp    C++        No     Yes
Model                        WindowedApp   C++        No     Yes
NkSLCheck                    ConsoleApp    C++        No     Yes
NKPA                         WindowedApp   C++        No     Yes
NKECS_Tests                  TestSuite     C++        Yes    Yes
NKECS                        StaticLib     C++        No     Yes
Noge                         StaticLib     C++        No     Yes
Noge_Tests                   TestSuite     C++        Yes    Yes
Nogee                        WindowedApp   C++        No     Yes
NKEditorKitDemo              WindowedApp   C++        No     Yes
NKEditorKitTest              ConsoleApp    C++        No     Yes
NKUIDesign                   WindowedApp   C++        No     Yes
ConquerorLab                 WindowedApp   C++        No     Yes
NkRef                        WindowedApp   C++        No     Yes
NkAnimaEditor                WindowedApp   C++        No     Yes
ImGuiRef                     WindowedApp   C++        No     Yes
NKGuiDrawTest                ConsoleApp    C++        No     Yes
NKGuiDemo                    WindowedApp   C++        No     Yes
NKViewportDemo               WindowedApp   C++        No     Yes
PV3DE                        WindowedApp   C++        No     Yes
Pong                         WindowedApp   C++        No     Yes
Nkoung                       WindowedApp   C++        No     Yes
Mou                          WindowedApp   C++        No     Yes
NkImeTest                    WindowedApp   C++        No     Yes
NkImageDemo                  WindowedApp   C++        No     Yes
RihenDefi                    WindowedApp   C++        No     Yes
NkAudioECSDemo               ConsoleApp    C++        No     Yes
NkNetWorldDemo               ConsoleApp    C++        No     Yes
NkNavDemo                    ConsoleApp    C++        No     Yes
NkNavCoreDemo                ConsoleApp    C++        No     Yes
NkHotReloadDemo              ConsoleApp    C++        No     Yes
NkUIHudDemo                  ConsoleApp    C++        No     Yes
Tuto03Scene                  WindowedApp   C++        No     Yes
Tuto02Renderer               WindowedApp   C++        No     Yes
Tuto04Camera                 WindowedApp   C++        No     Yes
Tuto01Fenetre                WindowedApp   C++        No     Yes
Tuto05Meshes                 WindowedApp   C++        No     Yes
NKXRDemo                     WindowedApp   C++        No     Yes
NKARDemo                     WindowedApp   C++        No     Yes
GemCrush                     WindowedApp   C++        No     Yes
NkDames                      WindowedApp   C++        No     Yes
NkEchecs                     WindowedApp   C++        No     Yes
NkLudo                       WindowedApp   C++        No     Yes
UnkenyEditor                 WindowedApp   C++        No     Yes
MonEssai                     ConsoleApp    C++        No     Yes


Available Toolchains
------------------------------------------------------------
Name                Family   Target OS   Arch     Env  
=======================================================
host-clang          clang    Windows     x86_64   mingw
host-gcc            gcc      Windows     x86_64   mingw
clang-mingw         clang    Windows     x86_64   mingw
mingw               gcc      Windows     x86_64   mingw
clang-cross-linux   clang    Linux       x86_64   gnu

```

construction du projet :

``` 

╔══════════════════════════════════════════════════════════════════════════════════════════════╗
║  Project: MonEssai                                                        Kind: CONSOLE_APP  ║
╚══════════════════════════════════════════════════════════════════════════════════════════════╝

ℹ Found 1 source file(s)
✓ All files up to date
ℹ Linking...
✓ Built: Build\Bin\Debug-Windows\MonEssai\MonEssai.exe

┌──────────────────────────────────────────────────────────────────────────────────────────────┐
│  ✓ Build Successful                                                             Time: 0.33s  │
└──────────────────────────────────────────────────────────────────────────────────────────────┘

════════════════════════════════════════════════════════════════════════════════
                                BUILD COMPLETED                                 
════════════════════════════════════════════════════════════════════════════════
Projects Built:  17/17
Time:           1m29.8s
Status:         ✓ SUCCESS
════════════════════════════════════════════════════════════════════════════════
```

workspace:NKENTSEU.jenga

```
#!/usr/bin/env python3

# -*- coding: utf-8 -*-

r"""

=============================================================================

Nkentseu.jenga => Workspace principal du framework Nkentseu

=============================================================================



Framework C++ multi-plateforme de gestion de fenetres, d'evenements

et de rendu pixel. Namespace : nkentseu



Architecture et ordre de dependances :



  NKPlatform  => Detection OS/arch/compilateur/CPU         (C++20)

       ↓

  NKCore      => Types, macros, assertions, bits            (C++20)

       ↓            ↓

  NKMath      => Types géométriques (Vec2, Rect, …)        (C++17)

  NKLogger    => Journalisation asynchrone multi-sink       (C++17)

       ↓            ↓                   ↓

  NKTime      => Gestion du temps / chrono                  (C++17)

  NKStream    => Flux de données (fichier, binaire…)        (C++17)

  NKMemory    => Gestion mémoire + smart pointers           (C++17)

       ↓

  NKWindow    => Fenetrage, evenements, entrees             (C++17)

       ↓

  NKRenderer  => Rendu graphique (Software, OpenGL…)        (C++17)

       ↓

  Sandbox     => Application de demonstration (tous OS)     (C++17)



Chaque projet possède son propre fichier .jenga dans son répertoire.

Ce fichier workspace les réunit via include().



Plateformes supportees :

  Windows     => Backend Win32                   (clang-mingw)

  Linux XLib  => Backend X11/XLib (defaut)       (clang-native / WSL2)

  Linux XCB   => Backend X11/XCB                 (clang-native / WSL2)

  Linux Wayland => Backend Wayland + xdg-shell   (clang-native / WSL2)

  Linux NOOP  => Backend headless (CI/WSL)        (clang-native / WSL2)

  macOS       => Backend Cocoa                   (clang-native)

  Android     => NativeActivity+EGL              (android-ndk)

  iOS         => Backend UIKit

  Web         => Emscripten+Canvas               (emscripten)

  HarmonyOS   => ArkUI Native

  XboxSeries  => UWP GameCore                    (xbox-clang)

  XboxOne     => UWP GameCore                    (xbox-clang)



Usage :

  jenga build                                                   # Hote (XLib)

  jenga build --platform windows                                # Windows

  jenga build --platform linux                                  # Linux XLib (defaut)

  jenga build --platform linux --linux-backend xcb

  jenga build --platform linux --linux-backend wayland

  jenga build --platform linux --linux-backend headless         # Linux headless

  jenga build --platform macos                                  # macOS Cocoa

  jenga build --platform android                                # Android (NDK)

  jenga build --platform ios                                    # iOS (UIKit)

  jenga build --platform web                                    # Web (Emscripten)

  jenga build --platform windows --windows-runtime desktop      # Windows desktop (Win32)

  jenga build --platform windows --windows-runtime uwp          # UWP (Windows Runtime)

  jenga build --platform xboxseries                             # Xbox Series

  jenga build --platform xboxone                                # Xbox One

  jenga build --config Release                                  # Build Release



=============================================================================

PACKAGING (jenga package) -- creer des installers distribuables

=============================================================================



Une fois le build OK, on peut empaqueter le binaire dans 3 formats Windows :



  jenga package --platform windows --project Pong --type zip --config Release

                --output ./dist

        => Pong.zip : archive portable (decompresser + lancer .exe)



  jenga package --platform windows --project Pong --type exe --config Release

                --output ./dist

        => Pong_setup.exe : installer Inno Setup avec wizard complet

           (EULA + choix dossier + raccourcis bureau/menu)



  jenga package --platform windows --project Pong --type msi --config Release

                --output ./dist

        => Pong.msi : Windows Installer officiel (WiX 5), idem fonctions



Linux : --type deb (dpkg-deb), --type rpm/appimage/snap (stubs)

macOS : --type pkg (pkgbuild), --type dmg (create-dmg)

Web   : --type zip (favicon + html + wasm + assets)



-----------------------------------------------------------------------------

PREREQUIS A INSTALLER avant de packager (Windows)

-----------------------------------------------------------------------------



  ZIP : aucun (Python stdlib seulement)



  EXE (Inno Setup) :

    winget install JRSoftware.InnoSetup

    -> installe iscc dans %LOCALAPPDATA%\\Programs\\Inno Setup 6\

    -> jenga le detecte auto (pas besoin de toucher au PATH)



  MSI (WiX Toolset) :

    dotnet tool install --global wix --version 5.0.2

    -> ATTENTION : ne pas installer WiX 7+ qui demande l'OSMF EULA payante.

    -> jenga ajoute auto WiX a son PATH session



  Pillow (pour conversion icones PNG -> .ico/.icns/mipmap) :

    pip install Pillow>=10.0

    -> deja installe normalement (dep jenga via requirements.txt)



=============================================================================

ICONES D'APPLICATION (DSL Jenga, voir Core/IconConverter.py)

=============================================================================



  Dans un .jenga de projet (ex: Pong.jenga, hors filter) :



  appicon("Resources/MyApp/icon.png")

        # Source UNIQUE, dispatchee a TOUTES les plateformes :

        #   - Windows : convertit en .ico embedded via .res

        #   - macOS   : convertit en .icns dans bundle .app

        #   - Android : genere hierarchie res/mipmap-* (ldpi..xxxhdpi)

        #   - iOS     : copie + reference dans Info.plist

        #   - Web     : favicon.ico + favicon-{16,32,180,192,512}.png



  # Overrides par plateforme (gagnent sur appicon) :

  androidappicon("path.png")    # accepte PNG ou dossier res/mipmap-*/

  windowsicon   ("path.ico")    # accepte PNG ou .ico natif

  macosicon     ("path.icns")   # accepte PNG ou .icns natif

  iosappicon    ("path.png")    # ou dossier AppIcon.appiconset

  webfavicon    ("path.png")    # PNG converti automatiquement



  Note : Pong.exe affiche son icone correctement dans la taskbar/titre/

  Alt+Tab grace a un AppUserModelID stable defini dans NKWindow Win32

  (Rihen.Nkentseu.<NomApp>). Sans ca, Windows utilise un AUMID auto

  base sur le ProductCode MSI -> icone generique cassee.



=============================================================================

METADONNEES INSTALLER (MSI/EXE/DEB/PKG)

=============================================================================



  Dans un .jenga de projet (hors filter) :



  appversion           ("1.0.0")                  # affichee dans Programs & Features

  apppublisher         ("Rihen Universe")         # nom editeur

  licensefile          ("../../LICENSE")          # .txt/.md (auto-converti en RTF pour WiX), ou .rtf direct

  createdesktopshortcut(True)                     # toggle raccourci bureau



  # Bag d'options libres (extensible) pour les besoins avances :

  installeroption("autostart_on_login", True)

  installeroption("registry_entry",     r\"HKLM\\Software\\Pong")

  installeroption("autoupdate_url",     "https://updates.example.com")



  # Ressources runtime a embarquer dans le package :

  dependfiles(["../../Resources/MyApp"])          # dossier ou fichier

        # Preserve la hierarchie relative au workspace.

        # Auto-inclut aussi les SHARED_LIB declarees via dependson().



=============================================================================

CYCLE DE BUILD + PACKAGE TYPIQUE (Pong exemple)

=============================================================================



  # 1. Build optimise

  jenga build --target Pong --config Release



  # 2. Generer les 3 packages Windows

  jenga package --platform windows --project Pong --type zip --config Release

  jenga package --platform windows --project Pong --type exe --config Release

  jenga package --platform windows --project Pong --type msi --config Release



  # 3. (optionnel) Build + APK Android

  jenga build --target Pong --config Release --platform android

  jenga deploy --platform android --project Pong --config Release \

               --apk path/to/Pong-Release.apk --force-stop --run



  Distribution typique pour testeurs : envoyer Pong_setup.exe (Inno EXE)

  car wizard plus convivial que MSI. ZIP comme alternative sans install.



=============================================================================

IDE auto-config (jenga ide-setup)

=============================================================================



  jenga le fait automatiquement au premier `jenga build` :

    - VSCode/Cursor/Windsurf : .vscode/settings.json (associations .jenga

      = Python, extraPaths Jenga, diagnostics)

    - pyrightconfig.json universel (Neovim+pyright, Helix, Emacs+lsp-mode,

      Sublime+LSP, Zed)

  Merge non-destructif : preserve toutes vos prefs IDE existantes.

  Desactiver : JENGA_NO_IDE_CONFIG=1



  Reload editor apres premiere installation pour activer la coloration

  Python + autocomplete sur les .jenga.



  Notes Wayland :

    Prerequis : libwayland-dev, libxkbcommon-dev, wayland-protocols, libdecor-0-dev

    Generer xdg-shell-client-protocol.h :

      wayland-scanner client-header

        /usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml

        Kernel/Runtime/NKWindow/src/NKWindow/Platform/Wayland/xdg-shell-client-protocol.h

      wayland-scanner private-code

        /usr/share/wayland-protocols/stable/xdg-shell/xdg-shell.xml

        Kernel/Runtime/NKWindow/src/NKWindow/Platform/Wayland/xdg-shell-protocol.c



Auteur : Rihen

Date   : 2026

=============================================================================

"""



import os

import sys

import shutil

from Jenga import *

from jengaconfig import *



# Ensure workspace root is in sys.path so '' works in all .jenga files

_WORKSPACE_ROOT = os.path.dirname(os.path.abspath(__file__)) if "__file__" in dir() else os.getcwd()

if _WORKSPACE_ROOT not in sys.path:

    sys.path.insert(0, _WORKSPACE_ROOT)



# Config partagee (registre des modules : kind static/shared + dependances).

# Chargee UNE fois ici via useconfig() et propagee a TOUS les .jenga inclus

# (feature Jenga 2.0.5) -> fini le bloc config inline (~285 lignes).

useconfig("config/modules.jenga")

useconfig("config/toolchain.jenga")

useconfig("config/graphics.jenga")   # Vulkan SDK / glslang / SPIRV-Cross (partage)

useconfig("config/wayland.jenga")    # backend Wayland Linux (partage)



with workspace("Nkentseu", location="."):

    nkentseutoolchain()



    dutc(enable=True)

    dute(enable=True)



    configurations(["Debug", "Release"])



    # ===== Options Linux : choix du backend de fenetrage ========================

    newoption(

        trigger="linux-backend",

        value="BACKEND",

        allowed=[

            ["xlib",     "X11/XLib  (defaut, le plus compatible)"],

            ["xcb",      "X11/XCB   (plus leger, asynchrone)"],

            ["wayland",  "Wayland   (compositeurs modernes, sans X11)"],

            ["headless", "Pas de fenetre (CI, serveurs, WSL sans ecran)"],

        ],

        default="xlib",

        description="Backend de fenetrage Linux"

    )



    newoption(

        trigger="headless",

        description="[Obsolete] Utiliser --options linux-backend=headless"

    )



    # ===== Option Windows : Desktop vs UWP ====================================

    # Jenga v2.0.1 n'expose pas TargetOS.UWP; on route UWP via une option.

    newoption(

        trigger="windows-runtime",

        value="RUNTIME",

        allowed=[

            ["desktop", "Windows desktop classique (Win32)"],

            ["uwp",     "Windows Runtime (UWP)"],

        ],

        default="desktop",

        description="Runtime Windows cible (desktop ou UWP)"

    )



    # ===== Plateformes et architectures cibles ==================================

    targetoses([

        TargetOS.WINDOWS,

        TargetOS.LINUX,

        TargetOS.MACOS,

        TargetOS.ANDROID,

        TargetOS.IOS,

        TargetOS.WEB,

        TargetOS.HARMONYOS,

        TargetOS.XBOX_SERIES,

        TargetOS.XBOX_ONE,

    ])



    targetarchs([

        TargetArch.X86_64,   # Desktop (Windows, Linux, macOS, Xbox)

        TargetArch.ARM64,    # Mobile  (Android, iOS)

        TargetArch.WASM32,   # Web     (Emscripten)

    ])



    with unitest() as u:
        u.Compile()



    startproject("Sandbox")



    # Backend de fenetrage Linux : le define NKENTSEU_FORCE_WINDOWING_*_ONLY est

    # emis par _emit_linux_backend_defines() dans config/modules.jenga, appele

    # par nkentseudependson() — donc par CHAQUE projet. Ne pas le poser ici :

    # hors projet, defines() est ignore silencieusement par Jenga (essaye, sans

    # effet ; l'explication complete est dans config/modules.jenga).



    # =========================================================================

    # Inclusion de chaque projet depuis son propre fichier .jenga

    # L'ordre respecte la chaine de dependances.

    # =========================================================================



    with include("Kernel/Foundation/NKPlatform/NKPlatform.jenga"):

        pass



    with include("Kernel/Foundation/NKCore/NKCore.jenga"):

        pass



    with include("Kernel/System/NKLogger/NKLogger.jenga"):

        pass



    with include("Kernel/Foundation/NKMath/NKMath.jenga"):

        pass



    with include("Kernel/Foundation/NKMemory/NKMemory.jenga"):

        pass



    with include("Kernel/Foundation/NKContainers/NKContainers.jenga"):

        pass



    with include("Kernel/Runtime/NKImage/NKImage.jenga"):

        pass



    with include("Kernel/Runtime/NKFont/NKFont.jenga"):

        pass



    with include("Kernel/Runtime/NKAudio/NKAudio.jenga"):

        pass

    with include("Kernel/Runtime/NKMedia/NKMedia.jenga"):

        pass



    with include("Kernel/System/NKTime/NKTime.jenga"):

        pass



    with include("Kernel/System/NKStream/NKStream.jenga"):

        pass



    with include("Kernel/System/NKThreading/NKThreading.jenga"):

        pass



    with include("Kernel/System/NKFileSystem/NKFileSystem.jenga"):

        pass



    with include("Kernel/System/NKReflection/NKReflection.jenga"):

        pass



    with include("Kernel/System/NKNetwork/NKNetwork.jenga"):

        pass



    with include("Kernel/System/NKSerialization/NKSerialization.jenga"):

        pass



    with include("Externals/Libs/NKGlad/NKGlad.jenga"):

        pass



    with include("Externals/Libs/NKGLSlang/NKGLSlang.jenga"):

        pass



    with include("Externals/Libs/NKSPIRVCross/NKSPIRVCross.jenga"):

        pass



    with include("Externals/Libs/NKMbedTLS/NKMbedTLS.jenga"):

        pass



    with include("Externals/Libs/pybind11/pybind11.jenga"):

        pass



    with include("Kernel/Runtime/NKEvent/NKEvent.jenga"):

        pass



    with include("Kernel/Runtime/NKWindow/NKWindow.jenga"):

        pass



    with include("Kernel/Runtime/NKSL/NKSL.jenga"):

        pass



    with include("Kernel/Runtime/NKCanvas/NKCanvas.jenga"):

        pass



    with include("Kernel/Runtime/NKRHI/NKRHI.jenga"):

        pass



    with include("Kernel/Runtime/NKUI/NKUI.jenga"):

        pass



    # NKGui (framework UI immediat) + NKEditorKit (coquille d'editeur) : requis par NKCode.

    with include("Kernel/Runtime/NKGui/NKGui.jenga"):

        pass



    with include("Engine/NKEditorKit/NKEditorKit.jenga"):

        pass

    # Unkeny — moteur de jeu 2D sur NKCanvas. Il COMPOSE NKECS, NKCollision
    # et NKPhysics ; il n'en reecrit rien. Son editeur vit dans
    # Applications/UnkenyEditor : un moteur ne contient pas son outil.
    with include("Engine/Unkeny/Unkeny.jenga"):

        pass



    with include("Applications/NKCode/NKCode.jenga"):

        pass



    with include("Applications/NK3DModeler/NK3DModeler.jenga"):

        pass



    # Integrations decouplees (ImGui / NKUI -> NKCanvas/NKRHI). Optionnelles :

    # une app les lie seulement si elle en a besoin (ImGui n'est PAS tire dans

    # le coeur de NKCanvas/NKRHI).

    with include("Integrations/ImGui/NKImGuiIntegration.jenga"):

        pass



    with include("Integrations/NKUI/NKUIIntegration.jenga"):

        pass



    with include("Integrations/NKGui/NKGuiIntegration.jenga"):

        pass



    with include("Kernel/Runtime/NKCamera/NKCamera.jenga"):

        pass



    # NKCollision (collision 2D+3D, zero-STL).

    with include("Kernel/Runtime/NKCollision/NKCollision.jenga"):

        pass



    # NKPhysics (dynamique corps rigide 2D+3D, sur NKCollision).

    with include("Kernel/Runtime/NKPhysics/NKPhysics.jenga"):

        pass



    # NKAnimPhysics (pose physiquement correcte : masse/COM, equilibre, contacts,
    # correction de pose et de clip). Extrait de NKRenderer/Tools/Animation le
    # 2026-08-14 -- bloc de decision "substrats animation" du CLAUDE.md parent.
    # CPU pur, headless, Foundation seule. NE depend PAS de NKPhysics aujourd hui :
    # voir l en-tete de NKAnimPhysics.jenga, qui dit pourquoi, et ou brancher le
    # pont le jour venu (NkRagdoll, jamais un second pont).

    with include("Kernel/Runtime/NKAnimPhysics/NKAnimPhysics.jenga"):

        pass



    # NKAnimation (substrat d animation : clips, blend 1D/2D, HFSM, reciblage,
    # motion path, edition de pose-cles). Extrait de NKRenderer/Tools/Animation
    # le 2026-08-14. Foundation seule ; le renderer n en garde que la facade
    # de rendu et le debug-draw, et les CONSOMME.

    with include("Kernel/Runtime/NKAnimation/NKAnimation.jenga"):

        pass



    # NKNavigation (NavMesh + pathfinding A*, sur NKCollision -- raycast reel
    # de sondage walkable). Voir Engine/Noge/ROADMAP.md, pilier Navigation IA.

    with include("Kernel/Runtime/NKNavigation/NKNavigation.jenga"):

        pass



    # NKXR (runtime VR/AR/XR : sessions, espaces, poses, entrees par actions,
    # swapchains par oeil ; backend n°1 = simulateur desktop). Etage 0 de la
    # mission XR_MISSION_IA.md.

    with include("Kernel/Runtime/NKXR/NKXR.jenga"):

        pass



    with include("Applications/Sandbox/Sandbox.jenga"):

        pass



    with include("Applications/ConquerorProto/ConquerorProto.jenga"):

        pass



    with include("Applications/NkAudioDemo/NkAudioDemo.jenga"):

        pass



    with include("Applications/NkCameraDemos/NkCameraDemos.jenga"):

        pass



    with include("Sandbox/System/NKFileSystem/NKFileSystemSandbox.jenga"):

        pass



    with include("Sandbox/System/NKLogger/NKLoggerSandbox.jenga"):

        pass



    with include("Sandbox/System/NKReflection/NKReflectionSandbox.jenga"):

        pass



    with include("Sandbox/System/NKNetwork/NKNetworkSandbox.jenga"):

        pass



    with include("Kernel/Runtime/NKRenderer/NKRenderer.jenga"):

        pass



    # ===== Sous-systeme IA (Kernel/AI) — construit bottom-up =====

    with include("Kernel/AI/NKTensor/NKTensor.jenga"):

        pass



    with include("Kernel/AI/NKAutograd/NKAutograd.jenga"):

        pass



    with include("Kernel/AI/NKNN/NKNN.jenga"):

        pass



    with include("Kernel/AI/NKOptim/NKOptim.jenga"):

        pass



    with include("Kernel/AI/NKData/NKData.jenga"):

        pass



    with include("Kernel/AI/NKTrain/NKTrain.jenga"):

        pass



    with include("Kernel/AI/NKInfer/NKInfer.jenga"):

        pass



    with include("Kernel/AI/NKRL/NKRL.jenga"):

        pass



    with include("Kernel/AI/NKAgent/NKAgent.jenga"):

        pass



    with include("Kernel/AI/NKEvolve/NKEvolve.jenga"):

        pass



    with include("Kernel/AI/NKCivilization/NKCivilization.jenga"):

        pass



    with include("Kernel/AI/NKEmbodied/NKEmbodied.jenga"):

        pass



    with include("Kernel/AI/NKGen/NKGen.jenga"):

        pass

    with include("Kernel/AI/NKGpt/NKGpt.jenga"):

        pass

    with include("Kernel/AI/NKSpeech/NKSpeech.jenga"):

        pass



    with include("Applications/NKTensorDemo/NKTensorDemo.jenga"):

        pass



    with include("Applications/NkSLComputeCheck/NkSLComputeCheck.jenga"):

        pass



    with include("Applications/NkGpuProbe/NkGpuProbe.jenga"):

        pass



    with include("Applications/NkComputeNkSL/NkComputeNkSL.jenga"):

        pass



    with include("Applications/NkTensorGpuTest/NkTensorGpuTest.jenga"):

        pass



    with include("Applications/NKGpuBenchTest/NKGpuBenchTest.jenga"):

        pass



    with include("Applications/NKConvBenchTest/NKConvBenchTest.jenga"):

        pass



    with include("Applications/NKConvResidentBench/NKConvResidentBench.jenga"):

        pass



    with include("Applications/NKMlpResidentBench/NKMlpResidentBench.jenga"):

        pass



    with include("Applications/NKMnistGpuTrain/NKMnistGpuTrain.jenga"):

        pass



    with include("Applications/NKRebasinTest/NKRebasinTest.jenga"):

        pass



    with include("Applications/NKMnistCnnGpuTrain/NKMnistCnnGpuTrain.jenga"):

        pass



    with include("Applications/NKTransformerTest/NKTransformerTest.jenga"):

        pass



    with include("Applications/NKGptTrain/NKGptTrain.jenga"):

        pass



    with include("Applications/NKIlyana/NKIlyana.jenga"):

        pass



    with include("Applications/NKAutogradTest/NKAutogradTest.jenga"):

        pass



    with include("Applications/NKNNTest/NKNNTest.jenga"):

        pass



    with include("Applications/NKConvTest/NKConvTest.jenga"):

        pass



    with include("Applications/NKDataTest/NKDataTest.jenga"):

        pass



    with include("Applications/NKBpeTest/NKBpeTest.jenga"):

        pass



    with include("Applications/NKLlamaBlockTest/NKLlamaBlockTest.jenga"):

        pass



    with include("Applications/NKRebasinTransformer/NKRebasinTransformer.jenga"):

        pass



    with include("Applications/NKTrainTest/NKTrainTest.jenga"):

        pass



    with include("Applications/NKFp16Test/NKFp16Test.jenga"):

        pass



    with include("Applications/NKRnnCtcTest/NKRnnCtcTest.jenga"):

        pass



    with include("Applications/NKASRTest/NKASRTest.jenga"):

        pass



    with include("Applications/NKImageCodecTest/NKImageCodecTest.jenga"):

        pass

    with include("Applications/NkEditableMeshDemo/NkEditableMeshDemo.jenga"):

        pass

    with include("Applications/NkLocomotionDemo/NkLocomotionDemo.jenga"):

        pass

    with include("Applications/NkAssetIODemo/NkAssetIODemo.jenga"):

        pass

    with include("Applications/NkFBXParityDemo/NkFBXParityDemo.jenga"):

        pass

    with include("Applications/NkSVGImportDemo/NkSVGImportDemo.jenga"):

        pass

    with include("Applications/NKMeshAITest/NKMeshAITest.jenga"):

        pass

    with include("Applications/NKEditMeshHarness/NKEditMeshHarness.jenga"):

        pass

    with include("Applications/NkAnimPhysTest/NkAnimPhysTest.jenga"):

        pass

    # NkMatInventaireTest : banc ARRETE (cc6aba5b), RETIRE du workspace le 17/08.
    # Il echoue au lien PAR CONSTRUCTION -- 118 symboles Demo3DHost* definis dans
    # NkDemo3D.cpp, jamais compile ici -- et c'etait documente dans son en-tete
    # d'arret : ces 118 symboles SONT la mesure de la dette C (lire un .nkmat
    # tire toute la pile d'interface). Le laisser enregistre faisait echouer le
    # build complet de main pour tout le monde (trouve par l'agent Ilyana).
    # NE PAS le « reparer » en ajoutant NkDemo3D.cpp a ses sources : compiler
    # toute la pile d'interface a chaque build est precisement le cout qui a
    # fait arreter ce banc. Ses sources restent dans Applications/ avec leur
    # en-tete d'arret ; il se re-enregistre le jour ou Demo3DHost devient une
    # bibliotheque -- il linkera alors sans une ligne de plus.
    # with include("Applications/NkMatInventaireTest/NkMatInventaireTest.jenga"):
    #     pass

    with include("Applications/NkMicRecord/NkMicRecord.jenga"):

        pass

    with include("Applications/NKSpeechTest/NKSpeechTest.jenga"):

        pass

    with include("Applications/NKTTSTrain/NKTTSTrain.jenga"):

        pass

    with include("Applications/NkVoiceLoopDemo/NkVoiceLoopDemo.jenga"):

        pass

    with include("Applications/NKSpeechFeatureDemo/NKSpeechFeatureDemo.jenga"):

        pass

    with include("Applications/NKMediaTest/NKMediaTest.jenga"):

        pass

    with include("Applications/NkVideoReadTest/NkVideoReadTest.jenga"):

        pass

    with include("Applications/NkAudioPlayer/NkAudioPlayer.jenga"):

        pass

    with include("Applications/NkVideoPlayer/NkVideoPlayer.jenga"):

        pass

    with include("Applications/NKOpusRef/NKOpusRef.jenga"):

        pass

    with include("Applications/NKVideoTest/NKVideoTest.jenga"):

        pass



    with include("Applications/NKInferTest/NKInferTest.jenga"):

        pass



    with include("Applications/NKGGUFInspectTest/NKGGUFInspectTest.jenga"):

        pass



    with include("Applications/NKLLMInferTest/NKLLMInferTest.jenga"):

        pass



    with include("Applications/NKQwenTokenizerTest/NKQwenTokenizerTest.jenga"):

        pass



    with include("Applications/NKQwen2BackwardTest/NKQwen2BackwardTest.jenga"):

        pass



    with include("Applications/NKQwen2SftTest/NKQwen2SftTest.jenga"):

        pass



    with include("Applications/NKQ4MatmulTest/NKQ4MatmulTest.jenga"):

        pass



    with include("Applications/NKQwen2GpuTest/NKQwen2GpuTest.jenga"):

        pass



    with include("Applications/NKQwen2Chat/NKQwen2Chat.jenga"):

        pass



    with include("Applications/NKQwen2SftGpuTest/NKQwen2SftGpuTest.jenga"):

        pass



    with include("Applications/NKQwen2Train/NKQwen2Train.jenga"):

        pass



    with include("Applications/NKQwen2Ask/NKQwen2Ask.jenga"):

        pass



    with include("Applications/NKRLTest/NKRLTest.jenga"):

        pass



    with include("Applications/NKAgentTest/NKAgentTest.jenga"):

        pass



    with include("Applications/NKAgentLLMTest/NKAgentLLMTest.jenga"):

        pass


    with include("Applications/NkAgentEcsDemo/NkAgentEcsDemo.jenga"):

        pass



    with include("Applications/NKEmbodiedTest/NKEmbodiedTest.jenga"):

        pass



    with include("Applications/NKEvolveTest/NKEvolveTest.jenga"):

        pass



    with include("Applications/NKEvolveNNTest/NKEvolveNNTest.jenga"):

        pass



    with include("Applications/NKCivilizationTest/NKCivilizationTest.jenga"):

        pass



    with include("Applications/NKCivilizationSocialTest/NKCivilizationSocialTest.jenga"):

        pass



    with include("Applications/NKCivilizationScaleTest/NKCivilizationScaleTest.jenga"):

        pass



    with include("Applications/NKGenTest/NKGenTest.jenga"):

        pass



    with include("Applications/NKVAETest/NKVAETest.jenga"):

        pass



    with include("Applications/NKMnistVAETest/NKMnistVAETest.jenga"):

        pass



    with include("Applications/NKMnistConvVAETest/NKMnistConvVAETest.jenga"):

        pass



    with include("Applications/NKConvVAETest/NKConvVAETest.jenga"):

        pass



    with include("Applications/NKDiffusionTest/NKDiffusionTest.jenga"):

        pass



    with include("Applications/NKVoxelGenTest/NKVoxelGenTest.jenga"):

        pass



    with include("Applications/NKObjectGenTest/NKObjectGenTest.jenga"):

        pass



    with include("Applications/NKGen3DTest/NKGen3DTest.jenga"):

        pass



    with include("Applications/NKGenMeshTest/NKGenMeshTest.jenga"):

        pass



    with include("Applications/NKSmoothMeshTest/NKSmoothMeshTest.jenga"):

        pass

    with include("Applications/NKMatTypeResetTest/NKMatTypeResetTest.jenga"):

        pass



    with include("Applications/NKEditTargetTest/NKEditTargetTest.jenga"):

        pass



    with include("Applications/NKMeshRenderTest/NKMeshRenderTest.jenga"):

        pass



    with include("Applications/Model/Model.jenga"):

        pass



    with include("Applications/NkSLCheck/NkSLCheck.jenga"):

        pass



    with include("Applications/NKPA/NKPA.jenga"):

        pass



    # NKECS (ECS bas niveau archetypes) — DOIT etre enregistre AVANT Noge qui en

    # depend (sinon %{NKECS.location} vide -> includes NKECS/* introuvables).

    with include("Kernel/Runtime/NKECS/NKECS.jenga"):

        pass



    with include("Engine/Noge/Noge.jenga"):

        pass



    with include("Applications/Nogee/Nogee.jenga"):

        pass



    with include("Applications/NKEditorKitDemo/NKEditorKitDemo.jenga"):

        pass



    # Banc SANS FENETRE de NKEditorKit : resolution des roles de theme (le
    # magenta du 18/08) et vocabulaire du backend graphique (Metal compris).
    # Console, aucun GPU, code de sortie 0/1 -- il peut donc tourner partout.
    with include("Applications/NKEditorKitTest/NKEditorKitTest.jenga"):

        pass



    with include("Applications/NKUIDesign/NKUIDesign.jenga"):

        pass



    with include("Applications/ConquerorLab/ConquerorLab.jenga"):

        pass



    with include("Applications/NkRef/NkRef.jenga"):

        pass



    with include("Applications/NkAnimaEditor/NkAnimaEditor.jenga"):

        pass



    with include("Applications/ImGuiRef/ImGuiRef.jenga"):

        pass



    with include("Applications/NKGuiDrawTest/NKGuiDrawTest.jenga"):

        pass



    with include("Applications/NKGuiDemo/NKGuiDemo.jenga"):

        pass



    with include("Applications/NKViewportDemo/NKViewportDemo.jenga"):

        pass



    with include("Applications/PV3DE/PV3DE.jenga"):

        pass



    with include("Applications/Pong/Pong.jenga"):

        pass



    # TODO(Songoo) : migration rendu GL -> NKCanvas a FINIR (12 scenes UI utilisent encore
    # Render/GLContext|GLRenderer2D|Texture2D|FontAtlas supprimes). Desactive du build pour
    # ne pas casser `jenga build`. Le code source reste dans main ; reactiver apres migration.
    # with include("Applications/Songoo/Songoo.jenga"):
    #     pass
    if False:
        with include("Applications/Songoo/Songoo.jenga"):
            pass



    with include("Applications/Nkoung/Nkoung.jenga"):

        pass



    with include("Applications/Mou/Mou.jenga"):

        pass



    with include("Applications/NkImeTest/NkImeTest.jenga"):

        pass



    with include("Applications/NkImageDemo/NkImageDemo.jenga"):

        pass



    with include("Applications/RihenDefi/RihenDefi.jenga"):

        pass



    with include("Applications/NkAudioECSDemo/NkAudioECSDemo.jenga"):

        pass

    with include("Applications/NkNetWorldDemo/NkNetWorldDemo.jenga"):

        pass



    with include("Applications/NkNavDemo/NkNavDemo.jenga"):

        pass



    with include("Applications/NkNavCoreDemo/NkNavCoreDemo.jenga"):

        pass


    # Jalon G2.3 Noge : scripting C++ natif hot-reload (DLL) — démo console
    # (compile un script en .dll a runtime, hot-reload avec etat preserve).
    with include("Applications/NkHotReloadDemo/NkHotReloadDemo.jenga"):

        pass


    # Jalon G2.1 Noge : systeme ECS UI in-game (HUD) — demo console headless
    # (NKCanvas backend Software CPU + NKFont embarque, assertions de pixels).
    with include("Applications/NkUIHudDemo/NkUIHudDemo.jenga"):

        pass



    # Serie d'apprentissage : concevoir une app 3D avec NKRenderer pas a pas
    # (5 etapes/projets : fenetre -> renderer -> scene -> camera -> meshes custom).
    # Voir Tutoriels3D/README.md.

    with include("Tutoriels3D/Tutoriels3D.jenga"):

        pass



    # Etage 0 XR : scene NKRenderer en stereo SIMULEE via NKXR (simulateur
    # desktop, souris = tete). Voir XR_MISSION_IA.md.

    with include("Applications/NKXRDemo/NKXRDemo.jenga"):
        pass



    # Etage 3 XR : realite augmentee a marqueurs (camera + NkArSession).
    with include("Applications/NKARDemo/NKARDemo.jenga"):
        pass


    # GemCrush — SEULEMENT si son .jenga est la. Sur cette branche le dossier
    # n'a jamais ete commite (il l'est sur main) : depuis f9b68097 (2026-09-01)
    # un clone frais — donc tout runner GitHub Actions — echouait des le
    # chargement du workspace (« External file not found »), quelle que soit
    # la cible demandee. Constate le 2026-09-04 sur le build macOS de NKCode.
    if os.path.isfile(os.path.join(_WORKSPACE_ROOT, "Applications", "Gemcrush", "GemCrush.jenga")):
        with include("Applications/Gemcrush/GemCrush.jenga"):
            pass

    # Les trois jeux de plateau, batis sur la coquille moderne NkCanvasApp.
    # Ils servent aussi de PREUVE a cette coquille : une base qui n a qu un
    # seul consommateur ne prouve rien sur sa reutilisabilite.
    with include("Applications/NkDames/NkDames.jenga"):
        pass

    with include("Applications/NkEchecs/NkEchecs.jenga"):
        pass

    with include("Applications/NkLudo/NkLudo.jenga"):
        pass

    # L'editeur d'Unkeny. Il vit ici, pas dans Engine : un moteur ne
    # contient pas son outil.
    with include("Applications/UnkenyEditor/UnkenyEditor.jenga"):
        pass
    
    with include("Applications/MonEssai/MonEssai.jenga"):
        pass
```