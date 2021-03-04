
#ifndef SANDBOX_DEFERRED_RENDERING_H
#define SANDBOX_DEFERRED_RENDERING_H

#include <framework/scene.h>
#include <framework/buffer/fbo.h>

namespace Sandbox {

    class SceneDeferredRendering : public Scene {
        public:
            SceneDeferredRendering(int width, int height);
            ~SceneDeferredRendering() override;

        protected:
            void OnInit() override;

            void OnUpdate(float dt) override;

            void OnPreRender() override;
            void OnRender() override;
            void OnPostRender() override;

            void OnImGui() override;

            void OnShutdown() override;

        private:
            void InitializeShaders();
            void InitializeTextures();
            void InitializeMaterials();
            void ConfigureModels();
            void ConstructFBO();

            void RenderWithShader(Shader* shaderProgram);

            FrameBufferObject _fbo;
    };

}

#endif //SANDBOX_DEFERRED_RENDERING_H
