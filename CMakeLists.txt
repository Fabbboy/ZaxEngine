cmake_minimum_required(VERSION 3.22)
project(game)

set(CMAKE_CXX_STANDARD 14)
include_directories(/usr/local/Cellar/sdl2/2.24.0/include)
include_directories(/usr/local/Cellar/sdl2/2.24.0/include/SDL2)
include_directories(/usr/local/Cellar/sdl2_ttf/2.20.1/include)
include_directories(/usr/local/Cellar/sdl2_image/2.6.2/include)
include_directories(/usr/local/Cellar/sdl2_mixer/2.6.2/include)
include_directories(/usr/local/Cellar/sdl2_gfx/1.0.4/include)

#g++ -c src/*.cpp -std=c++14 -O3 -Wall -m64 -I include && mkdir -p bin/release && g++ *.o -o bin/release/main -s -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
# set flags
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -O3 -Wall -m64 -I include")
add_executable(game main.cpp engine/includes/RenderWindow.h engine/includes/Entity.h engine/RenderWindow.cpp engine/Entity.cpp engine/includes/utils.h engine/utils.cpp engine/includes/Input.h engine/Input.cpp engine/includes/Texture.h engine/Texture.cpp engine/includes/Vector.h engine/includes/System.h engine/System.cpp engine/includes/Colors.h)
target_link_libraries(game /usr/local/Cellar/sdl2/2.24.0/lib/libSDL2.dylib)
target_link_libraries(game /usr/local/Cellar/sdl2_ttf/2.20.1/lib/libSDL2_ttf.dylib)
target_link_libraries(game /usr/local/Cellar/sdl2_image/2.6.2/lib/libSDL2_image.dylib)
target_link_libraries(game /usr/local/Cellar/sdl2_mixer/2.6.2/lib/libSDL2_mixer.dylib)
target_link_libraries(game /opt/X11/lib/libfreetype.6.dylib)
target_link_libraries(game /usr/local/Cellar/sdl2_gfx/1.0.4/lib/libSDL2_gfx.dylib)
