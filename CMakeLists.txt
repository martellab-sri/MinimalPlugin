PROJECT( testPlugin )
CMAKE_MINIMUM_REQUIRED( VERSION 3.8 )
#Enable C++17 features
SET(CMAKE_CXX_STANDARD 17)

# Load the Sedeen dependencies
SET(PROGRAMFILESX86 "PROGRAMFILES\(X86\)")
FIND_PACKAGE( SEDEENSDK REQUIRED 
                HINTS ../../.. 
				   "$ENV{${PROGRAMFILESX86}}/Sedeen Viewer SDK/v5.4.0.20181217/msvc2017"
                   "$ENV{PROGRAMFILES}/Sedeen Viewer SDK/v5.4.0.20181217/msvc2017" )

INCLUDE_DIRECTORIES( "${SEDEENSDK_INCLUDE_DIR}" )
LINK_DIRECTORIES( "${SEDEENSDK_LIBRARY_DIR}" )

#Build the code into a module library
ADD_LIBRARY( ${PROJECT_NAME} MODULE ${PROJECT_NAME}.cpp ${PROJECT_NAME}.h )

#Link the library against the Sedeen libraries
TARGET_LINK_LIBRARIES( ${PROJECT_NAME} ${SEDEENSDK_LIBRARIES} )

# Set the install destination directory
IF(NOT PLUGIN_DESTINATION_DIR)
  IF( ${SEDEEN_FOUND} )
    SET(PLUGIN_DESTINATION_DIR "${PATHCORE_DIR}/plugins/cpp/piip/${PROJECT_NAME}" CACHE PATH "Installation directory for the plugin within a Sedeen Viewer directory")
  ELSE()
    SET(PLUGIN_DESTINATION_DIR "PLUGIN_DESTINATION_DIR-NOTFOUND" CACHE PATH "Installation directory for the plugin within a Sedeen Viewer directory")
  ENDIF()
ENDIF()

# Install the plugin in the PLUGIN_DESTINATION_DIR directory
IF( ${SEDEEN_FOUND} )
  install(TARGETS ${PROJECT_NAME}
          LIBRARY DESTINATION "${PLUGIN_DESTINATION_DIR}")
ENDIF()