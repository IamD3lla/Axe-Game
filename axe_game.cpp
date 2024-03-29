//Libraries that are already built into c++ are included with <>
//External libraries are included using ""
//External libraries also need to be included .h to the statement because it contais the header files
#include "raylib.h"

//Window dimensions
int width = 800, 
    height = 450;

//Circle Values
int circleX = 200, 
    circleY = 200,
    radius = 25;

//Circle Colision
int circleLeft = circleX - radius,
    circleRight = circleX + radius,
    circleTop = circleY - radius,
    circleBottom = circleY + radius;

//Rectangle values
int rectX = 400, 
    rectY = 0,
    rectLength = 50;

//Rectangle Colision
int rectLeft = rectX,
    rectRight = rectX + rectLength,
    rectTop = rectY,
    rectBottom = rectY + rectLength;

//Value to move the axe(rectangle)
int direction = 10;

bool collisionRect = (rectBottom >= circleTop) && 
                    (rectTop <= circleBottom) && 
                    (rectRight >= circleLeft) &&
                    (rectLeft <= circleRight);

int main() {

    //raylib function that initializes a Window
    //takes 3 parameters, width = int, height = int and title = string
    InitWindow(width, height, "Axe Game");

    //Raylib function that sets a number for times the window update each second
    SetTargetFPS(60);
    //WindowShouldClose is a raylib function that returns a boolean value, if the "x" button on the window
    //is pressed, it returns true, otherwise it returns false
    while(WindowShouldClose() == false) {
        //Begin/EndDrawing are raylib functions that sets the area where the content will be drawed
        BeginDrawing();
        //ClearBackground is a raylib function that clears the background and takes 
        //one parameter for the color
        ClearBackground(WHITE);

        if(collisionRect == true) {
            
            DrawText("Game Over!", 400, 200, 20, RED);

        }else {

            //Game Logic Begins

            //Update the edges for collision
            circleLeft = circleX - radius;
            circleRight = circleX + radius;
            circleTop = circleY - radius;
            circleBottom = circleY + radius;

            rectLeft = rectX;
            rectRight = rectX + rectLength;
            rectTop = rectY;
            rectBottom = rectY + rectLength;

            //Update collision with axe(rectangle)
            collisionRect = (rectBottom >= circleTop) && 
                            (rectTop <= circleBottom) && 
                            (rectRight >= circleLeft) &&
                            (rectLeft <= circleRight);

            //DrawCircle is a raylib function that draws a circle and takes 4 parameters
            //DrawCircle(int centerx, int centery, intradius,raylib color )
            DrawCircle(circleX, circleY,radius, BLUE);
            //DrawRectangle is a raylib function that draws a rectangle in the screen with 5 parameters
            //The position is generated by the top left corner of the rectangle
            DrawRectangle(rectX, rectY, rectLength, rectLength, RED);
            DrawRectangle(780, 0, 20, height, GREEN);



            //Move the axe(rectangle)
            rectY += direction;
            //checks if the rectangle touches the border of the screen
            if(rectY + rectLength >= height || rectY <= 0) {
                //Reverse the rectangle direction
                direction = -direction;
            }

            if(circleRight >= 780){
                DrawText("You Won!", 350, 200, 32, GREEN);
                
            }

            //IsKeyDown(KEY) is a raylib function that verifies if the specified Key is Down
            if(IsKeyDown(KEY_D) && circleX <= width - radius) {
                circleX += 10;
            }else if(IsKeyDown(KEY_A) && circleX >= radius){
                circleX -= 10;
            }

                

        }

        EndDrawing();
    }

    

}