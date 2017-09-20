/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#include "DebounceFilterLib.h"

bool values[] = { 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 1, 0};
size_t valuesLength = sizeof(values) / sizeof(values[0]);

bool getMeasure()
{
	size_t static index = 0;
	index++;
	return values[index - 1];
}


DebounceFilter debouncer;

void setup() 
{
	Serial.begin(9600);
	debouncer.SetInterval(50);
	debouncer.OnFalling = []() {Serial.println("OnFalling");};

	for (size_t index = 0; index < valuesLength; index++)
	{
		bool raw = getMeasure();
		debouncer.AddValue(raw);

		delay(10);
	}
}


void loop() 
{

}
