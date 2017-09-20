/***************************************************
Copyright (c) 2017 Luis Llamas
(www.luisllamas.es)

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions and limitations under the License
 ****************************************************/

#include "StopwatchLib.h"

Stopwatch stopwatch;

void setup()
{
	Serial.begin(9600);
}

void loop()
{
	//delay(20) simula la tarea a medir
	stopwatch.Measure([]() {delay(20);});
	
	Serial.print(stopwatch.GetElapsed()); 
	Serial.print('\t'); 
	Serial.println(stopwatch.GetFrequency());
	Serial.println();
}
