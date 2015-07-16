add_executable(openbts GetConfigurationKeys.cpp OpenBTS.cpp)
target_link_libraries(openbts
    ${PC_ORTP_LIBRARIES} ${PC_ZMQ_LIBRARIES}
    control cli common GPRS GSM GSMShare globals
    nodemanager peering SGSNGGSN SIP SMS scanning trxmanager
)
add_executable(openbts-cli OpenBTSCLI.cpp)
target_link_libraries(openbts-cli
    cli ${READLINE_LIBRARIES} globals control
)
