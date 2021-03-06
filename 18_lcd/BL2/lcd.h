#ifndef _LCD_H_
#define _LCD_H_
void lcd_init(void);
void lcd_draw_pixel(int row, int col, int color);
void lcd_clear_screen(int color);
void lcd_draw_hline(int row, int col1, int col2, int color);
void lcd_draw_vline(int col, int row1, int row2, int color);
void lcd_draw_cross(int row, int col, int halflen, int color);
void lcd_draw_circle(int row,int col,int halflen, int color);
#endif
