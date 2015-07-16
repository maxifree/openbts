set(CMAKE_C_FLAGS "-std=gnu99 -march=native")
add_library(transceiver-lib STATIC
    radioInterfaceResamp.cpp
    Resampler.cpp
    radioInterface.cpp
    radioVector.cpp
    radioClock.cpp
    sigProcLib.cpp
    Transceiver.cpp
    DummyLoad.cpp
    convolve.c
    convert.c
    UHDDevice.cpp
)
target_link_libraries(transceiver-lib GSM common ${PC_UHD_LIBRARIES} ${PC_SQLITE3_LIBRARIES})
add_executable(transceiver runTransceiver.cpp)
target_link_libraries(transceiver transceiver-lib ${PC_UHD_LIBRARIES})
#target_link_libraries(openbts
#    ${PC_ORTP_LIBRARIES} ${PC_ZMQ_LIBRARIES}
#    control cli common GPRS GSM GSMShare globals
#    nodemanager peering SGSNGGSN SIP SMS scanning trxmanager
#)
