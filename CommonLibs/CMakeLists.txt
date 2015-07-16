set(SOURCE_FILES
    Variables.cpp
    BitVector.cpp
    LinkedLists.cpp
    SelfDetect.cpp
    UnixSignal.cpp
    Sockets.cpp
    Threads.cpp
    Timeval.cpp
    Reporting.cpp
    Logger.cpp
    Configuration.cpp
    sqlite3util.cpp
    URLEncode.cpp
    Utils.cpp
)
add_library(common STATIC ${SOURCE_FILES})
target_link_libraries(common
    ${PC_SQLITE3_LIBRARIES}
    ${CMAKE_THREAD_LIBS_INIT} 
    -lpthread
)

foreach(TARGET 
    BitVectorTest
    ConfigurationTest
    F16Test
    InterthreadTest
    LockTest
    LogTest
    RegexpTest
    #ReportingTest
    SelfDetectTest
    SocketsTest
    ThreadTest
    TimevalTest
    URLEncodeTest
    UnixSignalTest
    UtilsTest
    VectorTest
)
    add_executable(${TARGET} ${TARGET}.cpp)
    target_link_libraries(${TARGET} common)
endforeach(TARGET)
