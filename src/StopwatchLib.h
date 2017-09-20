/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#define _StopwatchLib_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
class Stopwatch
{
	typedef  void(*StopwatchAction)();

public:
	Stopwatch();

	void Reset();
	void Update();

	unsigned long GetElapsed() const;
	float GetFrequency() const;

	void Measure(StopwatchAction action);

private:
	unsigned long _lastMicros;
	unsigned long _elapsed;
	const unsigned int _tuning = 8;
};

#endif

