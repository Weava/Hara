#ifndef ENGINE_H
#define ENGINE_H

namespace Hara {
    class Engine {
       public:
        void run();

       private:
        bool init();
        void renderLoop();
        void cleanup();

       private:
        bool isRunning = true;
    };
}  // namespace Hara
#endif