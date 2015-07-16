set(SOURCE_FILES
    Sgsn.cpp
    Ggsn.cpp
    GPRSL3Messages.cpp
    iputils.cpp
    miniggsn.cpp
    LLC.cpp
    SgsnCli.cpp
)
add_library(SGSNGGSN STATIC ${SOURCE_FILES})
