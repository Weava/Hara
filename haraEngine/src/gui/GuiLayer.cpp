#include "GuiLayer.h"

#include "../../vendor/imgui/backends/imgui_impl_opengl3.h"
#include "../../vendor/imgui/imgui.h"
#include "../hpch.h"

namespace Hara {

    GuiLayer::GuiLayer() : Layer("GuiLayer") {}

    GuiLayer::~GuiLayer() {}

    void GuiLayer::onAttach() {
        ImGui::CreateContext();
        ImGui::StyleColorsLight();

        ImGuiIO& io = ImGui::GetIO();
        io.BackendFlags |= ImGuiBackendFlags_HasMouseCursors;
        io.BackendFlags |= ImGuiBackendFlags_HasSetMousePos;

        ImGui_ImplOpenGL3_Init("#version 410");
    }

    void GuiLayer::onDetach() {}

    void GuiLayer::onUpdate() {
        ImGui_ImplOpenGL3_NewFrame();
        ImGui::NewFrame();

        ImGuiIO& io = ImGui::GetIO();

        static bool show = true;
        ImGui::ShowDemoWindow(&show);

        ImGui::Render();
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
    }

    void GuiLayer::onEvent(Event& event) {}
}  // namespace Hara