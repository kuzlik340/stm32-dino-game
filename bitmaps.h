/*
 * bitmaps.h   v1.0
 *
 * contains every bitmap used in this project
 *
 * T.Kuz    8.2024
 */

/* Default dino bitmap(all legs are on the ground), used while jumping*/
const char dino1_bitMap[] = {
    0b00000000, 0b00000000, 0b00000000, 0b00000000,
    0b00000000, 0b00000111, 0b11111110, 0b00000000,
    0b00000000, 0b00000110, 0b11111111, 0b00000000,
    0b00000000, 0b00001110, 0b11111111, 0b00000000,
    0b00000000, 0b00001111, 0b11111111, 0b00000000,
    0b00000000, 0b00001111, 0b11111111, 0b00000000,
    0b00000000, 0b00001111, 0b11111111, 0b00000000,
    0b00000000, 0b00001111, 0b11000000, 0b00000000,
    0b00000000, 0b00001111, 0b11111100, 0b00000000,
    0b01000000, 0b00001111, 0b11000000, 0b00000000,
    0b01000000, 0b00011111, 0b10000000, 0b00000000,
    0b01000000, 0b01111111, 0b10000000, 0b00000000,
    0b01100000, 0b11111111, 0b11100000, 0b00000000,
    0b01110001, 0b11111111, 0b10100000, 0b00000000,
    0b01111111, 0b11111111, 0b10000000, 0b00000000,
    0b01111111, 0b11111111, 0b10000000, 0b00000000,
    0b01111111, 0b11111111, 0b10000000, 0b00000000,
    0b00111111, 0b11111111, 0b00000000, 0b00000000,
    0b00011111, 0b11111111, 0b00000000, 0b00000000,
    0b00001111, 0b11111110, 0b00000000, 0b00000000,
    0b00000011, 0b11111100, 0b00000000, 0b00000000,
    0b00000001, 0b11011100, 0b00000000, 0b00000000,
    0b00000001, 0b10001100, 0b00000000, 0b00000000,
    0b00000001, 0b10001100, 0b00000000, 0b00000000,
    0b00000001, 0b00001100, 0b00000000, 0b00000000,
    0b00000001, 0b10001110, 0b00000000, 0b00000000};

/* Dino bitmap(with right leg up)*/
const char dino2_bitMap[] = {
    0b00000000, 0b00000000, 0b00000000, 0b00000000,
    0b00000000, 0b00000111, 0b11111110, 0b00000000,
    0b00000000, 0b00000110, 0b11111111, 0b00000000,
    0b00000000, 0b00001110, 0b11111111, 0b00000000,
    0b00000000, 0b00001111, 0b11111111, 0b00000000,
    0b00000000, 0b00001111, 0b11111111, 0b00000000,
    0b00000000, 0b00001111, 0b11111111, 0b00000000,
    0b00000000, 0b00001111, 0b11000000, 0b00000000,
    0b00000000, 0b00001111, 0b11111100, 0b00000000,
    0b01000000, 0b00001111, 0b11000000, 0b00000000,
    0b01000000, 0b00011111, 0b10000000, 0b00000000,
    0b01000000, 0b01111111, 0b10000000, 0b00000000,
    0b01100000, 0b11111111, 0b11100000, 0b00000000,
    0b01110001, 0b11111111, 0b10100000, 0b00000000,
    0b01111111, 0b11111111, 0b10000000, 0b00000000,
    0b01111111, 0b11111111, 0b10000000, 0b00000000,
    0b01111111, 0b11111111, 0b10000000, 0b00000000,
    0b00111111, 0b11111111, 0b00000000, 0b00000000,
    0b00011111, 0b11111111, 0b00000000, 0b00000000,
    0b00001111, 0b11111110, 0b00000000, 0b00000000,
    0b00000011, 0b11111100, 0b00000000, 0b00000000,
    0b00000001, 0b11011100, 0b00000000, 0b00000000,
    0b00000001, 0b00001100, 0b00000000, 0b00000000,
    0b00000001, 0b10001100, 0b00000000, 0b00000000,
    0b00000000, 0b00001100, 0b00000000, 0b00000000,
    0b00000000, 0b00001110, 0b00000000, 0b00000001};

/* Dino bitmap (with left leg up)*/
const char dino3_bitMap[] = {
    0b00000000, 0b00000000, 0b00000000, 0b00000000,
    0b00000000, 0b00000111, 0b11111110, 0b00000000,
    0b00000000, 0b00000110, 0b11111111, 0b00000000,
    0b00000000, 0b00001110, 0b11111111, 0b00000000,
    0b00000000, 0b00001111, 0b11111111, 0b00000000,
    0b00000000, 0b00001111, 0b11111111, 0b00000000,
    0b00000000, 0b00001111, 0b11111111, 0b00000000,
    0b00000000, 0b00001111, 0b11000000, 0b00000000,
    0b00000000, 0b00001111, 0b11111100, 0b00000000,
    0b01000000, 0b00001111, 0b11000000, 0b00000000,
    0b01000000, 0b00011111, 0b10000000, 0b00000000,
    0b01000000, 0b01111111, 0b10000000, 0b00000000,
    0b01100000, 0b11111111, 0b11100000, 0b00000000,
    0b01110001, 0b11111111, 0b10100000, 0b00000000,
    0b01111111, 0b11111111, 0b10000000, 0b00000000,
    0b01111111, 0b11111111, 0b10000000, 0b00000000,
    0b01111111, 0b11111111, 0b10000000, 0b00000000,
    0b00111111, 0b11111111, 0b00000000, 0b00000000,
    0b00011111, 0b11111111, 0b00000000, 0b00000000,
    0b00001111, 0b11111110, 0b00000000, 0b00000000,
    0b00000011, 0b11111100, 0b00000000, 0b00000000,
    0b00000001, 0b11011100, 0b00000000, 0b00000000,
    0b00000001, 0b10001110, 0b00000000, 0b00000000,
    0b00000001, 0b10000000, 0b00000000, 0b00000000,
    0b00000001, 0b00000000, 0b00000000, 0b00000000,
    0b00000001, 0b10000000, 0b00000000, 0b00000000};

/* Bitmap of obstacle*/
const unsigned char tree1_bitMap[] = {
    0b00011110, 0b00000000,
    0b00011111, 0b00000000,
    0b00011111, 0b01000000,
    0b00011111, 0b11100000,
    0b00011111, 0b11100000,
    0b11011111, 0b11100000,
    0b11111111, 0b11100000,
    0b11111111, 0b11100000,
    0b11111111, 0b11100000,
    0b11111111, 0b11100000,
    0b11111111, 0b11100000,
    0b11111111, 0b11100000,
    0b11111111, 0b11000000,
    0b11111111, 0b00000000,
    0b11111111, 0b00000000,
    0b01111111, 0b00000000,
    0b00011111, 0b00000000,
    0b00011111, 0b00000000,
    0b00011111, 0b00000000,
    0b00011111, 0b00000000,
    0b00011111, 0b00000000,
    0b00011111, 0b00000000,
    0b00011111, 0b00000000};

/* Dead dino bitmap*/
const unsigned char dead_dino_bitMap[] = {
    0b00000000, 0b00000000, 0b00000000, 0b00000000,
    0b00000000, 0b00000111, 0b11111110, 0b00000000,
    0b00000000, 0b00000110, 0b00111111, 0b00000000,
    0b00000000, 0b00001110, 0b10111111, 0b00000000,
    0b00000000, 0b00001110, 0b00111111, 0b00000000,
    0b00000000, 0b00001111, 0b11111111, 0b00000000,
    0b00000000, 0b00001111, 0b11111111, 0b00000000,
    0b00000000, 0b00001111, 0b11000000, 0b00000000,
    0b00000000, 0b00001111, 0b11111100, 0b00000000,
    0b01000000, 0b00001111, 0b11000000, 0b00000000,
    0b01000000, 0b00011111, 0b10000000, 0b00000000,
    0b01000000, 0b01111111, 0b10000000, 0b00000000,
    0b01100000, 0b11111111, 0b11100000, 0b00000000,
    0b01110001, 0b11111111, 0b10100000, 0b00000000,
    0b01111111, 0b11111111, 0b10000000, 0b00000000,
    0b01111111, 0b11111111, 0b10000000, 0b00000000,
    0b01111111, 0b11111111, 0b10000000, 0b00000000,
    0b00111111, 0b11111111, 0b00000000, 0b00000000,
    0b00011111, 0b11111111, 0b00000000, 0b00000000,
    0b00001111, 0b11111110, 0b00000000, 0b00000000,
    0b00000011, 0b11111100, 0b00000000, 0b00000000,
    0b00000001, 0b11011100, 0b00000000, 0b00000000,
    0b00000001, 0b10001100, 0b00000000, 0b00000000,
    0b00000001, 0b10001100, 0b00000000, 0b00000000,
    0b00000001, 0b00001100, 0b00000000, 0b00000000,
    0b00000001, 0b10001110, 0b00000000, 0b00000000};
