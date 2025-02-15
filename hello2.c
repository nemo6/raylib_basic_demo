#include "raylib.h"

int main(void)
{

	// int screenWidth = GetMonitorWidth(GetCurrentMonitor());
	// int screenHeight = GetMonitorHeight(GetCurrentMonitor());

	// int screenWidth = GetScreenWidth();
	// int screenHeight = GetScreenHeight();

	const int raylibWindowWidth = 1;
	const int raylibWindowHeight = 1;

	// SetConfigFlags(FLAG_WINDOW_UNDECORATED);
	// SetConfigFlags(FLAG_WINDOW_HIDDEN);

	InitWindow( raylibWindowWidth, raylibWindowHeight, "Hello" );

	float timer = 0.0f;
	bool running = true;
	// SetWindowOpacity(0.1f);
	// char text[] = "Congrats! You created your first window!";
	int fontSize = 20;

	int windowWidth = 600;
	int windowHeight = 600;
	// Color whiteColor = { 255, 255, 255, 255 };

	// Vector2 position = GetWindowPosition();

	char text[20];
	// sprintf( text, "Value: %d,%d", position.x, position.y );
	// sprintf( text, "Value: %d,%d", 5 , 5 );

	// when window move, print new text position

	SetTargetFPS(60);

	Vector2 position;

	Font font = GetFontDefault();

	// int p = position.y - 105;

	while ( /*running*/ /*||*/ !WindowShouldClose() ) {

		timer += GetFrameTime();

		/*if ( timer >= 1.0f && timer <= 1.001f ) {

		}*/

		if( timer >= 0.0f && timer <= 0.1f ){

			SetWindowSize( windowWidth , windowHeight );
			// SetWindowPosition( 0 , 0 );
			// SetWindowPosition( /*position.x + 3*/ (GetScreenWidth()/2) + (windowWidth/2), /*position.y*/ (GetScreenHeight()/2) - (windowHeight/4) );

		}

		/*if ( timer >= 4.0f && timer <= 4.01f ) {
			
			SetWindowPosition( position.x + 15 , position.y + 15 );
			SetWindowSize( windowWidth , windowHeight );

		}*/

		/*if( timer >= 8.0f ) {
			running = false;
		}*/

		BeginDrawing();
		ClearBackground( RAYWHITE );

		position = GetWindowPosition();

		char text1[50];
		char text2[50];
		char text[1024];
		sprintf( text1, "Window Position: (%d, %d)", (int)position.x, (int)position.y );
		sprintf( text2, "Screen Size: (%d, %d)", (int)GetScreenWidth(), (int)GetScreenHeight() );
		sprintf( text, "%s\n\n%s", text1, text2 );

		// int textWidth = MeasureText( text, fontSize );

		Vector2 textSize = MeasureTextEx( font, text, fontSize, 2 );
		int textWidth = textSize.x;
		int textHeight = textSize.y;

		int x = ( GetScreenWidth() - textWidth ) / 2;
		int y = ( GetScreenHeight() - textHeight ) / 2;

		/*char blob[1024];
		sprintf( blob, "( %d,%d )", textWidth, textHeight );*/

		// DrawText( text , 190, 200, 20, LIGHTGRAY);
		// DrawText( text, x, GetScreenHeight() / 2 - fontSize / 2, fontSize, LIGHTGRAY );
		DrawText( text, x, ( GetScreenHeight() - textHeight ) / 2 - fontSize / 2 , fontSize, LIGHTGRAY );

		EndDrawing();

	}

	CloseWindow();

	return 0;

}
