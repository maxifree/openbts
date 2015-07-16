cmake_minimum_required(VERSION 2.8)
project(openbts)

execute_process(COMMAND ${CMAKE_SOURCE_DIR}/Globals/GrabRepoInfo.sh ${CMAKE_SOURCE_DIR}
                OUTPUT_VARIABLE REPO_REV)
string(STRIP ${REPO_REV} REPO_REV)
add_definitions(-DREPO_REV="${REPO_REV}")

execute_process(COMMAND date +"%Y-%m-%dT%H:%M:%S"
                OUTPUT_VARIABLE TIMESTAMP_ISO)
string(STRIP ${TIMESTAMP_ISO} TIMESTAMP_ISO)
add_definitions(-DTIMESTAMP_ISO=${TIMESTAMP_ISO})

find_library(READLINE_LIBRARIES readline)
find_library(A53_LIBRARIES a53)
find_package(Threads REQUIRED)
find_package(PkgConfig REQUIRED)
pkg_check_modules(PC_SQLITE3 REQUIRED sqlite3)
pkg_check_modules(PC_ZMQ REQUIRED libzmq)
pkg_check_modules(PC_ORTP REQUIRED ortp)
pkg_check_modules(PC_UHD REQUIRED uhd)

file(WRITE ${CMAKE_CURRENT_BINARY_DIR}/config.h
"#define HAVE_BYTESWAP_H 1
#define HAVE_GETHOSTBYNAME2_R 1
#define HAVE_SSE3
#define HAVE_SSE4_1
#define ORTP_NEW_API 1
#define USE_UHD 1
#define VERSION \"5.0-master\"
#define WORDS_BIGENDIAN
"
)

# For config.h
include_directories(${CMAKE_CURRENT_BINARY_DIR})

include_directories(NodeManager)
include_directories(NodeManager/JsonBox-0.4.3/include)
include_directories(CLI)
include_directories(tools)
include_directories(GSM)
include_directories(SMS)
include_directories(Transceiver52M)
include_directories(TRXManager)
include_directories(SGSNGGSN)
include_directories(debian)
include_directories(TransceiverRAD1)
include_directories(CommonLibs)
include_directories(Peering)
include_directories(GPRS)
include_directories(GSMShare)
include_directories(Globals)
include_directories(Control)
include_directories(package)
include_directories(apps)
include_directories(config)
include_directories(SIP)
include_directories(Scanning)

add_subdirectory(CLI)
add_subdirectory(Globals)
add_subdirectory(NodeManager)
add_subdirectory(tools)
add_subdirectory(GSM)
add_subdirectory(SMS)
add_subdirectory(Transceiver52M)
add_subdirectory(TRXManager)
add_subdirectory(GPRS)
add_subdirectory(SGSNGGSN)
#add_subdirectory(TransceiverRAD1)
add_subdirectory(CommonLibs)
add_subdirectory(Peering)
add_subdirectory(GSMShare)
add_subdirectory(Control)
add_subdirectory(SIP)
add_subdirectory(Scanning)
add_subdirectory(apps)
