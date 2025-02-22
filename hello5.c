#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "raylib.h"

int add( int a, int b, int c ) {
	int result;
	result = a + b;
	c += 1;
	return result;
}

int counter_rgb = 0;
Color fontColor = { 255, 255, 255, 255 };

char array_COLOR[7][10] = { "RED", "RED","BLUE","BLUE","VERT","JAUNE","RED" };

void clamp_color( Color *BackgroundColor, Color *fontColor ) {

	if ( BackgroundColor -> r == 255 && counter_rgb == 0 ){
		counter_rgb=1;
		/*fontColor->r = 255;
		fontColor->g = 0;
		fontColor->b = 0;
		fontColor->a = 255;*/
	}

	if ( BackgroundColor -> b == 255 && counter_rgb == 1 ){
		counter_rgb=2;
	}

	if ( BackgroundColor -> r == 0 && counter_rgb == 2 ){
		counter_rgb=3;
	}

	if ( BackgroundColor -> g == 255 && counter_rgb == 3 ){
		counter_rgb=4;
	}

	if ( BackgroundColor -> b == 0 && counter_rgb == 4 ){
		counter_rgb=5;
	}

	if ( BackgroundColor -> r == 255 && counter_rgb == 5 ){
		counter_rgb=6;
	}

	if ( BackgroundColor -> g == 0 && counter_rgb == 6 ){
		counter_rgb=1;
	}

	//

	if ( BackgroundColor -> r < 255 && counter_rgb == 0 ){

		BackgroundColor -> r += 15;

		fontColor->r -= 15;
		fontColor->g -= 15;
		fontColor->b -= 15;
		// fontColor->a += 15;

	}

	if ( BackgroundColor -> b < 255 && counter_rgb == 1 ) {
		BackgroundColor -> b += 15;
	}

	if ( BackgroundColor -> r > 0 && counter_rgb == 2 ) {
		BackgroundColor -> r -= 15;
	}

	if ( BackgroundColor -> g < 255 && counter_rgb == 3 ) {
		BackgroundColor -> g += 15;
	}

	if ( BackgroundColor -> b > 0 && counter_rgb == 4 ) {
		BackgroundColor -> b -= 15;
	}

	if ( BackgroundColor -> r < 255 && counter_rgb == 5 ) {
		BackgroundColor -> r += 15;
	}

	if ( BackgroundColor -> g > 0 && counter_rgb == 6 ) {
		BackgroundColor -> g -= 15;
	}

}

/*
R+ 0 BLACK
B+ 1 RED
R- 2 ROSE
G+ 3 BLUE
B- 4 VERT
R+ 5 JAUNE
G- 6 RED
*/

char* padding( char* c, int numSpaces ) {
    int length = strlen(c);
    char* result = (char*) malloc((numSpaces * 2 + length + 1) * sizeof(char));
    strcpy(result, "");
    for (int i = 0; i < numSpaces; i++) {
        strcat(result, " ");
    }
    strcat(result, c);
    for (int i = 0; i < numSpaces; i++) {
        strcat(result, " ");
    }
    return result;
}

int main(void)
{

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
	int fontSize = 30;

	Font font = GetFontDefault();

	Color BackgroundColor = { 0, 0, 0, 0 };

	int counter_timer = 0;

	float tick = 2.0;

	// sprintf( text, "Value: %d,%d", position.x, position.y );
	// sprintf( text, "Value: %d,%d", 5 , 5 );

	SetTargetFPS(60);

	Vector2 position;

	// int p = position.y - 105;

	char text1[150];
	char text2[150];
	char text3[150];
	char text[1024];

	float counter_opacity = 0.0f;

	SetWindowOpacity( counter_opacity );

	while ( /*running*/ /*||*/ !WindowShouldClose() ) {

		timer += GetFrameTime();
		timer2 += GetFrameTime();

		counter_timer = (int)timer;

		/*if ( counter_timer >= 5 ) {
			sprintf( text, "hello!" );
		}else{
			sprintf( text, "%d", counter_timer );
		}*/

		if ( counter_timer == 0 ){
			SetWindowSize( windowWidth , windowHeight );
			position = GetWindowPosition();
			SetWindowPosition( screenWidth/2-(windowWidth/2) , screenHeight/2-(windowHeight/2) );
		}

		if( timer <= 5.0f ){
			
			counter_opacity += 0.1f;
			SetWindowOpacity(counter_opacity);

		}

		if( timer2 >= 0.01 && timer2 <= 0.02 ){
			clamp_color( &BackgroundColor, &fontColor );
		}

		if( timer2 >= 0.05 )
		timer2 = 0.0f;

		/*position = GetWindowPosition();
		sprintf( text1, "Window Position: (%d, %d)", (int)position.x, (int)position.y );
		sprintf( text2, "Window size: (%d, %d)", windowWidth, windowHeight );
		sprintf( text3, "Screen size : (%d, %d)", screenWidth, screenHeight );
		sprintf( text3, "add: (%d)", n );
		sprintf( text, "%s\n\n%s\n\n%s", text1, text2, text3 );

		Vector2 textSize = MeasureTextEx( font, text, fontSize, 2 );
		int textWidth = textSize.x;
		int textHeight = textSize.y;
		int x = ( GetScreenWidth() - textWidth ) / 2;
		int y = ( GetScreenHeight() - textHeight ) / 2;*/

		// sprintf( text1, "( %d )", counter_rgb );
		sprintf( text1, "%s", array_COLOR[counter_rgb] );
		sprintf( text2, "( %d, %d, %d )", BackgroundColor.r, BackgroundColor.g, BackgroundColor.b );

		// sprintf( text, "%s\n\n%s", text1, text2 );

		Vector2 textSize1 = MeasureTextEx( font, text1, fontSize, 2 );
		int textWidth1 = textSize1.x;
		int textHeight1 = textSize1.y;
		int x1 = ( GetScreenWidth() - textWidth1 ) / 2;
		int y1 = ( GetScreenHeight() - textHeight1 ) / 2;

		Vector2 textSize2 = MeasureTextEx( font, text2, fontSize, 2 );
		int textWidth2 = textSize2.x;
		int textHeight2 = textSize2.y;
		int x2 = ( GetScreenWidth() - textWidth2 ) / 2;
		int y2 = ( GetScreenHeight() - textHeight2 ) / 2;

		DrawText( text1, x1, ((( GetScreenHeight() - textHeight1 ) / 2 - fontSize / 2) - 45) + (45/2)  , fontSize, fontColor );
		DrawText( text2, x2, (( GetScreenHeight() - textHeight2 ) / 2 - fontSize / 2) + (45/2) , fontSize, fontColor );

		BeginDrawing();
		ClearBackground( BackgroundColor );

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
