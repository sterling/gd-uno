#include "SingleFrameAnimatedMatrix.h"

SingleFrameAnimatedMatrix::SingleFrameAnimatedMatrix(const byte* _frame, unsigned long _durationMs)
// ledControl(data, clk, cs, count)
: ledControl(4, 2, 3, 1), current(0) {
	ledControl.shutdown(0, false);  // Wake up displays
	ledControl.setIntensity(0, 0);  // Set intensity levels
	ledControl.clearDisplay(0);  // Clear Displays

	for (int i = 0; i < rows; i++) {
		Serial.println(_frame[i]);
		frame[i] = _frame[i];
	}
}

void SingleFrameAnimatedMatrix::scroll(int direction) {
	int totalRows = rows + space;

	for (int i = 0; i < totalRows; i++) {
		int targetRow = (i + current) % totalRows;
		int targetData = B00000000;

		if (i < rows) {
			targetData = frame[i];
		}

		if (targetRow < 0) {
			targetRow = totalRows + targetRow;
		}

		if (targetRow < rows) {
			ledControl.setRow(0, targetRow, targetData);
		}
	}

	if (direction > 0) {
		current--;
	} else {
		current++;
	}
}
