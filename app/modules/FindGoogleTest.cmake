
set(GoogleTest_FOUND                    true)
set(GoogleTest_PROJECT_NAME             GoogleTest)
set(GoogleTest_DEPENDENCY_NAME          ${GoogleTest_PROJECT_NAME})
set(GoogleTest_LIBRARY_NAME             gtest)
set(GoogleTest_OUTPUT_DIR               ${CMAKE_BINARY_DIR}/modules/GoogleTest)
set(GoogleTest_INCLUDE_DIRS             ${GoogleTest_OUTPUT_DIR}/include)
set(GoogleTest_LIBRARIES                ${GoogleTest_OUTPUT_DIR}/lib/lib${GoogleTest_LIBRARY_NAME}.a
                                        ${GoogleTest_OUTPUT_DIR}/lib/libgmock.a)
