#include "helpers.h"

#include <math.h>

//int pixav (pixcount);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    //r - row, c - column
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            // RGB float
            float blue = image[r][c].rgbtBlue;
            float red = image[r][c].rgbtRed;
            float green = image[r][c].rgbtGreen;

            // average pixel colour rounded int
            int average = round((blue + green + red) / 3.0);

            // assign average colour pixel
            image[r][c].rgbtRed = image[r][c].rgbtGreen = image[r][c].rgbtBlue = average;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width; c++)
        {
            // original RGB
            float blue = image[r][c].rgbtBlue;
            float red = image[r][c].rgbtRed;
            float green = image[r][c].rgbtGreen;
            // formulas sepia
            int sepiaRed = round(.393 * red + .769 * green + .189 * blue);
            int sepiaGreen = round(.349 * red + .686 * green + .168 * blue);
            int sepiaBlue = round(.272 * red + .534 * green + .131 * blue);
            // cap values exceeding 255
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
            // assign sepia clolour
            image[r][c].rgbtRed = sepiaRed;
            image[r][c].rgbtGreen = sepiaGreen;
            image[r][c].rgbtBlue = sepiaBlue;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int r = 0; r < height; r++)
    {
        for (int c = 0; c < width / 2; c++)
        {
            // save temp pixel value
            RGBTRIPLE temp = image[r][c];
            // end replace start pixel (+ 1 for index starts at 0)
            image[r][c] = image[r][width - (c + 1)];
            // temp replaces end pixel
            image[r][width - (c + 1)] = temp;
        }
    }
    return;
}

// Box blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // IMAGE COPY
    RGBTRIPLE copy[height][width];
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            copy[y][x] = image[y][x];
        }
    }
    for (int y = 0; y < height; y++)
    {
        for (int x = 0; x < width; x++)
        {
            int sumred = 0, sumblue = 0, sumgreen = 0;
            float pixcount = 0;

            // check neighbouring pixels
            for (int i = -1; i <= 1; i++)
            {
                for (int j = -1; j <= 1; j++)
                {
                    int yaxis = y + i, xaxis = x + j;

                    //Check for valid pixel
                    if ((yaxis < 0 || yaxis > (height - 1)) || (xaxis < 0 || xaxis > (width - 1)))
                    {
                        continue;
                    }

                    // SUM THE VALID PIXELS from copy image
                    sumred += copy[yaxis][xaxis].rgbtRed;
                    sumgreen += copy[yaxis][xaxis].rgbtGreen;
                    sumblue += copy[yaxis][xaxis].rgbtBlue;
                    pixcount++;

                    // assigning avepix to the orig of image
                    image[y][x].rgbtRed = round(sumred / pixcount);
                    image[y][x].rgbtGreen = round(sumgreen / pixcount);
                    image[y][x].rgbtBlue = round(sumblue / pixcount);
                }
            }
        }
    }
    return;
}
