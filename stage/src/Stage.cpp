#include "Hara.h"

class ExampleLayer : public Hara::Layer {
   public:
    ExampleLayer() : Layer("Example") {}

    void onUpdate() override { CORE_LOG_INFO("ExampleLayer::onUpdate"); }

    void onEvent(Hara::Event& event) override {
        CORE_LOG_TRACE("{0}", event.toString());
    }
};

class Stage : public Hara::Application {
   public:
    Stage() { pushLayer(new ExampleLayer()); }
    ~Stage() {}
};

Hara::Application* Hara::createApplication() { return new Stage(); }
