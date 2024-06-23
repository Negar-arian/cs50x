#include "helpers.h"

void colorize(int height, int width, RGBTRIPLE image[height][width])
{
    // Change all black pixels to a color of your choosing
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (image[i][j].rgbtRed == 0x00 && image[i][j].rgbtGreen == 0x00 && image[i][j].rgbtBlue == 0x00)
            {
                if ((i == 4 && j == 2) || (i == 4 && j == 5) || (i == 5 && j == 3) || (i == 5 && j == 4))
                {
                    image[i][j].rgbtRed = 0xff;
                    image[i][j].rgbtGreen = 0x69;
                    image[i][j].rgbtBlue = 0x69;
                }
                else if ((i == 2 && j == 2) || (i == 2 && j == 5))
                {
                    image[i][j].rgbtRed = 0x8E;
                    image[i][j].rgbtGreen = 0xCD;
                    image[i][j].rgbtBlue = 0xDE;
                }
                else
                {
                    image[i][j].rgbtRed = 0xFF;
                    image[i][j].rgbtGreen = 0xCC;
                    image[i][j].rgbtBlue = 0x70;
                }
            }
        }
    }
}
