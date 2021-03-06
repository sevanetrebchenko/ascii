
#ifndef SANDBOX_WINDOW_H
#define SANDBOX_WINDOW_H

#include <sandbox_pch.h>

namespace Sandbox {

    class Window {
        public:
            Window(std::string name, int width, int height);
            ~Window();

            void PollEvents();
            void SwapBuffers();
            bool IsActive();

            [[nodiscard]] GLFWwindow* GetNativeWindow() const;

            [[nodiscard]] int GetWidth() const;
            [[nodiscard]] int GetHeight() const;
            [[nodiscard]] const std::string& GetName() const;

        private:
            void InitializeGLFW();
            void CreateGLFWWindow();
            void SetupGLFWCallbacks();
            void InitializeOpenGLContext();
            void InitializeImGui();

            // Window data.
            GLFWwindow* _window;
            std::string _name;
            int _width;
            int _height;
    };

}

#endif // SANDBOX_WINDOW_H
