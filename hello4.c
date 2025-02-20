#include "raylib.h"
#include <stdio.h>

int add( int a, int b, int c ) {
	int result;
	result = a + b;
	c += 1;
	return result;
}

int main(void)
{

	int global_count = 0;

	const int raylibWindowWidth = 1;
	const int raylibWindowHeight = 1;

	float timer = 0.0f;
	float timer2 = 0.0f;

	SetConfigFlags( FLAG_WINDOW_UNDECORATED );

	InitWindow( raylibWindowWidth, raylibWindowHeight, "Hello" );

	int screenWidth = GetMonitorWidth(GetCurrentMonitor());
	int screenHeight = GetMonitorHeight(GetCurrentMonitor());

	// int windowWidth = GetScreenWidth();
	// int windowHeight = GetScreenHeight();

	int windowWidth = 600;
	int windowHeight = 600;

	bool running = true;
	// char text[] = "Congrats! You created your first window!";
	int fontSize = 30;

	Color myColor = { 0, 0, 0, 0 };

	int counter_timer = 0;
	int counter_color = 0;

	float tick = 2.0;

	// sprintf( text, "Value: %d,%d", position.x, position.y );
	// sprintf( text, "Value: %d,%d", 5 , 5 );

	SetTargetFPS(60);

	Vector2 position;

	Font font = GetFontDefault();

	// int p = position.y - 105;

	char text1[50];
	char text2[50];
	char text3[50];
	char text[1024];

	float counter_opacity = 0.0f;

	SetWindowOpacity( counter_opacity );

	while ( /*running*/ /*||*/ !WindowShouldClose() ) {

		timer += GetFrameTime();
		timer2 += GetFrameTime();

		counter_timer = (int)timer;
		// counter_color = (int)timer2;

		/*if ( counter_timer >= 5 ) {
			sprintf( text, "hello!" );
		}else{
			sprintf( text, "%d", counter_timer );
		}*/

		sprintf( text, "%d", myColor.r );

		//

		if ( counter_timer == 0 ){
			SetWindowSize( windowWidth , windowHeight );
			position = GetWindowPosition();
			SetWindowPosition( screenWidth/2-(windowWidth/2) , screenHeight/2-(windowHeight/2) );
		}

		// SetWindowPosition( position.x+5 , position.y+5 );

		if( timer <= 5.0f ){
			
			counter_opacity += 0.1f;
			SetWindowOpacity(counter_opacity);

		}

		if( timer2 >= 0.01 && timer2 <= 0.02 )
		myColor.r += 1;

		if( timer2 >= 0.05 )
		timer2 = 0.0f;

		/*int n = add( 5, 5 , global_count );
		position = GetWindowPosition();
		sprintf( text1, "Window Position: (%d, %d)", (int)position.x, (int)position.y );
		sprintf( text2, "Window size: (%d, %d)", windowWidth, windowHeight );
		sprintf( text3, "Screen size : (%d, %d)", screenWidth, screenHeight );
		sprintf( text3, "add: (%d)", n );
		sprintf( text, "%s\n\n%s\n\n%s", text1, text2, text3 );*/

		//

		Vector2 textSize = MeasureTextEx( font, text, fontSize, 2 );
		int textWidth = textSize.x;
		int textHeight = textSize.y;
		int x = ( GetScreenWidth() - textWidth ) / 2;
		int y = ( GetScreenHeight() - textHeight ) / 2;

		//

		DrawText( text, x, ( GetScreenHeight() - textHeight ) / 2 - fontSize / 2 , fontSize, BLUE /*RAYWHITE*/ /*LIGHTGRAY*/ );

		BeginDrawing();
		ClearBackground( myColor /*RAYWHITE*/ /*BLACK*/ );

		/*if( timer >= 8.0f ) {
			running = false;
		}*/

		EndDrawing();

	}

	CloseWindow();

	return 0;

}


/*if ( timer >= 4.0f && timer <= 4.01f ) {
	
	SetWindowPosition( position.x + 15 , position.y + 15 );
	SetWindowSize( windowWidth , windowHeight );

}*/
