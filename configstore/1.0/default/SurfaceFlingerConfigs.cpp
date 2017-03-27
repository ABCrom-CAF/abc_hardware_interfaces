#include "SurfaceFlingerConfigs.h"

#include <android-base/logging.h>

namespace android {
namespace hardware {
namespace configstore {
namespace V1_0 {
namespace implementation {

// Methods from ::android::hardware::configstore::V1_0::ISurfaceFlingerConfigs follow.
Return<void> SurfaceFlingerConfigs::vsyncEventPhaseOffsetNs(vsyncEventPhaseOffsetNs_cb _hidl_cb) {
#ifdef VSYNC_EVENT_PHASE_OFFSET_NS
    _hidl_cb({true, VSYNC_EVENT_PHASE_OFFSET_NS});
    LOG(INFO) << "vsync event phase offset ns =  " << VSYNC_EVENT_PHASE_OFFSET_NS;
#else
    _hidl_cb({false, 0});
#endif
    return Void();
}

Return<void> SurfaceFlingerConfigs::vsyncSfEventPhaseOffsetNs(vsyncEventPhaseOffsetNs_cb _hidl_cb) {
#ifdef SF_VSYNC_EVENT_PHASE_OFFSET_NS
    _hidl_cb({true, SF_VSYNC_EVENT_PHASE_OFFSET_NS});
    LOG(INFO) << "sfvsync event phase offset ns =  " << SF_VSYNC_EVENT_PHASE_OFFSET_NS;
#else
    _hidl_cb({false, 0});
#endif
    return Void();
}

Return<void> SurfaceFlingerConfigs::useContextPriority(useContextPriority_cb _hidl_cb) {
#ifdef USE_CONTEXT_PRIORITY
    _hidl_cb({true, USE_CONTEXT_PRIORITY});
    LOG(INFO) << "SurfaceFlinger useContextPriority=" << USE_CONTEXT_PRIORITY;
#else
    _hidl_cb({false, false});
#endif
    return Void();
}

Return<void> SurfaceFlingerConfigs::maxFrameBufferAcquiredBuffers(maxFrameBufferAcquiredBuffers_cb _hidl_cb) {
#ifdef NUM_FRAMEBUFFER_SURFACE_BUFFERS
    _hidl_cb({true, NUM_FRAMEBUFFER_SURFACE_BUFFERS});
    LOG(INFO) << "SurfaceFlinger FrameBuffer max acquired buffers : " << NUM_FRAMEBUFFER_SURFACE_BUFFERS;
#else
    _hidl_cb({false, 0});
#endif
    return Void();
}

Return<void> SurfaceFlingerConfigs::hasWideColorDisplay(hasWideColorDisplay_cb _hidl_cb) {
    bool value = false;
#ifdef HAS_WIDE_COLOR_DISPLAY
    value = true;
#endif
    _hidl_cb({true, value});
    LOG(INFO) << "SurfaceFlinger Display: " << (value ? "Wide Color" : "Standard Color");
    return Void();
}

Return<void> SurfaceFlingerConfigs::hasSyncFramework(hasSyncFramework_cb _hidl_cb) {
    bool value = true;
#ifdef RUNNING_WITHOUT_SYNC_FRAMEWORK
    value = false;
#endif
    _hidl_cb({true, value});
    LOG(INFO) << "SurfaceFlinger hasSyncFramework: " << value;
    return Void();
}

Return<void> SurfaceFlingerConfigs::hasHDRDisplay(hasHDRDisplay_cb _hidl_cb) {
    bool value = false;
#ifdef HAS_HDR_DISPLAY
    value = true;
#endif
    _hidl_cb({true, value});
    LOG(INFO) << "SurfaceFlinger Display: " << (value ? "HDR" : "SDR");
    return Void();
}

Return<void> SurfaceFlingerConfigs::presentTimeOffsetFromVSyncNs(presentTimeOffsetFromVSyncNs_cb _hidl_cb) {
#ifdef PRESENT_TIME_OFFSET_FROM_VSYNC_NS
      _hidl_cb({true, PRESENT_TIME_OFFSET_FROM_VSYNC_NS});
      LOG(INFO) << "SurfaceFlinger presentTimeStampOffsetNs =  " << PRESENT_TIME_OFFSET_FROM_VSYNC_NS;
#else
      _hidl_cb({false, 0});
#endif
      return Void();
}

Return<void> SurfaceFlingerConfigs::useHwcForRGBtoYUV(useHwcForRGBtoYUV_cb _hidl_cb) {
    bool value = false;
#ifdef FORCE_HWC_COPY_FOR_VIRTUAL_DISPLAYS
    value = true;
#endif
    _hidl_cb({true, value});
    LOG(INFO) << "SurfaceFlinger forceHwcForRGBtoYUV: " << value;
    return Void();
}

Return<void> SurfaceFlingerConfigs::maxVirtualDisplaySize(maxVirtualDisplaySize_cb _hidl_cb) {
  uint64_t maxSize = 0;
#ifdef MAX_VIRTUAL_DISPLAY_DIMENSION
  maxSize = MAX_VIRTUAL_DISPLAY_DIMENSION;
  _hidl_cb({true, maxSize});
  LOG(INFO) << "SurfaceFlinger MaxVirtualDisplaySize: " << maxSize;
#else
  _hidl_cb({false, maxSize});
#endif
  return Void();
}

Return<void> SurfaceFlingerConfigs::useVrFlinger(useVrFlinger_cb _hidl_cb) {
    bool value = false;
    bool specified = false;
#ifdef USE_VR_FLINGER
    value = true;
    specified = true;
#endif
    _hidl_cb({specified, value});
    LOG(INFO) << "SurfaceFlinger UseVrFlinger: " << (value ? "true" : "false");
    return Void();
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace configstore
}  // namespace hardware
}  // namespace android
