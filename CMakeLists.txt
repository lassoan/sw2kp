CMAKE_MINIMUM_REQUIRED(VERSION 2.6.3 FATAL_ERROR)
PROJECT(sw2kp)

SET(sw2kp_SRCS
  sw2kp.cxx
)

SET(sw2kp_LIBS
  vtkCommon
  vtkIO
)

# Need to include class headers and the configuration header.
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR})
INCLUDE_DIRECTORIES(${PROJECT_BINARY_DIR})

# Find and load VTK settings.
FIND_PACKAGE(VTK REQUIRED)
INCLUDE(${VTK_USE_FILE})

# Create the executable.
ADD_EXECUTABLE(${PROJECT_NAME} ${sw2kp_SRCS})
TARGET_LINK_LIBRARIES(${PROJECT_NAME} ${sw2kp_LIBS})

INCLUDE(CTest)
ADD_TEST(TestConversion 
  ${EXECUTABLE_OUTPUT_PATH}/sw2kp ${PROJECT_SOURCE_DIR}/SampleSafeWallet.xml SampleKeepass.xml)
