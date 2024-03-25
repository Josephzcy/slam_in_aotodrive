# Automatically generated by scripts/boost/generate-ports.ps1

vcpkg_from_github(
    OUT_SOURCE_PATH SOURCE_PATH
    REPO boostorg/format
    REF boost-1.81.0
    SHA512 a526b1ef7379a44d67641b9124ea6b145e1153aa631a753e92ad7e3983481b7b9064b28219da408ae71e6837a0b9c53407d9c55418dc0101d5a16ee04068ac39
    HEAD_REF master
)

include(${CURRENT_INSTALLED_DIR}/share/boost-vcpkg-helpers/boost-modular-headers.cmake)
boost_modular_headers(SOURCE_PATH ${SOURCE_PATH})