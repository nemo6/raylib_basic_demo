timer += GetFrameTime(); // float timer = 0.0f;
int counter_timer = (int)timer;

if ( counter_timer >= 10 ) {
    sprintf( text, "hello" );
}else{
    sprintf( text, "%d", counter_timer );
}

Vector2 textSize = MeasureTextEx( font, text, fontSize, 2 );
int textWidth = textSize.x;
int textHeight = textSize.y;
int x = ( GetScreenWidth() - textWidth ) / 2;
int y = ( GetScreenHeight() - textHeight ) / 2;

DrawText( text, x, ( GetScreenHeight() - textHeight ) / 2 - fontSize / 2 , fontSize, BLACK );
