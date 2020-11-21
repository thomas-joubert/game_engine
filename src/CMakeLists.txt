include_directories("${Something_SOURCE_DIR}/include")

find_package(SFML REQUIRED window graphics system)

add_library(main SHARED object.cc textured_object.cc obstacle.cc player.cc)
