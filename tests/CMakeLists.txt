include_directories("${Something_SOURCE_DIR}/include")

find_package(GTest)

add_library(test SHARED EXCLUDE_FROM_ALL object/object_tests.cc
                        texturedObject/textured_object_tests.cc
                        player/player_tests.cc)
