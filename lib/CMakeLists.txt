cmake_minimum_required(VERSION 2.6)
project(prpg)

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
	"./"
	"game"
)

set(SRCS
	game/game.cpp
	include/key.h
	include/rect.h
	include/colour.h
	include/igamerenderer.h
	include/gameinfo.h
	include/game.h
	include/gamestate.h
)

add_library(prpg STATIC "${SRCS}")

source_group(TREE ../../lib FILES ${SRCS})