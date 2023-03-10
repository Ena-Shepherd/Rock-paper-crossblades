#################################################################################
##
## Thor C++ Library
## Copyright (c) 2011-2022 Jan Haller
##
## This software is provided 'as-is', without any express or implied
## warranty. In no event will the authors be held liable for any damages
## arising from the use of this software.
##
## Permission is granted to anyone to use this software for any purpose,
## including commercial applications, and to alter it and redistribute it
## freely, subject to the following restrictions:
##
## 1. The origin of this software must not be misrepresented; you must not
##    claim that you wrote the original software. If you use this software
##    in a product, an acknowledgment in the product documentation would be
##    appreciated but is not required.
##
## 2. Altered source versions must be plainly marked as such, and must not be
##    misrepresented as being the original software.
##
## 3. This notice may not be removed or altered from any source distribution.
##
#################################################################################

# Directory Thor/src


# C++ source files
set(THOR_SRC
	Action.cpp
	ActionOperations.cpp
	Affectors.cpp
	Arrow.cpp
	BigSprite.cpp
	BigTexture.cpp
	CallbackTimer.cpp
	ColorAnimation.cpp
	ColorGradient.cpp
	ConcaveShape.cpp
	Connection.cpp
	Distributions.cpp
	Emitters.cpp
	FadeAnimation.cpp
	FrameAnimation.cpp
	InputNames.cpp
	Joystick.cpp
	Particle.cpp
	ParticleSystem.cpp
	Random.cpp
	Shapes.cpp
	StopWatch.cpp
	Timer.cpp
	ToString.cpp
	Triangulation.cpp
	Trigonometry.cpp
	UniformAccess.cpp
)


# Library to build
set(THOR_LIB ${PROJECT_NAME})


# Determine library suffixes depending on static/shared configuration
if(THOR_SHARED_LIBS)
	add_library(${THOR_LIB} SHARED ${THOR_SRC})
	set_target_properties(${THOR_LIB} PROPERTIES DEBUG_POSTFIX -d)
else()
	add_definitions(-DSFML_STATIC)
	add_library(${THOR_LIB} STATIC ${THOR_SRC})
	set_target_properties(${THOR_LIB} PROPERTIES DEBUG_POSTFIX -s-d)
	set_target_properties(${THOR_LIB} PROPERTIES RELEASE_POSTFIX -s)
endif()

thor_link_sfml(${THOR_LIB})

# Set IDE folder for main project
set_target_properties(${THOR_LIB} PROPERTIES FOLDER "Thor")


# Install (use "bin" folder for DLL, "lib" for SO files)
if(WIN32)
	install(TARGETS ${THOR_LIB}
			RUNTIME DESTINATION bin
			LIBRARY DESTINATION lib
			ARCHIVE DESTINATION lib)
else()
	install(TARGETS ${THOR_LIB}
			RUNTIME DESTINATION lib
			LIBRARY DESTINATION lib
			ARCHIVE DESTINATION lib)
endif()

if (APPLE)
	set_target_properties(${THOR_LIB} PROPERTIES 
						  BUILD_WITH_INSTALL_RPATH 1 
						  INSTALL_NAME_DIR "@rpath")
endif()
