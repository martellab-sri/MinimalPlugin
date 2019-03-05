PROJECT( testPlugin )
CMAKE_MINIMUM_REQUIRED( VERSION 3.8 )
#Enable C++17 features
SET(CMAKE_CXX_STANDARD 17)

# Load the Sedeen dependencies
SET(PROGRAMFILESX86 "PROGRAMFILES\(X86\)")
FIND_PACKAGE( SEDEENSDK REQUIRED 
                HINTS ../../.. 
				   "$ENV{PROGRAMFILESX86}/Sedeen Viewer SDK/v5.4.0.20181217/msvc2017"
                   "$ENV{PROGRAMFILES}/Sedeen Viewer SDK/v5.4.0.20181217/msvc2017" )

INCLUDE_DIRECTORIES( "${SEDEENSDK_INCLUDE_DIR}" )
LINK_DIRECTORIES( "${SEDEENSDK_LIBRARY_DIR}" )

#Build the code into a module library
ADD_LIBRARY( ${PROJECT_NAME} MODULE ${PROJECT_NAME}.cpp ${PROJECT_NAME}.h )

#Link the library against the Sedeen libraries
TARGET_LINK_LIBRARIES( ${PROJECT_NAME} ${SEDEENSDK_LIBRARIES} )

IF( ${SEDEEN_FOUND} )
  # Install the plugin in the sedeen plugins directory
  SET( PLUGIN_DESTINATION_DIR "D:/mschumaker/projects/Sedeen/testSedeen/Sedeen Viewer/plugins/cpp/piip/${PROJECT_NAME}")
  message("Installation directory set to ${PLUGIN_DESTINATION_DIR}")
  install(TARGETS ${PROJECT_NAME}
          LIBRARY DESTINATION "${PLUGIN_DESTINATION_DIR}")
ENDIF()