// Copyright 2018 The Dawn Authors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#ifndef SRC_DAWN_NATIVE_D3D12_NATIVESWAPCHAINIMPLD3D12_H_
#define SRC_DAWN_NATIVE_D3D12_NATIVESWAPCHAINIMPLD3D12_H_

#include "dawn/native/d3d12/d3d12_platform.h"

#include "dawn/dawn_wsi.h"
#include "dawn/native/IntegerTypes.h"
#include "dawn/native/dawn_platform.h"

#include <vector>

namespace dawn::native::d3d12 {

    class Device;

    class NativeSwapChainImpl {
      public:
        using WSIContext = DawnWSIContextD3D12;

        NativeSwapChainImpl(Device* device, HWND window);
        ~NativeSwapChainImpl();

        void Init(DawnWSIContextD3D12* context);
        DawnSwapChainError Configure(WGPUTextureFormat format,
                                     WGPUTextureUsage,
                                     uint32_t width,
                                     uint32_t height);
        DawnSwapChainError GetNextTexture(DawnSwapChainNextTexture* nextTexture);
        DawnSwapChainError Present();

        wgpu::TextureFormat GetPreferredFormat() const;

      private:
        HWND mWindow = nullptr;
        Device* mDevice = nullptr;
        UINT mInterval;

        ComPtr<IDXGISwapChain3> mSwapChain = nullptr;
        std::vector<ComPtr<ID3D12Resource>> mBuffers;
        std::vector<ExecutionSerial> mBufferSerials;
        uint32_t mCurrentBuffer;
    };

}  // namespace dawn::native::d3d12

#endif  // SRC_DAWN_NATIVE_D3D12_NATIVESWAPCHAINIMPLD3D12_H_
