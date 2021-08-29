#include <math.h>
#include "helpers.h"

// Convert image to grayscale (black & white)
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

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // sepia algorithm
            float sepiaRed = .393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue;
            float sepiaGreen = .349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue;
            float sepiaBlue = .272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue;

            // make sure the result is a valid number (0 < sepia < 255)
            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            // apply the changes (integer numbers)
            image[i][j].rgbtRed = round(sepiaRed);
            image[i][j].rgbtGreen =  round(sepiaGreen);
            image[i][j].rgbtBlue = round(sepiaBlue);
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
