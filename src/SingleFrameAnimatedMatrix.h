#include <Arduino.h>
#include <LedControl.h>

class SingleFrameAnimatedMatrix {
	private:
		long current;
		byte frame[8];
		bool done;
		unsigned long durationMs;
		LedControl ledControl;

		static const int delayMs = 200;
		static const int rows = 8;
		static const int space = 2;

	public:
		SingleFrameAnimatedMatrix(const byte* frame, unsigned long durationMs);

		void scroll(int direction);
};
