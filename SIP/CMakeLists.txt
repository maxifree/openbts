set(SOURCE_FILES
    SIPRtp.cpp
    SIPParse.cpp
    SIPMessage.cpp
    SIPDialog.cpp
    SIP2Interface.cpp
    SIPBase.cpp
    SIPUtility.cpp
    SIPTransaction.cpp
)
add_library(SIP STATIC ${SOURCE_FILES})
target_link_libraries(SIP ${PC_ORTP_LIBRARIES})
