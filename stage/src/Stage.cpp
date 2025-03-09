#include "Hara.h"

class Stage : public Hara::Application {
   public:
    Stage() {}
    ~Stage() {}
};

Hara::Application* Hara::createApplication() { return new Stage(); }