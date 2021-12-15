set("CPACK_COMPONENT_LIBRARY_DESCRIPTION" "A library for looking up strings in gettext mo files.")

buildAndPackageLib("${FORMAT_NAME}"
	TARGET_NAME_WITH_LIB_PREFIX
	COMPONENT "library"
	DESCRIPTION "A library for looking up strings in gettext mo files."
	PUBLIC_INCLUDES ${Include_dir}
	PRIVATE_INCLUDES ${kaitai_include_dir}
)

file(GLOB kaitai_sources "${kaitai_source_dir}/*.c" "${kaitai_source_dir}/*.cc" "${kaitai_source_dir}/*.cpp" "${kaitai_source_dir}/*.cxx" "${kaitai_source_dir}/*.c++")
target_sources("${PROJECT_NAME}" PRIVATE ${kaitai_sources})
target_compile_definitions("${PROJECT_NAME}" PRIVATE "-DKS_STR_ENCODING_NONE")
