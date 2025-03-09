#pragma once

#include "core/Application.h"
#include "core/Log.h"

extern Hara::Application* Hara::createApplication();

int main(int argc, char** argv) {
    Hara::Log::init();
    auto app = Hara::createApplication();
    app->run();
    delete app;
}