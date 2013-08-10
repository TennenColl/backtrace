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

#include <memory>
#include <thread>

#include "root.hpp"
#include "scenemanager/scenemanager.hpp"
#include "rendertarget/screen/sdlscreen/sdlscreen.hpp"
#include "rendertarget/screen/sdlscreen/sdlscreen.cpp"
#include "object/primitive/sphere.hpp"
#include "object/primitive/plane.hpp"
#include "raytracer/simple.hpp"
#include "sampler/jittered.hpp"

using namespace backtrace;

int main()
{
    Root root(new SceneManager(),
        new SDLScreen(640, 480, 32, false),
        new SimpleRayTracer(),
        new JitteredSampler()
        );

    auto sphere = root.sceneManager->addObject<Sphere>();
    sphere->setColor(RGBColor(1, 0, 0));
    sphere->mCenter = (0, 0.5, 0);

    sphere = root.sceneManager->addObject<Sphere>();
    sphere->setColor(RGBColor(1, 1, 0));
    sphere->mCenter = (0, 0, 0.5);

    root.renderSceneOrthographic();

    root.renderTarget->update();

    std::chrono::milliseconds dura(2000);
    std::this_thread::sleep_for(dura);
}
