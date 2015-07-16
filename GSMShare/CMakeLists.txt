set(SOURCE_FILES
    L3Enums.cpp
    AmrCoder.cpp
    GSM503Tables.cpp
    ViterbiR204.cpp
    A51.cpp
)
add_library(GSMShare STATIC ${SOURCE_FILES})

add_executable(ViterbiTest ViterbiTest.cpp)
target_link_libraries(ViterbiTest GSMShare globals GSM common ${PC_SQLITE3_LIBRARIES})
add_executable(AMRTest AMRTest.cpp)
target_link_libraries(AMRTest GSMShare globals GSM common ${PC_SQLITE3_LIBRARIES})
add_executable(A51Test A51Test.cpp)
target_link_libraries(A51Test GSMShare globals GSM common ${PC_SQLITE3_LIBRARIES})
