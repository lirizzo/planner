#pragma once


using namespace System;

namespace FutureDo {
	public ref class Timer_pomodoro {
	private:
		static TimeSpan timer = TimeSpan::FromSeconds(1500);
	public:
		static void Set_timer(int seconds) {
			timer = TimeSpan::FromSeconds(seconds);
		}
		static TimeSpan Get_timer() {
			return timer;
		}
		static int Get_seconds() {
			return (int)timer.TotalSeconds;
		}

	};
}