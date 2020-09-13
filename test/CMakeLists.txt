set(TEST_SRCS
        baseTest.cpp
        )
foreach (test ${TEST_SRCS})
    string(REGEX REPLACE ".*/" "" test_name ${test})
    string(REGEX REPLACE "\\..*" "" test_name ${test_name})
    add_executable(${test_name} ${test})
    target_include_directories(${test_name}
            PUBLIC
            $<INSTALL_INTERFACE:include>
            $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/../include>
            PRIVATE
            )
    target_link_libraries(${test_name} Boost::unit_test_framework pthread)
    add_test(NAME ${test_name} COMMAND ${test_name})
endforeach ()
