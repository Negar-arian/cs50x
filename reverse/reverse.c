#include "wav.h"
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse input.wav output.wav\n");
        return 1;
    }
    // Open input file for reading
    // TODO #2
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Input is invalid or not exist.\n");
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, input);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(header) == 0)
    {
        printf("Input is not a WAV file.\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *output = fopen(argv[2], "w");

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(WAVHEADER), 1, output);

    // Use get_block_size to calculate size of block
    // TODO #7
    int block_size = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    BYTE buffer[block_size];
    fseek(input, 0, SEEK_END);
    long audio_size = ftell(input) - sizeof(WAVHEADER);
    int audio_block = (int) audio_size / block_size;
    for (int i = audio_block - 1; i >= 0; i--)
    {

        fseek(input, sizeof(WAVHEADER) + i * block_size, SEEK_SET);
        fread(buffer, block_size, 1, input);
        fwrite(buffer, block_size, 1, output);
    }
    fclose(input);
    fclose(output);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    BYTE check[4] = {'W', 'A', 'V', 'E'};
    for (int i = 0; i < 4; i++)
    {
        if (check[i] != header.format[i])
        {
            return 0;
        }
    }
    return 1;
}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    WORD bytePerSample = header.bitsPerSample / 8;
    int block_size = (header.numChannels) * (bytePerSample);
    return block_size;
}
