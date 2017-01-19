# Copyright (C) 2016, The Android Open Source Project
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#     http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

LOCAL_PATH := $(call my-dir)

include $(CLEAR_VARS)
LOCAL_MODULE := android.hardware.drm.crypto@1.0-impl
LOCAL_MODULE_RELATIVE_PATH := hw
LOCAL_SRC_FILES := \
    CryptoFactory.cpp \
    CryptoPlugin.cpp \
    TypeConvert.cpp \

LOCAL_SHARED_LIBRARIES := \
    libhidlbase \
    libhidltransport \
    libhwbinder \
    libhidlmemory \
    libutils \
    liblog \
    libmediadrm \
    libstagefright_foundation \
    android.hardware.drm.crypto@1.0 \
    android.hidl.memory@1.0 \

LOCAL_C_INCLUDES := \
    frameworks/native/include \
    frameworks/av/include

# TODO: The legacy DRM plugins only support 32-bit. They need
# to be migrated to 64-bit (b/18948909)
LOCAL_32_BIT_ONLY := true


include $(BUILD_SHARED_LIBRARY)
