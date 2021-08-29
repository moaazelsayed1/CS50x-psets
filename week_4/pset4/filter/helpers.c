 #include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // calculating the avarage of RGB of one pixel one by one
            float avr = (image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.000;

            // apply the avarge (intager number) in the image using round()
            image[i][j].rgbtGreen = round(avr);
            image[i][j].rgbtBlue = round(avr);
            image[i][j].rgbtRed = round(avr);
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // swapping the symmetric pixels using k as a temp variable
            // if pixel is j then its symmetric one is ((width - 1) - j)
            RGBTRIPLE k = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = k;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // we have to save the original photo in order to calculate the sums of
    // RGB right, so we apply the changes on another RGBTRIPLE image (cpimage)
    RGBTRIPLE cpimage[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumblue = 0;
            int sumred = 0;
            int sumgreen = 0;
            // total number of pixels around
            float counter = 0.0;

            // counter to calculate the sums through rows (3 iterations [-1, 0, 1])
            for (int h = -1; h < 2; h++)
            {
                // counter to calculate the sums through columns (3 iterations [-1, 0, 1])
                for (int w = -1; w < 2; w++)
                {
                    // any time the sum of rows is less than 0 or more than height
                    // (out of the range [0 - height]) then skip this iteration
                    // same for columns..
                    if (i + h < 0 || i + h > height - 1 || j + w < 0 || j + w > width - 1)
                    {
                        continue;
                    }
                    else
                    {
                        // sum of surrouded pixels
                        sumred += image[i + h][j + w].rgbtRed;
                        sumblue += image[i + h][j + w].rgbtGreen;
                        sumgreen += image[i + h][j + w].rgbtBlue;

                        // for every iteration increament counter (surrounded pixels + 1)
                        counter++;
                    }

                }
            }
            // save changes in cpimage
            cpimage[i][j].rgbtRed = round(sumred / counter);
            cpimage[i][j].rgbtGreen = round(sumblue / counter);
            cpimage[i][j].rgbtBlue = round(sumgreen / counter);
        }
    }

    // apply changes in the original image (image)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = cpimage[i][j].rgbtRed;
            image[i][j].rgbtGreen = cpimage[i][j].rgbtGreen;
            image[i][j].rgbtBlue = cpimage[i][j].rgbtBlue;
        }
    }
    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    // we have to save the original photo in order to calculate the sums of
    // RGB right, so we apply the changes on another RGBTRIPLE image (cpimage)
    RGBTRIPLE cpimage[height][width];
   
    // intialization of Gx and Gy matrices
    int GX[3][3] = 
    {
        {-1, 0, 1}, 
        {-2, 0, 2},
        {-1, 0, 1},
    };
    
    int GY[3][3] = 
    {
        {-1, -2, -1}, 
        {0, 0, 0},
        {1, 2, 1},
    };               

    // iterate across height
    for (int i = 0; i < height; i++)
    {
        // iterate across width
        for (int j = 0; j < width; j++)
        {
            // intialization of Gxs
            float GxRed = 0;
            float GxGreen = 0;
            float GxBlue = 0;

            // intialization of Gys
            float GyRed = 0;
            float GyGreen = 0;
            float GyBlue = 0;
            
            int Red = 0;
            int Green = 0;
            int Blue = 0;
            
            // counter to calculate the sums through rows (3 iterations [-1, 0, 1])
            for (int h = -1; h < 2; h++)
            {
                // counter to calculate the sums through columns (3 iterations [-1, 0, 1])
                for (int w = -1; w < 2; w++)
                {
                    // any time the sum of rows counters is less than 0 or more than height
                    // (out of the range [0 - height]) then skip convert it to black pixel
                    // same for columns..
                    if (i + h < 0 || i + h > height - 1 || j + w < 0 || j + w > width - 1)
                    {
                      
                        continue;
                         
                    }
                    else
                    {
                        // applying Sobel operator in x and y directions
                        GxRed += (GX[h + 1][w + 1] * image[i + h][j + w].rgbtRed);
                        GxGreen += (GX[h + 1][w + 1] * image[i + h][j + w].rgbtGreen);
                        GxBlue += (GX[h + 1][w + 1] * image[i + h][j + w].rgbtBlue);

                        GyRed += (GY[h + 1][w + 1] * image[i + h][j + w].rgbtRed);
                        GyGreen += (GY[h + 1][w + 1] * image[i + h][j + w].rgbtGreen);
                        GyBlue += (GY[h + 1][w + 1] * image[i + h][j + w].rgbtBlue);
                    }
                }
            }
            Red = round(sqrt(pow(GxRed, 2) + pow(GyRed, 2)));
            Green = round(sqrt(pow(GxGreen, 2) + pow(GyGreen, 2)));
            Blue = round(sqrt(pow(GxBlue, 2) + pow(GyBlue, 2)));
            
            if (Red > 255)
            {
                Red = 255;
            }
            if (Green > 255)
            {
                Green = 255;
            }
            if (Blue > 255)
            {
                Blue = 255;
            }
            
            cpimage[i][j].rgbtRed = Red;  
            cpimage[i][j].rgbtGreen = Green; 
            cpimage[i][j].rgbtBlue = Blue; 
            
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = cpimage[i][j];
        }
    }
    return;
}
