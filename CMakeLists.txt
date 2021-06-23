cmake_minimum_required(VERSION 3.11)
project(bomberman)

find_package(raylib 3.0 QUIET)

if (NOT raylib_FOUND)
  include(FetchContent)

  FetchContent_Declare(
    raylib
    URL https://github.com/raysan5/raylib/archive/master.tar.gz
  )

  FetchContent_GetProperties(raylib)
  if (NOT raylib_POPULATED)
    set(FETCHCONTENT_QUIET NO)
    FetchContent_Populate(raylib)

    set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

    add_subdirectory(${raylib_SOURCE_DIR} ${raylib_BINARY_DIR})

  endif()

endif()

set(SrcText
 src/encapsulation/Text/EText.cpp)

set(SrcWindow
 src/encapsulation/Window/EWindow.cpp)

set(SrcCamera
 src/encapsulation/Camera/ECamera.cpp)

set(SrcCharacter
 src/Character/AI.cpp
 src/Character/InputUser.cpp
 src/Character/Player.cpp
 src/Character/CharacterFactory.cpp
 src/Character/CharacterManager.cpp)

set(SrcController
 src/encapsulation/Controller/Controller.cpp)

set(SrcShapes
 src/encapsulation/Shapes/Shapes3D/Cube.cpp
 src/encapsulation/Shapes/Shapes2D/ERectangle.cpp
 src/encapsulation/Shapes/Shapes2D/ECircle.cpp
 src/encapsulation/Shapes/Shapes3D/Sphere.cpp)

set(SrcColor
 src/encapsulation/Color/EColor.cpp)

set(SrcAudio
 src/encapsulation/Audio/EMusic.cpp
 src/encapsulation/Audio/ESound.cpp
 src/encapsulation/Audio/AudioManager.cpp)

set(SrcScene
 src/Scene/Menu.cpp
 src/Scene/Game.cpp
 src/Scene/Settings.cpp
 src/Scene/Pause.cpp
 src/Scene/Options.cpp
 src/Scene/SelectMap.cpp
 src/Scene/Loading.cpp
 src/Scene/HowToPlay.cpp
 src/Scene/Transition.cpp
 src/Scene/Scoreboard.cpp)

set(SrcModel
 src/encapsulation/Model/EModel.cpp)

set(SrcTools
 src/tools/tools.cpp)

set (SrcWidget
 src/Widget/Button.cpp)

set(SrcBlock
 src/Block/Wall.cpp
 src/Block/Spawn.cpp
 src/Block/Barrel.cpp
 src/Block/BlockFactory.cpp
 src/Block/Empty.cpp)

set(SrcMap
 src/Map/Map.cpp
 src/Map/MapParser.cpp)

set(SrcItems
 src/Bomb/Bomb.cpp)

set(SrcClock
 src/Clock/Clock.cpp)

set(SrcImage
 src/encapsulation/Image/EImage.cpp)

add_executable(bomberman
 main.cpp
 src/App/App.cpp
 ${SrcScene}
 ${SrcCharacter}
 ${SrcController}
 ${SrcCamera}
 ${SrcWindow}
 ${SrcColor}
 ${SrcShapes}
 ${SrcText}
 ${SrcAudio}
 ${SrcModel}
 ${SrcTools}
 ${SrcWidget}
 ${SrcBlock}
 ${SrcMap}
 ${SrcItems}
 ${SrcClock}
 ${SrcImage})

set_property(TARGET bomberman
 PROPERTY
  CXX_STANDARD 17
)

target_link_libraries(bomberman raylib)
include_directories(bomberman include)