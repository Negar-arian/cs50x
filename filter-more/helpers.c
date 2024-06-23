#include "helpers.h"
#include <math.h>
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float a = image[i][j].rgbtRed;
            float b = image[i][j].rgbtGreen;
            float c = image[i][j].rgbtBlue;
            int s = round((a + b + c) / 3);
            image[i][j].rgbtRed = s;
            image[i][j].rgbtGreen = s;
            image[i][j].rgbtBlue = s;
        }
    }
    return;
}
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_array[height][width];
    for (int a = 0; a < height; a++)
    {
        for (int b = 0; b < width; b++)
        {
            temp_array[a][b] = image[a][b];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtRed = temp_array[i][width - j - 1].rgbtRed;
            image[i][j].rgbtGreen = temp_array[i][width - j - 1].rgbtGreen;
            image[i][j].rgbtBlue = temp_array[i][width - j - 1].rgbtBlue;
        }
    }
    return;
}
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_array[height][width];
    float avRed, avGreen, avBlue;
    int counter;
    int c, d;
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            counter = 0;
            avRed = 0;
            avGreen = 0;
            avBlue = 0;
            for (int a = -1; a < 2; a++)
            {
                for (int b = -1; b < 2; b++)
                {
                    c = i + a;
                    d = j + b;
                    if (c < height && d < width && c >= 0 && d >= 0)
                    {
                        avRed += image[c][d].rgbtRed;
                        avGreen += image[c][d].rgbtGreen;
                        avBlue += image[c][d].rgbtBlue;
                        counter++;
                    }
                }
            }

            avRed = round(avRed / counter);
            avGreen = round(avGreen / counter);
            avBlue = round(avBlue / counter);
            temp_array[i][j].rgbtRed = avRed;
            temp_array[i][j].rgbtGreen = avGreen;
            temp_array[i][j].rgbtBlue = avBlue;
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = temp_array[i][j];
        }
    }
    return;
}
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp_array[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp_array[i][j] = image[i][j];
        }
    }
    int Gx[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int Gy[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};
    float redsx, greensx, bluesx, redsy, greensy, bluesy;
    int a, b;
    for (int i = 0; i < height; i++)
    {

        for (int j = 0; j < width; j++)
        {

            redsx = greensx = bluesx = redsy = greensy = bluesy = 0;

            for (int k = 0; k < 3; k++)
            {

                for (int t = 0; t < 3; t++)
                {

                    a = i + k - 1;
                    b = j + t - 1;

                    if (a < height && b < width && a >= 0 && b >= 0)
                    {

                        redsx += temp_array[a][b].rgbtRed * Gx[k][t];
                        greensx += temp_array[a][b].rgbtGreen * Gx[k][t];
                        bluesx += temp_array[a][b].rgbtBlue * Gx[k][t];

                        redsy += temp_array[a][b].rgbtRed * Gy[k][t];
                        greensy += temp_array[a][b].rgbtGreen * Gy[k][t];
                        bluesy += temp_array[a][b].rgbtBlue * Gy[k][t];
                    }
                }
            }

            int redG = round(sqrt(pow(redsx, 2) + pow(redsy, 2)));
            int greenG = round(sqrt(pow(greensx, 2) + pow(greensy, 2)));
            int blueG = round(sqrt(pow(bluesx, 2) + pow(bluesy, 2)));

            if (redG > 255)
                redG = 255;

            if (greenG > 255)
                greenG = 255;

            if (blueG > 255)
                blueG = 255;

            image[i][j].rgbtRed = redG;
            image[i][j].rgbtGreen = greenG;
            image[i][j].rgbtBlue = blueG;
        }
    }
    return;
}
