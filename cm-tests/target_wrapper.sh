#!/bin/sh
DYLD_FRAMEWORK_PATH=/Users/Peter/Qt5.12.0/5.12.0/clang_64/lib${DYLD_FRAMEWORK_PATH:+:$DYLD_FRAMEWORK_PATH}
export DYLD_FRAMEWORK_PATH
QT_PLUGIN_PATH=/Users/Peter/Qt5.12.0/5.12.0/clang_64/plugins${QT_PLUGIN_PATH:+:$QT_PLUGIN_PATH}
export QT_PLUGIN_PATH
exec "$@"
