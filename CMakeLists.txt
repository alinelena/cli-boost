CMAKE_POLICY(SET CMP0048 NEW)
#to be abe to use version
project(cli
LANGUAGES CXX
VERSION 0.0.1.0)
cmake_minimum_required(VERSION 2.8.12)
set(AUTHOR "Alin M Elena")
set(AUTHOR_DETAILS "alin@elena.space")
set(DESCRIPTION "Simple command line argument handling using boost")
include(GNUInstallDirs)
if (CMAKE_VERSION VERSION_LESS 3.1.0)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
else()
	set(CMAKE_CXX_STANDARD 11)
endif()
find_package(Boost  COMPONENTS program_options)
message(STATUS "Building prepareation for ${PROJECT_NAME} version: ${cli_VERSION_MAJOR}.${cli_VERSION_MINOR}.${cli_VERSION_PATCH}.${cli_VERSION_TWEAK}")
option(BUILD_TESTING "Build with tests" ON)
option(BUILD_DOCS "Build with tests" ON)
if (${BUILD_TESTING})
  include(CTest)
endif()

set(LIBRARY_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_LIBDIR})
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/${CMAKE_INSTALL_BINDIR})

add_executable(cli source/cliconf.cxx  source/parseCLI.cxx)
target_link_libraries(cli ${Boost_LIBRARIES})

if(BUILD_DOCS)
  find_package(Doxygen REQUIRED)
  configure_file(${PROJECT_SOURCE_DIR}/cmake/Doxyfile.cmake ${PROJECT_BIN_DIR}Doxyfile)
  add_custom_target(docs
    ${DOXYGEN_EXECUTABLE} ${PROJECT_BINARY_DIR}/Doxyfile)
endif()

if (${BUILD_TESTING})
#testing this macro in big projects may go in its own file
macro (do_test count arg result)
  add_test(cliTest${count} ${CMAKE_INSTALL_BINDIR}/cli "${arg}")
  set_tests_properties (cliTest${count}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)

  do_test(1 "-s 42" "steps[\ ].*42")
  do_test(2 "-m MC"  "method[\ ].*MC")
endif()
