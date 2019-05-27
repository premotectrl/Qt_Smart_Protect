# Refer to A PDF: LEarn Qt 5 Build modern, responsive cross-platform
#desktop applications with Qt, C++ andQML by   Nicholas Sherriff

platform_path = unkown-path
compiler_path = unkown-compiler
processor-path = unkown-processor
build-path = unkown-build

PLATFORM_OSX {
    platform_path = osx
}

PLATFORM_LINUX {
    platform_path = linux
}

COMPILER_GCC {
    compiler_path = gcc
}

COMPILER_CLANG {
    compiler_path = clang
}

PROCESSOR_x86 {
    processor_path = x86
}

PROCESSOR_x64 {
    processor_path = x64
}

BUILD_DEBUG {
    build_path = debug
}else {
    build_path = release
}

DESTINATION_PATH = $$platform_path/$$compiler_path/$$processor_path/$$build_path
message(DEST path: $${DESTINATION_PATH})
