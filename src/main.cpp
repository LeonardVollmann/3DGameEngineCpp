#include "engine/core/core_engine.h"
#include "engine/rendering/window.h"
#include "engine/rendering/rendering_engine.h"
#include "game/test_game.h"

int main(int argc, const char * argv[]) {
    Window window = Window("3D Game Engine", 800, 600);
    RenderingEngine renderingEngine = RenderingEngine();
	TestGame game = TestGame();
    CoreEngine engine = CoreEngine(60, &window, &renderingEngine, &game);
    engine.start();
    return 0;
}
