#include "GuiLayer.h"

#include "../../vendor/imgui/imgui.h"
#include "../../vendor/imgui/imgui_impl_glfw.h"
#include "../../vendor/imgui/imgui_impl_opengl3.h"
#include "../core/Log.h"
#include "../hpch.h"
#include "GLFW/glfw3.h"

namespace Hara {

    float currentTime = 0.0f;

    GuiLayer::GuiLayer() : Layer("GuiLayer") {}

    GuiLayer::~GuiLayer() {}

    void GuiLayer::onAttach() {
        IMGUI_CHECKVERSION();
        ImGui::CreateContext();
        ImGui::StyleColorsDark();

        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        ImGui_ImplOpenGL3_Init("#version 410 core");
    }

    void GuiLayer::onDetach() {}

    void GuiLayer::onUpdate() {
        ImGuiIO& io = ImGui::GetIO();
        io.DisplaySize = ImVec2(1280, 720);

        float time = (float)glfwGetTime();
        io.DeltaTime =
            currentTime > 0.0f ? (time - currentTime) : (1.0f / 60.0f);
        currentTime = time;

        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);
        auto lol = ImGui::GetCurrentContext();

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void GuiLayer::onEvent(Event& event) {}
}  // namespace Hara