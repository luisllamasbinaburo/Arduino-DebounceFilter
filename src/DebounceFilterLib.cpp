/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#include "DebounceFilterLib.h"

DebounceFilter::DebounceFilter()
{
	DebounceFilter(50, 0);
}

DebounceFilter::DebounceFilter(bool _state)
{
	DebounceFilter(50, _state);
}

DebounceFilter::DebounceFilter(unsigned long interval)
{
	DebounceFilter(interval, 0);

}

DebounceFilter::DebounceFilter(unsigned long interval, bool state)
{
	_previousMillis = 0;
	_intervalMillis = interval;
	_state = state;
	_changed = false;
	OnChange = nullptr;
	OnFalling = nullptr;
	OnRising = nullptr;
}


bool DebounceFilter::AddValue(bool newState)
{
	_changed = false;
	if (millis() - _previousMillis >= _intervalMillis)
	{
		if (_state != newState)
		{
			_previousMillis = millis();
			_state = newState;
			_change();
		}
	}
	return _state;
}

void DebounceFilter::SetInterval(uint16_t interval)
{
	_intervalMillis = interval;
}

bool DebounceFilter::GetState() const
{
	return _state;
}

bool DebounceFilter::IsRising() const
{
	return _changed && _state;
}

bool DebounceFilter::IsFalling() const
{
	return _changed && !_state;
}

void DebounceFilter::_change()
{
	_changed = true;
	if(OnChange != nullptr) OnChange();
	if (IsRising() && OnRising != nullptr) OnRising();
	if (IsFalling() && OnFalling != nullptr) OnFalling();
}