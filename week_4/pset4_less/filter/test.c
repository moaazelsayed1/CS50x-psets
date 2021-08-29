#include <stdio.h>
#include <math.h>


int main(void)
{
    float avr = (28 +29 + 31) / 3;
    float avarage = round(avr);
    printf("%f", avarage);
    //image[i][j].rgbtBlue = round(avr);
    //image[i][j].rgbtRed = round(avr);
}

void blur(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (i == 0 && j == 0)
            {
                float avar0 = (image[0][1].rgbtRed + image[1][0].rgbtRed + image[1][1].rgbtRed) / 3.0;
                float avag0 = (image[0][1].rgbtGreen + image[1][0].rgbtGreen + image[1][1].rgbtGreen) / 3.0;
                float avab0 = (image[0][1].rgbtBlue + image[1][0].rgbtBlue + image[1][1].rgbtBlue) / 3.0;

                image[i][j].rgbtRed = round(avar0);
                image[i][j].rgbtGreen = round(avag0);
                image[i][j].rgbtBlue = round(avab0);
            }
            else if (i == height - 1 && j == 0)
            {
                float avar1 = (image[i][j + 1].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i - 1][0].rgbtRed) / 3.0;
                float avag1 = (image[i][j + 1].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i - 1][0].rgbtGreen) / 3.0;
                float avab1 = (image[i][j + 1].rgbtBlue + image[i - 1][i + 1].rgbtBlue + image[i - 1][0].rgbtBlue) / 3.0;

                image[i][j].rgbtRed = round(avar1);
                image[i][j].rgbtGreen = round(avag1);
                image[i][j].rgbtBlue = round(avab1);
            }
            else if (i == 0 && j == width - 1)
            {
                float avar2 = (image[0][j - 1].rgbtRed + image[1][j].rgbtRed + image[1][j - 1].rgbtRed) / 3.0;
                float avag2 = (image[0][j - 1].rgbtGreen + image[1][j].rgbtGreen + image[1][j - 1].rgbtGreen) / 3.0;
                float avab2 = (image[0][j - 1].rgbtBlue + image[1][j].rgbtBlue + image[1][j - 1].rgbtBlue) / 3.0;

                image[i][j].rgbtRed = round(avar2);
                image[i][j].rgbtGreen = round(avag2);
                image[i][j].rgbtBlue = round(avab2);
            }
            else if (i == height - 1 && j == width - 1)
            {
                float avar3 = (image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed) / 3.0;
                float avag3 = (image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen) / 3.0;
                float avab3 = (image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue) / 3.0;

                image[i][j].rgbtRed = round(avar3);
                image[i][j].rgbtGreen = round(avag3);
                image[i][j].rgbtBlue = round(avab3);
            }
            else if (i >= 1 && i <= height - 2 && j == 0)
            {
                float avar4 = (image[i - 1][j].rgbtRed + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed
                + image[i + 1][j + 1].rgbtRed + image[i+ 1][j].rgbtRed) / 5.0;
                 float avag4 = (image[i - 1][j].rgbtGreen + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen
                + image[i + 1][j + 1].rgbtGreen + image[i+ 1][j].rgbtGreen) / 5.0;
                float avab4 = (image[i - 1][j].rgbtBlue + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue
                + image[i + 1][j + 1].rgbtBlue + image[i+ 1][j].rgbtBlue) / 5.0;

                image[i][j].rgbtRed = round(avar4);
                image[i][j].rgbtGreen = round(avag4);
                image[i][j].rgbtBlue = round(avab4);
            }
            else if (i >= 1 && i <= height - 2 && j == width - 1)
            {
                float avar5 = (image[i - 1][j].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i][j - 1].rgbtRed
                + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed) / 5.0;
                 float avag5 = (image[i - 1][j].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i][j - 1].rgbtGreen
                + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen) / 5.0;
                float avab5 = (image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j - 1].rgbtBlue
                + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 5.0;

                image[i][j].rgbtRed = round(avar5);
                image[i][j].rgbtGreen = round(avag5);
                image[i][j].rgbtBlue = round(avab5);
            }
            else if (i == 0 && j >= 1 && j <= width - 2)
            {
                float avar6 = (image[i][j - 1].rgbtRed + image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed
                + image[i + 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed) / 5.0;
                 float avag6 = (image[i][j - 1].rgbtGreen + image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen
                + image[i + 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen) / 5.0;
                float avab6 = (image[i - 1][j].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue
                + image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue) / 5.0;

                image[i][j].rgbtRed = round(avar6);
                image[i][j].rgbtGreen = round(avag6);
                image[i][j].rgbtBlue = round(avab6);
            }
            else if (i == height - 1 && j >= 1 && j <= width - 2)
            {
                float avar7 = (image[i][j - 1].rgbtRed + image[i - 1][j - 1].rgbtRed + image[i - 1][j].rgbtRed
                + image[i - 1][j + 1].rgbtRed + image[i][j + 1].rgbtRed) / 5.0;
                 float avag7 = (image[i][j - 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen + image[i - 1][j].rgbtGreen
                + image[i - 1][j + 1].rgbtGreen + image[i][j + 1].rgbtGreen) / 5.0;
                float avab7 = (image[i][j - 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue + image[i - 1][j].rgbtBlue
                + image[i - 1][j + 1].rgbtBlue + image[i][j + 1].rgbtBlue) / 5.0;

                image[i][j].rgbtRed = round(avar7);
                image[i][j].rgbtGreen = round(avag7);
                image[i][j].rgbtBlue = round(avab7);
            }
            else
            {
                float avar8 = (image[i][j - 1].rgbtRed + image[i][j + 1].rgbtRed + image[i - 1][j - 1].rgbtRed
                + image[i - 1][j + 1].rgbtRed + image[i - 1][j].rgbtRed +
                image[i + 1][j - 1].rgbtRed + image[i + 1][j].rgbtRed + image[i + 1][j + 1].rgbtRed) / 8.0;

                float avag8 = (image[i][j - 1].rgbtGreen + image[i][j + 1].rgbtGreen + image[i - 1][j - 1].rgbtGreen
                + image[i - 1][j + 1].rgbtGreen + image[i - 1][j].rgbtGreen +
                image[i + 1][j - 1].rgbtGreen + image[i + 1][j].rgbtGreen + image[i + 1][j + 1].rgbtGreen) / 8.0;

                float avab8 = (image[i][j - 1].rgbtBlue + image[i][j + 1].rgbtBlue + image[i - 1][j - 1].rgbtBlue
                + image[i - 1][j + 1].rgbtBlue + image[i - 1][j].rgbtBlue +
                image[i + 1][j - 1].rgbtBlue + image[i + 1][j].rgbtBlue + image[i + 1][j + 1].rgbtBlue) / 5.0;

                image[i][j].rgbtRed = round(avar8);
                image[i][j].rgbtGreen = round(avag8);
                image[i][j].rgbtBlue = round(avab8);
            }
        }
    }
    return;
}