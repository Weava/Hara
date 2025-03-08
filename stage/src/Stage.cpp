#include "Hara.h"

class Stage : public Hara::Application {
   public:
    Stage() {}
    ~Stage() {}
};

int main() {
    Stage* stage = new Stage();
    stage->run();
    delete stage;
};