project(PracaLicencjackaSrc)

add_executable(PracaLicencjackaSrc
    main.cpp)

target_include_directories(PracaLicencjackaSrc PRIVATE ${CMAKE_SOURCE_DIR}/src)
