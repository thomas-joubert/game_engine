include_directories("${Something_SOURCE_DIR}/include")

find_package(GTest)

include_directories(third_party/nlohmann)

add_library(test SHARED EXCLUDE_FROM_ALL tests_cases/object/object_tests.cc
                        tests_cases/texturedObject/textured_object_tests.cc
                        tests_cases/player/player_tests.cc
                        tests_cases/logger/logger_tests.cc
                        tests_cases/obstacle/obstacle-tests.cc
                        tests_cases/collision/collision_handler_tests.cc)
