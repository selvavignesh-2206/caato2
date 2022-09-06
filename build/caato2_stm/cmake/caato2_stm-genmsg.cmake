# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "caato2_stm: 2 messages, 3 services")

set(MSG_I_FLAGS "-Icaato2_stm:/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg;-Igeometry_msgs:/opt/ros/noetic/share/geometry_msgs/cmake/../msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg;-Iactionlib_msgs:/opt/ros/noetic/share/actionlib_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(caato2_stm_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/caato_state.msg" NAME_WE)
add_custom_target(_caato2_stm_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "caato2_stm" "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/caato_state.msg" ""
)

get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/navigation_state.msg" NAME_WE)
add_custom_target(_caato2_stm_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "caato2_stm" "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/navigation_state.msg" ""
)

get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/change_robot_state.srv" NAME_WE)
add_custom_target(_caato2_stm_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "caato2_stm" "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/change_robot_state.srv" ""
)

get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_sequence.srv" NAME_WE)
add_custom_target(_caato2_stm_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "caato2_stm" "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_sequence.srv" ""
)

get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_goal.srv" NAME_WE)
add_custom_target(_caato2_stm_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "caato2_stm" "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_goal.srv" "geometry_msgs/Pose:geometry_msgs/Point:geometry_msgs/Quaternion"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/caato_state.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/caato2_stm
)
_generate_msg_cpp(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/navigation_state.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/caato2_stm
)

### Generating Services
_generate_srv_cpp(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/change_robot_state.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/caato2_stm
)
_generate_srv_cpp(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_sequence.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/caato2_stm
)
_generate_srv_cpp(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_goal.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/caato2_stm
)

### Generating Module File
_generate_module_cpp(caato2_stm
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/caato2_stm
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(caato2_stm_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(caato2_stm_generate_messages caato2_stm_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/caato_state.msg" NAME_WE)
add_dependencies(caato2_stm_generate_messages_cpp _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/navigation_state.msg" NAME_WE)
add_dependencies(caato2_stm_generate_messages_cpp _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/change_robot_state.srv" NAME_WE)
add_dependencies(caato2_stm_generate_messages_cpp _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_sequence.srv" NAME_WE)
add_dependencies(caato2_stm_generate_messages_cpp _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_goal.srv" NAME_WE)
add_dependencies(caato2_stm_generate_messages_cpp _caato2_stm_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(caato2_stm_gencpp)
add_dependencies(caato2_stm_gencpp caato2_stm_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS caato2_stm_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/caato_state.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/caato2_stm
)
_generate_msg_eus(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/navigation_state.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/caato2_stm
)

### Generating Services
_generate_srv_eus(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/change_robot_state.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/caato2_stm
)
_generate_srv_eus(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_sequence.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/caato2_stm
)
_generate_srv_eus(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_goal.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/caato2_stm
)

### Generating Module File
_generate_module_eus(caato2_stm
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/caato2_stm
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(caato2_stm_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(caato2_stm_generate_messages caato2_stm_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/caato_state.msg" NAME_WE)
add_dependencies(caato2_stm_generate_messages_eus _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/navigation_state.msg" NAME_WE)
add_dependencies(caato2_stm_generate_messages_eus _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/change_robot_state.srv" NAME_WE)
add_dependencies(caato2_stm_generate_messages_eus _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_sequence.srv" NAME_WE)
add_dependencies(caato2_stm_generate_messages_eus _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_goal.srv" NAME_WE)
add_dependencies(caato2_stm_generate_messages_eus _caato2_stm_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(caato2_stm_geneus)
add_dependencies(caato2_stm_geneus caato2_stm_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS caato2_stm_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/caato_state.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/caato2_stm
)
_generate_msg_lisp(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/navigation_state.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/caato2_stm
)

### Generating Services
_generate_srv_lisp(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/change_robot_state.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/caato2_stm
)
_generate_srv_lisp(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_sequence.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/caato2_stm
)
_generate_srv_lisp(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_goal.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/caato2_stm
)

### Generating Module File
_generate_module_lisp(caato2_stm
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/caato2_stm
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(caato2_stm_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(caato2_stm_generate_messages caato2_stm_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/caato_state.msg" NAME_WE)
add_dependencies(caato2_stm_generate_messages_lisp _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/navigation_state.msg" NAME_WE)
add_dependencies(caato2_stm_generate_messages_lisp _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/change_robot_state.srv" NAME_WE)
add_dependencies(caato2_stm_generate_messages_lisp _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_sequence.srv" NAME_WE)
add_dependencies(caato2_stm_generate_messages_lisp _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_goal.srv" NAME_WE)
add_dependencies(caato2_stm_generate_messages_lisp _caato2_stm_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(caato2_stm_genlisp)
add_dependencies(caato2_stm_genlisp caato2_stm_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS caato2_stm_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/caato_state.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/caato2_stm
)
_generate_msg_nodejs(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/navigation_state.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/caato2_stm
)

### Generating Services
_generate_srv_nodejs(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/change_robot_state.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/caato2_stm
)
_generate_srv_nodejs(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_sequence.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/caato2_stm
)
_generate_srv_nodejs(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_goal.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/caato2_stm
)

### Generating Module File
_generate_module_nodejs(caato2_stm
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/caato2_stm
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(caato2_stm_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(caato2_stm_generate_messages caato2_stm_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/caato_state.msg" NAME_WE)
add_dependencies(caato2_stm_generate_messages_nodejs _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/navigation_state.msg" NAME_WE)
add_dependencies(caato2_stm_generate_messages_nodejs _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/change_robot_state.srv" NAME_WE)
add_dependencies(caato2_stm_generate_messages_nodejs _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_sequence.srv" NAME_WE)
add_dependencies(caato2_stm_generate_messages_nodejs _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_goal.srv" NAME_WE)
add_dependencies(caato2_stm_generate_messages_nodejs _caato2_stm_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(caato2_stm_gennodejs)
add_dependencies(caato2_stm_gennodejs caato2_stm_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS caato2_stm_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/caato_state.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/caato2_stm
)
_generate_msg_py(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/navigation_state.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/caato2_stm
)

### Generating Services
_generate_srv_py(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/change_robot_state.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/caato2_stm
)
_generate_srv_py(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_sequence.srv"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/caato2_stm
)
_generate_srv_py(caato2_stm
  "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_goal.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/caato2_stm
)

### Generating Module File
_generate_module_py(caato2_stm
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/caato2_stm
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(caato2_stm_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(caato2_stm_generate_messages caato2_stm_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/caato_state.msg" NAME_WE)
add_dependencies(caato2_stm_generate_messages_py _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/msg/navigation_state.msg" NAME_WE)
add_dependencies(caato2_stm_generate_messages_py _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/change_robot_state.srv" NAME_WE)
add_dependencies(caato2_stm_generate_messages_py _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_sequence.srv" NAME_WE)
add_dependencies(caato2_stm_generate_messages_py _caato2_stm_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/dimsum/caato2_ws/src/caato2/caato2_stm/srv/navigate_goal.srv" NAME_WE)
add_dependencies(caato2_stm_generate_messages_py _caato2_stm_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(caato2_stm_genpy)
add_dependencies(caato2_stm_genpy caato2_stm_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS caato2_stm_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/caato2_stm)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/caato2_stm
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(caato2_stm_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(caato2_stm_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET actionlib_msgs_generate_messages_cpp)
  add_dependencies(caato2_stm_generate_messages_cpp actionlib_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/caato2_stm)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/caato2_stm
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(caato2_stm_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(caato2_stm_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET actionlib_msgs_generate_messages_eus)
  add_dependencies(caato2_stm_generate_messages_eus actionlib_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/caato2_stm)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/caato2_stm
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(caato2_stm_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(caato2_stm_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET actionlib_msgs_generate_messages_lisp)
  add_dependencies(caato2_stm_generate_messages_lisp actionlib_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/caato2_stm)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/caato2_stm
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(caato2_stm_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(caato2_stm_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET actionlib_msgs_generate_messages_nodejs)
  add_dependencies(caato2_stm_generate_messages_nodejs actionlib_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/caato2_stm)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/caato2_stm\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/caato2_stm
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(caato2_stm_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(caato2_stm_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET actionlib_msgs_generate_messages_py)
  add_dependencies(caato2_stm_generate_messages_py actionlib_msgs_generate_messages_py)
endif()
