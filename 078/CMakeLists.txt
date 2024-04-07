cmake_minimum_required(VERSION 3.16)

project(main CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_BUILD_TYPE Debug)

include(FetchContent)

FetchContent_Declare(
  PDFHummus
  GIT_REPOSITORY https://github.com/galkahana/PDF-Writer.git
  GIT_TAG        v4.6.2
)
FetchContent_MakeAvailable(PDFHummus)

add_executable(main main.cc image_pdf.h image_pdf.cc)

target_link_libraries(main PRIVATE PDFHummus::PDFWriter )

target_include_directories(main PUBLIC ${PDFHummus_SOURCE_DIR})

# TARGET_LINK_LIBRARIES( main LINK_PUBLIC ${Boost_LIBRARIES} )
install(TARGETS main DESTINATION ${CMAKE_CURRENT_SOURCE_DIR})