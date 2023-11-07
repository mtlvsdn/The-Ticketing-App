# Install script for directory: C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files (x86)/libharu")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE FILE FILES
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_types.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_consts.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_annotation.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_catalog.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_conf.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_destination.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_doc.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_encoder.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_encrypt.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_encryptdict.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_error.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_ext_gstate.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_font.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_fontdef.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_gstate.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_image.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_info.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_list.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_mmgr.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_namedict.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_objects.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_outline.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_pages.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_page_label.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_streams.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_u3d.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_utils.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_pdfa.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_3dmeasure.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_exdata.h"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/include/hpdf_version.h"
    "C:/MATEI/ASE/ANUL 2/POO/The Ticketing App/build/build/include/hpdf_config.h"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/libharu" TYPE FILE FILES
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/README.md"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/CHANGES"
    "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/INSTALL"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Unspecified" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/libharu" TYPE DIRECTORY FILES "C:/Users/Matei/Downloads/libharu-libharu-v2.4.4-0-g0c598be/libharu-libharu-0c598be/bindings")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/MATEI/ASE/ANUL 2/POO/The Ticketing App/build/build/src/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "C:/MATEI/ASE/ANUL 2/POO/The Ticketing App/build/build/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
