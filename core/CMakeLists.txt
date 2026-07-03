file(GLOB_RECURSE CORE_SOURCES "src/*.cpp")

if(CORE_SOURCES)
  add_library(core STATIC ${CORE_SOURCES})
  target_include_directories(core PUBLIC include)
else()
  add_library(core INTERFACE)
  target_include_directories(core INTERFACE include)
endif()