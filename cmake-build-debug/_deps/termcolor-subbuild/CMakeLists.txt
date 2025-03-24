# Distributed under the OSI-approved BSD 3-Clause License.  See accompanying
# file Copyright.txt or https://cmake.org/licensing for details.

cmake_minimum_required(VERSION 3.16.5)

# We name the project and the target for the ExternalProject_Add() call
# to something that will highlight to the user what we are working on if
# something goes wrong and an error message is produced.

project(termcolor-populate NONE)

include(ExternalProject)
ExternalProject_Add(termcolor-populate
                     "UPDATE_DISCONNECTED" "False" "GIT_REPOSITORY" "https://github.com/ikalnytskyi/termcolor.git" "GIT_TAG" "master"
                    SOURCE_DIR          "/home/mwiner/SchoolProjects/CMPR-131/CMPR131-HW2/cmake-build-debug/_deps/termcolor-src"
                    BINARY_DIR          "/home/mwiner/SchoolProjects/CMPR-131/CMPR131-HW2/cmake-build-debug/_deps/termcolor-build"
                    CONFIGURE_COMMAND   ""
                    BUILD_COMMAND       ""
                    INSTALL_COMMAND     ""
                    TEST_COMMAND        ""
                    USES_TERMINAL_DOWNLOAD  YES
                    USES_TERMINAL_UPDATE    YES
)
