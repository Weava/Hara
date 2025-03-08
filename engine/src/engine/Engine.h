#ifndef ENGINE_H
#define ENGINE_H

namespace GameEngine {
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
}  // namespace GameEngine
#endif