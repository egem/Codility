set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -pedantic -Werror")

option(ENABLE_UNIT_TESTS "ON/OFF, Enable to activate unit test. Default value is ON" ON)