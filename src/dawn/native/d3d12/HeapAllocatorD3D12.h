// Copyright 2019 The Dawn Authors
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

#ifndef SRC_DAWN_NATIVE_D3D12_HEAPALLOCATORD3D12_H_
#define SRC_DAWN_NATIVE_D3D12_HEAPALLOCATORD3D12_H_

#include "dawn/native/D3D12Backend.h"
#include "dawn/native/ResourceHeapAllocator.h"
#include "dawn/native/d3d12/d3d12_platform.h"

namespace dawn::native::d3d12 {

    class Device;

    // Wrapper to allocate a D3D12 heap.
    class HeapAllocator : public ResourceHeapAllocator {
      public:
        HeapAllocator(Device* device,
                      D3D12_HEAP_TYPE heapType,
                      D3D12_HEAP_FLAGS heapFlags,
                      MemorySegment memorySegment);
        ~HeapAllocator() override = default;

        ResultOrError<std::unique_ptr<ResourceHeapBase>> AllocateResourceHeap(
            uint64_t size) override;
        void DeallocateResourceHeap(std::unique_ptr<ResourceHeapBase> allocation) override;

      private:
        Device* mDevice;
        D3D12_HEAP_TYPE mHeapType;
        D3D12_HEAP_FLAGS mHeapFlags;
        MemorySegment mMemorySegment;
    };

}  // namespace dawn::native::d3d12

#endif  // SRC_DAWN_NATIVE_D3D12_HEAPALLOCATORD3D12_H_
