include(ExternalProject)

include(${CMAKE_CURRENT_SOURCE_DIR}/FindGoogleTest.cmake)

set(GOOGLETEST_VERSION_NAME googletest-release-1.10.0)
set(GOOGLE_TEST_COMPRESSED_FILE_NAME   ${CMAKE_CURRENT_SOURCE_DIR}/${GOOGLETEST_VERSION_NAME}.tar.gz)

message("Uncompressing ${GOOGLE_TEST_COMPRESSED_FILE_NAME} ...")

execute_process(
    COMMAND             ${CMAKE_COMMAND} -E tar xzf ${GOOGLE_TEST_COMPRESSED_FILE_NAME}
    WORKING_DIRECTORY   ${CMAKE_CURRENT_BINARY_DIR}
)

ExternalProject_Add(        ${GoogleTest_PROJECT_NAME}
    SOURCE_DIR              ${CMAKE_CURRENT_BINARY_DIR}/${GOOGLETEST_VERSION_NAME}
    BINARY_DIR              ${GoogleTest_OUTPUT_DIR}
    PREFIX                  ${GoogleTest_OUTPUT_DIR}
    BUILD_COMMAND           make
    INSTALL_COMMAND         make install
    LIST_SEPARATOR          | # Use the alternate list separator
    CMAKE_ARGS
                            -DCMAKE_INSTALL_PREFIX=${GoogleTest_OUTPUT_DIR}
)
