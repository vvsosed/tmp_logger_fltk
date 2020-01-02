#include "main_window.h"
#include <FL/fl_draw.H>

#define MAX_ROWS 30
#define MAX_COLS 26		// A-Z

void HeatersTable::DrawHeader(const char* s, int X, int Y, int W, int H) {
	fl_push_clip(X, Y, W, H);
	fl_draw_box(FL_THIN_UP_BOX, X, Y, W, H, row_header_color());
	fl_color(FL_BLACK);
	fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);
	fl_pop_clip();
}

void HeatersTable::DrawData(const char* s, int X, int Y, int W, int H) {
	fl_push_clip(X, Y, W, H);
	// Draw cell bg
	fl_color(FL_WHITE); fl_rectf(X, Y, W, H);
	// Draw cell data
	fl_color(FL_GRAY0); fl_draw(s, X, Y, W, H, FL_ALIGN_CENTER);
	// Draw box border
	fl_color(color()); fl_rect(X, Y, W, H);
	fl_pop_clip();
}

void HeatersTable::draw_cell(TableContext context, int ROW, int COL, int X, int Y, int W, int H)
{
	static char s[40];
	switch (context) {
	case CONTEXT_STARTPAGE:                   // before page is drawn..
		fl_font(FL_HELVETICA, 16);              // set the font for our drawing operations
		return;
	case CONTEXT_COL_HEADER:                  // Draw column headers
		sprintf(s, "%c", 'A' + COL);                // "A", "B", "C", etc.
		DrawHeader(s, X, Y, W, H);
		return;
	case CONTEXT_ROW_HEADER:                  // Draw row headers
		sprintf(s, "%03d:", ROW);                 // "001:", "002:", etc
		DrawHeader(s, X, Y, W, H);
		return;
	case CONTEXT_CELL:                        // Draw data in cells
		//sprintf(s, "%d", data[ROW][COL]);
		//DrawData(s, X, Y, W, H);
		return;
	default:
		return;
	}
}

void HeatersTable::init() 
{
	// Rows
	rows(MAX_ROWS);             // how many rows
	row_header(1);              // enable row headers (along left)
	row_height_all(20);         // default height of rows
	row_resize(0);              // disable row resizing
	// Cols
	cols(MAX_COLS);             // how many columns
	col_header(1);              // enable column headers (along top)
	col_width_all(80);          // default width of columns
	col_resize(1);              // enable column resizing
}