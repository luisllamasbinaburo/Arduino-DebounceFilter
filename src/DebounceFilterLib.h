/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#ifndef _DebounceFilterLib_h
#define _DebounceFilterLib_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif

typedef  void(*DebounceAction)();

class DebounceFilter
{
public:
	DebounceFilter();
	DebounceFilter(bool state);
	DebounceFilter(unsigned long interval);
	DebounceFilter(unsigned long interval, bool state);

	bool AddValue(bool newState);
	void SetInterval(uint16_t interval);

	bool GetState() const;
	bool IsFalling() const;
	bool IsRising() const;

	DebounceAction OnChange;
	DebounceAction OnFalling;
	DebounceAction OnRising;

private:
	unsigned long _previousMillis;
	unsigned long _intervalMillis;

	bool _state;
	bool _changed;

	void _change();
};
#endif

