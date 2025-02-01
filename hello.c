#include "raylib.h"

int main(void)
{
	const int raylibWindowWidth = 600;
	const int raylibWindowHeight = 600;
	SetConfigFlags(FLAG_WINDOW_UNDECORATED);
	InitWindow( raylibWindowWidth, raylibWindowHeight, "" );
	// SetWindowState(FLAG_WINDOW_UNDECORATED);
	// SetWindowState(FLAG_WINDOW_HIDDEN);

	float timer = 0.0f;
	bool running = true;

	// SetWindowOpacity(0.1f);
	// SetWindowPosition( 0, 0 );
	char text[] = "Press ESC / ECHAP to quit";
	int fontSize = 20;

	// SetWindowPosition( 0, 0 );

	SetTargetFPS(60);
	while ( /*running*/ !WindowShouldClose()) {
		/*timer += GetFrameTime();
		if ( timer >= 5.0f ) {
			running = false;
		}*/
		BeginDrawing();
		ClearBackground(RAYWHITE);

		int textWidth = MeasureText( text, fontSize );
		int x = ( GetScreenWidth() - textWidth ) / 2;

		DrawText( text, x, GetScreenHeight() / 2 - fontSize / 2, fontSize, LIGHTGRAY );

		EndDrawing();
	}

	CloseWindow();

	return 0;
}
