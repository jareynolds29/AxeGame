#include "raylib.h" // External Include

int main() 
{
    // Window dimensions
    int width{800};
    int height{450};
    InitWindow(width, height, "Axe Game"); // Multiple Input Function (this function takes width, height, title)

    // Circle coordinates
    int circleX{200};
    int circleY{200};
    int circleRadius{25};
    // Circle Edges
    int l_circleX{circleX - circleRadius};
    int r_circleX{circleX + circleRadius};
    int u_circleY{circleY - circleRadius};
    int b_circleY{circleY + circleRadius};

    // Axe coordinates
    int axeX{400};
    int axeY{0};
    int direction{10};
    int axeLength{50};
    // Axe Edges
    int l_axeX{axeX};
    int r_axeX{axeX + axeLength};
    int u_axeY{axeY};
    int b_axeY{axeY + axeLength};
    // Axe Utility
    bool collisionWithAxe = 
                        (b_axeY >= u_circleY) && 
                        (u_axeY <= b_circleY) && 
                        (r_axeX >= l_circleX) && 
                        (l_axeX <= r_circleX);

    SetTargetFPS(60);
    while ( WindowShouldClose() != true ) // also could do == false.
    {
        BeginDrawing();
        ClearBackground(WHITE); // Clears the canvas of raylib colours 

        if(collisionWithAxe) {
            DrawText("Game Over!", 400, 200, 20, RED);
        } else {
            // Game logic begins 

            // Update the edges
            l_circleX = circleX - circleRadius;
            r_circleX = circleX + circleRadius;
            u_circleY = circleY - circleRadius;
            b_circleY = circleY + circleRadius;
            l_axeX = axeX;
            r_axeX = axeX + axeLength;
            u_axeY = axeY;
            b_axeY = axeY + axeLength;

            // Update Collision With Axe
            collisionWithAxe = 
                        (b_axeY >= u_circleY) && 
                        (u_axeY <= b_circleY) && 
                        (r_axeX >= l_circleX) && 
                        (l_axeX <= r_circleX);

            DrawCircle(circleX, circleY, circleRadius, BLUE); // circleX, CircleY, Radius, Colour
            DrawRectangle(axeX, axeY, axeLength, axeLength, RED);

            // Move the Axe
            axeY += direction;
            if(axeY > 400 || axeY < 0) {
                direction = -direction;
            }

            if (IsKeyDown(KEY_D) && (circleX < width)){
                circleX += 10;
            } else if (IsKeyDown(KEY_A) && (circleX > 0)){
                circleX -= 10;
            } 
            // Game logic ends
        }
        EndDrawing();
    } 
}