set(SOURCE_FILES
    MSInfo.cpp
    RLCEngine.cpp
    TBF.cpp
    MAC.cpp
    FEC.cpp
    RLCEngine.cpp
    RLCMessages.cpp
    ByteVector.cpp
    GPRSCLI.cpp
    RLC.cpp
    MsgBase.cpp
)
add_library(GPRS STATIC ${SOURCE_FILES})
