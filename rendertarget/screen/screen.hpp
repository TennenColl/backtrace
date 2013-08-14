/*
 * Copyright 2013 TennenColl
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef BACKTRACE_RENDERTARGET_SCREEN_HPP
#define BACKTRACE_RENDERTARGET_SCREEN_HPP

#include "../rendertarget.hpp"

namespace backtrace {

class Screen : public RenderTarget
{
protected:
    float mAspectRatio;
    float mGamma;
    float mInvGamma;

public:
    Screen(uint32_t width, uint32_t height, uint8_t colorDepth, float gamma = 1.0f)
        : RenderTarget(width, height, colorDepth),
        mAspectRatio(static_cast<float>(width) / static_cast<float>(height)),
        mGamma(gamma),
        mInvGamma(1.0 / gamma)
    {
    }

    void setGamma(float gamma)
    {
        mGamma = gamma;
        mInvGamma = 1.0f / gamma;
    }

    float getGamma() { return mGamma; }
    float getInvGamma() { return mInvGamma; }

    float getAspectRatio() { return mAspectRatio; }
    // void setAspectRatio(float ratio) { mAspectRatio = ratio; }

    virtual void update(uint32_t x, uint32_t y, uint32_t width, uint32_t height) {}

    void update()
    {
        update(0, 0, mWidth, mHeight);
    }
    
    virtual ~Screen() {};
};

}

#endif
